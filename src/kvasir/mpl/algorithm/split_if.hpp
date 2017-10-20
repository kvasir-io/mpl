//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>

#include "../algorithm/fold_right.hpp"
#include "../functional/call.hpp"
#include "../sequence/push_front.hpp"
#include "../types/list.hpp"

namespace kvasir {
	namespace mpl {
		namespace detail {
			template <typename T, typename U>
			struct split_push;
			template <typename... Ls, typename... Ts, typename U>
			struct split_push<list<list<Ts...>, Ls...>, U> {
				using type = list<list<U, Ts...>, Ls...>;
			};

			template <typename T>
			struct split_next;
			template <typename... Ls>
			struct split_next<list<Ls...>> {
				using type = list<list<>, Ls...>;
			};

			template <template <typename...> class F>
			struct split_if_pred {
				template <typename T, typename U>
				using f = typename std::conditional<F<U>::value, split_next<T>,
				                                    split_push<T, U>>::type::type;
			};
		} // namespace detail
		/// \brief splits a lits into multiple lists at every point for which the provided predicate
		/// holds
		template <typename F = identity, typename C = listify>
		struct split_if {
			template <typename... Ts>
			using f = typename dcall<fold_right<detail::split_if_pred<F::template f>,
			                                    push_front<unpack<C>, cfe<call>>>,
			                         sizeof...(Ts)>::template f<list<list<>>, Ts...>;
		};
		namespace eager {
			template <typename List, template <typename...> class F = identity>
			using split_if = call<unpack<mpl::split_if<cfe<F>>>, List>;
		}
	} // namespace mpl
} // namespace kvasir

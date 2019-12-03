//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../algorithm/fold_right.hpp"
#include "../functional/call.hpp"
#include "../functional/flow.hpp"
#include "../sequence/at.hpp"
#include "../sequence/push_front.hpp"
#include "../types/list.hpp"
#include "../utility/conditional.hpp"

namespace kvasir {
	namespace mpl {
		namespace detail {
			template <typename T, typename U>
			struct split_push;
			template <typename... Ls, typename... Ts, typename U>
			struct split_push<list<list<Ts...>, Ls...>, U> {
				using type = list<list<U, Ts...>, Ls...>;
			};

			template <typename F>
			using split_if_pred = if_<at1<F>, at0<unpack<push_front<list<>>>>, cfl<split_push>>;
		} // namespace detail
		/// \brief splits a lits into multiple lists at every point for which the provided predicate
		/// holds
		template <typename F = identity, typename C = listify>
		struct split_if {
			template <typename... Ts>
			using f = typename dcall<
			        fold_right<detail::split_if_pred<F>, push_front<unpack<C>, cfe<call>>>,
			        sizeof...(Ts)>::template f<list<list<>>, Ts...>;
		};
		namespace eager {
			template <typename List, template <typename...> class F = identity>
			using split_if = call<unpack<mpl::split_if<cfe<F>>>, List>;
		}
	} // namespace mpl
} // namespace kvasir

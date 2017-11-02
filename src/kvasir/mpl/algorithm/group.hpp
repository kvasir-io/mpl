//          Copyright Jonathan Poelen 2017.
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../algorithm/fold_left.hpp"
#include "../algorithm/rotate.hpp"
#include "../algorithm/zip_with.hpp"
#include "../functional/bind.hpp"
#include "../functional/call.hpp"
#include "../sequence/push_front.hpp"
#include "../sequence/take.hpp"
#include "../types/int.hpp"
#include "../types/list.hpp"
#include "../types/traits.hpp"
#include "../utility/conditional.hpp"

namespace kvasir {
	namespace mpl {
		namespace detail {
			template <typename T, typename U>
			struct group_push;
			template <typename... Ls, typename... Ts, typename U1, typename U2>
			struct group_push<list<list<Ts...>, Ls...>, list<U1, U2>> {
				using type = list<list<Ts..., U2>, Ls...>;
			};

			template <typename T, typename U>
			struct group_next;
			template <typename L, typename... Ls, typename U1, typename U2>
			struct group_next<list<L, Ls...>, list<U1, U2>> {
				using type = list<list<U2>, Ls..., L>;
			};

			template <typename Pred>
			struct group_pred {
				template <typename In, typename Pair>
				using f = typename conditional<call<unpack<Pred>, Pair>::value>::template f<
				        group_push<In, Pair>, group_next<In, Pair>>::type;
			};

			template <typename C, bool>
			struct group_impl;

			template <typename C>
			struct group_impl<C, 0> {
				template <typename Pred>
				using f = list<>;
			};

			template <typename C>
			struct group_impl<C, 1> {
				template <typename Pred, typename T0, typename... Ts>
				using f = typename dcall<
				        zip_with<listify, push_front<list<list<T0>>,
				                                     fold_left<group_pred<Pred>,
				                                               unpack<rotate<mpl::uint_<1>, C>>>>>,
				        sizeof...(Ts)>::template f<call<take<uint_<sizeof...(Ts)>>, T0, Ts...>,
				                                   list<Ts...>>;
			};
		} // namespace detail

		/// \brief Group adjacent elements that respect a predicate in a sublist
		/// \requires Type `Pred` shall be a `continuation binary predicate` and `C` shall be any
		/// `continuation`.
		/// \example call<group<is_same<>>,void,void,int,void>
		/// resolves to list<list<void,void>,list<int>,list<void>>
		template <typename Pred = is_same<>, typename C = listify>
		struct group {
			template <typename... Ts>
			using f = typename detail::group_impl<C, sizeof...(Ts) != 0>::template f<Pred, Ts...>;
		};

		namespace eager {
			template <typename List, template <typename...> class Pred = std::is_same>
			using group = call<unpack<mpl::group<cfe<Pred>>>, List>;
		}
	} // namespace mpl
} // namespace kvasir

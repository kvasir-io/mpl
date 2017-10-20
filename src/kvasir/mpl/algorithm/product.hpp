//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../algorithm/fold_right.hpp"
#include "../algorithm/transform.hpp"
#include "../sequence/join.hpp"
#include "../sequence/push_back.hpp"
#include "../sequence/push_front.hpp"

namespace kvasir {
	namespace mpl {
		namespace detail {
			/// adds all the ts into the param list
			template <typename... Ts0>
			struct product_pusher_list {
				template <template <typename...> class F, typename... Ts1>
				using push = list<F<Ts0..., Ts1>...>;
			};

			template <template <typename...> class F, typename C>
			struct product_end_cont {};

			template <typename C, typename L>
			struct product_pusher;

			template <typename C, template <typename...> class L0, typename... Ts0>
			struct product_pusher<C, L0<Ts0...>> {
				template <typename... State>
				using f = typename dcall<join<C>, sizeof...(State)>::template f<
				        typename State::template push<product_pusher_list, Ts0...>...>;
			};

			template <template <typename...> class F, typename C, template <typename...> class L,
			          typename... Ts>
			struct product_pusher<product_end_cont<F, C>, L<Ts...>> {
				template <typename... State>
				using f = typename dcall<join<C>, sizeof...(State)>::template f<
				        typename State::template push<F, Ts...>...>;
			};
		} // namespace detail

		/// \brief creates an n-ary cartesian product
		template <typename F = listify, typename C = listify>
		struct product {
			template <typename... Ts>
			using f = call<typename dcall<fold_right<cfe<detail::product_pusher>>, sizeof...(Ts)>::
			                       template f<detail::product_end_cont<F::template f, C>, Ts...>,
			               detail::product_pusher_list<>>;
		};

		/// \exclude
		template <template <typename...> class F, typename C>
		struct product<cfe<F, identity>, C> {
			template <typename... Ts>
			using f = call<typename dcall<fold_right<cfe<detail::product_pusher>>, sizeof...(Ts)>::
			                       template f<detail::product_end_cont<F, C>, Ts...>,
			               detail::product_pusher_list<>>;
		};

		namespace eager {
			template <typename List, template <typename...> class F = list>
			using product = call<unpack<mpl::product<cfe<F>>>, List>;
		}
	} // namespace mpl
} // namespace kvasir

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
			struct product_pusher {};

			template <typename C, template <typename...> class L0, typename... Ts0>
			struct product_pusher<C, L0<Ts0...>> {
				template <typename... State>
				using f = typename join<C>::template f<
				        typename State::template push<product_pusher_list, Ts0...>...>;
			};

			template <typename C, template <typename...> class L0, typename... Ts0,
			          template <typename...> class L1, typename... Ts1>
			struct product_pusher<product_pusher<C, L1<Ts1...>>, L0<Ts0...>> {
				template <typename... State>
				using ts1_pusher =
				        typename product_pusher_list<State...>::template push<product_pusher_list,
				                                                              Ts1...>;

				template <typename... State>
				using f = typename join<join<C>>::template f<
				        typename State::template push<ts1_pusher, Ts0...>...>;
			};

			template <template <typename...> class F, typename C, template <typename...> class L,
			          typename... Ts>
			struct product_pusher<product_end_cont<F, C>, L<Ts...>> {
				template <typename... Ts1>
				using f = typename join<C>::template f<typename Ts1::template push<F, Ts...>...>;
			};

			template <template <typename...> class F, typename C, template <typename...> class L0,
			          typename... Ts0, template <typename...> class L1, typename... Ts1>
			struct product_pusher<product_pusher<product_end_cont<F, C>, L1<Ts1...>>, L0<Ts0...>> {
				template <typename... State>
				using ts1_pusher = typename product_pusher_list<State...>::template push<F, Ts1...>;

				template <typename... State>
				using f = typename join<join<C>>::template f<
				        typename State::template push<ts1_pusher, Ts0...>...>;
			};
		}

		template <typename F = listify, typename C = listify>
		struct product {
			template <typename... Ts>
			using f = call<call<fold_right<cfe<detail::product_pusher>>,
			                    detail::product_end_cont<F::template f, C>, Ts...>,
			               detail::product_pusher_list<>>;
		};

		template <template <typename...> class F, typename C>
		struct product<cfe<F, identity>, C> {
			template <typename... Ts>
			using f = call<call<fold_right<cfe<detail::product_pusher>>,
			                    detail::product_end_cont<F, C>, Ts...>,
			               detail::product_pusher_list<>>;
		};

		namespace eager {
			template <typename List, template <typename...> class F = list>
			using product = call<unpack<mpl::product<cfe<F>>>, List>;
		}
	}
}

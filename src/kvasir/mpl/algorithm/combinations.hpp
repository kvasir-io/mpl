//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../algorithm/reverse.hpp"
#include "../functional/flow.hpp"
#include "../functions/comparison/greater_than.hpp"
#include "../sequence/front.hpp"
#include "../sequence/join.hpp"
#include "../sequence/push_back.hpp"
#include "../sequence/size.hpp"
#include "../types/int.hpp"
#include "../utility/always.hpp"

namespace kvasir {
	namespace mpl {
		namespace detail {
			constexpr unsigned combinations_single_impl_select(unsigned n) {
				return n >= 2 ? 2 : n >= 1 ? 1 : 0;
			}

			/// get all the combinations for a pack, calling the function F as F<T, (pack-T...)> for
			/// every combination
			/// the pred should thus be defined as template<typename T, typename ...Other>
			/// this means that the predicate will always have a first element, so you can rely on
			/// functions like front<>
			/// \tparam n
			template <unsigned n>
			struct combinations_single_impl {
				template <typename F, typename PrevTypes, typename...>
				using f = detail::rlist_tail_of8;
			};

			template <>
			struct combinations_single_impl<1> {
				template <typename F, typename PrevTypes, typename T0, typename... Ts>
				using f = detail::rlist<
				        list<call<join<F>, list<T0>, PrevTypes, list<Ts...>>>,
				        typename combinations_single_impl<combinations_single_impl_select(sizeof...(
				                Ts))>::template f<F,
				                                  typename join<>::template f<PrevTypes, list<T0>>,
				                                  Ts...>>;
			};

			template <>
			struct combinations_single_impl<2> {
				template <typename F, typename PrevTypes, typename T0, typename T1, typename... Ts>
				using f = detail::rlist<
				        list<call<join<F>, list<T0>, PrevTypes, list<T1>, list<Ts...>>,
				             call<join<F>, list<T1>, PrevTypes, list<T0>, list<Ts...>>>,
				        typename combinations_single_impl<combinations_single_impl_select(
				                sizeof...(Ts))>::
				                template f<F, typename join<>::template f<PrevTypes, list<T0, T1>>,
				                           Ts...>>;
			};

			template <typename F = listify, typename C = listify>
			struct combinations_single {
				template <typename... Ts>
				using f = typename detail::recursive_join<C>::template f<
				        typename combinations_single_impl<combinations_single_impl_select(
				                sizeof...(Ts))>::template f<F, list<>, Ts...>>;
			};

			// TODO can be fast tracked for higher dimensions
			template <unsigned n, typename FrontC, typename FullC, typename... Prev>
			struct combinations_impl {
				template <typename T, typename... Ts>
				using f = typename combinations_single<
				        combinations_impl<(n - 1), FrontC, FullC, T, Prev...>,
				        join<>>::template f<Ts...>;
			};

			template <typename FrontC, typename FullC, typename... Prev>
			struct combinations_impl<1, FrontC, FullC, Prev...> {
				template <typename T, typename... Ts>
				using f = typename combinations_single<
				        combinations_impl<0, FrontC, FullC, T, Prev...>,
				        listify>::template f<Ts...>;
			};

			template <typename FrontC, typename FullC, typename... Prev>
			struct combinations_impl<0, FrontC, FullC, Prev...> {
				template <typename T, typename... Ts>
				// reverse ordering is needed as a workaround for a bug in gcc <= 4.8, which
				// doesn't like non-pack parameters as the last argument in a template instantiation
				using f = call<FullC, call<reverse<FrontC>, T, Prev...>, Ts...>;
			};
		}

		template <typename N, typename FrontC, typename FullC, typename C>
		using combinations =
		        if_<size<push_back<uint_<0>, greater_than<>>>,
		            detail::combinations_single<
		                    detail::combinations_impl<(N::value - 1), FrontC, FullC>, join<C>>,
		            always<list<>, C>>;
	}
}

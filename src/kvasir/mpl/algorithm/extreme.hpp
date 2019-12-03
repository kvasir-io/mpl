//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../functional/identity.hpp"

namespace kvasir {
	namespace mpl {
		namespace detail {
			constexpr unsigned extreme_impl_select(unsigned n) {
				return n >= 16 ? 16 : n >= 8 ? 8 : n >= 4 ? 4 : n >= 2 ? 2 : n >= 1 ? 1 : 0;
			}

			/// this implementation of extreme does a tournament-style elimination between the
			/// elements, costing about n comparisons, but resulting in a approx O(log(n))
			/// runtime instead of the traditional O(N^2) using fold
			template <unsigned n>
			struct extreme_impl {
				// no elements, no extreme
				template <typename C, template <typename...> class Pred, typename... Ts>
				using f = typename C::template f<>;
			};

			template <>
			struct extreme_impl<1> {
				template <typename C, template <typename...> class Pred, typename Result,
				          typename... Ts>
				using f = typename C::template f<Result>;
			};

			template <>
			struct extreme_impl<2> {
				template <typename C, template <typename...> class Pred, typename T0, typename T1,
				          typename... Ts>
				using f =
				        typename extreme_impl<(sizeof...(Ts) + 1)>::template f<C, Pred,
				                                                               Pred<T0, T1>, Ts...>;
			};

			template <>
			struct extreme_impl<4> {
				template <typename C, template <typename...> class Pred, typename T0, typename T1,
				          typename T2, typename T3, typename... Ts>
				using f = typename extreme_impl<extreme_impl_select(
				        sizeof...(Ts) + 2)>::template f<C, Pred, Pred<T0, T1>, Pred<T2, T3>, Ts...>;
			};

			template <>
			struct extreme_impl<8> {
				template <typename C, template <typename...> class Pred, typename T0, typename T1,
				          typename T2, typename T3, typename T4, typename T5, typename T6,
				          typename T7, typename... Ts>
				using f = typename extreme_impl<extreme_impl_select(sizeof...(Ts) + 4)>::template f<
				        C, Pred, Pred<T0, T1>, Pred<T2, T3>, Pred<T4, T5>, Pred<T6, T7>, Ts...>;
			};

			template <>
			struct extreme_impl<16> {
				template <typename C, template <typename...> class Pred, typename T0, typename T1,
				          typename T2, typename T3, typename T4, typename T5, typename T6,
				          typename T7, typename T8, typename T9, typename T10, typename T11,
				          typename T12, typename T13, typename T14, typename T15, typename... Ts>
				using f = typename extreme_impl<extreme_impl_select(sizeof...(Ts) + 8)>::template f<
				        C, Pred, Pred<T0, T1>, Pred<T2, T3>, Pred<T4, T5>, Pred<T6, T7>,
				        Pred<T8, T9>, Pred<T10, T11>, Pred<T12, T13>, Pred<T14, T15>, Ts...>;
			};
		}

		template <typename Pred, typename C = identity>
		struct extreme {
			template <typename... Ts>
			using f = typename detail::extreme_impl<detail::extreme_impl_select(
			        sizeof...(Ts))>::template f<C, Pred::template f, Ts...>;
		};
	}
}

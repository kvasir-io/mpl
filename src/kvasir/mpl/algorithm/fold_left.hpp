//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <utility>

#include "../functional/call.hpp"
#include "../sequence/pop_front.hpp"
#include "../sequence/push_front.hpp"
#include "../sequence/size.hpp"
#include "../types/list.hpp"

namespace kvasir {
	namespace mpl {
		namespace detail {
			static constexpr int select_fold(const int in) {
				return /*in >= 256 ? 256 :*/ in >= 64 ? 64 : in >= 16 ?
				                                        16 :
				                                        in >= 4 ? 4 : in >= 2 ? 2 : in == 1 ? 1 : 0;
			}
			template <int>
			struct fold_impl;
			template <>
			struct fold_impl<0> {
				template <template <typename...> class F, typename In>
				using f = In;
			};
			template <>
			struct fold_impl<1> {
				template <template <typename...> class F, typename In, typename T0>
				using f = F<In, T0>;
			};
			template <>
			struct fold_impl<2> {
				template <template <typename...> class F, typename In, typename T0, typename T1,
				          typename... Ts>
				using f = typename fold_impl<select_fold(
				        sizeof...(Ts))>::template f<F, F<F<In, T0>, T1>, Ts...>;
			};
			template <>
			struct fold_impl<4> {
				template <template <typename...> class F, typename In, typename T0, typename T1,
				          typename T2, typename T3, typename... Ts>
				using f = typename fold_impl<select_fold(
				        sizeof...(Ts))>::template f<F, F<F<F<F<In, T0>, T1>, T2>, T3>, Ts...>;
			};
			template <>
			struct fold_impl<16> {
				template <template <typename...> class F, typename In, typename T0, typename T1,
				          typename T2, typename T3, typename T4, typename T5, typename T6,
				          typename T7, typename T8, typename T9, typename T10, typename T11,
				          typename T12, typename T13, typename T14, typename T15, typename... Ts>
				using f = typename fold_impl<select_fold(sizeof...(Ts))>::template f<
				        F,
				        F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<In, T0>, T1>, T2>, T3>, T4>, T5>, T6>, T7>,
				                        T8>,
				                      T9>,
				                    T10>,
				                  T11>,
				                T12>,
				              T13>,
				            T14>,
				          T15>,
				        Ts...>;
			};
			template <>
			struct fold_impl<64> {
				template <template <typename...> class F, typename In, typename T0, typename T1,
				          typename T2, typename T3, typename T4, typename T5, typename T6,
				          typename T7, typename T8, typename T9, typename T10, typename T11,
				          typename T12, typename T13, typename T14, typename T15, typename T16,
				          typename T17, typename T18, typename T19, typename T20, typename T21,
				          typename T22, typename T23, typename T24, typename T25, typename T26,
				          typename T27, typename T28, typename T29, typename T30, typename T31,
				          typename T32, typename T33, typename T34, typename T35, typename T36,
				          typename T37, typename T38, typename T39, typename T40, typename T41,
				          typename T42, typename T43, typename T44, typename T45, typename T46,
				          typename T47, typename T48, typename T49, typename T50, typename T51,
				          typename T52, typename T53, typename T54, typename T55, typename T56,
				          typename T57, typename T58, typename T59, typename T60, typename T61,
				          typename T62, typename T63, typename... Ts>
				using f = typename fold_impl<select_fold(sizeof...(Ts))>::template f<
				        F,
				        F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<In, T0>,
				                                                                                                                                      T1>,
				                                                                                                                                    T2>,
				                                                                                                                                  T3>,
				                                                                                                                                T4>,
				                                                                                                                              T5>,
				                                                                                                                            T6>,
				                                                                                                                          T7>,
				                                                                                                                        T8>,
				                                                                                                                      T9>,
				                                                                                                                    T10>,
				                                                                                                                  T11>,
				                                                                                                                T12>,
				                                                                                                              T13>,
				                                                                                                            T14>,
				                                                                                                          T15>,
				                                                                                                        T16>,
				                                                                                                      T17>,
				                                                                                                    T18>,
				                                                                                                  T19>,
				                                                                                                T20>,
				                                                                                              T21>,
				                                                                                            T22>,
				                                                                                          T23>,
				                                                                                        T24>,
				                                                                                      T25>,
				                                                                                    T26>,
				                                                                                  T27>,
				                                                                                T28>,
				                                                                              T29>,
				                                                                            T30>,
				                                                                          T31>,
				                                                                        T32>,
				                                                                      T33>,
				                                                                    T34>,
				                                                                  T35>,
				                                                                T36>,
				                                                              T37>,
				                                                            T38>,
				                                                          T39>,
				                                                        T40>,
				                                                      T41>,
				                                                    T42>,
				                                                  T43>,
				                                                T44>,
				                                              T45>,
				                                            T46>,
				                                          T47>,
				                                        T48>,
				                                      T49>,
				                                    T50>,
				                                  T51>,
				                                T52>,
				                              T53>,
				                            T54>,
				                          T55>,
				                        T56>,
				                      T57>,
				                    T58>,
				                  T59>,
				                T60>,
				              T61>,
				            T62>,
				          T63>,
				        Ts...>;
			};
		} // namespace detail
		/// \brief folds left over a list using a binary predicate /
		/// fold left consideres the first element in the input pack the state, use `push_front<>`
		/// to add state if needed
		template <typename F, typename C = identity>
		struct fold_left {
			template <typename... Ts>
			using f = typename C::template f<typename detail::fold_impl<detail::select_fold(
			        sizeof...(Ts)-1)>::template f<F::template f, Ts...>>;
		};
		/// \exclude
		template <template <typename...> class F, typename C>
		struct fold_left<cfe<F, identity>, C> {
			template <typename... Ts>
			using f = typename C::template f<typename detail::fold_impl<detail::select_fold(
			        sizeof...(Ts)-1)>::template f<F, Ts...>>;
		};

		namespace eager {
			template <typename List, typename State, template <typename...> class Func>
			using fold_left = call<unpack<mpl::push_front<State, mpl::fold_left<cfe<Func>>>>, List>;
		}
	} // namespace mpl
} // namespace kvasir

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
			static constexpr int select_fold_right(const int in) {
				return /*in >= 256 ? 256 :*/ in >= 64 ? 64 : in >= 16 ?
				                                        16 :
				                                        in >= 4 ? 4 : in >= 2 ? 2 : in == 1 ? 1 : 0;
			}
			template <int>
			struct fold_right_impl;
			template <>
			struct fold_right_impl<0> {
				template <template <typename...> class F, typename In>
				using f = In;
			};
			template <>
			struct fold_right_impl<1> {
				template <template <typename...> class F, typename In, typename T0>
				using f = F<In, T0>;
			};
			template <>
			struct fold_right_impl<2> {
				template <template <typename...> class F, typename In, typename T0, typename T1,
				          typename... Ts>
				using f = F<F<typename fold_right_impl<select_fold_right(
				                      sizeof...(Ts))>::template f<F, In, Ts...>,
				              T1>,
				            T0>;
			};
			template <>
			struct fold_right_impl<4> {
				template <template <typename...> class F, typename In, typename T0, typename T1,
				          typename T2, typename T3, typename... Ts>
				using f = F<F<F<F<typename fold_right_impl<select_fold_right(
				                          sizeof...(Ts))>::template f<F, In, Ts...>,
				                  T3>,
				                T2>,
				              T1>,
				            T0>;
			};
			template <>
			struct fold_right_impl<16> {
				template <template <typename...> class F, typename In, typename T0, typename T1,
				          typename T2, typename T3, typename T4, typename T5, typename T6,
				          typename T7, typename T8, typename T9, typename T10, typename T11,
				          typename T12, typename T13, typename T14, typename T15, typename... Ts>
				using f =
				        F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<typename fold_right_impl<select_fold_right(
				                                                sizeof...(Ts))>::template f<F, In,
				                                                                            Ts...>,
				                                        T15>,
				                                      T14>,
				                                    T13>,
				                                  T12>,
				                                T11>,
				                              T10>,
				                            T9>,
				                          T8>,
				                        T7>,
				                      T6>,
				                    T5>,
				                  T4>,
				                T3>,
				              T2>,
				            T1>,
				          T0>;
			};
			template <>
			struct fold_right_impl<64> {
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
				using f = F<
				        F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<F<typename fold_right_impl<select_fold_right(
				                                                                                                                                              sizeof...(Ts))>::
				                                                                                                                                              template f<
				                                                                                                                                                      F, In,
				                                                                                                                                                      Ts...>,
				                                                                                                                                      T63>,
				                                                                                                                                    T62>,
				                                                                                                                                  T61>,
				                                                                                                                                T60>,
				                                                                                                                              T59>,
				                                                                                                                            T58>,
				                                                                                                                          T57>,
				                                                                                                                        T56>,
				                                                                                                                      T55>,
				                                                                                                                    T54>,
				                                                                                                                  T53>,
				                                                                                                                T52>,
				                                                                                                              T51>,
				                                                                                                            T50>,
				                                                                                                          T49>,
				                                                                                                        T48>,
				                                                                                                      T47>,
				                                                                                                    T46>,
				                                                                                                  T45>,
				                                                                                                T44>,
				                                                                                              T43>,
				                                                                                            T42>,
				                                                                                          T41>,
				                                                                                        T40>,
				                                                                                      T39>,
				                                                                                    T38>,
				                                                                                  T37>,
				                                                                                T36>,
				                                                                              T35>,
				                                                                            T34>,
				                                                                          T33>,
				                                                                        T32>,
				                                                                      T31>,
				                                                                    T30>,
				                                                                  T29>,
				                                                                T28>,
				                                                              T27>,
				                                                            T26>,
				                                                          T25>,
				                                                        T24>,
				                                                      T23>,
				                                                    T22>,
				                                                  T21>,
				                                                T20>,
				                                              T19>,
				                                            T18>,
				                                          T17>,
				                                        T16>,
				                                      T15>,
				                                    T14>,
				                                  T13>,
				                                T12>,
				                              T11>,
				                            T10>,
				                          T9>,
				                        T8>,
				                      T7>,
				                    T6>,
				                  T5>,
				                T4>,
				              T3>,
				            T2>,
				          T1>,
				        T0>;
			};
		} // namespace detail
		/// \breif fold right consideres the first element in the input pack the state, use
		/// push_front to add state if needed
		template <typename F, typename C = identity>
		struct fold_right {
			template <typename... Ts>
			using f = typename C::template f<typename detail::fold_right_impl<
			        detail::select_fold_right(sizeof...(Ts)-1)>::template f<F::template f, Ts...>>;
		};
		/// \exclude
		template <template <typename...> class F, typename C>
		struct fold_right<cfe<F, identity>, C> {
			template <typename... Ts>
			using f = typename C::template f<typename detail::fold_right_impl<
			        detail::select_fold_right(sizeof...(Ts)-1)>::template f<F, Ts...>>;
		};

		namespace eager {
			/// fold right over a list, initialized with State
			template <typename List, typename State, template <typename...> class Func>
			using fold_right = call<unpack<mpl::push_front<State, fold_right<cfe<Func>>>>, List>;
		} // namespace eager
	} // namespace mpl
} // namespace kvasir

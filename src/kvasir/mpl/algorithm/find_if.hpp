//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

//#include <cstddef>

#include "../functional/bind.hpp"
#include "../functional/call.hpp"
#include "../functional/identity.hpp"
#include "../types/list.hpp"

namespace kvasir {
	namespace mpl {
		namespace c {
			namespace detail {
				constexpr unsigned first_find(const unsigned size) {
					return size >= 64 ? 14 : size >= 16 ? 13 : size >= 4 ? 12 : size >= 1 ? 11 : 0;
				}
				constexpr unsigned find_any(const unsigned size, const bool b0) {
					return b0 ? 1 : size == 0 ? 0 : 2;
				}
				constexpr unsigned find_any(const unsigned size, const bool b0, const bool b1,
				                            const bool b2, const bool b3) {
					return b0 ? 1 : (b1 || b2 || b3) ? 2 : size >= 4 ? 3 : 2;
				}
				constexpr unsigned find_any(const unsigned size, const bool b0, const bool b1,
				                            const bool b2, const bool b3, const bool b4,
				                            const bool b5, const bool b6, const bool b7,
				                            const bool b8, const bool b9, const bool b10,
				                            const bool b11, const bool b12, const bool b13,
				                            const bool b14, const bool b15) {
					return b0 ? 1 : (b1 || b2 || b3) ? 2 :
					                                   (b4 || b5 || b6 || b7 || b8 || b9 || b10 ||
					                                    b11 || b12 || b13 || b14 || b15) ?
					                                   3 :
					                                   size >= 16 ? 4 : 3;
				}
				constexpr unsigned
				find_any(const unsigned size, const bool b0, const bool b1, const bool b2,
				         const bool b3, const bool b4, const bool b5, const bool b6, const bool b7,
				         const bool b8, const bool b9, const bool b10, const bool b11,
				         const bool b12, const bool b13, const bool b14, const bool b15,
				         const bool b16, const bool b17, const bool b18, const bool b19,
				         const bool b20, const bool b21, const bool b22, const bool b23,
				         const bool b24, const bool b25, const bool b26, const bool b27,
				         const bool b28, const bool b29, const bool b30, const bool b31,
				         const bool b32, const bool b33, const bool b34, const bool b35,
				         const bool b36, const bool b37, const bool b38, const bool b39,
				         const bool b40, const bool b41, const bool b42, const bool b43,
				         const bool b44, const bool b45, const bool b46, const bool b47,
				         const bool b48, const bool b49, const bool b50, const bool b51,
				         const bool b52, const bool b53, const bool b54, const bool b55,
				         const bool b56, const bool b57, const bool b58, const bool b59,
				         const bool b60, const bool b61, const bool b62, const bool b63) {
					return b0 ? 1 : (b1 || b2 || b3) ?
					            2 :
					            (b4 || b5 || b6 || b7 || b8 || b9 || b10 || b11 || b12 || b13 ||
					             b14 || b15) ?
					            3 :
					            (b16 || b17 || b18 || b19 || b20 || b21 || b22 || b23 || b24 ||
					             b25 || b26 || b27 || b28 || b29 || b30 || b31 || b32 || b33 ||
					             b34 || b35 || b36 || b37 || b38 || b39 || b40 || b41 || b42 ||
					             b43 || b44 || b45 || b46 || b47 || b48 || b49 || b50 || b51 ||
					             b52 || b53 || b54 || b55 || b56 || b57 || b58 || b59 || b60 ||
					             b61 || b62 || b63) ?
					            4 :
					            size >= 64 ? 5 : 4;
				}
				template <unsigned, typename C>
				struct find_if_impl;
				template <typename C>
				struct find_if_impl<0, C> { // not found
					template <template <typename...> class F, typename... Ts>
					using f = typename C::template f<>;
				};
				template <typename C>
				struct find_if_impl<1, C> {
					template <template <typename...> class F, typename... Ts>
					using f = typename C::template f<Ts...>;
				}; // found

				template <typename C>
				struct find_if_impl<2, C> {
					template <template <typename...> class F, typename R, typename T,
					          typename... Ts>
					using f = typename find_if_impl<find_any(sizeof...(Ts), F<T>::value),
					                                C>::template f<F, T, Ts...>;
				};
				template <typename C>
				struct find_if_impl<3, C> {
					template <template <typename...> class F, typename R0, typename R1, typename R2,
					          typename R3, typename T0, typename T1, typename T2, typename T3,
					          typename... Ts>
					using f = typename find_if_impl<find_any(sizeof...(Ts), F<T0>::value,
					                                         F<T1>::value, F<T2>::value,
					                                         F<T3>::value),
					                                C>::template f<F, T0, T1, T2, T3, Ts...>;
				};
				template <typename C>
				struct find_if_impl<4, C> {
					template <template <typename...> class F, typename R0, typename R1, typename R2,
					          typename R3, typename R4, typename R5, typename R6, typename R7,
					          typename R8, typename R9, typename R10, typename R11, typename R12,
					          typename R13, typename R14, typename R15, typename T0, typename T1,
					          typename T2, typename T3, typename T4, typename T5, typename T6,
					          typename T7, typename T8, typename T9, typename T10, typename T11,
					          typename T12, typename T13, typename T14, typename T15,
					          typename... Ts>
					using f = typename find_if_impl<
					        find_any(sizeof...(Ts), F<T0>::value, F<T1>::value, F<T2>::value,
					                 F<T3>::value, F<T4>::value, F<T5>::value, F<T6>::value,
					                 F<T7>::value, F<T8>::value, F<T9>::value, F<T10>::value,
					                 F<T11>::value, F<T12>::value, F<T13>::value, F<T14>::value,
					                 F<T15>::value),
					        C>::template f<F, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
					                       T13, T14, T15, Ts...>;
				};
				template <typename C>
				struct find_if_impl<5, C> {
					template <template <typename...> class F, typename R0, typename R1, typename R2,
					          typename R3, typename R4, typename R5, typename R6, typename R7,
					          typename R8, typename R9, typename R10, typename R11, typename R12,
					          typename R13, typename R14, typename R15, typename R16, typename R17,
					          typename R18, typename R19, typename R20, typename R21, typename R22,
					          typename R23, typename R24, typename R25, typename R26, typename R27,
					          typename R28, typename R29, typename R30, typename R31, typename R32,
					          typename R33, typename R34, typename R35, typename R36, typename R37,
					          typename R38, typename R39, typename R40, typename R41, typename R42,
					          typename R43, typename R44, typename R45, typename R46, typename R47,
					          typename R48, typename R49, typename R50, typename R51, typename R52,
					          typename R53, typename R54, typename R55, typename R56, typename R57,
					          typename R58, typename R59, typename R60, typename R61, typename R62,
					          typename R63, typename T0, typename T1, typename T2, typename T3,
					          typename T4, typename T5, typename T6, typename T7, typename T8,
					          typename T9, typename T10, typename T11, typename T12, typename T13,
					          typename T14, typename T15, typename T16, typename T17, typename T18,
					          typename T19, typename T20, typename T21, typename T22, typename T23,
					          typename T24, typename T25, typename T26, typename T27, typename T28,
					          typename T29, typename T30, typename T31, typename T32, typename T33,
					          typename T34, typename T35, typename T36, typename T37, typename T38,
					          typename T39, typename T40, typename T41, typename T42, typename T43,
					          typename T44, typename T45, typename T46, typename T47, typename T48,
					          typename T49, typename T50, typename T51, typename T52, typename T53,
					          typename T54, typename T55, typename T56, typename T57, typename T58,
					          typename T59, typename T60, typename T61, typename T62, typename T63,
					          typename... Ts>
					using f = typename find_if_impl<
					        find_any(sizeof...(Ts), F<T0>::value, F<T1>::value, F<T2>::value,
					                 F<T3>::value, F<T4>::value, F<T5>::value, F<T6>::value,
					                 F<T7>::value, F<T8>::value, F<T9>::value, F<T10>::value,
					                 F<T11>::value, F<T12>::value, F<T13>::value, F<T14>::value,
					                 F<T15>::value, F<T16>::value, F<T17>::value, F<T18>::value,
					                 F<T19>::value, F<T20>::value, F<T21>::value, F<T22>::value,
					                 F<T23>::value, F<T24>::value, F<T25>::value, F<T26>::value,
					                 F<T27>::value, F<T28>::value, F<T29>::value, F<T30>::value,
					                 F<T31>::value, F<T32>::value, F<T33>::value, F<T34>::value,
					                 F<T35>::value, F<T36>::value, F<T37>::value, F<T38>::value,
					                 F<T39>::value, F<T40>::value, F<T41>::value, F<T42>::value,
					                 F<T43>::value, F<T44>::value, F<T45>::value, F<T46>::value,
					                 F<T47>::value, F<T48>::value, F<T49>::value, F<T50>::value,
					                 F<T51>::value, F<T52>::value, F<T53>::value, F<T54>::value,
					                 F<T55>::value, F<T56>::value, F<T57>::value, F<T58>::value,
					                 F<T59>::value, F<T60>::value, F<T61>::value, F<T62>::value,
					                 F<T63>::value),
					        C>::template f<F, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
					                       T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23,
					                       T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34,
					                       T35, T36, T37, T38, T39, T40, T41, T42, T43, T44, T45,
					                       T46, T47, T48, T49, T50, T51, T52, T53, T54, T55, T56,
					                       T57, T58, T59, T60, T61, T62, T63, Ts...>;
				};
				template <typename C>
				struct find_if_impl<11, C> { // start 1
					template <template <typename...> class F, typename T0, typename... Ts>
					using f = typename find_if_impl<find_any(sizeof...(Ts), F<T0>::value),
					                                C>::template f<F, T0, Ts...>;
				};
				template <typename C>
				struct find_if_impl<12, C> { // start 4
					template <template <typename...> class F, typename T0, typename T1, typename T2,
					          typename T3, typename... Ts>
					using f = typename find_if_impl<find_any(sizeof...(Ts), F<T0>::value,
					                                         F<T1>::value, F<T2>::value,
					                                         F<T3>::value),
					                                C>::template f<F, T0, T1, T2, T3, Ts...>;
				};
				template <typename C>
				struct find_if_impl<13, C> { // start 16
					template <template <typename...> class F, typename T0, typename T1, typename T2,
					          typename T3, typename T4, typename T5, typename T6, typename T7,
					          typename T8, typename T9, typename T10, typename T11, typename T12,
					          typename T13, typename T14, typename T15, typename... Ts>
					using f = typename find_if_impl<
					        find_any(sizeof...(Ts), F<T0>::value, F<T1>::value, F<T2>::value,
					                 F<T3>::value, F<T4>::value, F<T5>::value, F<T6>::value,
					                 F<T7>::value, F<T8>::value, F<T9>::value, F<T10>::value,
					                 F<T11>::value, F<T12>::value, F<T13>::value, F<T14>::value,
					                 F<T15>::value),
					        C>::template f<F, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
					                       T13, T14, T15, Ts...>;
				};
				template <typename C>
				struct find_if_impl<14, C> { // start 64
					template <template <typename...> class F, typename T0, typename T1, typename T2,
					          typename T3, typename T4, typename T5, typename T6, typename T7,
					          typename T8, typename T9, typename T10, typename T11, typename T12,
					          typename T13, typename T14, typename T15, typename T16, typename T17,
					          typename T18, typename T19, typename T20, typename T21, typename T22,
					          typename T23, typename T24, typename T25, typename T26, typename T27,
					          typename T28, typename T29, typename T30, typename T31, typename T32,
					          typename T33, typename T34, typename T35, typename T36, typename T37,
					          typename T38, typename T39, typename T40, typename T41, typename T42,
					          typename T43, typename T44, typename T45, typename T46, typename T47,
					          typename T48, typename T49, typename T50, typename T51, typename T52,
					          typename T53, typename T54, typename T55, typename T56, typename T57,
					          typename T58, typename T59, typename T60, typename T61, typename T62,
					          typename T63, typename... Ts>
					using f = typename find_if_impl<
					        find_any(sizeof...(Ts), F<T0>::value, F<T1>::value, F<T2>::value,
					                 F<T3>::value, F<T4>::value, F<T5>::value, F<T6>::value,
					                 F<T7>::value, F<T8>::value, F<T9>::value, F<T10>::value,
					                 F<T11>::value, F<T12>::value, F<T13>::value, F<T14>::value,
					                 F<T15>::value, F<T16>::value, F<T17>::value, F<T18>::value,
					                 F<T19>::value, F<T20>::value, F<T21>::value, F<T22>::value,
					                 F<T23>::value, F<T24>::value, F<T25>::value, F<T26>::value,
					                 F<T27>::value, F<T28>::value, F<T29>::value, F<T30>::value,
					                 F<T31>::value, F<T32>::value, F<T33>::value, F<T34>::value,
					                 F<T35>::value, F<T36>::value, F<T37>::value, F<T38>::value,
					                 F<T39>::value, F<T40>::value, F<T41>::value, F<T42>::value,
					                 F<T43>::value, F<T44>::value, F<T45>::value, F<T46>::value,
					                 F<T47>::value, F<T48>::value, F<T49>::value, F<T50>::value,
					                 F<T51>::value, F<T52>::value, F<T53>::value, F<T54>::value,
					                 F<T55>::value, F<T56>::value, F<T57>::value, F<T58>::value,
					                 F<T59>::value, F<T60>::value, F<T61>::value, F<T62>::value,
					                 F<T63>::value),
					        C>::template f<F, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
					                       T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23,
					                       T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34,
					                       T35, T36, T37, T38, T39, T40, T41, T42, T43, T44, T45,
					                       T46, T47, T48, T49, T50, T51, T52, T53, T54, T55, T56,
					                       T57, T58, T59, T60, T61, T62, T63, Ts...>;
				};
			}
			template <typename F, typename C = listify>
			struct find_if {
				template <typename... Ts>
				using f = typename detail::find_if_impl<detail::first_find(sizeof...(Ts)),
				                                        C>::template f<F::template f, Ts...>;
			};
		}

		/// fold left over a list, initialized with State
		template <typename List, template <typename...> class Cond = identity>
		using find_if = c::call<c::find_if<c::cfe<Cond>>, List>;
	}
}

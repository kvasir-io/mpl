//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../functional/call.hpp"
#include "../sequence/front.hpp"
#include "../types/int.hpp"

namespace kvasir {
	namespace mpl {
		namespace detail {

			constexpr unsigned select_next_drop_step(unsigned N, unsigned) {
				return N > 256 ? 256 : N > 64 ? 64 : N > 16 ? 16 : N > 8 ? 8 : N;
			}

			template <unsigned N, typename C>
			struct drop_impl;

			template <typename C>
			struct drop_impl<0, C> {
				template <unsigned N, typename... Ts>
				using f = typename conditional<(sizeof...(Ts) <
				                                1000000)>::template f<C, void>::template f<Ts...>;
			};

			template <typename C>
			struct drop_impl<1, C> {
				template <unsigned N, typename T, typename... Ts>
				using f = typename conditional<(sizeof...(Ts) <
				                                1000000)>::template f<C, void>::template f<Ts...>;
			};
			template <typename C>
			struct drop_impl<2, C> {
				template <unsigned N, typename T0, typename T1, typename... Ts>
				using f = typename conditional<(sizeof...(Ts) <
				                                1000000)>::template f<C, void>::template f<Ts...>;
			};
			template <typename C>
			struct drop_impl<3, C> {
				template <unsigned N, typename T0, typename T1, typename T2, typename... Ts>
				using f = typename conditional<(sizeof...(Ts) <
				                                1000000)>::template f<C, void>::template f<Ts...>;
			};
			template <typename C>
			struct drop_impl<4, C> {
				template <unsigned N, typename T0, typename T1, typename T2, typename T3,
				          typename... Ts>
				using f = typename conditional<(sizeof...(Ts) <
				                                1000000)>::template f<C, void>::template f<Ts...>;
			};
			template <typename C>
			struct drop_impl<5, C> {
				template <unsigned N, typename T0, typename T1, typename T2, typename T3,
				          typename T4, typename... Ts>
				using f = typename conditional<(sizeof...(Ts) <
				                                1000000)>::template f<C, void>::template f<Ts...>;
			};
			template <typename C>
			struct drop_impl<6, C> {
				template <unsigned N, typename T0, typename T1, typename T2, typename T3,
				          typename T4, typename T5, typename... Ts>
				using f = typename conditional<(sizeof...(Ts) <
				                                1000000)>::template f<C, void>::template f<Ts...>;
			};
			template <typename C>
			struct drop_impl<7, C> {
				template <unsigned N, typename T0, typename T1, typename T2, typename T3,
				          typename T4, typename T5, typename T6, typename... Ts>
				using f = typename conditional<(sizeof...(Ts) <
				                                1000000)>::template f<C, void>::template f<Ts...>;
			};
			template <typename C>
			struct drop_impl<8, C> {
				template <unsigned N, typename T0, typename T1, typename T2, typename T3,
				          typename T4, typename T5, typename T6, typename T7, typename... Ts>
				using f = typename drop_impl<N - 8, C>::template f<(N - 8), Ts...>;
			};
			template <typename C>
			struct drop_impl<16, C> {
				template <unsigned N, typename T0, typename T1, typename T2, typename T3,
				          typename T4, typename T5, typename T6, typename T7, typename T8,
				          typename T9, typename T10, typename T11, typename T12, typename T13,
				          typename T14, typename T15, typename... Ts>
				using f = typename drop_impl<select_next_drop_step(N - 16, sizeof...(Ts)),
				                             C>::template f<(N - 16), Ts...>;
			};
			template <typename C>
			struct drop_impl<64, C> {
				template <unsigned N, typename T0, typename T1, typename T2, typename T3,
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
				using f = typename drop_impl<select_next_drop_step(N - 64, sizeof...(Ts)),
				                             C>::template f<(N - 64), Ts...>;
			};
			template <typename C>
			struct drop_impl<256, C> {
				template <unsigned N, typename T0, typename T1, typename T2, typename T3,
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
				          typename T64, typename T65, typename T66, typename T67, typename T68,
				          typename T69, typename T70, typename T71, typename T72, typename T73,
				          typename T74, typename T75, typename T76, typename T77, typename T78,
				          typename T79, typename T80, typename T81, typename T82, typename T83,
				          typename T84, typename T85, typename T86, typename T87, typename T88,
				          typename T89, typename T90, typename T91, typename T92, typename T93,
				          typename T94, typename T95, typename T96, typename T97, typename T98,
				          typename T99, typename T100, typename T101, typename T102, typename T103,
				          typename T104, typename T105, typename T106, typename T107, typename T108,
				          typename T109, typename T110, typename T111, typename T112, typename T113,
				          typename T114, typename T115, typename T116, typename T117, typename T118,
				          typename T119, typename T120, typename T121, typename T122, typename T123,
				          typename T124, typename T125, typename T126, typename T127, typename T128,
				          typename T129, typename T130, typename T131, typename T132, typename T133,
				          typename T134, typename T135, typename T136, typename T137, typename T138,
				          typename T139, typename T140, typename T141, typename T142, typename T143,
				          typename T144, typename T145, typename T146, typename T147, typename T148,
				          typename T149, typename T150, typename T151, typename T152, typename T153,
				          typename T154, typename T155, typename T156, typename T157, typename T158,
				          typename T159, typename T160, typename T161, typename T162, typename T163,
				          typename T164, typename T165, typename T166, typename T167, typename T168,
				          typename T169, typename T170, typename T171, typename T172, typename T173,
				          typename T174, typename T175, typename T176, typename T177, typename T178,
				          typename T179, typename T180, typename T181, typename T182, typename T183,
				          typename T184, typename T185, typename T186, typename T187, typename T188,
				          typename T189, typename T190, typename T191, typename T192, typename T193,
				          typename T194, typename T195, typename T196, typename T197, typename T198,
				          typename T199, typename T200, typename T201, typename T202, typename T203,
				          typename T204, typename T205, typename T206, typename T207, typename T208,
				          typename T209, typename T210, typename T211, typename T212, typename T213,
				          typename T214, typename T215, typename T216, typename T217, typename T218,
				          typename T219, typename T220, typename T221, typename T222, typename T223,
				          typename T224, typename T225, typename T226, typename T227, typename T228,
				          typename T229, typename T230, typename T231, typename T232, typename T233,
				          typename T234, typename T235, typename T236, typename T237, typename T238,
				          typename T239, typename T240, typename T241, typename T242, typename T243,
				          typename T244, typename T245, typename T246, typename T247, typename T248,
				          typename T249, typename T250, typename T251, typename T252, typename T253,
				          typename T254, typename T255, typename... Ts>
				using f = typename drop_impl<select_next_drop_step(N - 256, sizeof...(Ts)),
				                             C>::template f<(N - 256), Ts...>;
			};
		} // namespace detail
		template <typename N, typename C = listify>
		struct drop {
			template <typename... Ts>
			using f = typename detail::drop_impl<detail::select_next_drop_step(N::value,
			                                                                   sizeof...(Ts)),
			                                     C>::template f<N::value, Ts...>;
		};

		// composition matching for common lambda cases
		template <typename C>
		struct drop<uint_<0>, front<C>> {
			template <typename T, typename... Ts>
			using f = typename C::template f<T>;
		};

		template <typename C>
		struct drop<uint_<1>, front<C>> {
			template <typename T0, typename T1, typename... Ts>
			using f = typename C::template f<T1>;
		};

		template <typename C>
		struct drop<uint_<2>, front<C>> {
			template <typename T0, typename T1, typename T2, typename... Ts>
			using f = typename C::template f<T2>;
		};

		template <typename C>
		struct drop<uint_<3>, front<C>> {
			template <typename T0, typename T1, typename T2, typename T3, typename... Ts>
			using f = typename C::template f<T3>;
		};

		template <>
		struct drop<uint_<0>, front<identity>> {
			template <typename T, typename... Ts>
			using f = T;
		};

		template <>
		struct drop<uint_<1>, front<identity>> {
			template <typename T0, typename T1, typename... Ts>
			using f = T1;
		};

		template <>
		struct drop<uint_<2>, front<identity>> {
			template <typename T0, typename T1, typename T2, typename... Ts>
			using f = T2;
		};

		template <>
		struct drop<uint_<3>, front<identity>> {
			template <typename T0, typename T1, typename T2, typename T3, typename... Ts>
			using f = T3;
		};

		namespace eager {
			template <typename List, unsigned Index>
			using drop = call<unpack<mpl::drop<mpl::uint_<Index>>>, List>;
		}
	} // namespace mpl
} // namespace kvasir

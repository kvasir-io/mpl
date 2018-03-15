//          Copyright Odin Holmes 2017.
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once
#include "../functional/call.hpp"
#include "../types/int.hpp"

namespace kvasir {
	namespace mpl {
		namespace detail {

			constexpr unsigned select_next_rotate_step(unsigned N, unsigned) {
				return N >= 256 ? 256 : N >= 64 ? 64 : N >= 16 ? 16 : N >= 8 ? 8 : N;
			}

			constexpr unsigned select_rotate_size(unsigned n, unsigned size) {
				return n >= size ? (size == 0 ? 0 : n % size) : n;
			}

			template <unsigned N, typename C>
			struct rotate_impl;

			template <typename C>
			struct rotate_impl<0, C> {
				template <unsigned N, typename... Ts>
				using f = typename conditional<(sizeof...(Ts) <
				                                1000000)>::template f<C, void>::template f<Ts...>;
			};

			template <typename C>
			struct rotate_impl<1, C> {
				template <unsigned N, typename T, typename... Ts>
				using f = typename conditional<(sizeof...(Ts) >
				                                0)>::template f<C, void>::template f<Ts..., T>;
			};
			template <typename C>
			struct rotate_impl<2, C> {
				template <unsigned N, typename T0, typename T1, typename... Ts>
				using f = typename conditional<(sizeof...(Ts) >
				                                0)>::template f<C, void>::template f<Ts..., T0, T1>;
			};
			template <typename C>
			struct rotate_impl<3, C> {
				template <unsigned N, typename T0, typename T1, typename T2, typename... Ts>
				using f = typename conditional<(
				        sizeof...(Ts) > 0)>::template f<C, void>::template f<Ts..., T0, T1, T2>;
			};
			template <typename C>
			struct rotate_impl<4, C> {
				template <unsigned N, typename T0, typename T1, typename T2, typename T3,
				          typename... Ts>
				using f = typename conditional<(
				        sizeof...(Ts) > 0)>::template f<C, void>::template f<Ts..., T0, T1, T2, T3>;
			};
			template <typename C>
			struct rotate_impl<5, C> {
				template <unsigned N, typename T0, typename T1, typename T2, typename T3,
				          typename T4, typename... Ts>
				using f = typename conditional<(sizeof...(Ts) > 0)>::template f<
				        C, void>::template f<Ts..., T0, T1, T2, T3, T4>;
			};
			template <typename C>
			struct rotate_impl<6, C> {
				template <unsigned N, typename T0, typename T1, typename T2, typename T3,
				          typename T4, typename T5, typename... Ts>
				using f = typename conditional<(sizeof...(Ts) > 0)>::template f<
				        C, void>::template f<Ts..., T0, T1, T2, T3, T4, T5>;
			};
			template <typename C>
			struct rotate_impl<7, C> {
				template <unsigned N, typename T0, typename T1, typename T2, typename T3,
				          typename T4, typename T5, typename T6, typename... Ts>
				using f = typename conditional<(sizeof...(Ts) > 0)>::template f<
				        C, void>::template f<Ts..., T0, T1, T2, T3, T4, T5, T6>;
			};
			template <typename C>
			struct rotate_impl<8, C> {
				template <unsigned N, typename T0, typename T1, typename T2, typename T3,
				          typename T4, typename T5, typename T6, typename T7, typename... Ts>
				using f = typename rotate_impl<select_next_rotate_step(N - 8, sizeof...(Ts)),
				                               C>::template f<(N - 8), Ts..., T0, T1, T2, T3, T4,
				                                              T5, T6, T7>;
			};
			template <typename C>
			struct rotate_impl<16, C> {
				template <unsigned N, typename T0, typename T1, typename T2, typename T3,
				          typename T4, typename T5, typename T6, typename T7, typename T8,
				          typename T9, typename T10, typename T11, typename T12, typename T13,
				          typename T14, typename T15, typename... Ts>
				using f = typename rotate_impl<select_next_rotate_step(N - 16, sizeof...(Ts)),
				                               C>::template f<(N - 16), Ts..., T0, T1, T2, T3, T4,
				                                              T5, T6, T7, T8, T9, T10, T11, T12,
				                                              T13, T14, T15>;
			};
			template <typename C>
			struct rotate_impl<64, C> {
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
				using f = typename rotate_impl<select_next_rotate_step(N - 64, sizeof...(Ts)), C>::
				        template f<(N - 64), Ts..., T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10,
				                   T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23,
				                   T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36,
				                   T37, T38, T39, T40, T41, T42, T43, T44, T45, T46, T47, T48, T49,
				                   T50, T51, T52, T53, T54, T55, T56, T57, T58, T59, T60, T61, T62,
				                   T63>;
			};
			template <typename C>
			struct rotate_impl<256, C> {
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
				using f = typename rotate_impl<select_next_rotate_step(N - 256, sizeof...(Ts)), C>::
				        template f<(N - 256), Ts..., T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10,
				                   T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23,
				                   T24, T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36,
				                   T37, T38, T39, T40, T41, T42, T43, T44, T45, T46, T47, T48, T49,
				                   T50, T51, T52, T53, T54, T55, T56, T57, T58, T59, T60, T61, T62,
				                   T63, T64, T65, T66, T67, T68, T69, T70, T71, T72, T73, T74, T75,
				                   T76, T77, T78, T79, T80, T81, T82, T83, T84, T85, T86, T87, T88,
				                   T89, T90, T91, T92, T93, T94, T95, T96, T97, T98, T99, T100,
				                   T101, T102, T103, T104, T105, T106, T107, T108, T109, T110, T111,
				                   T112, T113, T114, T115, T116, T117, T118, T119, T120, T121, T122,
				                   T123, T124, T125, T126, T127, T128, T129, T130, T131, T132, T133,
				                   T134, T135, T136, T137, T138, T139, T140, T141, T142, T143, T144,
				                   T145, T146, T147, T148, T149, T150, T151, T152, T153, T154, T155,
				                   T156, T157, T158, T159, T160, T161, T162, T163, T164, T165, T166,
				                   T167, T168, T169, T170, T171, T172, T173, T174, T175, T176, T177,
				                   T178, T179, T180, T181, T182, T183, T184, T185, T186, T187, T188,
				                   T189, T190, T191, T192, T193, T194, T195, T196, T197, T198, T199,
				                   T200, T201, T202, T203, T204, T205, T206, T207, T208, T209, T210,
				                   T211, T212, T213, T214, T215, T216, T217, T218, T219, T220, T221,
				                   T222, T223, T224, T225, T226, T227, T228, T229, T230, T231, T232,
				                   T233, T234, T235, T236, T237, T238, T239, T240, T241, T242, T243,
				                   T244, T245, T246, T247, T248, T249, T250, T251, T252, T253, T254,
				                   T255>;
			};
		} // namespace detail
		/// \brief moves N elements from the front of a list to the back of the list
		template <typename N, typename C = listify>
		struct rotate {
			template <typename... Ts>
			using f = typename detail::rotate_impl<
			        detail::select_next_rotate_step(
			                detail::select_rotate_size(N::value, sizeof...(Ts)), 0),
			        C>::template f<detail::select_rotate_size(N::value, sizeof...(Ts)), Ts...>;
		};

		namespace eager {
			template <typename List, unsigned Index>
			using rotate = call<unpack<mpl::rotate<mpl::uint_<Index>>>, List>;
		}
	} // namespace mpl
} // namespace kvasir

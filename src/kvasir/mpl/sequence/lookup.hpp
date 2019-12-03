//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../functional/call.hpp"
#include "../types/list.hpp"

namespace kvasir {
	namespace mpl {
		namespace detail {

			template <unsigned>
			struct index;
			template <>
			struct index<0> {
				template <typename T0, typename... Ts>
				using f = T0;
			};
			template <>
			struct index<1> {
				template <typename T0, typename T1, typename... Ts>
				using f = T1;
			};
			template <>
			struct index<2> {
				template <typename T0, typename T1, typename T2, typename... Ts>
				using f = T2;
			};
			template <>
			struct index<3> {
				template <typename T0, typename T1, typename T2, typename T3, typename... Ts>
				using f = T3;
			};
			template <>
			struct index<4> {
				template <typename T0, typename T1, typename T2, typename T3, typename T4,
				          typename... Ts>
				using f = T4;
			};
			template <>
			struct index<5> {
				template <typename T0, typename T1, typename T2, typename T3, typename T4,
				          typename T5, typename... Ts>
				using f = T5;
			};
			template <>
			struct index<6> {
				template <typename T0, typename T1, typename T2, typename T3, typename T4,
				          typename T5, typename T6, typename... Ts>
				using f = T6;
			};
			template <>
			struct index<7> {
				template <typename T0, typename T1, typename T2, typename T3, typename T4,
				          typename T5, typename T6, typename T7, typename... Ts>
				using f = T7;
			};
			template <>
			struct index<8> {
				template <typename T0, typename T1, typename T2, typename T3, typename T4,
				          typename T5, typename T6, typename T7, typename T8, typename... Ts>
				using f = T8;
			};
			template <>
			struct index<9> {
				template <typename T0, typename T1, typename T2, typename T3, typename T4,
				          typename T5, typename T6, typename T7, typename T8, typename T9,
				          typename... Ts>
				using f = T9;
			};
			template <>
			struct index<10> {
				template <typename T0, typename T1, typename T2, typename T3, typename T4,
				          typename T5, typename T6, typename T7, typename T8, typename T9,
				          typename T10, typename... Ts>
				using f = T10;
			};
			template <>
			struct index<11> {
				template <typename T0, typename T1, typename T2, typename T3, typename T4,
				          typename T5, typename T6, typename T7, typename T8, typename T9,
				          typename T10, typename T11, typename... Ts>
				using f = T11;
			};
			template <>
			struct index<12> {
				template <typename T0, typename T1, typename T2, typename T3, typename T4,
				          typename T5, typename T6, typename T7, typename T8, typename T9,
				          typename T10, typename T11, typename T12, typename... Ts>
				using f = T12;
			};
			template <>
			struct index<13> {
				template <typename T0, typename T1, typename T2, typename T3, typename T4,
				          typename T5, typename T6, typename T7, typename T8, typename T9,
				          typename T10, typename T11, typename T12, typename T13, typename... Ts>
				using f = T13;
			};
			template <>
			struct index<14> {
				template <typename T0, typename T1, typename T2, typename T3, typename T4,
				          typename T5, typename T6, typename T7, typename T8, typename T9,
				          typename T10, typename T11, typename T12, typename T13, typename T14,
				          typename... Ts>
				using f = T14;
			};
			template <>
			struct index<15> {
				template <typename T0, typename T1, typename T2, typename T3, typename T4,
				          typename T5, typename T6, typename T7, typename T8, typename T9,
				          typename T10, typename T11, typename T12, typename T13, typename T14,
				          typename T15, typename... Ts>
				using f = T15;
			};

			template <typename... Ts>
			struct indexed {
				template <template <typename...> class F>
				using f = F<Ts...>;
			};
			template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5,
			          typename T6, typename T7, typename T8, typename T9, typename T10,
			          typename T11, typename T12, typename T13, typename T14, typename T15,
			          typename Tail>
			struct indexed<rlist<
			        T0,
			        rlist<T1,
			              rlist<T2,
			                    rlist<T3,
			                          rlist<T4,
			                                rlist<T5,
			                                      rlist<T6,
			                                            rlist<T7,
			                                                  rlist<T8,
			                                                        rlist<T9,
			                                                              rlist<T10,
			                                                                    rlist<T11,
			                                                                          rlist<T12,
			                                                                                rlist<T13,
			                                                                                      rlist<T14,
			                                                                                            rlist<T15,
			                                                                                                  Tail>>>>>>>>>>>>>>>>> {
				template <template <typename...> class F>
				using f = F<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15>;
			};

			template <unsigned>
			struct indexed_builder;
			template <>
			struct indexed_builder<0> {
				template <typename...>
				using f = detail::rlist<
				        void,
				        detail::rlist<
				                void,
				                detail::rlist<
				                        void,
				                        detail::rlist<
				                                void,
				                                detail::rlist<
				                                        void,
				                                        detail::rlist<
				                                                void,
				                                                detail::rlist<
				                                                        void,
				                                                        detail::rlist<
				                                                                void,
				                                                                detail::rlist_tail_of8>>>>>>>>;
			};
			template <>
			struct indexed_builder<1> {
				template <typename T0 = void, typename T1 = void, typename T2 = void,
				          typename T3 = void, typename T4 = void, typename T5 = void,
				          typename T6 = void, typename T7 = void, typename T8 = void,
				          typename T9 = void, typename T10 = void, typename T11 = void,
				          typename T12 = void, typename T13 = void, typename T14 = void,
				          typename T15 = void, typename...>
				using f                = detail::rlist<
				        indexed<indexed<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13,
				                        T14, T15>>,
				        detail::rlist<
				                void,
				                detail::rlist<
				                        void,
				                        detail::rlist<
				                                void,
				                                detail::rlist<
				                                        void,
				                                        detail::rlist<
				                                                void,
				                                                detail::rlist<
				                                                        void,
				                                                        detail::rlist<
				                                                                void,
				                                                                detail::rlist_tail_of8>>>>>>>>;
			};
			template <>
			struct indexed_builder<3> {
				template <typename T0 = void, typename T1 = void, typename T2 = void,
				          typename T3 = void, typename T4 = void, typename T5 = void,
				          typename T6 = void, typename T7 = void, typename T8 = void,
				          typename T9 = void, typename T10 = void, typename T11 = void,
				          typename T12 = void, typename T13 = void, typename T14 = void,
				          typename T15 = void, typename T16 = void, typename T17 = void,
				          typename T18 = void, typename T19 = void, typename T20 = void,
				          typename T21 = void, typename T22 = void, typename T23 = void,
				          typename T24 = void, typename T25 = void, typename T26 = void,
				          typename T27 = void, typename T28 = void, typename T29 = void,
				          typename T30 = void, typename T31 = void, typename T32 = void,
				          typename T33 = void, typename T34 = void, typename T35 = void,
				          typename T36 = void, typename T37 = void, typename T38 = void,
				          typename T39 = void, typename T40 = void, typename T41 = void,
				          typename T42 = void, typename T43 = void, typename T44 = void,
				          typename T45 = void, typename T46 = void, typename T47 = void,
				          typename T48 = void, typename T49 = void, typename T50 = void,
				          typename T51 = void, typename T52 = void, typename T53 = void,
				          typename T54 = void, typename T55 = void, typename T56 = void,
				          typename T57 = void, typename T58 = void, typename T59 = void,
				          typename T60 = void, typename T61 = void, typename T62 = void,
				          typename T63 = void, typename T64 = void, typename T65 = void,
				          typename T66 = void, typename T67 = void, typename T68 = void,
				          typename T69 = void, typename T70 = void, typename T71 = void,
				          typename T72 = void, typename T73 = void, typename T74 = void,
				          typename T75 = void, typename T76 = void, typename T77 = void,
				          typename T78 = void, typename T79 = void, typename T80 = void,
				          typename T81 = void, typename T82 = void, typename T83 = void,
				          typename T84 = void, typename T85 = void, typename T86 = void,
				          typename T87 = void, typename T88 = void, typename T89 = void,
				          typename T90 = void, typename T91 = void, typename T92 = void,
				          typename T93 = void, typename T94 = void, typename T95 = void,
				          typename T96 = void, typename T97 = void, typename T98 = void,
				          typename T99 = void, typename T100 = void, typename T101 = void,
				          typename T102 = void, typename T103 = void, typename T104 = void,
				          typename T105 = void, typename T106 = void, typename T107 = void,
				          typename T108 = void, typename T109 = void, typename T110 = void,
				          typename T111 = void, typename T112 = void, typename T113 = void,
				          typename T114 = void, typename T115 = void, typename T116 = void,
				          typename T117 = void, typename T118 = void, typename T119 = void,
				          typename T120 = void, typename T121 = void, typename T122 = void,
				          typename T123 = void, typename T124 = void, typename T125 = void,
				          typename T126 = void, typename T127 = void, typename T128 = void,
				          typename T129 = void, typename T130 = void, typename T131 = void,
				          typename T132 = void, typename T133 = void, typename T134 = void,
				          typename T135 = void, typename T136 = void, typename T137 = void,
				          typename T138 = void, typename T139 = void, typename T140 = void,
				          typename T141 = void, typename T142 = void, typename T143 = void,
				          typename T144 = void, typename T145 = void, typename T146 = void,
				          typename T147 = void, typename T148 = void, typename T149 = void,
				          typename T150 = void, typename T151 = void, typename T152 = void,
				          typename T153 = void, typename T154 = void, typename T155 = void,
				          typename T156 = void, typename T157 = void, typename T158 = void,
				          typename T159 = void, typename T160 = void, typename T161 = void,
				          typename T162 = void, typename T163 = void, typename T164 = void,
				          typename T165 = void, typename T166 = void, typename T167 = void,
				          typename T168 = void, typename T169 = void, typename T170 = void,
				          typename T171 = void, typename T172 = void, typename T173 = void,
				          typename T174 = void, typename T175 = void, typename T176 = void,
				          typename T177 = void, typename T178 = void, typename T179 = void,
				          typename T180 = void, typename T181 = void, typename T182 = void,
				          typename T183 = void, typename T184 = void, typename T185 = void,
				          typename T186 = void, typename T187 = void, typename T188 = void,
				          typename T189 = void, typename T190 = void, typename T191 = void,
				          typename T192 = void, typename T193 = void, typename T194 = void,
				          typename T195 = void, typename T196 = void, typename T197 = void,
				          typename T198 = void, typename T199 = void, typename T200 = void,
				          typename T201 = void, typename T202 = void, typename T203 = void,
				          typename T204 = void, typename T205 = void, typename T206 = void,
				          typename T207 = void, typename T208 = void, typename T209 = void,
				          typename T210 = void, typename T211 = void, typename T212 = void,
				          typename T213 = void, typename T214 = void, typename T215 = void,
				          typename T216 = void, typename T217 = void, typename T218 = void,
				          typename T219 = void, typename T220 = void, typename T221 = void,
				          typename T222 = void, typename T223 = void, typename T224 = void,
				          typename T225 = void, typename T226 = void, typename T227 = void,
				          typename T228 = void, typename T229 = void, typename T230 = void,
				          typename T231 = void, typename T232 = void, typename T233 = void,
				          typename T234 = void, typename T235 = void, typename T236 = void,
				          typename T237 = void, typename T238 = void, typename T239 = void,
				          typename T240 = void, typename T241 = void, typename T242 = void,
				          typename T243 = void, typename T244 = void, typename T245 = void,
				          typename T246 = void, typename T247 = void, typename T248 = void,
				          typename T249 = void, typename T250 = void, typename T251 = void,
				          typename T252 = void, typename T253 = void, typename T254 = void,
				          typename T255 = void, typename... Ts>

				using f = rlist<
				        indexed<indexed<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13,
				                        T14, T15>,
				                indexed<T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27,
				                        T28, T29, T30, T31>,
				                indexed<T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42, T43,
				                        T44, T45, T46, T47>,
				                indexed<T48, T49, T50, T51, T52, T53, T54, T55, T56, T57, T58, T59,
				                        T60, T61, T62, T63>,

				                indexed<T64, T65, T66, T67, T68, T69, T70, T71, T72, T73, T74, T75,
				                        T76, T77, T78, T79>,
				                indexed<T80, T81, T82, T83, T84, T85, T86, T87, T88, T89, T90, T91,
				                        T92, T93, T94, T95>,
				                indexed<T96, T97, T98, T99, T100, T101, T102, T103, T104, T105,
				                        T106, T107, T108, T109, T110, T111>,
				                indexed<T112, T113, T114, T115, T116, T117, T118, T119, T120, T121,
				                        T122, T123, T124, T125, T126, T127>,

				                indexed<T128, T129, T130, T131, T132, T133, T134, T135, T136, T137,
				                        T138, T139, T140, T141, T142, T143>,
				                indexed<T144, T145, T146, T147, T148, T149, T150, T151, T152, T153,
				                        T154, T155, T156, T157, T158, T159>,
				                indexed<T160, T161, T162, T163, T164, T165, T166, T167, T168, T169,
				                        T170, T171, T172, T173, T174, T175>,
				                indexed<T176, T177, T178, T179, T180, T181, T182, T183, T184, T185,
				                        T186, T187, T188, T189, T190, T191>,

				                indexed<T192, T193, T194, T195, T196, T197, T198, T199, T200, T201,
				                        T202, T203, T204, T205, T206, T207>,
				                indexed<T208, T209, T210, T211, T212, T213, T214, T215, T216, T217,
				                        T218, T219, T220, T221, T222, T223>,
				                indexed<T224, T225, T226, T227, T228, T229, T230, T231, T232, T233,
				                        T234, T235, T236, T237, T238, T239>,
				                indexed<T240, T241, T242, T243, T244, T245, T246, T247, T248, T249,
				                        T250, T251, T252, T253, T254, T255>>,
				        typename indexed_builder<(sizeof...(Ts) > 16 ? 3 : 1)>::template f<Ts...>>;
			};

			template <typename T, unsigned I>
			using lookup3 = typename T::template f<detail::index<(I >> 8)>::template f>::
			        template f<detail::index<((I >> 4) & 0xF)>::template f>::template f<
			                detail::index<(I & 0xF)>::template f>;
		} // namespace detail
		template <typename C = identity>
		struct build_indexed {
			template <typename... Ts>
			using f = typename C::template f<detail::indexed<typename detail::indexed_builder<(
			        sizeof...(Ts) > 16 ? 3 : 1)>::template f<Ts...>>>;
		};

		template <>
		struct build_indexed<identity> {
			template <typename... Ts>
			using f = detail::indexed<typename detail::indexed_builder<(
			        sizeof...(Ts) > 16 ? 3 : 1)>::template f<Ts...>>;
		};

		namespace eager {
			template <typename L, unsigned N>
			using lookup = mpl::detail::lookup3<call<unpack<build_indexed<>>, L>, N>;
		}
	} // namespace mpl
} // namespace kvasir

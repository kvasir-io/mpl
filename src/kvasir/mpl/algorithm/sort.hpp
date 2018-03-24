//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "fold_left.hpp"
#include "stable_sort.hpp"
#include "../functions/comparison/less_than.hpp"
#include "../sequence/join.hpp"
#include "../sequence/push_front.hpp"
#include "../types/bool.hpp"
#include "../types/nothing.hpp"

namespace kvasir {
	namespace mpl {
		namespace detail {
			template <class L, class Seq1, class Seq2, template <typename...> class Comp>
			struct merge_impl;

			template <class Seq1, class Seq2, template <typename...> class Comp>
			using merge = typename merge_impl<list<>, Seq1, Seq2, Comp>::type;

			template <bool, class L, class Seq1, class Seq2, template <typename...> class Comp>
			struct merge_insert;

			template <class... R, class T0, class T1, class... Ts, class U, class... Us,
			          template <typename...> class Comp>
			struct merge_insert<true, list<R...>, list<T0, T1, Ts...>, list<U, Us...>, Comp>
			        : merge_insert<Comp<T1, U>::value, list<R..., T0>, list<T1, Ts...>,
			                       list<U, Us...>, Comp> {};

			template <class... R, class T, class U, class... Us, template <typename...> class Comp>
			struct merge_insert<true, list<R...>, list<T>, list<U, Us...>, Comp> {
				using out   = list<R..., T>;
				using left  = list<>;
				using right = list<U, Us...>;
			};

			template <class... R, class T, class... Ts, class U0, class U1, class... Us,
			          template <typename...> class Comp>
			struct merge_insert<false, list<R...>, list<T, Ts...>, list<U0, U1, Us...>, Comp>
			        : merge_insert<Comp<T, U1>::value, list<R..., U0>, list<T, Ts...>,
			                       list<U1, Us...>, Comp> {};

			template <class... R, class T, class... Ts, class U, template <typename...> class Comp>
			struct merge_insert<false, list<R...>, list<T, Ts...>, list<U>, Comp> {
				using out   = list<R..., U>;
				using left  = list<T, Ts...>;
				using right = list<>;
			};

			template <class... R, class T0, class T1, class T2, class T3, class T4, class T5,
			          class T6, class T7, class T8, class T9, class... Ts, class U0, class U1,
			          class U2, class U3, class U4, class U5, class U6, class U7, class U8,
			          class U9, class... Us, template <typename...> class Comp>
			struct merge_impl<list<R...>, list<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, Ts...>,
			                  list<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9, Us...>, Comp> {
				using sub = merge_insert<Comp<T0, U0>::value, list<>,
				                         list<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9>,
				                         list<U0, U1, U2, U3, U4, U5, U6, U7, U8, U9>, Comp>;
				using type = typename merge_impl<
				        typename join<listify>::template f<list<R...>, typename sub::out>,
				        typename join<listify>::template f<typename sub::left, list<Ts...>>,
				        typename join<listify>::template f<typename sub::right, list<Us...>>,
				        Comp>::type;
			};

			template <class... R, class T, class... Ts, class U, class... Us,
			          template <typename...> class Comp>
			struct merge_impl<list<R...>, list<T, Ts...>, list<U, Us...>, Comp>
			        : std::conditional<
			                  Comp<T, U>::value,
			                  merge_impl<list<R..., T>, list<Ts...>, list<U, Us...>, Comp>,
			                  merge_impl<list<R..., U>, list<T, Ts...>, list<Us...>, Comp>>::type {
			};

			template <class... R, class... Ts, template <typename...> class Comp>
			struct merge_impl<list<R...>, list<Ts...>, list<>, Comp> {
				using type = list<R..., Ts...>;
			};

			template <class... R, class... Us, template <typename...> class Comp>
			struct merge_impl<list<R...>, list<>, list<Us...>, Comp> {
				using type = list<R..., Us...>;
			};

			template <class... R, template <typename...> class Comp>
			struct merge_impl<list<R...>, list<>, list<>, Comp> {
				using type = list<R...>;
			};

			template <class Ls, class Seq, template <typename...> class Comp>
			struct sort_impl;

			template <class L, template <typename...> class Comp>
			struct mini_sort;

			template <class T0, class T1, class T2, class T3, class T4, class T5, class T6,
			          class T7, class T8, class... Ts, template <typename...> class Comp>
			struct mini_sort<list<T0, T1, T2, T3, T4, T5, T6, T7, T8, Ts...>, Comp>
			        : merge_impl<list<>, typename mini_sort<list<T0, T1, T2, T3, T4, T5, T6, T7>,
			                                                Comp>::type,
			                     typename mini_sort<list<T8, Ts...>, Comp>::type, Comp> {};

			template <class T0, class T1, class T2, class T3, class T4, class... Ts,
			          template <typename...> class Comp>
			struct mini_sort<list<T0, T1, T2, T3, T4, Ts...>, Comp>
			        : merge_impl<list<>, typename mini_sort<list<T0, T1, T2, T3>, Comp>::type,
			                     typename mini_sort<list<T4, Ts...>, Comp>::type, Comp> {};

			template <class T0, class T1, class T2, class T3, template <typename...> class Comp>
			struct mini_sort<list<T0, T1, T2, T3>, Comp>
			        : merge_impl<list<>, typename mini_sort<list<T0, T1>, Comp>::type,
			                     typename mini_sort<list<T2, T3>, Comp>::type, Comp> {};

			template <class T0, class T1, class T2, template <typename...> class Comp>
			struct mini_sort<list<T0, T1, T2>, Comp>
			        : merge_impl<list<>, typename mini_sort<list<T0, T1>, Comp>::type, list<T2>,
			                     Comp> {};

			template <class T0, class T1, template <typename...> class Comp>
			struct mini_sort<list<T0, T1>, Comp> {
				using base = Comp<T0, T1>;
				using type =
				        typename std::conditional<base::value, list<T0, T1>, list<T1, T0>>::type;
			};

			template <class T0, template <typename...> class Comp>
			struct mini_sort<list<T0>, Comp> {
				using type = list<T0>;
			};

			template <class T0, class T1, class T2, class T3, class T4, class T5, class T6,
			          class T7, class T8, class T9, class T10, class T11, class T12, class T13,
			          class T14, class T15, class T16, class T17, class... Ts,
			          template <typename...> class Comp>
			struct sort_impl<list<>, list<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
			                              T13, T14, T15, T16, T17, Ts...>,
			                 Comp>
			        : sort_impl<
			                  list<typename mini_sort<list<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9,
			                                               T10, T11, T12, T13, T14, T15, T16, T17>,
			                                          Comp>::type>,
			                  list<Ts...>, Comp> {};

			template <class L0, class T0, class T1, class T2, class T3, class T4, class T5,
			          class T6, class T7, class T8, class T9, class T10, class T11, class T12,
			          class T13, class T14, class T15, class T16, class T17, class... Ts,
			          template <typename...> class Comp>
			struct sort_impl<list<L0>, list<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
			                                T13, T14, T15, T16, T17, Ts...>,
			                 Comp>
			        : sort_impl<list<L0, typename mini_sort<
			                                     list<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10,
			                                          T11, T12, T13, T14, T15, T16, T17>,
			                                     Comp>::type>,
			                    list<Ts...>, Comp> {};

			template <class L0, class L1, class T0, class T1, class T2, class T3, class T4,
			          class T5, class T6, class T7, class T8, class T9, class T10, class T11,
			          class T12, class T13, class T14, class T15, class T16, class T17, class... Ts,
			          template <typename...> class Comp>
			struct sort_impl<list<L0, L1>, list<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11,
			                                    T12, T13, T14, T15, T16, T17, Ts...>,
			                 Comp>
			        : sort_impl<list<L0, L1, typename mini_sort<
			                                         list<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9,
			                                              T10, T11, T12, T13, T14, T15, T16, T17>,
			                                         Comp>::type>,
			                    list<Ts...>, Comp> {};

			template <class L0, class L1, class L2, class T0, class T1, class T2, class T3,
			          class T4, class T5, class T6, class T7, class T8, class T9, class T10,
			          class T11, class T12, class T13, class T14, class T15, class T16, class T17,
			          class... Ts, template <typename...> class Comp>
			struct sort_impl<list<L0, L1, L2>, list<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10,
			                                        T11, T12, T13, T14, T15, T16, T17, Ts...>,
			                 Comp>
			        : sort_impl<list<merge<L0, L1, Comp>,
			                         merge<typename mini_sort<
			                                       list<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10,
			                                            T11, T12, T13, T14, T15, T16, T17>,
			                                       Comp>::type,
			                               L2, Comp>>,
			                    list<Ts...>, Comp> {};

			template <class T, class... Ts, template <typename...> class Comp>
			struct sort_impl<list<>, list<T, Ts...>, Comp> {
				using type = typename mini_sort<list<T, Ts...>, Comp>::type;
			};

			template <class L, class T, class... Ts, template <typename...> class Comp>
			struct sort_impl<list<L>, list<T, Ts...>, Comp> {
				using type = merge<typename mini_sort<list<T, Ts...>, Comp>::type, L, Comp>;
			};

			template <class L0, class L1, class T, class... Ts, template <typename...> class Comp>
			struct sort_impl<list<L0, L1>, list<T, Ts...>, Comp> {
				using type =
				        merge<L0, merge<typename mini_sort<list<T, Ts...>, Comp>::type, L1, Comp>,
				              Comp>;
			};

			template <class L0, class L1, class L2, class T, class... Ts,
			          template <typename...> class Comp>
			struct sort_impl<list<L0, L1, L2>, list<T, Ts...>, Comp> {
				using type = merge<merge<L0, L1, Comp>,
				                   merge<typename mini_sort<list<T, Ts...>, Comp>::type, L2, Comp>,
				                   Comp>;
			};

			template <class L, template <typename...> class Comp>
			struct sort_impl<list<L>, list<>, Comp> {
				using type = L;
			};

			template <class L0, class L1, template <typename...> class Comp>
			struct sort_impl<list<L0, L1>, list<>, Comp> {
				using type = merge<L0, L1, Comp>;
			};

			template <class L0, class L1, class L2, template <typename...> class Comp>
			struct sort_impl<list<L0, L1, L2>, list<>, Comp> {
				using type = merge<merge<L0, L1, Comp>, L2, Comp>;
			};

			template <template <typename...> class Comp>
			struct sort_impl<list<>, list<>, Comp> {
				using type = list<>;
			};

			// 255 or more elements case
			template <class T0, class T1, class T2, class T3, class T4, class T5, class T6,
			          class T7, class T8, class T9, class T10, class T11, class T12, class T13,
			          class T14, class T15, class T16, class T17, class T18, class T19, class T20,
			          class T21, class T22, class T23, class T24, class T25, class T26, class T27,
			          class T28, class T29, class T30, class T31, class T32, class T33, class T34,
			          class T35, class T36, class T37, class T38, class T39, class T40, class T41,
			          class T42, class T43, class T44, class T45, class T46, class T47, class T48,
			          class T49, class T50, class T51, class T52, class T53, class T54, class T55,
			          class T56, class T57, class T58, class T59, class T60, class T61, class T62,
			          class T63, class T64, class T65, class T66, class T67, class T68, class T69,
			          class T70, class T71, class T72, class T73, class T74, class T75, class T76,
			          class T77, class T78, class T79, class T80, class T81, class T82, class T83,
			          class T84, class T85, class T86, class T87, class T88, class T89, class T90,
			          class T91, class T92, class T93, class T94, class T95, class T96, class T97,
			          class T98, class T99, class T100, class T101, class T102, class T103,
			          class T104, class T105, class T106, class T107, class T108, class T109,
			          class T110, class T111, class T112, class T113, class T114, class T115,
			          class T116, class T117, class T118, class T119, class T120, class T121,
			          class T122, class T123, class T124, class T125, class T126, class T127,
			          class T128, class T129, class T130, class T131, class T132, class T133,
			          class T134, class T135, class T136, class T137, class T138, class T139,
			          class T140, class T141, class T142, class T143, class T144, class T145,
			          class T146, class T147, class T148, class T149, class T150, class T151,
			          class T152, class T153, class T154, class T155, class T156, class T157,
			          class T158, class T159, class T160, class T161, class T162, class T163,
			          class T164, class T165, class T166, class T167, class T168, class T169,
			          class T170, class T171, class T172, class T173, class T174, class T175,
			          class T176, class T177, class T178, class T179, class T180, class T181,
			          class T182, class T183, class T184, class T185, class T186, class T187,
			          class T188, class T189, class T190, class T191, class T192, class T193,
			          class T194, class T195, class T196, class T197, class T198, class T199,
			          class T200, class T201, class T202, class T203, class T204, class T205,
			          class T206, class T207, class T208, class T209, class T210, class T211,
			          class T212, class T213, class T214, class T215, class T216, class T217,
			          class T218, class T219, class T220, class T221, class T222, class T223,
			          class T224, class T225, class T226, class T227, class T228, class T229,
			          class T230, class T231, class T232, class T233, class T234, class T235,
			          class T236, class T237, class T238, class T239, class T240, class T241,
			          class T242, class T243, class T244, class T245, class T246, class T247,
			          class T248, class T249, class T250, class T251, class T252, class T253,
			          class T254, class T255, typename... Ts, template <typename...> class Comp>
			struct sort_impl<
			        list<>,
			        list<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16,
			             T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29, T30, T31,
			             T32, T33, T34, T35, T36, T37, T38, T39, T40, T41, T42, T43, T44, T45, T46,
			             T47, T48, T49, T50, T51, T52, T53, T54, T55, T56, T57, T58, T59, T60, T61,
			             T62, T63, T64, T65, T66, T67, T68, T69, T70, T71, T72, T73, T74, T75, T76,
			             T77, T78, T79, T80, T81, T82, T83, T84, T85, T86, T87, T88, T89, T90, T91,
			             T92, T93, T94, T95, T96, T97, T98, T99, T100, T101, T102, T103, T104, T105,
			             T106, T107, T108, T109, T110, T111, T112, T113, T114, T115, T116, T117,
			             T118, T119, T120, T121, T122, T123, T124, T125, T126, T127, T128, T129,
			             T130, T131, T132, T133, T134, T135, T136, T137, T138, T139, T140, T141,
			             T142, T143, T144, T145, T146, T147, T148, T149, T150, T151, T152, T153,
			             T154, T155, T156, T157, T158, T159, T160, T161, T162, T163, T164, T165,
			             T166, T167, T168, T169, T170, T171, T172, T173, T174, T175, T176, T177,
			             T178, T179, T180, T181, T182, T183, T184, T185, T186, T187, T188, T189,
			             T190, T191, T192, T193, T194, T195, T196, T197, T198, T199, T200, T201,
			             T202, T203, T204, T205, T206, T207, T208, T209, T210, T211, T212, T213,
			             T214, T215, T216, T217, T218, T219, T220, T221, T222, T223, T224, T225,
			             T226, T227, T228, T229, T230, T231, T232, T233, T234, T235, T236, T237,
			             T238, T239, T240, T241, T242, T243, T244, T245, T246, T247, T248, T249,
			             T250, T251, T252, T253, T254, T255, Ts...>,
			        Comp> {
				using type = merge<
				        typename sort_impl<
				                list<>,
				                list<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13,
				                     T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25,
				                     T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37,
				                     T38, T39, T40, T41, T42, T43, T44, T45, T46, T47, T48, T49,
				                     T50, T51, T52, T53, T54, T55, T56, T57, T58, T59, T60, T61,
				                     T62, T63, T64, T65, T66, T67, T68, T69, T70, T71, T72, T73,
				                     T74, T75, T76, T77, T78, T79, T80, T81, T82, T83, T84, T85,
				                     T86, T87, T88, T89, T90, T91, T92, T93, T94, T95, T96, T97,
				                     T98, T99, T100, T101, T102, T103, T104, T105, T106, T107, T108,
				                     T109, T110, T111, T112, T113, T114, T115, T116, T117, T118,
				                     T119, T120, T121, T122, T123, T124, T125, T126, T127, T128,
				                     T129, T130, T131, T132, T133, T134, T135, T136, T137, T138,
				                     T139, T140, T141, T142, T143, T144, T145, T146, T147, T148,
				                     T149, T150, T151, T152, T153, T154, T155, T156, T157, T158,
				                     T159, T160, T161, T162, T163, T164, T165, T166, T167, T168,
				                     T169, T170, T171, T172, T173, T174, T175, T176, T177, T178,
				                     T179, T180, T181, T182, T183, T184, T185, T186, T187, T188,
				                     T189, T190, T191, T192, T193, T194, T195, T196, T197, T198,
				                     T199, T200, T201, T202, T203, T204, T205, T206, T207, T208,
				                     T209, T210, T211, T212, T213, T214, T215, T216, T217, T218,
				                     T219, T220, T221, T222, T223, T224, T225, T226, T227, T228,
				                     T229, T230, T231, T232, T233, T234, T235, T236, T237, T238,
				                     T239, T240, T241, T242, T243, T244, T245, T246, T247, T248,
				                     T249, T250, T251, T252, T253, T254>,
				                Comp>::type,
				        typename sort_impl<list<>, list<T255, Ts...>, Comp>::type, Comp>;
			};
		} // namespace detail

		namespace detail {
			template <template <typename...> class F, typename T0, typename T1, typename T2,
			          typename T3, typename T4, typename T5, typename T6, typename T7, typename T8,
			          typename T9, typename T10, typename T11, typename T12, typename T13,
			          typename T14, typename T15>
			using sort16 = mpl::detail::merge<
			        mpl::detail::merge<
			                mpl::detail::merge<
			                        typename std::conditional<F<T0, T1>::value, list<T0, T1>,
			                                                  list<T1, T0>>::type,
			                        typename std::conditional<F<T2, T3>::value, list<T2, T3>,
			                                                  list<T3, T2>>::type,
			                        F>,
			                mpl::detail::merge<
			                        typename std::conditional<F<T4, T5>::value, list<T4, T5>,
			                                                  list<T5, T4>>::type,
			                        typename std::conditional<F<T6, T7>::value, list<T6, T7>,
			                                                  list<T7, T6>>::type,
			                        F>,
			                F>,
			        mpl::detail::merge<
			                mpl::detail::merge<
			                        typename std::conditional<F<T8, T9>::value, list<T8, T9>,
			                                                  list<T9, T8>>::type,
			                        typename std::conditional<F<T10, T11>::value, list<T10, T11>,
			                                                  list<T11, T10>>::type,
			                        F>,
			                mpl::detail::merge<
			                        typename std::conditional<F<T2, T13>::value, list<T12, T13>,
			                                                  list<T13, T12>>::type,
			                        typename std::conditional<F<T14, T15>::value, list<T14, T15>,
			                                                  list<T15, T14>>::type,
			                        F>,
			                F>,
			        F>;
			constexpr unsigned select_sort_loop(const unsigned in) {
				return /*in >= 256 ? 256 :*/ in >= 64 ? 64 : in >= 16 ? 16 : in >= 4 ? 4 : in >= 1 ?
				                                                                       1 :
				                                                                       0;
			}
			template <unsigned I, template <typename...> class F>
			struct sort_loop;
			template <template <typename...> class F>
			struct sort_loop<0, F> {
				template <typename... Ts>
				using f = rlist_tail_of8;
			};
			template <template <typename...> class F>
			struct sort_loop<1, F> {
				template <typename T>
				using f = rlist<list<T>, rlist_tail_of8>;
			};
			template <template <typename...> class F>
			struct sort_loop<4, F> {
				template <typename T0, typename T1, typename T2, typename T3, typename... Ts>
				using f = rlist<
				        mpl::detail::merge<typename std::conditional<F<T0, T1>::value, list<T0, T1>,
				                                                     list<T1, T0>>::type,
				                           typename std::conditional<F<T2, T3>::value, list<T2, T3>,
				                                                     list<T3, T2>>::type,
				                           F>,
				        typename sort_loop<select_sort_loop(sizeof...(Ts)), F>::template f<Ts...>>;
			};
			template <template <typename...> class F>
			struct sort_loop<16, F> {
				template <typename T0, typename T1, typename T2, typename T3, typename T4,
				          typename T5, typename T6, typename T7, typename T8, typename T9,
				          typename T10, typename T11, typename T12, typename T13, typename T14,
				          typename T15, typename... Ts>
				using f = rlist<
				        sort16<F, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14,
				               T15>,
				        typename sort_loop<select_sort_loop(sizeof...(Ts)), F>::template f<Ts...>>;
			};
			template <template <typename...> class F>
			struct sort_loop<64, F> {
				template <typename T0, typename T1, typename T2, typename T3, typename T4,
				          typename T5, typename T6, typename T7, typename T8, typename T9,
				          typename T10, typename T11, typename T12, typename T13, typename T14,
				          typename T15, typename T16, typename T17, typename T18, typename T19,
				          typename T20, typename T21, typename T22, typename T23, typename T24,
				          typename T25, typename T26, typename T27, typename T28, typename T29,
				          typename T30, typename T31, typename T32, typename T33, typename T34,
				          typename T35, typename T36, typename T37, typename T38, typename T39,
				          typename T40, typename T41, typename T42, typename T43, typename T44,
				          typename T45, typename T46, typename T47, typename T48, typename T49,
				          typename T50, typename T51, typename T52, typename T53, typename T54,
				          typename T55, typename T56, typename T57, typename T58, typename T59,
				          typename T60, typename T61, typename T62, typename T63, typename... Ts>
				using f = rlist<
				        mpl::detail::merge<
				                mpl::detail::merge<sort16<F, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9,
				                                          T10, T11, T12, T13, T14, T15>,
				                                   sort16<F, T16, T17, T18, T19, T20, T21, T22, T23,
				                                          T24, T25, T26, T27, T28, T29, T30, T31>,
				                                   F>,
				                mpl::detail::merge<sort16<F, T32, T33, T34, T35, T36, T37, T38, T39,
				                                          T40, T41, T42, T43, T44, T45, T46, T47>,
				                                   sort16<F, T48, T49, T50, T51, T52, T53, T54, T55,
				                                          T56, T57, T58, T59, T60, T61, T62, T63>,
				                                   F>,
				                F>,
				        typename sort_loop<select_sort_loop(sizeof...(Ts)), F>::template f<Ts...>>;
			};
			template <template <typename...> class F, typename T>
			struct recursive_merge;
			template <template <typename...> class F, typename T, typename U>
			struct recursive_merge<F, rlist<T, U>> {
				using type = mpl::detail::merge<T, typename recursive_merge<F, U>::type, F>;
			};
			template <template <typename...> class F, typename T, typename U>
			struct recursive_merge<F, rlist<T, rlist<list<>, U>>> {
				using type = T;
			};
		} // namespace detail
		//			template <template <typename...> class F>
		//			struct sort {
		//				template <typename... Ts>
		//				using f = typename
		// detail::sort_loop<detail::select_sort_loop(sizeof...(Ts)),
		//				                                     F>::template f<Ts...>;
		//			};

		/// \brief sorts a pack of elements
		template <typename F = less_than<>, typename C = listify>
		using sort = stable_sort<F, C>;

		namespace eager {
			template <typename List, template <typename...> class Comp = less_than>
			using sort = stable_sort<List, Comp>;
		}
	} // namespace mpl
} // namespace kvasir

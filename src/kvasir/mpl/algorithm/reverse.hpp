//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../functional/call.hpp"
#include "../sequence/join.hpp"

namespace kvasir {
	namespace mpl {
		namespace detail {
			static constexpr int select_reverse(const int in) {
				return /*in >= 256 ? 256 :*/ in >= 64 ? 64 : in >= 16 ?
				                                        16 :
				                                        in >= 4 ? 4 : in >= 2 ? 2 : in == 1 ? 1 : 0;
			}
			template <int>
			struct reverse_impl;
			template <>
			struct reverse_impl<0> {
				template <typename Tail, typename...>
				using f = Tail;
			};
			template <>
			struct reverse_impl<1> {
				template <typename Tail, typename T0>
				using f = rlist<list<T0>, Tail>;
			};
			template <>
			struct reverse_impl<2> {
				template <typename Tail, typename T0, typename T1, typename... Ts>
				using f = typename reverse_impl<select_reverse(
				        sizeof...(Ts))>::template f<rlist<list<T1, T0>, Tail>, Ts...>;
			};
			template <>
			struct reverse_impl<4> {
				template <typename Tail, typename T0, typename T1, typename T2, typename T3,
				          typename... Ts>
				using f = typename reverse_impl<select_reverse(
				        sizeof...(Ts))>::template f<rlist<list<T3, T2, T1, T0>, Tail>, Ts...>;
			};
			template <>
			struct reverse_impl<16> {
				template <typename Tail, typename T0, typename T1, typename T2, typename T3,
				          typename T4, typename T5, typename T6, typename T7, typename T8,
				          typename T9, typename T10, typename T11, typename T12, typename T13,
				          typename T14, typename T15, typename... Ts>
				using f = typename reverse_impl<select_reverse(
				        sizeof...(Ts))>::template f<rlist<list<T15, T14, T13, T12, T11, T10, T9, T8,
				                                               T7, T6, T5, T4, T3, T2, T1, T0>,
				                                          Tail>,
				                                    Ts...>;
			};
			template <>
			struct reverse_impl<64> {
				template <typename Tail, typename T0, typename T1, typename T2, typename T3,
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
				using f = typename reverse_impl<select_reverse(sizeof...(Ts))>::template f<
				        rlist<list<T63, T62, T61, T60, T59, T58, T57, T56, T55, T54, T53, T52, T51,
				                   T50, T49, T48, T47, T46, T45, T44, T43, T42, T41, T40, T39, T38,
				                   T37, T36, T35, T34, T33, T32, T31, T30, T29, T28, T27, T26, T25,
				                   T24, T23, T22, T21, T20, T19, T18, T17, T16, T15, T14, T13, T12,
				                   T11, T10, T9, T8, T7, T6, T5, T4, T3, T2, T1, T0>,
				              Tail>,
				        Ts...>;
			};
		} // namespace detail
		/// \brief reverses the order of elements in a pack
		template <typename C = listify>
		struct reverse {
			template <typename... Ts>
			using f = typename detail::recursive_join<C>::template f<
			        typename detail::reverse_impl<detail::select_reverse(
			                sizeof...(Ts))>::template f<detail::rlist_tail_of8, Ts...>>;
		};

		namespace eager {
			template <typename List>
			using reverse = call<unpack<mpl::reverse<typename sequencify<List>::type>>, List>;
		}
	} // namespace mpl
} // namespace kvasir

//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../types/list.hpp"
#include "pop_front.hpp"

namespace kvasir {
	namespace mpl {
		namespace detail
		{
			//monad at, fast tracks up to 16 are good for small offsets, for larger ones first drop and then call at
			template<int I>
			struct at_m;
			template<>
			struct at_m<0> {
				template<typename T, typename...>
				using f = T;
			};
			template<>
			struct at_m<1> {
				template<typename T0, typename T1, typename...>
				using f = T1;
			};
			template<>
			struct at_m<2> {
				template<typename T0, typename T1, typename T2, typename...>
				using f = T2;
			};
			template<>
			struct at_m<3> {
				template<typename T0, typename T1, typename T2, typename T3, typename...>
				using f = T3;
			};
			template<>
			struct at_m<4> {
				template<typename T0, typename T1, typename T2, typename T3, typename T4, typename...>
				using f = T4;
			};
			template<>
			struct at_m<5> {
				template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename...>
				using f = T5;
			};
			template<>
			struct at_m<6> {
				template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename...>
				using f = T6;
			};
			template<>
			struct at_m<7> {
				template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename...>
				using f = T7;
			};
			template<>
			struct at_m<8> {
				template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename...>
				using f = T8;
			};
			template<>
			struct at_m<9> {
				template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename...>
				using f = T9;
			};
			template<>
			struct at_m<10> {
				template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename...>
				using f = T10;
			};
			template<>
			struct at_m<11> {
				template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename...>
				using f = T11;
			};
			template<>
			struct at_m<12> {
				template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename...>
				using f = T12;
			};
			template<>
			struct at_m<13> {
				template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename...>
				using f = T13;
			};
			template<>
			struct at_m<14> {
				template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename...>
				using f = T14;
			};
			template<>
			struct at_m<15> {
				template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename...>
				using f = T15;
			};
		}


		namespace impl {
			template <unsigned N, typename List>
			struct at_impl {
				using f = typename at_impl<N - 1, typename pop_front_impl<List>::rest>::f;
			};

			template <typename List>
			struct at_impl<0, List> {
				using f = typename pop_front_impl<List>::front;
			};
		}

		/// get the n-th element of the list
		template <unsigned N, typename List>
		using at = typename impl::at_impl<N, List>::f;
	}
}
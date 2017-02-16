//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../types/list.hpp"

namespace kvasir {
	namespace mpl {
		namespace impl {
			template <unsigned N, typename List>
			struct at_impl;

			/// kvasir::mpl::list implementation
			template <unsigned N, typename T, typename... Ts>
			struct at_impl<N, mpl::list<T, Ts...>> {
				using f = typename at_impl<N - 1, mpl::list<Ts...>>::f;
			};

			template <typename T, typename... Ts>
			struct at_impl<0, mpl::list<T, Ts...>> {
				using f = T;
			};

			/// past the end of the list; result is undefined
			template <unsigned N>
			struct at_impl<N, mpl::list<>>;
		}

		/// get the n-th element of the list
		template <unsigned N, typename List>
		using at = typename at_impl<N, List>::f;
	}
}
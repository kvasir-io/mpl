//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../types/list.hpp"

namespace kvasir {
	namespace mpl {
		namespace impl {
			template <typename Elem, typename List>
			struct push_front_impl;

			/// kvasir::mpl::list implementation
			template <typename Elem, typename... Ts>
			struct push_front_impl<Elem, mpl::list<Ts...>> {
				using f = mpl::list<Elem, Ts...>;
			};
		}

		/// push an element to the back of a list
		template <typename Elem, typename List>
		using push_front = typename push_front_impl<Elem, List>::f;
	}
}
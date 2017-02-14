//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../types/list.hpp"

namespace kvasir {
	namespace mpl {
		namespace impl {
			template<typename List>
			struct pop_front_impl;

			template<typename T, typename ...Ts>
			struct pop_front_impl<mpl::list<T, Ts...>> {
				struct f {
					using front = T;
					using rest  = mpl::list<Ts...>;
				};
			};
		}

		/// pop a single element from the front of a list
		/// returns a pair of the first element and the rest of the list, with ::first and ::rest
		/// respectively
		template <typename List>
		using pop_front = typename impl::pop_front_impl<List>::f;
	}
}

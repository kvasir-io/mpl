//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../types/list.hpp"
#include "../types/nothing.hpp"

namespace kvasir {
	namespace mpl {
		namespace impl {
			template <typename List>
			struct pop_front_impl {
				using front = List;
				using rest  = nothing;
			};

			template <typename T, typename... Ts>
			struct pop_front_impl<mpl::list<T, Ts...>> {
				using front = T;
				using rest  = mpl::list<Ts...>;
			};

			template <>
			struct pop_front_impl<mpl::list<>> {
				using front = nothing;
				using rest  = nothing;
			};
		}

		/// pop a single element from the front of a list
		/// returns a pair of the first element and the rest of the list, with ::front and ::rest
		/// respectively
		template <typename List>
		using pop_front = impl::pop_front_impl<List>;
	}
}

//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

namespace kvasir {
	namespace mpl {
		namespace impl {
			template <typename List>
			struct create_impl;

			/// default implementation for flat lists
			template <template <typename...> class ListT, typename... Ts>
			struct create_impl<ListT<Ts...>> {
				using f = ListT<>;
			};
		}

		/// takes any list and creates an empty list of the same type
		template <typename List>
		using create = typename impl::create_impl<List>::f;
	}
}

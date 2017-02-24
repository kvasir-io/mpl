//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../types/list.hpp"

namespace kvasir {
	namespace mpl {
		namespace impl {
			template <typename... Lists>
			struct join_impl {};

			// do not create a zero list case, as the result will be undefined

			/// case for only a single list
			template <typename List>
			struct join_impl<List> {
				using f = List;
			};

			/// join implementation for kvasir::mpl::list
			template <typename... Ts1, typename... Ts2, typename... Lists>
			struct join_impl<mpl::list<Ts1...>, mpl::list<Ts2...>, Lists...> {
				using f = typename join_impl<mpl::list<Ts1..., Ts2...>, Lists...>::f;
			};
		}

		/// join two or more lists together
		/// when there is only one list input the result is that list
		/// in the case of joining two or more distinct list types, the first list type will always
		/// be the resulting type
		template <typename List, typename... Lists>
		using join = typename impl::join_impl<List, Lists...>::f;
	}
}
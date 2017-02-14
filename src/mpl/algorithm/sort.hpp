//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../types/list.hpp"

namespace kvasir {
	namespace mpl {
		namespace impl {
			template <typename List>
			struct sort_impl;

			/// kvasir::mpl::list implementation
			template <typename... Ts>
			struct sort_impl<mpl::list<Ts...>> {}; // TODO
		}

		template <typename List>
		using sort = typename impl::sort_impl<List>::f;
	}
}
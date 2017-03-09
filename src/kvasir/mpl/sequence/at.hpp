//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../types/list.hpp"
#include "pop_front.hpp"

namespace kvasir {
	namespace mpl {

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
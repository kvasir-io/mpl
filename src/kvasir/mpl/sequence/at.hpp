//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../functional/call.hpp"
#include "../sequence/drop.hpp"
#include "../sequence/front.hpp"
#include "../types/int.hpp"

namespace kvasir {
	namespace mpl {
		namespace c {
			template <typename N>
			using at = drop<N, front>;
		}

		/// get the n-th element of the list
		template <typename List, unsigned N>
		using at = c::call<c::at<mpl::uint_<N>>, List>;
	}
}

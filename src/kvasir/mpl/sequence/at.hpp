//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../algorithm/rotate.hpp"
#include "../types/int.hpp"
#include "../sequence/front.hpp"
#include "../sequence/size.hpp"
#include "../functional/call.hpp"

namespace kvasir {
	namespace mpl {

		/// get the n-th element of the list
		template <typename List, unsigned N>
		using at = c::call<c::rotate<mpl::int_<N>, c::front>, List>;
	}
}
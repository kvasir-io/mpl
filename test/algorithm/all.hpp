//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <kvasir/mpl/algorithm/all.hpp>
#include <kvasir/mpl/types/list.hpp>
#include <kvasir/mpl/utility/same_as.hpp>

namespace all_test {
	using namespace kvasir;
	using namespace mpl;

	true_ t1  = call<all<same_as<int>>, int, int, int, int>{};
	false_ t2 = call<all<same_as<int>>, int, int, bool, int>{};

	true_ t3  = call<all<same_as<int>>, int>{};
	false_ t4 = call<all<same_as<int>>, bool>{};
}

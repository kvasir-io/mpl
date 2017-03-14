//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <kvasir/mpl/algorithm/transform.hpp>

namespace {
	using namespace kvasir;
	static_assert(std::is_same<mpl::transform<mpl::list<void, char, short, int>, list>,
		mpl::list<mpl::list<void>, mpl::list<char>, mpl::list<short>, mpl::list<int>>>{},
		"");
}
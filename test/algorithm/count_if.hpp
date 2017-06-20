//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>

#include <kvasir/mpl/algorithm/count_if.hpp>

namespace {
	template <typename T>
	using comp = std::is_same<int, T>;

	using namespace kvasir;
	static_assert(mpl::eager::count_if<mpl::list<void, char, int, float>, comp>::value == 1, "");
	static_assert(mpl::eager::count_if<mpl::list<void, char, bool, float>, comp>::value == 0, "");
}

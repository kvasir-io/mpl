//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>

#include <kvasir/mpl/algorithm/none.hpp>
#include <kvasir/mpl/functional/bind.hpp>
#include <kvasir/mpl/types/list.hpp>

namespace {
	template <typename T>
	using comp = std::is_same<int, T>;

	using namespace kvasir;
	static_assert(!mpl::eager::none<mpl::list<void, char, int, float>, comp>::value, "");
	static_assert(mpl::eager::none<mpl::list<void, char, bool, float>, comp>::value, "");
}

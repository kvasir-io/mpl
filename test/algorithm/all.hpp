//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>

#include <kvasir/mpl/algorithm/all.hpp>
#include <kvasir/mpl/types/list.hpp>
#include <kvasir/mpl/functional/bind.hpp>

namespace {
	template<typename T>
	using comp = std::is_same<int, T>;

	using namespace kvasir;
	static_assert(mpl::all<comp, mpl::list<int, int, int, int>>{}, "");
	static_assert(!mpl::all<comp, mpl::list<int, int, bool, int>>{}, "");
}

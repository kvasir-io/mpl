//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <kvasir/mpl/algorithm/split_if.hpp>
#include <kvasir/mpl/types/bool.hpp>
#include <kvasir/mpl/types/int.hpp>
#include <kvasir/mpl/types/list.hpp>

namespace split_if_test {
	using namespace kvasir::mpl;
	template <typename T>
	using is_99 = bool_<T::value == 99>;
	using a = eager::split_if<list<int_<1>, int_<2>, int_<99>, int_<3>, int_<4>, int_<99>, int_<5>>,
	                          is_99>;
	using b = list<list<int_<1>, int_<2>>, list<int_<3>, int_<4>>, list<int_<5>>>;
	static_assert(std::is_same<a, b>{}, "");
}
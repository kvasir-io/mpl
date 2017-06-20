//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>

#include <kvasir/mpl/algorithm/partition.hpp>
#include <kvasir/mpl/types/bool.hpp>
#include <kvasir/mpl/types/int.hpp>

namespace partition_test {
	using namespace kvasir::mpl;
	template <typename T>
	using less_than_5 = bool_<(T::value < 5)>;
	using l           = list<int_<1>, int_<2>, int_<7>, int_<8>>;
	using p           = eager::partition<l, less_than_5>;
	static_assert(std::is_same<p, list<list<int_<7>, int_<8>>, list<int_<1>, int_<2>>>>::value,
	              "partition error");
}

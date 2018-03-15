//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>
//#include <tuple>

#include <kvasir/mpl/algorithm/filter.hpp>
#include <kvasir/mpl/types/bool.hpp>
#include <kvasir/mpl/types/int.hpp>

namespace {
	using namespace kvasir::mpl;
	template <typename T>
	using less_than_5 = bool_<(T::value < 5)>;
	struct filter_test {
		filter_test() {
			call<filter<cfe<less_than_5>>, int_<1>, int_<2>, int_<7>, int_<8>>{} =
			        list<int_<1>, int_<2>>{};
			call<filter<cfe<less_than_5>>, int_<9>, int_<2>, int_<7>, int_<8>>{} = list<int_<2>>{};
			call<filter<cfe<less_than_5>>>{} = list<>{};
			call<filter<cfe<less_than_5>, cfe<list>>, int_<1>, int_<2>, int_<7>, int_<8>>{} =
			        list<int_<1>, int_<2>>{};
		}
	};
}

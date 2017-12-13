//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>
#include <kvasir/mpl/mpl.hpp>

namespace {
	struct combinations_test {
		combinations_test() {
			using namespace kvasir::mpl;

			call<combinations<uint_<2>, listify, front<>, listify>, uint_<0>, uint_<1>,
			     uint_<2>>{} = list<list<uint_<0>, uint_<1>>, list<uint_<0>, uint_<2>>,
			                        list<uint_<1>, uint_<0>>, list<uint_<1>, uint_<2>>,
			                        list<uint_<2>, uint_<0>>, list<uint_<2>, uint_<1>>>{};
		}
	};
}

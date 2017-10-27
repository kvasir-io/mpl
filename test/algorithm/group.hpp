//          Copyright Jonathan Poelen 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <kvasir/mpl/algorithm/group.hpp>
#include <kvasir/mpl/algorithm/make_sequence.hpp>

namespace {
	struct group_test {
		group_test() {
			using namespace kvasir::mpl;

			eager::group<list<>>{}    = list<>{};
			eager::group<list<int>>{} = list<list<int>>{};
			eager::group<list<int, double>>{} = list<list<int>, list<double>>{};
			eager::group<list<int, double, float>>{} = list<list<int>, list<double>, list<float>>{};
			eager::group<list<int, int, double, double, double, int, int, int, float>>{} =
			        list<list<int, int>, list<double, double, double>, list<int, int, int>,
			             list<float>>{};
			using seq           = eager::make_int_sequence<uint_<5>>;
			eager::group<seq>{} = eager::transform<seq, list>{};
		}
	};
}

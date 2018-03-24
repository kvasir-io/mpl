//          Copyright Jonathan Poelen 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <kvasir/mpl/algorithm/group.hpp>
#include <kvasir/mpl/sequence/make_sequence.hpp>

namespace {
	struct group_test {
		group_test() {
			using namespace kvasir::mpl;
			call<group<>>{} = list<>{};
			call<group<>, int>{} = list<list<int>>{};
			call<group<>, int, double>{} = list<list<int>, list<double>>{};
			call<group<>, int, double, float>{} = list<list<int>, list<double>, list<float>>{};
			call<group<>, int, int, double, double, double, int, int, int, float>{} =
			        list<list<int, int>, list<double, double, double>, list<int, int, int>,
			             list<float>>{};
			using seq = call<make_int_sequence<>, uint_<5>>;
			call<unpack<group<>>, seq>{} = call<unpack<transform<cfe<list>>>, seq>{};
		}
	};
}

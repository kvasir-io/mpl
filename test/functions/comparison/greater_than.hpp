//          Copyright Odin Holmes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <kvasir/mpl/functional/call.hpp>
#include <kvasir/mpl/functions/comparison/greater_than.hpp>
#include <kvasir/mpl/types/int.hpp>

namespace {
	struct greater_than_test {
		greater_than_test() {
			using namespace kvasir::mpl;

			eager::greater_than<int_<0>, int_<1>>{} = bool_<false>{};
			call<greater_than<>, int_<0>, int_<1>>{} = bool_<false>{};
		}
	};
}

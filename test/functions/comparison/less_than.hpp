//          Copyright Odin Holmes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <kvasir/mpl/functional/call.hpp>
#include <kvasir/mpl/functions/comparison/less_than.hpp>
#include <kvasir/mpl/types/int.hpp>

namespace {
	struct less_than_test {
		less_than_test() {
			using namespace kvasir::mpl;

			eager::less_than<int_<0>, int_<1>>{} = bool_<true>{};
			call<less_than<>, int_<0>, int_<1>>{} = bool_<true>{};
		}
	};
}

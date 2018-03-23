//          Copyright Odin Holmes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <kvasir/mpl/functional/call.hpp>
#include <kvasir/mpl/functions/comparison/not_equal.hpp>
#include <kvasir/mpl/types/int.hpp>

namespace {
	struct not_equal_test {
		not_equal_test() {
			using namespace kvasir::mpl;

			eager::not_equal<uint_<0>, uint_<1>>{} = bool_<true>{};
			call<not_equal<>, uint_<0>, uint_<1>>{} = bool_<true>{};
		}
	};
}

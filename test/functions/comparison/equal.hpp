//          Copyright Odin Holmes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <kvasir/mpl/functional/call.hpp>
#include <kvasir/mpl/functions/comparison/equal.hpp>
#include <kvasir/mpl/types/bool.hpp>
#include <kvasir/mpl/types/int.hpp>

namespace {
	struct equal_test {
		equal_test() {
			using namespace kvasir::mpl;

			eager::equal<uint_<0>, uint_<1>>{} = bool_<false>{};
			call<equal<>, uint_<0>, uint_<1>>{} = bool_<false>{};
		}
	};
}

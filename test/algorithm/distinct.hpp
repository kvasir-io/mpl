//          Copyright Emil Fresk 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>

#include <kvasir/mpl/algorithm/distinct.hpp>

namespace {
	struct distinct_test {
		distinct_test() {
			using namespace kvasir::mpl;
			static_assert(call<distinct<>, void, char, int, float>::value == true, "");
			static_assert(call<distinct<>, void, char, int, char>::value == false, "");
			static_assert(call<distinct<>>::value, "");
		}
	};
}

//          Copyright Odin Holmes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <kvasir/mpl/functional/call.hpp>
#include <kvasir/mpl/functions/bitwise/bitwise_complement.hpp>
#include <kvasir/mpl/types/int.hpp>
#include <kvasir/mpl/types/integral_constant.hpp>

namespace {
	struct bitwise_complement_test {
		bitwise_complement_test() {
			using namespace kvasir::mpl;

			eager::bitwise_complement<uint_<0>>{} =
			        integral_constant<unsigned long long, (~0ull)>{};
			call<bitwise_complement<>, uint_<0>>{} =
			        integral_constant<unsigned long long, (~0ull)>{};
		}
	};
}

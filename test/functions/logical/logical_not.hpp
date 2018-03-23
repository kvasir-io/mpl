//          Copyright Odin Holmes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>
#include <kvasir/mpl/functional/call.hpp>
#include <kvasir/mpl/functions/logical/logical_not.hpp>
#include <kvasir/mpl/types/bool.hpp>
#include <kvasir/mpl/types/int.hpp>

namespace {
	struct logical_not_test {
		logical_not_test() {
			using namespace kvasir::mpl;

			eager::logical_not<uint_<0>>{} = bool_<true>{};
			call<logical_not<>, uint_<0>>{} = bool_<true>{};
		}
	};
}

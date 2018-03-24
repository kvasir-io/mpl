//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <kvasir/mpl/functional/call.hpp>
#include <kvasir/mpl/types/bool.hpp>
#include <kvasir/mpl/utility/conditional.hpp>

namespace {
	struct conditional_test {
		conditional_test() {
			using namespace kvasir::mpl;

			call<conditional<true>, bool_<true>, bool_<false>>{}  = bool_<true>{};
			call<conditional<false>, bool_<true>, bool_<false>>{} = bool_<false>{};
		}
	};
}

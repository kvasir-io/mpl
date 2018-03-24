//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <kvasir/mpl/algorithm/all.hpp>
#include <kvasir/mpl/types/list.hpp>
#include <kvasir/mpl/utility/same_as.hpp>

namespace {
	struct all_test {
		template <typename T>
		using comp = std::is_same<int, T>;

		all_test() {
			using namespace kvasir;
			using namespace mpl;

			call<all<cfe<comp>>, int, int, int, int>{}  = true_{};
			call<all<cfe<comp>>, int, int, bool, int>{} = false_{};

			call<all<cfe<comp>>, int, int, int, int>{}  = true_{};
			call<all<cfe<comp>>, int, int, bool, int>{} = false_{};
		}
	};
}

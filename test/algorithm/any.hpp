//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>

#include <kvasir/mpl/algorithm/any.hpp>
#include <kvasir/mpl/functional/bind.hpp>
#include <kvasir/mpl/types/list.hpp>

namespace {
	struct any_test {
		template <typename T>
		using comp = std::is_same<int, T>;

		any_test() {
			using namespace kvasir::mpl;
			call<any<cfe<comp>>, void, char, int, float>{}  = true_{};
			call<any<cfe<comp>>, void, char, bool, float>{} = false_{};
			call<any<cfe<comp>>>{} = false_{};
		}
	};
}

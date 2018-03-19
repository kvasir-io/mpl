//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>

#include <kvasir/mpl/algorithm/count_if.hpp>
namespace {
	struct count_if_test {
		template <typename t>
		using comp = std::is_same<int, t>;

		count_if_test() {
			using namespace kvasir::mpl;
			call<count_if<cfe<comp>>, void, char, bool, float>{} = uint_<0>{};
			call<count_if<cfe<comp>>, void, char, int, float>{}  = uint_<1>{};
			call<count_if<cfe<comp>>, int, char, int, float>{}   = uint_<2>{};
			call<count_if<cfe<comp>>>{} = uint_<0>{};
		}
	};
}

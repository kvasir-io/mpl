//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <kvasir/mpl/functional/call.hpp>
#include <kvasir/mpl/sequence/size.hpp>

namespace {
	struct size_test {
		size_test() {
			using namespace kvasir::mpl;

			call<size<>>{} = uint_<0>{};
			call<size<>, int>{} = uint_<1>{};
			call<size<>, int, int>{} = uint_<2>{};
			call<size<>, int, int, int>{} = uint_<3>{};
			call<size<>, int, int, int, int>{} = uint_<4>{};
			call<size<>, int, int, int, int, int>{} = uint_<5>{};
			call<size<>, int, int, int, int, int, int>{} = uint_<6>{};
		}
	};
}

//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <kvasir/mpl/sequence/at.hpp>

namespace {
	using namespace kvasir::mpl;

	char c1  = call<at<int_<1>>, void, char, short>{};
	char c2  = call<at<int_<7>>, int, int, int, int, int, int, int, char, void, short>{};
	char c3  = call<at<int_<8>>, int, int, int, int, int, int, int, void, char, short>{};
	short c4 = call<at<int_<9>>, int, int, int, int, int, int, int, void, char, short>{};
	char c5  = call<at<int_<17>>, int, int, int, int, int, int, int, int, int, int, int, int, int,
	               int, int, int, void, char, short>{};
}

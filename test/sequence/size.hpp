//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <kvasir/mpl/sequence/size.hpp>

namespace size_test {
	using namespace kvasir::mpl;
	static_assert(size<>::template f<>::value == 0, "size test failed");
	static_assert(size<>::template f<int>::value == 1, "size test failed");
	static_assert(size<>::template f<int, int>::value == 2, "size test failed");
	static_assert(size<>::template f<int, int, int>::value == 3, "size test failed");
	static_assert(size<>::template f<int, int, int, int>::value == 4, "size test failed");
	static_assert(size<>::template f<int, int, int, int, int>::value == 5, "size test failed");
	static_assert(size<>::template f<int, int, int, int, int, int>::value == 6, "size test failed");
}

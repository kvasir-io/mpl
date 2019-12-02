//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <kvasir/mpl/sequence/size.hpp>

#include <metacheck/metacheck.hpp>

namespace size { /*
	 using namespace kvasir::mpl;
	 static_assert(size<>::template f<>::value == 0, "size test failed");
	 static_assert(size<>::template f<int>::value == 1, "size test failed");
	 static_assert(size<>::template f<int, int>::value == 2, "size test failed");
	 static_assert(size<>::template f<int, int, int>::value == 3, "size test failed");
	 static_assert(size<>::template f<int, int, int, int>::value == 4, "size test failed");
	 static_assert(size<>::template f<int, int, int, int, int>::value == 5, "size test failed");
	 static_assert(size<>::template f<int, int, int, int, int, int>::value == 6, "size test
	 failed");*/

	namespace mpl = kvasir::mpl;

	template <typename L1, typename L2>
	using distributive =
	        mc::prop::distributive<mpl::eager::size, mpl::eager::join, mpl::eager::plus, L1, L2>;

	constexpr auto distributive_test =
	        mc::test<distributive, 20, mc::gen::list_of<mc::gen::anything>,
	                 mc::gen::list_of<mc::gen::anything>>;
} // namespace size

constexpr auto size_section_t = mc::section("size", size::distributive_test);
extern mc::result *size_section;

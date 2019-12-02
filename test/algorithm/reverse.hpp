//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <metacheck/metacheck.hpp>

namespace reverse {
	namespace mpl = kvasir::mpl;

	template <typename L>
	using double_reverse =
	        mc::mpl::equal<mpl::call<mpl::unpack<mpl::reverse<mpl::reverse<>>>, L>, L>;

	constexpr auto double_reverse_test =
	        mc::test<double_reverse, 20, mc::gen::list_of<mc::gen::anything>>;
} // namespace reverse

constexpr auto reverse_section_t = mc::section("reverse", reverse::double_reverse_test);
extern mc::result *reverse_section;

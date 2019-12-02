//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <metacheck/metacheck.hpp>

namespace zip_with {
	namespace mpl = kvasir::mpl;

	template <typename L>
	using same = mpl::call<mpl::fork<mpl::identity, mpl::identity,
	                                 mpl::zip_with<mpl::is_same<>, mpl::all<mpl::identity>>>,
	                       L>;

	constexpr auto same_test = mc::test<same, 20, mc::gen::list_of<mc::gen::anything>>;
} // namespace zip_with

constexpr auto zip_with_section_t = mc::section("zip_with", zip_with::same_test);
extern mc::result *zip_with_section;

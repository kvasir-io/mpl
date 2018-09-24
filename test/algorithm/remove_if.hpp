//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>

#include <metacheck.hpp>

namespace remove_if_test {
	namespace mpl = kvasir::mpl;

	template <typename L1, typename L2>
	using distributive =
	        mc::prop::distributive<mpl::unpack<mpl::remove_if<mpl::identity>>::template f,
	                               mpl::eager::join, mpl::eager::join, L1, L2>;

	constexpr auto distributive_test = mc::test<distributive, 20, mc::gen::list_of<mc::gen::bool_>,
	                                            mc::gen::list_of<mc::gen::bool_>>;
} // namespace remove_if_test

constexpr auto remove_if_section_t = mc::section("remove_if", remove_if_test::distributive_test);
extern mc::detail::section_base *remove_if_section;

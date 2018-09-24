//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>

#include <metacheck.hpp>

namespace remove_adjacent {
	namespace mpl = kvasir::mpl;

	template <typename L>
	using same = mc::mpl::equal<
	        mpl::call<mpl::unpack<mpl::remove_adjacent<
	                          mpl::is_same<>, mpl::remove_adjacent<mpl::is_same<mpl::invert<>>>>>,
	                  L>,
	        mpl::list<>>;

	constexpr auto same_test = mc::test<same, 20, mc::gen::list_of<mc::gen::bool_>>;
} // namespace remove_adjacent

constexpr auto remove_adjacent_section_t =
        mc::section("remove_adjacent", remove_adjacent::same_test);
extern mc::detail::section_base *remove_adjacent_section;

//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>

#include <kvasir/mpl/mpl.hpp>

#include <metacheck/metacheck.hpp>

namespace flatten {
	namespace mpl = kvasir::mpl;

	template <unsigned depth = 5>
	struct recursive_list {
		template <typename seed>
		using generate =
		        typename mc::gen::list_of<mc::gen::any<mc::gen::bool_, recursive_list<depth - 1>>,
		                                  mc::gen::uint_<depth>>::template generate<seed>;
	};

	template <typename L1, typename L2>
	using distributive =
	        mc::prop::distributive<mpl::eager::flatten, mpl::eager::join, mpl::eager::join, L1, L2>;

	constexpr auto distributive_test =
	        mc::test<distributive, 20, recursive_list<>, recursive_list<>>;
} // namespace flatten

constexpr auto flatten_section_t = mc::section("flatten", flatten::distributive_test);
extern mc::result *flatten_section;

//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>

#include <kvasir/mpl/algorithm/count_if.hpp>

#include <metacheck.hpp>

namespace count_if {
	namespace mpl = kvasir::mpl;

	template <typename L>
	using same_size = mc::mpl::equal<mpl::eager::size<L>, mpl::eager::count_if<L>>;

	constexpr auto same_size_test =
	        mc::test<same_size, 20, mc::gen::list_of<mc::gen::just<mpl::bool_<true>>>>;

	template <typename L1, typename L2>
	using distributive = mc::prop::distributive<mpl::unpack<mpl::count_if<>>::template f,
	                                            mpl::eager::join, mpl::eager::plus, L1, L2>;

	constexpr auto distributive_test = mc::test<distributive, 20, mc::gen::list_of<mc::gen::bool_>,
	                                            mc::gen::list_of<mc::gen::bool_>>;

	template <typename L1, typename L2>
	using commutative = mc::prop::commutative<mpl::join<mpl::count_if<>>::template f, L1, L2>;

	constexpr auto commutative_test = mc::test<commutative, 20, mc::gen::list_of<mc::gen::bool_>,
	                                           mc::gen::list_of<mc::gen::bool_>>;
} // namespace count_if

constexpr auto count_if_section_t =
        mc::section("count_if", count_if::same_size_test, count_if::distributive_test,
                    count_if::commutative_test);
extern mc::detail::section_base *count_if_section;

//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>

#include <kvasir/mpl/algorithm/filter.hpp>
#include <kvasir/mpl/types/bool.hpp>
#include <kvasir/mpl/types/int.hpp>

#include <metacheck/metacheck.hpp>

namespace filter {
	namespace mpl = kvasir::mpl;

	template <typename L>
	using same_size = mc::mpl::equal<mpl::eager::size<L>, mpl::eager::size<mpl::eager::filter<L>>>;

	constexpr auto same_size_test =
	        mc::test<same_size, 20, mc::gen::list_of<mc::gen::just<mpl::bool_<true>>>>;

	template <typename L1, typename L2>
	using distributive = mc::prop::distributive<mpl::unpack<mpl::filter<>>::template f,
	                                            mpl::eager::join, mpl::eager::join, L1, L2>;

	constexpr auto distributive_test = mc::test<distributive, 20, mc::gen::list_of<mc::gen::bool_>,
	                                            mc::gen::list_of<mc::gen::bool_>>;

	template <typename L1, typename L2>
	using commutative =
	        mc::prop::commutative<mpl::join<mpl::filter<mpl::identity, mpl::size<>>>::template f,
	                              L1, L2>;

	constexpr auto commutative_test = mc::test<commutative, 20, mc::gen::list_of<mc::gen::bool_>,
	                                           mc::gen::list_of<mc::gen::bool_>>;

	template <typename L>
	using associative =
	        mc::prop::associative<mpl::unpack<mpl::filter<>>::template f,
	                              mpl::unpack<mpl::filter<mpl::logical_not<>>>::template f, L>;

	constexpr auto associative_test = mc::test<associative, 20, mc::gen::list_of<mc::gen::bool_>>;
} // namespace filter

constexpr auto filter_section_t =
        mc::section("filter", filter::same_size_test, filter::distributive_test,
                    filter::commutative_test, filter::associative_test);
extern mc::result *filter_section;

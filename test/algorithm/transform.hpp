//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>

#include <metacheck.hpp>

namespace transform {
	namespace mpl = kvasir::mpl;

	template <typename L1, typename L2>
	using distributive =
	        mc::prop::distributive<mpl::unpack<mpl::transform<mpl::listify>>::template f,
	                               mpl::eager::join, mpl::eager::join, L1, L2>;

	constexpr auto distributive_test =
	        mc::test<distributive, 20, mc::gen::list_of<mc::gen::anything>,
	                 mc::gen::list_of<mc::gen::anything>>;

	template <typename L>
	using size =
	        mc::mpl::equal<mpl::eager::size<L>,
	                       mpl::call<mpl::unpack<mpl::transform<mpl::listify, mpl::size<>>>, L>>;

	constexpr auto size_test = mc::test<size, 20, mc::gen::list_of<mc::gen::anything>>;

	template <typename L>
	using not_same =
	        mpl::call<mpl::unpack<mpl::fork<
	                          mpl::listify, mpl::transform<mpl::listify>,
	                          mpl::zip_with<mpl::is_same<mpl::invert<>>, mpl::all<mpl::identity>>>>,
	                  L>;

	constexpr auto not_same_test = mc::test<not_same, 20, mc::gen::list_of<mc::gen::anything>>;
} // namespace transform

constexpr auto transform_section_t = mc::section("transform", transform::distributive_test,
                                                 transform::size_test, transform::not_same_test);
extern mc::detail::section_base *transform_section;

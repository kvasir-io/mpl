//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>

#include <kvasir/mpl/algorithm/fold_right.hpp>
#include <kvasir/mpl/functions/arithmetic/plus.hpp>
#include <kvasir/mpl/types/int.hpp>
#include <kvasir/mpl/types/list.hpp>

#include <metacheck.hpp>

namespace fold_right {
	namespace mpl = kvasir::mpl;

	template <typename L1, typename L2>
	using distributive = mc::prop::distributive<
	        mpl::unpack<mpl::push_front<mpl::uint_<0>, mpl::fold_right<mpl::plus<>>>>::template f,
	        mpl::eager::join, mpl::eager::plus, L1, L2>;

	constexpr auto distributive_test =
	        mc::test<distributive, 20, mc::gen::list_of<mc::gen::uint_<>>,
	                 mc::gen::list_of<mc::gen::uint_<>>>;

	template <typename L>
	using ordering = mc::mpl::equal<
	        L, mpl::call<mpl::unpack<mpl::push_front<
	                             mpl::list<>,
	                             mpl::fold_right<mpl::fork<mpl::at1<>, mpl::at0<>,
	                                                       mpl::cfe<mpl::eager::push_front>>>>>,
	                     L>>;

	constexpr auto ordering_test = mc::test<ordering, 20, mc::gen::list_of<mc::gen::anything>>;
}

constexpr auto fold_right_section =
        mc::section("fold_right", fold_right::distributive_test, fold_right::ordering_test);

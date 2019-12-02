//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>

#include <kvasir/mpl/algorithm/any.hpp>
#include <kvasir/mpl/functional/bind.hpp>
#include <kvasir/mpl/types/list.hpp>

#include <metacheck/metacheck.hpp>

namespace any {
	namespace mpl = kvasir::mpl;

	template <typename Front, typename Elem, typename Back>
	struct bools_impl;
	template <typename... Front, typename Elem, typename... Back>
	struct bools_impl<mpl::list<Front...>, Elem, mpl::list<Back...>> {
		using type = mc::mpl::equal<Elem, mpl::call<mpl::any<>, Front..., Elem, Back...>>;
	};

	template <typename Front, typename Elem, typename Back>
	using bools = typename bools_impl<Front, Elem, Back>::type;

	constexpr auto bools_test =
	        mc::test<bools, 20, mc::gen::list_of<mc::gen::just<mpl::bool_<false>>>, mc::gen::bool_,
	                 mc::gen::list_of<mc::gen::just<mpl::bool_<false>>>>;

	template <typename List>
	using prepend = mpl::call<mpl::unpack<mpl::push_front<mpl::bool_<true>, mpl::any<>>>, List>;

	constexpr auto prepend_test = mc::test<prepend, 20, mc::gen::list_of<mc::gen::bool_>>;
} // namespace any

constexpr auto any_section_t = mc::section("any", any::bools_test, any::prepend_test);
extern mc::result *any_section;

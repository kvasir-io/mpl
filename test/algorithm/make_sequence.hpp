//          Copyright Odin Holmes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>

#include <kvasir/mpl/algorithm/make_sequence.hpp>
#include <kvasir/mpl/types/bool.hpp>
#include <kvasir/mpl/types/int.hpp>
#include <kvasir/mpl/types/list.hpp>

namespace {
	namespace mpl = kvasir::mpl;

	using a = mpl::eager::make_int_sequence<mpl::int_<5>>;
	using b = mpl::list<mpl::uint_<0>, mpl::uint_<1>, mpl::uint_<2>, mpl::uint_<3>, mpl::uint_<4>>;
	static_assert(std::is_same<a, b>{}, "");

	static_assert(std::is_same<mpl::eager::make_int_sequence<mpl::int_<0>>, mpl::list<>>{}, "");
}

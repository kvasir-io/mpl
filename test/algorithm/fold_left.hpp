//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>

#include <kvasir/mpl/algorithm/fold_left.hpp>
#include <kvasir/mpl/types/int.hpp>

namespace {
	using namespace kvasir;
	using mpl::uint_;

	template <typename T1, typename T2>
	using add = uint_<(T1::value + T2::value)>;

	static_assert(
	        std::is_same<mpl::eager::fold_left<mpl::list<uint_<1>, uint_<2>, uint_<3>, uint_<4>>,
	                                           uint_<0>, add>,
	                     uint_<10>>::value,
	        "");
}

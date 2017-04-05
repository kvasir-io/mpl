//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>
#include <kvasir/mpl/sequence/lookup.hpp>

namespace {
	namespace mpl = kvasir::mpl;
	template <int>
	struct x;
	using xs0  = mpl::list<x<1>>;
	using xs1  = mpl::list<x<1>, x<2>>;
	using xs15 = mpl::list<x<1>, x<2>, x<3>, x<4>, x<5>, x<6>, x<7>, x<8>, x<9>, x<10>, x<11>,
	                       x<12>, x<13>, x<14>, x<15>, x<16>>;
	using xs16 = mpl::list<x<1>, x<2>, x<3>, x<4>, x<5>, x<6>, x<7>, x<8>, x<9>, x<10>, x<11>,
	                       x<12>, x<13>, x<14>, x<15>, x<16>, x<17>>;
	using xs17 = mpl::list<x<1>, x<2>, x<3>, x<4>, x<5>, x<6>, x<7>, x<8>, x<9>, x<10>, x<11>,
	                       x<12>, x<13>, x<14>, x<15>, x<16>, x<17>, x<18>>;

	static_assert(std::is_same<mpl::eager::lookup<xs0, 0>, x<1>>::value, "");
	static_assert(std::is_same<mpl::eager::lookup<xs1, 1>, x<2>>::value, "");
	static_assert(std::is_same<mpl::eager::lookup<xs15, 15>, x<16>>::value, "");
	static_assert(std::is_same<mpl::eager::lookup<xs16, 16>, x<17>>::value, "");
	static_assert(std::is_same<mpl::eager::lookup<xs17, 17>, x<18>>::value, "");
}

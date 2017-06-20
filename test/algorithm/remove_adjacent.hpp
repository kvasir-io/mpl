//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>

#include <kvasir/mpl/algorithm/remove_adjacent.hpp>
#include <kvasir/mpl/types/bool.hpp>
#include <kvasir/mpl/types/list.hpp>

namespace {
	namespace mpl = kvasir::mpl;
	static_assert(std::is_same<mpl::eager::remove_adjacent<mpl::list<void, char, char, short>>,
	                           mpl::list<void, char, short>>{},
	              "");

	template <typename T1, typename T2>
	struct foo_is_same_impl {
		using f = mpl::bool_<false>;
	};

	template <typename T>
	struct foo_is_same_impl<T, T> {
		using f = mpl::bool_<true>;
	};

	template <typename T1, typename T2>
	using foo_is_same = typename foo_is_same_impl<T1, T2>::f;

	// unoptimised version of remove_adjacent
	static_assert(std::is_same<mpl::eager::remove_adjacent<mpl::list<void, char, char, short>,
	                                                       foo_is_same>,
	                           mpl::list<void, char, short>>{},
	              "");
}

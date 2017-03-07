//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <kvasir/mpl/utility/always.hpp>

static_assert(std::is_same<always<int>::template f<void>, int>{}, "");

template <typename T>
struct foo {
	static_assert(always_false<T>{}, "always_false should not have been instantiated");
};

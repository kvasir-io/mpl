//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <kvasir/mpl/algorithm/stable_sort.hpp>

#include <type_traits>

#include <kvasir/mpl/types/int.hpp>
#include <kvasir/mpl/types/list.hpp>

namespace mpl = kvasir::mpl;

template <typename A, typename B>
struct equal {
	constexpr static bool value = false;
};

template <typename A, typename B>
struct less {
	constexpr static bool value = A::value < B::value;
};

using namespace mpl;

using ss_test_list =
        list<int_<3>, int_<0>, int_<7>, int_<2>, int_<1>, int_<3>, int_<4>, int_<6>, int_<5>>;
using ss_expect_list =
        list<int_<0>, int_<1>, int_<2>, int_<3>, int_<3>, int_<4>, int_<5>, int_<6>, int_<7>>;

static_assert(std::is_same<ss_test_list, mpl::stable_sort<ss_test_list, equal>>::value,
              "Stable sort is not stable");
static_assert(std::is_same<ss_expect_list, mpl::stable_sort<ss_test_list, less>>::value,
              "Stable sort is not sort");

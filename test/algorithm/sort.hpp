//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>

#include <kvasir/mpl/algorithm/sort.hpp>
#include <kvasir/mpl/types/bool.hpp>
#include <kvasir/mpl/types/int.hpp>
#include <kvasir/mpl/types/list.hpp>

using namespace kvasir::mpl;

template <typename E1, typename E2>
using compare_func = bool_<(E1::value < E2::value)>;

using test_list =
        list<int_<3>, int_<0>, int_<7>, int_<2>, int_<1>, int_<3>, int_<4>, int_<6>, int_<5>>;
using expect_list =
        list<int_<0>, int_<1>, int_<2>, int_<3>, int_<3>, int_<4>, int_<5>, int_<6>, int_<7>>;

static_assert(std::is_same<eager::sort<test_list>, expect_list>::value, "");

using empty_sort_test = eager::sort<list<>>;

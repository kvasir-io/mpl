//          Copyright Odin Holmes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <kvasir/mpl/functions/comparison/greater_than.hpp>
#include <kvasir/mpl/types/integral_constant.hpp>


static_assert(std::is_same<kvasir::mpl::eager::greater_than<kvasir::mpl::integral_constant<int, 0>, kvasir::mpl::integral_constant<int, 1>>, kvasir::mpl::bool_<0>>::value, "");
static_assert(std::is_same<kvasir::mpl::greater_than<>::template f<kvasir::mpl::integral_constant<int, 0>, kvasir::mpl::integral_constant<int, 1>>, kvasir::mpl::bool_<0>>::value, "");

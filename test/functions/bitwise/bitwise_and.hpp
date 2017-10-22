//          Copyright Odin Holmes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <kvasir/mpl/functions/bitwise/bitwise_and.hpp>
#include <kvasir/mpl/types/integral_constant.hpp>
#include <type_traits>

static_assert(std::is_same<kvasir::mpl::eager::bitwise_and<kvasir::mpl::integral_constant<unsigned, 0>, kvasir::mpl::integral_constant<unsigned, 1>>, kvasir::mpl::integral_constant<unsigned, 0>>::value, "");
static_assert(std::is_same<kvasir::mpl::bitwise_and<>::template f<kvasir::mpl::integral_constant<unsigned, 0>, kvasir::mpl::integral_constant<unsigned, 1>>, kvasir::mpl::integral_constant<unsigned, 0>>::value, "");

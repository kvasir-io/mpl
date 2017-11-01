//          Copyright Odin Holmes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>
#include <kvasir/mpl/functions/bitwise/bitwise_complement.hpp>
#include <kvasir/mpl/types/integral_constant.hpp>

static_assert(
        std::is_same<
                kvasir::mpl::eager::bitwise_complement<kvasir::mpl::integral_constant<unsigned, 0>>,
                kvasir::mpl::integral_constant<unsigned, (~0U)>>::value,
        "");
static_assert(std::is_same<kvasir::mpl::bitwise_complement<>::template f<
                                   kvasir::mpl::integral_constant<unsigned, 0>>,
                           kvasir::mpl::integral_constant<unsigned, (~0U)>>::value,
              "");

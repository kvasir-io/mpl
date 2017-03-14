//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>

#include <kvasir/mpl/algorithm/fold_left.hpp>
#include <kvasir/mpl/types/int.hpp>

using namespace kvasir;
using mpl::uint_;

template <typename T1, typename T2>
using add = uint_<(T1{} + T2{})>;

static_assert(std::is_same<mpl::fold_left<mpl::list<uint_<1>, uint_<2>, uint_<3>, uint_<4>>,
                                          uint_<0>, add>,
                           uint_<10>>{},
              "");

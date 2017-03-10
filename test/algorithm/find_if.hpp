//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>

#include <kvasir/mpl/algorithm/find_if.hpp>
#include <kvasir/mpl/functional/bind.hpp>

using namespace kvasir;
static_assert(std::is_same<mpl::find_if<mpl::bind1<std::is_same, char>,
                                        mpl::list<void, char, short, int>>,
                           mpl::list<char, short, int>>{},
              "");

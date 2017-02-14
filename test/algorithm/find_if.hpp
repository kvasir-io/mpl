//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>
#include "../../src/kvasir/mpl/algorithm/find_if.hpp"
#include "../../src/kvasir/mpl/types/list.hpp"

using namespace kvasir::mpl;
static_assert(std::is_same<find_if<bind<std::is_same, char>::f, list<void, char, short, int>>,
                           list<char, short, int>>,
              "");
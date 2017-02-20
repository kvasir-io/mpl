//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>
#include <kvasir/mpl/algorithm/find_if.hpp>
#include <kvasir/mpl/functional/bind.hpp>

using namespace kvasir::mpl;
static_assert(
        std::is_same<find_if<bind<std::is_same, char>::template f, list<void, char, short, int>>,
                     list<char, short, int>>{},
        "");
//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <kvasir/mpl/algorithm/contains.hpp>
#include <kvasir/mpl/types/list.hpp>
#include <kvasir/mpl/functional/bind.hpp>

using namespace kvasir;
static_assert(mpl::contains<mpl::bind<std::is_same, int>::template f,
                            mpl::list<void, char, int, float>>{},
              "");

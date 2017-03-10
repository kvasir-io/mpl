//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>

#include <kvasir/mpl/algorithm/any.hpp>
#include <kvasir/mpl/types/list.hpp>
#include <kvasir/mpl/types/bool.hpp>
#include <kvasir/mpl/functional/bind.hpp>

template <typename T>
using comp = std::is_same<int, T>;

using namespace kvasir;
static_assert(mpl::any<comp, mpl::list<void, char, int, float>>{}, "");

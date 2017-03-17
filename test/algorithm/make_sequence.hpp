//          Copyright Odin Holmes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>

#include <kvasir/mpl/algorithm/make_sequence.hpp>
#include <kvasir/mpl/types/bool.hpp>
#include <kvasir/mpl/types/int.hpp>
#include <kvasir/mpl/types/list.hpp>

namespace mpl = kvasir::mpl;
template <typename T>
using is_99 = mpl::bool_<T::value == 99>;
using a     = mpl::make_int_sequence<mpl::int_<5>>;
using b     = mpl::list<mpl::int_<1>, mpl::int_<2>, mpl::int_<3>, mpl::int_<4>, mpl::int_<5>>;
static_assert(std::is_same<a, b>{}, "");

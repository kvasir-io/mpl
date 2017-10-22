//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <kvasir/mpl/types/list.hpp>
#include <kvasir/mpl/utility/is_instance.hpp>

using namespace kvasir::mpl;
static_assert(eager::is_instance<list, list<void>>::value, "");
static_assert(!eager::is_instance<list, void>::value, "");
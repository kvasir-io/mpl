//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>

#include <kvasir/mpl/algorithm/find_if.hpp>
#include <kvasir/mpl/functional/bind.hpp>
#include <kvasir/mpl/utility/same_as.hpp>

namespace find_if_test {
	using namespace kvasir::mpl;
	list<char, short, int> t1 = call<find_if<same_as<char>>, void, char, short, int>{};
}

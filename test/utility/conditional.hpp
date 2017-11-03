//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <kvasir/mpl/types/bool.hpp>
#include <kvasir/mpl/utility/conditional.hpp>

namespace conditional_test {
	using namespace kvasir::mpl;
	static_assert(conditional<true>::template f<bool_<true>, bool_<false>>::value,
	              "conditional test failed");
	static_assert(conditional<false>::template f<bool_<true>, bool_<false>>::value == false,
	              "conditional test failed");
} // namespace conditional_test
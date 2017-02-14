//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "integral_constant.hpp"

namespace kvasir {
	namespace mpl {
		template <unsigned long long value>
		using uint_ = integral_constant<unsigned long long, value>;

		template <long long value>
		using int_ = integral_constant<long long, value>;
	}
}

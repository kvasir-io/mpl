//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../types/integral_constant.hpp"

namespace kvasir {
	namespace mpl {

		template<typename T>
		struct always {
			template<typename ...>
			using f = T;
		};

		template<typename T>
		using always_false = bool_constant<false>;

	}
}

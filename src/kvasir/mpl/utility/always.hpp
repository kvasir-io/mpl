//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../types/bool.hpp"

namespace kvasir {
	namespace mpl {

		template <typename T>
		struct always {
			template <typename...>
			using f = T;
		};

		template <typename ...>
		struct always_false {
			constexpr operator bool() const {
				return false;
			}
		};
	}
}

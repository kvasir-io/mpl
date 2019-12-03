//          Copyright Emil Fresk 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../../functional/identity.hpp"
#include "../../types/bool.hpp"

namespace kvasir {
	namespace mpl {
		template <typename C = identity>
		struct equal {
			template <typename A, typename B>
			using f = typename C::template f<bool_<(A::value == B::value)>>;
		};
		namespace eager {
			template <typename A, typename B>
			using equal = bool_<(A::value == B::value)>;
		}
	} // namespace mpl
} // namespace kvasir

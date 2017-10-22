//          Copyright Emil Fresk 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../../functional/identity.hpp"
#include "../../types/integral_constant.hpp"

namespace kvasir {
	namespace mpl {
		template <typename C = identity>
		struct increment {
			template <typename A>
			using f = typename C::template f<
			        integral_constant<decltype(A::value + 1), (A::value + 1)>>;
		};
		namespace eager {
			template <typename A>
			using increment = integral_constant<decltype(A::value + 1), (A::value + 1)>;
		}
	} // namespace mpl
} // namespace kvasir

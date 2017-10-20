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
		struct invert {
			template <typename A>
			using f = typename C::template f<integral_constant<decltype(!A::value), (!A::value)>>;
		};
		namespace eager {
			template <typename A>
			using invert = integral_constant<decltype(!A::value), (!A::value)>;
		}
	} // namespace mpl
} // namespace kvasir

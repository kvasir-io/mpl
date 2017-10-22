//          Copyright Emil Fresk 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../../functional/identity.hpp"
#include "../../types/integral_constant.hpp"
#include "../../utility/conditional.hpp"

namespace kvasir {
	namespace mpl {

		template <typename C = identity>
		struct max {
			template <typename A, typename B>
			using f = typename C::template f<
			        typename conditional<(A::value > B::value)>::template f<A, B>>;
		};
		namespace eager {
			template <typename A, typename B>
			using max = typename conditional<(A::value > B::value)>::template f<A, B>;
		}
	} // namespace mpl
} // namespace kvasir

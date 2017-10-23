//          Copyright Emil Fresk 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../../functional/identity.hpp"
#include "../../types/integral_constant.hpp"

namespace kvasir {
	namespace mpl {
		/// \brief bitwise or of the ::value of two inputs
		template <typename C = identity>
		struct bitwise_or {
			template <typename A, typename B>
			using f = typename C::template f<
			        integral_constant<decltype(A::value | B::value), (A::value | B::value)>>;
		};
		namespace eager {
			template <typename A, typename B>
			using bitwise_or =
			        integral_constant<decltype(A::value | B::value), (A::value | B::value)>;
		}
	} // namespace mpl
} // namespace kvasir

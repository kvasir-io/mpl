//          Copyright Jan Halsema 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "../../functional/identity.hpp"
#include "../../types/integral_constant.hpp"

namespace kvasir {
	namespace mpl {
		template <typename C = identity>
		struct bitwise_shr {
			template <typename A, typename B>
			using f = typename C::template f<
			        integral_constant<decltype(A::value >> B::value), (A::value >> B::value)>>;
		};
		namespace eager {
			template <typename A, typename B>
			using bitwise_shr =
			        integral_constant<decltype(A::value >> B::value), (A::value >> B::value)>;
		}
	} // namespace mpl
} // namespace kvasir

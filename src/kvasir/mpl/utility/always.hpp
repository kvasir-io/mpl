//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../types/bool.hpp"
#include "../functional/identity.hpp"

namespace kvasir {
	namespace mpl {
		template <typename T, typename C = identity>
		struct always {
			template <typename...>
			using f = typename C::template f<T>;
		};
		template <typename T>
		struct always<T,identity> {
			template <typename...>
			using f = T;
		};
		namespace eager {
			template <typename...>
			struct always_false {
				static constexpr bool value = false;
			};
		}
	}
}

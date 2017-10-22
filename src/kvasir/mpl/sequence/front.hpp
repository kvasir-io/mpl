//          Copyright Odin Holmes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../functional/identity.hpp"
#include "../types/list.hpp"

namespace kvasir {
	namespace mpl {
		template <typename C = identity>
		struct front {
			template <typename T, typename... Ts>
			using f = typename C::template f<T>;
		};
		template <>
		struct front<identity> {
			template <typename T, typename... Ts>
			using f = T;
		};
	} // namespace mpl
} // namespace kvasir

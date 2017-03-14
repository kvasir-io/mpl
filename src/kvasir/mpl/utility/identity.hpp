//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../functional/call.hpp"

namespace kvasir {
	namespace mpl {
		namespace c {
			template <typename C>
			struct identity {
				template <typename... Ts>
				using f = typename C::template f<Ts...>;
			};

			template <template <typename...> class F>
			struct identity<lambda<F>> {
				template <typename... Ts>
				using f = F<Ts...>;
			};
		}

		template <typename T>
		using identity = T;
	}
}

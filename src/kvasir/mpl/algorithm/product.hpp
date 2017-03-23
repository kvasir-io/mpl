//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../algorithm/transform.hpp"
#include "../functional/bind.hpp"
#include "../functional/fork.hpp"
#include "../sequence/join.hpp"
#include "../sequence/push_back.hpp"
#include "../sequence/push_front.hpp"

namespace kvasir {
	namespace mpl {
		namespace c {
			/*template <typename F = listify, typename C = listify>
			struct product {
			    template <typename L0, typename L1, typename... Ls>
			    using f = call<call<transform<push_back<F, cfe<push_front, cfe<transform>>>,
			                                  push_front<join<C>, cfe<fork>>>, L1>, L0>;
			};*/

			template <typename F = listify, typename C = listify>
			struct product {
				// push front the element from the first list, continue into F
				template <typename T>
				using transform_push = transform<push_front<T, F>>;

				// call all the functions Ts with some input, joining the output
				template <typename... Ts>
				using fork_join = fork<join<C>, Ts...>;

				template <typename L0, typename L1, typename... Ls>
				using f = call<call<transform<cfe<transform_push>, cfe<fork_join>>, L1>, L0>;
			};
		}

		template <typename List, template <typename...> class F = list>
		using product = c::call<c::product<c::cfe<F>>, List>;
	}
}

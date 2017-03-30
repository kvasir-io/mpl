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

		template <typename F = listify, typename C = listify>
		struct product {
			// push front the element from the first list, continue into F
			template <typename T>
			using transform_push = transform<push_front<T, F>>;

			// call all the functions Ts with some input, joining the output
			template <typename... Ts>
			using fork_join = fork<join<C>, Ts...>;

			template <typename L0, typename L1, typename... Ls>
			using f = call<unpack<call<unpack<transform<cfe<transform_push>, cfe<fork_join>>>, L1>>, L0>;
		};
		namespace eager {
			template <typename List, template <typename...> class F = list>
			using product = call<unpack<mpl::product<cfe<F>>>, List>;
		}
	}
}

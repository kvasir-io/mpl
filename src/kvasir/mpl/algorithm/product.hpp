//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../functional/fork.hpp"
#include "../sequence/push_back.hpp"
#include "../sequence/push_front.hpp"
#include "../algorithm/transform.hpp"
#include "../functional/bind.hpp"

namespace kvasir {
	namespace mpl {
		namespace c {
			template<typename F = listify>
			struct product {
				template<typename L0, typename L1, typename...Ls>
				using f = call<call<transform<push_back<F, cfe<push_front, cfe<transform>>>, push_front<listify, cfe<fork>>>, L1>, L0>;
			};
		}

		template <typename List, template <typename...> class F = list>
		using product = c::call<c::product<c::cfe<F>>, List>;
	}
}

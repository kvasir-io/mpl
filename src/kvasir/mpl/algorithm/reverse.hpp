//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../sequence/push_front.hpp"
#include "../sequence/pop_front.hpp"
#include "../sequence/create.hpp"

namespace kvasir {
	namespace mpl {
		namespace impl {
			template <typename List, typename Result>
			struct reverse_impl {
				template <typename State, typename Elem>
				using push_front_pred = typename push_front_impl<Elem, State>::f;
				using f = typename fold_left_impl<List>::template f<push_front_pred, Result>;
			};
		}

		template <typename List, typename Result = typename impl::create_impl<List>::f>
		using reverse = typename impl::reverse_impl<List, Result>::f;
	}
}
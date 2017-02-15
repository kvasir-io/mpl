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
			template <typename List>
			struct reverse_impl {
				template <typename Result, typename Elem>
				using push_front_pred = typename push_front_impl<Elem, Result>::f;
				using f               = typename fold_left_impl<List>::template f<push_front_pred,
				                                                    typename create_impl<List>::f>;
			};
		}

		template <typename List>
		using reverse = typename impl::reverse_impl<List>::f;
	}
}
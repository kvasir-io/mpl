//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../types/list.hpp"
#include "../sequence/push_back.hpp"
#include "../sequence/create.hpp"

namespace kvasir {
	namespace mpl {
		namespace impl {
			template <template <typename...> class F, typename List>
			struct transform_impl {
				template <typename Result, typename Elem>
				using transform_pred = typename push_back_impl<F<Elem>, Result>::f;
				using f              = typename fold_left_impl<List>::template f<transform_pred,
				                                                    typename create_impl<List>::f>;
			};

			/// kvasir::mpl::list implementation
			template <template <typename...> class F, typename... Ts>
			struct transform_impl<F, mpl::list<Ts...>> {
				using f = mpl::list<F<Ts>...>;
			};
		}

		/// transform each element in a list with a function
		template <template <typename...> class F, typename List>
		using transform = typename impl::transform_impl<F, List>::f;
	}
}
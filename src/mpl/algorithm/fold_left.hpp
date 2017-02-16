//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../types/list.hpp"

namespace kvasir {
	namespace mpl {
		namespace impl {
			template <template <typename, typename> class Func, typename State, typename List>
			struct fold_left_impl;

			/// kvasir::mpl::list implementation
			template <template <typename, typename> class Func, typename State, typename T,
			          typename... Ts>
			struct fold_left_impl<Func, State, mpl::list<T, Ts...>> {
				using f = Func<typename fold_left_impl<Func, State, Ts...>::f, T>;
			};

			template <template <typename, typename> class Func, typename State>
			struct fold_left_impl<Func, State, mpl::list<>> {
				using f = State;
			};
		}

		/// fold left over a list, initialized with State
		template <template <typename, typename> class Func, typename State, typename List>
		using fold_left = typename fold_left_impl<Func, State, List>::f;
	}
}
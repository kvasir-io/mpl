//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../types/list.hpp"
#include "../sequence/push_front.hpp"

namespace kvasir {
	namespace mpl {

		namespace detail {

			template <typename List, typename... Ts>
			struct reverse_impl {
				using f = List;
			};

			template <typename List, typename T, typename... Ts>
			struct reverse_impl<List, T, Ts...> {
				// use push_front_impl since this is internal code
				using f = reverse_impl<typename push_front_impl<T, List>::f, Ts...>;
			};
		}

		template <typename List>
		struct reverse_impl;

		/// kvasir::mpl::list implementation
		template <typename... Ts>
		struct reverse_impl<mpl::list<Ts...>> {
			using f = typename detail::reverse_impl<mpl::list<>, Ts...>::f;
		};

		template <typename List>
		using reverse = typename reverse_impl<List>::f;
	}
}
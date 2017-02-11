//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../types/list.hpp"

namespace kvasir {
	namespace mpl {

		namespace detail {

			template <template <typename> class Cond, typename... Ts>
			struct find_if_impl;

			template <bool Cond>
			struct find_if_selector;
			template <>
			struct find_if_selector<true> {
				template <template <typename> class Cond, typename... Ts>
				using f = mpl::list<Ts...>;
			};
			template <>
			struct find_if_selector<false> {
				template <template <typename> class Cond, typename T, typename... Ts>
				using f = find_if_impl<Cond, Ts...>;
			};

			template <template <typename> class Cond, typename... Ts>
			struct find_if_impl {
				// no more elements
				using f = mpl::list<>;
			};

			template <template <typename> class Cond, typename T, typename... Ts>
			struct find_if_impl<Cond, T, Ts...> {
				using f = typename find_if_selector<Cond<T>{}>::template f<Cond, T, Ts...>;
			};
		}

		template <template <typename> class Cond, typename List>
		struct find_if_impl;

		/// kvasir::mpl::list implementation
		template <template <typename> class Cond, typename... Ts>
		struct find_if_impl<Cond, mpl::list<Ts...>> {
			using f = typename detail::find_if_impl<Cond, Ts...>::f;
		};

		/// fold left over a list, initialized with State
		template <template <typename> class Cond, typename List>
		using find_if = typename find_if_impl<Cond, List>::f;
	}
}
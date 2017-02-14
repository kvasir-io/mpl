//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../types/list.hpp"
#include "../sequence/push_back.hpp"

namespace kvasir {
	namespace mpl {
		namespace impl {
			namespace list {
				template <bool cond>
				struct push_if;
				template <>
				struct push_if<true> {
					template <typename Elem, typename List>
					using f = typename push_back_impl<Elem, List>::f;
				};
				template <>
				struct push_if<false> {
					template <typename Elem, typename List>
					using f = List;
				};

				template <template <typename...> class Cond, typename Result, typename... Ts>
				struct remove_if_impl {
					using f = Result;
				};

				template <template <typename...> class Cond, typename Result, typename T,
				          typename... Ts>
				struct remove_if_impl<Cond, Result, T, Ts...> {
					using f = typename remove_if_impl<
					        Cond, typename push_if<Cond<T>{}>::template f<T, Result>, Ts...>::f;
				};
			}

			template <template <typename...> class Cond, typename List>
			struct remove_if_impl;

			/// kvasir::mpl::list implementation
			template <template <typename...> class Cond, typename... Ts>
			struct remove_if_impl<Cond, mpl::list<Ts...>> {
				using f = typename list::remove_if_impl<Cond, mpl::list<>, Ts...>::f;
			};
		}

		/// filter elements from a list
		/// takes a lambda that should return a type convertible to bool
		template <template <typename...> class Cond, typename List>
		using remove_if = typename impl::remove_if_impl<Cond, List>::f;
	}
}
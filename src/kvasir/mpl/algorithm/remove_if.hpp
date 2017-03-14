//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../algorithm/transform.hpp"
#include "../functional/bind.hpp"
#include "../functional/call.hpp"
#include "../sequence/join.hpp"

namespace kvasir {
	namespace mpl {
		namespace c {
			namespace detail {
				template <bool>
				struct list_wrap_if;
				template <>
				struct list_wrap_if<true> {
					template <typename T>
					using f = list<T>;
				};
				template <>
				struct list_wrap_if<false> {
					template <typename>
					using f = list<>;
				};
			}
			template <typename F>
			struct list_wrap_if {
				template <typename T>
				using f = typename detail::list_wrap_if<typename F::template f<T>{}>::template f<T>;
			};
			template <template <typename...> class F>
			struct list_wrap_if<lambda<F>> {
				template <typename T>
				using f = typename detail::list_wrap_if<F<T>{}>::template f<T>;
			};
			template <typename F>
			struct list_wrap_if_not {
				template <typename T>
				using f = typename detail::list_wrap_if<(!typename F::template f<T>{})>::template
				f<T>;
			};
			template <template <typename...> class F>
			struct list_wrap_if_not<lambda<F>> {
				template <typename T>
				using f = typename detail::list_wrap_if<(!F<T>{})>::template f<T>;
			};

			/// continuation version of remove_if, taking a continuation and predicate
			template <typename Cond, typename C = listify>
			using remove_if = transform<list_wrap_if_not<Cond>, join<C>>;
		}

		/// filter elements from a list
		/// takes a lambda that should return a type convertible to bool
		template <typename List, template <typename...> class Cond>
		using remove_if = c::call<c::remove_if<lambda<Cond>>, List>;
	}
}

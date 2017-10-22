//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../algorithm/transform.hpp"
#include "../functional/bind.hpp"
#include "../functional/call.hpp"
#include "../functional/identity.hpp"
#include "../sequence/join.hpp"

namespace kvasir {
	namespace mpl {
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
		} // namespace detail
		template <typename F>
		struct list_wrap_if {
			template <typename T>
			using f = typename detail::list_wrap_if<F::template f<T>::value>::template f<T>;
		};
		/// \exclude
		template <template <typename> class F>
		struct list_wrap_if<cfe<F, identity>> {
			template <typename T>
			using f = typename detail::list_wrap_if<F<T>::value>::template f<T>;
		};
		template <typename F>
		struct list_wrap_if_not {
			template <typename T>
			using f = typename detail::list_wrap_if<(!F::template f<T>::value)>::template f<T>;
		};
		/// \exclude
		template <template <typename> class F>
		struct list_wrap_if_not<cfe<F, identity>> {
			template <typename T>
			using f = typename detail::list_wrap_if<(!F<T>::value)>::template f<T>;
		};

		/// \brief removes all elements for which a predicate holds
		template <typename F = identity, typename C = listify>
		using remove_if = transform<list_wrap_if_not<F>, join<C>>;

		namespace eager {
			template <typename List, template <typename...> class Cond = identity>
			using remove_if = call<unpack<mpl::remove_if<cfe<Cond>>>, List>;
		}
	} // namespace mpl
} // namespace kvasir

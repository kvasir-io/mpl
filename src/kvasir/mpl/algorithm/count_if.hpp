//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "filter.hpp"
#include "../functional/bind.hpp"
#include "../sequence/size.hpp"
#include "../utility/conditional.hpp"

namespace kvasir {
	namespace mpl {
		namespace detail {
			template <typename F>
			struct list_wrap_void_if {
				template <typename T>
				using f = typename conditional<F::template f<T>::value>::template f<list<void>,
				                                                                    list<>>;
			};
			template <template <typename...> class F>
			struct list_wrap_void_if<cfe<F, identity>> {
				template <typename T>
				using f = typename conditional<F<T>::value>::template f<list<void>, list<>>;
			};
		} // namespace detail
		/// \brief counts elements for which the predicate holds
		/// \effects resolves to uint_<X> where X is the number of elements in the input pack which
		/// fulfill the provided predicate. \requires Type `F` shall be a `continuation predicate`
		/// and `C` shall be any `continuation`. example call<count_if<same_as<void>>,void,int,char>
		/// resolves to uint_<1>.
		template <typename F = identity, typename C = identity>
		using count_if = transform<detail::list_wrap_void_if<F>, join<size<C>>>;

		namespace eager {
			template <typename List, template <typename...> class Cond = identity>
			using count_if = call<unpack<mpl::count_if<cfe<Cond>>>, List>;
		}
	} // namespace mpl
} // namespace kvasir

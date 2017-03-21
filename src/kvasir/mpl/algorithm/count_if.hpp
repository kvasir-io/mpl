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
		namespace c {
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
			}
			template <typename Cond>
			using count_if = transform<detail::list_wrap_void_if<Cond>, join<size>>;
		}

		/// filter elements from a list
		/// takes a lambda that should return a type convertible to bool
		template <typename List, template <typename...> class Cond = identity>
		using count_if = c::call<c::count_if<c::cfe<Cond>>, List>;
	}
}

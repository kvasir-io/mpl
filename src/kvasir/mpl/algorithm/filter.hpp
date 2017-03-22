//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "remove_if.hpp"
#include "../functional/identity.hpp"

namespace kvasir {
	namespace mpl {
		namespace c {
			/// continuation version of filter, taking a continuation and predicate
			template <typename Cond, typename C = listify>
			using filter = transform<list_wrap_if<Cond>, join<C>>;
		}

		/// filter elements from a list
		/// takes a lambda that should return a type convertible to bool
		template <typename List, template <typename...> class Cond = identity>
		using filter = c::call<c::filter<c::cfe<Cond>>, List>;
	}
}

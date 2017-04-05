//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "remove_if.hpp"
#include "../functional/identity.hpp"

namespace kvasir {
	namespace mpl {
		/// \effects calls `C` with all elements in the input pack for which the provided predicate `F` holds.
		/// \requires Type `F` shall be a `ContinuationPredicate` and C shall be any `Continuation`.
		/// \example call<filter<same_as<int>,cfe<std::tuple>>,void,int,char> resolves to std::tuple<int>.
		template <typename F, typename C = listify>
		using filter = transform<list_wrap_if<F>, join<C>>;

		namespace eager {
			/// filter elements from a list
			/// takes a lambda that should return a type convertible to bool
			template <typename List, template <typename...> class F = identity>
			using filter = call<unpack<mpl::filter<cfe<F>>>, List>;
		}
	}
}

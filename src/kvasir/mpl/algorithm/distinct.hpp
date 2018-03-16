//          Copyright Emil Fresk 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "remove_adjacent.hpp"
#include "stable_sort.hpp"
#include "../functional/fork.hpp"
#include "../functional/identity.hpp"
#include "../sequence/size.hpp"
#include "../utility/is_same.hpp"

namespace kvasir {
	namespace mpl {
		/// \brief Resolves to true_ if all elements in the input pack are distinct,
		/// otherwise false_. \requires Type Comp shall be any comparison for sorting the
		/// types, type IsSame shall be any comparison for checking if two types are the same,
		/// and type C shall be any `continuation`.
		/// example call<distinct<>, void,int,char> resolves to true_, and
		/// call<distinct<>, void,int,char,int> resolves to false_.
		template <typename Comp = is_same<>, typename IsSame = is_same<>, typename C = identity>
		using distinct =
		        fork<size<>, stable_sort<Comp, remove_adjacent<IsSame, size<>>>, is_same<C>>;
		namespace eager {
			template <typename List, typename Comp = is_same<>, typename IsSame = is_same<>>
			using distinct = call<unpack<distinct<Comp, IsSame>>, List>;
		}
	} // namespace mpl
} // namespace kvasir

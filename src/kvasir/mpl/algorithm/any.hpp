//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "contains.hpp"
#include "../utility/identity.hpp"

namespace kvasir {
	namespace mpl {
		/// filter elements from a list
		/// takes a lambda that should return a type convertible to bool
		template <typename List, template <typename...> class Cond = identity>
		using any = impl::contains_impl<Cond, List>;
	}
}
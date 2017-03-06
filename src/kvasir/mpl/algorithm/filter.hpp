//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once
#include "remove_if.hpp"


namespace kvasir {
	namespace mpl {

		/// filter elements from a list
		/// takes a lambda that should return a type convertible to bool
		template <template <typename...> class Cond, typename List>
		using filter = c::call<c::transform<c::join<c::listify>, c::list_wrap_if<Cond>>, List>;
	}
}

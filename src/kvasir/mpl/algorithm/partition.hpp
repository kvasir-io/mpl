//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../algorithm/remove_if.hpp"

namespace kvasir {
	namespace mpl {

		template <template <typename...> class Cond, typename List>
		using partition = c::call<
			list<  //using the forking version
			c::listify, 
			c::transform<c::join<c::listify>, c::list_wrap_if_not<Cond>>, //essentially a remove if
			c::transform<c::join<c::listify>, c::list_wrap_if<Cond>>>, //essentially a filter
			List>;
	}
}
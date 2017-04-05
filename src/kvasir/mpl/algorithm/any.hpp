//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "find_if.hpp"
#include "../functional/identity.hpp"
#include "../types/bool.hpp"
#include "../utility/always.hpp"

namespace kvasir {
	namespace mpl {
		template <typename F>
		using any = find_if<F, always<bool_<true>>,always<bool_<false>>>;
		namespace eager {
			/// filter elements from a list
			/// takes a lambda that should return a type convertible to bool
			template <typename List, template <typename...> class Cond = identity>
			using any = call<unpack<mpl::any<cfe<Cond>>>, List>;
		}
	}
}

//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "find_if.hpp"
#include "../functional/identity.hpp"

namespace kvasir {
	namespace mpl {
		namespace detail {
			struct one_or_more {
				template <typename... Ts>
				using f = bool_<(sizeof...(Ts) > 0)>;
			};
		}
		template <typename F>
		using any = find_if<F, detail::one_or_more>;
		namespace eager {
			/// filter elements from a list
			/// takes a lambda that should return a type convertible to bool
			template <typename List, template <typename...> class Cond = identity>
			using any = call<unpack<mpl::any<cfe<Cond>>>, List>;
		}
	}
}

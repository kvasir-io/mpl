//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../algorithm/filter.hpp"
#include "../algorithm/remove_if.hpp"
#include "../functional/fork.hpp"
#include "../functional/identity.hpp"

namespace kvasir {
	namespace mpl {
		namespace c {
			template <typename Cond, typename R = listify>
			using partition = c::fork<R, remove_if<Cond>, filter<Cond>>;
		}

		template <typename List, template <typename...> class Cond = identity>
		using partition = c::call<c::partition<c::cfe<Cond>>, List>;
	}
}

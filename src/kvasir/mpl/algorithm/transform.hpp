//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../functional/bind.hpp"
#include "../functional/call.hpp"
#include "../types/list.hpp"

namespace kvasir {
	namespace mpl {
		namespace c {

			/// transform a list using a type wrapped predicate
			template <class F, typename C = listify>
			struct transform {
				template <typename... Ts>
				using f = typename C::template f<typename F::template f<Ts>...>;
			};
		}

		/// transform each element in a list with a function
		template <template <typename...> class F, typename List>
		using transform = c::call<c::transform<c::listify, bind<F>>, List>;
	}
}
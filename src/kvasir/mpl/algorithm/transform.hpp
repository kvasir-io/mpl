//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../types/list.hpp"
#include "../functional/call.hpp"
#include "../functional/bind.hpp"

namespace kvasir {
	namespace mpl {
		namespace c {

			///transform a list using a type wrapped predicate
			template<typename C, class F>
			struct transform {
				template<typename...Ts>
				using f = typename C::template f<typename F::template f<Ts>...>;
			};

			///forkable version of transform
			template<typename R, typename...C, class F>
			struct transform<list<R,C...>,F> {
				template<typename...Ts>
				using f = typename R::template f<typename C::template f<typename F::template f<Ts>...>...>;
			};

		}

		/// transform each element in a list with a function
		template <template <typename...> class F, typename List>
		using transform = c::call<c::transform<c::listify,bind<F>>, List>;
	}
}
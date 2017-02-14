//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

namespace kvasir {
	namespace mpl {
		/// bind a function object to a type so that it can be returned or stored in a list
		/// this version of bind differs from normal implementations in that it does not take the
		/// parameters for it's execution in the initial call site, thus allowing the function to
		/// be either extracted from the type, or to be processed and used at a later stage.
		/// It is however possible to add parameters to the function before execution, so that
		/// they will be prepended to the function arguments when it is called.
		template <template <typename...> class Func, typename... Args>
		struct bind {
			template <typename... Ts>
			using f = Func<Args..., Ts...>;
		};
	}
}

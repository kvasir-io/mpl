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
		/// be either extracted from the type, or to be processed and used at a later stage
		template <template <typename...> class Func>
		struct bind {
			template <typename... Ts>
			using f = Func<Ts...>;
		};
	}
}

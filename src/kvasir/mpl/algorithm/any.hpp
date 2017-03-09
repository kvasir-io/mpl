//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "find_if.hpp"

namespace kvasir {
	namespace mpl {
		namespace c {
			namespace detail {
				struct one_or_more {
					template<typename...Ts>
					using f = std::integral_constant<bool, (sizeof...(Ts) > 0)>;
				};
			}
			template<typename F>
			struct any : find_if<F, detail::one_or_more> {};
		}
		/// filter elements from a list
		/// takes a lambda that should return a type convertible to bool
		template <template <typename...> class Cond, typename List>
		using any = c::call<c::any<bind<Cond>>, List>;
	}
}
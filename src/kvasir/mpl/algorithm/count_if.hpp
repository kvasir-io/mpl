//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "remove_if.hpp"
#include "../sequence/size.hpp"
#include "../functional/compose.hpp"
#include "../utility/invert.hpp"

namespace kvasir {
	namespace mpl {
		//namespace impl {
		//	/// generic implementation for any list type
		//	template <template <typename...> class Cond, typename List>
		//	struct count_if_impl {
		//		using f = size_impl<remove_if_impl<compose<Cond, invert>::template f, List>>;
		//	};
		//}

		/// filter elements from a list
		/// takes a lambda that should return a type convertible to bool
		template <template <typename...> class Cond, typename List>
		using count_if = int; // typename impl::count_if_impl<Cond, List>::f;
	}
}
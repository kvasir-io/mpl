//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "remove_if.hpp"
#include "../sequence/size.hpp"
#include "../functional/compose.hpp"
#include "../utility/invert.hpp"

namespace kvasir {
	namespace mpl {
		namespace impl {
			/// generic implementation for any list type
			template <template <typename...> class Cond, typename List>
			struct all_impl {
				constexpr operator bool() const {
					return 0; // size_impl<remove_if_impl<Cond, List>>{} == 0;
					//TODO implement this in faster terms
				}
			};
		};

		/// filter elements from a list
		/// takes a lambda that should return a type convertible to bool
		template <template <typename...> class Cond, typename List>
		using all = impl::all_impl<Cond, List>;
	}
}
//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <cstddef>

#include "../types/list.hpp"

namespace kvasir {
	namespace mpl {
		namespace impl {
			template <typename List>
			struct size_impl;

			/// kvasir::mpl::list implementation
			template <typename... Ts>
			struct size_impl<mpl::list<Ts...>> {
				constexpr operator std::size_t() const {
					return sizeof...(Ts);
				}
			};
		}

		/// get the size of a list, the returned type is convertible to some unspecified int type
		template <typename List>
		using size = typename impl::size_impl<List>::f;
	}
}

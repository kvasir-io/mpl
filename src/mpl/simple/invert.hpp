//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

namespace kvasir {
	namespace mpl {
		namespace impl {
			template <bool val>
			struct invert_impl {
				constexpr operator bool() const {
					return !val;
				}
			};
		}

		template <typename B>
		using invert = detail::invert_impl<B{}>;
	}
}

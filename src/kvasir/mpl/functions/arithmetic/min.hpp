//          Copyright Emil Fresk 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

namespace kvasir {
	namespace mpl {
		namespace detail {

			template <bool>
			struct min_impl;

			template <>
			struct min_impl<true> {
				template <typename A, typename B>
				using f = A;
			};

			template <>
			struct min_impl<false> {
				template <typename A, typename B>
				using f = B;
			};
		}

		template <typename A, typename B>
		using min = typename detail::max_impl<(A{} < B{})>::template f<A, B>;
	}
}
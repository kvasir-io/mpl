//          Copyright Odin Holmes & Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

namespace kvasir {
	namespace mpl {
		template <bool>
		struct conditional;

		template <>
		struct conditional<true> {
			template <typename A, typename B>
			using f = A;
		};

		template <>
		struct conditional<false> {
			template <typename A, typename B>
			using f = B;
		};
	} // namespace mpl
} // namespace kvasir

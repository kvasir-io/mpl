//          Copyright Odin Holmes & Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

namespace kvasir {
	namespace mpl {
		/// \brief continuation version fo std::conditional
		template <bool>
		struct conditional;
		/// \exclude
		template <>
		struct conditional<true> {
			template <typename A, typename B>
			using f = A;
		};
		/// \exclude
		template <>
		struct conditional<false> {
			template <typename A, typename B>
			using f = B;
		};
	} // namespace mpl
} // namespace kvasir

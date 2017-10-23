//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

namespace kvasir {
	namespace mpl {
		/// \brief universal unsigned integer type
		template <unsigned long long Value>
		struct uint_ {
			static constexpr unsigned long long value = Value;
		};
		/// \brief universal integer type
		template <long long Value>
		struct int_ {
			static constexpr long long value = Value;
		};
	} // namespace mpl
} // namespace kvasir

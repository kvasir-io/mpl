//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

namespace kvasir {
	namespace mpl {
		template <unsigned long long Value>
		struct uint_ {
			static constexpr unsigned long long value = Value;
		};

		template <long long Value>
		struct int_ {
			static constexpr long long value = Value;
		};
	} // namespace mpl
} // namespace kvasir

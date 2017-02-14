//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

namespace kvasir {
	namespace mpl {
		template <typename T, T val>
		struct integral_constant {
			constexpr operator T() const {
				return val;
			}
		};

		template <bool val>
		using bool_constant = integral_constant<bool, val>;

		template <typename T>
		constexpr auto make_integral(const T &&val) -> integral_constant<T, val> {
			return {};
		}
	}
}

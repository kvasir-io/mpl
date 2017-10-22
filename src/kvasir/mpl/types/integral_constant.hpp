//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

namespace kvasir {
	namespace mpl {
		template <typename T, T val>
		struct integral_constant {
			static constexpr T value = val;
		};

		namespace eager {
			template <typename T>
			struct is_integral {
				static constexpr bool value = false;
			};

			template <typename T, T val>
			struct is_integral<integral_constant<T, val>> {
				static constexpr bool value = true;
			};

			template <typename T>
			struct is_integral<integral_constant<T, nullptr>> {
				static constexpr bool value = true;
			};

			template <>
			struct is_integral<integral_constant<decltype(nullptr), nullptr>> {
				static constexpr bool value = true;
			};
		} // namespace eager
	} // namespace mpl
} // namespace kvasir

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

		template <typename T>
		struct is_integral {
			constexpr operator bool() const {
				return false;
			}
		};

		template <typename T, T val>
		struct is_integral<integral_constant<T, val>> {
			constexpr operator bool() const {
				return true;
			}
		};

		template <typename T>
		struct is_integral<integral_constant<T, nullptr>> {
			constexpr operator bool() const {
				return true;
			}
		};
	}
}

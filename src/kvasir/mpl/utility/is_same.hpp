//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once
#include <type_traits>
#include "../functional/identity.hpp"
namespace kvasir {
	namespace mpl {
		template <typename C = identity>
		struct is_same {
			template <typename T, typename U>
			using f = typename C::template f<std::is_same<T, U>>;
		};
		template <>
		struct is_same<identity> {
			template <typename T, typename U>
			using f = std::is_same<T, U>;
		};
		template <typename M, typename C = identity>
		struct same_as {
			template <typename T>
			using f = typename C::template f<std::is_same<M, T>>;
		};
		template <typename M>
		struct same_as<M, identity> {
			template <typename T>
			using f = std::is_same<M, T>;
		};
	} // namespace mpl
} // namespace kvasir

//          Copyright Odin Holmes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "compatability.hpp"
#include "../utility/conditional.hpp"

namespace kvasir {
	namespace mpl {
		namespace detail {
			template <bool b, typename C>
			struct dependant_impl;
			template <typename C>
			struct dependant_impl<true, C> : C {};
		} // namespace detail

		template <typename C, unsigned size>
		using dcall = typename detail::dependant_impl<static_cast<bool>(size < 100000), C>;

		template <bool>
		struct dcallf;
		template <>
		struct dcallf<true> {
			template <template <typename...> class F1, typename... Ts>
			using f1 = F1<Ts...>;
			template <template <typename...> class F1, template <typename...> class F2,
			          typename... Ts>
			using f2 = F1<F2<Ts...>>;
		};
		template <>
		struct dcallf<false> {
			template <template <typename...> class F1, typename... Ts>
			using f1 = F1<>;
			template <template <typename...> class F1, template <typename...> class F2,
			          typename... Ts>
			using f2 = F1<F2<>>;
		};
	} // namespace mpl
} // namespace kvasir

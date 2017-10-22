//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../compatability/dependent_call.hpp"
#include "../types/list.hpp"

namespace kvasir {
	namespace mpl {
		template <typename Input, typename C = listify>
		struct push_front {
			template <typename... Ts>
			using f = typename dcall<C, sizeof...(Ts)>::template f<Input, Ts...>;
		};
		namespace eager {
			namespace impl {
				template <typename Elem, typename List>
				struct push_front_impl;

				/// kvasir::mpl::list implementation
				template <typename Elem, typename... Ts>
				struct push_front_impl<Elem, mpl::list<Ts...>> {
					using f = mpl::list<Elem, Ts...>;
				};
			} // namespace impl

			/// push an element to the back of a list
			template <typename Elem, typename List>
			using push_front = typename impl::push_front_impl<Elem, List>::f;
		} // namespace eager
	} // namespace mpl
} // namespace kvasir

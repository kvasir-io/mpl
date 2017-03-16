//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../types/list.hpp"
#include "../types/nothing.hpp"
#include "../compatability/dependent_call.hpp"
#include <type_traits>

namespace kvasir {
	namespace mpl {
		namespace c {
			template<typename C>
			struct pop_front {
				template<typename T, typename...Ts>
				using f = typename std::conditional<(sizeof...(Ts)<100000), C, void>::type::template f< Ts... >;
			};
		}
		namespace impl {
			template <typename List>
			struct pop_front_impl {
				// when used with any element, just return the element
				using front = List;
				using rest  = nothing;
			};

			template <typename T, typename... Ts>
			struct pop_front_impl<mpl::list<T, Ts...>> {
				using front = T;
				using rest  = mpl::list<Ts...>;
			};

			template <>
			struct pop_front_impl<mpl::list<>> {
				// when the list is empty return nothing as the element and an empty list as rest
				using front = nothing;
				using rest  = mpl::list<>;
			};
		}

		/// pop a single element from the front of a list
		/// returns a pair of the first element and the rest of the list, with ::front and ::rest
		/// respectively
		/// when the input is not a list, ::front will be the element, and ::rest will be nothing
		/// when the input is an empty list, ::front will be nothing, and ::rest will be an empty
		/// list
		template <typename List>
		using pop_front = impl::pop_front_impl<List>;
	}
}

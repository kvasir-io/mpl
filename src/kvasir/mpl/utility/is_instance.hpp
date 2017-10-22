//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../types/bool.hpp"

namespace kvasir {
	namespace mpl {
		namespace eager {
			namespace impl {
				template <template <typename...> class Type, typename T>
				struct is_instance_impl {
					using f = bool_<false>;
				};

				template <template <typename...> class Type, typename... Ts>
				struct is_instance_impl<Type, Type<Ts...>> {
					using f = bool_<true>;
				};
			} // namespace impl

			template <template <typename...> class Type, typename T>
			using is_instance = typename impl::is_instance_impl<Type, T>::f;
		} // namespace eager
	} // namespace mpl
} // namespace kvasir

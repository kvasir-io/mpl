//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../types/bool.hpp"
#include "../types/list.hpp"

namespace kvasir {
	namespace mpl {
		namespace eager {
			namespace impl {
				template <typename Elem>
				struct is_list {
					using f = bool_<false>;
				};

				template <typename... Ts>
				struct is_list<mpl::list<Ts...>> {
					using f = bool_<true>;
				};
			} // namespace impl

			template <typename Elem>
			using is_list = typename impl::is_list<Elem>::f;
		} // namespace eager
	} // namespace mpl
} // namespace kvasir

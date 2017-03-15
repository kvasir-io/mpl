//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../sequence/join.hpp"

namespace kvasir {
	namespace mpl {
		namespace detail {

			template <class L>
			struct flatten_impl {
				using type = L;
			};

			template <template <class...> class L, class T>
			struct flatten_element_impl {
				using type = L<T>;
			};

			template <template <class...> class L, class... Ts>
			struct flatten_element_impl<L, L<Ts...>> {
				using type = typename c::detail::join_select<c::detail::select_join_size(sizeof...(
				        Ts))>::template f<list, typename flatten_element_impl<L, Ts>::type...>;
			};

			template <template <class...> class L, class... Ts>
			struct flatten_impl<L<Ts...>> {
				using type = typename flatten_element_impl<L, L<Ts...>>::type;
			};
		}

		template <typename Sequence>
		using flatten = typename detail::flatten_impl<Sequence>::type;
	}
}

//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../types/list.hpp"
#include "../sequence/push_back.hpp"

namespace kvasir {
	namespace mpl {

		namespace detail {

			template<unsigned N>
			struct partition_impl {
				template<typename Result, typename T, typename ...Ts>
				using f = typename partition_impl<N - 1>
				::template f<push_back_impl<T, Result>, Ts...>;
			};

			template<>
			struct partition_impl<0> {
				template<typename Result, typename ...Ts>
				using f = mpl::list<Result, mpl::list<Ts...>>;
			};

		}

		template<unsigned N, typename List>
		struct partition_impl;


		/// kvasir::mpl::list implementation
		template<unsigned N, typename ...Ts>
		struct partition_impl<N, mpl::list<Ts...>> {
		using f = typename detail::partition_impl<N>::template f<mpl::list<>, Ts...>;
	};

		/// partition a list by a certain number of elements
		/// returns a pair with the first element being the front part, and the second element
		/// being the back
		template<unsigned N, typename List>
		using partition = typename partition_impl<N, List>::f;

	}
}
//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../types/list.hpp"
#include "../sequence/push_back.hpp"
#include "../sequence/pop_front.hpp"
#include "../sequence/create.hpp"

namespace kvasir {
	namespace mpl {
		namespace impl {
			namespace generic {
				template <unsigned N>
				struct partition_impl {
					template <typename Result, typename List>
					using f = typename partition_impl<N - 1>::template f<
					        push_back_impl<typename pop_front_impl<List>::front, Result>,
					        typename pop_front_impl<List>::rest>;
				};

				template <>
				struct partition_impl<0> {
					template <typename Result, typename List>
					struct f {
						using front = Result;
						using rest  = List;
					};
				};
			}

			template <unsigned N, typename List>
			struct partition_impl {
				using f = typename generic::partition_impl<N>::template f<
				        typename create_impl<List>::f, List>;
			};
		}

		/// partition a list by a certain number of elements
		/// returns a struct that is like the struct in pop_front
		template <typename List, unsigned N>
		using partition = typename impl::partition_impl<N, List>::f;
	}
}
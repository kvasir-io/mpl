//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../sequence/push_back.hpp"
#include "../sequence/create.hpp"
#include "../algorithm/fold_left.hpp"
#include "../utility/identity.hpp"

namespace kvasir {
	namespace mpl {
		namespace impl {
			namespace generic {
				template <bool cond>
				struct push_if;
				template <>
				struct push_if<true> {
					template <typename Elem, typename List>
					using f = typename push_back_impl<Elem, List>::f;
				};
				template <>
				struct push_if<false> {
					template <typename Elem, typename List>
					using f = List;
				};
			}

			template <template <typename...> class Cond, typename List>
			struct remove_if_impl {
				template <typename Result, typename Elem>
				using cond_add_pred =
				        typename generic::push_if<Cond<Elem>{}>::template f<Elem, Result>;

				using f = typename fold_left_impl<List>::template f<cond_add_pred,
				                                                    typename create_impl<List>::f>;
			};
		}

		/// filter elements from a list
		/// takes a lambda that should return a type convertible to bool
		template <typename List, template <typename...> class Cond = identity>
		using remove_if = typename impl::remove_if_impl<Cond, List>::f;
	}
}
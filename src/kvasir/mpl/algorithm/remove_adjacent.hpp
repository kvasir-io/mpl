//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "fold_right.hpp"
#include "../sequence/push_front.hpp"
#include "../types/list.hpp"

namespace kvasir {
	namespace mpl {
		namespace impl {
			namespace generic {
				template <bool>
				struct omit_if;

				template <>
				struct omit_if<false> {
					template <typename T, typename List>
					using f = typename push_front_impl<T, List>::f;
				};

				template <>
				struct omit_if<true> {
					template <typename T, typename List>
					using f = List;
				};

				template <template <typename...> class Pred>
				struct remove_adjacent_func {
					template <typename State, typename Elem>
					using f = typename omit_if<Pred<typename pop_front_impl<State>::front,
					                                Elem>{}>::template f<Elem, State>;
				};

				/// function that combines push_if and is_same
				/// inserts T1 into List if the two element are not the same
				template <typename T1, typename T2, typename List>
				struct omit_if_same {
					using f = typename push_front_impl<T1, List>::f;
				};

				template <typename T, typename List>
				struct omit_if_same<T, T, List> {
					using f = List;
				};

				/// simple optimisation for when using std::is_same (which is most of the time)
				template <>
				struct remove_adjacent_func<std::is_same> {
					template <typename State, typename Elem>
					using f = typename omit_if_same<Elem, typename pop_front_impl<State>::front,
					                                State>::f;
				};
			}

			template <template <typename...> class Pred, typename List>
			struct remove_adjacent {
				using f = typename fold_right_impl<List>::template f<
				        generic::remove_adjacent_func<Pred>::template f, mpl::list<>>;
			};
		}

		/// takes a boolean predicate with two parameters
		/// if the predicate return true for any two adjacent elements,
		/// then the first of the two elements is removed
		template <template <typename...> class Pred, typename List>
		using remove_adjacent = typename impl::remove_adjacent<Pred, List>::f;
	}
}

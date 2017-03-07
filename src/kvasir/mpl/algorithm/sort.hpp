//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../types/nothing.hpp"
#include "../algorithm/fold_left.hpp"
#include "../sequence/create.hpp"
#include "../sequence/push_front.hpp"

namespace kvasir {
	namespace mpl {
		namespace impl {
			namespace generic {
				template <typename Elem, typename Left, typename Right>
				struct bst {};

				template <typename BST>
				struct push_bst;
				template <bool greater>
				struct push_bst_impl;

				template <>
				struct push_bst<nothing> {
					template <template <typename...> class Comp, typename Elem>
					using f = bst<Elem, nothing, nothing>;
				};

				template <typename BSTElem, typename BSTLeft, typename BSTRight>
				struct push_bst<bst<BSTElem, BSTLeft, BSTRight>> {
					template <template <typename...> class Comp, typename Elem>
					using f = typename push_bst_impl<Comp<Elem, BSTElem>{}>::template f<
					        Comp, Elem, BSTElem, BSTLeft, BSTRight>;
				};

				template <>
				struct push_bst_impl<true> {
					template <template <typename...> class Comp, typename Elem, typename BSTElem,
					          typename BSTLeft, typename BSTRight>
					using f = bst<BSTElem, typename push_bst<BSTLeft>::template f<Comp, Elem>,
					              BSTRight>;
				};

				template <>
				struct push_bst_impl<false> {
					template <template <typename...> class Comp, typename Elem, typename BSTElem,
					          typename BSTLeft, typename BSTRight>
					using f = bst<BSTElem, BSTLeft,
					              typename push_bst<BSTRight>::template f<Comp, Elem>>;
				};

				template <typename Elem, typename Result>
				struct flatten_bst {
					// case anything that is not a bst node; must always be nothing
					using f = Result;
				};

				template <typename Elem, typename Left, typename Right, typename Result>
				struct flatten_bst<bst<Elem, Left, Right>, Result> {
					using f = typename flatten_bst<
					        Left, typename push_front_impl<
					                      Elem, typename flatten_bst<Right, Result>::f>::f>::f;
				};

				template <typename Elem, typename Left, typename Elem2, typename Left2,
				          typename Right2, typename Result>
				struct flatten_bst<bst<Elem, Left, bst<Elem2, Left2, Right2>>, Result> {
					using f = typename flatten_bst<
					        Left,
					        typename push_front_impl<
					                Elem,
					                typename flatten_bst<
					                        Left2,
					                        typename push_front_impl<
					                                Elem2, typename flatten_bst<Right2, Result>::
					                                               f>::f>::f>::f>::f;
				};
			}

			template <template <typename...> class Comp, typename List>
			struct sort_impl {
				template <typename Result, typename Elem>
				using push_func = typename generic::push_bst<Result>::template f<Comp, Elem>;

				// implementation of sort using treesort
				using f = typename generic::flatten_bst<
				        int, // TODO fix this     typename fold_left_impl<List>::template f<push_func, nothing>,
				        typename create_impl<List>::f>::f;
			};
		}

		template <template <typename...> class Comp, typename List>
		using sort = typename impl::sort_impl<Comp, List>::f;
	}
}

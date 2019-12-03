//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../algorithm/fold_left.hpp"
#include "../functional/bind.hpp"
#include "../functions/comparison/less_than.hpp"
#include "../sequence/join.hpp"
#include "../sequence/push_front.hpp"
#include "../types/bool.hpp"
#include "../types/list.hpp"
#include "../types/nothing.hpp"

namespace kvasir {
	namespace mpl {
		namespace eager {
			namespace detail {
				// empty element case is just the element

				/// binary search tree node with left element filled
				template <typename Elem, typename Left>
				struct bst_left {};

				/// binary search tree node with right element filled
				template <typename Elem, typename Right>
				struct bst_right {};

				/// binary search tree node with both elements filled
				template <typename Elem, typename Left, typename Right>
				struct bst {};

				// implementation for non-node elements
				template <bool>
				struct push_bst_elem_impl;
				template <>
				struct push_bst_elem_impl<true> {
					template <typename Elem, typename BSTElem>
					using f = bst_left<BSTElem, Elem>;
				};
				template <>
				struct push_bst_elem_impl<false> {
					template <typename Elem, typename BSTElem>
					using f = bst_right<BSTElem, Elem>;
				};
				template <typename Elem>
				struct push_bst {
					// any element case
					template <template <typename...> class Comp, typename T>
					using f =
					        typename push_bst_elem_impl<Comp<T, Elem>::value>::template f<T, Elem>;
				};

				// implementation for nothing
				template <>
				struct push_bst<nothing> {
					template <template <typename...> class Comp, typename Elem>
					using f = Elem;
				};

				// implementation for bst with left as only element
				template <bool>
				struct push_bst_left_impl;
				template <>
				struct push_bst_left_impl<true> {
					template <template <typename...> class Comp, typename T, typename Elem,
					          typename Left>
					using f = bst_left<Elem, typename push_bst<Left>::template f<Comp, T>>;
				};
				template <>
				struct push_bst_left_impl<false> {
					template <template <typename...> class Comp, typename T, typename Elem,
					          typename Left>
					using f = bst<Elem, Left, T>;
				};
				template <typename Elem, typename Left>
				struct push_bst<bst_left<Elem, Left>> {
					template <template <typename...> class Comp, typename T>
					using f = typename push_bst_left_impl<Comp<T, Elem>::value>::template f<
					        Comp, T, Elem, Left>;
				};

				// implementation for bst with right as only element
				template <bool>
				struct push_bst_right_impl;
				template <>
				struct push_bst_right_impl<true> {
					template <template <typename...> class Comp, typename T, typename Elem,
					          typename Right>
					using f = bst<Elem, T, Right>;
				};
				template <>
				struct push_bst_right_impl<false> {
					template <template <typename...> class Comp, typename T, typename Elem,
					          typename Right>
					using f = bst_right<Elem, typename push_bst<Right>::template f<Comp, T>>;
				};
				template <typename Elem, typename Right>
				struct push_bst<bst_right<Elem, Right>> {
					template <template <typename...> class Comp, typename T>
					using f = typename push_bst_right_impl<Comp<T, Elem>::value>::template f<
					        Comp, T, Elem, Right>;
				};

				// implementation for bst with both elements
				template <bool greater>
				struct push_bst_impl;
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
				template <typename Elem, typename Left, typename Right>
				struct push_bst<bst<Elem, Left, Right>> {
					template <template <typename...> class Comp, typename T>
					using f =
					        typename push_bst_impl<Comp<T, Elem>::value>::template f<Comp, T, Elem,
					                                                                 Left, Right>;
				};

				// case for just an element
				template <typename Elem>
				struct flatten_bst {
					using f = list<Elem>;
				};

				// case for nothing
				template <>
				struct flatten_bst<nothing> {
					// case anything that is not a bst node; must always be nothing
					using f = list<>;
				};

				// case for left bst
				template <typename L1, typename E>
				struct join_extents_left;
				template <typename... L1, typename E>
				struct join_extents_left<mpl::list<L1...>, E> {
					using f = mpl::list<L1..., E>;
				};
				template <typename Elem, typename Left>
				struct flatten_bst<bst_left<Elem, Left>> {
					using f = typename join_extents_left<typename flatten_bst<Left>::f, Elem>::f;
				};

				// case for right bst
				template <typename E, typename L1>
				struct join_extents_right;
				template <typename E, typename... L1>
				struct join_extents_right<E, mpl::list<L1...>> {
					using f = mpl::list<E, L1...>;
				};
				template <typename Elem, typename Right>
				struct flatten_bst<bst_right<Elem, Right>> {
					using f = typename join_extents_right<Elem, typename flatten_bst<Right>::f>::f;
				};

				// case for full bst
				template <typename L1, typename E, typename L2>
				struct join_extents;
				template <typename... L1, typename E, typename... L2>
				struct join_extents<mpl::list<L1...>, E, mpl::list<L2...>> {
					using f = mpl::list<L1..., E, L2...>;
				};
				template <typename Elem, typename Left, typename Right>
				struct flatten_bst<bst<Elem, Left, Right>> {
					using f = typename join_extents<typename flatten_bst<Left>::f, Elem,
					                                typename flatten_bst<Right>::f>::f;
				};

				template <template <typename...> class Comp>
				struct push_func {
					template <typename Result, typename Elem>
					using f = typename push_bst<Result>::template f<Comp, Elem>;
				};
			} // namespace detail
			template <typename List, template <typename...> class Comp = less_than>
			using stable_sort = typename detail::flatten_bst<mpl::call<
			        unpack<mpl::push_front<nothing, mpl::fold_left<detail::push_func<Comp>>>>,
			        List>>::f;
		} // namespace eager
		/// \brief stable sorts a pack of elements
		template <typename F = less_than<>, typename C = listify>
		struct stable_sort {
			template <typename... Ts>
			using f = call<unpack<C>, eager::stable_sort<list<Ts...>, F::template f>>;
		};
	} // namespace mpl
} // namespace kvasir

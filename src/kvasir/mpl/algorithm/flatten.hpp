//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../sequence/join.hpp"

namespace kvasir {
	namespace mpl {
		namespace detail {
			template <template <class...> class L, class T>
			struct flatten_element_impl {
				using type = list<T>;
			};

			template <template <class...> class L, class... Ts>
			struct flatten_element_impl<L, L<Ts...>> {
				using type = typename detail::join_select<detail::select_join_size(sizeof...(Ts))>::
				        template f<list, typename flatten_element_impl<L, Ts>::type...>::type;
			};
		} // namespace detail
		/// \brief converts a tree or list of lists into one list containing the contents of all
		/// children \effects \requires example call<flatten<>,list<void>,list<list<int>,char>,bool>
		/// resolves to list<void,int,char,bool>.
		template <typename SequenceType = cfe<list>, typename C = listify>
		struct flatten;
		/// \exclude
		template <template <typename...> class S, typename C>
		struct flatten<cfe<S, identity>, C> {
			template <typename... Ts>
			using f = typename detail::join_select<detail::select_join_size(sizeof...(
			        Ts))>::template f<C::template f,
			                          typename detail::flatten_element_impl<S, Ts>::type...>::type;
		};

		namespace eager {
			namespace detail {
				template <typename T>
				struct flatten_impl;
				template <template <typename...> class S, typename... Ts>
				struct flatten_impl<S<Ts...>> {
					using type = typename mpl::flatten<cfe<S>>::template f<Ts...>;
				};
			} // namespace detail

			template <typename Sequence>
			using flatten = typename detail::flatten_impl<Sequence>::type;
		} // namespace eager
	} // namespace mpl
} // namespace kvasir

//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <utility>

#include "../types/list.hpp"
#include "../sequence/pop_front.hpp"
#include "../sequence/size.hpp"

namespace kvasir {
	namespace mpl {
		namespace impl {
			namespace generic {
				template <bool empty>
				struct fold_left;

				template <>
				struct fold_left<false> {
					template <template <typename...> class Func, typename State, typename List>
					using f = typename fold_left<size_impl<List>{} == 1>::template f<
					        Func, Func<State, typename pop_front_impl<List>::front>,
					        typename pop_front_impl<List>::rest>;
				};

				template <>
				struct fold_left<true> {
					template <template <typename...> class Func, typename State, typename List>
					using f = State;
				};
			}

			template <typename List>
			struct fold_left_impl { // TODO change to using is_empty
				template <template <typename...> class Func, typename State>
				using f = typename generic::fold_left<size_impl<List>{} == 0>::template f<Func,
				                                                                          State>;
			};

#if __cpp_fold_expressions
			namespace list {
				template<template<typename...> class Func, typename State>
				struct fold_monad {
				// not really a monad because the foldee does not contain the function but whatever
					template<typename T>
					constexpr auto operator>>=(folder<T>&&) -> fold_monad<Func<State, T>> {
						return {};
					}

					using f = State;
				};
			}

			template<typename ...Ts>
			struct fold_left_impl<mpl::list<Ts...>> {
				template<template<typename...> class Func, typename State>
				using f = typename (fold_monad<Func, State>{} >>= ... >>= std::declval<Ts>{})::f;
			};
#endif
		}

		/// fold left over a list, initialized with State
		template <template <typename...> class Func, typename State, typename List>
		using fold_left = typename impl::fold_left_impl<List>::template f<Func, State>;
	}
}
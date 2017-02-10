//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../types/list.hpp"

namespace kvasir {
	namespace mpl {

		template<template<typename, typename> class Func, typename State, typename List>
		struct fold_right_impl;


		/// kvasir::mpl::list implementation
		template<template<typename, typename> class Func, typename State, typename T, typename ...Ts>
		struct fold_right_impl<Func, State, mpl::list<T, Ts...>> {
		using f = typename fold_right_impl<Func, Func<State, T>, mpl::list<Ts...>>::f;
	};

	template<template<typename, typename> class Func, typename State>
	struct fold_right_impl<Func, State, mpl::list<>> {
		using f = State;
	};

		/// fold right over a list, initialized with State
		template<template<typename, typename> class Func, typename State, typename List>
		using fold_right = typename fold_right_impl<Func, State, List>::f;

	}
}
//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "filter.hpp"
#include "../sequence/size.hpp"

namespace kvasir {
	namespace mpl {
		namespace c {
			namespace detail {
				template<template<typename...> class F>
				struct list_wrap_void_if {
					template<typename T>
					using f = typename std::conditional<F<T>::value, list<void>, list<>>::type;
				};
			}
			template<template <typename...> class Cond>
			using count_if = transform<detail::list_wrap_void_if<Cond>, join<size>>;
		}


		/// filter elements from a list
		/// takes a lambda that should return a type convertible to bool
		template <template <typename...> class Cond, typename List>
		using count_if = c::call < c::count_if<Cond>, List>;
	}
}
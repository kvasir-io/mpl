//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../functional/call.hpp"
#include "../functional/bind.hpp"
#include "../algorithm/find_if.hpp"

namespace kvasir {
	namespace mpl {
		namespace c {
			namespace detail {
				struct nothing_found {
					template<typename...Ts>
					using f = std::integral_constant<bool, (sizeof...(Ts) == 0)>;
				};
				template<typename F>
				struct not_ {
					template<typename T>
					using f = std::bool_constant<(!F::template f<T>::value)>;
				};
				template<template<typename...> class F>
				struct not_<bind<F>> {
					template<typename T>
					using f = std::bool_constant<(!F<T>::value)>;
				};
			}

			template<typename F>
			struct all : find_if<detail::not_<F>, detail::nothing_found> {};
		}

		/// resolves to std::true_type if all elements in the input list 
		/// fulfill the provided predicate
		template <template <typename...> class Cond, typename List>
		using all = c::call<c::all<bind<Cond>>,List>;
	}
}
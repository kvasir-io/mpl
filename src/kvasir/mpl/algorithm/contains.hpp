//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "all.hpp"

namespace kvasir {
	namespace mpl {
		namespace c {
			template<template<typename...> class F, typename TrueType = std::true_type, typename FalseType = std::false_type>
			struct any {
				template<typename...Ts>
				using f = decltype(detail::all_tester::all_same<std::false_type, FalseType, TrueType>({ std::bool_constant<F<Ts>::value>{}... }));
			};
		}

		/// filter elements from a list
		/// takes a lambda that should return a type convertible to bool
		template <template <typename...> class Cond, typename List>
		using contains = impl::contains_impl<Cond, List>;
	}
}

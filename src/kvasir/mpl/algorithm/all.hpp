//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../functional/call.hpp"

namespace kvasir {
	namespace mpl {
		namespace c {
			namespace detail {
				namespace all_tester {
					struct constructable {
						constructable(...) {}
					};

					template<typename Match, typename T, typename U>
					T all_same(std::initializer_list<Match>) {
						return{};
					}

					template<typename Match, typename T, typename U>
					U all_same(constructable) {
						return{};
					}
				}
			}

			template<template<typename...> class F, typename TrueType = std::true_type, typename FalseType = std::false_type>
			struct all {
				template<typename...Ts>
				using f = decltype(detail::all_tester::all_same<std::true_type, TrueType, FalseType>({ std::bool_constant<F<Ts>::value>{}... }));
			};
		}

		/// resolves to std::true_type if all elements in the input list 
		/// fulfill the provided predicate
		template <template <typename...> class Cond, typename List>
		using all = c::call<c::all<Cond>,List>;
	}
}
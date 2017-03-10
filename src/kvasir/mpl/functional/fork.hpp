//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

namespace kvasir {
	namespace mpl {
		namespace c {
			namespace detail {
				template<typename T>
				struct make_bound : T {};
				template<template<typename...> class F>
				struct make_bound<lambda<F>> {
					template<typename...Ts>
					using f = F<Ts...>;
				};
			}
			template <typename Combiner, typename... Cs>
			struct fork {
				template <typename... Ts>
				using f = typename detail::make_bound<Combiner>::template f<typename detail::make_bound<Cs>::template f<Ts...>...>;
			};
		}
	}
}

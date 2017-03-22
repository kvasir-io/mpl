//          Copyright Odin Holmes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "compatability.hpp"
#include "../utility/conditional.hpp"

namespace kvasir {
	namespace mpl {
		namespace c {
			template<typename C, unsigned size>
			using dcall = typename conditional<(size<100000)>::template f<C, void>;


			template<bool>
			struct dcallf;
			template<>
			struct dcallf<true> {
				template<template<typename...> class F1, typename...Ts>
				using f1 = F1<Ts...>;
				template<template<typename...> class F1, template<typename...> class F2, typename...Ts>
				using f2 = F1<F2<Ts...>>;
			};
			template<>
			struct dcallf<false> {
				template<template<typename...> class F1, typename...Ts>
				using f1 = F1<>;
				template<template<typename...> class F1, template<typename...> class F2, typename...Ts>
				using f2 = F1<F2<>>;
			};


			
		}
	}
}

#define KVASIR_D_CALL(T, Pack) typename ::kvasir::mpl::c::dcall<T,sizeof...(Pack)>::template f




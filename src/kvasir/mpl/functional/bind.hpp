//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../compatability/dependent_call.hpp"
#include "../functional/identity.hpp"
#include "../types/arity.hpp"

namespace kvasir {
	namespace mpl {
		/// \brief makes a continuation from a lazy metafunction /
		/// wraps a template template parameter in such a way that it can be used as a
		/// continuation capable meta closure.
		/// \requires fixed parameters: a template template parameter which contains a nestesd
		/// ::type (the lazy metafunction) dynamic parameters: a variadic pack of type parameters
		/// \effects the result will be whatever the ::type of the lazy metafunction maps to when
		/// passed the dynamic parameters
		template <template <typename...> class F, typename C = identity>
		struct cfl {
			template <typename... Ts>
			using f = typename C::template f<typename F<Ts...>::type>;
		};
		/// \exclude
		template <template <typename...> class F>
		struct cfl<F, identity> {
			template <typename... Ts>
			using f = typename F<Ts...>::type;
		};

		/// \brief makes a continuation from an eager metafunction /
		/// wraps a template template parameter in such a way that it can be used as a
		/// continuation capable meta closure.
		/// \requires fixed parameters: a template template parameter (the eager metafunction)
		/// dynamic parameters: a variadic pack of type parameters
		/// \effects the result will be whatever the eager metafunction maps to when passed the
		/// dynamic parameters
		/// \notes when passed an alias the result is the same as a traditional call to the at
		/// metafunction/ \notes it is perfectly valid to pass a template such as tuple or pair as a
		/// 'metafunction'
		template <template <typename...> class F, typename C = identity>
		struct cfe {
			template <typename... Ts>
			using f = typename dcall<C, sizeof...(Ts)>::template f<
			        typename dcallf<bool(sizeof...(Ts) > 0)>::template f1<F, Ts...>>;
		};
	

		/// \exclude
		template <template <typename...> class F>
		struct cfe<F, identity> {
			template <typename... Ts>
			using f = typename dcallf<bool(sizeof...(Ts) > 0)>::template f1<F, Ts...>;
		};

		/// \brief explicit 1-ary version of cfe
		template <template <typename...> class F, typename C = identity>
		struct cfe1 {
			template <typename T>
			using f = typename C::template f<F<T>>;
		};

		/// \exclude
		template<template<typename...> class F, typename C>
		struct arity_traits<cfe1<F,C>,void>{
			using type = arity<1,1>;
		};
	

		/// \exclude
		template <template <typename...> class F>
		struct cfe1<F,identity> {
			template <typename T>
			using f = F<T>;
		};
	
	} // namespace mpl
} // namespace kvasir

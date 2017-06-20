//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once
#include "../functional/bind.hpp"
#include "../types/list.hpp"

namespace kvasir {
	namespace mpl {
		namespace detail {
			template<typename F, typename T>
			using each_impl = typename F::template f<T>;
		}
		template <typename List, typename C>
		struct fork; 
		template <typename... Fs, typename C>
		struct fork<list<Fs...>, C> {
			template <typename... Ts>
			using f = typename dcall<C, sizeof...(Fs)>::template f<
				typename dcall<Fs, sizeof...(Ts)>::template f<Ts...>...>;
		};
		template <typename List, typename C>
		struct each;
		template <typename... Fs, typename C>
		struct each<list<Fs...>,C> {
			template <typename... Ts>
			using f = typename dcall<C, sizeof...(Ts)>::template f<
				typename Fs::template f<Ts>...>;
		};
		template <typename F, typename C>
		struct fork_front {
			template <typename... Ts>
			using f = typename dcall<C, sizeof...(Ts)>::template f<
			        typename dcall<F, sizeof...(Ts)>::template f<Ts...>, Ts...>;
		};
	}
}

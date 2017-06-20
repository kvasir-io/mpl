//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../compatability/dependent_call.hpp"
#include "../functional/fork.hpp"
#include "../types/list.hpp"
namespace kvasir {
	namespace mpl {
		namespace detail {
			template <typename C, typename L, typename... Ts>
			struct unpack_impl;
			template <typename C, template <typename...> class Seq, typename... Ls, typename... Ts>
			struct unpack_impl<C, Seq<Ls...>, Ts...> {
				using type = typename dcall<C, sizeof...(Ls)>::template f<Ts..., Ls...>;
			};
			// forking version of call expects a "combining" continuation as its first arguement
			// and a variadic pack of continuations which are executed in paralell
			template <typename C, typename... Fs, template <typename...> class Seq, typename... Ls>
			struct unpack_impl<fork<list<Fs...>,C>, Seq<Ls...>> {
				using type = typename C::template f<typename Fs::template f<Ls...>...>;
			};
		}
		template <typename C>
		struct unpack {
			template <typename... Ls>
			using f = typename detail::unpack_impl<C, Ls...>::type;
		};

		// call a continuation (left parameter) with a variadic pack
		template <typename C, typename... Ts>
		using call = typename dcall<C, sizeof...(Ts)>::template f<Ts...>;
	}
}

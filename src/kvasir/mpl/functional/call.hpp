//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../types/list.hpp"
namespace kvasir {
	namespace mpl {
		namespace c {
			namespace detail {
				template<typename C, typename L>
				struct call_impl;
				template<typename C, template<typename...> class Seq, typename...Ts>
				struct call_impl<C, Seq<Ts...>> {
					using type = typename C::template f<Ts...>;
				};
				//forking version of call expects a "combining" continuation as its first arguement 
				//and a variadic pack of continuations which are executed in paralell
				template<typename R, typename...C, template<typename...> class Seq, typename...Ts>
				struct call_impl<list<R, C...>, Seq<Ts...>> {
					using type = typename R::template f<typename C::template f<Ts...>...>;
				};
			}
			template<typename C, typename L>
			using call = typename detail::call_impl<C, L>::type;
		}
	}
}

//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../functional/identity.hpp"
#include "../compatability/dependent_call.hpp"

namespace kvasir {
	namespace mpl {
		template <template <typename...> class F, typename C = identity>
		struct cfl {
			template <typename... Ts>
			using f = typename C::template f<typename F<Ts...>::type>;
		};
		template <template <typename...> class F>
		struct cfl<F, identity> {
			template <typename... Ts>
			using f = typename F<Ts...>::type;
		};

		template <template <typename...> class F, typename C = identity>
		struct cfe {
			template <typename... Ts>
			using f = typename dcall<C, sizeof...(Ts)>::template f<
			        typename dcallf<static_cast<bool>(sizeof...(Ts))>::template f1<F, Ts...>>;
		};
		template <template <typename...> class F>
		struct cfe<F, identity> {
			template <typename... Ts>
			using f = typename dcallf<static_cast<bool>(sizeof...(Ts))>::template f1<F, Ts...>;
		};
	}
}

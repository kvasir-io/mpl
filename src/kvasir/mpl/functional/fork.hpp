//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once
#include "../functional/bind.hpp"

namespace kvasir {
	namespace mpl {
		namespace c {
			template <typename Combiner, typename... Cs>
			struct fork {
				template <typename... Ts>
				using f = typename dcall<Combiner, sizeof...(Cs)>::template f<
					typename dcall<Cs, sizeof...(Ts)>::template f<Ts...>...>;
			};
			template <typename F, typename C>
			struct fork_front {
				template <typename... Ts>
				using f = typename dcall<C, sizeof...(Ts)>::template f<typename dcall<F, sizeof...(Ts)>::template f<Ts...>, Ts...>;
			};
		}
	}
}

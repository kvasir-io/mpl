//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "drop.hpp"
#include "../algorithm/rotate.hpp"
namespace kvasir {
	namespace mpl {
		namespace c {
			template<typename N, typename C = listify>
			struct take {
				template<typename...Ts>
				using f = typename dcall<rotate<N, drop<uint_<(sizeof...(Ts)-N::value)>, C>>, sizeof...(Ts)>::template f<Ts...>;
			};
		}

		template <typename List, unsigned N>
		using take = c::call<c::take<mpl::uint_<N>>, List>;
	}
}
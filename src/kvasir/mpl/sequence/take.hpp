//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "drop.hpp"
#include "../algorithm/rotate.hpp"
namespace kvasir {
	namespace mpl {

		template <typename N, typename C = listify>
		struct take {
			template <typename... Ts>
			using f = typename dcall<rotate<N, drop<uint_<(sizeof...(Ts)-N::value)>, C>>,
			                         sizeof...(Ts)>::template f<Ts...>;
		};

		namespace eager {
			template <typename List, unsigned N>
			using take = call<unpack<mpl::take<mpl::uint_<N>>>, List>;
		}
	} // namespace mpl
} // namespace kvasir
//          Copyright Odin Holmes 2017.
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once
#include "../algorithm/rotate.hpp"
#include "../functional/call.hpp"
#include "../sequence/push_front.hpp"
#include "../types/int.hpp"

namespace kvasir {
	namespace mpl {
		template <typename Index, typename Input, typename C = listify>
		struct insert {
			template <typename... Ts>
			using f = typename rotate<
			        Index, push_front<Input, rotate<uint_<(1 + sizeof...(Ts)-Index::value)>, C>>>::
			        template f<Ts...>;
		};

		namespace eager {
			template <typename List, unsigned Index, typename Input>
			using insert = call<unpack<insert<uint_<Index>, Input>>, List>;
		}
	} // namespace mpl
} // namespace kvasir

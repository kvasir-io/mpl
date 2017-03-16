//          Copyright Odin Holmes 2017.
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once
#include "rotate.hpp"
#include "../types/int.hpp"
#include "../sequence/push_front.hpp"
#include "../sequence/size.hpp"
#include "../functional/call.hpp"


namespace kvasir {
	namespace mpl {
		namespace c {
			namespace detail {
			}

		}

		template <typename List, typename Index, typename Input>
		using insert = c::call<c::rotate<mpl::int_<Index::value>, c::push_front<Input,c::rotate<mpl::int_<(size<List>::value - Index::value)>, c::listify>>>, List>;
	}
}

//          Copyright Odin Holmes 2017.
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once
#include "rotate.hpp"
#include "../types/int.hpp"
#include "../sequence/pop_front.hpp"
#include "../sequence/size.hpp"
#include "../functional/call.hpp"


namespace kvasir {
	namespace mpl {
		namespace c {
			namespace detail {
			}

			template<typename Index>
			struct erase {
				template<typename...Ts>
				using f = typename rotate < mpl::int_<Index::value>, pop_front<rotate<mpl::int_<(sizeof...(Ts)-Index::value-1)>, listify>>>::template f<Ts...>;
			};
		}

		template <typename List, unsigned Index>
		using erase = c::call<c::erase<int_<Index>>, List>;
	}
}

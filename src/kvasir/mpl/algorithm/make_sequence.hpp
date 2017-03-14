//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../types/int.hpp"
#include "../types/list.hpp"

namespace kvasir {
	namespace mpl {
		namespace detail {
			template<typename T, template<T> class W, template<typename...> class S, bool Continue = true>
			struct make_sequence {
				template<T N, typename...Ts>
				using f = typename make_sequence<T, W, S, (N > 0)>::template f<N - 1, W<N>, Ts...>;
			};
			template<typename T, template<T> class W, template<typename...> class S>
			struct make_sequence<T, W, S, false> {
				template<T N, typename...Ts>
				using f = S<Ts...>;
			};
		}
		template<typename T>
		using make_int_sequence = detail::make_sequence<long long, int_, list>::template f<T::value>;
	}
}
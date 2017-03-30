//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../algorithm/transform.hpp"
#include "../functional/call.hpp"
#include "../functional/identity.hpp"
#include "../sequence/join.hpp"
#include "../utility/conditional.hpp"

namespace kvasir {
	namespace mpl {
		namespace detail {
			template <typename F, typename Input>
			struct replace_if_pred {
				template <typename T>
				using f = typename conditional<F::template f<T>::value>::template f<Input, T>;
			};
			template <template <typename...> class F, typename Input>
			struct replace_if_pred<cfe<F, identity>, Input> {
				template <typename T>
				using f = typename conditional<F<T>::value>::template f<Input, T>;
			};
		}

		template <typename F, typename Input, typename C = listify>
		using replace_if = transform<detail::replace_if_pred<F, Input>, C>;

		namespace eager {
			template <typename List, typename Input, template <typename...> class Cond = identity>
			using replace_if = call<unpack<mpl::replace_if<cfe<Cond>, Input>>, List>;
		}
	}
}

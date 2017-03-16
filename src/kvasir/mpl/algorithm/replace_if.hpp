//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../functional/call.hpp"
#include "../functional/identity.hpp"
#include "../sequence/join.hpp"
#include "../utility/conditional.hpp"
#include "../algorithm/transform.hpp"

namespace kvasir {
	namespace mpl {
		namespace c {
			namespace detail {
				template<typename F, typename Input>
				struct replace_if_pred {
					template <typename T>
					using f = typename conditional<F::template f<T>::value>::template f<Input, T>;
				};
				template<template <typename...> class F, typename Input>
				struct replace_if_pred<lambda<F>,Input> {
					template <typename T>
					using f = typename conditional<F<T>::value>::template f<Input, T>;
				};
			}

			template <typename F, typename Input, typename C = listify>
			using replace_if = transform<detail::replace_if_pred<F,Input>, C>;
		}

		template <typename List, typename Input, template <typename...> class Cond = identity>
		using replace_if = c::call<c::replace_if<lambda<Cond>, Input>, List>;
	}
}

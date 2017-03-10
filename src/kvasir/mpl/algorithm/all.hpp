//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../algorithm/find_if.hpp"
#include "../functional/bind.hpp"
#include "../functional/call.hpp"
#include "../types/bool.hpp"
#include "../utility/identity.hpp"

namespace kvasir {
	namespace mpl {
		namespace c {
			namespace detail {
				struct nothing_found {
					template <typename... Ts>
					using f = bool_<(sizeof...(Ts) == 0)>;
				};
				template <typename F>
				struct not_ {
					template <typename T>
					using f = bool_<(!F::template f<T>::value)>;
				};
				template <template <typename...> class F>
				struct not_<lambda<F>> {
					template <typename T>
					using f = bool_<(!F<T>::value)>;
				};
			}

			template <typename F>
			using all = find_if<detail::not_<F>, detail::nothing_found>;
		}

		/// resolves to std::true_type if all elements in the input list
		/// fulfill the provided predicate
		template<typename List, template<typename...> class Cond = identity>
		using all = c::call<c::all<lambda<Cond>>, List>;
	}
}

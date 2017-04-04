//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../algorithm/find_if.hpp"
#include "../functional/bind.hpp"
#include "../functional/call.hpp"
#include "../functional/identity.hpp"
#include "../types/bool.hpp"

#if defined(KVASIR_CONSTEXPR_14)
#include <initializer_list>
namespace kvasir {
	namespace mpl {
		namespace detail {
			constexpr int and_(std::initializer_list<bool> l) {
				bool out = true;
				for (auto i : l) {
					out = out && i;
				}
				return out;
			}
		}
		template <typename F>
		struct all {
			template <typename... Ts>
			using f = bool_<detail::and_(
			        {static_cast<bool>(dcall<F, sizeof...(Ts)>::template f<Ts>::value)...})>;
		};
		template <template <typename...> class F>
		struct all<cfe<F, identity>> {
			template <typename... Ts>
			using f = bool_<detail::and_({static_cast<bool>(F<Ts>::value)...})>;
		};
#else
namespace kvasir {
	namespace mpl {
		namespace detail {
			template <typename C = identity>
			struct nothing_found {
				template <typename... Ts>
				using f = typename C::template f<bool_<(sizeof...(Ts) == 0)>>;
			};
			template <>
			struct nothing_found<identity> {
				template <typename... Ts>
				using f = bool_<(sizeof...(Ts) == 0)>;
			};
			template <typename F>
			struct not_ {
				template <typename T>
				using f = bool_<(!(F::template f<T>::value))>;
			};
			template <template <typename...> class F>
			struct not_<cfe<F, identity>> {
				template <typename T>
				using f = bool_<(!F<T>::value)>;
			};
		}

		template <typename F, typename C = identity>
		using all = find_if<detail::not_<F>, detail::nothing_found<>>;
#endif
		namespace eager {
			/// resolves to std::true_type if all elements in the input list
			/// fulfill the provided predicate
			template <typename List, template <typename...> class Cond = identity>
			using all = call<unpack<mpl::all<cfe<Cond>>>, List>;
		}
	}
}

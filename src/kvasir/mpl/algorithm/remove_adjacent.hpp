//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../compatability/dependent_call.hpp"
#include "remove_if.hpp"
#include "../utility/conditional.hpp"

namespace kvasir {
	namespace mpl {
		namespace detail {
			template <typename T>
			struct rotate_one_impl {
				using type = T;
			};
			template <template <typename...> class S, typename T, typename... Ts>
			struct rotate_one_impl<S<T, Ts...>> {
				using type = S<Ts..., T>;
			};

#if defined(KVASIR_MSVC_2017) || defined(KVASIR_MSVC_2015) || defined(KVASIR_MSVC_2013)
			template <template <typename...> class Pred, typename T, typename U>
			struct binary_list_if_not {
				using type = typename conditional<Pred<T, U>::value>::template f<list<>, list<T>>;
			};

			template <template <typename...> class Pred, typename T, typename U>
			struct remove_adjacent;
			template <template <typename...> class Pred, template <typename...> class S,
			          typename... Ts, typename... Us>
			struct remove_adjacent<Pred, S<Ts...>, S<Us...>> {
				using type = typename ::kvasir::mpl::c::detail::dependent_call<
				        c::join<lambda<S>>, ::kvasir::mpl::c::detail::always_true(sizeof...(Ts))>::
				        template f<typename binary_list_if_not<Pred, Ts, Us>::type...>;
			};
#else
			template <template <typename...> class Pred>
			struct binary_list_if_not {
				template <typename T, typename U>
				using f = typename conditional<Pred<T, U>::value>::template f<list<>, list<T>>;
			};

			template <template <typename...> class Pred, typename T, typename U>
			struct remove_adjacent;
			template <template <typename...> class Pred, template <typename...> class S,
			          typename... Ts, typename... Us>
			struct remove_adjacent<Pred, S<Ts...>, S<Us...>> {
				using type =
				        KVASIR_D_CALL(c::join<lambda<S>>,
				                      Ts)<typename binary_list_if_not<Pred>::template f<Ts, Us>...>;
			};
#endif
		}

		/// takes a boolean predicate with two parameters
		/// if the predicate return true for any two adjacent elements,
		/// then the first of the two elements is removed
		template <typename List, template <typename...> class Pred = std::is_same>
		using remove_adjacent = typename detail::remove_adjacent<
		        Pred, List, typename detail::rotate_one_impl<List>::type>::type;
	}
}

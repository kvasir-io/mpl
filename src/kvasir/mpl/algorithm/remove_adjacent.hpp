//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>

#include "remove_if.hpp"
#include "../algorithm/rotate.hpp"
#include "../compatability/dependent_call.hpp"
#include "../utility/conditional.hpp"

namespace kvasir {
	namespace mpl {
		namespace detail {
#if defined(KVASIR_MSVC_2017) || defined(KVASIR_MSVC_2015) || defined(KVASIR_MSVC_2013)
			template <template <typename...> class Pred, typename T, typename U>
			struct binary_list_if_not {
				using type = typename conditional<Pred<T, U>::value>::template f<list<>, list<T>>;
			};

			template <template <typename...> class Pred, typename T, typename U,
			          typename C = listify>
			struct remove_adjacent;
			template <template <typename...> class Pred, typename... Ts, typename... Us, typename C>
			struct remove_adjacent<Pred, list<Ts...>, list<Us...>, C> {
				using type = typename dcall<join<C>, sizeof...(Ts)>::template f<
				        typename binary_list_if_not<Pred, Ts, Us>::type...>;
			};
#else
			template <template <typename...> class Pred>
			struct binary_list_if_not {
				template <typename T, typename U>
				using f = typename conditional<Pred<T, U>::value>::template f<list<>, list<T>>;
			};

			template <template <typename...> class Pred, typename T, typename U,
			          typename C = listify>
			struct remove_adjacent;
			template <template <typename...> class Pred, typename... Ts, typename... Us, typename C>
			struct remove_adjacent<Pred, list<Ts...>, list<Us...>, C> {
				using type = typename dcall<join<C>, sizeof...(Ts)>::template f<
				        typename binary_list_if_not<Pred>::template f<Ts, Us>...>;
			};
#endif
		}
		/// \brief removes each element in a list which is the same type as the privious element
		template <typename F, typename C = listify>
		struct remove_adjacent {
			template <typename... Ts>
			using f = typename detail::remove_adjacent<
			        F::template f, list<Ts...>,
			        typename dcall<rotate<uint_<1>>, sizeof...(Ts)>::template f<Ts...>, C>::type;
		};
		/// \exclude
		template <template <typename... Ts> class F, typename C>
		struct remove_adjacent<cfe<F, identity>, C> {
			template <typename... Ts>
			using f = typename detail::remove_adjacent<
			        F, list<Ts...>,
			        typename dcall<rotate<uint_<1>>, sizeof...(Ts)>::template f<Ts...>, C>::type;
		};

		namespace eager {
			/// takes a boolean predicate with two parameters
			/// if the predicate return true for any two adjacent elements,
			/// then the first of the two elements is removed
			template <typename List, template <typename...> class Pred = std::is_same>
			using remove_adjacent = call<unpack<mpl::remove_adjacent<cfe<Pred>>>, List>;
		} // namespace eager
	} // namespace mpl
} // namespace kvasir

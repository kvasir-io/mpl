//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../compatability/dependent_call.hpp"
#include "../functional/bind.hpp"
#include "../functional/call.hpp"
#include "../types/list.hpp"

namespace kvasir {
	namespace mpl {
		/// \brief executes the continuation `F` on every element in the input pack passing the
		/// results to the continuation `C`
		template <typename F = identity, typename C = listify>
		struct transform {
			template <typename... Ts>
			using f = typename dcall<C, sizeof...(Ts)>::template f<typename F::template f<Ts>...>;
		};
		/// \exclude
		template <template <typename...> class F, typename C>
		struct transform<cfe<F, identity>, C> {
			template <typename... Ts>
			using f = typename dcall<C, sizeof...(Ts)>::template f<
			        typename dcallf<(sizeof...(Ts) < 100000)>::template f1<F, Ts>...>;
		};
		/// \exclude
		template <template <typename...> class F, template <typename...> class C>
		struct transform<cfe<F, identity>, cfe<C, identity>> {
			template <typename... Ts>
			using f = C<F<Ts>...>;
		};
		/// \exclude
		template <typename F, template <typename...> class C>
		struct transform<F, cfe<C, identity>> {
			template <typename... Ts>
			using f = typename dcallf<(sizeof...(Ts) <
			                           100000)>::template f1<C, typename F::template f<Ts>...>;
		};

		namespace eager {
			template <typename List, template <typename...> class F>
			using transform = call<unpack<mpl::transform<cfe<F>, listify>>, List>;
		}
	} // namespace mpl
} // namespace kvasir

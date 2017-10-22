//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "bind.hpp"
#include "identity.hpp"

namespace kvasir {
	namespace mpl {
		namespace eager {
			namespace impl {
				template <template <typename...> class F1, template <typename...> class F2>
				struct compose_impl {
					template <typename... Ts>
					using f = F2<F1<Ts...>>;
				};

				template <template <typename...> class F, template <typename...> class... Fs>
				struct compose_n_impl {
					template <template <typename...> class Result>
					using f =
					        typename compose_n_impl<Fs...>::template f<compose_impl<Result, F>::f>;
				};

				template <template <typename...> class F>
				struct compose_n_impl<F> {
					template <template <typename...> class Result>
					using f = compose_impl<Result, F>;
				};
			} // namespace impl

			template <template <typename...> class F, template <typename...> class... Fs>
			using compose = typename impl::compose_n_impl<Fs...>::template f<F>;
		} // namespace eager
	} // namespace mpl
} // namespace kvasir

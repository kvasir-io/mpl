#pragma once
#include "../compatability/dependent_call.hpp"
namespace kvasir {
	namespace mpl {
		namespace detail {
			template <bool B, typename T, typename U>
			struct if_impl;

			template <typename T, typename U>
			struct if_impl<true, T, U> : T {};

			template <typename T, typename U>
			struct if_impl<false, T, U> : U {};
		} // namespace detail

		template <typename P, typename TC, typename FC>
		struct if_ {
			template <typename... Ts>
			using f = typename detail::if_impl<dcall<P, sizeof...(Ts)>::template f<Ts...>::value,
			                                   TC, FC>::template f<Ts...>;
		};

	} // namespace mpl
} // namespace kvasir

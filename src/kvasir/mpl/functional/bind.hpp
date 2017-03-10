//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

namespace kvasir {
	namespace mpl {
		/// bind a function object to a type so that it can be returned or stored in a list
		/// this version of bind differs from normal implementations in that it does not take the
		/// parameters for it's execution in the initial call site, thus allowing the function to
		/// be either extracted from the type, or to be processed and used at a later stage.
		/// It is however possible to add parameters to the function before execution, so that
		/// they will be prepended to the function arguments when it is called.
		template <template <typename...> class Func, typename... Args>
		struct bind0n { // takes pack of 0-n elements
			template <typename... T>
			using f = Func<Args..., T...>;
		};
		template <template <typename...> class Func, typename... Args>
		struct bind1 {
			template <typename T>
			using f = Func<Args..., T>;
		};
		template <template <typename...> class Func, typename... Args>
		struct bind1n { // takes pack of 1-n elements
			template <typename T, typename... Ts>
			using f = Func<Args..., T, Ts...>;
		};
		template <template <typename...> class Func, typename... Args>
		struct bind2 {
			template <typename T, typename U>
			using f = Func<Args..., T, U>;
		};
		template <template <typename...> class Func, typename... Args>
		struct bind2n { // takes pack of 2-n elements
			template <typename T, typename U, typename... Ts>
			using f = Func<Args..., T, U, Ts...>;
		};
		template <template <typename...> class F>
		struct lambda {};
		namespace c {
			using mpl::bind0n;
			using mpl::bind1;
			using mpl::bind1n;
			using mpl::bind2;
			using mpl::bind2n;
			using mpl::lambda;
		}
	}
}

//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <utility>

#include "../types/list.hpp"
#include "../sequence/pop_front.hpp"
#include "../sequence/size.hpp"

namespace kvasir {
	namespace mpl {
		namespace impl {
			namespace generic {
				template <bool empty>
				struct fold_right;

				template <>
				struct fold_right<false> {
					template <template <typename...> class Func, typename State, typename List>
					using f = typename fold_right<(size_impl<List>{} == 1)>::template f<
					        Func, Func<State, typename pop_front_impl<List>::front>,
					        typename pop_front_impl<List>::rest>;
				};

				template <>
				struct fold_right<true> {
					template <template <typename...> class Func, typename State, typename List>
					using f = State;
				};
			}

			template <typename List>
			struct fold_right_impl {
				template <template <typename...> class Func, typename State>
				using f = typename generic::fold_right<(size_impl<List>{} == 0)>::template f<Func,
				                                                                             State>;
			};

#if __cpp_fold_expressions | __cplusplus >= 201406
			namespace list {
				template <template <typename...> class Func, typename T>
				struct folder {
					template <typename State>
					constexpr auto operator>>=(State &&) -> Func<State, T> {
						return {};
					}
				};
			}

			template <typename... Ts>
			struct fold_left_impl<mpl::list<Ts...>> {
				template <template <typename...> class Func, typename State>
				using f = decltype(folder<Func, Ts>{} >>= ... >>= std::declval<State>{});
			};
#endif
		}

		/// fold right over a list, initialized with State
		template <template <typename...> class Func, typename State, typename List>
		using fold_right = typename impl::fold_right_impl<List>::template f<Func, State>;
	}
}
//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "transform.hpp"
#include "../functional/bind.hpp"
#include "../types/nothing.hpp"
#include "../utility/always.hpp"

#include "../sequence/create.hpp"
#include "../sequence/pop_front.hpp"
#include "../sequence/push_front.hpp"
#include "../sequence/size.hpp"

namespace kvasir {
	namespace mpl {
		namespace c {

			template <typename F, typename C = listify>
			struct zip_with {
			}; // just a placeholder, has no ::template f, we must use specialization

			namespace detail {
				template <typename F, typename C, template <typename...> class Seq1, template <typename...> class Seq2, typename... L0s,
				          typename... L1s>
				struct call_impl<zip_with<F, C>, Seq1< Seq2<L0s...>, Seq2<L1s...>>> {
					using type = typename dcall<C,sizeof...(L0s)>::template f<
					        typename dcall<F,sizeof...(L0s)>::template f<L0s, L1s>...>;
				};
				template <typename F, typename C, template <typename...> class Seq1, template <typename...> class Seq2, typename... L0s,
				          typename... L1s, typename... L2s>
				struct call_impl<zip_with<F, C>, Seq1<Seq2<L0s...>, Seq2<L1s...>, Seq2<L2s...>>> {
					using type = typename C::template f<
					        typename dcall<F, sizeof...(L0s)>::template f<L0s, L1s, L2s>...>;
				};
				template <typename F, typename C, template <typename...> class Seq1, template <typename...> class Seq2, typename... L0s,
				          typename... L1s, typename... L2s, typename... L3s>
				struct call_impl<zip_with<F, C>, Seq1<Seq2<L0s...>, Seq2<L1s...>, Seq2<L2s...>,
				                 Seq2<L3s...>>> {
					using type = typename C::template f<
					        typename dcall<F, sizeof...(L0s)>::template f<L0s, L1s, L2s, L3s>...>;
				};
			}
		}
		namespace impl {
			namespace generic {
				template <bool empty>
				struct zip_with;

				template <>
				struct zip_with<false> {
					template <template <typename...> class F, typename Result, typename List,
					          typename... Lists>
					using f = typename push_front_impl<
					        F<typename pop_front_impl<List>::front,
					          typename pop_front_impl<Lists>::front...>,
					        typename zip_with<(
					                size<typename pop_front_impl<List>::rest>::value ==
					                0)>::template f<F, Result, typename pop_front_impl<List>::rest,
					                                typename pop_front_impl<Lists>::rest...>>::f;
				};

				template <>
				struct zip_with<true> {
					template <template <typename...> class F, typename Result, typename... Lists>
					using f = Result;
				};
			}

			template <template <typename...> class F, typename... Lists>
			struct zip_with {
				// no lists case; return nothing
				using f = nothing;
			};

			template <template <typename...> class F, typename List, typename... Lists>
			struct zip_with<F, List, Lists...> {
				using f = typename generic::zip_with<(size<List>::value == 0)>::template f<
				        F, typename create_impl<List>::f, List, Lists...>;
			};

			/// mpl::list optimization for only two lists
			template <template <typename...> class F, typename... Ts1, typename... Ts2>
			struct zip_with<F, mpl::list<Ts1...>, mpl::list<Ts2...>> {
				using f = mpl::list<F<Ts1, Ts2>...>;
			};
		}

		template <template <typename...> class Func, typename... Lists>
		using zip_with = typename impl::zip_with<Func, Lists...>::f;
	}
}

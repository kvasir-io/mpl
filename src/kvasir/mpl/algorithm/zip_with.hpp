//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "transform.hpp"
#include "../functional/bind.hpp"
#include "../functional/call.hpp"
#include "../types/list.hpp"
#include "../types/nothing.hpp"
#include "../utility/always.hpp"

#include "../sequence/pop_front.hpp"
#include "../sequence/push_front.hpp"
#include "../sequence/size.hpp"
#include "../sequence/drop.hpp"

namespace kvasir {
	namespace mpl {
		namespace detail {
			template <typename>
			struct append;
			template <template <typename...> class Seq, typename... Ts0>
			struct append<Seq<Ts0...>> {
				template <typename... Ts1>
				using f = Seq<Ts0..., Ts1...>;
			};

			template <typename F, typename C, typename Result, typename... Ts>
			struct zip_with_impl {
				using f = call<unpack<transform<unpack<F>, C>>, Result>;
			};
			template <typename F, typename C, template <typename...> class Seq, typename... Result,
			          template <typename...> class Seq0, typename... Ts0, typename... Ts>
			struct zip_with_impl<F, C, Seq<Result...>, Seq0<Ts0...>, Ts...> {
				using f = typename zip_with_impl<
				        F, C, list<typename append<Result>::template f<Ts0>...>, Ts...>::f;
			};
			template <typename F, typename C, template <typename...> class Seq, typename... Result,
			          template <typename...> class Seq0, typename... Ts0,
			          template <typename...> class Seq1, typename... Ts1, typename... Ts>
			struct zip_with_impl<F, C, Seq<Result...>, Seq0<Ts0...>, Seq1<Ts1...>, Ts...> {
				using f = typename zip_with_impl<
				        F, C, list<typename append<Result>::template f<Ts0, Ts1>...>, Ts...>::f;
			};
			template <typename F, typename C, template <typename...> class Seq, typename... Result,
			          template <typename...> class Seq0, typename... Ts0,
			          template <typename...> class Seq1, typename... Ts1,
			          template <typename...> class Seq2, typename... Ts2,
			          template <typename...> class Seq3, typename... Ts3, typename... Ts>
			struct zip_with_impl<F, C, Seq<Result...>, Seq0<Ts0...>, Seq1<Ts1...>, Seq2<Ts2...>,
			                     Seq3<Ts3...>, Ts...> {
				using f = typename zip_with_impl<
				        F, C, list<typename append<Result>::template f<Ts0, Ts1, Ts2, Ts3>...>,
				        Ts...>::f;
			};
			template <typename F, typename C, template <typename...> class Seq, typename... Result,
			          template <typename...> class Seq0, typename... Ts0,
			          template <typename...> class Seq1, typename... Ts1,
			          template <typename...> class Seq2, typename... Ts2,
			          template <typename...> class Seq3, typename... Ts3,
			          template <typename...> class Seq4, typename... Ts4,
			          template <typename...> class Seq5, typename... Ts5,
			          template <typename...> class Seq6, typename... Ts6,
			          template <typename...> class Seq7, typename... Ts7, typename... Ts>
			struct zip_with_impl<F, C, Seq<Result...>, Seq0<Ts0...>, Seq1<Ts1...>, Seq2<Ts2...>,
			                     Seq3<Ts3...>, Seq4<Ts4...>, Seq5<Ts5...>, Seq6<Ts6...>,
			                     Seq7<Ts7...>, Ts...> {
				using f = typename zip_with_impl<
				        F, C, list<typename append<Result>::template f<Ts0, Ts1, Ts2, Ts3>...>,
				        Ts...>::f;
			};

			template <typename F, typename C, typename... Ts>
			struct zip_with_unpack {
				// in the case of no lists just call c
				using f = typename C::template f<>;
			};
			template <typename F, typename C, typename T, typename... Ts>
			struct zip_with_unpack<F, C, T, Ts...> {
				using f =
				        typename zip_with_impl<F, C, call<unpack<transform<listify>>, T>, Ts...>::f;
			};
		} // namespace detail

		/// \brief n-ary version of transform
		template <typename F = listify, typename C = listify>
		struct zip_with {
			template <typename... Ts>
			using f = typename detail::zip_with_unpack<F, C, Ts...>::f;
		};
		
		template<typename F, typename...Ls>
		struct zip_fixed{
			private:
			using fixed_size = uint_<(sizeof...(Ls)-1)>;
			using C = typename drop<fixed_size>::template f<Ls...>;
			public:
			template<typename...Ts>
			using f = typename rotate<uint_<sizeof...(Ls)>,pop_front<zip_with<F,C>>>::template f<list<Ts...>,Ls...>;
		};

		template<typename F, template<typename...> class L, typename...Ls, typename C>
		struct zip_fixed<F,L<Ls...>,C>{
			template<typename...Ts>
			using f = typename dcall<C,sizeof...(Ts)>::template f<typename dcall<F, sizeof...(Ts)>::template f<Ts,Ls>...>;
		};

		template<typename F, template<typename...> class L1, template<typename...> class L2,
			typename...L1s, typename...L2s, typename C>
		struct zip_fixed<F,L1<L1s...>,L2<L2s...>,C>{
			template<typename...Ts>
			using f = typename dcall<C,sizeof...(Ts)>::template f<typename dcall<F, sizeof...(Ts)>::template f<Ts,L1s,L2s>...>;
		};

		namespace eager {
			template <template <typename...> class Func, typename... Lists>
			using zip_with = call<zip_with<cfe<Func>>, Lists...>;
		}
	} // namespace mpl
} // namespace kvasir

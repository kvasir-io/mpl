//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../functional/call.hpp"
#include "../types/int.hpp"
#include "../types/list.hpp"

namespace kvasir {
	namespace mpl {
		namespace detail {
			// has to be a seperate function as cfe does not accept non-type template parameters
			struct make_uint {
				template <typename N>
				using f = uint_<N::value>;
			};

			template <typename L1, typename L2>
			struct seq_join;

			template <typename... Ls1, typename... Ls2>
			struct seq_join<list<Ls1...>, list<Ls2...>> {
				using type = list<Ls1..., Ls2...>;
			};

			template <typename F, unsigned min, unsigned max>
			struct make_part_int_seq {
				using type = typename seq_join<
				        typename make_part_int_seq<F, min, min + (max - min) / 2>::type,
				        typename make_part_int_seq<F, min + (max - min) / 2 + 1, max>::type>::type;
			};

			template <typename F, unsigned n>
			struct make_part_int_seq<F, n, n> {
				using type = list<call<F, uint_<n>>>;
			};

			template <unsigned n>
			struct make_part_int_seq<identity, n, n> {
				using type = list<uint_<n>>;
			};

			template <unsigned n, typename F>
			struct make_int_seq_impl {
				using type = typename make_part_int_seq<F, 0, n - 1>::type;
			};

			template <typename F>
			struct make_int_seq_impl<0, F> {
				using type = list<>;
			};
		}

		template <typename F = identity, typename C = listify>
		struct make_int_sequence {
			template <typename N>
			using f = call<unpack<C>, typename detail::make_int_seq_impl<N::value, F>::type>;
		};

		template <typename F>
		struct make_int_sequence<F, listify> {
			template <typename N>
			using f = typename detail::make_int_seq_impl<N::value, F>::type;
		};

		namespace eager {
			template <typename N>
			using make_int_sequence = call<make_int_sequence<>, N>;
		}
	}
}

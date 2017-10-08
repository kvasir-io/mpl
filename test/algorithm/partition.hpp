//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <limits>
#include <type_traits>

#include <metacheck.hpp>

namespace partition {
	namespace mpl = kvasir::mpl;

	template <bool...>
	struct bool_list {};

	template <typename... Ts1>
	struct ordered_impl {
		template <typename... Ts2>
		using f = std::is_same<bool_list<true, (Ts1::value < Ts2::value)...>,
		                       bool_list<(Ts1::value < Ts2::value)..., true>>;
	};

	template <typename...>
	struct ordered {
		using type = mpl::bool_<true>;
	};

	template <typename T, typename... Ts>
	struct ordered<T, Ts...> {
		using type = typename ordered_impl<T, Ts...>::template f<
		        Ts..., mpl::uint_<std::numeric_limits<unsigned>::max()>>;
	};

	template <typename L>
	using ordering =
	        mpl::call<mpl::fork<mpl::unpack<mpl::size<mpl::make_int_sequence<>>>, mpl::identity,
	                            mpl::zip_with<mpl::listify,
	                                          mpl::partition<mpl::unpack<mpl::at1<>>,
	                                                         mpl::all<mpl::unpack<mpl::transform<
	                                                                 mpl::unpack<mpl::at0<>>,
	                                                                 mpl::cfl<ordered>>>>>>>,
	                  L>;

	constexpr auto ordering_test = mc::test<ordering, 20, mc::gen::list_of<mc::gen::bool_>>;

	template <typename L>
	using same_size =
	        mpl::call<mpl::unpack<mpl::fork<mpl::partition<mpl::identity, mpl::join<mpl::size<>>>,
	                                        mpl::size<>, mpl::equal<>>>,
	                  L>;

	constexpr auto same_size_test = mc::test<same_size, 20, mc::gen::list_of<mc::gen::bool_>>;
}

constexpr auto partition_section = mc::section("partition", partition::ordering_test,
                                               partition::same_size_test);

//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>

#include <metacheck/metacheck.hpp>

namespace sort {
	namespace mpl = kvasir::mpl;

	template <bool...>
	struct bool_list {};

	template <typename... Ts1>
	struct ordered_impl {
		template <typename... Ts2>
		using f = std::is_same<bool_list<true, (Ts1::value <= Ts2::value)...>,
		                       bool_list<(Ts1::value <= Ts2::value)..., true>>;
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
	using order = mpl::call<mpl::unpack<mpl::sort<mpl::eager::less_than, mpl::cfl<ordered>>>, L>;

	constexpr auto order_test = mc::test<order, 20, mc::gen::list_of<mc::gen::uint_<>>>;
} // namespace sort

constexpr auto sort_section_t = mc::section("sort", sort::order_test);
extern mc::result *sort_section;

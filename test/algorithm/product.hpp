//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <kvasir/mpl/algorithm/product.hpp>

#include <type_traits>

#include <kvasir/mpl/functional/call.hpp>
#include <kvasir/mpl/types/list.hpp>

namespace product_test {
	namespace mpl = kvasir::mpl;

	template <typename...>
	struct foo_list {};
	struct foo_listify {
		template <typename... Ts>
		using f = foo_list<Ts...>;
	};
	template <typename...>
	struct bar_list {};
	struct bar_listify {
		template <typename... Ts>
		using f = bar_list<Ts...>;
	};

	static_assert(std::is_same<mpl::call<mpl::product<foo_listify, bar_listify>,
	                                     mpl::list<void, char>, mpl::list<void, char>>,
	                           bar_list<foo_list<void, void>, foo_list<void, char>,
	                                    foo_list<char, void>, foo_list<char, char>>>::value,
	              "");
}

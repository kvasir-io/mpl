//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>

#include <metacheck.hpp>

namespace product {
	namespace mpl = kvasir::mpl;

	template <typename...>
	struct foo_list {};
	struct foo_listify {
		template <typename... Ts>
		using f = foo_list<Ts...>;
	};

	template <typename Ls>
	using size = mpl::call<
	        mpl::unpack<mpl::fork<
	                mpl::product<mpl::listify, mpl::size<>>,
	                mpl::transform<mpl::unpack<mpl::size<>>,
	                               mpl::push_front<mpl::uint_<1>, mpl::fold_left<mpl::times<>>>>,
	                mpl::cfe<mc::mpl::equal>>>,
	        Ls>;

	constexpr auto size_test =
	        mc::test<size, 20,
	                 mc::gen::list_of<mc::gen::list_of<mc::gen::anything, mc::gen::uint_<16>>,
	                                  mc::gen::uint_<4>>>;
} // namespace product

constexpr auto product_section_t = mc::section("product", product::size_test);
extern mc::detail::section_base *product_section;

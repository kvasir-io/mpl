//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>

#include <kvasir/mpl/algorithm/find_if.hpp>
#include <kvasir/mpl/functional/bind.hpp>
#include <kvasir/mpl/utility/is_same.hpp>

#include <metacheck.hpp>

namespace find_if {
	namespace mpl = kvasir::mpl;

	template <typename N, typename ListSize>
	using uint_seq = mc::mpl::equal<
	        mpl::eager::min<N, ListSize>,
	        mpl::eager::minus<
	                ListSize,
	                mpl::call<mpl::make_int_sequence<mpl::identity,
	                                                 mpl::find_if<mpl::same_as<N>, mpl::size<>>>,
	                          ListSize>>>;

	constexpr auto uint_seq_test = mc::test<uint_seq, 20, mc::gen::uint_<>, mc::gen::uint_<>>;

	template <typename L1, typename L2>
	using distributive = mc::prop::distributive<
	        mpl::unpack<mpl::find_if<mpl::identity, mpl::front<>,
	                                 mpl::always<mpl::bool_<true>>>>::template f,
	        mpl::eager::join,
	        mpl::find_if<mpl::identity, mpl::front<>, mpl::always<mpl::bool_<true>>>::template f,
	        L1, L2>;

	constexpr auto distributive_test = mc::test<distributive, 20, mc::gen::list_of<mc::gen::bool_>,
	                                            mc::gen::list_of<mc::gen::bool_>>;
}

constexpr auto find_if_section =
        mc::section("find_if", find_if::uint_seq_test, find_if::distributive_test);

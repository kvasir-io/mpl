//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <metacheck/metacheck.hpp>

namespace split_if {
	namespace mpl = kvasir::mpl;
	template <typename T>
	using is_0 = mpl::bool_<T::value == 0>;

	template <typename L1, typename L2>
	using distributive = mc::prop::distributive<
	        mpl::unpack<mpl::split_if<mpl::cfe<is_0>>>::template f, mpl::eager::join,
	        mpl::fork<
	                mpl::at0<mpl::unpack<mpl::fork_front<
	                        mpl::size<mpl::push_back<
	                                mpl::uint_<1>,
	                                mpl::minus<mpl::fork<
	                                        mpl::cfe<mpl::take>,
	                                        mpl::push_back<mpl::identity, mpl::cfe<mpl::drop>>,
	                                        mpl::always<mpl::listify>, mpl::cfe<mpl::fork>>>>>,
	                        mpl::call_f<>>>>,
	                mpl::at1<mpl::unpack<mpl::fork<mpl::pop_front<>, mpl::front<>, mpl::listify>>>,
	                mpl::fork<mpl::at0<mpl::unpack<mpl::at0<mpl::identity>>>,
	                          mpl::transform<mpl::unpack<mpl::at1<mpl::identity>>,
	                                         mpl::join<mpl::cfe<mpl::list, mpl::listify>>>,
	                          mpl::at1<mpl::unpack<mpl::at0<mpl::identity>>>,
	                          mpl::join<>>>::template f,
	        L1, L2>;

	constexpr auto distributive_test =
	        mc::test<distributive, 20, mc::gen::list_of<mc::gen::uint_<>, mc::gen::uint_<128>>,
	                 mc::gen::list_of<mc::gen::uint_<>, mc::gen::uint_<128>>>;
} // namespace split_if

constexpr auto split_if_section_t = mc::section("split_if", split_if::distributive_test);
extern mc::result *split_if_section;

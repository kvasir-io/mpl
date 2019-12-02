//          Copyright Odin Holmes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>

#include <kvasir/mpl/algorithm/make_sequence.hpp>
#include <kvasir/mpl/types/list.hpp>

#include <metacheck/metacheck.hpp>

namespace make_sequence {
	namespace mpl = kvasir::mpl;

	// series of tests to prove correctness by induction

	// the total size of the list must be N
	template <typename N>
	using equal_size =
	        mc::mpl::equal<mpl::call<mpl::make_int_sequence<mpl::identity, mpl::size<>>, N>, N>;

	constexpr auto equal_size_test = mc::test<equal_size, 20, mc::gen::uint_<>>;

	// the first element must always be zero on non-zero length lists
	template <typename N>
	using front_zero = mc::mpl::equal<mpl::call<mpl::make_int_sequence<mpl::identity, mpl::front<>>,
	                                            mpl::uint_<N::value + 1>>,
	                                  mpl::uint_<0>>;

	constexpr auto front_zero_test = mc::test<front_zero, 20, mc::gen::uint_<>>;

	// all subsequent elements must be incremental
	template <typename N>
	using incremental = mpl::call<
	        mpl::fork<mpl::push_front<mpl::uint_<1>, mpl::plus<mpl::make_int_sequence<
	                                                         mpl::identity, mpl::pop_front<>>>>,
	                  mpl::make_int_sequence<>,
	                  mpl::zip_with<mpl::minus<mpl::push_front<mpl::uint_<1>, mpl::equal<>>>,
	                                mpl::all<mpl::identity>>>,
	        mpl::uint_<N::value + 1>>;

	constexpr auto incremental_test = mc::test<incremental, 20, mc::gen::uint_<>>;
} // namespace make_sequence

constexpr auto make_sequence_section_t =
        mc::section("make_sequence", make_sequence::equal_size_test, make_sequence::front_zero_test,
                    make_sequence::incremental_test);
extern mc::result *make_sequence_section;

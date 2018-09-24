//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>
#include <kvasir/mpl/algorithm/make_sequence.hpp>
#include <kvasir/mpl/sequence/lookup.hpp>

#include <metacheck.hpp>

namespace lookup {
	namespace mpl = kvasir::mpl;

	template <typename N, typename Size>
	using uint_seq = mc::mpl::equal<
	        mpl::eager::lookup<mpl::call<mpl::make_int_sequence<>, mpl::uint_<Size::value + 1>>,
	                           N::value % (Size::value + 1)>,
	        // looking up over the list size is UB
	        // therefor looking up on empty lists is always UB
	        mpl::uint_<N::value % (Size::value + 1)>>;

	constexpr auto uint_seq_test = mc::test<uint_seq, 20, mc::gen::uint_<>, mc::gen::uint_<>>;
} // namespace lookup

constexpr auto lookup_section_t = mc::section("lookup", lookup::uint_seq_test);
extern mc::detail::section_base *lookup_section;

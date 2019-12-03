//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <kvasir/mpl/algorithm/rotate.hpp>
#include <kvasir/mpl/sequence/drop.hpp>
#include <kvasir/mpl/sequence/join.hpp>
#include <kvasir/mpl/sequence/make_sequence.hpp>

namespace {
	struct rotate_test {
		template <int n>
		void rotate_test_impl() {
			using namespace kvasir::mpl;
			constexpr int len = 522;
			using seq         = eager::make_int_sequence<int_<len>>;
			using left_seq    = eager::make_int_sequence<int_<n>>;
			using right_seq   = eager::drop<seq, n>;
			eager::join<right_seq, left_seq>{} = eager::rotate<seq, n>{};
		}

		rotate_test() {
			rotate_test_impl<0>();
			rotate_test_impl<1>();
			rotate_test_impl<2>();
			rotate_test_impl<3>();
			rotate_test_impl<4>();
			rotate_test_impl<5>();
			rotate_test_impl<6>();
			rotate_test_impl<7>();
			rotate_test_impl<8>();
			rotate_test_impl<9>();
			rotate_test_impl<15>();
			rotate_test_impl<16>();
			rotate_test_impl<17>();
			rotate_test_impl<31>();
			rotate_test_impl<32>();
			rotate_test_impl<33>();
			rotate_test_impl<63>();
			rotate_test_impl<64>();
			rotate_test_impl<65>();
			rotate_test_impl<127>();
			rotate_test_impl<128>();
			rotate_test_impl<129>();
			rotate_test_impl<255>();
			rotate_test_impl<256>();
			rotate_test_impl<257>();
			rotate_test_impl<511>();
			rotate_test_impl<512>();
			rotate_test_impl<513>();
		}
	};
}

//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <kvasir/mpl/algorithm/transform.hpp>
#include <kvasir/mpl/sequence/join.hpp>
#include <kvasir/mpl/sequence/make_sequence.hpp>

namespace {
	struct join_test {
		template <int n>
		void join_test_impl() {
			using namespace kvasir::mpl;
			using seq = call<make_int_sequence<>, int_<n>>;
			seq{}     = call<unpack<transform<listify, join<>>>, seq>{};
		}

		join_test() {
			join_test_impl<0>();
			join_test_impl<1>();
			join_test_impl<2>();
			join_test_impl<3>();
			join_test_impl<4>();
			join_test_impl<5>();
			join_test_impl<6>();
			join_test_impl<7>();
			join_test_impl<8>();
			join_test_impl<9>();
			join_test_impl<15>();
			join_test_impl<16>();
			join_test_impl<17>();
			join_test_impl<31>();
			join_test_impl<32>();
			join_test_impl<33>();
			join_test_impl<63>();
			join_test_impl<64>();
			join_test_impl<65>();
			join_test_impl<127>();
			join_test_impl<128>();
			join_test_impl<129>();
			join_test_impl<255>();
			join_test_impl<256>();
			join_test_impl<257>();
			join_test_impl<527>();
			join_test_impl<528>();
			join_test_impl<529>();
			join_test_impl<1023>();
			join_test_impl<1024>();
			join_test_impl<1025>();
		}
	};
}

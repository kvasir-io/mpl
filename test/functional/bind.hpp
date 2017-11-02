//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <kvasir/mpl/functional/bind.hpp>
#include <kvasir/mpl/algorithm/transform.hpp>
#include <kvasir/mpl/types/traits.hpp>
#include <tuple>
namespace {
	struct bind_test {
		template<typename T>
		using add_const_t = const T;
		bind_test() {
			using namespace kvasir;
			using namespace mpl;

			call<transform<cfe<add_const_t>>, int, char, bool>{} = list<const int, const char, const bool>{};
			call<transform<cfe1<add_const_t>>, int, char, bool>{} = list<const int, const char, const bool>{};
			call<transform<add_volatile<>,cfe2<std::tuple>>, char, int>{} = std::tuple<volatile char, volatile int>{};
		}
	};

}

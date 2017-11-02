//          Copyright Odin Holmes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <tuple>
#include <type_traits>

#include <kvasir/mpl/algorithm/index_if.hpp>
#include <kvasir/mpl/types/bool.hpp>
#include <kvasir/mpl/types/int.hpp>

namespace {
	using namespace kvasir::mpl;
	template <typename T>
	using less_than_5 = bool_<(T::value < 5)>;
	struct index_if_test {
		index_if_test() {
			call<detail::index_if<cfe<less_than_5>>, int_<9>, int_<2>, int_<1>, int_<8>>{} =
			        list<uint_<1>, uint_<2>>{};
			call<detail::index_if<cfe<less_than_5>>, int_<9>, int_<2>, int_<7>, int_<8>>{} =
			        list<uint_<1>>{};
			call<detail::index_if<cfe<less_than_5>>>{} = list<>{};
			call<detail::index_if<cfe<less_than_5>, cfe<std::tuple>>, int_<1>, int_<2>, int_<7>,
			     int_<8>>{}                    = std::tuple<uint_<0>, uint_<1>>{};
		}
	};
} // namespace

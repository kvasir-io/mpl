//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>

#include <tuple>
#include <kvasir/mpl/algorithm/flatten.hpp>
#include <kvasir/mpl/functional/call.hpp>
#include <kvasir/mpl/types/list.hpp>
namespace {
	using namespace kvasir::mpl;
	list<> t1 = call<flatten<>, list<list<list<>, list<>>, list<>>, list<>>{};
	list<> t2 =
	        call<flatten<cfe<std::tuple>>, std::tuple<std::tuple<>, std::tuple<>>, std::tuple<>>{};
	std::tuple<> t3 = call<flatten<cfe<std::tuple>, cfe<std::tuple>>,
	                       std::tuple<std::tuple<>, std::tuple<>>, std::tuple<>>{};
	list<int, bool> t4 = call<flatten<>, list<int, bool>>{};
	std::tuple<int, bool> t5 =
	        call<flatten<cfe<std::tuple>, cfe<std::tuple>>, std::tuple<int, bool>>{};
	std::tuple<int, bool> t6 = call<flatten<cfe<list>, cfe<std::tuple>>, list<int, list<bool>>>{};
}

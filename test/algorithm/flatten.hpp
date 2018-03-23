//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>

#include <kvasir/mpl/algorithm/flatten.hpp>
#include <kvasir/mpl/functional/call.hpp>
#include <kvasir/mpl/types/list.hpp>

namespace {
	using namespace kvasir::mpl;
	list<> t1 = call<flatten<>, list<list<list<>, list<>>, list<>>, list<>>{};
	
	template<typename...>
	struct foo_list {
	};
	list<> t2 =
	        call<flatten<cfe<foo_list>>, foo_list<foo_list<>, foo_list<>>, foo_list<>>{};
	foo_list<> t3 = call<flatten<cfe<foo_list>, cfe<foo_list>>,
	                       foo_list<foo_list<>, foo_list<>>, foo_list<>>{};
	list<int, bool> t4 = call<flatten<>, list<int, bool>>{};
	foo_list<int, bool> t5 =
	        call<flatten<cfe<foo_list>, cfe<foo_list>>, foo_list<int, bool>>{};
	foo_list<int, bool> t6 = call<flatten<cfe<list>, cfe<foo_list>>, list<int, list<bool>>>{};
}

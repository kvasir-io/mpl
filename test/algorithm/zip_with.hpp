//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <kvasir/mpl/algorithm/zip_with.hpp>
#include <kvasir/mpl/functional/bind.hpp>

namespace {
	using namespace kvasir;
	using namespace mpl;

	struct zip_with_test {
		zip_with_test() {
			using zip_a        = mpl::list<void, char, short, int>;
			using zip_b        = mpl::list<int, void, char, short>;
			using zip_shoud_be = mpl::list<mpl::list<void, int>, mpl::list<char, void>,
			                               mpl::list<short, char>, mpl::list<int, short>>;
			call<zip_with<cfe<mpl::list>>, zip_a, zip_b>{}   = zip_shoud_be{};
			call<zip_with<cfe<mpl::list>>, list<>, list<>>{} = list<>{};
		}
	};

	struct zip_fix_test {
		zip_fix_test() {
			using zip_a        = mpl::list<void, char, short, int>;
			using zip_b        = mpl::list<int, void, char, short>;
			using zip_shoud_be = mpl::list<mpl::list<void, int>, mpl::list<char, void>,
			                               mpl::list<short, char>, mpl::list<int, short>>;
			call<unpack<zip_fixed<cfe<mpl::list>, zip_a, cfe<list>>>, zip_b>{} = zip_shoud_be{};
			call<zip_fixed<cfe<mpl::list>, list<>, cfe<list>>>{}               = list<>{};
		}
	};
} // namespace

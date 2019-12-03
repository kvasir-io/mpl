//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <kvasir/mpl/functional/call.hpp>
#include <kvasir/mpl/types/bool.hpp>
#include <kvasir/mpl/utility/always.hpp>

namespace {
	namespace mpl = kvasir::mpl;

	struct always_test {
		always_test() {
			mpl::call<mpl::always<mpl::bool_<false>>, void>{} = mpl::bool_<false>{};
		}
	};

	template <typename T>
	struct foo {
		static_assert(mpl::eager::always_false<T>::value,
		              "always_false should not have been instantiated");
	};
}

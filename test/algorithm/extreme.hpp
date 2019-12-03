//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <kvasir/mpl/mpl.hpp>

namespace {
	namespace mpl      = kvasir::mpl;
	using extreme_pred = mpl::if_<mpl::greater_than<>, mpl::at0<>, mpl::at1<>>;

	struct extreme_test {
		extreme_test() {
			mpl::call<mpl::extreme<extreme_pred>, mpl::uint_<0>, mpl::uint_<5>, mpl::uint_<4>,
			          mpl::uint_<4>>{} = mpl::uint_<5>{};
		}
	};
}

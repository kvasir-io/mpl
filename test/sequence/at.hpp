//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <kvasir/mpl/sequence/at.hpp>

#include <type_traits>

#include <kvasir/mpl/types/list.hpp>

namespace {
	namespace mpl = kvasir::mpl;

	static_assert(std::is_same<mpl::eager::at<mpl::list<void, char, short>, 1>, char>::value, "");
	static_assert(
	        std::is_same<
	                mpl::eager::at<mpl::list<int, int, int, int, int, int, int, void, char, short>,
	                               7>,
	                void>::value,
	        "");
	static_assert(
	        std::is_same<
	                mpl::eager::at<mpl::list<int, int, int, int, int, int, int, void, char, short>,
	                               8>,
	                char>::value,
	        "");
	static_assert(
	        std::is_same<
	                mpl::eager::at<mpl::list<int, int, int, int, int, int, int, void, char, short>,
	                               9>,
	                short>::value,
	        "");
	static_assert(
	        std::is_same<mpl::eager::at<mpl::list<int, int, int, int, int, int, int, int, int, int,
	                                              int, int, int, int, int, int, void, char, short>,
	                                    17>,
	                     char>::value,
	        "");
}

//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

namespace kvasir {
	namespace mpl {
		/// class used when a function errors, as in the haskell nothing
		/// all functions that take nothing as a parameter should return nothing
		struct nothing {};
	} // namespace mpl
} // namespace kvasir

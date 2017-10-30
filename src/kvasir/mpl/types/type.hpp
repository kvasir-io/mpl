//          Copyright Odin Holmes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once
#include "nothing.hpp"
namespace kvasir {
	namespace mpl {
		/// \brief type wrapper for types/
		template<typename T>
		struct type_ {
			using type = T;
		};
		
	} // namespace mpl
} // namespace kvasir

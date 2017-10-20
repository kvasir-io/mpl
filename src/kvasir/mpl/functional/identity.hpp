//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

namespace kvasir {
	namespace mpl {
		/// \brief results in the dynamic input. Use to break recursive chains or forward args /
		/// identity is one of the core concepts of cmpl. It is used as the default continuation and
		/// when reached it breaks the chain as it has not continuation it self. it also comes in
		/// handy as a place holder in each if one only wants to modify some of the arguments. It is
		/// also used as a default predicate in algorithms like all where a predicate may be
		/// unneeded.
		struct identity {
			template <typename T>
			using f = T;
		};
		namespace eager {
			template <typename T>
			using identity = T;
		}
	} // namespace mpl
} // namespace kvasir

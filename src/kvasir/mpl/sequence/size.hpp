//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "../functional/call.hpp"
#include "../functional/identity.hpp"
#include "../types/int.hpp"
#include "../types/list.hpp"

namespace kvasir {
	namespace mpl {
		template <typename C = identity>
		struct size {
			template <typename... Ts>
			using f = typename C::template f<uint_<sizeof...(Ts)>>;
		};
		template <>
		struct size<identity> {
			template <typename... Ts>
			using f = uint_<sizeof...(Ts)>;
		};

		/// offset provides the difference between the origional length of a list
		///(provided as the input parameter) and the pack supplied to f
		template <typename T, typename C = identity>
		struct offset {
			template <typename... Ts>
			using f = typename C::template f<uint_<(T::value - sizeof...(Ts))>>;
		};
		template <typename T>
		struct offset<T, identity> {
			template <typename... Ts>
			using f = uint_<(T::value - sizeof...(Ts))>;
		};
		namespace eager {
			/// get the size of a list, the returned type is convertible to some unspecified int
			/// type
			template <typename List>
			using size = call<unpack<mpl::size<>>, List>;
		} // namespace eager
	} // namespace mpl
} // namespace kvasir

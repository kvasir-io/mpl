//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>

#include <kvasir/mpl/algorithm/fold_right.hpp>
#include <kvasir/mpl/functional/bind.hpp>
#include <kvasir/mpl/functions/arithmetic/plus.hpp>
#include <kvasir/mpl/types/int.hpp>
#include <kvasir/mpl/types/list.hpp>

namespace {
	using namespace kvasir::mpl;

	template <typename T1, typename T2>
	using add = uint_<(T1::value + T2::value)>;

	template <typename T, typename U>
	struct push;
	template <typename... Ts, typename U>
	struct push<list<Ts...>, U> {
		using type = list<U, Ts...>;
	};

	template <typename C, typename T>
	struct fold_right_foo {
		template <typename... Ts>
		using f = call<C, Ts..., T>;
	};

	template <typename T>
	struct fold_right_cont_test {
		template <typename... Ts>
		using f = typename dcall<fold_right<cfe<add>>, sizeof...(Ts)>::template f<uint_<1>, Ts...>;
	};

	struct fold_right_test {

		fold_right_test() {
			eager::fold_right<list<uint_<1>, uint_<2>, uint_<3>, uint_<4>>, uint_<0>, add>{} =
			        uint_<10>{};

			call<fold_right<cfl<push>>, list<>, uint_<1>, uint_<2>>{} = list<uint_<1>, uint_<2>>{};
			call<fold_right<cfl<push>>, list<>, uint_<1>, uint_<2>, uint_<3>>{} =
			        list<uint_<1>, uint_<2>, uint_<3>>{};
			call<fold_right<cfl<push>>, list<>, uint_<1>, uint_<2>, uint_<3>, uint_<4>>{} =
			        list<uint_<1>, uint_<2>, uint_<3>, uint_<4>>{};
			call<fold_right<cfl<push>>, list<>, uint_<1>, uint_<2>, uint_<3>, uint_<4>,
			     uint_<5>>{} = list<uint_<1>, uint_<2>, uint_<3>, uint_<4>, uint_<5>>{};
			call<fold_right<cfl<push>>, list<>, uint_<1>, uint_<2>, uint_<3>, uint_<4>, uint_<5>,
			     uint_<6>>{} = list<uint_<1>, uint_<2>, uint_<3>, uint_<4>, uint_<5>, uint_<6>>{};
			call<fold_right<cfl<push>>, list<>, uint_<1>, uint_<2>, uint_<3>, uint_<4>, uint_<5>,
			     uint_<6>, uint_<7>>{} =
			        list<uint_<1>, uint_<2>, uint_<3>, uint_<4>, uint_<5>, uint_<6>, uint_<7>>{};

			call<call<fold_right<cfe<fold_right_foo>>, listify, char, short, int>, void>{} =
			        list<void, char, short, int>{};
		}
	};
}

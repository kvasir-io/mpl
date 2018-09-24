//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>

#include <metacheck.hpp>

namespace stable_sort {
	namespace mpl = kvasir::mpl;

	template <bool...>
	struct bool_list {};

	template <bool... Bs>
	using bool_list_check = std::is_same<bool_list<true, Bs...>, bool_list<Bs..., true>>;

	template <typename Elem, typename Seq>
	struct sort_elem {
		using T1 = Elem;
		using T2 = Seq;
	};

	template <typename... Ts1>
	struct ordered_stable_check {
		template <typename... Ts2>
		struct f : bool_list_check<((Ts1::T1::value <= Ts2::T1::value) &&
		                            ((Ts1::T2::value < Ts2::T2::value) ||
		                             !(Ts1::T1::value == Ts2::T1::value)))...> {};
	};

	template <typename...>
	struct ordered_stable_impl {
		using type = mpl::bool_<true>;
	};

	template <typename T, typename... Ts>
	struct ordered_stable_impl<T, Ts...> {
		using type = typename ordered_stable_check<T, Ts...>::template f<
		        Ts..., sort_elem<mpl::uint_<std::numeric_limits<unsigned>::max()>,
		                         mpl::uint_<std::numeric_limits<unsigned>::max()>>>;
	};

	template <typename L>
	using ordered_stable = mpl::call<
	        mpl::fork<mpl::identity, mpl::unpack<mpl::size<mpl::make_int_sequence<>>>,
	                  mpl::zip_with<mpl::cfe<sort_elem>,
	                                mpl::stable_sort<mpl::transform<mpl::unpack<mpl::at0<>>,
	                                                                mpl::less_than<>>::template f,
	                                                 mpl::cfl<ordered_stable_impl>>>>,
	        L>;

	constexpr auto ordered_stable_test =
	        mc::test<ordered_stable, 20, mc::gen::list_of<mc::gen::uint_<16>>>;
} // namespace stable_sort

constexpr auto stable_sort_section_t = mc::section("stable_sort", stable_sort::ordered_stable_test);
extern mc::detail::section_base *stable_sort_section;

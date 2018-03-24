//          Copyright Odin Holmes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>
#include "bool.hpp"
#include "../compatability/compatability.hpp"
#include "../functional/identity.hpp"

namespace kvasir {
	namespace mpl {
		/// \brief tests if a type is void
		/// \effects results in true_ if dynamic input is void
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_void except the return is true_ or false_ and
		/// may be faster/
		template <typename C = identity>
		struct is_void {
			template <typename T>
			using f = typename C::template f<bool_<std::is_void<T>::value>>;
		};
		/// \brief tests if a type is an integral type
		/// \effects results in true_ if dynamic input is an integral type
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_integral except the return is true_ or false_
		/// and may be faster/
		template <typename C = identity>
		struct is_integral {
			template <typename T>
			using f = typename C::template f<bool_<std::is_integral<T>::value>>;
		};
		/// \brief tests if a type is a floating point type
		/// \effects results in true_ if dynamic input is a floating point type
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_floating_point except the return is true_ or
		/// false_ and may be faster/
		template <typename C = identity>
		struct is_floating_point {
			template <typename T>
			using f = typename C::template f<bool_<std::is_floating_point<T>::value>>;
		};
		/// \brief tests if a type is an array
		/// \effects results in true_ if dynamic input is an array
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_array except the return is true_ or false_ and
		/// may be faster/
		template <typename C = identity>
		struct is_array {
			template <typename T>
			using f = typename C::template f<bool_<std::is_array<T>::value>>;
		};
		/// \brief tests if a type is an enum
		/// \effects results in true_ if dynamic input is an enum
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_enum except the return is true_ or false_ and
		/// may be faster/
		template <typename C = identity>
		struct is_enum {
			template <typename T>
			using f = typename C::template f<bool_<std::is_enum<T>::value>>;
		};
		/// \brief tests if a type is a union
		/// \effects results in true_ if dynamic input is a union
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_union except the return is true_ or false_ and
		/// may be faster/
		template <typename C = identity>
		struct is_union {
			template <typename T>
			using f = typename C::template f<bool_<std::is_union<T>::value>>;
		};
		/// \brief tests if a type is a class
		/// \effects results in true_ if dynamic input is a class
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_class except the return is true_ or false_ and
		/// may be faster/
		template <typename C = identity>
		struct is_class {
			template <typename T>
			using f = typename C::template f<bool_<std::is_class<T>::value>>;
		};
		/// \brief tests if a type is a function
		/// \effects results in true_ if dynamic input is a function
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_funtion except the return is true_ or false_
		/// and may be faster/
		template <typename C = identity>
		struct is_function {
			template <typename T>
			using f = typename C::template f<bool_<std::is_function<T>::value>>;
		};
		/// \brief tests if a type is a pointer
		/// \effects results in true_ if dynamic input is a pointer
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_pointer except the return is true_ or false_
		/// and may be faster/
		template <typename C = identity>
		struct is_pointer {
			template <typename T>
			using f = typename C::template f<bool_<std::is_pointer<T>::value>>;
		};
		/// \brief tests if a type is an lvalue reference
		/// \effects results in true_ if dynamic input is an lvalue reference
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_lvalue_reference except the return is true_ or
		/// false_ and may be faster/
		template <typename C = identity>
		struct is_lvalue_reference {
			template <typename T>
			using f = typename C::template f<bool_<std::is_lvalue_reference<T>::value>>;
		};
		/// \brief tests if a type is an rvalue reference
		/// \effects results in true_ if dynamic input is an rvalue reference
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_rvalue_reference except the return is true_ or
		/// false_ and may be faster/
		template <typename C = identity>
		struct is_rvalue_reference {
			template <typename T>
			using f = typename C::template f<bool_<std::is_rvalue_reference<T>::value>>;
		};
		template <typename C = identity>
		struct is_member_object_pointer {
			template <typename T>
			using f = typename C::template f<bool_<std::is_member_object_pointer<T>::value>>;
		};
		template <typename C = identity>
		struct is_member_function_pointer {
			template <typename T>
			using f = typename C::template f<bool_<std::is_member_function_pointer<T>::value>>;
		};
		template <typename C = identity>
		struct is_fundamental {
			template <typename T>
			using f = typename C::template f<bool_<std::is_fundamental<T>::value>>;
		};
		template <typename C = identity>
		struct is_arithmetic {
			template <typename T>
			using f = typename C::template f<bool_<std::is_arithmetic<T>::value>>;
		};
		template <typename C = identity>
		struct is_scalar {
			template <typename T>
			using f = typename C::template f<bool_<std::is_scalar<T>::value>>;
		};
		template <typename C = identity>
		struct is_object {
			template <typename T>
			using f = typename C::template f<bool_<std::is_object<T>::value>>;
		};
		template <typename C = identity>
		struct is_compound {
			template <typename T>
			using f = typename C::template f<bool_<std::is_compound<T>::value>>;
		};
		template <typename C = identity>
		struct is_reference {
			template <typename T>
			using f = typename C::template f<bool_<std::is_reference<T>::value>>;
		};
		template <typename C = identity>
		struct is_member_pointer {
			template <typename T>
			using f = typename C::template f<bool_<std::is_member_pointer<T>::value>>;
		};
		template <typename C = identity>
		struct is_volatile {
			template <typename T>
			using f = typename C::template f<bool_<std::is_const<T>::value>>;
		};
		template <typename C = identity>
		struct is_trivial {
			template <typename T>
			using f = typename C::template f<bool_<std::is_trivial<T>::value>>;
		};
#if (__has_feature(is_trivially_copyable) && defined(_LIBCPP_VERSION)) || \
        (defined(__GNUC__) && __GNUC__ >= 5)
		template <typename C = identity>
		struct is_trivially_copyable {
			template <typename T>
			using f = typename C::template f<bool_<std::is_trivially_copyable<T>::value>>;
		};
#endif
		template <typename C = identity>
		struct is_standard_layout {
			template <typename T>
			using f = typename C::template f<bool_<std::is_standard_layout<T>::value>>;
		};
		template <typename C = identity>
		struct is_pod {
			template <typename T>
			using f = typename C::template f<bool_<std::is_pod<T>::value>>;
		};
		template <typename C = identity>
		struct is_literal_type {
			template <typename T>
			using f = typename C::template f<bool_<std::is_literal_type<T>::value>>;
		};
		template <typename C = identity>
		struct is_empty {
			template <typename T>
			using f = typename C::template f<bool_<std::is_empty<T>::value>>;
		};
		template <typename C = identity>
		struct is_polymorphic {
			template <typename T>
			using f = typename C::template f<bool_<std::is_polymorphic<T>::value>>;
		};
		template <typename C = identity>
		struct is_abstract {
			template <typename T>
			using f = typename C::template f<bool_<std::is_abstract<T>::value>>;
		};
		template <typename C = identity>
		struct is_signed {
			template <typename T>
			using f = typename C::template f<bool_<std::is_signed<T>::value>>;
		};
		template <typename C = identity>
		struct is_unsigned {
			template <typename T>
			using f = typename C::template f<bool_<std::is_unsigned<T>::value>>;
		};
		template <typename C = identity>
		struct is_constructible {
			template <typename T>
			using f = typename C::template f<bool_<std::is_constructible<T>::value>>;
		};
#if (__has_feature(is_trivially_constructible) && defined(_LIBCPP_VERSION)) || \
        (defined(__GNUC__) && __GNUC__ >= 5)
		template <typename C = identity>
		struct is_trivially_constructible {
			template <typename T>
			using f = typename C::template f<bool_<std::is_trivially_constructible<T>::value>>;
		};
#endif
		template <typename C = identity>
		struct is_nothrow_constructible {
			template <typename T>
			using f = typename C::template f<bool_<std::is_nothrow_constructible<T>::value>>;
		};
		template <typename C = identity>
		struct is_default_constructible {
			template <typename T>
			using f = typename C::template f<bool_<std::is_default_constructible<T>::value>>;
		};
#if (__has_feature(is_trivially_default_constructible) && defined(_LIBCPP_VERSION)) || \
        (defined(__GNUC__) && __GNUC__ >= 5)
		template <typename C = identity>
		struct is_trivially_default_constructible {
			template <typename T>
			using f = typename C::template f<
			        bool_<std::is_trivially_default_constructible<T>::value>>;
		};
#endif
		template <typename C = identity>
		struct is_nothrow_default_constructible {
			template <typename T>
			using f =
			        typename C::template f<bool_<std::is_nothrow_default_constructible<T>::value>>;
		};
		template <typename C = identity>
		struct is_copy_constructible {
			template <typename T>
			using f = typename C::template f<bool_<std::is_copy_constructible<T>::value>>;
		};
#if (__has_feature(is_trivially_copy_constructible) && defined(_LIBCPP_VERSION)) || \
        (defined(__GNUC__) && __GNUC__ >= 5)
		template <typename C = identity>
		struct is_trivially_copy_constructible {
			template <typename T>
			using f = typename C::template f<bool_<std::is_trivially_copy_constructible<T>::value>>;
		};
#endif
		template <typename C = identity>
		struct is_nothrow_copy_constructible {
			template <typename T>
			using f = typename C::template f<bool_<std::is_nothrow_copy_constructible<T>::value>>;
		};
		template <typename C = identity>
		struct is_move_constructible {
			template <typename T>
			using f = typename C::template f<bool_<std::is_move_constructible<T>::value>>;
		};
#if (__has_feature(is_trivially_move_constructible) && defined(_LIBCPP_VERSION)) || \
        (defined(__GNUC__) && __GNUC__ >= 5)
		template <typename C = identity>
		struct is_trivially_move_constructible {
			template <typename T>
			using f = typename C::template f<bool_<std::is_trivially_move_constructible<T>::value>>;
		};
#endif
		template <typename C = identity>
		struct is_nothrow_move_constructible {
			template <typename T>
			using f = typename C::template f<bool_<std::is_nothrow_move_constructible<T>::value>>;
		};
		template <typename C = identity>
		struct is_assignable {
			template <typename T, typename U>
			using f = typename C::template f<bool_<std::is_assignable<T, U>::value>>;
		};
#if (__has_feature(is_trivially_assignable) && defined(_LIBCPP_VERSION)) || \
        (defined(__GNUC__) && __GNUC__ >= 5)
		template <typename C = identity>
		struct is_trivially_assignable {
			template <typename T, typename U>
			using f = typename C::template f<bool_<std::is_trivially_assignable<T, U>::value>>;
		};
#endif
		template <typename C = identity>
		struct is_nothrow_assignable {
			template <typename T, typename U>
			using f = typename C::template f<bool_<std::is_nothrow_assignable<T, U>::value>>;
		};
		template <typename C = identity>
		struct is_copy_assignable {
			template <typename T>
			using f = typename C::template f<bool_<std::is_copy_assignable<T>::value>>;
		};
#if (__has_feature(is_trivially_copy_assignable) && defined(_LIBCPP_VERSION)) || \
        (defined(__GNUC__) && __GNUC__ >= 5)
		template <typename C = identity>
		struct is_trivially_copy_assignable {
			template <typename T>
			using f = typename C::template f<bool_<std::is_trivially_copy_assignable<T>::value>>;
		};
#endif
		template <typename C = identity>
		struct is_nothrow_copy_assignable {
			template <typename T>
			using f = typename C::template f<bool_<std::is_nothrow_copy_assignable<T>::value>>;
		};
		template <typename C = identity>
		struct is_move_assignable {
			template <typename T>
			using f = typename C::template f<bool_<std::is_move_assignable<T>::value>>;
		};
#if (__has_feature(is_trivially_move_assignable) && defined(_LIBCPP_VERSION)) || \
        (defined(__GNUC__) && __GNUC__ >= 5)
		template <typename C = identity>
		struct is_trivially_move_assignable {
			template <typename T>
			using f = typename C::template f<bool_<std::is_trivially_move_assignable<T>::value>>;
		};
#endif
		template <typename C = identity>
		struct is_nothrow_move_assignable {
			template <typename T>
			using f = typename C::template f<bool_<std::is_nothrow_move_assignable<T>::value>>;
		};
		template <typename C = identity>
		struct is_destructible {
			template <typename T>
			using f = typename C::template f<bool_<std::is_destructible<T>::value>>;
		};
#if (__has_feature(is_trivially_destructible))
		template <typename C = identity>
		struct is_trivially_destructible {
			template <typename T>
			using f = typename C::template f<bool_<std::is_trivially_destructible<T>::value>>;
		};
#endif
#if (__has_feature(is_nothrow_destructible))
		template <typename C = identity>
		struct is_nothrow_destructible {
			template <typename T>
			using f = typename C::template f<bool_<std::is_nothrow_destructible<T>::value>>;
		};
#endif
		template <typename C = identity>
		struct has_virtual_destructor {
			template <typename T>
			using f = typename C::template f<bool_<std::has_virtual_destructor<T>::value>>;
		};

		template <typename C = identity>
		struct is_same {
			template <typename T, typename U>
			using f = typename C::template f<bool_<std::is_same<T, U>::value>>;
		};
		template <typename C = identity>
		struct is_base_of {
			template <typename T, typename U>
			using f = typename C::template f<bool_<std::is_base_of<T, U>::value>>;
		};
		template <typename C = identity>
		struct is_convertible {
			template <typename T, typename U>
			using f = typename C::template f<bool_<std::is_convertible<T, U>::value>>;
		};

		template <typename C = identity>
		struct alignment_of {
			template <typename T>
			using f = typename C::template f<typename std::alignment_of<T>::type>;
		};
		template <typename C = identity>
		struct rank {
			template <typename T>
			using f = typename C::template f<typename std::rank<T>::type>;
		};
		template <typename C = identity>
		struct extent {
			template <typename T>
			using f = typename C::template f<typename std::extent<T>::type>;
		};
		template <typename C = identity>
		struct remove_cv {
			template <typename T>
			using f = typename C::template f<typename std::remove_cv<T>::type>;
		};
		template <typename C = identity>
		struct remove_const {
			template <typename T>
			using f = typename C::template f<typename std::remove_const<T>::type>;
		};
		template <typename C = identity>
		struct remove_volatile {
			template <typename T>
			using f = typename C::template f<typename std::remove_volatile<T>::type>;
		};
		template <typename C = identity>
		struct add_cv {
			template <typename T>
			using f = typename C::template f<typename std::add_cv<T>::type>;
		};
		template <typename C = identity>
		struct add_const {
			template <typename T>
			using f = typename C::template f<typename std::add_const<T>::type>;
		};
		template <typename C = identity>
		struct add_volatile {
			template <typename T>
			using f = typename C::template f<typename std::add_volatile<T>::type>;
		};
		template <typename C = identity>
		struct remove_reference {
			template <typename T>
			using f = typename C::template f<typename std::remove_reference<T>::type>;
		};
		template <typename C = identity>
		struct add_lvalue_reference {
			template <typename T>
			using f = typename C::template f<typename std::add_lvalue_reference<T>::type>;
		};
		template <typename C = identity>
		struct add_rvalue_reference {
			template <typename T>
			using f = typename C::template f<typename std::add_rvalue_reference<T>::type>;
		};
		template <typename C = identity>
		struct remove_pointer {
			template <typename T>
			using f = typename C::template f<typename std::remove_pointer<T>::type>;
		};
		template <typename C = identity>
		struct add_pointer {
			template <typename T>
			using f = typename C::template f<typename std::add_pointer<T>::type>;
		};
		template <typename C = identity>
		struct make_signed {
			template <typename T>
			using f = typename C::template f<typename std::make_signed<T>::type>;
		};
		template <typename C = identity>
		struct make_unsigned {
			template <typename T>
			using f = typename C::template f<typename std::make_unsigned<T>::type>;
		};
		template <typename C = identity>
		struct remove_extent {
			template <typename T>
			using f = typename C::template f<typename std::remove_extent<T>::type>;
		};
		template <typename C = identity>
		struct remove_all_extents {
			template <typename T>
			using f = typename C::template f<typename std::remove_all_extents<T>::type>;
		};
		template <typename C = identity>
		struct decay {
			template <typename T>
			using f = typename C::template f<typename std::decay<T>::type>;
		};
		template <typename C = identity>
		struct common_type {
			template <typename T>
			using f = typename C::template f<typename std::alignment_of<T>::type>;
		};
		template <typename C = identity>
		struct underlying_type {
			template <typename T>
			using f = typename C::template f<typename std::alignment_of<T>::type>;
		};
#if __cplusplus >= 201402L
#ifdef __cpp_lib_is_null_pointer
		template <typename C = identity>
		struct is_null_pointer {
			template <typename T>
			using f = typename C::template f<bool_<std::is_null_pointer<T>::value>>;
		};
		template <>
		struct is_null_pointer<identity> {
			template <typename T>
			using f = bool_<std::is_null_pointer<T>::value>;
		};
#endif
#ifdef __cpp_lib_is_final
		template <typename C = identity>
		struct is_final {
			template <typename T>
			using f = typename C::template f<bool_<__is_final(T)>>;
		};
		/// \exclude
		template <>
		struct is_final<identity> {
			template <typename T>
			using f = bool_<__is_final(T)>;
		};
#endif
#endif
	} // namespace mpl
} // namespace kvasir

//          Copyright Odin Holmes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once
#include <type_traits>
#include <utility> //for std::swap
#include "bool.hpp"
#include "int.hpp"
#include "../compatability/compatability.hpp"
#include "../functional/identity.hpp"

namespace kvasir {
	namespace mpl {
		namespace detail {
			namespace swap_test {
				using std::swap;
				template <typename, typename, bool>
				false_ test(...);

				template <typename T, typename U,
				          bool SwappableOnly> // if SwappableOnly we return true_ as long as we do
				                              // not SFINAE
				bool_<((noexcept(swap(std::declval<T &>(), std::declval<U &>())) &&
				        noexcept(swap(std::declval<U &>(), std::declval<T &>()))) ||
				       SwappableOnly)>
				test(int);
			} // namespace swap_test
		} // namespace detail
		  /// \brief tests if a type is swappable with another type /
		  /// \effects results in true_ if dynamic input types are swappable with each other
		  /// \requires fixed parameters: optional continuation, dynamic parameters: two types to be
		  /// tested \notes this is the same as std::is_swappable_with except the return is true_ or
		  /// false_ and may be faster/
		template <typename C = identity>
		struct is_swappable_with {
			template <typename T, typename U>
			using f = typename C::template f<decltype(detail::swap_test::test<T, U, true>(0))>;
		};

		/// \brief tests if a type is swappable
		/// \effects results in true_ if dynamic input is a swappable type
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_swappable except the return is true_ or false_
		/// and may be faster/
		template <typename C = identity>
		struct is_swappable {
			template <typename T>
			using f = typename C::template f<decltype(detail::swap_test::test<T, T, true>(0))>;
		};

		/// \brief tests if two types are nothrow swappable
		/// \effects results in true_ if dynamic input types are nothrow swappable
		/// \requires fixed parameters: optional continuation, dynamic parameters: the types to be
		/// tested \notes this is the same as std::is_swappable_with except the return is true_ or
		/// false_ and may be faster/
		template <typename C = identity>
		struct is_nothrow_swappable_with {
			template <typename T, typename U>
			using f = typename C::template f<decltype(detail::swap_test::test<T, U, false>(0))>;
		};

		/// \brief tests if a type is nothrow swappable
		/// \effects results in true_ if dynamic input is nothrow spwappable
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_nothrow_swappable except the return is true_
		/// or false_ and may be faster/
		template <typename C = identity>
		struct is_nothrow_swappable {
			template <typename T>
			using f = typename C::template f<decltype(detail::swap_test::test<T, T, false>(0))>;
		};
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
		/// \brief tests if a type is a member object pointer
		/// \effects results in true_ if dynamic input is a member object pointer
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_member_object_pointer except the return is
		/// `true_` or `false_` and may be faster/

		template <typename C = identity>
		struct is_member_object_pointer {
			template <typename T>
			using f = typename C::template f<bool_<std::is_member_object_pointer<T>::value>>;
		};
		/// \brief tests if a type is a member function pointer
		/// \effects results in true_ if dynamic input is a member function pointer
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_member_function_pointer except the return is
		/// `true_` or `false_` and may be faster/

		template <typename C = identity>
		struct is_member_function_pointer {
			template <typename T>
			using f = typename C::template f<bool_<std::is_member_function_pointer<T>::value>>;
		};
		/// \brief tests if a type is functional
		/// \effects results in true_ if dynamic input is functional
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_functional except the return is `true_` or
		/// `false_` and may be faster/

		template <typename C = identity>
		struct is_fundamental {
			template <typename T>
			using f = typename C::template f<bool_<std::is_fundamental<T>::value>>;
		};
		/// \brief tests if a type is an arithmatic type
		/// \effects results in true_ if dynamic input is an arithmatic type
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_arithmatic except the return is true_ or
		/// false_ and may be faster/

		template <typename C = identity>
		struct is_arithmetic {
			template <typename T>
			using f = typename C::template f<bool_<std::is_arithmetic<T>::value>>;
		};
		/// \brief tests if a type is a scalar
		/// \effects results in true_ if dynamic input is a scalar
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_scalar except the return is true_ or false_
		/// and may be faster/

		template <typename C = identity>
		struct is_scalar {
			template <typename T>
			using f = typename C::template f<bool_<std::is_scalar<T>::value>>;
		};
		/// \brief tests if a type is an object
		/// \effects results in true_ if dynamic input is an object
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_object except the return is true_ or false_
		/// and may be faster/

		template <typename C = identity>
		struct is_object {
			template <typename T>
			using f = typename C::template f<bool_<std::is_object<T>::value>>;
		};
		/// \brief tests if a type is compound
		/// \effects results in true_ if dynamic input is compound
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_compound except the return is true_ or false_
		/// and may be faster/

		template <typename C = identity>
		struct is_compound {
			template <typename T>
			using f = typename C::template f<bool_<std::is_compound<T>::value>>;
		};
		/// \brief tests if a type is a reference
		/// \effects results in true_ if dynamic input is a reference
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_reference except the return is true_ or false_
		/// and may be faster/

		template <typename C = identity>
		struct is_reference {
			template <typename T>
			using f = typename C::template f<bool_<std::is_reference<T>::value>>;
		};
		/// \brief tests if a type is a member pointer
		/// \effects results in true_ if dynamic input is a member pointer
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_member_pointer except the return is true_ or
		/// false_ and may be faster/

		template <typename C = identity>
		struct is_member_pointer {
			template <typename T>
			using f = typename C::template f<bool_<std::is_member_pointer<T>::value>>;
		};
		/// \brief tests if a type is volatile
		/// \effects results in true_ if dynamic input is volatile
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_volatile except the return is true_ or false_
		/// and may be faster/

		template <typename C = identity>
		struct is_volatile {
			template <typename T>
			using f = typename C::template f<bool_<std::is_const<T>::value>>;
		};
		/// \brief tests if a type is trivial
		/// \effects results in true_ if dynamic input is trivial
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_trivial except the return is true_ or false_
		/// and may be faster/

		template <typename C = identity>
		struct is_trivial {
			template <typename T>
			using f = typename C::template f<bool_<std::is_trivial<T>::value>>;
		};
#if (__has_feature(is_trivially_copyable) && defined(_LIBCPP_VERSION)) || \
        (defined(__GNUC__) && __GNUC__ >= 5)
		/// \brief tests if a type is trivially copyable
		/// \effects results in true_ if dynamic input is trivially copyable
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_trivially_copyable except the return is true_
		/// or false_ and may be faster/

		template <typename C = identity>
		struct is_trivially_copyable {
			template <typename T>
			using f = typename C::template f<bool_<std::is_trivially_copyable<T>::value>>;
		};
#endif
		/// \brief tests if a type is standard layout
		/// \effects results in true_ if dynamic input is standard layout
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_standard_layout except the return is true_ or
		/// false_ and may be faster/

		template <typename C = identity>
		struct is_standard_layout {
			template <typename T>
			using f = typename C::template f<bool_<std::is_standard_layout<T>::value>>;
		};
		/// \brief tests if a type is a pod
		/// \effects results in true_ if dynamic input is a pod
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_pod except the return is true_ or false_ and
		/// may be faster/

		template <typename C = identity>
		struct is_pod {
			template <typename T>
			using f = typename C::template f<bool_<std::is_pod<T>::value>>;
		};
		/// \brief tests if a type is a literal type
		/// \effects results in true_ if dynamic input is a literal type
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_literal_type except the return is true_ or
		/// false_ and may be faster/

		template <typename C = identity>
		struct is_literal_type {
			template <typename T>
			using f = typename C::template f<bool_<std::is_literal_type<T>::value>>;
		};
		/// \brief tests if a type is empty
		/// \effects results in true_ if dynamic input is empty
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_empty except the return is true_ or false_ and
		/// may be faster/

		template <typename C = identity>
		struct is_empty {
			template <typename T>
			using f = typename C::template f<bool_<std::is_empty<T>::value>>;
		};
		/// \brief tests if a type is polymorphic
		/// \effects results in `true_` if dynamic input is polymorphic
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_polymorphic except the return is `true_` or
		/// `false_` and may be faster/

		template <typename C = identity>
		struct is_polymorphic {
			template <typename T>
			using f = typename C::template f<bool_<std::is_polymorphic<T>::value>>;
		};
		/// \brief tests if a type is abstract
		/// \effects results in `true_` if dynamic input is abstract
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_abstract except the return is `true_` or
		/// `false_` and may be faster/
		template <typename C = identity>
		struct is_abstract {
			template <typename T>
			using f = typename C::template f<bool_<std::is_abstract<T>::value>>;
		};
		/// \brief tests if a type is signed
		/// \effects results in `true_` if dynamic input is signed
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_signed except the return is `true_` or
		/// `false_` and may be faster/
		template <typename C = identity>
		struct is_signed {
			template <typename T>
			using f = typename C::template f<bool_<std::is_signed<T>::value>>;
		};
		/// \brief tests if a type is unsigned
		/// \effects results in `true_` if dynamic input is unsigned
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_unsigned except the return is `true_` or
		/// `false_` and may be faster/
		template <typename C = identity>
		struct is_unsigned {
			template <typename T>
			using f = typename C::template f<bool_<std::is_unsigned<T>::value>>;
		};
		/// \brief tests if a type is constructible
		/// \effects results in `true_` if dynamic input is constructible
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_constructible except the return is `true_` or
		/// `false_` and may be faster/
		template <typename C = identity>
		struct is_constructible {
			template <typename T>
			using f = typename C::template f<bool_<std::is_constructible<T>::value>>;
		};
#if (__has_feature(is_trivially_constructible) && defined(_LIBCPP_VERSION)) || \
        (defined(__GNUC__) && __GNUC__ >= 5)
		/// \brief tests if a type is trivially constructible
		/// \effects results in `true_` if dynamic input is trivially constructible
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_trivially_constructible except the return is
		/// `true_` or `false_` and may be faster/
		template <typename C = identity>
		struct is_trivially_constructible {
			template <typename T>
			using f = typename C::template f<bool_<std::is_trivially_constructible<T>::value>>;
		};
#endif
		/// \brief tests if a type is nothrow constructible
		/// \effects results in `true_` if dynamic input is nothrow constructible
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_nothrow_constructible except the return is
		/// `true_` or `false_` and may be faster/
		template <typename C = identity>
		struct is_nothrow_constructible {
			template <typename T>
			using f = typename C::template f<bool_<std::is_nothrow_constructible<T>::value>>;
		};
		/// \brief tests if a type is default constructible
		/// \effects results in `true_` if dynamic input is default constructible
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_default_constructible except the return is
		/// `true_` or `false_` and may be faster/
		template <typename C = identity>
		struct is_default_constructible {
			template <typename T>
			using f = typename C::template f<bool_<std::is_default_constructible<T>::value>>;
		};
#if (__has_feature(is_trivially_default_constructible) && defined(_LIBCPP_VERSION)) || \
        (defined(__GNUC__) && __GNUC__ >= 5)
		/// \brief tests if a type is trivially default constructible
		/// \effects results in `true_` if dynamic input is trivially default constructible
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_trivially_default_constructible except the
		/// return is `true_` or `false_` and may be faster/
		template <typename C = identity>
		struct is_trivially_default_constructible {
			template <typename T>
			using f = typename C::template f<
			        bool_<std::is_trivially_default_constructible<T>::value>>;
		};
#endif
		/// \brief tests if a type is nothrow default constructible
		/// \effects results in `true_` if dynamic input is nothrow default constructible
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_nothrow_default_constructible except the
		/// return is `true_` or `false_` and may be faster/
		template <typename C = identity>
		struct is_nothrow_default_constructible {
			template <typename T>
			using f =
			        typename C::template f<bool_<std::is_nothrow_default_constructible<T>::value>>;
		};
		/// \brief tests if a type is copy constructible
		/// \effects results in `true_` if dynamic input is copy constructible
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_copy_constructible except the return is
		/// `true_` or `false_` and may be faster/
		template <typename C = identity>
		struct is_copy_constructible {
			template <typename T>
			using f = typename C::template f<bool_<std::is_copy_constructible<T>::value>>;
		};
#if (__has_feature(is_trivially_copy_constructible) && defined(_LIBCPP_VERSION)) || \
        (defined(__GNUC__) && __GNUC__ >= 5)
		/// \brief tests if a type is trivially copy constructible
		/// \effects results in `true_` if dynamic input is trivially copy constructible
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_trivially_copy_constructible except the return
		/// is `true_` or `false_` and may be faster/
		template <typename C = identity>
		struct is_trivially_copy_constructible {
			template <typename T>
			using f = typename C::template f<bool_<std::is_trivially_copy_constructible<T>::value>>;
		};
#endif
		/// \brief tests if a type is nothrow copy constructible
		/// \effects results in `true_` if dynamic input is nothrow copy constructible
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_nothrow_copy_constructible except the return
		/// is `true_` or `false_` and may be faster/
		template <typename C = identity>
		struct is_nothrow_copy_constructible {
			template <typename T>
			using f = typename C::template f<bool_<std::is_nothrow_copy_constructible<T>::value>>;
		};
		/// \brief tests if a type is move constructible
		/// \effects results in `true_` if dynamic input is move constructible
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_move_constructible except the return is
		/// `true_` or `false_` and may be faster/
		template <typename C = identity>
		struct is_move_constructible {
			template <typename T>
			using f = typename C::template f<bool_<std::is_move_constructible<T>::value>>;
		};
#if (__has_feature(is_trivially_move_constructible) && defined(_LIBCPP_VERSION)) || \
        (defined(__GNUC__) && __GNUC__ >= 5)
		/// \brief tests if a type is trivially move constructible
		/// \effects results in `true_` if dynamic input is trivially move constructible
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_trivially_move_constructible except the return
		/// is `true_` or `false_` and may be faster/
		template <typename C = identity>
		struct is_trivially_move_constructible {
			template <typename T>
			using f = typename C::template f<bool_<std::is_trivially_move_constructible<T>::value>>;
		};
#endif
		/// \brief tests if a type is nothrow move constructible
		/// \effects results in `true_` if dynamic input is nothrow move constructible
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_nothrow_move_constructible except the return
		/// is `true_` or `false_` and may be faster/
		template <typename C = identity>
		struct is_nothrow_move_constructible {
			template <typename T>
			using f = typename C::template f<bool_<std::is_nothrow_move_constructible<T>::value>>;
		};
		/// \brief tests if a type is assignable
		/// \effects results in `true_` if dynamic input is assignable
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_assignable except the return is `true_` or
		/// `false_` and may be faster/
		template <typename C = identity>
		struct is_assignable {
			template <typename T, typename U>
			using f = typename C::template f<bool_<std::is_assignable<T, U>::value>>;
		};
#if (__has_feature(is_trivially_assignable) && defined(_LIBCPP_VERSION)) || \
        (defined(__GNUC__) && __GNUC__ >= 5)
		/// \brief tests if a type is trivially assignable
		/// \effects results in `true_` if dynamic input is trivially assignable
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_trivially_assignable except the return is
		/// `true_` or `false_` and may be faster/
		template <typename C = identity>
		struct is_trivially_assignable {
			template <typename T, typename U>
			using f = typename C::template f<bool_<std::is_trivially_assignable<T, U>::value>>;
		};
#endif
		/// \brief tests if a type is nothrow assignable
		/// \effects results in `true_` if dynamic input is nothrow assignable
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_nothrow_assignable except the return is
		/// `true_` or `false_` and may be faster/
		template <typename C = identity>
		struct is_nothrow_assignable {
			template <typename T, typename U>
			using f = typename C::template f<bool_<std::is_nothrow_assignable<T, U>::value>>;
		};
		/// \brief tests if a type is copy assignable
		/// \effects results in `true_` if dynamic input copy assignable
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_copy_assignable except the return is `true_`
		/// or `false_` and may be faster/
		template <typename C = identity>
		struct is_copy_assignable {
			template <typename T>
			using f = typename C::template f<bool_<std::is_copy_assignable<T>::value>>;
		};
#if (__has_feature(is_trivially_copy_assignable) && defined(_LIBCPP_VERSION)) || \
        (defined(__GNUC__) && __GNUC__ >= 5)
		/// \brief tests if a type is trivally copy assignable
		/// \effects results in `true_` if dynamic input is trivially copy assignable
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_trivially_copy_assignable except the return is
		/// `true_` or `false_` and may be faster/
		template <typename C = identity>
		struct is_trivially_copy_assignable {
			template <typename T>
			using f = typename C::template f<bool_<std::is_trivially_copy_assignable<T>::value>>;
		};
#endif
		/// \brief tests if a type is nothrow copy assignable
		/// \effects results in `true_` if dynamic input is nothrow copy assignable
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_nothrow_copy_assignable except the return is
		/// `true_` or `false_` and may be faster/
		template <typename C = identity>
		struct is_nothrow_copy_assignable {
			template <typename T>
			using f = typename C::template f<bool_<std::is_nothrow_copy_assignable<T>::value>>;
		};
		/// \brief tests if a type is move assignable
		/// \effects results in `true_` if dynamic input is move assignable
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_move_assignable except the return is `true_`
		/// or `false_` and may be faster/
		template <typename C = identity>
		struct is_move_assignable {
			template <typename T>
			using f = typename C::template f<bool_<std::is_move_assignable<T>::value>>;
		};
#if (__has_feature(is_trivially_move_assignable) && defined(_LIBCPP_VERSION)) || \
        (defined(__GNUC__) && __GNUC__ >= 5)
		/// \brief tests if a type is trivially move assignable
		/// \effects results in `true_` if dynamic input is trivally move assignable
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_trivially_move_assignable except the return is
		/// `true_` or `false_` and may be faster/
		template <typename C = identity>
		struct is_trivially_move_assignable {
			template <typename T>
			using f = typename C::template f<bool_<std::is_trivially_move_assignable<T>::value>>;
		};
#endif
		/// \brief tests if a type is nothrow move assignable
		/// \effects results in `true_` if dynamic input is nothrow move assignable
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_nothrow_move_assignable except the return is
		/// `true_` or `false_` and may be faster/
		template <typename C = identity>
		struct is_nothrow_move_assignable {
			template <typename T>
			using f = typename C::template f<bool_<std::is_nothrow_move_assignable<T>::value>>;
		};
		/// \brief tests if a type is destructible
		/// \effects results in `true_` if dynamic input is destructible
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_destructible except the return is `true_` or
		/// `false_` and may be faster/
		template <typename C = identity>
		struct is_destructible {
			template <typename T>
			using f = typename C::template f<bool_<std::is_destructible<T>::value>>;
		};
		/// \brief tests if a type is trivially destructible
		/// \effects results in `true_` if dynamic input is trivially destructible
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_trivially_destructible except the return is
		/// `true_` or `false_` and may be faster/
		template <typename C = identity>
		struct is_trivially_destructible {
			template <typename T>
			using f = typename C::template f<bool_<std::is_trivially_destructible<T>::value>>;
		};
		/// \brief tests if a type is nothrow destructible
		/// \effects results in `true_` if dynamic input is nothrow destructible
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_nothrow_destructible except the return is
		/// `true_` or `false_` and may be faster/
		template <typename C = identity>
		struct is_nothrow_destructible {
			template <typename T>
			using f = typename C::template f<bool_<std::is_nothrow_destructible<T>::value>>;
		};
		/// \brief tests if a type has a virtual destructor
		/// \effects results in `true_` if dynamic input has a virtual destructor
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::has_virtual_destructor except the return is
		/// `true_` or `false_` and may be faster/
		template <typename C = identity>
		struct has_virtual_destructor {
			template <typename T>
			using f = typename C::template f<bool_<std::has_virtual_destructor<T>::value>>;
		};

		/// \brief tests if a type is the same as another type
		/// \effects results in `true_` if dynamic input is the same as another type
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_same except the return is `true_` or `false_`
		/// and may be faster/
		template <typename C = identity>
		struct is_same {
			template <typename T, typename U>
			using f = typename C::template f<bool_<std::is_same<T, U>::value>>;
		};
		/// \brief tests if a type is the base class of another type
		/// \effects results in `true_` if dynamic input is the base class of another type
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_base_of except the return is `true_` or
		/// `false_` and may be faster/
		template <typename C = identity>
		struct is_base_of {
			template <typename T, typename U>
			using f = typename C::template f<bool_<std::is_base_of<T, U>::value>>;
		};
		/// \brief tests if a type is convertible to another type
		/// \effects results in `true_` if dynamic input is convertible to another type
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// tested \notes this is the same as std::is_convertible except the return is `true_` or
		/// `false_` and may be faster/
		template <typename C = identity>
		struct is_convertible {
			template <typename T, typename U>
			using f = typename C::template f<bool_<std::is_convertible<T, U>::value>>;
		};

		/// \brief returns the allignment of a type
		/// \effects results in `uint_<N>` for a type with allignment of N
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// quirried \notes this is the same as std::allignment_of except the return is `uint_<N>`
		/// and may be faster/
		template <typename C = identity>
		struct alignment_of {
			template <typename T>
			using f = typename C::template f<typename std::alignment_of<T>::type>;
		};
		/// \brief returns the rank of a type
		/// \effects results in `uint_<N>` for a type with rank of N
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// quirried \notes this is the same as std::rank except the return is `uint_<N>` and
		/// may be faster/
		template <typename C = identity>
		struct rank {
			template <typename T>
			using f = typename C::template f<uint_<std::rank<T>::value>>;
		};
		/// \brief returns the extent of a type
		/// \effects results in `uint_<N>` for a type with extent of N
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// quirried \notes this is the same as std::extent except the return is `uint_<N>` and
		/// may be faster/
		template <typename C = identity>
		struct extent {
			template <typename T>
			using f = typename C::template f<uint_<std::extent<T>::value>>;
		};
		/// \brief returns the input type with const and volatile qualifiers stripped
		/// \effects results in the input type with const and volatile qualifiers stripped
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// modified \notes this is the same as std::remove_cv except it
		/// may be faster/
		template <typename C = identity>
		struct remove_cv {
			template <typename T>
			using f = typename C::template f<typename std::remove_cv<T>::type>;
		};
		/// \brief returns the input type with const qualifiers stripped
		/// \effects results in the input type with const qualifiers stripped
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// modified \notes this is the same as std::remove_const except it
		/// may be faster/
		template <typename C = identity>
		struct remove_const {
			template <typename T>
			using f = typename C::template f<typename std::remove_const<T>::type>;
		};
		/// \brief returns the input type with volatile qualifiers stripped
		/// \effects results in the input type with volatile qualifiers stripped
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// modified \notes this is the same as std::remove_volatile except it
		/// may be faster/
		template <typename C = identity>
		struct remove_volatile {
			template <typename T>
			using f = typename C::template f<typename std::remove_volatile<T>::type>;
		};
		/// \brief returns the input type with const and volatile qualifiers added
		/// \effects results in the input type with const and volatile qualifiers added
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// modified \notes this is the same as std::add_cv except it
		/// may be faster/
		template <typename C = identity>
		struct add_cv {
			template <typename T>
			using f = typename C::template f<const volatile T>;
		};
		/// \brief returns the input type with const qualifiers added
		/// \effects results in the input type with const qualifiers added
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// modified \notes this is the same as std::add_comst except it
		/// may be faster/
		template <typename C = identity>
		struct add_const {
			template <typename T>
			using f = typename C::template f<const T>;
		};
		/// \brief returns the input type with volatile qualifiers added
		/// \effects results in the input type with const qualifiers added
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// modified \notes this is the same as std::add_volatile except it
		/// may be faster/
		template <typename C = identity>
		struct add_volatile {
			template <typename T>
			using f = typename C::template f<volatile T>;
		};
		template <typename C = identity>
		struct remove_reference {
			template <typename T>
			using f = typename C::template f<typename std::remove_reference<T>::type>;
		};
		/// \brief returns the input type as an lvalue reference
		/// \effects results in the input type as an lvalue reference
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// modified \notes this is the same as std::add_lvalue_reference except it
		/// may be faster/
		template <typename C = identity>
		struct add_lvalue_reference {
			template <typename T>
			using f = typename C::template f<typename std::add_lvalue_reference<T>::type>;
		};
		/// \brief returns the input type as an rvalue reference
		/// \effects results in the input type as an rvalue reference
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// modified \notes this is the same as std::add_volatile except it
		/// may be faster/
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
		/// \brief returns the input type with a pointer added
		/// \effects results in the input type with a pointer added
		/// \requires fixed parameters: optional continuation, dynamic parameters: the type to be
		/// modified \notes this is the same as std::add_pointer except it
		/// may be faster/
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
			using f = typename C::template f<typename std::common_type<T>::type>;
		};
		template <typename C = identity>
		struct underlying_type {
			template <typename T>
			using f = typename C::template f<typename std::underlying_type<T>::type>;
		};
#if __cplusplus >= 201402L
#ifdef __cpp_lib_is_null_pointer
		template <typename C = identity>
		struct is_null_pointer {
			template <typename T>
			using f = typename C::template f<bool_<std::is_null_pointer<T>::value>>;
		};
		/// \exclude
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

//          Copyright Odin Holmes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#ifndef __has_feature
#define __has_feature(x) 0
#endif

#if defined(__cplusplus)
#if __cplusplus >= 201402L
///\exclude
#define KVASIR_CONSTEXPR_14
#endif
#endif

#if defined(_MSC_VER) && !defined(__GNUC__) && !defined(__clang__)
#if _MSC_VER == 1910
///\exclude
#define KVASIR_MSVC_2017
#elif _MSC_VER == 1900
///\exclude
#define KVASIR_MSVC_2015
#elif _MSC_VER == 1800
///\exclude
#define KVASIR_MSVC_2013
#endif
#elif __INTEL_COMPILER

#elif __GNUC__
#ifndef __clang__
///\exclude
#define KVASIR_GCC
#if __GNUC__ < 5
// old GCC
#else
#if __GNUC__ < 6
///\exclude
#define KVASIR_GCC5
#else
#if __GNUC__ < 7
///\exclude
#define KVASIR_GCC6
#else
///\exclude
#define KVASIR_GCC7
#endif
#endif
#endif
#else
///\exclude
#define KVASIR_CLANG
#if __clang_major__ == 3
#if __clang_minor__ == 5
///\exclude
#define KVASIR_CLANG_35
#elif __clang_minor__ == 6
///\exclude
#define KVASIR_CLANG_36
#elif __clang_minor__ == 7
#define KVASIR_CLANG_37
#endif
#endif
#endif
#endif

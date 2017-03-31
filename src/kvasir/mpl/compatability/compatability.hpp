//          Copyright Odin Holmes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#if defined(__cplusplus)
#  if __cplusplus >= 201402L
#    define KVASIR_CONSTEXPR_14
#  endif
#endif


#if defined(_MSC_VER) && !defined(__GNUC__) && !defined(__clang__)
#if _MSC_VER == 1910
#define KVASIR_MSVC_2017
#elif _MSC_VER == 1900
#define KVASIR_MSVC_2015
#elif _MSC_VER == 1800
#define KVASIR_MSVC_2013
#endif
#elif __INTEL_COMPILER

#elif __GNUC__
#ifndef __clang__
// GCC
#else
#if __clang_major__ == 3
#if __clang_minor__ == 5
#define KVASIR_CLANG_35
#elif __clang_minor__ == 6
#define KVASIR_CLANG_36
#elif __clang_minor__ == 7
#define KVASIR_CLANG_37
#endif
#endif
#endif
#endif

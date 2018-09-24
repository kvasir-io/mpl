//          Copyright Chiel Douwes 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#define TEST_CPP(NAME) \
auto NAME##_impl = PRECALC_SECTION(NAME##_t); \
mc::detail::section_base *NAME = &NAME##_impl;


////////////////////////////////////////////////////////////////////////////////
/// \file    core_assert.h
///
/// \author  Joerg Sahm
/// \author  Copyright (c) Joerg Sahm. All rights reserved.
///
/// \date    2011
///
/// \version 1.0
///
/// \brief   A brief file description.
///
/// A detailed file description.
////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef __INCLUDE_CORE_ASSERT_H_
#define __INCLUDE_CORE_ASSERT_H_

#include "base_defines.h"

#include CORE_INCLUDE_ASSERTMANAGER

// -----------------------------------------------------------------------------
// Compile time assert
// -----------------------------------------------------------------------------
#define CORE_STATIC_ASSERT(Condition)       typedef CORE::Private::SStaticAssertTest<sizeof(CORE::Private::SStaticAssertError<(Condition)>)> SStaticAssert

// -----------------------------------------------------------------------------
// Runtime asserts
// -----------------------------------------------------------------------------
#if (BASE_HAS_ASSERTS == BASE_TRUE)

#define CORE_ASSERT(Condition)              { \
                                                if (!(Condition)) \
                                                { \
                                                    ::CORE::Assert::Handle(#Condition, "", __FILE__, __LINE__, 0); \
                                                } \
                                            }

#define CORE_ASSERTM(Condition, Message)    { \
                                                if (!(Condition)) \
                                                { \
                                                    ::CORE::Assert::Handle(#Condition, (Message), __FILE__, __LINE__, 0); \
                                                } \
                                            }

#define CORE_ERROR(Message)                 ::CORE::Assert::Handle("", (Message), __FILE__, __LINE__, 0)

#else

#define CORE_ASSERT(Condition)              BASE_EMPTY_STATEMENT
#define CORE_ASSERTM(Condition, Message)    BASE_EMPTY_STATEMENT
#define CORE_ERROR(Message)                 BASE_EMPTY_STATEMENT

#endif // CORE_ENABLE_ASSERTS

namespace CORE
{
namespace Private
{
    template <bool>
    struct SStaticAssertError;

    // -----------------------------------------------------------------------------

    template <> 
    struct SStaticAssertError<true> 
    {
    };

    // -----------------------------------------------------------------------------

    template <int> 
    struct SStaticAssertTest 
    {
    };
} // namespace Private
} // namespace CORE

#endif // __INCLUDE_CORE_ASSERT_H_
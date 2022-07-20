
////////////////////////////////////////////////////////////////////////////////
/// \file    ut_tools.h
///
/// \author  Joerg Sahm
/// \author  Credits to Dirk Steenpass.
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

#ifndef __INCLUDE_UT_TEST_H_
#define __INCLUDE_UT_TEST_H_

#include "base_defines.h"

#include UT_INCLUDE_TOOLS

#include <exception>

#define UT_TEST(TestFunction)                                                                       \
    void TestFunction();                                                                            \
    void BASE_CONCAT(SetTestSource, TestFunction)();                                                \
    struct BASE_CONCAT(SReg, TestFunction)                                                          \
    {                                                                                               \
        BASE_CONCAT(SReg, TestFunction())                                                           \
        {                                                                                           \
            ::UT::Suite::RegisterTest(BASE_CONCAT(SetTestSource, TestFunction));                    \
            ::UT::Suite::RegisterTest(TestFunction);                                                \
        }                                                                                           \
    } const BASE_CONCAT(g_Reg, TestFunction);                                                       \
    void BASE_CONCAT(SetTestSource, TestFunction)()                                                 \
    {                                                                                               \
        ::UT::Suite::SetTestSource(__FILE__, #TestFunction, __LINE__);                              \
    }                                                                                               \
    void TestFunction()

// -----------------------------------------------------------------------------

#define UT_CHECK(Condition)                                                                         \
    {                                                                                               \
        ::UT::Suite::SetTestSource(__FILE__, __FUNCTION__, __LINE__);                               \
        try                                                                                         \
        {                                                                                           \
            if (!(Condition))                                                                       \
            {                                                                                       \
                ::UT::Suite::LogFailure();                                                          \
                ::UT::Suite::LogCondition(#Condition);                                              \
            }                                                                                       \
        }                                                                                           \
        catch (std::exception& _rException)                                                         \
        {                                                                                           \
            ::UT::Suite::LogFailure();                                                              \
            ::UT::Suite::LogException(_rException.what());                                          \
            ::UT::Suite::LogCondition(#Condition);                                                  \
        }                                                                                           \
        catch (...)                                                                                 \
        {                                                                                           \
            ::UT::Suite::LogFailure();                                                              \
            ::UT::Suite::LogException("unknown exception");                                         \
            ::UT::Suite::LogCondition(#Condition);                                                  \
        }                                                                                           \
    }                                                                                               \
    BASE_EMPTY_STATEMENT

// -----------------------------------------------------------------------------

#define UT_CHECK_EQUAL(A, B)                                                                        \
    {                                                                                               \
        ::UT::Suite::SetTestSource(__FILE__, __FUNCTION__, __LINE__);                               \
        ::UT::Private::CheckEqual(A, B);                                                            \
    }                                                                                               \
    BASE_EMPTY_STATEMENT

// -----------------------------------------------------------------------------

#define UT_CHECK_ABS_CLOSE(A, B, Tolerance)                                                         \
    {                                                                                               \
        ::UT::Suite::SetTestSource(__FILE__, __FUNCTION__, __LINE__);                               \
        ::UT::Private::CheckAbsClose(A, B, Tolerance);                                              \
    }                                                                                               \
    BASE_EMPTY_STATEMENT

// -----------------------------------------------------------------------------

#define UT_CHECK_REL_CLOSE(A, B, Tolerance)                                                         \
    {                                                                                               \
        ::UT::Suite::SetTestSource(__FILE__, __FUNCTION__, __LINE__);                               \
        ::UT::Private::CheckRelClose(A, B, Tolerance);                                              \
    }                                                                                               \
    BASE_EMPTY_STATEMENT

// -----------------------------------------------------------------------------

#define UT_CHECK_REL_CLOSE_WEAK(A, B, Tolerance)                                                    \
    {                                                                                               \
        ::UT::Suite::SetTestSource(__FILE__, __FUNCTION__, __LINE__);                               \
        ::UT::Private::CheckRelCloseWeak(A, B, Tolerance);                                          \
    }                                                                                               \
    BASE_EMPTY_STATEMENT

// -----------------------------------------------------------------------------

#define UT_CHECK_THROW(Expression, ExceptionType)                                                   \
    {                                                                                               \
        ::UT::Suite::SetTestSource(__FILE__, __FUNCTION__, __LINE__);                               \
        ::UT::Private::SCheckThrowResult::Enum Result(::UT::Private::SCheckThrowResult::NoThrow);   \
        try                                                                                         \
        {                                                                                           \
            Expression;                                                                             \
        }                                                                                           \
        catch (ExceptionType&)                                                                      \
        {                                                                                           \
            Result = ::UT::Private::SCheckThrowResult::ExpectedThrow;                               \
        }                                                                                           \
        catch (...)                                                                                 \
        {                                                                                           \
            Result = ::UT::Private::SCheckThrowResult::BadThrow;                                    \
        }                                                                                           \
        IO::CStringOutputStream& rStream = ::UT::Suite::GetLogStream();                             \
        if (Result == ::UT::Private::SCheckThrowResult::NoThrow)                                    \
        {                                                                                           \
            ::UT::Suite::LogFailure();                                                              \
            rStream << #ExceptionType << " not thrown";                                             \
            ::UT::Suite::Log(rStream);                                                              \
        }                                                                                           \
        else if (Result == ::UT::Private::SCheckThrowResult::BadThrow)                              \
        {                                                                                           \
            ::UT::Suite::LogFailure();                                                              \
            rStream << "unhandled exception in UT_CHECK_THROW";                                     \
            ::UT::Suite::Log(rStream);                                                              \
        }                                                                                           \
    }                                                                                               \
    BASE_EMPTY_STATEMENT

#endif // __INCLUDE_UT_TEST_H_
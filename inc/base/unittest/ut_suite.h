
////////////////////////////////////////////////////////////////////////////////
/// \file    ut_suite.h
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

#ifndef __INCLUDE_UT_SUITE_H_
#define __INCLUDE_UT_SUITE_H_

#include "base_defines.h"

#include CORE_INCLUDE_TYPES

#include <sstream>

namespace UT
{
    typedef void (*FTestFunction)();
} // namespace UT

namespace UT
{
namespace Suite
{
    void SetName(const CORE::Char* _pName);
    const CORE::Char* GetName();

    void Reset(std::ostream* _pStream = 0);

    void RegisterTest(FTestFunction _Test);
    void RunTests();

    void SetTestSource(const CORE::Char* _pFilename, const CORE::Char* _pFunctionName, int _LineNumber);

    void LogFailure();
    void LogException(const CORE::Char* _pException);
    void LogCondition(const CORE::Char* _pCondition);
    void Log(std::ostringstream& _rStream);

    std::ostringstream& GetLogStream();

    size_t GetTestCount();
    size_t GetFailedTestCount();
} // namespace Suite
} // namespace UT

#endif // __INCLUDE_UT_SUITE_H_
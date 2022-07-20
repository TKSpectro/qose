
////////////////////////////////////////////////////////////////////////////////
/// \file    core_assertmanager.h
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

#ifndef __INCLUDE_CORE_ASSERTMANAGER_H_
#define __INCLUDE_CORE_ASSERTMANAGER_H_

#include "base_defines.h"

#include CORE_INCLUDE_TYPES

namespace CORE
{
    class CAssertHandler;
} // namespace CORE

namespace CORE
{
namespace Assert
{
    int Handle(const Char* _pCondition, const Char* _pMessage, const Char* _pFile, int _Line, int _Extra);

    void SetAssertHandler(CAssertHandler* _pHandler);
    CAssertHandler* GetAssertHandler();

    void SetAssertsEnabled(bool _Flag);
    bool AreAssertsEnabled();
} // namespace Assert
} // namespace CORE

#endif // __INCLUDE_CORE_ASSERTMANAGER_H_
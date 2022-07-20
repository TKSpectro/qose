
////////////////////////////////////////////////////////////////////////////////
/// \file    core_nativeasserthandler.cpp
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

#if (BASE_PLATFORM == BASE_PLATFORM_WIN32)

#include "base_defines.h"

#include CORE_INCLUDE_NATIVEASSERTHANDLER
#include CORE_INCLUDE_SYSTEM

#include <stdio.h>

namespace CORE
{
namespace Private
{
    // -----------------------------------------------------------------------------
    // Implementation CNativeAssertHandler.
    // -----------------------------------------------------------------------------
    CNativeDefaultAssertHandler::CNativeDefaultAssertHandler()
    {
    }

    // -----------------------------------------------------------------------------

    CNativeDefaultAssertHandler::~CNativeDefaultAssertHandler()
    {
    }

    // -----------------------------------------------------------------------------

    int CNativeDefaultAssertHandler::Handle(const Char* _pCondition, const Char* _pMessage, const Char* _pFile, int _Line, int _Extra)
    {
        BASE_UNUSED(_Extra);

        Char Buffer[4096];

        _snprintf_s(Buffer, sizeof(Buffer), _TRUNCATE, "\n\n%s(%u) : ASSERT FAILURE: %s %s\n", _pFile, _Line, _pCondition, _pMessage);

        printf(Buffer);

        DebugBreak();

        return 0;
    }
} // namespace Private
} // namespace CORE

#endif // BASE_PLATFORM == BASE_PLATFORM_WIN32
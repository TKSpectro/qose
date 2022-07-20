
////////////////////////////////////////////////////////////////////////////////
/// \file    io_nativedebug.cpp
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

#include "base_defines.h"

#if (BASE_PLATFORM == BASE_PLATFORM_WIN32)

#include CORE_INCLUDE_ASSERT
#include CORE_INCLUDE_SYSTEM

#include IO_INCLUDE_NATIVEDEBUG

namespace IO
{
namespace Private
{
    // -----------------------------------------------------------------------------
    // Implementation CNativeDebug.
    // -----------------------------------------------------------------------------
    CNativeDebug::CNativeDebug()
    {
    }

    // -----------------------------------------------------------------------------

    CNativeDebug::~CNativeDebug()
    {
    }

    // -----------------------------------------------------------------------------

    void CNativeDebug::Write(const CORE::Char* _pBuffer) const
    {
        CORE_ASSERTM(_pBuffer != 0, "Debug string is NULL.");

        OutputDebugStringA(_pBuffer);
    }

    // -----------------------------------------------------------------------------

    void CNativeDebug::Write(const CORE::WChar* _pBuffer) const
    {
        CORE_ASSERTM(_pBuffer != 0, "Debug string is NULL.");

        OutputDebugStringW(_pBuffer);
    }
} // namespace Private
} // namespace IO

#endif // BASE_PLATFORM == BASE_PLATFORM_WIN32
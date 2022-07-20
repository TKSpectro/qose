
////////////////////////////////////////////////////////////////////////////////
/// \file    core_asserthandler.cpp
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

#if (BASE_HAS_ASSERTS == BASE_TRUE)

#include "base_defines.h"

#include CORE_INCLUDE_ASSERTHANDLER

namespace CORE
{
    CDefaultAssertHandler::CDefaultAssertHandler()
        : m_NativeHandler()
    {
    }

    // -----------------------------------------------------------------------------

    CDefaultAssertHandler::~CDefaultAssertHandler()
    {
    }

    // -----------------------------------------------------------------------------

    int CDefaultAssertHandler::InternHandle(const Char* _pCondition, const Char* _pMessage, const Char* _pFile, int _Line, int _Extra)
    {
        return m_NativeHandler.Handle(_pCondition, _pMessage, _pFile, _Line, _Extra);
    }
} // namespace CORE

#endif // Has assertions

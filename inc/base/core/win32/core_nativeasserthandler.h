
////////////////////////////////////////////////////////////////////////////////
/// \file    core_nativeasserthandler.h
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

#ifndef __INCLUDE_CORE_NATIVEASSERTHANDLER_H_
#define __INCLUDE_CORE_NATIVEASSERTHANDLER_H_

#include "base_defines.h"

#include CORE_INCLUDE_TYPES

namespace CORE
{
namespace Private
{
    // -----------------------------------------------------------------------------
    // Declaration CNativeAssertHandler.
    // -----------------------------------------------------------------------------
    class BASE_API CNativeDefaultAssertHandler
    {
        public:

            CNativeDefaultAssertHandler();
           ~CNativeDefaultAssertHandler();

        public:

            int Handle(const Char* _pCondition, const Char* _pMessage, const Char* _pFile, int _Line, int _Extra);

        private:

            CNativeDefaultAssertHandler(const CNativeDefaultAssertHandler&);

            CNativeDefaultAssertHandler& operator = (const CNativeDefaultAssertHandler&);
    };
} // namespace Private
} // namespace CORE

#endif // __INCLUDE_CORE_NATIVEASSERTHANDLER_H_
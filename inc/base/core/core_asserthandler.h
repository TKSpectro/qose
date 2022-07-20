
////////////////////////////////////////////////////////////////////////////////
/// \file    core_asserthandler.h
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

#ifndef __INCLUDE_CORE_ASSERTHANDLER_H_
#define __INCLUDE_CORE_ASSERTHANDLER_H_

#include "base_defines.h"

#include CORE_INCLUDE_NATIVEASSERTHANDLER
#include CORE_INCLUDE_TYPES

namespace CORE
{
    class CAssertHandler
    {
        public:

            inline int Handle(const Char* _pCondition, const Char* _pMessage, const Char* _pFile, int _Line, int _Extra);

        public:

            virtual int InternHandle(const Char* _pCondition, const Char* _pMessage, const Char* _pFile, int _Line, int _Extra) = 0;
    };
} // namespace CORE

namespace CORE
{
    class CDefaultAssertHandler : public CAssertHandler
    {
        public:

            CDefaultAssertHandler();
           ~CDefaultAssertHandler();

        private:

            virtual int InternHandle(const Char* _pCondition, const Char* _pMessage, const Char* _pFile, int _Line, int _Extra);

        private:

            Private::CNativeDefaultAssertHandler m_NativeHandler;
    };
} // namespace CORE

namespace CORE
{
    inline int CAssertHandler::Handle(const Char* _pCondition, const Char* _pMessage, const Char* _pFile, int _Line, int _Extra)
    {
        return InternHandle(_pCondition, _pMessage, _pFile, _Line, _Extra);
    }
} // namespace CORE

#endif // __INCLUDE_CORE_ASSERTHANDLER_H_
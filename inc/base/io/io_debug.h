
////////////////////////////////////////////////////////////////////////////////
/// \file    io_debug.h
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

#ifndef __INCLUDE_IO_DEBUG_H_
#define __INCLUDE_IO_DEBUG_H_

#include "base_defines.h"

#include CORE_INCLUDE_TYPES

#include IO_INCLUDE_NATIVEDEBUG

namespace IO
{
    // -----------------------------------------------------------------------------
    // Declaration CDebug.
    // -----------------------------------------------------------------------------
    class CDebug
    {
        public:

            inline CDebug();
            inline ~CDebug();

            inline void Write(const CORE::Char*  _pBuffer) const;
            inline void Write(const CORE::WChar* _pBuffer) const;

        private:

            ::IO::Private::CNativeDebug m_NativeDebug;

        private:

            CDebug(const CDebug&);

            CDebug& operator = (const CDebug&);
    };
} // namespace IO

namespace IO
{
    // -----------------------------------------------------------------------------
    // Implementation CDebug.
    // -----------------------------------------------------------------------------
    inline CDebug::CDebug()
    {
    }

    // -----------------------------------------------------------------------------

    inline CDebug::~CDebug()
    {
    }

    // -----------------------------------------------------------------------------

    inline void CDebug::Write(const CORE::Char* _pBuffer) const
    {
        m_NativeDebug.Write(_pBuffer);
    }

    // -----------------------------------------------------------------------------

    inline void CDebug::Write(const CORE::WChar* _pBuffer) const
    {
        m_NativeDebug.Write(_pBuffer);
    }
} // namespace IO

#endif // __INCLUDE_IO_DEBUG_H_
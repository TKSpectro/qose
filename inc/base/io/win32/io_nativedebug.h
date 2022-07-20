
////////////////////////////////////////////////////////////////////////////////
/// \file    io_nativedebug.h
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

#ifndef __INCLUDE_IO_NATIVEDEBUG_H_
#define __INCLUDE_IO_NATIVEDEBUG_H_

#include "base_defines.h"

#include CORE_INCLUDE_TYPES

namespace IO
{
namespace Private
{
    // -----------------------------------------------------------------------------
    // Declaration CNativeDebug.
    // -----------------------------------------------------------------------------
    class BASE_API CNativeDebug
    {
        public:

            CNativeDebug();
           ~CNativeDebug();

            void Write(const CORE::Char*  _pBuffer) const;
            void Write(const CORE::WChar* _pBuffer) const;

        private:

            CNativeDebug(const CNativeDebug&);

            CNativeDebug& operator = (const CNativeDebug&);
    };
} // namespace Private
} // namespace IO

#endif // __INCLUDE_IO_NATIVEDEBUG_H_
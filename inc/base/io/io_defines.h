
////////////////////////////////////////////////////////////////////////////////
/// \file    io_defines.h
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

#ifndef __INCLUDE_IO_DEFINES_H_
#define __INCLUDE_IO_DEFINES_H_

// -----------------------------------------------------------------------------
// Include paths.
// -----------------------------------------------------------------------------
#define IO_INCLUDE_DEBUG                "io/io_debug.h"

#if (BASE_PLATFORM == BASE_PLATFORM_WIN32)
#define IO_INCLUDE_NATIVEDEBUG          "io/win32/io_nativedebug.h"
#elif (BASE_PLATFORM == BASE_PLATFORM_WIN64)
#define IO_INCLUDE_NATIVEDEBUG          "io/win64/io_nativedebug.h"
#endif // Native includes

#endif // __INCLUDE_IO_DEFINES_H_
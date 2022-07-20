
////////////////////////////////////////////////////////////////////////////////
/// \file    core_defines.h
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

#ifndef __INCLUDE_CORE_DEFINES_H_
#define __INCLUDE_CORE_DEFINES_H_

// -----------------------------------------------------------------------------
// Include paths.
// -----------------------------------------------------------------------------
#define CORE_INCLUDE_ALIGNEDALLOCATOR           "core/core_alignedallocator.h"
#define CORE_INCLUDE_ALLOCATOR                  "core/core_allocator.h"
#define CORE_INCLUDE_ASSERT                     "core/core_assert.h"
#define CORE_INCLUDE_ASSERTHANDLER              "core/core_asserthandler.h"
#define CORE_INCLUDE_ASSERTMANAGER              "core/core_assertmanager.h"
#define CORE_INCLUDE_EMPTYALLOCATOR             "core/core_emptyallocator.h"
#define CORE_INCLUDE_ERROR                      "core/core_error.h"
#define CORE_INCLUDE_EXCEPTION                  "core/core_exception.h"
#define CORE_INCLUDE_FUNCTOR                    "core/core_functor.h"
#define CORE_INCLUDE_MEMORY                     "core/core_memory.h"
#define CORE_INCLUDE_MEMORYCOMPARE              "core/core_memorycompare.h"
#define CORE_INCLUDE_MEMORYCOPY                 "core/core_memorycopy.h"
#define CORE_INCLUDE_MEMORYERRORHANDLER         "core/core_memoryerrorhandler.h"
#define CORE_INCLUDE_MEMORYERRORMANAGER         "core/core_memoryerrormanager.h"
#define CORE_INCLUDE_MEMORYFILL                 "core/core_memoryfill.h"
#define CORE_INCLUDE_STRING                     "core/core_string.h"
#define CORE_INCLUDE_SYSTEM                     "core/core_system.h"
#define CORE_INCLUDE_TOOLS                      "core/core_tools.h"
#define CORE_INCLUDE_TYPELIST                   "core/core_typelist.h"
#define CORE_INCLUDE_TYPETOOLS                  "core/core_typetools.h"
#define CORE_INCLUDE_TYPES                      "core/core_types.h"

#if (BASE_PLATFORM == BASE_PLATFORM_WIN32)
#define CORE_INCLUDE_NATIVEASSERTHANDLER        "core/win32/core_nativeasserthandler.h"
#define CORE_INCLUDE_NATIVESYSTEM               "core/win32/core_nativesystem.h"
#elif (BASE_PLATFORM == BASE_PLATFORM_WIN64)
#define CORE_INCLUDE_NATIVEASSERTHANDLER        "core/win64/core_nativeasserthandler.h"
#define CORE_INCLUDE_NATIVESYSTEM               "core/win64/core_nativesystem.h"
#endif // Native includes

#endif // __INCLUDE_CORE_DEFINES_H_
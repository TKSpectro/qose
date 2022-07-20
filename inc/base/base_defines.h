
////////////////////////////////////////////////////////////////////////////////
/// \file    base_defines.h
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

#ifndef __INCLUDE_BASE_DEFINES_H_
#define __INCLUDE_BASE_DEFINES_H_

// -----------------------------------------------------------------------------
// Includes with definitions.
// -----------------------------------------------------------------------------
#include "core\core_defines.h"
#include "io\io_defines.h"
#include "pattern\pat_defines.h"
#include "unittest\ut_defines.h"

// -----------------------------------------------------------------------------
// On/Off switches.
// -----------------------------------------------------------------------------
#define BASE_FALSE                  1
#define BASE_TRUE                   2

// -----------------------------------------------------------------------------
// Available platforms.
// -----------------------------------------------------------------------------
#define BASE_PLATFORM_WIN32         1
#define BASE_PLATFORM_WIN64         2

// -----------------------------------------------------------------------------
// Available compilers.
// -----------------------------------------------------------------------------
#define BASE_COMPILER_VC9           1
#define BASE_COMPILER_VC10          2

// -----------------------------------------------------------------------------
// Available configurations.
// -----------------------------------------------------------------------------
#define BASE_CFG_DEBUG              1
#define BASE_CFG_RELEASE            2

// -----------------------------------------------------------------------------
// Available address sizes.
// -----------------------------------------------------------------------------
#define BASE_ADDRESS_SIZE_32        32
#define BASE_ADDRESS_SIZE_64        64

// -----------------------------------------------------------------------------
// Define the configuration.
// -----------------------------------------------------------------------------
#ifdef BASE_DEBUG
#define BASE_CFG                    BASE_CFG_DEBUG
#elif BASE_RELEASE
#define BASE_CFG                    BASE_CFG_RELEASE
#else
#error ("Unsupported compile configuration.")
#endif // Compile configuration

// -----------------------------------------------------------------------------
// Unused argument macro to avoid compiler warnings.
// -----------------------------------------------------------------------------
#define BASE_UNUSED(Argument)       ((void) &Argument)

// -----------------------------------------------------------------------------
// Empty statement.
// -----------------------------------------------------------------------------
#define BASE_EMPTY_STATEMENT        ((void) 0)

// -----------------------------------------------------------------------------
// Macro concatenation
// -----------------------------------------------------------------------------
#define BASE_CONCAT(A, B)           BASE_CONCAT_IMPL(A, B)
#define BASE_CONCAT_IMPL(A, B)      BASE_CONCAT_IMPL2(A, B)
#define BASE_CONCAT_IMPL2(A, B)     A ## B

// -----------------------------------------------------------------------------
// Include user defined settings.
// -----------------------------------------------------------------------------
#include "base_config.h"

// -----------------------------------------------------------------------------
// Define the namespace identifiers.
// -----------------------------------------------------------------------------
#if (BASE_HAS_USER_NAMESPACE == BASE_TRUE)
#define ARCH                        BASE_USER_NAMESPACE
#define CON                         BASE_USER_NAMESPACE
#define CORE                        BASE_USER_NAMESPACE
#define CC                          BASE_USER_NAMESPACE
#define IO                          BASE_USER_NAMESPACE
#define MATH                        BASE_USER_NAMESPACE
#define MEM                         BASE_USER_NAMESPACE
#define PAT                         BASE_USER_NAMESPACE
#define UT                          BASE_USER_NAMESPACE
#else
#define ARCH                        archive
#define CC                          concurrent
#define CON                         con
#define CORE                        core
#define IO                          io
#define MATH                        math
#define MEM                         mem
#define PAT                         pattern
#define UT                          unittest
#endif // User defined or default namespace

// -----------------------------------------------------------------------------
// Define 32 bit or 64 bit software
// -----------------------------------------------------------------------------
#if (BASE_PLATFORM == BASE_PLATFORM_WIN32)
#define BASE_ADDRESS_SIZE           BASE_ADDRESS_SIZE_32
#elif (BASE_PLATFORM == BASE_PLATFORM_WIN64)
#define BASE_ADDRESS_SIZE           BASE_ADDRESS_SIZE_64
#endif // 32 bit or 64 bit software

// -----------------------------------------------------------------------------
// DLL import/export definitions.
// -----------------------------------------------------------------------------
#if (BASE_COMPILER == BASE_COMPILER_VC9) || (BASE_COMPILER == BASE_COMPILER_VC10)
#define BASE_DLL_IMPORT             __declspec(dllimport)
#define BASE_DLL_EXPORT             __declspec(dllexport)
#else
#define BASE_DLL_IMPORT
#define BASE_DLL_EXPORT
#endif // Import and export declarations

#ifdef BASE_DLL
#define BASE_API_IMPORT             BASE_DLL_IMPORT
#define BASE_API_EXPORT             BASE_DLL_EXPORT
#else
#define BASE_API_IMPORT
#define BASE_API_EXPORT
#endif // DLL or no DLL

#ifdef BASE_EXPORT_DLL
#define BASE_API                    BASE_API_EXPORT
#else
#define BASE_API                    BASE_API_IMPORT
#endif // Export or import

// -----------------------------------------------------------------------------
// Declares a class as a single inheritance class.
// -----------------------------------------------------------------------------
#if (BASE_COMPILER == BASE_COMPILER_VC9) || (BASE_COMPILER == BASE_COMPILER_VC10)
#define BASE_SINGLE_INHERITANCE     __single_inheritance
#else
#define BASE_SINGLE_INHERITANCE
#endif // Single inheritance

// -----------------------------------------------------------------------------
// Calling conventions.
// -----------------------------------------------------------------------------
#if (BASE_COMPILER == BASE_COMPILER_VC9) || (BASE_COMPILER == BASE_COMPILER_VC10)
#define BASE_CCALL                  __cdecl
#define BASE_STDCALL                __stdcall
#define BASE_FASTCALL               __fastcall
#else
#define BASE_CCALL
#define BASE_STDCALL
#define BASE_FASTCALL
#endif // Calling conventions

// -----------------------------------------------------------------------------
// Data alignment.
// -----------------------------------------------------------------------------
#if (BASE_COMPILER == BASE_COMPILER_VC9) || (BASE_COMPILER == BASE_COMPILER_VC10)
#define BASE_ALIGNOF                __alignof
#else
#define BASE_ALIGNOF
#endif // Data alignment

#endif // __INCLUDE_BASE_DEFINES_H_
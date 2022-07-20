
////////////////////////////////////////////////////////////////////////////////
/// \file    base_preconfig.h
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

#ifndef __INCLUDE_BASE_PRECONFIG_H_
#define __INCLUDE_BASE_PRECONFIG_H_

// -----------------------------------------------------------------------------
// Define the platform.
// -----------------------------------------------------------------------------
#define BASE_PLATFORM                   BASE_PLATFORM_WIN32

// -----------------------------------------------------------------------------
// Define the compiler.
// -----------------------------------------------------------------------------
#define BASE_COMPILER                   BASE_COMPILER_VC10

// -----------------------------------------------------------------------------
// Use default namespace or user defined namespace.
// -----------------------------------------------------------------------------
#define BASE_HAS_USER_NAMESPACE         BASE_FALSE

// -----------------------------------------------------------------------------
// In case of a user defined namespace define its identifier.
// -----------------------------------------------------------------------------
#define BASE_USER_NAMESPACE

// -----------------------------------------------------------------------------
// Define when to use assertions.
// -----------------------------------------------------------------------------
#if (BASE_CFG == BASE_CFG_DEBUG)
#define BASE_HAS_ASSERTS                 BASE_TRUE
#elif (BASE_CFG == BASE_CFG_RELEASE)
#define BASE_HAS_ASSERTS                 BASE_FALSE
#endif // Assertions on/off

#endif // __INCLUDE_BASE_PRECONFIG_H_
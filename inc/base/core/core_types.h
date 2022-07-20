
////////////////////////////////////////////////////////////////////////////////
/// \file    core_types.h
///
/// \author  Joerg Sahm
/// \author  Credits to Andrei Alexandrescu.
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

#ifndef __INCLUDE_CORE_TYPES_H_
#define __INCLUDE_CORE_TYPES_H_

namespace CORE
{
    typedef signed char         S8;         // 8 bit signed integer
    typedef unsigned char       U8;         // 8 bit unsigned integer
    typedef signed short        S16;        // 16 bit signed integer
    typedef unsigned short      U16;        // 16 bit unsigned integer
    typedef signed long         S32;        // 32 bit signed integer
    typedef unsigned long       U32;        // 32 bit unsigned integer
    typedef signed long long    S64;        // 64 bit signed integer
    typedef unsigned long long  U64;        // 64 bit unsigned integer
    typedef float               F32;        // 32 bit floating point
    typedef double              F64;        // 64 bit floating point
    typedef unsigned int        Word;       // Represents the data bus size
    typedef int                 SWord;      // Represents the data bus size
    typedef unsigned long       Address;    // Represents the address bus size
    typedef signed long         SAddress;   // Represents the address bus size
    typedef void*               Ptr;        // Typeless pointer type
    typedef char                Char;       // Character type
    typedef wchar_t				WChar;      // Wide-character type
    typedef unsigned long long  FPos;       // File position
} // namespace CORE

namespace CORE
{
    const S8        c_MinS8                 = -128;                     // Minimum value signed 8 bit integer
    const S8        c_MaxS8                 =  127;                     // Maximum value signed 8 bit integer
    const U8        c_MinU8                 =  0;                       // Minimum value unsigned 8 bit integer
    const U8        c_MaxU8                 =  255;                     // Maximum value unsigned 8 bit integer
    const S16       c_MinS16                = -32768;                   // Minimum value signed 16 bit integer
    const S16       c_MaxS16                =  32767;                   // Maximum value signed 16 bit integer
    const U16       c_MinU16                =  0;                       // Minimum value unsigned 16 bit integer
    const U16       c_MaxU16                =  65535;                   // Maximum value unsigned 16 bit integer
    const S32       c_MinS32                =  0x80000000;              // Minimum value signed 32 bit integer
    const S32       c_MaxS32                =  0x7FFFFFFF;              // Maximum value signed 32 bit integer
    const U32       c_MinU32                =  0x00000000;              // Minimum value unsigned 32 bit integer
    const U32       c_MaxU32                =  0xFFFFFFFF;              // Maximum value unsigned 32 bit integer
    const S64       c_MinS64                =  0x8000000000000000LL;    // Minimum value signed 64 bit integer
    const S64       c_MaxS64                =  0x7FFFFFFFFFFFFFFFLL;    // Maximum value signed 64 bit integer
    const U64       c_MinU64                =  0x0000000000000000ULL;   // Minimum value unsigned 64 bit integer
    const U64       c_MaxU64                =  0xFFFFFFFFFFFFFFFFULL;   // Maximum value unsigned 64 bit integer
    
    const F32       c_MinFloat32            = -3.402823466E+38F;        // Minimum value 32 bit floating point
    const F32       c_MaxFloat32            =  3.402823466E+38F;        // Maximum value 32 bit floating point
    const F32       c_MinPositiveFloat32    =  1.175494351E-38F;        // Minimum positive value 32 bit floating point
    const F32       c_MaxPositiveFloat32    =  3.402823466E+38F;        // Maximum positive value 32 bit floating point
    const S32       c_MinExpFloat32         = -126;                     // Minimum exponent 32 bit floating point
    const S32       c_MaxExpFloat32         =  127;                     // Maximum exponent 32 bit floating point
        
    const F64       c_MinFloat64            = -1.7976931348623158E+308; // Minimum value 64 bit floating point
    const F64       c_MaxFloat64            =  1.7976931348623158E+308; // Maximum value 64 bit floating point
    const F64       c_MinPositiveFloat64    =  2.2250738585072014E-308; // Minimum positive value 64 bit floating point
    const F64       c_MaxPositiveFloat64    =  1.7976931348623158E+308; // Maximum positive value 64 bit floating point
    const S32       c_MinExpFloat64         = -1022;                    // Minimum exponent 64 bit floating point
    const S32       c_MaxExpFloat64         =  1023;                    // Maximum exponent 64 bit floating point
    
#if (BASE_ADDRESS_SIZE == BASE_ADDRESS_SIZE_32)
    const Address   c_MinAddress            = c_MinU32;                 // Minimum Address
    const Address   c_MaxAddress            = c_MaxU32;                 // Maximum Address
    const SAddress  c_MinSAddress           = c_MinS32;                 // Minimum signed Address
    const SAddress  c_MaxSAddress           = c_MaxS32;                 // Maximum signed Address
#elif (BASE_ADDRESS_SIZE == BASE_ADDRESS_SIZE_64)
    const Address   c_MinAddress            = c_MinU64;                 // Minimum Address
    const Address   c_MaxAddress            = c_MaxU64;                 // Maximum Address
    const SAddress  c_MinSAddress           = c_MinS64;                 // Minimum signed Address
    const SAddress  c_MaxSAddress           = c_MaxS64;                 // Maximum signed Address
#endif // 32 bit address or 64 bit address
} // namespace CORE

namespace CORE
{
    ////////////////////////////////////////////////////////////////////////////////
    /// \struct SNull
    ///
    /// \brief Represents a typeless entry.
    ///
    /// Andrei Alexandrescu
    /// "Modern C++ Design: Generic Programming and Design Patterns Applied"
    /// Addison-Wesley, 2001
    ////////////////////////////////////////////////////////////////////////////////
    struct SNull 
    {
    };

    ////////////////////////////////////////////////////////////////////////////////
    /// \struct SEmpty
    ///
    /// \brief Represents a class without any content.
    ///
    /// Andrei Alexandrescu
    /// "Modern C++ Design: Generic Programming and Design Patterns Applied"
    /// Addison-Wesley, 2001
    ////////////////////////////////////////////////////////////////////////////////
    struct SEmpty 
    {
    };
} // namespace CORE

namespace CORE
{
    inline bool operator == (const SEmpty&, const SEmpty&);
    inline bool operator != (const SEmpty&, const SEmpty&);
    inline bool operator <  (const SEmpty&, const SEmpty&);
    inline bool operator >  (const SEmpty&, const SEmpty&);
} // namespace CORE

namespace CORE
{
    inline bool operator == (const SEmpty&, const SEmpty&)
    {
        return true;
    }   

    // -----------------------------------------------------------------------------

    inline bool operator != (const SEmpty&, const SEmpty&)
    {
        return false;
    }   

    // -----------------------------------------------------------------------------

    inline bool operator < (const SEmpty&, const SEmpty&)
    {
        return false;
    }

    // -----------------------------------------------------------------------------

    inline bool operator > (const SEmpty&, const SEmpty&)
    {
        return false;
    }
} // namespace CORE

#endif // __INCLUDE_CORE_TYPES_H_
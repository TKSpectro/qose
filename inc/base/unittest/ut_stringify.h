
////////////////////////////////////////////////////////////////////////////////
/// \file    ut_stringify.h
///
/// \author  Joerg Sahm
/// \author  Credits to Dirk Steenpass.
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

#ifndef __INCLUDE_UT_STRINGIFY_H_
#define __INCLUDE_UT_STRINGIFY_H_

#include "base_defines.h"

#include CORE_INCLUDE_TYPES

#include <sstream>
#include <string>

namespace UT
{
    template <typename T>
    inline void Stringify(std::ostringstream& _rStream, const T&);

    template <>
    void Stringify(std::ostringstream& _rStream, const std::string& _rString);

    template <> 
    void Stringify(std::ostringstream& _rStream, const bool& _rValue);

    template <> 
    void Stringify(std::ostringstream& _rStream, const char& _rValue);

    template <>
    void Stringify(std::ostringstream& _rStream, const signed char& _rValue);

    template <>
    void Stringify(std::ostringstream& _rStream, const unsigned char& _rValue);

    template <>
    void Stringify(std::ostringstream& _rStream, const wchar_t& _rValue);

    template <>
    void Stringify(std::ostringstream& _rStream, const short int& _rValue);

    template <>
    void Stringify(std::ostringstream& _rStream, const unsigned short int& _rValue);

    template <>
    void Stringify(std::ostringstream& _rStream, const int& _rValue);

    template <>
    void Stringify(std::ostringstream& _rStream, const unsigned int& _rValue);

    template <>
    void Stringify(std::ostringstream& _rStream, const long int& _rValue);

    template <>
    void Stringify(std::ostringstream& _rStream, const unsigned long int& _rValue);

    template <>
    void Stringify(std::ostringstream& _rStream, const long long int& _rValue);

    template <>
    void Stringify(std::ostringstream& _rStream, const unsigned long long int& _rValue);

    template <>
    void Stringify(std::ostringstream& _rStream, const float& _rValue);

    template <>
    void Stringify(std::ostringstream& _rStream, const double& _rValue);

    template <>
    void Stringify(std::ostringstream& _rStream, const long double& _rValue);
} // namespace UT

namespace UT
{
    template <typename T>
    inline void Stringify(std::ostringstream& _rStream, T* const& _rpBuffer);

    template <>
    void Stringify(std::ostringstream& _rStream, const char* const& _rpBuffer);

    template <>
    void Stringify(std::ostringstream& _rStream, char* const& _rpBuffer);

    template <>
    void Stringify(std::ostringstream& _rStream, const void* const& _rpBuffer);
} // namespace UT

namespace UT
{
    void Stringify(std::ostringstream& _rStream, const char* _pBuffer);

    void Stringify(std::ostringstream& _rStream, const unsigned char* _pBuffer);

    void Stringify(std::ostringstream& _rStream, const signed char* _pBuffer);

    void Stringify(std::ostringstream& _rStream, const wchar_t* _pBuffer);
} // namespace UT

namespace UT
{
    template <typename T>
    inline void Stringify(std::ostringstream& _rStream, const T&)
    {
        _rStream << "not printable";
    }
} // namespace UT

namespace UT
{
    template <typename T>
    inline void Stringify(std::ostringstream& _rStream, T* const& _rpBuffer)
    { 
        Stringify(_rStream, static_cast<const void*>(_rpBuffer)); 
    }
} // namespace UT

#endif // __INCLUDE_UT_STRINGIFY_H_
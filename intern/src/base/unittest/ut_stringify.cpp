
////////////////////////////////////////////////////////////////////////////////
/// \file    ut_stringify.cpp
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

#include "base_defines.h"

#include UT_INCLUDE_STRINGIFY

namespace UT
{
    template <>
    void Stringify(std::ostringstream& _rStream, const std::string& _rString)
    {
        _rStream << _rString;
    }

    // -----------------------------------------------------------------------------

    template <> 
    void Stringify(std::ostringstream& _rStream, const bool& _rValue)
    {
        if (_rValue)
        {
            _rStream << "true";
        }
        else
        {
            _rStream << "false";
        }
    }

    // -----------------------------------------------------------------------------

    template <> 
    void Stringify(std::ostringstream& _rStream, const char& _rValue)
    {
        _rStream << _rValue;
    }

    // -----------------------------------------------------------------------------

    template <>
    void Stringify(std::ostringstream& _rStream, const signed char& _rValue)
    {
        _rStream << _rValue;
    }

    // -----------------------------------------------------------------------------

    template <>
    void Stringify(std::ostringstream& _rStream, const unsigned char& _rValue)
    {
        _rStream << _rValue;
    }

    // -----------------------------------------------------------------------------

    template <>
    void Stringify(std::ostringstream& _rStream, const wchar_t& _rValue)
    {
        _rStream << _rValue;
    }

    // -----------------------------------------------------------------------------

    template <>
    void Stringify(std::ostringstream& _rStream, const short& _rValue)
    {
        _rStream << _rValue;
    }

    // -----------------------------------------------------------------------------

    template <>
    void Stringify(std::ostringstream& _rStream, const unsigned short& _rValue)
    {
        _rStream << _rValue;
    }

    // -----------------------------------------------------------------------------

    template <>
    void Stringify(std::ostringstream& _rStream, const int& _rValue)
    {
        _rStream << _rValue;
    }

    // -----------------------------------------------------------------------------

    template <>
    void Stringify(std::ostringstream& _rStream, const unsigned int& _rValue)
    {
        _rStream << _rValue;
    }

    // -----------------------------------------------------------------------------

    template <>
    void Stringify(std::ostringstream& _rStream, const long& _rValue)
    {
        _rStream << _rValue;
    }

    // -----------------------------------------------------------------------------

    template <>
    void Stringify(std::ostringstream& _rStream, const unsigned long& _rValue)
    {
        _rStream << _rValue;
    }

    // -----------------------------------------------------------------------------

    template <>
    void Stringify(std::ostringstream& _rStream, const long long& _rValue)
    {
        _rStream << _rValue;
    }

    // -----------------------------------------------------------------------------

    template <>
    void Stringify(std::ostringstream& _rStream, const unsigned long long& _rValue)
    {
        _rStream << _rValue;
    }

    // -----------------------------------------------------------------------------

    template <>
    void Stringify(std::ostringstream& _rStream, const float& _rValue)
    {
        _rStream << _rValue;
    }

    // -----------------------------------------------------------------------------

    template <>
    void Stringify(std::ostringstream& _rStream, const double& _rValue)
    {
        _rStream << _rValue;
    }

    // -----------------------------------------------------------------------------

    template <>
    void Stringify(std::ostringstream& _rStream, const long double& _rValue)
    {
        _rStream << _rValue;
    }
} // namespace UT

namespace UT
{
    template <>
    void Stringify(std::ostringstream& _rStream, const char* const& _rpBuffer)
    {
        _rStream << _rpBuffer;
    }

    // -----------------------------------------------------------------------------

    template <>
    void Stringify(std::ostringstream& _rStream, char* const& _rpBuffer)
    {
        _rStream << _rpBuffer;
    }

    // -----------------------------------------------------------------------------

    template <>
    void Stringify(std::ostringstream& _rStream, const void* const& _rpBuffer)
    {
        BASE_UNUSED(_rpBuffer);

        _rStream << "not printable";
    }
} // namespace UT

namespace UT
{
    void Stringify(std::ostringstream& _rStream, const char* _pBuffer)
    {
        _rStream << _pBuffer;
    }

    // -----------------------------------------------------------------------------

    void Stringify(std::ostringstream& _rStream, const unsigned char* _pBuffer)
    {
        BASE_UNUSED(_pBuffer);

        _rStream << "not printable";
    }

    // -----------------------------------------------------------------------------

    void Stringify(std::ostringstream& _rStream, const signed char* _pBuffer)
    {
        BASE_UNUSED(_pBuffer);

        _rStream << "not printable";
    }

    // -----------------------------------------------------------------------------

    void Stringify(std::ostringstream& _rStream, const wchar_t* _pBuffer)
    {
        _rStream << _pBuffer;
    }
} // namespace UT


////////////////////////////////////////////////////////////////////////////////
/// \file    con_intrusivememberpolicy.h
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

#ifndef __INCLUDE_UT_TOOLS_H_
#define __INCLUDE_UT_TOOLS_H_

#include "base_defines.h"

#include UT_INCLUDE_STRINGIFY
#include UT_INCLUDE_SUITE

#include <exception>
#include <limits>
#include <sstream>
#include <string.h>

namespace UT
{
namespace Private
{
    struct SCheckThrowResult
    {
        enum Enum
        {
            NoThrow       = 0x00000000,
            ExpectedThrow = 0x00000001,
            BadThrow      = 0x00000002,
            EnumCount     = 0x00000003,
            Undefined     = 0xFFFFFFFF,
        };
    };
} // namespace Private
} // namespace UT

namespace UT
{
namespace Private
{
    template <class TLeft, class TRight>
    inline void CheckEqual(TLeft const& _rLeft, TRight const& _rRight);

    template <>
    inline void CheckEqual(const char* const& _rpLeft, const char* const& _rpRight);

    template <>
    inline void CheckEqual(const char* const& _rpLeft, char* const& _rpRight);

    template <>
    inline void CheckEqual(char* const& _rpLeft, const char* const& _rpRight);

    template <class TValue, class TTolerance>
    inline void CheckAbsClose(const TValue& _rLeft, const TValue& _rRight, const TTolerance& _rTolerance);

    template <class TValue, class TTolerance>
    inline void CheckRelClose(const TValue& _rLeft, const TValue& _rRight, const TTolerance& _rTolerance);

    template <class TValue, class TTolerance>
    void CheckRelCloseWeak(const TValue& _rLeft, const TValue& _rRight, const TTolerance& _rTolerance);
} // namespace Private
} // namespace UT

namespace UT
{
namespace Private
{
    template <typename TValue, typename TTolerance>
    class CAbsClose
    {
        public:

            typedef TTolerance XTolerance;

        public:

            inline CAbsClose(const TTolerance& _rTolerance);

            inline void SetTolerance(const XTolerance& _rTolerance);
            inline XTolerance GetTolerance() const;

            inline bool operator () (const TValue& _rX, const TValue& _rR) const;

        private:

            XTolerance m_Tolerance;
    };
} // namespace Private
} // namespace UT

namespace UT
{
namespace Private
{
    template <typename TTolerance>
    class CRelCloseBase
    {
        public:

            typedef TTolerance XTolerance;

        public:

            inline CRelCloseBase(const TTolerance& _rTolerance);

            inline void SetTolerance(const XTolerance& _rTolerance);
            inline XTolerance GetTolerance() const;

        protected:

            template <typename T>
            static inline T GetAbs(const T& _rX);

            template <typename T>
            static inline T SafeDivide(const T& _rX, const T& _rY);

        private:

            TTolerance m_Tolerance;
    };
} // namespace Private
} // namespace UT

namespace UT
{
namespace Private
{
    template <typename TValue, typename TTolerance>
    class CRelCloseStrong : public CRelCloseBase<TTolerance>
    {
        public:

            inline CRelCloseStrong(const TTolerance& _rTolerance);

            inline bool operator () (const TValue& _rX, const TValue& _rR) const;
    };
} // namespace Private
} // namespace UT

namespace UT
{
namespace Private
{
template <typename TValue, typename TTolerance>
class CRelCloseWeak: public CRelCloseBase<TTolerance>
{
    public:

        inline CRelCloseWeak(const TTolerance& _rTolerance);

        inline bool operator () (const TValue& _rX, const TValue& _rR) const;
};
} // namespace Private
} // namespace UT

namespace UT
{
namespace Private
{
    template <class TLeft, class TRight>
    inline void CheckEqual(TLeft const& _rLeft, TRight const& _rRight)
    {
        try
        {
            if (_rLeft != _rRight)
            {
                ::UT::Suite::LogFailure();

                std::ostringstream& rStream = ::UT::Suite::GetLogStream();
                ::UT::Stringify(rStream, _rLeft); 
                rStream << " == "; 
                ::UT::Stringify(rStream, _rRight); 
                rStream << "\n";

                ::UT::Suite::Log(rStream);
            }
        }
        catch (std::exception& _rException)
        {
            ::UT::Suite::LogFailure();

            std::ostringstream& rStream = ::UT::Suite::GetLogStream();
            rStream << "uncaught exception: ";

            ::UT::Suite::Log(rStream);
            ::UT::Suite::LogException(_rException.what());
        }
        catch (...)
        {
            ::UT::Suite::LogFailure();

            std::ostringstream& rStream = ::UT::Suite::GetLogStream();
            rStream << "uncaught exception\n";

            ::UT::Suite::Log(rStream);
        }
    }

    // -----------------------------------------------------------------------------

    template <>
    inline void CheckEqual(const char* const& _rpLeft, const char* const& _rpRight)
    {
        try
        {
            if (_rpLeft == _rpRight)
            {
                return;
            }

            if ((_rpLeft == 0) || (_rpRight == 0) || (!strcmp(_rpLeft, _rpRight)))
            {
                ::UT::Suite::LogFailure();

                std::ostringstream& rStream = ::UT::Suite::GetLogStream();
                ::UT::Stringify(rStream, _rpLeft); 
                rStream << " == "; 
                ::UT::Stringify(rStream, _rpRight); 
                rStream << "\n";

                ::UT::Suite::Log(rStream);
            }
        }
        catch (std::exception& _rException)
        {
            ::UT::Suite::LogFailure();

            std::ostringstream& rStream = ::UT::Suite::GetLogStream();
            rStream << "uncaught exception: ";

            ::UT::Suite::Log(rStream);
            ::UT::Suite::LogException(_rException.what());
        }
        catch (...)
        {
            ::UT::Suite::LogFailure();

            std::ostringstream& rStream = ::UT::Suite::GetLogStream();
            rStream << "uncaught exception\n";

            ::UT::Suite::Log(rStream);
        }
    }

    // -----------------------------------------------------------------------------

    template <>
    inline void CheckEqual(const char* const& _rpLeft, char* const& _rpRight)
    {
        CheckEqual(_rpLeft, static_cast<const char*>(_rpRight));
    }

    // -----------------------------------------------------------------------------

    template <>
    inline void CheckEqual(char* const& _rpLeft, const char* const& _rpRight)
    {
        CheckEqual(static_cast<const char*>(_rpLeft), _rpRight);
    }

    // -----------------------------------------------------------------------------

    template <class TValue, class TTolerance>
    inline void CheckAbsClose(const TValue& _rLeft, const TValue& _rRight, const TTolerance& _rTolerance)
    {
        try
        {
            CAbsClose<TValue, TTolerance> Test(_rTolerance);

            if (!Test(_rLeft, _rRight))
            {
                ::UT::Suite::LogFailure();

                std::ostringstream& rStream = ::UT::Suite::GetLogStream();
                ::UT::Stringify(rStream, _rLeft); 
                rStream << " ~= "; 
                ::UT::Stringify(rStream, _rRight); 
                rStream << " += "; 
                ::UT::Stringify(rStream, Test.GetTolerance()); 
                rStream << "\n";

                ::UT::Suite::Log(rStream);
            }
        }
        catch (std::exception& _rException)
        {
            ::UT::Suite::LogFailure();

            std::ostringstream& rStream = ::UT::Suite::GetLogStream();
            rStream << "uncaught exception: ";

            ::UT::Suite::Log(rStream);
            ::UT::Suite::LogException(_rException.what());
        }
        catch (...)
        {
            ::UT::Suite::LogFailure();

            std::ostringstream& rStream = ::UT::Suite::GetLogStream();
            rStream << "uncaught exception\n";

            ::UT::Suite::Log(rStream);
        }
    }

    // -----------------------------------------------------------------------------

    template <class TValue, class TTolerance>
    inline void CheckRelClose(const TValue& _rLeft, const TValue& _rRight, const TTolerance& _rTolerance)
    {
        try
        {
            CRelCloseStrong<TValue, TTolerance> Test(_rTolerance);

            if (!Test(_rLeft, _rRight))
            {
                ::UT::Suite::LogFailure();

                std::ostringstream& rStream = ::UT::Suite::GetLogStream();
                ::UT::Stringify(rStream, _rLeft); 
                rStream << " ~= "; 
                ::UT::Stringify(rStream, _rRight); 
                rStream << " |rel_s| "; 
                ::UT::Stringify(rStream, Test.GetTolerance()); 
                rStream << "\n";

                ::UT::Suite::Log(rStream);
            }
        }
        catch (std::exception& _rException)
        {
            ::UT::Suite::LogFailure();

            std::ostringstream& rStream = ::UT::Suite::GetLogStream();
            rStream << "uncaught exception: ";

            ::UT::Suite::Log(rStream);
            ::UT::Suite::LogException(_rException.what());
        }
        catch (...)
        {
            ::UT::Suite::LogFailure();

            std::ostringstream& rStream = ::UT::Suite::GetLogStream();
            rStream << "uncaught exception\n";

            ::UT::Suite::Log(rStream);
        }
    }

    // -----------------------------------------------------------------------------

    template <class TValue, class TTolerance>
    inline void CheckRelCloseWeak(const TValue& _rLeft, const TValue& _rRight, const TTolerance& _rTolerance)
    {
        try
        {
            CRelCloseWeak<TValue, TTolerance> Test(_rTolerance);

            if (!Test(_rLeft, _rRight))
            {
                ::UT::Suite::LogFailure();

                std::ostringstream& rStream = ::UT::Suite::GetLogStream();
                ::UT::Stringify(rStream, _rLeft); 
                rStream << " ~= "; 
                ::UT::Stringify(rStream, _rRight); 
                rStream << " |rel_w| "; 
                ::UT::Stringify(rStream, Test.GetTolerance()); 
                rStream << "\n";

                ::UT::Suite::Log(rStream);
            }
        }
        catch (std::exception& _rException)
        {
            ::UT::Suite::LogFailure();

            std::ostringstream& rStream = ::UT::Suite::GetLogStream();
            rStream << "uncaught exception: ";

            ::UT::Suite::Log(rStream);
            ::UT::Suite::LogException(_rException.what());
        }
        catch (...)
        {
            ::UT::Suite::LogFailure();

            std::ostringstream& rStream = ::UT::Suite::GetLogStream();
            rStream << "uncaught exception\n";

            ::UT::Suite::Log(rStream);
        }
    }
} // namespace Private
} // namespace UT

namespace UT
{
namespace Private
{
    template <typename TValue, typename TTolerance>
    inline CAbsClose<TValue, TTolerance>::CAbsClose(const TTolerance& _rTolerance)
        : m_Tolerance(_rTolerance < 0 ? -_rTolerance : _rTolerance)
    {
    }

    // -----------------------------------------------------------------------------

    template <typename TValue, typename TTolerance>
    inline void CAbsClose<TValue, TTolerance>::SetTolerance(const XTolerance& _rTolerance) 
    { 
        m_Tolerance = _rTolerance < 0 ? -_rTolerance : _rTolerance; 
    }

    // -----------------------------------------------------------------------------

    template <typename TValue, typename TTolerance>
    inline typename CAbsClose<TValue, TTolerance>::XTolerance CAbsClose<TValue, TTolerance>::GetTolerance() const 
    { 
        return m_Tolerance; 
    }

    // -----------------------------------------------------------------------------

    template <typename TValue, typename TTolerance>
    inline bool CAbsClose<TValue, TTolerance>::operator () (const TValue& _rX, const TValue& _rY) const
    {
        TValue Difference(_rY - _rX);

        if (Difference < 0) 
        {
            Difference = -Difference;
        }

        return Difference < m_Tolerance;
    }
} // namespace Private
} // namespace UT

namespace UT
{
namespace Private
{
    template <typename TTolerance>
    inline CRelCloseBase<TTolerance>::CRelCloseBase(const TTolerance& _rTolerance)
        : m_Tolerance(GetAbs(_rTolerance)) 
    {
    }

    // -----------------------------------------------------------------------------

    template <typename TTolerance>
    inline void CRelCloseBase<TTolerance>::SetTolerance(const XTolerance& _rTolerance) 
    { 
        m_Tolerance = GetAbs(_rTolerance); 
    }

    // -----------------------------------------------------------------------------

    template <typename TTolerance>
    inline typename CRelCloseBase<TTolerance>::XTolerance CRelCloseBase<TTolerance>::GetTolerance() const 
    { 
        return m_Tolerance; 
    }

    // -----------------------------------------------------------------------------

    template <typename TTolerance>
    template <typename T>
    inline T CRelCloseBase<TTolerance>::GetAbs(const T& _rX) 
    {  
        return _rX < 0 ? -_rX : _rX; 
    }

    // -----------------------------------------------------------------------------

    template <typename TTolerance>
    template <typename T>
    inline T CRelCloseBase<TTolerance>::SafeDivide(const T& _rX, const T& _rY)
    {
        typedef std::numeric_limits<T> CLimit;

        if ((_rY < 1) && (_rX > _rY * CLimit::max()))
        {
            return CLimit::max();
        }

        if ((!_rX) || ((_rY > 1) && (_rX < _rY * CLimit::min())))
        {
            return 0;
        }

        return _rX / _rY;
    }
} // namespace Private
} // namespace UT

namespace UT
{
namespace Private
{
    template <typename TValue, typename TTolerance>
    inline CRelCloseStrong<TValue, TTolerance>::CRelCloseStrong(const TTolerance& _rTolerance)
        : CRelCloseBase<TTolerance>(_rTolerance)
    {
    }

    // -----------------------------------------------------------------------------

    template <typename TValue, typename TTolerance>
    inline bool CRelCloseStrong<TValue, TTolerance>::operator () (const TValue& _rX, const TValue& _rR) const
    {
        typedef CRelCloseBase<TTolerance> CBase;

        TValue Difference (CBase::GetAbs(_rR - _rX));
        TValue Difference1(CBase::SafeDivide(Difference, CBase::GetAbs(_rX)));
        TValue Difference2(CBase::SafeDivide(Difference, CBase::GetAbs(_rR)));

        return (Difference1 < GetTolerance()) && (Difference2 < GetTolerance());
    }
} // namespace Private
} // namespace UT

namespace UT
{
namespace Private
{
    template <typename TValue, typename TTolerance>
    CRelCloseWeak<TValue, TTolerance>::CRelCloseWeak(const TTolerance& _rTolerance)
        : CRelCloseBase<TTolerance>(_rTolerance) 
    {

    }

    // -----------------------------------------------------------------------------

    template <typename TValue, typename TTolerance>
    bool CRelCloseWeak<TValue, TTolerance>::operator()(const TValue& _rX, const TValue& _rR) const
    {
        typedef CRelCloseBase<TTolerance> CBase;

        TValue Difference (CBase::GetAbs(_rR - _rX));
        TValue Difference1(CBase::SafeDivide(Difference, CBase::GetAbs(_rX)));
        TValue Difference2(CBase::SafeDivide(Difference, CBase::GetAbs(_rR)));

        return (Difference1 < GetTolerance()) || (Difference2 < GetTolerance());
    }
} // namespace Private
} // namespace UT

#endif // __INCLUDE_UT_TOOLS_H_
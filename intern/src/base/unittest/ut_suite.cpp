
////////////////////////////////////////////////////////////////////////////////
/// \file    ut_suite.cpp
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

#include CORE_INCLUDE_ASSERT

#include IO_INCLUDE_DEBUG

#include PAT_INCLUDE_UNCOPYABLE

#include UT_INCLUDE_SUITE

#include <exception>
#include <iostream>

namespace
{
    // -----------------------------------------------------------------------------
    // Declaration CLogWriter.
    // -----------------------------------------------------------------------------
    class CLogWriter : private PAT::CUncopyable
    {
        public:

            CLogWriter(std::ostream* _pOutputStream);

            void SetStream(std::ostream* _pOutputStream);
            bool HasStream() const;

            void operator () (std::ostringstream& _rStream);

        private:

            std::ostream* m_pOutputStream;
            IO::CDebug    m_Debug;
    };
} // namespace

namespace
{
    // -----------------------------------------------------------------------------
    // Declaration CSuite.
    // -----------------------------------------------------------------------------
    class CSuite : private PAT::CUncopyable
    {
        public:

            static const size_t s_FunctionCountPerTest = 2;

        public:

            CSuite();
           ~CSuite();

        public:

            void SetName(const CORE::Char* _pName);
            const CORE::Char* GetName() const;

            void Reset(std::ostream* _pStream);

            void RegisterTest(UT::FTestFunction _TestFunction);
            void RunTests();

            void SetTestSource(const CORE::Char* _pFilename, const CORE::Char* _pFunctionName, int _LineNumber);

            void LogStatistics();
            void LogFailure();
            void LogException(const CORE::Char* _pException);
            void LogCondition(const CORE::Char* _pCondition);
            void Log(std::ostringstream& _rStream);

            std::ostringstream& GetLogStream();

            size_t GetTestCount() const;
            size_t GetFailedTestCount() const;

        private:

            static const size_t s_PageSize             = 0x00001000;
            static const size_t s_FunctionCountPerPage = (s_PageSize - sizeof(void*)) / sizeof(UT::FTestFunction);

        private:

            struct SPage
            {
                SPage*            m_pNext;
                UT::FTestFunction m_Functions[s_FunctionCountPerPage];
            };

        private:

            SPage*             m_pFirstPage;
            SPage*             m_pLastPage;
            size_t             m_FunctionCount;
            size_t             m_FailedTestCount;
            size_t             m_FailedCheckCount;
            int                m_CurrentLineNumber;
            std::string        m_CurrentFunctionName;
            std::string        m_CurrentFileName;
            std::string        m_Name;
            std::ostringstream m_LogStream;
            CLogWriter         m_LogWriter;

        private:

            void ResetFailedCheckCount();
            void ResetCounters();
    };

    // -----------------------------------------------------------------------------

    CSuite& GetSuite();
} // namespace

namespace
{
    // -----------------------------------------------------------------------------
    // Implementation CLogWriter.
    // -----------------------------------------------------------------------------
    CLogWriter::CLogWriter(std::ostream* _pOutputStream)
        : m_pOutputStream(_pOutputStream)
    {
    }

    // -----------------------------------------------------------------------------

    void CLogWriter::SetStream(std::ostream* _pOutputStream)
    {
        m_pOutputStream = _pOutputStream;
    }

    // -----------------------------------------------------------------------------

    bool CLogWriter::HasStream() const
    {
        return m_pOutputStream != 0;
    }

    // -----------------------------------------------------------------------------

    void CLogWriter::operator () (std::ostringstream& _rStream)
    {
        if (HasStream())
        {
            *m_pOutputStream << _rStream.str().c_str();
        }
        else
        {
            m_Debug.Write(_rStream.str().c_str());
        }
    }
} // namespace

namespace
{
    // -----------------------------------------------------------------------------
    // Implementation CSuite.
    // -----------------------------------------------------------------------------
    CSuite::CSuite()
        : m_pFirstPage      (0)
        , m_pLastPage       (0)
        , m_FunctionCount   (0)
        , m_FailedTestCount (0)
        , m_FailedCheckCount(0)
        , m_LogWriter       (0)
    {
        SetName("Default Suite");
    }

    // -----------------------------------------------------------------------------

    CSuite::~CSuite()
    {
        SPage* pPage;

        while (m_pFirstPage != 0)
        {
            pPage = m_pFirstPage->m_pNext;

            free(m_pFirstPage);

            m_pFirstPage = pPage;
        }
    }

    // -----------------------------------------------------------------------------

    void CSuite::Reset(std::ostream* _pStream)
    {
        ResetCounters();

        m_LogWriter.SetStream(_pStream);
    }

    // -----------------------------------------------------------------------------

    void CSuite::ResetFailedCheckCount()
    {
        m_FailedCheckCount = 0;
    }

    // -----------------------------------------------------------------------------

    void CSuite::ResetCounters()
    {
        ResetFailedCheckCount();

        m_FailedTestCount = 0;
    }

    // -----------------------------------------------------------------------------

    void CSuite::SetName(const CORE::Char* _pName)
    {
        m_Name = _pName;
    }

    // -----------------------------------------------------------------------------

    const CORE::Char* CSuite::GetName() const
    {
        return m_Name.c_str();
    }

    // -----------------------------------------------------------------------------

    void CSuite::RegisterTest(UT::FTestFunction _TestFunction)
    {
        size_t FunctionIndex;
        SPage* pPage;

        FunctionIndex = m_FunctionCount % s_FunctionCountPerPage;

        // -----------------------------------------------------------------------------
        // Check if we have to allocate a new page.
        // -----------------------------------------------------------------------------
        if (FunctionIndex == 0)
        {
            if (m_pFirstPage == 0)
            {
                m_pFirstPage = reinterpret_cast<SPage*>(malloc(s_PageSize));
                m_pFirstPage->m_pNext = 0;

                m_pLastPage = m_pFirstPage;
                m_pLastPage->m_pNext = 0;
            }
            else
            {
                pPage = reinterpret_cast<SPage*>(malloc(s_PageSize));
                pPage->m_pNext = 0;

                m_pLastPage->m_pNext = pPage;
                m_pLastPage          = pPage;
            }
        }

        m_pLastPage->m_Functions[FunctionIndex] = _TestFunction;

        ++ m_FunctionCount;
    }

    // -----------------------------------------------------------------------------

    void CSuite::RunTests()
    {
        size_t FunctionIndex;
        size_t FunctionCount;
        SPage* pPage;

        FunctionIndex = 0;
        FunctionCount = 0;
        pPage         = m_pFirstPage;

        while (FunctionCount < m_FunctionCount)
        {
            ResetFailedCheckCount();

            FunctionIndex = FunctionCount % s_FunctionCountPerPage;

            UT::FTestFunction& rTestFunction = pPage->m_Functions[FunctionIndex];

            try
            {
                rTestFunction();
            }
            catch (std::exception& _rException)
            {
                LogFailure();
                LogException(_rException.what());
            }
            catch (...)
            {
                LogFailure();
                LogException("uncaught exception");
            }

            if (m_FailedCheckCount > 0)
            {
                ++ m_FailedTestCount;
            }

            if ((FunctionIndex + 1) == s_FunctionCountPerPage)
            {
                pPage = pPage->m_pNext;
            }

            ++ FunctionCount;
        }

        LogStatistics();
    }

    // -----------------------------------------------------------------------------

    void CSuite::SetTestSource(const CORE::Char* _pFilename, const CORE::Char* _pFunctionName, int _LineNumber)
    {
        m_CurrentLineNumber   = _LineNumber;
        m_CurrentFunctionName = _pFunctionName;
        m_CurrentFileName     = _pFilename;
    }

    // -----------------------------------------------------------------------------

    void CSuite::LogStatistics()
    {
        std::ostringstream& rStream = GetLogStream();

        rStream << GetName() << ": " << GetFailedTestCount() << " tests failed out of " << GetTestCount() << "\n";

        m_LogWriter(rStream);

        rStream.str(""); rStream.clear();
    }

    // -----------------------------------------------------------------------------

    void CSuite::LogFailure()
    {
        ++ m_FailedCheckCount;

        std::ostringstream& rStream = GetLogStream();

        rStream << "error: test case '" << m_CurrentFunctionName << "' failed \n";
        rStream << m_CurrentFileName << " (Line " << m_CurrentLineNumber << ")\n";

        m_LogWriter(rStream);

        rStream.str(""); rStream.clear();
    }

    // -----------------------------------------------------------------------------

    void CSuite::LogException(const CORE::Char* _pException)
    {
        CORE_ASSERTM(_pException != 0, "Exception to log is 0.");

        std::ostringstream& rStream = GetLogStream();

        rStream << "uncaught exception: '" << _pException << "'\n";

        m_LogWriter(rStream);

        rStream.str(""); rStream.clear();
    }

    // -----------------------------------------------------------------------------

    void CSuite::LogCondition(const CORE::Char* _pCondition)
    {
        CORE_ASSERTM(_pCondition != 0, "Condition to log is 0.");

        std::ostringstream& rStream = GetLogStream();

        rStream << "condition: '" << _pCondition << "'\n";

        m_LogWriter(rStream);

        rStream.str(""); rStream.clear();
    }

    // -----------------------------------------------------------------------------

    void CSuite::Log(std::ostringstream& _rStream)
    {
        m_LogWriter(_rStream);

        _rStream.str(""); _rStream.clear();
    }

    // -----------------------------------------------------------------------------

    std::ostringstream& CSuite::GetLogStream()
    {
        return m_LogStream;
    }

    // -----------------------------------------------------------------------------

    size_t CSuite::GetTestCount() const
    {
        CORE_ASSERTM((m_FunctionCount % s_FunctionCountPerTest) == 0, "Invalid count of test functions.");

        return m_FunctionCount / s_FunctionCountPerTest;
    }

    // -----------------------------------------------------------------------------

    size_t CSuite::GetFailedTestCount() const
    {
        return m_FailedTestCount;
    }

    // -----------------------------------------------------------------------------

    CSuite& GetSuite()
    {
        static CSuite s_Suite;

        return s_Suite;
    }
} // namespace

namespace UT
{
namespace Suite
{
    void SetName(const char* _pName)
    {
        GetSuite().SetName(_pName);
    }

    // -----------------------------------------------------------------------------

    const char* GetName()
    {
        return GetSuite().GetName();
    }

    // -----------------------------------------------------------------------------

    void Reset(std::ostream* _pStream)
    {
        GetSuite().Reset(_pStream);
    }

    // -----------------------------------------------------------------------------

    void RegisterTest(FTestFunction _Test)
    {
        GetSuite().RegisterTest(_Test);
    }

    // -----------------------------------------------------------------------------

    void RunTests()
    {
        GetSuite().RunTests();
    }

    // -----------------------------------------------------------------------------

    void SetTestSource(const char* _pFilename, const char* _pFunctionName, int _LineNumber)
    {
        GetSuite().SetTestSource(_pFilename, _pFunctionName, _LineNumber);
    }

    // -----------------------------------------------------------------------------

    void LogFailure()
    {
        GetSuite().LogFailure();
    }

    // -----------------------------------------------------------------------------

    void LogException(const CORE::Char* _pException)
    {
        GetSuite().LogException(_pException);
    }

    // -----------------------------------------------------------------------------

    void LogCondition(const CORE::Char* _pCondition)
    {
        GetSuite().LogCondition(_pCondition);
    }

    // -----------------------------------------------------------------------------

    void Log(std::ostringstream& _rStream)
    {
        GetSuite().Log(_rStream);
    }

    // -----------------------------------------------------------------------------

    std::ostringstream& GetLogStream()
    {
        return GetSuite().GetLogStream();
    }

    // -----------------------------------------------------------------------------

    size_t GetTestCount()
    {
        return GetSuite().GetTestCount();
    }

    // -----------------------------------------------------------------------------

    size_t GetFailedTestCount()
    {
        return GetSuite().GetFailedTestCount();
    }
} // namespace Suite
} // namespace UT
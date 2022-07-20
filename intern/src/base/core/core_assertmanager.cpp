
////////////////////////////////////////////////////////////////////////////////
/// \file    core_asserthandler.cpp
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

#if (BASE_HAS_ASSERTS == BASE_TRUE)

#include "base_defines.h"

#include CORE_INCLUDE_ASSERTHANDLER
#include CORE_INCLUDE_ASSERTMANAGER

namespace
{
    class CAssertManager
    {
        public:

            CAssertManager();
           ~CAssertManager();

        public:

            int Handle(const CORE::Char* _pCondition, const CORE::Char* _pMessage, const CORE::Char* _pFile, int _Line, int _Extra);

            void SetAssertHandler(CORE::CAssertHandler* _pAssertHandler);
            CORE::CAssertHandler* GetAssertHandler();

            void SetAssertsEnabled(bool _Flag);
            bool AreAssertsEnabled();

        private:

            CORE::CAssertHandler* m_pAssertHandler;
            bool                  m_AreAssertsEnabled;
    };

    CAssertManager& GetManager();
} // namespace

namespace
{
    CAssertManager::CAssertManager()
        : m_pAssertHandler   (0)
        , m_AreAssertsEnabled(true)
    {
    }

    // -----------------------------------------------------------------------------

    CAssertManager::~CAssertManager()
    {
    }

    // -----------------------------------------------------------------------------

    int CAssertManager::Handle(const CORE::Char* _pCondition, const CORE::Char* _pMessage, const CORE::Char* _pFile, int _Line, int _Extra)
    { 
        if (AreAssertsEnabled())
        {
            if (m_pAssertHandler != 0)
            {
                return m_pAssertHandler->Handle(_pCondition, _pMessage, _pFile, _Line, _Extra);
            }

            return CORE::CDefaultAssertHandler().Handle(_pCondition, _pMessage, _pFile, _Line, _Extra);
        }

        return -1;
    }

    // -----------------------------------------------------------------------------

    void CAssertManager::SetAssertHandler(CORE::CAssertHandler* _pHandler)
    {
        m_pAssertHandler = _pHandler;
    }

    // -----------------------------------------------------------------------------

    CORE::CAssertHandler* CAssertManager::GetAssertHandler()
    {
        return m_pAssertHandler;
    }

    // -----------------------------------------------------------------------------

    void CAssertManager::SetAssertsEnabled(bool _Flag)
    {
        m_AreAssertsEnabled = _Flag;
    }

    // -----------------------------------------------------------------------------

    bool CAssertManager::AreAssertsEnabled()
    {
        return m_AreAssertsEnabled;
    }

    // -----------------------------------------------------------------------------

    CAssertManager& GetManager()
    {
        static CAssertManager s_Manager;

        return s_Manager;
    }
}

namespace CORE
{
    namespace Assert
    {
        int Handle(const Char* _pCondition, const Char* _pMessage, const Char* _pFile, int _Line, int _Extra)
        {
            return GetManager().Handle(_pCondition, _pMessage, _pFile, _Line, _Extra);
        }

        // -----------------------------------------------------------------------------

        void SetAssertHandler(CAssertHandler* _pHandler)
        {
            GetManager().SetAssertHandler(_pHandler);
        }

        // -----------------------------------------------------------------------------

        CAssertHandler* GetAssertHandler()
        {
            return GetManager().GetAssertHandler();
        }

        // -----------------------------------------------------------------------------

        void SetAssertsEnabled(bool _Flag)
        {
            GetManager().SetAssertsEnabled(_Flag);
        }

        // -----------------------------------------------------------------------------

        bool AreAssertsEnabled()
        {
            return GetManager().AreAssertsEnabled();
        }
    } // namespace Assert
} // namespace CORE

#endif // Has assertions


////////////////////////////////////////////////////////////////////////////////
/// \file    pat_uncopyable.h
///
/// \author  Joerg Sahm
/// \author  Credits to Scott Meyers.
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

#ifndef __INCLUDE_PAT_UNCOPYABLE_H_
#define __INCLUDE_PAT_UNCOPYABLE_H_

namespace PAT
{
    class CUncopyable
    {
        protected:

            inline CUncopyable();
            inline ~CUncopyable();

        private:

            CUncopyable(const CUncopyable&);

            CUncopyable& operator = (const CUncopyable&);
    };
} // namespace PAT

namespace PAT
{
    inline CUncopyable::CUncopyable()
    {
    }

    // -----------------------------------------------------------------------------

    inline CUncopyable::~CUncopyable()
    {
    }
} // namespace PAT

#endif // __INCLUDE_PAT_UNCOPYABLE_H_
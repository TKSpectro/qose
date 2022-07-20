#include "unittest/ut_test.h"
#include <list>

using CIntList = std::list<int>;

UT_TEST(StdListConstruct)
{
    CIntList List;

    UT_CHECK(List.empty());
    UT_CHECK(List.size() == 0);
}

UT_TEST(StdListPushBack)
{
    CIntList List;

    UT_CHECK(List.empty());
    UT_CHECK(List.size() == 0);

    List.push_back(19);

    UT_CHECK(!List.empty());
    UT_CHECK(List.size() == 1);
    UT_CHECK(List.front() == 19);
    UT_CHECK(List.back() == 19);
    UT_CHECK(*List.begin() == 19);

    List.push_back(2);
}

UT_TEST(LongStdListPushBack)
{
    CIntList List;

    UT_CHECK(List.empty());
    UT_CHECK(List.size() == 0);

    int Values[] = { 19, 2, 22, 1, 5, 16 };

    for(int Index = 0; Index < std::size(Values); ++ Index)
    {
        List.push_back(Values[Index]);

        UT_CHECK(!List.empty());
        UT_CHECK(List.size() == (Index + 1));

        CIntList::iterator Iterator = List.begin();

        for(int IndexOfTestValues = 0; IndexOfTestValues <= Index; ++ IndexOfTestValues)
        {
            UT_CHECK(*Iterator == Values[IndexOfTestValues]);

            ++Iterator;
        }

        UT_CHECK(List.front() == Values[0]);
        UT_CHECK(List.back() == Values[Index]);

    }
}


// ------------------------------------
// Current video 2022-06-17
// ------------------------------------
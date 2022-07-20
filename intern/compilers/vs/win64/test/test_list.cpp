#include "unittest/ut_test.h"
#include <list>
#include <array>

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



using CArray = std::array<int, 4>;


UT_TEST(Test1)
{
    //std::array<int, 3> Test =  {1,2,3}
    CArray Array = {1,2,3,4};

    Array.at(1);
    Array[1];
    Array.empty();
    Array.size();
}
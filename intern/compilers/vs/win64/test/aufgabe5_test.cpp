#include "unittest/ut_test.h"
#include "aufgabe5.h"

UT_TEST(PersonDefaultConstructor)
{
    CPerson Person;

    UT_CHECK(Person.GetFirstname() == nullptr);
    UT_CHECK(Person.GetLastname() == nullptr);
    UT_CHECK(Person.GetAge() == -1);
}

UT_TEST(PersonSetterGetter)
{
    CPerson Person;

    char* Firstname = new char[strlen("Tom") + 1];
    strcpy_s(Firstname, strlen("Tom") + 1, "Tom");

    char* Lastname = new char[strlen("Käppler") + 1];
    strcpy_s(Lastname, strlen("Käppler") + 1, "Käppler");

    Person.SetFirstname(Firstname);
    Person.SetLastname(Lastname);
    Person.SetAge(22);

    UT_CHECK(strcmp(Person.GetFirstname(), "Tom") == 0);
    UT_CHECK(strcmp(Person.GetLastname(), "Käppler") == 0);
    UT_CHECK(Person.GetAge() == 22);
}
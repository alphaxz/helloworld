#include "TestHelloWorld.h"

CPPUNIT_TEST_SUITE_REGISTRATION (TestHelloWorld);

void TestHelloWorld::setUp()
{
    mHW = new HelloWorld();
}

void TestHelloWorld::tearDown()
{
    delete mHW;
}

void TestHelloWorld::testDo()
{
    CPPUNIT_ASSERT_NO_THROW (mHW->Do());
}

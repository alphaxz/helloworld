#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "HelloWorld.h"

class TestHelloWorld: public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestHelloWorld);
    CPPUNIT_TEST(testDo);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp (void);
    void tearDown (void);

protected: 
    void testDo (void);

private: 
    HelloWorld* mHW;
};

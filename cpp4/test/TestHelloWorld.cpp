#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>

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

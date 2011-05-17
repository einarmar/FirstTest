#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <getopt.h>
#include <fcntl.h>
#include <sys/mman.h>
#include "arabic_roman.h"

#include "unittest++/UnitTest++.h"
#include "unittest++/XmlTestReporter.h"

using namespace std;

static string outfile("test_arabic_roman.xml");


// Defines some basic test cases
SUITE(test_suite_for_arabic_roman)
{
    TEST(test_1)
    {
        arabic_roman* libPtr = new arabic_roman("arabic_roman");
        CHECK(libPtr);
        CHECK( NULL != libPtr->toOnes(2));
        delete libPtr;
    }

    TEST(test_2)
	{
		arabic_roman* libPtr = new arabic_roman("arabic_roman");
		CHECK(libPtr);
		CHECK( NULL != libPtr->toTens(9));
		delete libPtr;
	}

    TEST(test_3)
	{
		arabic_roman* libPtr = new arabic_roman("arabic_roman");
		CHECK(libPtr);
		CHECK( NULL != libPtr->toHundreds(3));
		delete libPtr;
	}

    TEST(test_4)
	{
		arabic_roman* libPtr = new arabic_roman("arabic_roman");
		CHECK(libPtr);
		CHECK_EQUAL( "CCCXXIV", libPtr->doConvert(324));
		delete libPtr;
	}

    TEST(test_5)
	{
		arabic_roman* libPtr = new arabic_roman("arabic_roman");
		CHECK(libPtr);
		CHECK_EQUAL( "CCCXXIV", libPtr->doConvert(3));
		delete libPtr;
	}

    TEST(test_6)
	{
    	int32_t testValues[] = { 1,2,3,4,5,6,7,8,9,10,20,30,40,50,60,70,80,90,100,21,33,67,83,14,39,41,98,49,92 };
    	int32_t arraySize = sizeof( testValues ) / 4;
    	printf("arraysize: %d\n", arraySize );
		arabic_roman* libPtr = new arabic_roman("arabic_roman");
		CHECK(libPtr);
		int32_t iCnt=0;
		do
		{
			const char* romanValue = libPtr->doConvert(testValues[iCnt]);
			printf("Value[%d]: %d = %s\n", iCnt, testValues[iCnt], romanValue);
			CHECK( NULL != romanValue);
		}while (++iCnt < arraySize);
		delete libPtr;
	}
//
//    TEST(test_2)
//    {
//        CHECK_CLOSE(1,2,3);
//    }

    //TODO Add your test cases here
    //...
    //...

}


int main(int argc, char **argv)
{

    mlockall(MCL_CURRENT | MCL_FUTURE);

    string command = "rm -rf " + outfile;
    system (command.c_str());

//    arabic_roman* libPtr = new arabic_roman("arabic_roman");
//    libPtr->doConvert( 12 );
    cout << "Results will be in the file " << outfile << "\nTesting...\n";
    ofstream f(outfile.c_str(), fstream::app | fstream::out);

    UnitTest::XmlTestReporter reporter(f);
    UnitTest::TestRunner runner(reporter);

    int ret = runner.RunTestsIf(UnitTest::Test::GetTestList(), NULL, UnitTest::True(), 0);

    cout << "Finished successfully\n";
    if (ret>0)
        cout << "!!! " << ret << " test(s) failed !!!\n";

    munlockall();
    return ret;
}

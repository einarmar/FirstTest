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
		CHECK( NULL != libPtr->toHundreds(30));
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

    arabic_roman* libPtr = new arabic_roman("arabic_roman");
    libPtr->doConvert( 123 );
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

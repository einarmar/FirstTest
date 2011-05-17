#include <stdlib.h>
#include "mversion.h"

static struct mversion _mversion_version = {
    .structversion = MVERSION,
    .projecttype = "SOLIB",
    .svnrev = 0,
    .localmodifications= 1,
    .compname = "arabic_roman",
    .builder = "einar",
    .machine = "einar-laptop",
    .url = "",
    .date = "Tue May 17 15:12:17 GMT 2011",
    .major = 0,
    .minor = 1,
    .patch = 0,
    .buildnumber = 0,
    .extraversion = "",
};

static void __attribute__((constructor)) _versioninit( void )
{
    mversion_add( &_mversion_version );
}

static void __attribute__((destructor)) _versiondeinit( void )
{
    mversion_remove( &_mversion_version );
}

const char * arabic_roman_svnversion( void )
{
	return "This function is no longer supported. Please use mversion_fprintf() in mversion library."
		"0.1.0-0";
}

const char * arabic_roman_longsvnversion( void )
{
	return "This function is no longer supported. Please use mversion_fprintf() in mversion library."
		"arabic_roman-0.1.0-0-einar-Tue May 17 15:12:17 GMT 2011";
}

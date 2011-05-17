/**
 @file arabic_roman.cpp

 @author Your-name-here <your.email.here@marel.com>

 <b>
 Copyright (c) 2011 Marel Food Systems
 Proprietary material, all rights reserved, use or disclosure forbidden.
 </b>
 */

// includes -------------------------------------------------------------------
#include "arabic_roman.h"

// defines --------------------------------------------------------------------
using namespace std;

// macros ---------------------------------------------------------------------

// forward declarations -------------------------------------------------------

// typedefs -------------------------------------------------------------------

// global variables -----------------------------------------------------------


// local prototypes -----------------------------------------------------------


//--------------------------------------------------------------------
// Public functions
//--------------------------------------------------------------------

/**
 * Constructor
 */
arabic_roman::arabic_roman( std::string appName M_UU ) :
    MarelCppApp( appName )
{
    //TODO Implement your construction time initialization
    //...
    //...
}

/**
 * Destructor
 */
arabic_roman::~arabic_roman()
{
    //TODO Implement your cleanup here
    //...
    //...
}

int32_t
arabic_roman::initialize( int32_t argc M_UU, char **argv M_UU )
{
   std::cout << endl << __PRETTY_FUNCTION__ << std::endl;

   //TODO Implement your initialization functionality here
   //...
   //...

   return 0;
}

void
arabic_roman::deinitialize()
{
    std::cout << endl << __PRETTY_FUNCTION__ << std::endl;

    //TODO Implement your deinitialization functionality here
    //...
    //...
}

void
arabic_roman::timeout()
{
    std::cout << endl << __PRETTY_FUNCTION__ << std::endl;

    //TODO Implement your timeout functionality here
    //...
    //...
}

int32_t
arabic_roman::onTmDead( mqs_streamid_t sid M_UU, const char * ep M_UU )
{
    std::cout << endl << __PRETTY_FUNCTION__ << std::endl;

    //TODO Implement your ticker master exit functionality here
    //Warning: Will be come obsolete in near future release
    //...
    //...

    return 0;
}

int32_t
arabic_roman::onTmAlive( mqs_streamid_t sid M_UU, const char * ep M_UU )
{
    std::cout << endl << __PRETTY_FUNCTION__ << std::endl;

    //TODO Implement your ticker master entry functionality here
    //Warning: Will be come obsolete in near future release
    //...
    //...

    return 0;
}

//--------------------------------------------------------------------
// Protected functions
//--------------------------------------------------------------------


//TODO Put your protected functions implementation here


//--------------------------------------------------------------------
// Private functions
//--------------------------------------------------------------------


//TODO Put your private functions implementation here




//--------------------------------------------------------------------
// End of implementation body
//--------------------------------------------------------------------




/*********************************************************************
 *                      PROGRAM ENTRY                                *
 *                                                                   *
 *            Do not remove this function else your                  *
 *            application will not run                               *
 *                                                                   *
 *********************************************************************/
int main(int argc M_UU, char *argv[] M_UU)
{
    arabic_roman* marelApp = new arabic_roman( argv[0] );
    if( marelApp )
    {
        return marelApp->startUp( argc, argv );
    }
    return -1;
}


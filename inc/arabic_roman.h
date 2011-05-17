/**
 *   @defgroup arabic_roman Put your doxygen label here
     @{

     @file arabic_roman.h

     <REPLACE WITH YOUR BRIEF DESCRIPTION>
     A user application class that implements all the user defined functionality

     <REPLACE WITH YOUR DESCRIPTION>
     When a new project is being created, a class like this one is created
     (with relevant class/method name) which inherits 'MarelCppApp'. This class
     should then represent the implementation of the application creator


     @author your-name-here <your.email.here@marel.com>

     <b>
     Copyright (c) 2011 Marel Food Systems
     Proprietary material, all rights reserved, use or disclosure forbidden.
     </b>
 */

#ifndef arabic_roman_H_
#define arabic_roman_H_

//--------------------------------------------------------------------
// includes
//--------------------------------------------------------------------
#include "MarelCppApp.h"
#include "arabic_roman_priv.h"

//--------------------------------------------------------------------
// defines
//--------------------------------------------------------------------


//--------------------------------------------------------------------
// macros
//--------------------------------------------------------------------


//--------------------------------------------------------------------
// forward declarations
//--------------------------------------------------------------------


//--------------------------------------------------------------------
// typedefs
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// global variables
//--------------------------------------------------------------------
std::string onesArray[9]; // = { "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
std::string tensArray[9]; // = { "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
std::string hundredsArray[9]; // = { "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };

//--------------------------------------------------------------------
// local prototypes
//--------------------------------------------------------------------


//--------------------------------------------------------------------
// functions & classes
//--------------------------------------------------------------------

class arabic_roman : public MarelCppApp
{
    public:
        /*
         * Constructor
         */
        arabic_roman( std::string appName M_UU );
        /*
         * Destructor
         */
        ~arabic_roman();

        int32_t doConvert( int32_t value )
        {
        	printf("DoConvert %d\n", value);
        	if( value < 1000 )
        	{
				int32_t hundredValue = (value/100);
				int32_t tensValue;
				const char* hValue = toHundreds( hundredValue );
				if( hValue )
				{
					tensValue = (value%100);
				}
				else
				{
					tensValue = (value/10);
				}
				printf("hvalue: %d - tvalue: %d\n", hundredValue, tensValue );
				const char* tValue = toTens( tensValue );
	        	const char* oValue = toOnes( (value-(hundredValue+tensValue)) );
	        	printf(" %s%s%s\n", hValue, tValue, oValue );
        	}

        }
        const char* toOnes( int32_t value )
        {
        	if( value < 10 )
        	{
        		return onesArray[value].c_str();
        	}
        	return NULL;
        }

        const char* toTens( int32_t value )
		{
			if( value < 10 )
			{
				return tensArray[value].c_str();
			}
			return NULL;
		}

        const char* toHundreds( int32_t value )
		{
			if( value < 10 )
			{
				return hundredsArray[value].c_str();
			}
			return NULL;
		}
        /**
         * The timeout function is periodically called by the application
         * loop. The length of the period is defined by the implementer by
         * calling 'setTimeout'
         *
         * @see setTimeout
         */
        void timeout();

        /**
         * Initializes the implementation class
         *
         * @param argc Number of arguments
         * @param argv Array of arguments
         * @return 0 if successful else -1
         */
        int32_t initialize( int32_t argc M_UU, char **argv M_UU );
        /**
         * Deinitializes the implementation class
         */
        void deinitialize();
        /**
         * Called when ticker master deceases
         *
         * TODO Under revision, will become obsolete
         */
        int32_t onTmDead( mqs_streamid_t sid M_UU, const char * ep M_UU );
        /**
         * Called when ticker master is up and running
         *
         * TODO Under revision, will become obsolete
         */
        int32_t onTmAlive( mqs_streamid_t sid M_UU, const char * ep M_UU );

    private:
        std::string finalValue;
};

/**@}*/

#endif /* arabic_roman_H_ */

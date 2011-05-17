##################################################
#                                                #
#            Marel Makefile                      #
#                                                #
##################################################

PRJ_NAME = arabic_roman

#PRJ_TYPE = PROG
PRJ_TYPE = SOLIB

MAIN_SRC = 
#arabic_roman.cpp

SRC = arabic_roman.cpp

TEST_SRC = test_arabic_roman.cpp

TEST_REGR_PRGS =

ADD_CFLAGS =

ADD_LFLAGS =

TEST_LDFLAGS =

ADD_LIBS = appbase 

ADD_LIBS_PATH =

ADD_LINT_FLAGS=

default: debug

ifndef MDEV
    $(error Environment variable MDEV required)
endif

ifndef CPU
    $(error Environment variable CPU <x86/ppc> required)
endif


#
# include main makefile
#
include $(MDEV)/make/make.main

#eof

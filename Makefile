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

ADD_CFLAGS = -I/home/einar/workspace/gmock-1.6.0/gtest/include -I/home/einar/workspace/gmock-1.6.0/gtest -c/home/einar/workspace/gmock-1.6.0/gtest/src/gtest-all.cc

GTEST_DIR = /home/einar/workspace/gmock-1.6.0/gtest/
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

ADD_LFLAGS = -L/home/einar/workspace/gmock-1.6.0/gtest/lib
#-I/home/einar/workspace/gmock-1.6.0/gtest/include -I/home/einar/workspace/gmock-1.6.0/gtest -c /home/einar/workspace/gmock-1.6.0/gtest/src/gtest-all.cc

TEST_LDFLAGS =

ADD_LIBS = appbase gtest

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

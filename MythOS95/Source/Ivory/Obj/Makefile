#様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
#
#                   Ivory -- A Memory Management Library
#
#                     Microsoft Windows 95/98/NT Version
#
#  Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
#
#陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
#
# This file and all associated files are subject to the terms of the
# GNU Lesser General Public License version 2 as published by the
# Free Software Foundation (http://www.gnu.org).   They remain the
# property of the authors: Dan Higdon, Tim Little, and Chuck Walbourn.
# See LICENSE.TXT in the distribution for a copy of this license.
#
# THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
# OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
# PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
# LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
# OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
#
#陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
#
#                        http://www.mythos-engine.org/
#
#陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
#
# Created by Dan Higdon
#
# makefile
#
#様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

#旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
#
#                               Variables
#
#旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

!if "$(DEBUG)" == ""
DEBUG = NO
!endif

!if "$(THREAD)" == ""
THREAD=YES
!endif

!if "$(MYTH95ROOT)" == ""
MYTH95ROOT = \MythOS95
!endif

INCPATH = ;..\inc;$(MYTH95ROOT)\inc;

#陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
# File specific variables                                                  �
#陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

LIB = Ivory

OBJS =\
ivalloc.obj\
ivallcpp.obj\
#ivhalloc.obj\
ivarena.obj\
ivarcpp.obj\
ivsalloc.obj


MFCLIB = IvoryMFC

MFCOBJS =\
ivmfc.obj\
#ivhalloc.obj\
ivarena.obj\
ivarcpp.obj\
ivsalloc.obj


LIBPATH = $(MYTH95ROOT)\lib;

#陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
# First target                                                             �
#陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

all: setstden $(LIB).lib $(MFCLIB).lib

#陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
# Standard make include                                                    �
#陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

!include $(MYTH95ROOT)\inc\make.inc

#旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
#
#                                 Rules
#
#旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#--- .c, .cpp, .asm setup in standard include ---

#臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
#
#                              Dependancies
#
#臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

ivallcpp.obj : ..\inc\ivory.hpp ..\inc\ivory.h ..\ivallcpp.cpp
ivarcpp.obj :  ..\inc\ivory.hpp ..\inc\ivory.h ..\ivarcpp.cpp
ivalloc.obj :  ..\inc\ivory.h   ..\ivalloc.c
ivarena.obj :  ..\inc\ivory.h   ..\ivarena.c
ivhalloc.obj : ..\inc\ivory.h   ..\ivhalloc.c
ivsalloc.obj : ..\inc\ivory.h   ..\ivsalloc.c
ivmfc.obj :    ..\inc\ivory.h   ..\ivmfc.c

#陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
# Library                                                                  �
#陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

$(LIB).lib:   $(OBJS)
    -del $(LIB).lib
    $(LB) $(LBOPTS) /out:$(LIB).lib @<<
    $(OBJS: =
)
<<

$(MFCLIB).lib:   $(MFCOBJS)
    -del $(MFCLIB).lib
    $(LB) $(LBOPTS) /out:$(MFCLIB).lib @<<
    $(MFCOBJS: =
)
<<

release: all
    copy ..\inc\*.* $(MYTH95ROOT)\inc
    copy $(LIB).lib $(MYTH95ROOT)\lib
    copy $(MFCLIB).lib $(MYTH95ROOT)\lib

clean:
    del *.obj
    del *.res
    del *.err
    del *.lst
    del *.ilk
    del *.pdb

#葦� End of makefile 憶�


#様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
#                  ooo        ooooo
#                  `88.       .888'
#                   888b     d'888   .oooo.   oooo    ooo
#                   8 Y88. .P  888  `P  )88b   `88b..8P'
#                   8  `888'   888   .oP"888     Y888'
#                   8    Y     888  d8(  888   .o8"'88b
#                  o8o        o888o `Y888""8o o88'   888o
#
#                          Across the event horizon...
#
#                       Microsoft Windows 95/98/NT Version
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

LIB = max
OBJS=\
maxevt.obj\
maxesrc.obj\
maxdevs.obj\
maxkb.obj\
maxmouse.obj\
maxjoy.obj\
maxetsk.obj\
maxvmap.obj

LIBPATH = $(MYTH95ROOT)\lib;

#陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
# First target                                                             �
#陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

all: setstden $(LIB).lib

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

maxevt.obj:   ..\maxevt.cpp  ..\inc\maxevt.hpp  ..\inc\maxdevs.hpp
maxesrc.obj:  ..\maxesrc.cpp ..\inc\maxesrc.hpp ..\inc\maxevt.hpp ..\inc\maxdevs.hpp
maxdevs.obj:  ..\maxdevs.cpp ..\inc\maxdevs.hpp ..\inc\maxjoy.hpp ..\inc\maxkb.hpp ..\inc\maxmouse.hpp
maxkb.obj:    ..\maxkb.cpp   ..\inc\maxkb.hpp
maxjoy.obj:   ..\maxjoy.cpp  ..\inc\maxjoy.hpp
maxmouse.obj: ..\maxmouse.cpp ..\inc\maxmouse.hpp
maxetsk.obj:  ..\maxetsk.cpp ..\inc\maxesrc.hpp ..\inc\maxevt.hpp
maxvmap.obj:  ..\maxvmap.cpp ..\inc\maxvmap.hpp

#陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
# Library                                                                  �
#陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

$(LIB).lib:   $(OBJS)
    -del $(LIB).lib
    $(LB) $(LBOPTS) /out:$(LIB).lib @<<
    $(OBJS: =
)
<<

release: all
    copy ..\inc\*.* $(MYTH95ROOT)\inc
    copy $(LIB).lib $(MYTH95ROOT)\lib

clean:
    del *.obj
    del *.res
    del *.err
    del *.lst
    del *.ilk
    del *.pdb

#葦� End of makefile 憶�

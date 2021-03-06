//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//           __ ,
//            ,-| ~           ,               ,,
//           ('||/__,        ||               ||                  _
//          (( |||  | \\ \\ =||=   _-_  \\/\\ ||/|,  _-_  ,._-_  / \\
//          (( |||==| || ||  ||   || \\ || || || || || \\  ||   || ||
//           ( / |  , || ||  ||   ||/   || || || |' ||/    ||   || ||
//            -____/  \\/\\  \\,  \\,/  \\ \\ \\/   \\,/   \\,  \\_-|
//                                                               /  \
//                                                              '----`
//                     Text Output and Font Management System
//                       Microsoft Windows 95/98/NT Version
//
//  Copyright (c) 1995-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
// This file and all associated files are subject to the terms of the
// GNU Lesser General Public License version 2 as published by the
// Free Software Foundation (http://www.gnu.org).   They remain the
// property of the authors: Dan Higdon, Tim Little, and Chuck Walbourn.
// See LICENSE.TXT in the distribution for a copy of this license.
//
// THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
// OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
// PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
// LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
// OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
//                        http://www.mythos-engine.org/
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
// Created by Chuck Walbourn
//
// gbrgtxt.c
//
// Contains the basic text management routines.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <debug.h>

#include <assert.h>
#include <string.h>

#include <gutenbrg.h>

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Routines
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

extern GBergTextInfo *igberg_empty_strings();

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

extern GBergIData   *GBergInstance;

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// gberg_select_strings                                                     �
//                                                                          �
// Makes the given text active.                                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
gberg_error_codes gberg_select_strings(const char *txtname)
{
    ulong               i;
    GBergTextInfo       *txt, *ntxt;

    assertMyth("Gutenberg must be initialized",GBergInstance);

    if (!txtname)
        return GBERG_ERR_TEXTNOTINSTALLED;

    txt=GBergInstance->text_active;
    if (txt)
    {
//陳 Check to see if already active
        if (*txtname == *txt->name)
        {
            if (!strcmp(txtname,txt->name))
                return GBERG_ERR_NONE;
        }
    }

//陳 Search for given text name
    for(i=0, ntxt=&GBergInstance->text[0]; i < GBergInstance->text_hi; i++, ntxt++)
    {
        if (*txtname == *ntxt->name)
                {
            if (!strcmp(txtname,ntxt->name))
                break;
        }
    }

    if (i >= GBergInstance->text_hi)
    {
        return GBERG_ERR_TEXTNOTINSTALLED;
    }

    GBergInstance->text_active=ntxt;

    return GBERG_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// gberg_loadstring                                                         �
//                                                                          �
// Locks the active resource and returns the requested string               �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
gberg_error_codes gberg_loadstring(ulong num, char *buff, ulong len)
{
    ulong               i;
    byte                *ptr;
    gberg_error_codes   err=GBERG_ERR_NONE;
    GBergTextInfo       *txt;

    assertMyth("Gutenberg must be initialized",GBergInstance);

    txt=GBergInstance->text_active;
    assertMyth("gberg_loadstring assumes there is an active text block",
               txt);

//陳 Lock
    ptr=ivory_hlock(txt->data);
    if (!ptr)
    {
        return GBERG_ERR_LOCKFAILED;
    }

//陳 Find string
    err = GBERG_ERR_STRINGNOTFOUND;
    for (i = txt->number_of_strings; i > 0; i--)
    {
        if ( *((ulong *)ptr) == num )
        {
            if (!len)
                strcpy(buff,ptr+4);
            else
                strncpy(buff,ptr+4,len);
                        err = GBERG_ERR_NONE;
            break;
        }
        else
        {
            ptr += 4+strlen(ptr+4)+1;   // Can't have embedded NULs, so this
                                        // is valid.  Compiler checks for
                                        // this.
        }
    }

//陳 Unlock & exit
    ivory_hunlock(txt->data);
    return err;
}

//葦� End of module - gbrgstr.c 憶�

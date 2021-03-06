//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//
//           ^           **   **   **** ***** *    ****     ^      Take me to
//          (_)            * *     *      *   *    *       (_)    / your
//     ^                    *      **     *   *    **            ^  leader...
//    (_)       ^          * *     *      *   *    *            (_)
//             (_)       **   **   *    ***** **** ****
//
//                    Microsoft Windows 95/98/NT Version
//
//  Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
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
// xfiwrite.cpp
//
// XFParseINI -
//
// Writing includes a number of cases.  The memory-copy of the buffer is
// scanned for the item to see if it needs to be replaced.  If not found,
// then the section is created and the variable is written out.
// The first part of the buffer is written, then the new lines, then
// the second part to replace a buffer.  Comments and whitespace
// are preserved expect on the actual line replaced.  The buffer is
// then reloaded.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <stdio.h>
#include <string.h>

#include <assert.h>

#include "xfile.hpp"

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  Operations  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// XFParseINI - write                                                       �
//                                                                          �
// Writes a variable (overwriting if it already exists in this section).    �
//                                                                          �
// Returns 0 if ok, error number otherwise.                                 �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
xf_error_codes XFParseINI::write(const char *item, const char *value)
{
    int  addcrlf=0;
    xf_error_codes error;
    char *ptr;
    char *prologue;
    char crlf[2] = { '\r', '\n' };
    char equal = '=';

    prologue=0;

//陳� Setup start of search  陳�
    ptr = start();
    if (!ptr && *sectname)
    {

//陳� Section doesn't exist, so this is definetly new:
//                                       append and write section name 陳�
        xf->seek_end(0);
        if (xf->write(crlf,2) != 2)
        {
            errorn=xf->error();
            return errorn;
        }
        if (xf->write(sectname,strlen(sectname)) != strlen(sectname))
        {
            errorn=xf->error();
            return errorn;
        }
        if (xf->write(crlf,2) != 2)
        {
            errorn=xf->error();
            return errorn;
        }

    }
    else
    {
//陳� Empty current file 陳�
        xf->setsize(0);

//陳� Scan section for variable already defined  陳�
        if ((ptr=find(ptr,item))!=0)
        {

//陳� Variable already defined 陳�
            for(prologue=ptr; *prologue && *prologue != '\n'; prologue++);
            if (*prologue)
                prologue++;

            if (ptr != buff && *ptr)
                ptr--;
        }
        else
        {

//陳� Variable not defined in section 陳�
            ptr = start();
            if (ptr && *sectname)
            {
                addcrlf=1;
                for(prologue=ptr; *prologue && *prologue != '\n'; prologue++);
                if (*prologue)
                    prologue++;
            }
            else
                prologue=ptr;
        }

//陳� Write any area previous to variable's location 陳�
        if (ptr && buff && (ptr != buff))
        {
            if (xf->write(buff,ptr-buff+1) != (ulong)(ptr-buff+1))
            {
                errorn=xf->error();
                return errorn;
            }
        }
    }

//陳� Write out 陳�
    if (addcrlf)
    {
        if (xf->write(crlf,2) != 2)
        {
            errorn=xf->error();
            return errorn;
        }
    }

    if (xf->write(item,strlen(item)) != strlen(item))
    {
        errorn=xf->error();
        return errorn;
    }
    if (xf->write(&equal,1) != 1)
    {
        errorn=xf->error();
        return errorn;
    }
    if (xf->write(value,strlen(value)) != strlen(value))
    {
        errorn=xf->error();
        return errorn;
    }
    if (xf->write(crlf,2) != 2)
    {
        errorn=xf->error();
        return errorn;
    }
    if (prologue && *prologue)
    {
        if (xf->write(prologue,strlen(prologue)) != strlen(prologue))
        {
            errorn=xf->error();
            return errorn;
        }
    }

//陳� Reload 陳�
    error=load();
    if (error)
        return error;

    return XF_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// XFParseINI - write                                                       �
//                                                                          �
// Writes a block of variables                                              �
//                                                                          �
// Returns 0 if ok, error number otherwise.                                 �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
xf_error_codes XFParseINI::write(const char **item, const char **value)
{
    int i;

    for(i=0; item[i] && *item[i]; i++)
    {
        if (write(item[i],value[i]))
            return errorn;
    }

    return XF_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// XFParseINI - write                                                       �
//                                                                          �
// Writes a variable with an integer value.                                 �
//                                                                          �
// Returns 0 if ok, error number otherwise.                                 �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
xf_error_codes XFParseINI::write(const char *item, int value)
{
    char            str[XF_MAX_INIVALUE];

    sprintf(str,"%d",value);

    return write(item,str);
}

//葦� End of module - xfiwrite.cpp 憶�


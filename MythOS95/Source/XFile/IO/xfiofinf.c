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
// Ported to Windows by Dan Higdon
//
// xfiofinf.c
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <assert.h>
#include <xfio.h>

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// word xf_getattr (const char *name);                                      �
//                                                                          �
// Get attribute bits for a file.                                           �
//                                                                          �
// Returns -1 on error, attribute bits otherwise.                           �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
word xf_getattr (const char *name)
{
    DWORD attrs = GetFileAttributes (name);

    if (attrs == -1)
        xf_last_error = GetLastError();

    return (word)attrs;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// FILETIME xf_getfdate(HANDLE fhandle);                                    �
//                                                                          �
// Gets the file's modification date.                                       �
//                                                                          �
// Returns date, or 0 if error.                                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
word xf_getfdate (HANDLE fhandle)
{
    BY_HANDLE_FILE_INFORMATION  finfo;

    if (GetFileInformationByHandle (fhandle, &finfo))
    {
        WORD    wdate, wtime;

        if (FileTimeToDosDateTime (&finfo.ftLastWriteTime, &wdate, &wtime))
            return wdate;
    }

    return 0;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// word xf_getftime(int fhandle);                                           �
//                                                                          �
// Gets the file's modification time.                                       �
//                                                                          �
// Returns time, or 0 if error.                                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
word xf_getftime (HANDLE fhandle)
{
    BY_HANDLE_FILE_INFORMATION  finfo;

    if (GetFileInformationByHandle (fhandle, &finfo))
    {
        WORD    wdate, wtime;

        if (FileTimeToDosDateTime (&finfo.ftLastWriteTime, &wdate, &wtime))
            return wtime;
    }

    xf_last_error = GetLastError ();
    return 0;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// xf_getsize                                                               �
//                                                                          �
// Returns size of the file in bytes or -1 if error.                        �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
ulong xf_getsize (HANDLE fhandle)
{
    DWORD res;

    res = GetFileSize (fhandle, NULL);

    if (res == (DWORD)-1)
        xf_last_error = GetLastError();

    return res;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// word xf_setattr(const char *name, word attr);                            �
//                                                                          �
// Set attribute bits for a file.                                           �
//                                                                          �
// Returns -1 on error, set attribute bits otherwise.                       �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
word xf_setattr (const char *name, word attr)
{
    // set and validate attributes
    if (!SetFileAttributes (name, attr) ||
        (word)GetFileAttributes (name) != attr)
    {
        xf_last_error = GetLastError();
        return (word)-1;
    }

    return attr;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// xf_setsize                                                               �
//                                                                          �
// Sets the size of the file to the given length (either extending or       �
// truncating).  Returns the new size or -1 if error.                       �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
ulong xf_setsize (HANDLE fhandle, ulong size)
{
    if (SetFilePointer (fhandle, size, NULL, FILE_BEGIN) == size)
    {
        if (SetEndOfFile (fhandle))
            return size;
    }

    return (ulong)-1;
}

//葦� End of module - xfiofinf.c 憶�


//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//
//           ^           **   **   **** ***** *    ****     ^      Take me to
//          (_)            * *     *      *   *    *       (_)    / your
//     ^                    *      **     *   *    **            ^  leader...
//    (_)       ^          * *     *      *   *    *            (_)
//             (_)       **   **   *    ***** **** ****
//
//    Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
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
// xfbase.hpp
//
//      This contains the base file object tree.  These objects are operated
//      upon by the various parsers.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

#ifndef __XFBASE_HPP
#define __XFBASE_HPP    1

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <ivory.hpp>

#include "portable.h"
#include "xfdefs.h"
#include "xfio.h"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Classes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// Abstract base class for XFile file objects.                              �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class XFile {
protected:
    xf_error_codes  errorn;
    dword           sFlags;
    char            fName[XF_MAX_PATH];

public:
    XFile();
    virtual ~XFile();

           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳朕
           // Returns status information about the XFile instance.          �
           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳潰
    dword status(void) { return(sFlags); };

           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳朕
           // Returns the XF_ERR_ value for the last error that occurred.   �
           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳潰
    xf_error_codes error(void) { return(errorn); };

           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳朕
           // Get the current location of the file from the beginning.      �
           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳潰
    ulong tell(void) { return (seek_cur(0)); };

           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳朕
           // Returns the name of the current XFile.                        �
           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳潰
    char *getname(void) { return fName; };

           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳朕
           // Create a new file and open it for reading/writing.            �
           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳潰
    xf_error_codes create(const char *name, dword flags)
        { return open(name,flags | XF_OPEN_CREATE | XF_OPEN_WRITE); };

           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳朕
           // Generic file operations: copyto, copyfrom                     �
           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳潰
    xf_error_codes copyto(XFile *to);
    xf_error_codes copyfrom(XFile *from);

           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳朕
           // Open a file using the given flags.                            �
           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳潰
    virtual xf_error_codes open(const char *name, dword flags)=0;

           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳朕
           // Close the open file, if any.                                  �
           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳潰
    virtual xf_error_codes close(void)=0;

           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳朕
           // Flush any pending changes to a write file.                    �
           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳潰
    virtual xf_error_codes flush(void);

           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳朕
           // Read a block of the given size from the open file.            �
           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳潰
    virtual ulong read(void *ptr, ulong size)=0;

           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳朕
           // Write a block of the given size to the open file.             �
           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳潰
    virtual ulong write(const void *ptr, ulong size)=0;

           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳朕
           // Seek to a given position, relative to the beginning, end, or  �
           // current location of the file.                                 �
           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳潰
    ulong seek_set(long offset) { return seek(offset,0); };
    ulong seek_cur(long offset) { return seek(offset,1); };
    ulong seek_end(long offset) { return seek(offset,2); };
    virtual ulong seek(long offset, int mode)=0;

           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳朕
           // Total file size control                                       �
           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳潰
    virtual ulong getsize(void)=0;
    virtual ulong setsize(ulong size)=0;

           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳朕
           // Lock/Unlock the file for sharing control                      �
           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳潰
    virtual xf_error_codes lock(ulong offset, ulong nbytes);
    virtual xf_error_codes unlock(ulong offset, ulong nbytes);
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// DOS File objects.                                                        �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

#define XFileDisk XFileDOS

class XFileDOS : public XFile {
protected:
    int     fHandle;

public:
    XFileDOS();
    virtual ~XFileDOS();

    virtual xf_error_codes open(const char *name, dword flags);
    virtual xf_error_codes close(void);
    virtual xf_error_codes flush(void);
    virtual ulong read(void *ptr, ulong size);
    virtual ulong write(const void *ptr, ulong size);
    virtual ulong seek(long offset, int mode);
    virtual ulong getsize(void);
    virtual ulong setsize(ulong size);

    virtual xf_error_codes opentmp(char *name, dword flags);

           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳朕
           // Date/time stamp control                                       �
           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳潰
    virtual word getfdate(void);
    virtual word getftime(void);
    virtual xf_error_codes setfdate(word date);
    virtual xf_error_codes setftime(word time);
};

#define XFileDiskBuf XFileDOSBuff

class XFileDOSBuff : public XFileDOS {
protected:
    byte    *end;
    byte    *next;
    ulong   buffSize;
    byte    *data;

public:
    XFileDOSBuff();
    virtual ~XFileDOSBuff();

    virtual xf_error_codes open(const char *name, dword flags);
    virtual xf_error_codes close(void);
    virtual xf_error_codes flush(void);
    virtual ulong read(void *ptr, ulong size);
    virtual ulong write(const void *ptr, ulong size);
    virtual ulong seek(long offset, int mode);

    virtual xf_error_codes opentmp(char *name, dword flags);

    ulong getbuffersize(void) { return buffSize; }
    ulong setbuffersize(ulong size);
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// RAM File object.                                                         �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class XFileRAM : public XFile {
protected:
    ulong       position;
    ulong       fileSize;
    ulong       buffSize;
    IvoryHandle handle;

    xf_error_codes expand(ulong nsize);

public:
    XFileRAM();
    virtual ~XFileRAM();

    virtual xf_error_codes open(const char *name, dword flags);
    virtual xf_error_codes close(void);
    virtual ulong read(void *ptr, ulong size);
    virtual ulong write(const void *ptr, ulong size);
    virtual ulong seek(long offset, int mode);
    virtual ulong getsize(void) { return fileSize; };
    virtual ulong setsize(ulong size);
};

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//葦� End of header - xfbase.hpp 憶�


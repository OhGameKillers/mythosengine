//���������������������������������������������������������������������������
//                            
//           ^           **   **   **** ***** *    ****     ^      Take me to
//          (_)            * *     *      *   *    *       (_)    / your
//     ^                    *      **     *   *    **            ^  leader...
//    (_)       ^          * *     *      *   *    *            (_)
//             (_)       **   **   *    ***** **** ****
//
//            Copyright (c) 1994-1997 by Charybdis Enterprises, Inc.
//                             All Rights Reserved.
//                        Microsoft Windows '95 Version
//
//���������������������������������������������������������������������������
//
//           *** Charybdis Enterprises, Inc. Company Confidential ***
//
//  This file and all associated files are the company proprietary property
//        of Charybdis Enterprises, Inc.  Unauthorized use prohibited.
//
// CHARYBDIS ENTERPRISES, INC. MAKES NO WARRANTIES, EXPRESS OR IMPLIED, AS
// TO THE CORRECTNESS OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE
// IT.  CHARYBDIS ENTERPRISES, INC. PROVIDES THE CODE ON AN "AS-IS" BASIS
// AND EXPLICITLY DISCLAIMS ANY LIABILITY, INCLUDING CONSEQUENTIAL AND
// INCIDENTAL DAMAGES FOR ERRORS, OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//���������������������������������������������������������������������������
//
// Created by Chuck Walbourn
//
// xfbase.hpp
//
// This contains the base file object tree.  These objects are operated
// upon by the various parsers.
//
//���������������������������������������������������������������������������

#ifndef __XFBASE_HPP
#define __XFBASE_HPP    1

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//���������������������������������������������������������������������������
//
//                                Includes
//
//���������������������������������������������������������������������������

#include <ivory.hpp>

#include "portable.h"
#include "xfdefs.h"
#include "xfio.h"

//���������������������������������������������������������������������������
//
//                                Classes
//
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// XFile - Abstract base class for XFile file objects.                      �
//���������������������������������������������������������������������������
class XFile
{
protected:
    xf_error_codes  errorn;
    dword           sFlags;
    char            fName[XF_MAX_PATH];

public:
    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    XFile();
    virtual ~XFile();
  
    //���������������������������������������������������������������������Ŀ
    // Accessor functions                                                   �
    //�����������������������������������������������������������������������
    dword status() const { return(sFlags); }
    xf_error_codes error() const { return(errorn); }
    const char *getname() const { return fName; }

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    ulong tell () { return (seek_cur(0)); }

    xf_error_codes create (const char *name, dword flags)
        { return open(name,flags | XF_OPEN_CREATE | XF_OPEN_WRITE); }

    xf_error_codes copyto (XFile *to);
    xf_error_codes copyfrom (XFile *from);

    virtual xf_error_codes open (const char *name, dword flags) = 0;

    virtual xf_error_codes close () = 0;

    virtual xf_error_codes flush ();

    virtual ulong read (void *ptr, ulong size) = 0;

    virtual ulong write (const void *ptr, ulong size) = 0;

    ulong seek_set (long offset) { return seek (offset, 0); }
    ulong seek_cur (long offset) { return seek (offset, 1); }
    ulong seek_end (long offset) { return seek (offset, 2); }
    virtual ulong seek (long offset, int mode) = 0;

    virtual ulong getsize () = 0;
    virtual ulong setsize (ulong size) = 0;

    virtual xf_error_codes lock (ulong offset, ulong nbytes);
    virtual xf_error_codes unlock (ulong offset, ulong nbytes);
};                                                        


//�������������������������������������������������������������������������Ŀ
// XFileDisk - Disk file class.                                             �
//���������������������������������������������������������������������������
#define XFileDOS XFileDisk

class XFileDisk : public XFile
{
protected:
    HANDLE  fHandle;

public:
    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    XFileDisk();
    virtual ~XFileDisk();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    virtual xf_error_codes open (const char *name, dword flags);
    virtual xf_error_codes close ();
    virtual xf_error_codes flush ();
    virtual ulong read  (void *ptr, ulong size);
    virtual ulong write (const void *ptr, ulong size);
    virtual ulong seek  (long offset, int mode);
    virtual ulong getsize ();
    virtual ulong setsize (ulong size);

    virtual xf_error_codes opentmp (const char *name, dword flags);

    virtual word getfdate ();
    virtual word getftime ();
};                                                        


//�������������������������������������������������������������������������Ŀ
// XFileDiskBuf - Buffered disk file class.                                 �
//���������������������������������������������������������������������������
#define XFileDOSBuff XFileDiskBuf

class XFileDiskBuf : public XFileDisk
{
protected:    
    byte    *end;
    byte    *next;
    ulong   buffSize;
    byte    *data;

public:
    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    XFileDiskBuf();
    virtual ~XFileDiskBuf();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    virtual xf_error_codes open (const char *name, dword flags);
    virtual xf_error_codes close ();
    virtual xf_error_codes flush ();
    virtual ulong read  (void *ptr, ulong size);
    virtual ulong write (const void *ptr, ulong size);
    virtual ulong seek  (long offset, int mode);

    virtual xf_error_codes opentmp (const char *name, dword flags);

    ulong getbuffersize ()  { return buffSize; }
    ulong setbuffersize (ulong size);
};                                                        


//�������������������������������������������������������������������������Ŀ
// XFileRAM - RAM File object.                                              �
//���������������������������������������������������������������������������
class XFileRAM : public XFile
{
protected:
    ulong       position;
    ulong       fileSize;
    ulong       buffSize;
    IvoryHandle handle;

    xf_error_codes expand (ulong nsize);

public:
    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    XFileRAM();
    virtual ~XFileRAM();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    virtual xf_error_codes open (const char *name, dword flags);
    virtual xf_error_codes close ();
    virtual ulong read  (void *ptr, ulong size);
    virtual ulong write (const void *ptr, ulong size);
    virtual ulong seek  (long offset, int mode);
    virtual ulong getsize ()    { return fileSize; };
    virtual ulong setsize (ulong size);
};

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//��� End of header - xfbase.hpp ���

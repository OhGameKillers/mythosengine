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
// xfiff.hpp
//
// Contains the header for the IFF parsing object.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

#ifndef __XFIFF_HPP
#define __XFIFF_HPP    1

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

#include "xfbase.hpp"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳� XFForm flags 陳�
#define XF_IFFFORM_DIRTY    0x1

//陳� Maximum supported depth for form embedding 陳�
#define XF_MAX_IFFDEPTH     16

//陳� XFParseIFF control flags 陳�
#define XF_IFF_NOPAD        0x1
#define XF_IFF_RIFF         0x2

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Structures
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳� Form Context Structure 陳�
struct XFForm
{
    dword   id;
    dword   flags;
    dword   start;
    dword   len;
};

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Classes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// XFParseIFF - IFF reader/writer class.                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class XFParseIFF
{
    dword            cflags;
    ulong            idepth;
    ulong            icurPos;
    ulong            ilength;
    ulong            ichunkSize;
    struct XFForm    iforms[XF_MAX_IFFDEPTH];
    XFileDisk        xfile;

    void initvars(void);

protected:
    XFile            *xf;

    xf_error_codes   errorn;

public:
    dword formid;
    dword chunkid;
    ulong chunkSize;
    ulong depth;

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    XFParseIFF(dword cf = 0);
    XFParseIFF(XFile *f, dword cf = 0);

    ~XFParseIFF();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    xf_error_codes error(void) const { return errorn; };

    void attach(XFile *f) { xf = (f) ? f : &xfile; }

           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳朕
           // Quick access functions for the XFile object embedded.         �
           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳潰
    xf_error_codes open(const char *name, dword flags)
    {
        xf_error_codes err=xf->open(name,flags|XF_OPEN_READ);
        if (!err)
        {
            return begin();
        }
        errorn=err;
        return err;
    }
    xf_error_codes create(const char *name, dword flags)
    {
        xf_error_codes err=xf->create(name,flags|XF_OPEN_READ);
        if (!err)
        {
            return begin();
        }
        errorn=err;
        return err;
    }
    xf_error_codes close(void)
    {
        end();
        xf_error_codes err=xf->close();
        if (err) errorn=err;
        return err;
    }

           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳朕
           // These must be called if the XFile object is not opened/closed �
           // via the member functions for this object.                     �
           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳潰
    xf_error_codes begin(void);
    xf_error_codes end(void);

           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳朕
           // Form-based file movement.                                     �
           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳潰
    xf_error_codes seekform(dword id);

    xf_error_codes newform(dword id);
    xf_error_codes enterform(void);

    xf_error_codes leaveform(void);

           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳朕
           // Chunk-based file movement.                                    �
           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳潰
    xf_error_codes seekchunk(dword id);

           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳朕
           // Item movement.                                                �
           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳潰
    xf_error_codes next(void);
    xf_error_codes topofcontext(int donext=1);

           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳朕
           // Reads/writes a chunk in the current position.                 �
           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳潰
    xf_error_codes read(void *ptr);
    xf_error_codes write(dword id, const void *ptr, ulong size);

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Utility functions.                                                   �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    static word swapendian(word c)
    {
        return ( ((c & 0xff) << 8)
                 | ((c & 0xff00) >> 8) );
    }
    static dword swapendian(dword c)
    {
        return ( ((c & 0xff) << 24)
                 | ((c & 0xff00) << 8)
                 | ((c & 0xff0000) >> 8)
                 | ((c & 0xff000000) >> 24) );
    }
    static dword makeid(char c1, char c2, char c3, char c4)
    {
        return ( (c4 << 24)
                 | (c3 << 16)
                 | (c2 << 8)
                 | c1);
    }
    static char *strid(dword id, char *buff)
    {
        buff[0] = (char)((id & 0xff));
        buff[1] = (char)((id & 0xff00) >> 8);
        buff[2] = (char)((id & 0xff0000) >> 16);
        buff[3] = (char)((id & 0xff000000) >> 24);
        buff[4] = 0;
        return buff;
    }
};

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//葦� End of header - xfiff.hpp 憶�


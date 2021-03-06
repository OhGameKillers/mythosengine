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
// xfcel.cpp
//
// .CEL files are Autodesk Animator files used by 3D Studio for
// textures in many materials.  There is an Autodesk Animator Pro
// .CEL file that is actually a .FLC file.  This code only supports
// the .CEL file from Autodesk Animator.  This code will also
// read Autodesk Animator .PIC files.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <string.h>

#include "xfile.hpp"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Structures
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

struct Header
{
   word    type;       // 0x9119 is magic tag for .CEL
   word    width;
   word    height;
   word    xcoord;
   word    ycoord;
   byte    depth;
   byte    compress;
   dword   datasize;
   char    reserved[16];
};

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  Operations  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// XFParseCEL - read                                                        �
//                                                                          �
// Reads a CEL format bitmap from the file object.                          �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
xf_error_codes XFParseCEL::read(XFBitmap *b)
{
    ushort xcoord, ycoord;

    return read(xcoord, ycoord, b);
}

xf_error_codes XFParseCEL::read(ushort &xcoord, ushort &ycoord, XFBitmap *b)
{
    int             i;
    byte            *ptr;
    struct  Header  header;
    byte            work[3*256];

    if (!b)
        b = bm;

//陳� Read file header 陳�
    if (xf->read(&header,sizeof(Header)) != sizeof(Header))
        return (errorn=xf->error());

//陳� Verify valid file header 陳�
    if (header.type != 0x9119)
        return (errorn=XF_ERR_INVALIDHEADER);

//陳� Check for unsupported formats 陳�
    if (header.compress
        || header.depth != 8)
       return (errorn=XF_ERR_NOTSUPPORTED);

//陳� Setup bitmap object 陳�
    b->release();

    b->flags=0;
    b->clrinuse=255;
    b->width = (ushort) header.width;
    b->height = (ushort) header.height;
    b->bpp = XFBM_BPP_8BIT;

    xcoord = header.xcoord;
    ycoord = header.ycoord;

//陳� Get palette data 陳�

    // Allocate memory
    b->palhandle = ivory_halloc(sizeof(dword)*256);
    if (!b->palhandle)
    {
        return (errorn=XF_ERR_NOMEMORY);
    }

    b->pal = (dword *)ivory_hlock(b->palhandle);
    if (!b->pal)
    {
        b->release();
        return (errorn=XF_ERR_LOCKFAILED);
    }

    memset(b->pal,0,sizeof(dword)*256);

    // Load palette into work-memory
    if (xf->read(work,3*256) != 3*256)
    {
        b->release();
        return (errorn=XF_ERR_INVALIDPALETTE);
    }

    // Move to standard Van Gogh order color dwords RGBX.
    // (original palette is always in range 0-63 for color components)
    for (i=0, ptr=(byte*)b->pal; i < 256; i++)
    {
        *(ptr++) = (byte)(work[i*3] << 2);      // red
        *(ptr++) = (byte)(work[i*3+1] << 2);    // green
        *(ptr++) = (byte)(work[i*3+2] << 2);    // blue
        *(ptr++) = 0;                           // na to make dword
    }

//陳� Load image data 陳�

    // Allocate memory
    b->handle = ivory_halloc(b->width * b->height * b->bpp);
    if (!b->handle)
    {
        b->release();
        return (errorn=XF_ERR_NOMEMORY);
    }

    b->data = (byte *)ivory_hlock(b->handle);
    if (!b->data)
    {
        b->release();
        return (errorn=XF_ERR_LOCKFAILED);
    }

    // Load image directly into data area
    if (xf->read(b->data,b->width * b->height) != ulong (b->width*b->height))
    {
        b->release();
        return (errorn=XF_ERR_INVALIDIMAGE);
    }

    return XF_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// XFParseCEL - write                                                       �
//                                                                          �
// Writes a CEL format bitmap to the file object.                           �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
xf_error_codes XFParseCEL::write(XFBitmap *b)
{
    return write(0,0,b);
}

xf_error_codes XFParseCEL::write(ushort xcoord, ushort ycoord, XFBitmap *b)
{
    int             i;
    byte            *ptr;
    int             locked=0;
    struct  Header  header;
    byte            work[3*256];

    if (!b)
        b = bm;

    if (b->bpp != XFBM_BPP_8BIT
        || !b->width || !b->height)
        return (errorn=XF_ERR_NOTSUPPORTED);

//陳� Create/write file header 陳�
    memset(&header,0,sizeof(Header));
    header.type=0x9119;
    header.width=b->width;
    header.height=b->height;
    header.xcoord = xcoord;
    header.ycoord = ycoord;
    header.depth=8;
    header.datasize=b->width*b->height;

    if (xf->write(&header,sizeof(Header)) != sizeof(Header))
    {
        errorn=xf->error();
        return errorn;
    }

    if (b->pal || b->data)
    {
        locked=1;
    }
    else
    {
        xf_error_codes err;

        err=b->lock();
        if (err)
        {
            return (errorn=err);
        }
    }

//陳� Write out palette 陳�
    if (!b->pal)
    {
        if (!locked)
            b->unlock();
        return (errorn=XF_ERR_INVALIDPALETTE);
    }

    for (i=0, ptr=(byte*)b->pal; i < 256; i++)
    {
        work[i*3]   = (byte)(*(ptr++) >> 2); // red
        work[i*3+1] = (byte)(*(ptr++) >> 2); // green
        work[i*3+2] = (byte)(*(ptr++) >> 2); // blue
        ptr++;                               // na to make dword
    }

    if (xf->write(work,3*256) != 3*256)
    {
        if (!locked)
            b->unlock();
        errorn=xf->error();
        return errorn;
    }

//陳� Write out image 陳�
    if (!b->data)
    {
        if (!locked)
            b->unlock();
        return (errorn=XF_ERR_INVALIDIMAGE);
    }

    if (xf->write(b->data,b->width * b->height) != ulong (b->width*b->height))
    {
        if (!locked)
            b->unlock();
        errorn=xf->error();
        return errorn;
    }

    if (!locked)
        b->unlock();

    return XF_ERR_NONE;
}

//葦� End of module - xfcel.cpp 憶�


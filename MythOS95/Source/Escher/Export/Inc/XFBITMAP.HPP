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
// xfbitmap.hpp
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

#ifndef __XFBITMAP_HPP
#define __XFBITMAP_HPP    1

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

#include "xfbase.hpp"
#include "xfiff.hpp"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

const ulong    XF_MAX_WIDTH    =65535;
const ulong    XF_MAX_HEIGHT   =65535;

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Classes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// Bitmap Object read/written by XFileBitmap.                               �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class XFBitmap {
public:
    word        flags;          // Flags for bitmap.
    ushort      width;          // X-size of bitmap
    ushort      height;         // Y-size of bitmap
    byte        bpp;            // Bytes per pixel for bitmap (1 or 3)
    byte        clrinuse;       // Highest pal index in use
    dword       *pal;           // Pointer to locked palette data, if any.
    byte        *data;          // Pointer to locked bitmap data.
    IvoryHandle palhandle;      // Palette data handle (256 dword table)
    IvoryHandle handle;         // Bitmap handle

    XFBitmap();
    ~XFBitmap();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations on bitmap objects.                                        �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    void release();

    xf_error_codes lock();
    void unlock();
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// Abstract base object for reading/writing bitmap files.                   �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class XFParseBitmap {
    XFileDOSBuff    xfile;
    XFBitmap        bitmap;

protected:
    XFile           *xf;
    xf_error_codes  errorn;

public:
    XFBitmap        *bm;

    XFParseBitmap();
    XFParseBitmap(XFile *f);
    XFParseBitmap(XFBitmap *b);
    XFParseBitmap(XFile *f, XFBitmap *b);
    virtual ~XFParseBitmap();

    void attach(XFile *f) { if (!f) {xf=&xfile;} else {xf=f;} };

    xf_error_codes error(void) { return errorn; };

           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳朕
           // Reads the given data into the object, freeing up any          �
           // previously loaded bitmap in the object's memory.              �
           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳潰
    xf_error_codes nameread(const char *name, XFBitmap *bm=0);
    virtual xf_error_codes read(XFBitmap *bm=0)=0;


           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳朕
           // Writes the bitmap in the object's memory to the given file.   �
           //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳潰
    xf_error_codes namewrite(const char *name, XFBitmap *b=0);
    virtual xf_error_codes write(XFBitmap *b=0)=0;
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// Bitmap reading/writing objects for various formats.                      �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

//陳 Windows BMP
class XFParseBMP : public XFParseBitmap {
public:
    virtual xf_error_codes read(XFBitmap *b=0);
    virtual xf_error_codes write(XFBitmap *b=0);
};

//陳 Autodesk's CEL
class XFParseCEL : public XFParseBitmap {
public:
    virtual xf_error_codes read(XFBitmap *b=0);
    virtual xf_error_codes write(XFBitmap *b=0);
};

//陳 IFF Standard ILBM
class XFParseLBM : public XFParseBitmap {
public:
    virtual xf_error_codes read(XFBitmap *b=0);
    virtual xf_error_codes write(XFBitmap *b=0);

    xf_error_codes read(XFParseIFF *iff, XFBitmap *b=0);
    xf_error_codes write(XFParseIFF *iff, XFBitmap *b=0);
};

//陳 Zsoft's PCX
class XFParsePCX : public XFParseBitmap {
public:
    virtual xf_error_codes read(XFBitmap *b=0);
    virtual xf_error_codes write(XFBitmap *b=0);
};

//陳 Targa TrueVision TGA
class XFParseTGA : public XFParseBitmap {
public:
    virtual xf_error_codes read(XFBitmap *b=0);
    virtual xf_error_codes write(XFBitmap *b=0);
};

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//葦� End of header - xfbitmap.hpp 憶�


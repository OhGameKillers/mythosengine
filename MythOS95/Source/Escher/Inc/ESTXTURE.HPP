//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//���������������������������������������������������������������������������
//����������旭旭旭旭旭�旭旭旭旭���旭旭旭旭��旭姻���旭姻旭旭旭旭旭�旭旭旭旭姻�
//���������葦姻������葦姻���葦姻葦姻���葦姻葦姻���葦姻葦姻�������葦姻���葦姻�
//��������碓甥������碓甥�������碓甥�������碓甥���碓甥碓甥�������碓甥���碓甥��
//�������渦臼葦渦��渦臼葦渦臼�渦甥�������渦臼葦渦臼�渦臼葦渦���渦臼葦渦姻����
//������渦甥�������������渦甥渦甥�������渦甥���渦甥渦甥�������渦甥���渦甥����
//�����憶悔������憶悔���憶悔憶悔���憶悔憶悔���憶悔憶悔�������憶悔���憶悔�����
//����臆臆臆臆臆�臆臆臆臆���臆臆臆臆��臆悔���臆悔臆臆臆臆臆�臆悔���臆悔������
//���������������������������������������������������������������������������
//����������������� Microsoft Windows 95/98/NT Version ����������������������
//���������������������������������������������������������������������������
//���Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn���
//���������������������������������������������������������������������������
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
// Created by Tim Little & Chuck Walbourn
//
// estxture.hpp
//
// EschTexture is the interface defining class for the texture container
// object.  The EschTexture class contains a VngoTexture pointer and a
// number of standard interface members used to control the texture
// usage.
//
// EschStaticTexture is a single-frame bitmap texture.
//
// EschMultiFrameTexture is an animated bitmap texture with 2 or more frames.
//
// EschProceduralTexture is a standard interface level for developing
// textures which are generated procedurally.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

#ifndef __ESTXTURE_HPP
#define __ESTXTURE_HPP    1

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

#include <portable.h>
#include <ivory.hpp>

#include "esdefs.h"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Structures
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

struct EschTextureCache
{
    IvoryHandle handle;
    ulong       count;
    dword       flags;
    word        typ;
    ushort      width;
    ushort      height;
    ushort      max;
    char        *name;
};

struct EschTextureFile
{
    dword           flags;
    XFParseIFF      *iff;
    ulong           count;
    char            *names;
    char            fname[XF_MAX_PATH];
};

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Classes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

class XFBitmap;
struct EschFileMtlMHDR;

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschTexture - Base texture object.                                       �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class EschTexture
{

protected:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Protected data members                                               �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    word        ttyp;                   // Run-time type
    word        na;

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Protected utility members                                            �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    esch_error_codes load_body(XFParseIFF *iff,
                               EschFileMtlMHDR &header,
                               VngoPal *pal, XFBitmap *bm);

public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Public data members                                                  �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    dword       flags;                  // Texture flags (ESCH_TXT_)
    char        *name;                  // Texture name pointer
    VngoTexture *ptr;                   // Pointer to Van Gogh texture to use
                                        // (valid when locked).
    void        *app_data;              // Application data pointer

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschTexture();
    EschTexture(const EschTexture &txt);

    virtual ~EschTexture();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Accessor functions                                                   �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    word get_type() const { return ttyp; }

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    const EschTexture &operator = (const EschTexture &txt);

    virtual void release();

    //陳� Lock/unlock texture ptr for use.
    virtual void lock();
    virtual void unlock();

    //陳� Animation callback to perform any per-frame changes.
    virtual void animate();

    //陳� Texture cache management
    static EschTexture *cache_new(const char *n);
    static int cache_release(IvoryHandle h);
    static esch_error_codes cache_register(const char *n, IvoryHandle hnd,
                                           word t, dword f,
                                           ushort w, ushort h, ushort m,
                                           char **name=0, int inuse=0);

    //陳� Texture file management
    static EschTexture *file_load(const char *n, VngoPal *pal=0,
                                  dword ctrlfl=ESCH_TXTLD_ALL);
    static esch_error_codes file_register(const char *fname);
    static void file_unregister(const char *fname=0);

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Utility functions.                                                   �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    void set_flags(const dword f) { flags = f; }
    void set_flags(const dword m, const int on)
    {
        if (on)
            flags |= m;
        else
            flags &= ~m;
    }

    void set_app_data(void *p) { app_data = p; }

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // I/O Routines.                                                        �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    virtual esch_error_codes load(const char *fname, const char *tname=0,
                                  dword ctrlfl=ESCH_TXTLD_ALL, VngoPal *pal=0);
    virtual esch_error_codes load(XFParseIFF *iff, const char *tname=0,
                                  dword ctrlfl=ESCH_TXTLD_ALL, VngoPal *pal=0);
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschStaticTexture - Single-frame bitmap texture.                         �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class EschStaticTexture : public EschTexture
{
public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Public data members                                                  �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    IvoryHandle handle;                 // Handle to bitmap data

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschStaticTexture() : EschTexture(), handle (0)
    {
        ttyp = ESCH_TXTT_STATIC;
    }

    virtual ~EschStaticTexture();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    virtual void release();
    virtual void lock();
    virtual void unlock();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Utility functions.                                                   �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    esch_error_codes create(XFBitmap *bm, int trans=1, VngoPal *pal=0);

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // I/O Routines.                                                        �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    virtual esch_error_codes load(const char *fname, const char *tname=0,
                                  dword ctrlfl=ESCH_TXTLD_ALL, VngoPal *pal=0);
    virtual esch_error_codes load(XFParseIFF *iff, const char *tname=0,
                                  dword ctrlfl=ESCH_TXTLD_ALL, VngoPal *pal=0);
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschMultiFrameTexture - Multiple-frame bitmap texture.                   �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class EschMultiFrameTexture : public EschTexture
{
protected:
    ulong       base;
    ulong       size;
    float       interval;
    float       time;

public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Public data members                                                  �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    ushort      index;                  // Current frame of texture
    ushort      max;                    // Max number of frames
    IvoryHandle handle;                 // Handle to bitmaps
    float       rate;

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschMultiFrameTexture();

    virtual ~EschMultiFrameTexture();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    virtual void release();
    virtual void lock();
    virtual void unlock();
    virtual void animate();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Utility functions.                                                   �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    void reset() { index=0;  time=0; }

    void set_interval(float i) { interval=i; }

    void set_rate(float r) { flags |= ESCH_MFTXT_TIMEBASED;  rate=r; }

    void set_size(ushort w, ushort h)
    {
        size = w*h;
        base = max * sizeof(VngoTexture);
    }

    esch_error_codes create(ushort n, XFBitmap *bms, int trans=1, VngoPal *pal=0);

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // I/O Routines.                                                        �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    virtual esch_error_codes load(const char *fname, const char *tname=0,
                                  dword ctrlfl=ESCH_TXTLD_ALL, VngoPal *pal=0);
    virtual esch_error_codes load(XFParseIFF *iff, const char *tname=0,
                                  dword ctrlfl=ESCH_TXTLD_ALL, VngoPal *pal=0);
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschProceduralTexture - Procedural texture interface class.              �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class EschProceduralTexture : public EschTexture
{
protected:
    VngoTexture txt;

public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschProceduralTexture()
    {
        txt.tex = 0;
        ttyp = ESCH_TXTT_PRC;
    }
    EschProceduralTexture(ushort w, ushort h, VngoPal *pal, int dogen=1)
    {
        txt.tex=0; init(w,h,pal,dogen);
    }

    virtual ~EschProceduralTexture();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    virtual void release();
    virtual void lock();
    virtual void unlock();
    virtual void animate();

    virtual esch_error_codes init(ushort w, ushort h, VngoPal *pal,
                                  int dogen=1);
    virtual void generate();
};

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//葦� End of header - estxture.hpp 憶�


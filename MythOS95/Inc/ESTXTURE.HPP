//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//�����������Copyright�(c)�1994-1997�by�Charybdis�Enterprises,�Inc.����������
//��������������������������All�Rights�Reserved.�����������������������������
//���������������������������������������������������������������������������
//��������������������� Microsoft Windows '95 Version �����������������������
//���������������������������������������������������������������������������
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
//���������������������������������������������������������������������������

#ifndef __ESTXTURE_HPP
#define __ESTXTURE_HPP    1

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

#include <portable.h>
#include <ivory.hpp>

#include "esdefs.h"

//���������������������������������������������������������������������������
//
//                               Structures
//
//���������������������������������������������������������������������������

struct EschTextureCache
{
    IvoryHandle handle;
    ulong       count;
    dword       flags;
    word        typ;
    ushort      width;
    ushort      height;
    ushort      max;
    char        name[ESCH_MAX_NAME];
};

//���������������������������������������������������������������������������
//
//                                Classes
//
//���������������������������������������������������������������������������

class XFBitmap;
struct EschFileMtlMHDR;

//�������������������������������������������������������������������������Ŀ
// EschTexture - Base texture object.                                       �
//���������������������������������������������������������������������������
class EschTexture
{

protected:
    //���������������������������������������������������������������������Ŀ
    // Protected data members                                               �
    //�����������������������������������������������������������������������
    word        ttyp;                   // Run-time type
    word        na;

    //���������������������������������������������������������������������Ŀ
    // Protected utility members                                            �
    //�����������������������������������������������������������������������
    esch_error_codes load_body(XFParseIFF *iff,
                               EschFileMtlMHDR &header,
                               VngoPal *pal);

public:
    //���������������������������������������������������������������������Ŀ
    // Public data members                                                  �
    //�����������������������������������������������������������������������
    dword       flags;                  // Texture flags (ESCH_TXT_)
    char        *name;                  // Texture name pointer
    VngoTexture *ptr;                   // Pointer to Van Gogh texture to use
                                        // (valid when locked).

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    EschTexture();
    EschTexture(const EschTexture &txt);

    virtual ~EschTexture();

    //���������������������������������������������������������������������Ŀ
    // Accessor functions                                                   �
    //�����������������������������������������������������������������������
    word get_type() const { return ttyp; }

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    const EschTexture &operator = (const EschTexture &txt);

    virtual void release();

    //��� Lock/unlock texture ptr for use.
    virtual void lock();
    virtual void unlock();

    //��� Animation callback to perform any per-frame changes.
    virtual void animate();

    //��� Texture cache management
    static EschTexture *cache_new(const char *n);
    static int cache_release(IvoryHandle h);
    static esch_error_codes cache_register(const char *n, IvoryHandle hnd, 
                                           word t, dword f,
                                           ushort w, ushort h, ushort m,
                                           char **name=0, int inuse=0);

    //���������������������������������������������������������������������Ŀ
    // Utility functions.                                                   �
    //�����������������������������������������������������������������������
    void set_flags(const dword f) { flags = f; }

    //���������������������������������������������������������������������Ŀ
    // I/O Routines.                                                        �
    //�����������������������������������������������������������������������
    virtual esch_error_codes load(const char *fname, const char *tname=0,
                                  dword ctrlfl=ESCH_TXTLD_ALL, VngoPal *pal=0);
    virtual esch_error_codes load(XFParseIFF *iff, const char *tname=0,
                                  dword ctrlfl=ESCH_TXTLD_ALL, VngoPal *pal=0);
};


//�������������������������������������������������������������������������Ŀ
// EschStaticTexture - Single-frame bitmap texture.                         �
//���������������������������������������������������������������������������
class EschStaticTexture : public EschTexture
{
public:
    //���������������������������������������������������������������������Ŀ
    // Public data members                                                  �
    //�����������������������������������������������������������������������
    IvoryHandle handle;                 // Handle to bitmap data

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    EschStaticTexture() : EschTexture(), handle (0)
    {
        ttyp = ESCH_TXTT_STATIC;
    }

    virtual ~EschStaticTexture();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    virtual void release();
    virtual void lock();
    virtual void unlock();

    //���������������������������������������������������������������������Ŀ
    // Utility functions.                                                   �
    //�����������������������������������������������������������������������
    esch_error_codes create(XFBitmap *bm, int trans=1);

    //���������������������������������������������������������������������Ŀ
    // I/O Routines.                                                        �
    //�����������������������������������������������������������������������
    virtual esch_error_codes load(XFParseIFF *iff, const char *tname=0,
                                  dword ctrlfl=ESCH_TXTLD_ALL, VngoPal *pal=0);
};


//�������������������������������������������������������������������������Ŀ
// EschMultiFrameTexture - Multiple-frame bitmap texture.                   �
//���������������������������������������������������������������������������
class EschMultiFrameTexture : public EschTexture
{
protected:
    ulong       base;
    ulong       size;
    Flx16       interval;
    Flx16       time;

public:
    //���������������������������������������������������������������������Ŀ
    // Public data members                                                  �
    //�����������������������������������������������������������������������
    ushort      index;                  // Current frame of texture
    ushort      max;                    // Max number of frames
    IvoryHandle handle;                 // Handle to bitmaps
    Flx16       rate;

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    EschMultiFrameTexture();

    virtual ~EschMultiFrameTexture();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    virtual void release();
    virtual void lock();
    virtual void unlock();
    virtual void animate();

    //���������������������������������������������������������������������Ŀ
    // Utility functions.                                                   �
    //�����������������������������������������������������������������������
    void reset() { index=0;  time=0; }
    
    void set_interval(Flx16 i) { interval=i; }

    void set_rate(Flx16 r) { flags |= ESCH_MFTXT_TIMEBASED;  rate=r; }

    void set_size(ushort w, ushort h)
    {
        size = w*h;
        base = max * sizeof(VngoTexture);
    }

    esch_error_codes create(ushort n, XFBitmap *bms, int trans=1);

    //���������������������������������������������������������������������Ŀ
    // I/O Routines.                                                        �
    //�����������������������������������������������������������������������
    virtual esch_error_codes load(XFParseIFF *iff, const char *tname=0,
                                  dword ctrlfl=ESCH_TXTLD_ALL, VngoPal *pal=0);
};


//�������������������������������������������������������������������������Ŀ
// EschProceduralTexture - Procedural texture interface class.              �
//���������������������������������������������������������������������������
class EschProceduralTexture : public EschTexture
{
protected:
    VngoTexture txt;

public:
    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
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

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
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

//��� End of header - estxture.hpp ���

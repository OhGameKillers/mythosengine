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
// estxture.cpp
//
// EschTexture is the interface defining class for the texture container
// object.  The EschTexture class contains a VngoTexture pointer and a
// number of standard interface members used to control the texture
// usage.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include "escher.hpp"
#include "esfile.hpp"

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

extern char EschNoName[];

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭�  Constructors/Destructors  碓旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschTexture - Constructor                                                �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschTexture::EschTexture() :
    ttyp(ESCH_TXTT_BASE),
    flags(0),
    name(EschNoName),
    ptr(0),
    app_data(0)
{
    //陳 Update diags
    assertMyth("EschTexture needs Escher initialized",EschSysInstance != 0);
    EschSysInstance->diag_ntxts++;
}

EschTexture::EschTexture(const EschTexture &txt) :
    ttyp(txt.ttyp),
    flags(txt.flags & ~ESCH_TXT_OWNSDATA),
    name(txt.name),
    ptr(txt.ptr),
    app_data(txt.app_data)
{
    //陳 Update diags
    assertMyth("EschTexture needs Escher initialized",EschSysInstance != 0);
    EschSysInstance->diag_ntxts++;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschTexture - Destructor                                                 �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschTexture::~EschTexture()
{
    release();

    //陳 Update diags
    assertMyth("EschTexture needs Escher initialized",EschSysInstance != 0);
    EschSysInstance->diag_ntxts--;
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  Operations  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschTexture - operator =                                                 �
//                                                                          �
// Copies the data from another texture.                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
const EschTexture &EschTexture::operator = (const EschTexture &txt)
{
    if (this != &txt)
    {
        release();

        flags = txt.flags & ~(ESCH_TXT_OWNSDATA|ESCH_TXT_SHARED);
        name = txt.name;
        ptr = txt.ptr;
        app_data = txt.app_data;
    }
    return *this;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschTexture - release                                                    �
//                                                                          �
// This first unlocks the texture, then it releases name and ptr.           �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschTexture::release()
{
    if (flags & ESCH_TXT_LOCKED)
        unlock();

    if (flags & ESCH_TXT_OWNSDATA)
    {
        if (name && name != EschNoName)
        {
            delete [] name;
        }
        name=EschNoName;

        if (ptr)
        {
            delete [] ptr;
        }
    }
    name=EschNoName;
    ptr=0;

    flags &= ~(ESCH_TXT_OWNSDATA | ESCH_TXT_LOCKED | ESCH_TXT_SHARED);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschTexture - lock                                                       �
//                                                                          �
// Locks the texture, making the 'ptr' member a valid pointer to a Van Gogh �
// texture object.                                                          �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschTexture::lock()
{
    // Just ensures LOCKED bit is maintained.

    if (flags & ESCH_TXT_LOCKED)
        return;

    if (!ptr)
        return;

    flags |= ESCH_TXT_LOCKED;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschTexture - unlock                                                     �
//                                                                          �
// Unlocks the texture.                                                     �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschTexture::unlock()
{
    // Just ensures LOCKED bit is maintained.

    if (flags & ESCH_TXT_LOCKED)
    {
        assertMyth("EschTexture::unlock expects ptr to be non-zero",
                   ptr);

        flags &= ~ESCH_TXT_LOCKED;
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschTexture - animate                                                    �
//                                                                          �
// Performs per-frame updating to animate the texture.                      �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschTexture::animate()
{
    // Performs no action
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  I/O Routines  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//                              旭� Protected 旭�                           �
// EschTexture - load_body                                                  �
//                                                                          �
// Utility member for loading bitmap body frames for textures which is used �
// by Static and Multiframe textures.                                       �
//                                                                          �
// Assumes that the ptr member is set to the target texture instance.       �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
esch_error_codes EschTexture::load_body(XFParseIFF *iff,
                                        EschFileMtlMHDR &header,
                                        VngoPal *pal, XFBitmap *bm)
{
    byte *work;

    assert(iff && ptr);
    assert(iff->chunkid == iff->makeid('B','O','D','Y') && iff->chunkSize);

//陳� Determine bytes per pixel
    int bpp, transp;
    switch (header.type)
    {
        case ESCH_MTL_TYPE_8BIT:            bpp=1;  transp=0;   break;
        case ESCH_MTL_TYPE_8BIT_TRANSP:     bpp=1;  transp=1;   break;
        case ESCH_MTL_TYPE_15BIT:           bpp=2;  transp=0;   break;
        case ESCH_MTL_TYPE_15BIT_TRANSP:    bpp=2;  transp=1;   break;
        case ESCH_MTL_TYPE_24BIT:           bpp=3;  transp=0;   break;
        case ESCH_MTL_TYPE_32BIT:           bpp=4;  transp=1;   break;
        default:
            return ESCH_ERR_NOTSUPPORTED;
    }

//陳� Process
    if (header.compress == ESCH_MTL_COMPRESS_RLE
        && iff->chunkSize < (ulong)(header.xsize * header.ysize * bpp))
    {
        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Compressed
        work = new byte[iff->chunkSize];
        if (!work)
            return ESCH_ERR_NOMEMORY;

        if (iff->read(work))
        {
            delete [] work;
            return ESCH_ERR_FILEERROR;
        }

        switch (bpp)
        {
            case 2:
                //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Convert to palette
                {
                    byte *dptr=(byte*)ptr->tex;
                    byte *eptr=(byte*)ptr->tex + (header.xsize*header.ysize);
                    for(byte *wptr=work; wptr < work+iff->chunkSize; )
                    {
                        int j = (char) *(wptr++);
                        if (j >= 0)
                        {
                            //陳� Literial
                            for(int i=0; i < j+1; i++)
                            {
                                if (dptr >= eptr)
                                {
                                    delete [] work;
                                    return ESCH_ERR_INVALIDDATA;
                                }

                                word pcolor = *wptr | (*(wptr+1) << 8);

                                if (transp && (pcolor & 0x8000))
                                {
                                    *(dptr++) = (byte)VNGO_TRANSPARENT_COLOR;
                                }
                                else
                                {
                                    pcolor &= ~0x8000;
                                    VngoColor24bit clr((pcolor >> 7) & 0xf8,
                                                       (pcolor >> 2) & 0xf8,
                                                       (pcolor << 3) & 0xf8);
                                    *(dptr++) = (byte)pal->get_index(clr);
                                }
                                wptr += 2;
                            }
                        }
                        else
                        {
                            //陳� Run
                            j = -j+1;

                            word pcolor = *wptr | (*(wptr+1) << 8);

                            byte index;
                            if (transp && (pcolor & 0x8000))
                            {
                                index = (byte)VNGO_TRANSPARENT_COLOR;
                            }
                            else
                            {
                                pcolor &= ~0x8000;
                                VngoColor24bit clr((pcolor >> 7) & 0xf8,
                                                   (pcolor >> 2) & 0xf8,
                                                   (pcolor << 3) & 0xf8);
                                index = (byte)pal->get_index(clr);
                            }

                            for(int i=0; i < j; i++)
                            {
                                if (dptr >= eptr)
                                {
                                    delete [] work;
                                    return ESCH_ERR_INVALIDDATA;
                                }

                                *(dptr++) = index;
                            }

                            wptr += 2;
                        }
                    }
                }
                //陳陳陳陳陳陳陳陳陳陳陳陳陳 Decompress to bitmap, if requested
                if (bm)
                {
                    if (bm->create(header.xsize,header.ysize,XFBM_BPP_15BIT))
                    {
                        delete [] work;
                        return ESCH_ERR_NOMEMORY;
                    }

                    if (XFParseXEB::uncompress_rle_16bpp(header.xsize,
                                                         header.ysize,
                                                         iff->chunkSize,
                                                         work,
                                                         bm->data))
                    {
                        delete [] work;
                        return ESCH_ERR_INVALIDDATA;
                    }
                }
                break;
            case 3:
                //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Convert to palette
                {
                    byte *dptr=(byte*)ptr->tex;
                    byte *eptr=(byte*)ptr->tex + (header.xsize*header.ysize);
                    for(byte *wptr=work; wptr < work+iff->chunkSize; )
                    {
                        int j = (char) *(wptr++);
                        if (j >= 0)
                        {
                            //陳� Literial
                            for(int i=0; i < j+1; i++)
                            {
                                if (dptr >= eptr)
                                {
                                    delete [] work;
                                    return ESCH_ERR_INVALIDDATA;
                                }

                                VngoColor24bit clr(*wptr,
                                                   *(wptr+1),
                                                   *(wptr+2));
                                *(dptr++) = (byte)pal->get_index(clr);
                                wptr += 3;
                            }
                        }
                        else
                        {
                            //陳� Run
                            j = -j+1;

                            VngoColor24bit clr(*wptr,
                                               *(wptr+1),
                                               *(wptr+2));
                            byte index = (byte)pal->get_index(clr);

                            for(int i=0; i < j; i++)
                            {
                                if (dptr >= eptr)
                                {
                                    delete [] work;
                                    return ESCH_ERR_INVALIDDATA;
                                }

                                *(dptr++) = index;
                            }

                            wptr += 3;
                        }
                    }
                }
                //陳陳陳陳陳陳陳陳陳陳陳陳陳 Decompress to bitmap, if requested
                if (bm)
                {
                    if (bm->create(header.xsize,header.ysize,XFBM_BPP_24BIT))
                    {
                        delete [] work;
                        return ESCH_ERR_NOMEMORY;
                    }

                    if (XFParseXEB::uncompress_rle_24bpp(header.xsize,
                                                         header.ysize,
                                                         iff->chunkSize,
                                                         work,
                                                         bm->data))
                    {
                        delete [] work;
                        return ESCH_ERR_INVALIDDATA;
                    }
                }
                break;
            case 4:
                //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Convert to palette
                {
                    byte *dptr=(byte*)ptr->tex;
                    byte *eptr=(byte*)ptr->tex + (header.xsize*header.ysize);
                    for(byte *wptr=work; wptr < work+iff->chunkSize; )
                    {
                        int j = (char) *(wptr++);
                        if (j >= 0)
                        {
                            //陳� Literial
                            for(int i=0; i < j+1; i++)
                            {
                                if (dptr >= eptr)
                                {
                                    delete [] work;
                                    return ESCH_ERR_INVALIDDATA;
                                }

                                if (*(wptr+3) < ESCH_ALPHA_TRANSP)
                                {
                                    *(dptr++) = (byte)VNGO_TRANSPARENT_COLOR;
                                }
                                else
                                {
                                    VngoColor24bit clr(*wptr,
                                                       *(wptr+1),
                                                       *(wptr+2));
                                    *(dptr++) = (byte)pal->get_index(clr);
                                }
                                wptr += 4;
                            }
                        }
                        else
                        {
                            //陳� Run
                            j = -j+1;

                            byte index;
                            if (*(wptr+3) < ESCH_ALPHA_TRANSP)
                            {
                                index = (byte)VNGO_TRANSPARENT_COLOR;
                            }
                            else
                            {
                                VngoColor24bit clr(*wptr,
                                                   *(wptr+1),
                                                   *(wptr+2));
                                index = (byte)pal->get_index(clr);
                            }

                            for(int i=0; i < j; i++)
                            {
                                if (dptr >= eptr)
                                {
                                    delete [] work;
                                    return ESCH_ERR_INVALIDDATA;
                                }

                                *(dptr++) = index;
                            }

                            wptr += 4;
                        }
                    }
                }
                //陳陳陳陳陳陳陳陳陳陳陳陳陳 Decompress to bitmap, if requested
                if (bm)
                {
                    if (bm->create(header.xsize,header.ysize,XFBM_BPP_32BIT))
                    {
                        delete [] work;
                        return ESCH_ERR_NOMEMORY;
                    }

                    if (XFParseXEB::uncompress_rle_32bpp(header.xsize,
                                                         header.ysize,
                                                         iff->chunkSize,
                                                         work,
                                                         bm->data))
                    {
                        delete [] work;
                        return ESCH_ERR_INVALIDDATA;
                    }
                }
                break;
            default:
                //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Decompress
                if (XFParseXEB::uncompress_rle_8bpp(header.xsize, header.ysize,
                                                    iff->chunkSize, work,
                                                    (byte*)ptr->tex))
                {
                    delete [] work;
                    return ESCH_ERR_INVALIDDATA;
                }
                break;
        }

        delete [] work;
    }
    else
    {
        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Uncompressed
        if (iff->chunkSize != (ulong)(header.xsize * header.ysize * bpp))
            return ESCH_ERR_INVALIDDATA;

        //陳� Handle 8bits directly
        if (bpp == 1)
        {
            if (iff->read(ptr->tex))
                return ESCH_ERR_FILEERROR;

            return ESCH_ERR_NONE;
        }

        //陳� Handle 15/24/32-bits
        work = new byte[iff->chunkSize];
        if (!work)
            return ESCH_ERR_NOMEMORY;

        if (iff->read(work))
        {
            delete [] work;
            return ESCH_ERR_FILEERROR;
        }

        //陳� Recolor
        assert(pal);

        switch (bpp)
        {
            //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� 15-bit format (5/5/5)
            case 2:
                {
                    byte *dptr = (byte*)ptr->tex;
                    byte *sptr = work;
                    for(ulong i=0; i < (ulong)(header.xsize * header.ysize); i++)
                    {
                        word pcolor = *sptr | (*(sptr+1) << 8);

                        if (transp && (pcolor & 0x8000))
                        {
                            *(dptr++) = (byte)VNGO_TRANSPARENT_COLOR;
                        }
                        else
                        {
                            pcolor &= ~0x8000;
                            *(dptr++) = (byte)pal->get_index(VngoColor24bit(
                                                              (pcolor >> 7) & 0xf8,
                                                              (pcolor >> 2) & 0xf8,
                                                              (pcolor << 3) & 0xf8));
                        }

                        sptr += 2;
                    }
                }
                //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Save to bitmap, if requested
                if (bm)
                {
                    if (bm->create(header.xsize,header.ysize,XFBM_BPP_15BIT))
                    {
                        delete [] work;
                        return ESCH_ERR_NOMEMORY;
                    }

                    memcpy(bm->data,work,header.xsize*header.ysize*2);
                }
                break;
            //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� 24-bit format (RGB)
            case 3:
                {
                    byte *dptr = (byte*)ptr->tex;
                    byte *sptr = work;
                    for(ulong i=0; i < (ulong)(header.xsize * header.ysize); i++)
                    {
                        *(dptr++) = (byte)pal->get_index(VngoColor24bit(
                                                         *sptr,
                                                         *(sptr+1),
                                                         *(sptr+2)));
                        sptr += 3;
                    }
                }
                //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Save to bitmap, if requested
                if (bm)
                {
                    if (bm->create(header.xsize,header.ysize,XFBM_BPP_24BIT))
                    {
                        delete [] work;
                        return ESCH_ERR_NOMEMORY;
                    }

                    memcpy(bm->data,work,header.xsize*header.ysize*3);
                }
                break;
            //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 32-bit format (RGBA)
            case 4:
                {
                    byte *dptr = (byte*)ptr->tex;
                    byte *sptr = work;
                    for(ulong i=0; i < (ulong)(header.xsize * header.ysize); i++)
                    {
                        if ((*(sptr+3)) < ESCH_ALPHA_TRANSP)
                        {
                            *(dptr++) = (byte)VNGO_TRANSPARENT_COLOR;
                        }
                        else
                        {
                            *(dptr++) = (byte)pal->get_index(VngoColor24bit(
                                                                *sptr,
                                                                *(sptr+1),
                                                                *(sptr+2)));
                        }
                        sptr += 4;
                    }
                }
                //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Save to bitmap, if requested
                if (bm)
                {
                    if (bm->create(header.xsize,header.ysize,XFBM_BPP_32BIT))
                    {
                        delete [] work;
                        return ESCH_ERR_NOMEMORY;
                    }

                    memcpy(bm->data,work,header.xsize*header.ysize*4);
                }
                break;
        }

        delete [] work;
    }

    return ESCH_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschTexture - load                                                       �
//                                                                          �
// Loads the data for the texture from an IFF file.                         �
//                                                                          �
// The IFF version assumes that the IFF is open and pointing at the proper  �
// chunk.  If a 'tname' is given and the name doesn't match that in the     �
// form, an error is returned.                                              �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
esch_error_codes EschTexture::load(const char *fname, const char *tname,
                                   dword ctrlfl, VngoPal *pal)
{
    esch_error_codes    err;
    XFParseIFF          iff;

//陳 Open file
    if (iff.open(fname,XF_OPEN_READ | XF_OPEN_DENYWRITE))
        return ESCH_ERR_FILEERROR;

//陳 Loop until a header with the correct name is found
    err=ESCH_ERR_NONE;

    for(;;)
    {
        if (iff.next() != XF_ERR_NONE)
        {
            if (!iff.depth)
                return ESCH_ERR_NOTFOUND;
            iff.leaveform();
            continue;
        }

        if (iff.chunkid == iff.makeid('F','O','R','M'))
        {
            if (iff.formid == iff.makeid('E','M','T','L')
                || iff.formid == iff.makeid('E','M','T','1'))
            {
                err=load(&iff,tname,ctrlfl,pal);
                if (!err
                    || err != ESCH_ERR_NOTFOUND)
                    break;
            }

            // Must scan inside any ESEN Scene forms.
            else if (iff.formid == iff.makeid('E','S','E','N'))
            {
                iff.enterform();
            }

            // Must scan inside any EMSH Mesh forms.
            else if (iff.formid == iff.makeid('E','M','S','H'))
            {
                iff.enterform();
            }

            // Must scan inside any ETER Terrain forms.
            else if (iff.formid == iff.makeid('E','T','E','R'))
            {
                iff.enterform();
            }
        }
    }

//陳 Return ok
    iff.close();
    return err;
}

esch_error_codes EschTexture::load(XFParseIFF *iff, const char *tname,
                                   dword ctrlfl, VngoPal *pal)
{
    return ESCH_ERR_NOTSUPPORTED;
}

//葦� End of module - estxture.cpp 憶�

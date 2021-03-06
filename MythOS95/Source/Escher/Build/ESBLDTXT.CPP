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
// esbldtxt.cpp
//
// The EschBuildTexture class provides a method for creating materials
// manually and is used by the EschBuildMesh class.  The class can write
// a data file for later use.
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
// EschBuildTexture - Constructor                                           �
//                                                                          �
// Intializes the instance                                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschBuildTexture::EschBuildTexture() :
    tflags(0),
    bms(0)
{
    strcpy(name,EschNoName);
}

EschBuildTexture::EschBuildTexture(ulong mf) :
    tflags(0),
    bms(0)
{
    strcpy(name,EschNoName);

    init(mf);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschBuildTexture - Destructor                                            �
//                                                                          �
// Ensures data is released.                                                �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschBuildTexture::~EschBuildTexture()
{
    release();
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  Operations  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschBuildTexture - init                                                  �
//                                                                          �
// Initializes the instance, create the needed array of pointers.           �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
esch_error_codes EschBuildTexture::init(ulong mf)
{
    if (!mf)
        return ESCH_ERR_INVALIDPARMS;

    release();

//陳� Bitmaps
    nframes = 0;
    maxframes = mf;
    bms = new XFBitmap *[mf];
    if (!bms)
        return ESCH_ERR_NOMEMORY;

    return ESCH_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschBuildTexture - release                                               �
//                                                                          �
// Frees all used memory.                                                   �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschBuildTexture::release(int freebms)
{
    if (bms)
    {
        for(ulong i=0; i < nframes; i++)
        {
            if (freebms && bms[i])
                delete bms[i];
        }
        delete [] bms;
        bms=0;
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschBuildTexture - save                                                  �
//                                                                          �
// Saves data to a data file base on data in builder.                       �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
esch_error_codes EschBuildTexture::save(const char *fname, dword ctrlfl, VngoPal *pal)
{
    XFParseIFF  iff;

    if (iff.create(fname,0))
    {
        return ESCH_ERR_FILEERROR;
    }

    esch_error_codes err = save(&iff,ctrlfl,pal);
    if (err)
        return err;

    iff.close();

    return ESCH_ERR_NONE;
}

esch_error_codes EschBuildTexture::save(XFParseIFF *iff,
                                        dword ctrlfl, VngoPal *pal)
{
    if (!bms || !nframes)
        return ESCH_ERR_MISSINGDATA;

    switch (ctrlfl & (ESCH_TBLD_8BIT|ESCH_TBLD_15BIT|ESCH_TBLD_TC))
    {
        case ESCH_TBLD_8BIT:
            if (!pal)
                return ESCH_ERR_INVALIDPARMS;
            break;
        case ESCH_TBLD_15BIT:
        case ESCH_TBLD_TC:
            break;
        default:
            return ESCH_ERR_INVALIDPARMS;
    }

//陳� Create form
    if (iff->newform((nframes > 1) ? iff->makeid('E','M','T','1')
                                   : iff->makeid('E','M','T','L')))
        return ESCH_ERR_FILEERROR;

//陳� Write header
    {
        EschFileMtlMHDR     header;
        memset(&header,0,sizeof(header));

        strncpy(header.name,name,sizeof(header.name));
        header.xsize = bms[0]->width;
        header.ysize = bms[0]->height;
        header.nframes = (ushort)nframes;

        if (ctrlfl & ESCH_TBLD_TC)
        {
            header.type = (ctrlfl & ESCH_TBLD_TRANSP)
                          ? ESCH_MTL_TYPE_32BIT
                          : ESCH_MTL_TYPE_24BIT;
        }
        else if (ctrlfl & ESCH_TBLD_15BIT)
        {
            header.type = (ctrlfl & ESCH_TBLD_TRANSP)
                          ? ESCH_MTL_TYPE_15BIT_TRANSP
                          : ESCH_MTL_TYPE_15BIT;
        }
        else
        {
            header.type = (ctrlfl & ESCH_TBLD_TRANSP)
                          ? ESCH_MTL_TYPE_8BIT_TRANSP
                          : ESCH_MTL_TYPE_8BIT;
        }

        header.compress = (ctrlfl & ESCH_TBLD_COMPRESS)
                          ? ESCH_MTL_COMPRESS_RLE
                          : ESCH_MTL_COMPRESS_NONE;

        header.flags = (tflags & ~(ESCH_TXT_LOCKED
                                   | ESCH_TXT_OWNSDATA
                                   | ESCH_TXT_SHARED
                                   | ESCH_TXT_TRANSP));

        if (iff->write(iff->makeid('M','H','D','R'),
                       &header,sizeof(header)))
            return ESCH_ERR_FILEERROR;
    }

//陳� Write body
    for(ulong i=0; i < nframes; i++)
    {
        XFBitmap *bm = bms[i];

        //陳� Lock bitmap
        int locked=0;
        if (bm->pal || bm->data)
        {
            locked=1;
        }
        else
        {
            if (bm->lock() || !bm->data)
                return ESCH_ERR_LOCKFAILED;
        }

        int bpp = bm->bpp;
        int freedata=0;
        byte *data = bm->data;

        //陳� Recolor to palette
        if ((ctrlfl & ESCH_TBLD_8BIT) && bm->bpp != 1)
        {
            assert(pal != 0);

            data=new byte [bm->width*bm->height];
            if (!data)
                return ESCH_ERR_NOMEMORY;

            freedata=1;
            bpp=1;

            switch (bm->bpp)
            {
                case 2:
                    {
                        byte *sptr = bm->data;
                        byte *dptr = data;
                        for(long i=0; i < bm->width*bm->height; i++)
                        {
                            word pcolor = *sptr | (*(sptr+1) << 8);

                            if ((ctrlfl & ESCH_TBLD_TRANSP)
                                && (pcolor & 0x8000))
                            {
                                *(dptr++) = (byte)VNGO_TRANSPARENT_COLOR;
                            }
                            else
                            {
                                pcolor &= ~0x8000;

                                VngoColor24bit clr((pcolor >> 7) & 0xf8,
                                                   (pcolor >> 2) & 0xf8,
                                                   (pcolor << 3) & 0xf8);

                                if ((ctrlfl & ESCH_TBLD_TRANSP)
                                    && clr.r == 248
                                    && clr.b == 248
                                    && clr.g == 0)
                                {
                                    *(dptr++) = (byte)VNGO_TRANSPARENT_COLOR;
                                }
                                else
                                {
                                    *(dptr++) = (byte)pal->get_index(clr);
                                }
                            }

                            sptr += 2;
                        }
                    }
                    break;
                case 3:
                    {
                        byte *sptr = bm->data;
                        byte *dptr = data;
                        for(long i=0; i < bm->width*bm->height; i++)
                        {
                            VngoColor24bit clr(*sptr,*(sptr+1),*(sptr+2));

                            if ((ctrlfl & ESCH_TBLD_TRANSP)
                                && clr.r == 255
                                && clr.b == 255
                                && clr.g == 0)
                            {
                                *(dptr++) = (byte)VNGO_TRANSPARENT_COLOR;
                            }
                            else
                            {
                                *(dptr++) = (byte)pal->get_index(clr);
                            }

                            sptr += 3;
                        }
                    }
                    break;
                case 4:
                    {
                        byte *sptr = bm->data;
                        byte *dptr = data;
                        for(long i=0; i < bm->width*bm->height; i++)
                        {
                            if ((ctrlfl & ESCH_TBLD_TRANSP)
                                && (*(sptr+3) < ESCH_ALPHA_TRANSP))
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
                    break;
                default:
                    assert(FALSE);
                    break;
            }
        }
        //陳� Convert to 3/4
        else if (ctrlfl & ESCH_TBLD_TC)
        {
            bpp = (ctrlfl & ESCH_TBLD_TRANSP) ? 4 : 3;
            if (bpp != bm->bpp)
            {
                data=new byte [bm->width*bm->height*bpp];
                if (!data)
                    return ESCH_ERR_NOMEMORY;

                freedata=1;

                switch (bm->bpp)
                {
                    case 1:
                        {
                            byte *sptr = bm->data;
                            byte *dptr = data;
                            for(long i=0; i < bm->width*bm->height; i++)
                            {
                                assert(bm->pal != 0);

                                VngoColor24bit clr(bm->pal[*sptr]);
                                *(dptr++) = clr.r;
                                *(dptr++) = clr.g;
                                *(dptr++) = clr.b;

                                if (bpp == 4)
                                {
                                    *(dptr++) = (*sptr == (byte)VNGO_TRANSPARENT_COLOR)
                                                ? 0 : 255;
                                }

                                sptr++;
                            }
                        }
                        break;
                    case 2:
                        {
                            byte *sptr = bm->data;
                            byte *dptr = data;
                            for(long i=0; i < bm->width*bm->height; i++)
                            {
                                word pcolor = *sptr | (*(sptr+1) << 8);

                                if ((bpp == 4) && (pcolor & 0x8000))
                                {
                                    *(dptr++) = 255;
                                    *(dptr++) = 0;
                                    *(dptr++) = 255;
                                    *(dptr++) = 0;
                                }
                                else
                                {
                                    pcolor &= ~0x8000;
                                    VngoColor24bit clr((pcolor >> 7) & 0xf8,
                                                       (pcolor >> 2) & 0xf8,
                                                       (pcolor << 3) & 0xf8);

                                    *(dptr++) = clr.r;
                                    *(dptr++) = clr.g;
                                    *(dptr++) = clr.b;

                                    if (bpp == 4)
                                    {
                                        if (clr.r == 248
                                            && clr.b == 248
                                            && clr.g == 0)
                                        {
                                            *(dptr++) = 0;
                                        }
                                        else
                                        {
                                            *(dptr++) = 255;
                                        }
                                    }
                                }

                                sptr += 2;
                            }
                        }
                        break;
                    case 3:
                        {
                            assert(bpp == 4);
                            byte *sptr = bm->data;
                            byte *dptr = data;
                            for(long i=0; i < bm->width*bm->height; i++)
                            {
                                *(dptr++) = *sptr;
                                *(dptr++) = *(sptr+1);
                                *(dptr++) = *(sptr+2);

                                if (*sptr == 255
                                    && *(sptr+2) == 255
                                    && *(sptr+1) == 0)
                                {
                                    *(dptr++) = 0;
                                }
                                else
                                {
                                    *(dptr++) = 255;
                                }

                                sptr += 3;
                            }
                        }
                        break;
                    case 4:
                        {
                            assert(bpp == 3);
                            byte *sptr = bm->data;
                            byte *dptr = data;
                            for(long i=0; i < bm->width*bm->height; i++)
                            {
                                *(dptr++) = *(sptr++);
                                *(dptr++) = *(sptr++);
                                *(dptr++) = *(sptr++);
                                sptr++;
                            }
                        }
                        break;
                    default:
                        assert(FALSE);
                        break;
                }
            }
        }
        //陳� Convert to 2bpp
        else if (ctrlfl & ESCH_TBLD_15BIT)
        {
            data=new byte [bm->width*bm->height*2];
            if (!data)
                return ESCH_ERR_NOMEMORY;

            freedata=1;
            bpp=2;

            switch (bm->bpp)
            {
                case 1:
                    {
                        byte *sptr = bm->data;
                        byte *dptr = data;
                        for(long i=0; i < bm->width*bm->height; i++)
                        {
                            assert(bm->pal != 0);

                            VngoColor24bit clr(bm->pal[*sptr]);

                            word pcolor = ((clr.r >> 3) << 10)
                                           + ((clr.g >> 3) << 5)
                                           + (clr.b >> 3);

                            if ((ctrlfl & ESCH_TBLD_TRANSP)
                                && *sptr == (byte)VNGO_TRANSPARENT_COLOR)
                            {
                                pcolor |= 0x8000;
                            }

                            *(dptr++) = byte(pcolor & 0xff);
                            *(dptr++) = byte((pcolor & 0xff00) >> 8);

                            sptr++;
                        }
                    }
                    break;
                case 2:
                    {
                        byte *sptr = bm->data;
                        byte *dptr = data;
                        for(long i=0; i < bm->width*bm->height; i++)
                        {
                            word pcolor = *sptr | (*(sptr+1) << 8);

                            if ((ctrlfl & ESCH_TBLD_TRANSP)
                                && (pcolor & 0x8000))
                            {
                                *(dptr++) = byte(pcolor & 0xff);
                                *(dptr++) = byte((pcolor & 0xff00) >> 8);
                            }
                            else
                            {
                                pcolor &= ~0x8000;

                                if (ctrlfl & ESCH_TBLD_TRANSP)
                                {
                                    VngoColor24bit clr((pcolor >> 7) & 0xf8,
                                                        (pcolor >> 2) & 0xf8,
                                                        (pcolor << 3) & 0xf8);

                                    if (clr.r == 248
                                        && clr.b == 248
                                        && clr.g == 0)
                                    {
                                        pcolor |= 0x8000;
                                    }
                                }

                                *(dptr++) = byte(pcolor & 0xff);
                                *(dptr++) = byte((pcolor & 0xff00) >> 8);
                            }

                            sptr += 2;
                        }
                    }
                    break;
                case 3:
                    {
                        byte *sptr = bm->data;
                        byte *dptr = data;
                        for(long i=0; i < bm->width*bm->height; i++)
                        {
                            word pcolor = (((*sptr) >> 3) << 10)
                                           + (((*(sptr+1)) >> 3) << 5)
                                           + ((*(sptr+2)) >> 3);

                            if ((ctrlfl & ESCH_TBLD_TRANSP)
                                && (*sptr == 255
                                    && *(sptr+2) == 255
                                    && *(sptr+1) == 0))
                            {
                                pcolor |= 0x8000;
                            }

                            *(dptr++) = byte(pcolor & 0xff);
                            *(dptr++) = byte((pcolor & 0xff00) >> 8);

                            sptr += 3;
                        }
                    }
                    break;
                case 4:
                    {
                        byte *sptr = bm->data;
                        byte *dptr = data;
                        for(long i=0; i < bm->width*bm->height; i++)
                        {
                            word pcolor = (((*sptr) >> 3) << 10)
                                           + (((*(sptr+1)) >> 3) << 5)
                                           + ((*(sptr+2)) >> 3);

                            if (*(sptr+3) < ESCH_ALPHA_TRANSP)
                            {
                                pcolor |= 0x8000;
                            }

                            *(dptr++) = byte(pcolor & 0xff);
                            *(dptr++) = byte((pcolor & 0xff00) >> 8);

                            sptr += 4;
                        }
                    }
                    break;
            }
        }

        //陳� Write
        byte *work=new byte [bm->width*bm->height*bpp];
        if (!work)
        {
            if (freedata)
                delete [] data;
            return ESCH_ERR_NOMEMORY;
        }

        dword size=0;
        if (ctrlfl & ESCH_TBLD_COMPRESS)
        {
            switch (bpp)
            {
                case 2:
                    size=XFParseXEB::compress_rle_16bpp(bm->width,bm->height,
                                                        data,work);
                    break;
                case 3:
                    size=XFParseXEB::compress_rle_24bpp(bm->width,bm->height,
                                                        data,work);
                    break;
                case 4:
                    size=XFParseXEB::compress_rle_32bpp(bm->width,bm->height,
                                                        data,work);
                    break;
                default:
                    assert(bpp == 1);
                    size=XFParseXEB::compress_rle_8bpp(bm->width,bm->height,
                                                       data,work);
                    break;
            }
        }

        if (size)
        {
            if (iff->write(iff->makeid('B','O','D','Y'),work,size))
            {
                if (freedata)
                    delete [] data;
                delete [] work;
                return ESCH_ERR_FILEERROR;
            }

            delete [] work;
        }
        else
        {
            delete [] work;

            if (iff->write(iff->makeid('B','O','D','Y'),
                           data,bm->width*bm->height*bpp))
            {
                if (freedata)
                    delete [] data;
                return ESCH_ERR_FILEERROR;
            }
        }

        if (freedata)
            delete [] data;

        //陳� Unlock bitmap
        if (!locked)
            bm->unlock();
    }

    iff->leaveform();

    if (ctrlfl & ESCH_MBLD_INSCENE)
        iff->leaveform();

    return ESCH_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschBuildTexture - load                                                  �
//                                                                          �
// Loads data from a data file into the builder.                            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
esch_error_codes EschBuildTexture::load(const char *fname, const char *tname,
                                        VngoPal *pal)
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
                err=load(&iff,tname,pal);
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

esch_error_codes EschBuildTexture::load(XFParseIFF *iff, const char *tname,
                                        VngoPal *pal)
{
    assertMyth("EschBuildTexture::load needs iff pointer",
               iff);

    release();

//陳 Verify correct form name
    if (iff->chunkid != iff->makeid('F','O','R','M')
        || (iff->formid != iff->makeid('E','M','T','L')
            && iff->formid != iff->makeid('E','M','T','1')))
        return ESCH_ERR_NOTFOUND;

//陳 Enter FORM, find header, verify name if any.
    iff->enterform();

    if (iff->seekchunk(iff->makeid('M','H','D','R'))
        || iff->chunkSize != sizeof(EschFileMtlMHDR))
    {
        iff->leaveform();
        return ESCH_ERR_INVALIDDATA;
    }

    EschFileMtlMHDR header;

    if (iff->read(&header))
    {
        iff->leaveform();
        return ESCH_ERR_FILEERROR;
    }

    if (tname && strncmp(tname,header.name,ESCH_MAX_NAME))
    {
        iff->leaveform();
        return ESCH_ERR_NOTFOUND;
    }

//陳 Verify header
    if (header.nframes < 1
        || (header.compress != ESCH_MTL_COMPRESS_NONE
            && header.compress != ESCH_MTL_COMPRESS_RLE))
    {
        iff->leaveform();
        return ESCH_ERR_NOTSUPPORTED;
    }

//陳 Found, so load
    strncpy(name,header.name,ESCH_MAX_NAME);
    tflags = (header.flags & ~(ESCH_TXT_LOCKED
                               | ESCH_TXT_OWNSDATA
                               | ESCH_TXT_SHARED
                               | ESCH_TXT_TRANSP));

    int bpp;
    switch (header.type)
    {
        case ESCH_MTL_TYPE_8BIT:
        case ESCH_MTL_TYPE_8BIT_TRANSP:
            if (!pal)
            {
                iff->leaveform();
                return ESCH_ERR_INVALIDPARMS;
            }
            bpp = 1;
            break;
        case ESCH_MTL_TYPE_15BIT:
        case ESCH_MTL_TYPE_15BIT_TRANSP:
            bpp = 2;
            break;
        case ESCH_MTL_TYPE_24BIT:
            bpp = 3;
            break;
        case ESCH_MTL_TYPE_32BIT:
            bpp = 4;
            break;
        default:
            iff->leaveform();
            return ESCH_ERR_NOTSUPPORTED;
    }

    switch (header.type)
    {
        case ESCH_MTL_TYPE_8BIT_TRANSP:
        case ESCH_MTL_TYPE_15BIT_TRANSP:
        case ESCH_MTL_TYPE_32BIT:
            tflags |= ESCH_TXT_TRANSP;
            break;
    }

    if (iff->seekchunk(iff->makeid('B','O','D','Y'))
        || !iff->chunkSize)
    {
        iff->leaveform();
        return ESCH_ERR_INVALIDDATA;
    }

//陳 Allocate memory
    nframes = header.nframes;
    bms = new XFBitmap*[header.nframes];
    if (!bms)
    {
        iff->leaveform();
        return ESCH_ERR_NOMEMORY;
    }
    memset(bms,0,sizeof(XFBitmap*) * header.nframes);

//陳� Load body chunks into bitmap array
    for(int f=0;;)
    {
        bms[f] = new XFBitmap;
        if (!bms[f]
            || bms[f]->create(header.xsize,header.ysize,bpp))
        {
            release(1);
            iff->leaveform();
            return ESCH_ERR_NOMEMORY;
        }

        //陳� Copy in palette if needed
        if (bpp == 1)
        {
            for(int i=0; i < 256; i++)
            {
                assert(pal != 0);
                VngoColor24bit clr = pal->hw_pal.p[i];
                bms[f]->pal[i] = (clr.r | (clr.g << 8) | (clr.b << 16));
            }

            if (header.type == ESCH_MTL_TYPE_8BIT_TRANSP)
                bms[f]->pal[255] = 0xff00ff;
        }

        //陳� Handle body
        if (header.compress == ESCH_MTL_COMPRESS_RLE
            && iff->chunkSize < (ulong)(header.xsize * header.ysize * bpp))
        {
            //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Compressed
            byte *work = new byte[iff->chunkSize];
            if (!work)
                return ESCH_ERR_NOMEMORY;

            if (iff->read(work))
            {
                delete [] work;
                release(1);
                iff->leaveform();
                return ESCH_ERR_FILEERROR;
            }

            switch (bpp)
            {
                case 1:
                    if (XFParseXEB::uncompress_rle_8bpp(header.xsize, header.ysize,
                                                        iff->chunkSize, work,
                                                        (byte*)bms[f]->data))
                    {
                        delete [] work;
                        release(1);
                        iff->leaveform();
                        return ESCH_ERR_INVALIDDATA;
                    }
                    break;
                case 2:
                    if (XFParseXEB::uncompress_rle_16bpp(header.xsize, header.ysize,
                                                         iff->chunkSize, work,
                                                         (byte*)bms[f]->data))
                    {
                        delete [] work;
                        release(1);
                        iff->leaveform();
                        return ESCH_ERR_INVALIDDATA;
                    }
                    break;
                case 3:
                    if (XFParseXEB::uncompress_rle_24bpp(header.xsize, header.ysize,
                                                         iff->chunkSize, work,
                                                         (byte*)bms[f]->data))
                    {
                        delete [] work;
                        release(1);
                        iff->leaveform();
                        return ESCH_ERR_INVALIDDATA;
                    }
                    break;
                case 4:
                    if (XFParseXEB::uncompress_rle_32bpp(header.xsize, header.ysize,
                                                         iff->chunkSize, work,
                                                         (byte*)bms[f]->data))
                    {
                        delete [] work;
                        release(1);
                        iff->leaveform();
                        return ESCH_ERR_INVALIDDATA;
                    }
                    break;
            }

            delete [] work;
        }
        else
        {
            //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Uncompressed
            if (iff->chunkSize != (ulong)(header.xsize * header.ysize * bpp))
            {
                release(1);
                iff->leaveform();
                return ESCH_ERR_INVALIDDATA;
            }

            if (iff->read(bms[f]->data))
            {
                release(1);
                iff->leaveform();
                return ESCH_ERR_FILEERROR;
            }
        }

        f++;
        if (f < header.nframes)
        {
            if (iff->seekchunk(iff->makeid('B','O','D','Y'))
                || !iff->chunkSize)
            {
                release(1);
                iff->leaveform();
                return ESCH_ERR_INVALIDDATA;
            }
        }
        else
            break;
    }

//陳� Return OK
    iff->leaveform();
    return ESCH_ERR_NONE;
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭�  Utility Routines  碓旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschBuildTexture - add_frame                                             �
//                                                                          �
// Adds a new frame to the texture.                                         �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
esch_error_codes EschBuildTexture::add_frame(XFBitmap *bm)
{
    assertMyth("EschBuildTexture::add_frame must be called after init",
               bms != 0);

    if (!bm
        || (bm->bpp != 1
            && bm->bpp != 2
            && bm->bpp != 3
            && bm->bpp != 4))
        return ESCH_ERR_INVALIDPARMS;

    if (nframes >= maxframes)
        return ESCH_ERR_NOMORE;

    if (!nframes)
    {
        switch (bm->width)
        {
            case 16:
            case 32:
            case 64:
            case 128:
            case 256:
                break;
            default:
                return ESCH_ERR_INVALIDSIZE;
        }

        switch (bm->height)
        {
            case 16:
            case 32:
            case 64:
            case 128:
            case 256:
                break;
            default:
                return ESCH_ERR_INVALIDSIZE;
        }
    }
    else if (bms[0]->width != bm->width
             || bms[0]->height != bm->height)
        return ESCH_ERR_INVALIDSIZE;

    bms[nframes++] = bm;

    return ESCH_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschBuildTexture - set_frame                                             �
//                                                                          �
// Changes a frame for the mesh.                                            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
esch_error_codes EschBuildTexture::set_frame(ulong i, XFBitmap *bm,
                                             int freeold)
{
    assertMyth("EschBuildTexture::set_frame must be called after init",
               bms != 0);

    if (!bm
        || (bm->bpp != 1
            && bm->bpp != 2
            && bm->bpp != 3
            && bm->bpp != 4)
        || i >= nframes)
        return ESCH_ERR_INVALIDPARMS;

    if (bms[0]->width != bm->width
        || bms[0]->height != bm->height)
        return ESCH_ERR_INVALIDSIZE;

    if (freeold && bms[i])
        delete bms[i];

    bms[i] = bm;

    return ESCH_ERR_NONE;
}

//葦� End of module - esbldtxt.cpp 憶�

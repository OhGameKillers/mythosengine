//���������������������������������������������������������������������������
//           __ ,                                                      
//            ,-| ~           ,               ,,                      
//           ('||/__,        ||               ||                  _   
//          (( |||  | \\ \\ =||=   _-_  \\/\\ ||/|,  _-_  ,._-_  / \\ 
//          (( |||==| || ||  ||   || \\ || || || || || \\  ||   || || 
//           ( / |  , || ||  ||   ||/   || || || |' ||/    ||   || || 
//            -____/  \\/\\  \\,  \\,/  \\ \\ \\/   \\,/   \\,  \\_-| 
//                                                               /  \ 
//                                                              '----`
//                     Text Output and Font Management System
//                          Microsoft Windows '95 Version
//
//            Copyright (c) 1995-1997 by Charybdis Enterprises, Inc.
//                           All Rights Reserved.
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
// gbrgifnt.cpp
//
// Contains the advanced font management routines.
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//                                
//���������������������������������������������������������������������������

#include <assert.h>
#include <string.h>

#include <ivory.hpp>
#include <xfile.hpp>

#include <gutenbrg.hpp>
#include <gbrgfile.hpp>

//���������������������������������������������������������������������������
//
//                               Routines
//
//���������������������������������������������������������������������������

extern "C" GBergFontInfo *igberg_empty_font();

STATIC gberg_error_codes igberg_install_font(XFParseIFF *iff, const char *fntname);

//���������������������������������������������������������������������������
//
//                                 Data
//
//���������������������������������������������������������������������������

extern "C" GBergIData   *GBergInstance;

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// gberg_install_font                                                       �
//                                                                          �
// This installs a new font, loading the data into the handle area and      �
// setting up for a later select.                                           �
//���������������������������������������������������������������������������
extern "C" gberg_error_codes gberg_install_font (const char *fname, const char *fntname)
{
    gberg_error_codes   err;
    GBergFontInfo       *fnt;
    XFParseIFF          iff;

    assertMyth("Gutenberg must be initialized",GBergInstance);

    if (!fname)
        return GBERG_ERR_FILEERROR;

//�� Make current font inactive
    fnt=GBergInstance->font_active;
    if (fnt)
    {

        //�� Check to see if already active
        if (fntname && *fntname == *fnt->name)
        {
            if (!strcmp(fntname,fnt->name))
                return GBERG_ERR_NONE;
        }

        //�� Unlock active
        assertMyth("gberg_install_font found that active font has no data",
                   fnt->data);

        ivory_hunlock(fnt->data);
        fnt->ptr=0;

        GBergInstance->font_active=0;
    }

//�� Open file
    if (iff.open(fname,XF_OPEN_READ))
        return GBERG_ERR_FILEERROR;

//�� Loop until a header with the correct name is found
    err=GBERG_ERR_NONE;

    for(;;)
    {
        if (iff.next() != XF_ERR_NONE)
        {
            return GBERG_ERR_FONTNOTFOUND;
        }

        if (iff.chunkid == iff.makeid('F','O','R','M'))
        {
            if (iff.formid == iff.makeid('G','F','N','T'))
            {
                err=igberg_install_font(&iff,fntname);
                if (!err
                    || err != GBERG_ERR_FONTNOTFOUND)
                    break;
            }
        }
    }

//�� Return ok
    iff.close();
    return err;
}


//�������������������������������������������������������������������������Ŀ
//                            ��� Private ���                               �
// igberg_install_font                                                      �
//                                                                          �
// This installs the new font, assuming that the IFF is pointing to the     �
// correct form.                                                            �
//���������������������������������������������������������������������������
STATIC gberg_error_codes igberg_install_font(XFParseIFF *iff, const char *fntname)
{
    gberg_error_codes   err;
    GBergFontInfo       *fnt;
    GBergFileFontHDR    header;

    assertMyth("igberg_install_font needs iff pointer",
               iff);

//�� Verify correct form name
    if (iff->chunkid != iff->makeid('F','O','R','M')
        || iff->formid != iff->makeid('G','F','N','T'))
        return GBERG_ERR_FONTNOTFOUND;

//�� Enter FORM, find header, verify name if any.
    iff->enterform();

    if (iff->seekchunk(iff->makeid('H','D','R',' '))
        || iff->chunkSize != sizeof(GBergFileFontHDR))
    {
        iff->leaveform();
        return GBERG_ERR_INVALIDDATA;
    }

    if (iff->read(&header))
    {
        iff->leaveform();
        return GBERG_ERR_FILEERROR;
    }

    if (fntname && strncmp(fntname,header.name,GBERG_MAX_NAME))
    {
        iff->leaveform();
        return GBERG_ERR_FONTNOTFOUND;
    }

//�� Found, so setup 
    //�� Get empty slot for font
    fnt=igberg_empty_font();
    if (!fnt)
        return GBERG_ERR_NOMEMORY;

//�� Verify header
    if ( (header.type != GBERG_FNT_MONOFIXED 
          && header.type != GBERG_FNT_MONOFIXEDEX)
         || header.compression)
    {
        iff->leaveform();
        return GBERG_ERR_NOTSUPPORTED;
    }

//�� Fill out data
    strncpy(fnt->name,header.name,GBERG_MAX_NAME);
    fnt->width = header.width;
    fnt->height = header.height;
    fnt->bpc = header.bpc;
    fnt->type = header.type;

    if (!fnt->bpc || !fnt->width || !fnt->height)
    {
        iff->leaveform();
        return GBERG_ERR_INVALIDDATA;
    }


    int numchars = (header.type == GBERG_FNT_MONOFIXEDEX) ? 256 : 128;

    if ((fnt->data=ivory_halloc(numchars*fnt->bpc))==0)
    {
        iff->leaveform();
        return GBERG_ERR_NOMEMORY;
    }

    fnt->ptr=(byte*)ivory_hlock(fnt->data);
    if (!fnt->ptr)
    {
        iff->leaveform();
        ivory_hfree(&fnt->data);
        return GBERG_ERR_LOCKFAILED;
    }

    while (!iff->next())
    {

        if (iff->chunkid == iff->makeid('B','O','D','Y'))
        {
            assertMyth("igberg_install_font only loads monochrome fonts",
                       header.type == GBERG_FNT_MONOFIXED);

            if (iff->chunkSize != (ulong)(numchars * fnt->bpc))
            {
                err=GBERG_ERR_INVALIDDATA;
                goto error_exit;
            }

            if (iff->read(fnt->ptr))
            {
                err=GBERG_ERR_FILEERROR;
                goto error_exit;
            }
        }
    }

//�� Make font active
    assertMyth("igberg_install_font no assumes there is no active font",
               !GBergInstance->font_active);
    GBergInstance->font_active=fnt;

    iff->leaveform();
    return GBERG_ERR_NONE;

error_exit:;
    if (fnt->data)
    {
        if (fnt->ptr)
        {
            ivory_hunlock(fnt->data);
            fnt->ptr=0;
        }
        ivory_hfree(&fnt->data);
    }
    memset(fnt,0,sizeof(GBergFontInfo));

    iff->leaveform();
    return err;
}


//�������������������������������������������������������������������������Ŀ
// gberg_info_font                                                          �
//                                                                          �
// Returns information about the given font.  If fntname is empty, it will  �
// return information for any current font.                                 �
//���������������������������������������������������������������������������
extern "C" gberg_error_codes gberg_info_font(const char *fntname, GBergFontInfo *info)
{
    ulong           i;
    GBergFontInfo   *fnt;

    assertMyth("Gutenberg must be initialized",GBergInstance);

    if (!fntname || !*fntname)
    {
    //�� No name means use the active font
        if ((fnt = GBergInstance->font_active) != 0)
        {
            *info = *fnt;
            return GBERG_ERR_NONE;
        }
    }
    else
    {
    //�� Search for given font name
        for (i = 0, fnt = &GBergInstance->fonts[0]; i < GBergInstance->fonts_hi; i++, fnt++)
        {
            if (*fntname == *fnt->name)
            {
                if (!strcmp (fntname, fnt->name))
                {
                    *info = *fnt;
                    return GBERG_ERR_NONE;
                }
            }
        }
    }

    return GBERG_ERR_FONTNOTINSTALLED;
}


//�������������������������������������������������������������������������Ŀ
// gberg_widthc                                                             �
//                                                                          �
// Returns the width of the given character in the current font, or 0 if    �
// no font is selected.                                                     �
//���������������������������������������������������������������������������
long gberg_widthc(char c)
{
    assertMyth("Gutenberg must be initialized",GBergInstance);

    return (GBergInstance->font_active) ?
                            GBergInstance->font_active->width
                            : 0;
}


//�������������������������������������������������������������������������Ŀ
// gberg_heightc                                                            �
//                                                                          �
// Returns the height of the given character in the current font, or 0 if   �
// no font is selected.                                                     �
//���������������������������������������������������������������������������
long gberg_heightc(char c)
{
    assertMyth("Gutenberg must be initialized",GBergInstance);

    return (GBergInstance->font_active) ?
                            GBergInstance->font_active->height
                            : 0;
}

//��� End of module - gbrgifnt.cpp ���


//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
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
//                       Microsoft Windows 95/98/NT Version
//
//  Copyright (c) 1995-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
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
// gbrgifnt.cpp
//
// Contains the advanced font management routines.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <assert.h>
#include <string.h>

#include <ivory.hpp>
#include <xfile.hpp>

#include <gutenbrg.hpp>
#include <gbrgfile.hpp>

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Routines
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

extern "C" GBergFontInfo *igberg_empty_font();

STATIC gberg_error_codes igberg_install_font(XFParseIFF *iff, const char *fntname);

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

extern "C" GBergIData   *GBergInstance;

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// gberg_install_font                                                       �
//                                                                          �
// This installs a new font, loading the data into the handle area and      �
// setting up for a later select.                                           �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
extern "C" gberg_error_codes gberg_install_font (const char *fname, const char *fntname)
{
    gberg_error_codes   err;
    GBergFontInfo       *fnt;
    XFParseIFF          iff;

    assertMyth("Gutenberg must be initialized",GBergInstance);

    if (!fname)
        return GBERG_ERR_FILEERROR;

//陳 Make current font inactive
    fnt=GBergInstance->font_active;
    if (fnt)
    {

        //陳 Check to see if already active
        if (fntname && *fntname == *fnt->name)
        {
            if (!strcmp(fntname,fnt->name))
                return GBERG_ERR_NONE;
        }

        //陳 Unlock active
        assertMyth("gberg_install_font found that active font has no data",
                   fnt->data);

        ivory_hunlock(fnt->data);
        fnt->ptr=0;

        GBergInstance->font_active=0;
    }

//陳 Open file
    if (iff.open(fname,XF_OPEN_READ))
        return GBERG_ERR_FILEERROR;

//陳 Loop until a header with the correct name is found
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

//陳 Return ok
    iff.close();
    return err;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//                            旭� Private 旭�                               �
// igberg_install_font                                                      �
//                                                                          �
// This installs the new font, assuming that the IFF is pointing to the     �
// correct form.                                                            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
STATIC gberg_error_codes igberg_install_font(XFParseIFF *iff, const char *fntname)
{
    gberg_error_codes   err;
    GBergFontInfo       *fnt;
    GBergFileFontHDR    header;

    assertMyth("igberg_install_font needs iff pointer",
               iff);

//陳 Verify correct form name
    if (iff->chunkid != iff->makeid('F','O','R','M')
        || iff->formid != iff->makeid('G','F','N','T'))
        return GBERG_ERR_FONTNOTFOUND;

//陳 Enter FORM, find header, verify name if any.
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

//陳 Found, so setup
    //陳 Get empty slot for font
    fnt=igberg_empty_font();
    if (!fnt)
        return GBERG_ERR_NOMEMORY;

//陳 Verify header
    switch (header.type)
    {
        case GBERG_FNT_MONOFIXED:
        case GBERG_FNT_MONOFIXEDEX:
        case GBERG_FNT_MONOVARIABLE:
        case GBERG_FNT_MONOVARIABLEEX:
            break;
        default:
            iff->leaveform();
            return GBERG_ERR_NOTSUPPORTED;
    }

    if (header.compression)
    {
        iff->leaveform();
        return GBERG_ERR_NOTSUPPORTED;
    }

//陳 Fill out data
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

    int numchars = 128;
    switch (header.type)
    {
        case GBERG_FNT_MONOFIXEDEX:
        case GBERG_FNT_MONOVARIABLEEX:
            numchars = 256;
            break;
    }

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

//陳 Make font active
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


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// gberg_info_font                                                          �
//                                                                          �
// Returns information about the given font.  If fntname is empty, it will  �
// return information for any current font.                                 �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
extern "C" gberg_error_codes gberg_info_font(const char *fntname, GBergFontInfo *info)
{
    ulong           i;
    GBergFontInfo   *fnt;

    assertMyth("Gutenberg must be initialized",GBergInstance);

    if (!fntname || !*fntname)
    {
    //陳 No name means use the active font
        if ((fnt = GBergInstance->font_active) != 0)
        {
            *info = *fnt;
            return GBERG_ERR_NONE;
        }
    }
    else
    {
    //陳 Search for given font name
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


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// gberg_widthc                                                             �
//                                                                          �
// Returns the width of the given character in the current font, or 0 if    �
// no font is selected.                                                     �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
long gberg_widthc(char c)
{
    assertMyth("Gutenberg must be initialized",GBergInstance);

    GBergFontInfo   *fnt=GBergInstance->font_active;

    if (!fnt)
        return 0;

    switch (fnt->type)
    {
        case GBERG_FNT_MONOFIXED:
        case GBERG_FNT_MONOFIXEDEX:
            return GBergInstance->font_active->width;

        case GBERG_FNT_MONOVARIABLE:
            {
                byte *ptr = (byte *)((byte *)fnt->ptr + (c*fnt->bpc));
                return *ptr;
            }

        case GBERG_FNT_MONOVARIABLEEX:
            {
                byte *ptr = (byte *)((byte *)fnt->ptr + ((byte)c*fnt->bpc));
                return *ptr;
            }

        default:
            return 0;
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// gberg_heightc                                                            �
//                                                                          �
// Returns the height of the current font, or 0 if no font is selected.     �                                                �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
long gberg_heightc()
{
    assertMyth("Gutenberg must be initialized",GBergInstance);

    return (GBergInstance->font_active) ?
                            GBergInstance->font_active->height
                            : 0;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// gberg_width                                                              �
//                                                                          �
// Returns the width of the given string in the current font, or 0 if       �
// no font is selected.                                                     �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
long gberg_width(const char *str)
{
    assertMyth("Gutenberg must be initialized",GBergInstance);

    GBergFontInfo   *fnt=GBergInstance->font_active;

    if (!fnt)
        return 0;

    switch (fnt->type)
    {
        case GBERG_FNT_MONOFIXED:
        case GBERG_FNT_MONOFIXEDEX:
            return (GBergInstance->font_active->width * strlen(str));

        case GBERG_FNT_MONOVARIABLE:
            {
                long len=0;
                for(const char *ch = str; *ch != 0; ch++)
                {
                    byte *ptr = (byte *)((byte *)fnt->ptr + ((*ch)*fnt->bpc));
                    len += *ptr;
                }
                return len;
            }

        case GBERG_FNT_MONOVARIABLEEX:
            {
                long len=0;
                for(const byte *ch = (const byte *)str; *ch != 0; ch++)
                {
                    byte *ptr = (byte *)((byte *)fnt->ptr + ((*ch)*fnt->bpc));
                    len += *ptr;
                }
                return len;
            }

        default:
            return 0;
    }
}

//葦� End of module - gbrgifnt.cpp 憶�



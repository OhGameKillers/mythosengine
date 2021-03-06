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
// gutenbrg.c
//
// Contains the library initialization and terminate code, as well as some
// required support routines.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <assert.h>
#include <string.h>

#include "gutenbrg.h"

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

GBergIData   *GBergInstance=0;

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// gberg_init                                                               �
//                                                                          �
// Initializes the internal data structures.                                �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
gberg_error_codes gberg_init()
{
//陳 Safeguard
    if (GBergInstance)
        return GBERG_ERR_NONE;

//陳 Allocate memory structure
    if ((GBergInstance=ivory_zalloc(sizeof(GBergIData)))==0)
    {
        return GBERG_ERR_NOMEMORY;
    }

//陳 Font Initialization
    GBergInstance->fcol = 1;
    GBergInstance->bcol = 0;

    assertMyth("gberg_init needs valid complie-time constant",
               GBERG_INIT_FONT > 0);

    if ((GBergInstance->fonts=ivory_zalloc(sizeof(GBergFontInfo)*GBERG_INIT_FONT))==0)
    {
        gberg_term();
        return GBERG_ERR_NOMEMORY;
    }
    GBergInstance->fonts_max=GBERG_INIT_FONT;

//陳 Text Initialization
    assertMyth("gberg_init needs valid complie-time constant",
               GBERG_INIT_TEXT > 0);

    if ((GBergInstance->text=ivory_zalloc(sizeof(GBergTextInfo)*GBERG_INIT_TEXT))==0)
    {
        gberg_term();
        return GBERG_ERR_NOMEMORY;
    }
    GBergInstance->text_max=GBERG_INIT_TEXT;

//陳 Return error
    return GBERG_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// gberg_term                                                               �
//                                                                          �
// Termintes the internal data structures, releasing all memory in use.     �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void gberg_term()
{
    dword i;

//陳 Safeguard
    if (!GBergInstance)
        return;

//陳 Release fonts
    if (GBergInstance->fonts)
    {
        for(i=0; i < GBergInstance->fonts_max; i++)
        {
            if (GBergInstance->fonts[i].data)
            {
                ivory_hfree(&GBergInstance->fonts[i].data);
            }
        }

        ivory_free(&GBergInstance->fonts);
    }

//陳 Release text
    if (GBergInstance->text)
    {
        for(i=0; i < GBergInstance->text_max; i++)
        {
            if (GBergInstance->text[i].data)
            {
                ivory_hfree(&GBergInstance->text[i].data);
            }
        }

        ivory_free(&GBergInstance->text);
    }

//陳 Release memory structure
    ivory_free(&GBergInstance);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//                          旭� Internal 旭�                                �
// igberg_empty_font                                                        �
//                                                                          �
// This finds an empty slot for installing a new font.                      �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
GBergFontInfo *igberg_empty_font()
{
    dword           i;
    GBergFontInfo   *fnt;

//陳 Safeguard
    assertMyth("Gutenberg must be initialized",GBergInstance);

    assertMyth("igberg_empty_font assumes fonts data blocks allocated",
               GBergInstance->fonts && (GBergInstance->fonts_hi <= GBergInstance->fonts_max));

//陳 Search for empty slot
    for(i=0, fnt=GBergInstance->fonts; i < GBergInstance->fonts_hi; i++, fnt++)
    {
        if (!fnt->data)
            return fnt;
    }

//陳 Take new slot
    if (++GBergInstance->fonts_hi >= GBergInstance->fonts_max)
    {

//陳 Must expand array
        if ((fnt=ivory_zalloc(sizeof(GBergFontInfo)*GBergInstance->fonts_max*2))==0)
        {
            return 0;
        }
        memcpy(fnt,GBergInstance->fonts,sizeof(GBergFontInfo)*GBergInstance->fonts_max);
        ivory_free(&GBergInstance->fonts);

        GBergInstance->fonts = fnt;
        GBergInstance->fonts_max *= 2;
    }

    return &GBergInstance->fonts[GBergInstance->fonts_hi-1];
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//                          旭� Internal 旭�                                �
// igberg_empty_strings                                                     �
//                                                                          �
// This finds an empty slot for installing a new text.                      �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
GBergTextInfo *igberg_empty_strings()
{
    dword           i;
    GBergTextInfo   *txt;

//陳 Safeguard
    assertMyth("Gutenberg must be initialized",GBergInstance);

    assertMyth("igberg_empty_strings assumes text data blocks allocated",
               GBergInstance->text && (GBergInstance->text_hi <= GBergInstance->text_max));

//陳 Search for empty slot
    for(i=0, txt=GBergInstance->text; i < GBergInstance->text_hi; i++, txt++)
    {
        if (!txt->data)
            return txt;
    }

//陳 Take new slot
    if (++GBergInstance->text_hi >= GBergInstance->text_max)
    {

//陳 Must expand array
        if ((txt=ivory_zalloc(sizeof(GBergTextInfo)*GBergInstance->text_max*2))==0)
        {
            return 0;
        }
        memcpy(txt,GBergInstance->text,sizeof(GBergTextInfo)*GBergInstance->text_max);
        ivory_free(&GBergInstance->text);

        GBergInstance->text = txt;
        GBergInstance->text_max *= 2;
    }

    return &GBergInstance->text[GBergInstance->text_hi-1];
}


//葦� End of module - gutenbrg.c 憶�


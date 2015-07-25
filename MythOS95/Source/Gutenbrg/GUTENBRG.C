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
// gutenbrg.c
//
// Contains the library initialization and terminate code, as well as some
// required support routines.
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//                                
//���������������������������������������������������������������������������

#include <assert.h>
#include <string.h>

#include "gutenbrg.h"

//���������������������������������������������������������������������������
//
//                                 Data
//
//���������������������������������������������������������������������������

GBergIData   *GBergInstance=0;

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// gberg_init                                                               �
//                                                                          �
// Initializes the internal data structures.                                �
//���������������������������������������������������������������������������
gberg_error_codes gberg_init()
{
//�� Safeguard
    if (GBergInstance)
        return GBERG_ERR_NONE;

//�� Allocate memory structure
    if ((GBergInstance=ivory_zalloc(sizeof(GBergIData)))==0)
    {
        return GBERG_ERR_NOMEMORY;
    }

//�� Font Initialization
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

//�� Text Initialization
    assertMyth("gberg_init needs valid complie-time constant",
               GBERG_INIT_TEXT > 0);

    if ((GBergInstance->text=ivory_zalloc(sizeof(GBergTextInfo)*GBERG_INIT_TEXT))==0)
    {
        gberg_term();
        return GBERG_ERR_NOMEMORY;
    }
    GBergInstance->text_max=GBERG_INIT_TEXT;

//�� Return error
    return GBERG_ERR_NONE;
}


//�������������������������������������������������������������������������Ŀ
// gberg_term                                                               �
//                                                                          �
// Termintes the internal data structures, releasing all memory in use.     �
//���������������������������������������������������������������������������
void gberg_term()
{
    dword i;

//�� Safeguard
    if (!GBergInstance)
        return;

//�� Release fonts
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

//�� Release text
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

//�� Release memory structure
    ivory_free(&GBergInstance);
}


//�������������������������������������������������������������������������Ŀ
//                          ��� Internal ���                                �
// igberg_empty_font                                                        �
//                                                                          �
// This finds an empty slot for installing a new font.                      �
//���������������������������������������������������������������������������
GBergFontInfo *igberg_empty_font()
{
    dword           i;
    GBergFontInfo   *fnt;

//�� Safeguard
    assertMyth("Gutenberg must be initialized",GBergInstance);

    assertMyth("igberg_empty_font assumes fonts data blocks allocated",
               GBergInstance->fonts && (GBergInstance->fonts_hi <= GBergInstance->fonts_max));

//�� Search for empty slot
    for(i=0, fnt=GBergInstance->fonts; i < GBergInstance->fonts_hi; i++, fnt++)
    {
        if (!fnt->data)
            return fnt;
    }
    
//�� Take new slot
    if (++GBergInstance->fonts_hi >= GBergInstance->fonts_max)
    {

//�� Must expand array
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


//�������������������������������������������������������������������������Ŀ
//                          ��� Internal ���                                �
// igberg_empty_strings                                                     �
//                                                                          �
// This finds an empty slot for installing a new text.                      �
//���������������������������������������������������������������������������
GBergTextInfo *igberg_empty_strings()
{
    dword           i;
    GBergTextInfo   *txt;

//�� Safeguard
    assertMyth("Gutenberg must be initialized",GBergInstance);

    assertMyth("igberg_empty_strings assumes text data blocks allocated",
               GBergInstance->text && (GBergInstance->text_hi <= GBergInstance->text_max));

//�� Search for empty slot
    for(i=0, txt=GBergInstance->text; i < GBergInstance->text_hi; i++, txt++)
    {
        if (!txt->data)
            return txt;
    }
    
//�� Take new slot
    if (++GBergInstance->text_hi >= GBergInstance->text_max)
    {

//�� Must expand array
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


//��� End of module - gutenbrg.c ���

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
// gutenbrg.h
//
// C-interface include header.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

#ifndef __GUTENBRG_H
#define __GUTENBRG_H    1

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

#ifdef __cplusplus
extern "C" {
#endif

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <ivory.h>

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳� Constants
#define GBERG_MAX_NAME              16
#define GBERG_INIT_FONT             2
#define GBERG_INIT_TEXT             2


//陳� Error codes for Guttenberg functions.
typedef enum _gberg_error_codes {
    GBERG_ERR_NONE                  =0,
    GBERG_ERR_NOMEMORY              =1,
    GBERG_ERR_LOCKFAILED            =2,
    GBERG_ERR_FILEERROR             =3,
    GBERG_ERR_INVALIDDATA           =4,
    GBERG_ERR_NOTSUPPORTED          =5,

    GBERG_ERR_FONTNOTINSTALLED      =20,
    GBERG_ERR_FONTNOTFOUND          =21,

    GBERG_ERR_TEXTNOTINSTALLED      =30,
    GBERG_ERR_TEXTNOTFOUND          =31,

    GBERG_ERR_STRINGNOTFOUND        =40,
} gberg_error_codes;


//陳� Font Types
#define GBERG_FNT_MONOFIXED         0 // 128 chars, monochrome, fixed size
#define GBERG_FNT_COLORFIXED        1 // 128 chars, 256 color, fixed size

#define GBERG_FNT_MONOFIXEDEX       10 // 256 chars, monochrone, fixed size

#define GBERG_FNT_MONOVARIABLE      20 // 128 chars, monochrome, variable size

#define GBERG_FNT_MONOVARIABLEEX    30 // 256 chars, monochrome, variable size


//陳� Flags for gberg_outf
#define GBERG_FMT_LEFT              0x1
#define GBERG_FMT_CENTER            0x2
#define GBERG_FMT_RIGHT             0x4
#define GBERG_FMT_TOP               0x8
#define GBERG_FMT_MIDDLE            0x10
#define GBERG_FMT_BOTTOM            0x20
#define GBERG_FMT_WORDWRAP          0x40

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Structures
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// Font information structure.                                              �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
typedef struct GBergFontInfo
{
    char                name[GBERG_MAX_NAME];   // Name
    ushort              width;                  // Size (max width)
    ushort              height;
    ushort              bpc;                    // Bytes/character
    ushort              type;                   // Type
    byte                *ptr;                   // 0 if unlocked
    IvoryHandle         data;                   // Data handle
} GBergFontInfo;


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// Text information structure.                                              �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
typedef struct GBergTextInfo
{
    char                name[GBERG_MAX_NAME];   // Name
    ulong               number_of_strings;
    IvoryHandle         data;                   // Data handle
} GBergTextInfo;


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// Internal data structures.                                                �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
typedef struct GBergIData
{
    //陳� Font Data
    GBergFontInfo   *font_active;
    dword           fcol, bcol;
    dword           fonts_hi;
    dword           fonts_max;
    GBergFontInfo   *fonts;
    dword           na1[10];

    //陳� Text Data
    GBergTextInfo   *text_active;
    dword           text_hi;
    dword           text_max;
    GBergTextInfo   *text;

    //陳� Future space
    dword           na[26];
} GBergIData;

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Prototypes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// Library control functions.                                               �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
gberg_error_codes gberg_init();
void gberg_term();

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// Text output functions.                                                   �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

// these must be C++ since Van Gogh is not C-callable

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// Font control functions.                                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
gberg_error_codes gberg_color(dword fcol, dword bcol);
gberg_error_codes gberg_select_font(const char *fntname);
gberg_error_codes gberg_install_font(const char *fname, const char *fntname);
gberg_error_codes gberg_info_font(const char *fntname, GBergFontInfo *info);
gberg_error_codes gberg_remove_font(const char *fntname);

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// External string functions.                                               �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
gberg_error_codes gberg_loadstring(ulong num, char *buff, ulong len);
gberg_error_codes gberg_select_strings(const char *txtname);
gberg_error_codes gberg_install_strings(const char *fname, const char *txtname);
gberg_error_codes gberg_info_strings(const char *txtname, GBergTextInfo *info);
gberg_error_codes gberg_remove_strings(const char *txtname);

#ifdef __cplusplus
}
#endif

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//葦� End of header - gutenbrg.h 憶�


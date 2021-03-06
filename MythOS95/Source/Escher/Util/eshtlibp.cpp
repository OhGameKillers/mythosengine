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
//                              *** Utilities ***
//
// Created by Chuck Walbourn
//
// eshtlibp.cpp
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <conio.h>
#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>

#include "debug.h"
#include "xfile.hpp"
#include "escher.hpp"
#include "esfile.hpp"

#include "eshtlib.h"
#include "eshtltok.h"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#define MAX_FRAMES      128

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Routines
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳 External from scanner.
extern "C" int yylex();
extern "C" int yy_pushfile(const char *fname);

//陳 External from main module.
void print_error(XFParseIFF *xp, char *s=0);

int extract(XFParseIFF &iff);

int find_txtname(const char *n);
int add_txtname(const char *n);

//陳 Local
STATIC void ctf();
STATIC void include();
STATIC void description();
STATIC void copyright();
STATIC void author();
STATIC void extract();
STATIC void texture();
STATIC void txtopts(EschBuildTexture &tbld, dword &ctrlfl);

STATIC ulong uinteger(void);
STATIC ulong uexpr(void);
STATIC ulong uterm(void);
STATIC ulong ufactor(void);

STATIC void match(int tok);
extern "C" void error(const char *str);
extern "C" void warning(const char *str);

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//陳 External from scanner.
extern "C" long     YY_integer;
extern "C" int      YY_lineno;
extern "C" int      YY_esc_allowed;
extern "C" char     *yytext;
extern "C" int      yyleng;

//陳 External from main module.
extern XFParseIFF   *TxtIFF;
extern XFParseIFF   *RmdrIFF;
extern dword        Flags;
extern VngoPal      *Palette;

//陳 Local
STATIC int          CurrentToken;

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// compile                                                                  �
//                                                                          �
// Parses file into output IFF(s) (both already opened by main).            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void compile()
{
    assert(TxtIFF != 0);

    CurrentToken = yylex();
    while (CurrentToken)
    {
        ctf();
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// ctf                                                                      �
//                                                                          �
//          ctf :- include                                                  �
//                 description                                              �
//                 copyright                                                �
//                 author                                                   �
//                 extract                                                  �
//                 texture                                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void ctf()
{
    switch (CurrentToken)
    {
        case YY_INCLUDE:
            include();
            break;
        case YY_DESC:
            description();
            break;
        case YY_COPYRIGHT:
            copyright();
            break;
        case YY_AUTHOR:
            author();
            break;
        case YY_EXTRACT:
            extract();
            break;
        case YY_TEXTURE:
            texture();
            break;
        default:
            error("Invalid operation: expected include, description, "
                  " copyright, author, extract, or texture statement");
            break;
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// include                                                                  �
//                                                                          �
//     include :- 'include' <string>                                        �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
STATIC void include()
{
    int err;

    YY_esc_allowed=0;
    match(YY_INCLUDE);
    YY_esc_allowed=1;

    switch(CurrentToken)
    {
        case YY_STRING:
            if (!(Flags & FLAGS_QUIET))
            {
                cout << "   旭� including '" << yytext << "' 旭�\n";
            }

            err=yy_pushfile(yytext);
            switch (err)
            {
                case 0:
                    /* OK */
                    break;
                case 1:
                    error("too many nested includes");
                    break;
                case 2:
                    error("could not open include file");
                    break;
                case 3:
                    error("not enough memory to include file");
                default:
                    error("include failed");
                    break;
            }

            // Read first token from new file and continue processing
            // yywrap will undo include later

            CurrentToken = yylex();

            break;
        default:
            error("Invalid include command, expecting filename of CTF file to include");
            break;
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// description                                                              �
//                                                                          �
//     description :- 'description' <string>                                �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
STATIC void description()
{
    match(YY_DESC);

    switch(CurrentToken)
    {
        case YY_STRING:
            yytext[yyleng]=0;
            if (TxtIFF->write(TxtIFF->makeid('D','E','S','C'),
                              yytext, yyleng))
            {
                print_error(TxtIFF,"Could not create description");
                exit(1);
            }

            match(YY_STRING);
            break;
        default:
            error("'description' must be followed by a string.");
            break;
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// copyright                                                                �
//                                                                          �
//     copyright :- 'copyright' <string>                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
STATIC void copyright()
{
    match(YY_COPYRIGHT);

    switch(CurrentToken)
    {
        case YY_STRING:
            yytext[yyleng]=0;
            if (TxtIFF->write(TxtIFF->makeid('(','C',')',' '),
                              yytext, yyleng))
            {
                print_error(TxtIFF,"Could not create copyright");
                exit(1);
            }

            match(YY_STRING);
            break;
        default:
            error("'copyright' must be followed by a string.");
            break;
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// author                                                                   �
//                                                                          �
//     author :- 'author' <string>                                          �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
STATIC void author()
{
    match(YY_AUTHOR);

    switch(CurrentToken)
    {
        case YY_STRING:
            yytext[yyleng]=0;
            if (TxtIFF->write(TxtIFF->makeid('A','U','T','H'),
                              yytext, yyleng))
            {
                print_error(TxtIFF,"Could not create author");
                exit(1);
            }

            match(YY_STRING);
            break;
        default:
            error("'author' must be followed by a string.");
            break;
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// extract                                                                  �
//                                                                          �
//     extract :- 'extract' <string>                                        �
//                          '{' (<string> [','])* '}'                       �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
STATIC void extract()
{
    YY_esc_allowed=0;
    match(YY_EXTRACT);

    if (CurrentToken == YY_LBRACE)
    {
        match(YY_LBRACE);

        while (CurrentToken && CurrentToken != YY_RBRACE)
        {
            if (CurrentToken != YY_STRING)
            {
                error("'extract {' must be followed filenames and then '}'");
                exit(1);
            }

            if (!(Flags & FLAGS_QUIET))
            {
                cout << "Extracting '" << yytext << "'...\n";
            }

            XFParseIFF iff;
            if (iff.open(yytext, XF_OPEN_READ | XF_OPEN_DENYWRITE))
            {
                error("Failed to open input file for 'extract'");
                exit(1);
            }

            if (extract(iff))
                error("Extract failed.");

            iff.close();

            match(YY_STRING);

            if (CurrentToken == YY_COMMA)
                match(YY_COMMA);
        }

        YY_esc_allowed=1;
        match(YY_RBRACE);
    }
    else if (CurrentToken != YY_STRING)
    {
        error("'extract' must be followed by a filename or '{' filename(s) '}'");
        exit(1);
    }
    else
    {
        if (!(Flags & FLAGS_QUIET))
        {
            cout << "Extracting '" << yytext << "'...\n";
        }

        XFParseIFF iff;
        if (iff.open(yytext, XF_OPEN_READ | XF_OPEN_DENYWRITE))
        {
            error("Failed to open input file for 'extract'");
            exit(1);
        }

        if (extract(iff))
            error("Extract failed.");

        iff.close();

        YY_esc_allowed=1;
        match(YY_STRING);
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// texture                                                                  �
//                                                                          �
//     texture :- 'texture' <string> txtopts '{' <string>* '}'              �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
STATIC void texture()
{
    match(YY_TEXTURE);

//陳� Setup control flags
    dword ctrlfl=0;
    if (!(Flags & FLAGS_UNCOMPRESS))
        ctrlfl |= ESCH_TBLD_COMPRESS;
    if (Flags & FLAGS_XPARENT)
        ctrlfl |= ESCH_TBLD_TRANSP;

//陳� Setup texture builder
    EschBuildTexture txt;
    if (txt.init(MAX_FRAMES))
    {
        error("out of memory for texture builder");
        exit(1);
    }

    if (CurrentToken != YY_STRING)
    {
        error("'texture' must be followed by texture name");
        exit(1);
    }

    if (find_txtname(yytext))
    {
        warning("texture name already exists in texture file");
    }
    else if (add_txtname(yytext))
    {
        error("Out of memory for texture names");
    }

    strncpy(txt.name,yytext,ESCH_MAX_NAME);

    match(YY_STRING);

//陳� Match options
    while (CurrentToken && CurrentToken != YY_LBRACE)
    {
        txtopts(txt,ctrlfl);
    }

    YY_esc_allowed=0;
    match(YY_LBRACE);

//陳� Output info
    if (!(Flags & FLAGS_QUIET))
    {
        cout << "Compiling texture '" << txt.name << "'...\n";
    }

//陳� Match bitmap names
    while (CurrentToken && CurrentToken != YY_RBRACE)
    {
        if (CurrentToken != YY_STRING)
        {
            error("'texture' must be followed by '{' bitmap filenames and then '}'");
            exit(1);
        }

        if (!(Flags & FLAGS_QUIET))
        {
            cout << "   Adding frame '" << yytext << "'...\n";
        }

        strlwr(yytext);

        XFBitmap *bm = new XFBitmap;
        assert(bm != 0);

        xf_error_codes err=XF_ERR_NONE;
        if (strstr(yytext,".tga"))
        {
            XFParseTGA  tga;

            err=tga.nameread(yytext,bm);
        }
        else if (strstr(yytext,".pcx"))
        {
            XFParsePCX  pcx;

            err=pcx.nameread(yytext,bm);
        }
        else if (strstr(yytext,".lbm"))
        {
            XFParseLBM  lbm;

            err=lbm.nameread(yytext,bm);
        }
        else if (strstr(yytext,".cel"))
        {
            XFParseCEL  cel;

            err=cel.nameread(yytext,bm);
        }
        else if (strstr(yytext,".bmp"))
        {
            XFParseBMP  bmp;

            err=bmp.nameread(yytext,bm);
        }
        else if (strstr(yytext,".xeb"))
        {
            XFParseXEB  xeb;

            err=xeb.nameread(yytext,bm);
        }
        else
        {
            error("Unknown bitmap image extender\n");
            exit(1);
        }
        if (err)
        {
            error("Failed to load bitmap");
            exit(1);
        }

        if (txt.add_frame(bm))
        {
            error("Failed to add bitmap to texture");
            exit(1);
        }

        match(YY_STRING);

        if (CurrentToken == YY_COMMA)
            match(YY_COMMA);
    }

    YY_esc_allowed=1;
    match(YY_RBRACE);

    if (txt.nframes < 1)
    {
        error("'texture' needs at least one bitmap filename");
        exit(1);
    }

    if (!(ctrlfl & (ESCH_TBLD_8BIT | ESCH_TBLD_15BIT | ESCH_TBLD_TC)))
    {
        if (txt.bms[0]->bpp == 1)
        {
            ctrlfl |= ESCH_TBLD_8BIT;
        }
        else if (txt.bms[0]->bpp == 2)
        {
            ctrlfl |= ESCH_TBLD_15BIT;
        }
        else if (txt.bms[0]->bpp == 3)
        {
            ctrlfl |= ESCH_TBLD_TC;
            ctrlfl &= ~ESCH_TBLD_TRANSP;
        }
        else if (txt.bms[0]->bpp == 4)
        {
            ctrlfl |= ESCH_TBLD_TC | ESCH_TBLD_TRANSP;
        }
        else
        {
            error("Invalid bit-depth for frames");
            exit(1);
        }
    }

//陳� Write texture
    esch_error_codes err = txt.save(TxtIFF, ctrlfl, Palette);
    if (err)
    {
        char buff[128];
        sprintf(buff,"Failed to write texture (error #%d)",err);
        error(buff);
        exit(1);
    }

    txt.release(1);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// txtopts                                                                  �
//                                                                          �
//     txtopts :- 'rle'                                                     �
//                'uncompressed'                                            �
//                'flags' '=' <uinteger>                                    �
//                'transparent'                                             �
//                'notransparent'                                           �
//                'bpp' <integer>                                           �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
STATIC void txtopts(EschBuildTexture &tbld, dword &ctrlfl)
{
    switch (CurrentToken)
    {
        case YY_LBRACE:
            break;

        case YY_RLE:
            match(YY_RLE);
            ctrlfl |= ESCH_TBLD_COMPRESS;
            break;

        case YY_UNCOMPRESSED:
            match(YY_UNCOMPRESSED);
            ctrlfl &= ~ESCH_TBLD_COMPRESS;
            break;

        case YY_FLAGS:
            match(YY_FLAGS);
            match(YY_EQUAL);
            tbld.tflags = uexpr();
            break;

        case YY_TRANSPARENT:
            match(YY_TRANSPARENT);
            ctrlfl |= ESCH_TBLD_TRANSP;
            break;

        case YY_NOTRANSPARENT:
            match(YY_NOTRANSPARENT);
            ctrlfl &= ~ESCH_TBLD_TRANSP;
            break;

        case YY_BPP:
            {
                match(YY_BPP);
                match(YY_EQUAL);
                ctrlfl &= ~(ESCH_TBLD_8BIT | ESCH_TBLD_15BIT | ESCH_TBLD_TC);
                ulong bpp = uexpr();
                switch (bpp)
                {
                    case 1:
                        ctrlfl |= ESCH_TBLD_8BIT;
                        break;
                    case 2:
                        ctrlfl |= ESCH_TBLD_15BIT;
                        break;
                    case 3:
                        ctrlfl |= ESCH_TBLD_TC;
                        ctrlfl &= ~ESCH_TBLD_TRANSP;
                        break;
                    case 4:
                        ctrlfl |= ESCH_TBLD_TC | ESCH_TBLD_TRANSP;
                        break;

                    default:
                        error("bpp must be followed by a 1, 2, 3, or 4");
                        break;
                }
            }
            break;

        default:
            error("expected 'rle', 'uncompressed', 'flags', 'transparent', "
                  "'notransparent', 'bpp', or '{'");
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// uinteger/uexpr                                                           �
//                                                                          �
// Unsigned integer expression parsers.                                     �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
STATIC ulong uinteger(void)
{
    ulong   t=0;

    if (CurrentToken == YY_INTEGER)
    {
        t=(ulong)YY_integer;
        match(YY_INTEGER);
    }

    return(t);
}


STATIC ulong uexpr(void)
{
    ulong   t1, t2;

    t1 = uterm();
    switch(CurrentToken)
    {
        case YY_PLUS:
            match(YY_PLUS);
            t2 = uterm();
            return (t1 + t2);
        case YY_MINUS:
            match(YY_MINUS);
            t2 = uterm();
            return (t1 - t2);
        default:
            return t1;
    }
}

STATIC ulong uterm(void)
{
    ulong   t1, t2;

    t1 = ufactor();
    switch (CurrentToken)
    {
        case YY_MULTIPLY:
            match(YY_MULTIPLY);
            t2 = uterm();
            return (t1 * t2);
        case YY_DIVIDE:
            match(YY_DIVIDE);
            t2 = uterm();
            if (!t2)
                error("Divide by zero in expression");
            return (t1 / t2);
        default:
            return t1;
    }
}

STATIC ulong ufactor(void)
{
    ulong   t;

    switch(CurrentToken)
    {
        case YY_LPAREN:
            match(YY_LPAREN);
            t = uexpr();
            match(YY_RPAREN);
            return (t);
        case YY_INTEGER:
            return (uinteger());
        case YY_PLUS:
            match(YY_PLUS);
            return uexpr();
        case YY_MINUS:
            error("Expected unsigned integer");
            break;
        default:
            error("Invalid unsigned integer expression");
            break;
    }

    return 0;
}
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// match                                                                    �
//                                                                          �
// Matches input token again target; if it failes, then it prints an error. �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
STATIC void match(int tok)
{
    if (tok != CurrentToken)
    {
        switch (tok)
        {
            case YY_LBRACE:
                error("Expected a '{'");
                break;
            case YY_RBRACE:
                error("Expected a '}'");
                break;
            case YY_LPAREN:
                error("Expected a '('");
                break;
            case YY_RPAREN:
                error("Expected a ')'");
                break;
            case YY_COMMA:
                error("Expected a ','");
                break;
            case YY_EQUAL:
                error("Expected a '='");
                break;
            default:
                error("Unexpected token in source file");
                break;
        }
    }

    CurrentToken = yylex();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// error                                                                    �
//                                                                          �
// Emits an error and aborts processing.                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
extern "C" void error(const char *str)
{
    cout << " Error(" << YY_lineno << "): " << str << "\n";
    exit(1);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// warning                                                                  �
//                                                                          �
// Emits a warning.                                                         �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
extern "C" void warning(const char *str)
{
    cout << " Warning(" << YY_lineno << "): " << str << "\n";
}

//葦� End of module - eshtlibp.cpp 憶�


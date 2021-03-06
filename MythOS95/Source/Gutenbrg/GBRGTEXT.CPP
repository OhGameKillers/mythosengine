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
// gbrgtext.cpp
//
// Text output class code.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <assert.h>
#include <stdio.h>

#include <gutenbrg.hpp>

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
// GBergText - outc                                                         �
//                                                                          �
// Outputs a character.                                                     �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void GBergText::outc(char c)
{
    assertMyth("GBergText assumes Gutenberg is initalized and has an active font",
               GBergInstance && GBergInstance->font_active);

//陳 Skip single character returns
    if (c == '\r')
        return;

//陳 Perform CR/LF on newline
    if (c == '\n')
    {
        cury += GBergInstance->font_active->height;
        curx = 0;
        return;
    }

//陳 Output character and update cursor position

    curx += gberg_outc(vport, curx, cury, c);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// GBergText - out                                                          �
//                                                                          �
// Outputs a string or long value as string.                                �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void GBergText::out(const char *str)
{
    assertMyth("GBergText assumes Gutenberg is initalized and has an active font",
               GBergInstance && GBergInstance->font_active);

    while (*str != 0)
    {
        outc(*(str++));
    }
}

void GBergText::out(long num)
{
    char    buff[16];

#ifdef WIN32
    wsprintf(buff,"%li",num);
#else
    sprintf(buff,"%li",num);
#endif
    out(buff);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// GBergText - outf                                                         �
//                                                                          �
// Outputs a string formatted with wsprintf.                                �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void GBergText::outf (const char *fmt, ...)
{
    char buff[256];

    // Perform a printf
    va_list parms;
    va_start (parms, fmt);
#ifdef WIN32
    int len = wvsprintf (buff, fmt, parms);
#else
    int len = vsprintf (buff, fmt, parms);
#endif
    va_end (parms);

    assert (len < sizeof (buff));
    out (buff);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// GBergText - outc_vert                                                    �
//                                                                          �
// Outputs a character vertically.                                          �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void GBergText::outc_vert(char c)
{
    assertMyth("GBergText assumes Gutenberg is initalized and has an active font",
               GBergInstance && GBergInstance->font_active);

//陳 Skip single character returns
    if (c == '\r')
        return;

//陳 skip newlines
    if (c == '\n')
        return;

//陳 Output character and update cursor position
    cury += gberg_outc(vport, curx, cury, c, TRUE);     // last param indicates VERTICAL text
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// GBergText - out_vert                                                     �
//                                                                          �
// Outputs a string or long value as string vertically on the screen.       �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void GBergText::out_vert(const char *str)
{
    assertMyth("GBergText assumes Gutenberg is initalized and has an active font",
               GBergInstance && GBergInstance->font_active);

    while (*str != 0)
    {
        outc_vert(*(str++));
    }
}

void GBergText::out_vert(long num)
{
    char    buff[16];

#ifdef WIN32
    wsprintf(buff,"%li",num);
#else
    sprintf(buff,"%li",num);
#endif
    out_vert(buff);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// GBergText - outf_vert                                                    �
//                                                                          �
// Outputs a string formatted with wsprintf vertically on the screen.       �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void GBergText::outf_vert (const char *fmt, ...)
{
    char buff[256];

    // Perform a printf
    va_list parms;
    va_start (parms, fmt);
#ifdef WIN32
    int len = wvsprintf (buff, fmt, parms);
#else
    int len = vsprintf (buff, fmt, parms);
#endif
    va_end (parms);

    assert (len < sizeof (buff));
    out_vert (buff);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// GBergText - out_wrap                                                     �
//                                                                          �
// Outputs a string wrapped to the given rectangle.                         �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void GBergText::out_wrap (const char *text, const VngoRect *rct)
{
    VngoRect trct;

    // If we have no rectangle, default to the viewport rectangle
    if (rct == 0)
    {
        trct.x  = 0;
        trct.y  = 0;
        trct.dx = vport->vbuff.width;
        trct.dy = vport->vbuff.height;
        rct = &trct;
    }

    // Some parameter validation
    assert (rct != 0);
    assert (rct->dx > 0);
    assert (rct->dy > 0);

    // Calculate some bounds information
    const int right  = rct->x + rct->dx;
    const int bottom = rct->y + rct->dy;

    // Clip cursor to the rectangle
    if (cury < rct->y)
        cury = rct->y;

    if (curx < rct->x)
        curx = rct->x;

    // Define loop variables
    const char *last_word = text;
    int col = rct->x;

    while (*text != '\0' && cury < bottom)
    {
        // The proposed character
        const char ch = *text;

        // Advance the proposed point by one character
        col += gberg_widthc (ch);

        // If we have left the rectangle, move to the next line
        if (col >= right)
        {
            if (curx == rct->x)
            {
                // If the word is too long for one line, write
                // as much as we can on this line, splitting the word
                for (; last_word != text; ++last_word)
                    outc (*last_word);
            }

            col = curx = rct->x;
            cury += GBergInstance->font_active->height;
        }

        // If we have reached a space, it is now safe to
        // write the current word (including the trailing space)
        if (isspace (ch))
        {
            for (; last_word != text; ++last_word)
                outc (*last_word);
            outc (ch);
            last_word = text + 1;
        }

        ++text;
    }

    // Output the trailer of the string
    while (last_word != text)
        outc (*last_word++);
}



//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// GBergText - setpos                                                       �
//                                                                          �
// Sets the position of the curx, cury cursor using the size of the         �
// font to determine rows and columns.                                      �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void GBergText::setpos(byte row, byte col)
{
    assertMyth("GBergText assumes Gutenberg is initalized and has an active font",
               GBergInstance && GBergInstance->font_active);

    curx = col * GBergInstance->font_active->width;
    cury = row * GBergInstance->font_active->height;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// GBergText - getpos                                                       �
//                                                                          �
// Gets the position of the curx, cury cursor using the size of the         �
// font to determine rows and columns.                                      �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void GBergText::getpos(byte *row, byte *col) const
{
    assertMyth("GBergText assumes Gutenberg is initalized and has an active font",
               GBergInstance && GBergInstance->font_active);

    assertMyth("GBergText assumes active font has non-zero width and height",
               GBergInstance->font_active->width
               && GBergInstance->font_active->height);

    *col = byte (curx / GBergInstance->font_active->width);
    *row = byte (cury / GBergInstance->font_active->height);
}

//葦� End of module - gbrgtext.cpp 憶�


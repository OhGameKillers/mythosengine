//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//
//                                                           %__________%
//                                                          %/ . .  .   \%
//           Van Gogh 2D-Display Library                     |  . .  o. |
//                                                           |. _  .   .|
//        Microsoft Windows 95/98/NT Version                 | / \   .  |
//                                                           |_|_|_._._.|
//                                                           |.-.-.-.-..|
//                                                          %\__________/%
//                                                           %          %
//
//  Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
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
// Created by Tim Little
//
// vngcolor.hpp
//
// This file has all of the various color definitions
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

#ifndef __VNGCOLOR_HPP
#define __VNGCOLOR_HPP 1

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include "portable.h"
#include "felix.hpp"

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

typedef dword VngoColorIndex;

#define VNGO_COLOR_HLS_INVALID  0x1
#define VNGO_SHADE_FLAT         191
#define PURE_COLOR_CONVERT      1

// because we need to be able to round up and we are realy (0-255) >> 3 we
// make this intensionaly small.
#define VNGO_SHADE_FULL         (30 << 3) // for 5.3 shade levels.

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Classes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

class VngoHwPal;
class VngoPal;
class VngoPal8;
class VngoColor24bit;

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// Color classes
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class Vngo24to8bit
{
public:
    byte    colorconvert[32768];

    VngoColorIndex get_index(VngoColor24bit clr);
    void init(VngoPal *my_pal);
};

class VngoColorHLS
{
public:
    Flx16   h;
    Flx16   l;
    Flx16   s;
    dword   flags;

    VngoColorHLS() {};
    VngoColorHLS(VngoColor24bit c);

    VngoColor24bit to_RGB();

private:
    int value(Flx16 a,Flx16 b, Flx16 c);
};

class VngoColor24bit
{
public:
    byte    r;
    byte    g;
    byte    b;
    byte    na;

    VngoColor24bit() {};
    VngoColor24bit(dword clr)
    {
        r =(byte)(clr & 0xff);
        g =(byte)((clr >> 8) & 0xff);
        b =(byte)((clr >> 16) & 0xff);
    }

    VngoColor24bit(byte pr,byte pg,byte pb) {r=pr; g=pg; b=pb;na=0;}

    VngoColor24bit(VngoColorHLS c);

    VngoColorHLS to_HLS();

    int compress() {return (((r>>3) << 10) + ((g>>3) << 5) + (b>>3)); }
    int compress16() {return (((r>>3) << 11) + ((g>>2) << 5) + (b>>3)); }
    int compress24() {return ((r << 16) + (g << 8) + b); }
};

class VngoColor16bit
{
public:
    word    pcolor;

    VngoColor16bit() {};
    VngoColor16bit (dword clr) {pcolor =  (word)clr;}
    VngoColor16bit (byte pr,byte pg, byte pb)
    {
        pcolor = (word) (((pr>>3) << 11) + ((pg >> 2) << 5) + (pb >> 3));
    }
    VngoColor16bit (VngoColor24bit clr)
    {
        pcolor = (word)clr.compress16();
    }
    VngoColor16bit (VngoColorHLS clr)
    {
        VngoColor24bit clr_24b(clr);
        pcolor = (word) clr_24b.compress16();
    }

    VngoColorHLS to_HLS()
    {
        VngoColor24bit  tclr;
        tclr.r = (pcolor >> 8) & 0xf8;
        tclr.g = (pcolor >> 3) & 0xfc;
        tclr.b = (pcolor << 3) & 0xff;
        return tclr.to_HLS();
    }
    VngoColor24bit to_24bit()
    {
        VngoColor24bit  tclr;
        tclr.r = (pcolor >> 8) & 0xf8;
        tclr.g = (pcolor >> 3) & 0xfc;
        tclr.b = (pcolor << 3) & 0xf8;
        return tclr;
    }
};

class VngoColor15bit
{
public:
    word    pcolor;

    VngoColor15bit () {};
    VngoColor15bit (dword clr) {pcolor =  (word)clr;}
    VngoColor15bit (byte pr,byte pg, byte pb)
    {
        pcolor = (word) (((pr>>3) << 10) + ((pg >> 3) << 5) + (pb >> 3));
    }
    VngoColor15bit (VngoColor24bit clr)
    {
        pcolor = (word) clr.compress();
    }
    VngoColor15bit (VngoColorHLS clr)
    {
        VngoColor24bit clr_24b(clr);
        pcolor = (word) clr_24b.compress();
    }
    VngoColorHLS to_HLS()
    {
        VngoColor24bit  tclr;
        tclr.r = (pcolor >> 7) & 0xf8;
        tclr.g = (pcolor >> 2) & 0xf8;
        tclr.b = (pcolor << 3) & 0xf8;
        return tclr.to_HLS();
    }
    VngoColor24bit to_24bit()
    {
        VngoColor24bit  tclr;
        tclr.r = (pcolor >> 7) & 0xf8;
        tclr.g = (pcolor >> 2) & 0xf8;
        tclr.b = (pcolor << 3) & 0xf8;
        return tclr;
    }
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// Color Convert Class
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class VngoClrConvert
{
public:
    Vngo24to8bit    cvt2_8;
    VngoHwPal       *mypal;

    void init(VngoPal *hwpal,int flags=0);
    VngoColorIndex get_index(VngoColor24bit clr) { return (cvt2_8.get_index(clr));}
    VngoColorIndex get_index(int indx) { return (indx);}
    VngoColorIndex get_index(VngoColorHLS clr) { return (cvt2_8.get_index(clr.to_RGB()));}
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// Color Shade Classes
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class VngoColorShade
{
public:

    VngoColorShade() {}
};

class VngoColorShadeHLS : public VngoColorShade
{
public:
    VngoColorHLS    shl[VNGO_SHADE_TABLE_SIZE];

    VngoColorShadeHLS() {}
};

class VngoColorShade8
{
    VngoColorShade8() {}
    friend class VngoShadePal8;

public:
    byte    shl[1]; //[VNGO_SHADE_TABLE_SIZE];
};

class VngoColorShade15 : public VngoColorShade
{
    VngoColorShade15() {}
    friend class VngoShadePal15;
public:
    word    shl[1]; //[VNGO_SHADE_TABLE_SIZE];

};

class VngoColorShade16 : public VngoColorShade
{
    VngoColorShade16() {}
    friend class VngoShadePal16;
public:
    word    shl[1]; //[VNGO_SHADE_TABLE_SIZE];

};

class VngoColorShade24 : public VngoColorShade
{
    VngoColorShade24() {}
    friend class VngoShadePal24;
public:
    dword   shl[1]; //[VNGO_SHADE_TABLE_SIZE];

};

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif         // __VNGCOLOR_HPP

//葦� End of header - vngcolor.hpp 憶�



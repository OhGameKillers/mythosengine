//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//
//
//            _,'|             _.-''``-...___..--';)
//           /_ \'.      __..-' ,      ,--...--'''
//          <\    .`--'''       `     /'
//           `-';'               ;   ; ;  Felix the Fixed-point Library
//     __...--''     ___...--_..'  .;.'
//    (,__....----'''       (,..--''
//
//
//    Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
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
// felix.hpp
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

#ifndef __FELIX_HPP
#define __FELIX_HPP    1

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include "portable.h"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Prototypes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

class Flx16;

extern "C" {
Flx16 flx_muldiv(Flx16 a,Flx16 b,Flx16 c);
dword flx_recip230(Flx16 a);
Flx16 flx_16mul16(Flx16 a,Flx16 b);
Flx16 flx_16mul30(dword a,dword b);
Flx16 flx_16div16(Flx16 a,Flx16 b);
Flx16 flx_sin(Flx16 degrees);
Flx16 flx_abs(Flx16 a);
Flx16 flx_sqrt(Flx16 a);
Flx16 flx_rand();
void  flx_srand(long s1,long s2);
}

#ifdef __WATCOMC__
#pragma aux (_ASMSTKCALL_) flx_sin;
#pragma aux (_ASMSTKCALL_) flx_abs;
#pragma aux (_ASMSTKCALL_) flx_sqrt;
#pragma aux (_ASMSTKCALL_) flx_rand;
#pragma aux (_ASMSTKCALL_) flx_srand;
#endif

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Structures
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Classes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

class Flx16
{
public:
   long    flx;

// Constructors.
   Flx16() {}
   Flx16(const int num) {flx = (num <<16);}
   Flx16(const long num) {flx = (num <<16);}
   Flx16(const long num, int dummy) {flx = num; dummy=dummy;}
   Flx16(const short num) {flx = ((int)num <<16);}
   Flx16(const char num) {flx = ((int)num << 16);}
   Flx16(const Flx16 &r) { flx = r.flx; }
   Flx16(const double num) {flx = (int) (num * 65536.0);}

// Operator.
   inline operator int() const {return(flx>>16);}
   inline operator long() const {return (flx>>16);}
   inline operator float() const {return ((float)(flx) / 65536.0);}

// Intrensic functions.
   inline Flx16 sin() const { return (flx_sin(*this));}
   inline Flx16 cos() const { return (flx_sin(*this+90));}
   inline Flx16 tan() const { return (flx_sin(*this)/flx_sin(*this+90));}
   inline Flx16 sqrt() const { return (flx_sqrt(*this));}
   inline Flx16 abs() const { return (flx_abs(*this));}
#if 0
   inline Flx16 acos() const {return (flxacos(flx));}
   inline Flx16 asin() const {return (flxasin(flx));}
   inline Flx16 tan() const {return (flxtan(flx));}
   inline Flx16 atan() const {return (flxatan(flx));}
   inline Flx16 atan2() const {return (flxatan2(flx));}
   inline Flx16 exp() const {return flxexp(flx));}
   inline Flx16 pow() const {return flxpow(flx));}
   inline Flx16 log10() const {return flxlog10(flx));}
   inline Flx16 log() const {return flxlog(flx));}
#endif
};

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

const Flx16 FLX16_ZERO  = 0;
const Flx16 FLX16_ONE   = 1;

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                                         Inline Functions
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <felix.ipp>

#endif         // __FELIX_HPP

//葦� End of header - felix.hpp 憶�



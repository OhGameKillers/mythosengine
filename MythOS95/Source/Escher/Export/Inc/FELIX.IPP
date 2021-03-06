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
// felix.ipp
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

#ifndef __FELIX_IPP
#define __FELIX_IPP    1

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

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

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Prototypes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                                         Inline Functions
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#if 1
#pragma aux flx_16mul16 =      \
   "imul   edx"                \
   "shrd   eax,edx,16"         \
   parm caller [eax][edx] nomemory \
   value [eax]                 \
   modify [eax edx] nomemory;

#pragma aux flx_16mul30 =      \
   "imul   edx"                \
   "shrd   eax,edx,30"         \
   parm caller [eax][edx] nomemory \
   value [eax]                 \
   modify [eax edx] nomemory;


#pragma aux flx_16div16 =      \
   "xor    eax,eax"            \
   "shrd   eax,edx,16"         \
   "sar    edx,16"             \
   "idiv   ecx"                \
   parm caller [edx][ecx] nomemory \
   value   [eax]               \
   modify  [eax edx] nomemory;

#pragma aux flx_muldiv =       \
   "imul   edx"                \
   "idiv   ecx"                \
   parm caller [eax][edx][ecx] nomemory \
   value   [eax]               \
   modify  [eax edx] nomemory;

#pragma aux flx_recip230 =     \
   "mov    edx,04000h"         \
   "xor    eax,eax"            \
   "idiv   ecx"                \
   parm caller [ecx] nomemory  \
   value   [eax]               \
   modify  [eax edx] nomemory;

#endif


// Intrinsic functions.
inline Flx16 flx_cos(const Flx16 degrees)
{
   return (flx_sin(degrees+90));
}

inline Flx16 flx_tan(const Flx16 degrees)
{
   return (flx_sin(degrees)/flx_cos(degrees));
}

inline Flx16 operator + (const Flx16 a, const Flx16 b)
{
   return Flx16(a.flx + b.flx, 0);
}

inline Flx16 operator - (const Flx16 a, const Flx16 b)
{
   return Flx16(a.flx - b.flx, 0);
}

inline Flx16 operator - (const Flx16 a)
{
   return Flx16(-a.flx, 0);
}

inline Flx16 operator * (Flx16 a, Flx16 b)
{
   return(flx_16mul16(a,b));
}

inline Flx16 operator / (const Flx16 a, const Flx16 b)
{
   return(flx_16div16(a,b));
}

inline int operator == (const Flx16 a, const Flx16 b)
{
   return(a.flx==b.flx);
}

inline int operator == (const Flx16 a, const int b)
{
   return(a.flx==(b << 16));
}

inline int operator == (const int a, const Flx16 b)
{
   return((a << 16)==b.flx);
}

inline int operator != (const Flx16 a, const Flx16 b)
{
   return(a.flx!=b.flx);
}

inline int operator != (const Flx16 a, const int b)
{
   return(a.flx!=(b << 16));
}

inline int operator != (const int a, const Flx16 b)
{
   return((a << 16)!=b.flx);
}

inline int operator > (const Flx16 a, const Flx16 b)
{
   return(a.flx>b.flx);
}

inline int operator > (const Flx16 a, const int b)
{
   return(a.flx>(b << 16));
}

inline int operator > (const int a, const Flx16 b)
{
   return((a << 16)>b.flx);
}

inline int operator >= (const Flx16 a, const Flx16 b)
{
   return(a.flx>=b.flx);
}

inline int operator >= (const Flx16 a, const int b)
{
   return(a.flx>=(b << 16));
}

inline int operator >= (const int a, const Flx16 b)
{
   return((a << 16)>=b.flx);
}

inline int operator < (const Flx16 a, const Flx16 b)
{
   return(a.flx<b.flx);
}

inline int operator < (const Flx16 a, const int b)
{
   return(a.flx<(b << 16));
}

inline int operator < (const int a, const Flx16 b)
{
   return((a << 16)<b.flx);
}

inline int operator <= (const Flx16 a, const Flx16 b)
{
   return(a.flx<=b.flx);
}

inline int operator <= (const Flx16 a, const int b)
{
   return(a.flx<=(b << 16));
}

inline int operator <= (const int a, const Flx16 b)
{
   return((a << 16)<=b.flx);
}

#endif         // __FELIX_IPP

//葦� End of header - felix.ipp 憶�



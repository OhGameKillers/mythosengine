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
// vngpoly16.cpp
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <string.h>
#include <assert.h>
#include "debug.h"
#include "portable.h"
#include "ivory.h"
#include "vangogh.hpp"

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
//                               Routines
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//                                                                          �
// This is more Virtual View Port stuff.                                    �
//                                                                          �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//                                                                          �
// This is the non-alpa blended portion of the polygon functions.           �
//                                                                          �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

VNGError VngoVVport16::poly (int count,VngoPointF pts[])
{
    assert (count < VNGO_MAX_VERTCOUNT);
    VngoTexture *tex = NULL;
    dword poly_flags = 0;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
        poly_flags |= VNGO_TRITYPE_ZBUFFER;

    if (vflags & VNGO_DEBUG_OUTLINE)
        poly_flags |= VNGO_TRITYPE_OUTLINE;

    vngo_poly(this,count,poly_flags,pts,tex,255);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::poly (int count,VngoPoint pts[])
{
    assert (count < VNGO_MAX_VERTCOUNT);

    VngoPointF tpts[VNGO_MAX_VERTCOUNT];

    for (int i = 0; i < count; i++)
    {
        tpts[i].x = float(pts[i].x);
        tpts[i].y = float(pts[i].y);
        tpts[i].z = float(dword(pts[i].z)) / float(0xffffffff);
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = float(pts[i].shade);
    }
    poly(count,tpts);
    return VNGO_NO_ERROR;
}


VNGError VngoVVport16::gpoly (int count,VngoPoint pts[])
{
    assert (count < VNGO_MAX_VERTCOUNT);

    VngoPointF tpts[VNGO_MAX_VERTCOUNT];

    for (int i = 0; i < count; i++)
    {
        tpts[i].x = float(pts[i].x);
        tpts[i].y = float(pts[i].y);
        tpts[i].z = float(dword(pts[i].z)) / float(0xffffffff);
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = float(pts[i].shade);
    }
    gpoly(count,tpts);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::gpoly (int count,VngoPointF pts[])
{
    assert (count <= VNGO_MAX_VERTCOUNT);
    VngoTexture *tex = NULL;
    dword poly_flags = VNGO_TRITYPE_GOURAUD;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
        poly_flags |= VNGO_TRITYPE_ZBUFFER;

    if (vflags & VNGO_DEBUG_OUTLINE)
        poly_flags |= VNGO_TRITYPE_OUTLINE;

    vngo_poly(this,count,poly_flags,pts,tex,255);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::gpoly_persp (int count,VngoPoint pts[])
{
    assert(count < VNGO_MAX_VERTCOUNT);
    return (gpoly(count,pts));
}

VNGError VngoVVport16::gpoly_persp (int count,VngoPointF pts[])
{
    assert(count < VNGO_MAX_VERTCOUNT);
    return (gpoly(count,pts));
}

VNGError VngoVVport16::tpoly (int count,VngoPoint pts[],VngoTexture *tex)
{
    assert (count < VNGO_MAX_VERTCOUNT);

    VngoPointF tpts[VNGO_MAX_VERTCOUNT];

    for (int i = 0; i < count; i++)
    {
        tpts[i].x = float(pts[i].x);
        tpts[i].y = float(pts[i].y);
        tpts[i].z = float(dword(pts[i].z)) / float(0xffffffff);
        tpts[i].u = float(pts[i].u) / float(0x10000);
        tpts[i].v = float(pts[i].v) / float(0x10000);
        tpts[i].w = float(pts[i].w) / float(0x3fffffff);
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = float(pts[i].shade);
    }
    tpoly(count,tpts,tex);
    return VNGO_NO_ERROR;

}


VNGError VngoVVport16::tpoly (int count,VngoPointF pts[],VngoTexture *tex)
{
    assert (count <= VNGO_MAX_VERTCOUNT);

    dword poly_flags = VNGO_TRITYPE_TEXTURED;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
        poly_flags |= VNGO_TRITYPE_ZBUFFER;

    if (vflags & VNGO_TEXTURE_FILTER)
        poly_flags |= VNGO_TRITYPE_FILTERED;

    if (vflags & VNGO_DEBUG_OUTLINE)
        poly_flags |= VNGO_TRITYPE_OUTLINE;

    vngo_poly(this,count,poly_flags,pts,tex,255);

    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::tpoly_persp (int count,VngoPoint pts[],VngoTexture *tex)
{
    assert (count < VNGO_MAX_VERTCOUNT);

    VngoPointF tpts[VNGO_MAX_VERTCOUNT];

    for (int i = 0; i < count; i++)
    {
        tpts[i].x = float(pts[i].x);
        tpts[i].y = float(pts[i].y);
        tpts[i].z = float(dword(pts[i].z)) / float(0xffffffff);
        tpts[i].u = float(pts[i].u) / float(0x10000);
        tpts[i].v = float(pts[i].v) / float(0x10000);
        tpts[i].w = float(pts[i].w) / float(0x3fffffff);
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = float(pts[i].shade);
    }
    tpoly_persp(count,tpts,tex);
    return VNGO_NO_ERROR;
}


VNGError VngoVVport16::tpoly_persp (int count,VngoPointF pts[],VngoTexture *tex)
{
    assert (count <= VNGO_MAX_VERTCOUNT);

    dword poly_flags = VNGO_TRITYPE_TEXTURED | VNGO_TRITYPE_PERSPECTIVE;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
        poly_flags |= VNGO_TRITYPE_ZBUFFER;

    if (vflags & VNGO_TEXTURE_FILTER)
        poly_flags |= VNGO_TRITYPE_FILTERED;

    if (vflags & VNGO_DEBUG_OUTLINE)
        poly_flags |= VNGO_TRITYPE_OUTLINE;

    vngo_poly(this,count,poly_flags,pts,tex,255);

    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::gtpoly (int count,VngoPoint pts[],VngoTexture *tex)
{
    assert (count < VNGO_MAX_VERTCOUNT);

    VngoPointF tpts[VNGO_MAX_VERTCOUNT];

    for (int i = 0; i < count; i++)
    {
        tpts[i].x = float(pts[i].x);
        tpts[i].y = float(pts[i].y);
        tpts[i].z = float(dword(pts[i].z)) / float(0xffffffff);
        tpts[i].u = float(pts[i].u) / float(0x10000);
        tpts[i].v = float(pts[i].v) / float(0x10000);
        tpts[i].w = float(pts[i].w) / float(0x3fffffff);
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = float(pts[i].shade);
    }
    gtpoly(count,tpts,tex);
    return VNGO_NO_ERROR;
}


VNGError VngoVVport16::gtpoly (int count,VngoPointF pts[],VngoTexture *tex)
{
    assert (count <= VNGO_MAX_VERTCOUNT);

    dword poly_flags = VNGO_TRITYPE_TEXTURED | VNGO_TRITYPE_GOURAUD;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
        poly_flags |= VNGO_TRITYPE_ZBUFFER;

    if (vflags & VNGO_TEXTURE_FILTER)
        poly_flags |= VNGO_TRITYPE_FILTERED;

    if (vflags & VNGO_DEBUG_OUTLINE)
        poly_flags |= VNGO_TRITYPE_OUTLINE;

    vngo_poly(this,count,poly_flags,pts,tex,255);

    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::gtpoly_persp (int count,VngoPoint pts[],VngoTexture *tex)
{
    assert (count < VNGO_MAX_VERTCOUNT);

    VngoPointF tpts[VNGO_MAX_VERTCOUNT];

    for (int i = 0; i < count; i++)
    {
        tpts[i].x = float(pts[i].x);
        tpts[i].y = float(pts[i].y);
        tpts[i].z = float(dword(pts[i].z)) / float(0xffffffff);
        tpts[i].u = float(pts[i].u) / float(0x10000);
        tpts[i].v = float(pts[i].v) / float(0x10000);
        tpts[i].w = float(pts[i].w) / float(0x3fffffff);
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = float(pts[i].shade);
    }

    gtpoly_persp(count,tpts,tex);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::gtpoly_persp (int count,VngoPointF pts[],VngoTexture *tex)
{
    assert (count <= VNGO_MAX_VERTCOUNT);

    dword poly_flags = VNGO_TRITYPE_TEXTURED | VNGO_TRITYPE_GOURAUD | VNGO_TRITYPE_PERSPECTIVE;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
        poly_flags |= VNGO_TRITYPE_ZBUFFER;

    if (vflags & VNGO_TEXTURE_FILTER)
        poly_flags |= VNGO_TRITYPE_FILTERED;

    if (vflags & VNGO_DEBUG_OUTLINE)
        poly_flags |= VNGO_TRITYPE_OUTLINE;

    vngo_poly(this,count,poly_flags,pts,tex,255);

    return VNGO_NO_ERROR;
}


VNGError VngoVVport16::grpoly (int count,VngoPoint pts[])
{
    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    VngoShadePal16   *tp = (VngoShadePal16*)(((VngoPal16*)vbuff.pal)->shd_pal);
    word            *tc = (word*)(&(*tp)[0]);
    for (int i=0;i < count;i++)
    {
        tpts[i].x = pts[i].x << 16;
        tpts[i].y = pts[i].y << 16;
        tpts[i].z = pts[i].z;
        if (!(pts[i].clr & VNGO_COLOR_24BIT))
        {
            int t = tc[(pts[i].clr << 5) + (pts[i].shade >> 3)];
            VngoColor24bit tclr( ((t & (0x1f << 11)) >> 8), ((t & (0x3f << 5)) >> 3),((t & 0x1f) << 3));
            tpts[i].clr = (tclr.r << 16) | (tclr.g << 8) | tclr.b | VNGO_COLOR_24BIT;
        }
        else
        {
            tpts[i].clr = pts[i].clr;
        }
    }
    vngo_grpoly16(this,count,tpts);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::grpoly (int count,VngoPointF pts[])
{
    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    VngoShadePal16  *tp = (VngoShadePal16*)(((VngoPal16*)vbuff.pal)->shd_pal);
    word            *tc = (word*)(&(*tp)[0]);
    for (int i=0;i < count;i++)
    {
        tpts[i].x = long(pts[i].x * float(0x10000));
        tpts[i].y = long(pts[i].y * float(0x10000));
        tpts[i].z = dword(pts[i].z * float(0xffffffff));
        if (!(pts[i].clr & VNGO_COLOR_24BIT))
        {
            int t = tc[(pts[i].clr << 5) + (long(pts[i].shade) >> 3)];
            VngoColor24bit tclr( ((t & (0x1f << 11)) >> 8), ((t & (0x3f << 5)) >> 3), ((t & 0x1f) << 3));
            tpts[i].clr = (tclr.r << 16) | (tclr.g << 8) | tclr.b | VNGO_COLOR_24BIT;
        }
        else
        {
            tpts[i].clr = pts[i].clr;
        }
    }
    vngo_grpoly16(this,count,tpts);
    return VNGO_NO_ERROR;
}

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳
//
// This is the alpa blended portion of the polygon functions.
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳

VNGError VngoVVport16::poly_a (int count,
                              VngoPointF pts[],
                              long alpha)
{
    assert (count < VNGO_MAX_VERTCOUNT);
    VngoTexture *tex = NULL;
    dword poly_flags = VNGO_TRITYPE_ALPHA;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
        poly_flags |= VNGO_TRITYPE_ZBUFFER;

    if (vflags & VNGO_DEBUG_OUTLINE)
        poly_flags |= VNGO_TRITYPE_OUTLINE;

    vngo_poly(this,count,poly_flags,pts,tex,alpha);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::poly_a (int count,
                              VngoPoint pts[],
                              long alpha)
{
    assert (count < VNGO_MAX_VERTCOUNT);

    VngoPointF tpts[VNGO_MAX_VERTCOUNT];

    for (int i = 0; i < count; i++)
    {
        tpts[i].x = float(pts[i].x);
        tpts[i].y = float(pts[i].y);
        tpts[i].z = float(dword(pts[i].z)) / float(0xffffffff);
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = float(pts[i].shade);
    }
    poly_a(count,tpts,alpha);
    return VNGO_NO_ERROR;
}


VNGError VngoVVport16::gpoly_a (int count,
                               VngoPoint pts[],
                               long alpha)
{
    assert (count < VNGO_MAX_VERTCOUNT);

    VngoPointF tpts[VNGO_MAX_VERTCOUNT];

    for (int i = 0; i < count; i++)
    {
        tpts[i].x = float(pts[i].x);
        tpts[i].y = float(pts[i].y);
        tpts[i].z = float(dword(pts[i].z)) / float(0xffffffff);
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = float(pts[i].shade);
    }
    gpoly_a(count,tpts,alpha);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::gpoly_a (int count,
                               VngoPointF pts[],
                               long alpha)
{
    assert (count < VNGO_MAX_VERTCOUNT);
    VngoTexture *tex = NULL;
    dword poly_flags = VNGO_TRITYPE_GOURAUD | VNGO_TRITYPE_ALPHA;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
        poly_flags |= VNGO_TRITYPE_ZBUFFER;

    if (vflags & VNGO_DEBUG_OUTLINE)
        poly_flags |= VNGO_TRITYPE_OUTLINE;

    vngo_poly(this,count,poly_flags,pts,tex,alpha);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::gpoly_persp_a (int count,
                                     VngoPoint pts[],
                                     long alpha)
{
    assert(count < VNGO_MAX_VERTCOUNT);
    return (gpoly_a(count,pts,alpha));
}

VNGError VngoVVport16::gpoly_persp_a (int count,
                                     VngoPointF pts[],
                                     long alpha)
{
    assert(count < VNGO_MAX_VERTCOUNT);
    return (gpoly_a(count,pts,alpha));
}

VNGError VngoVVport16::tpoly_a (int count,VngoPoint pts[],
                               VngoTexture *tex,
                               long alpha)
{
    assert (count < VNGO_MAX_VERTCOUNT);

    VngoPointF tpts[VNGO_MAX_VERTCOUNT];

    for (int i = 0; i < count; i++)
    {
        tpts[i].x = float(pts[i].x);
        tpts[i].y = float(pts[i].y);
        tpts[i].z = float(dword(pts[i].z)) / float(0xffffffff);
        tpts[i].u = float(pts[i].u) / float(0x10000);
        tpts[i].v = float(pts[i].v) / float(0x10000);
        tpts[i].w = float(pts[i].w) / float(0x3fffffff);
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = float(pts[i].shade);
    }

    tpoly_a(count,tpts,tex,alpha);
    return VNGO_NO_ERROR;
}


VNGError VngoVVport16::tpoly_a (int count,VngoPointF pts[],
                               VngoTexture *tex,
                               long alpha)
{
    assert (count <= VNGO_MAX_VERTCOUNT);

    dword poly_flags = VNGO_TRITYPE_ALPHA
                       | VNGO_TRITYPE_TEXTURED;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
        poly_flags |= VNGO_TRITYPE_ZBUFFER;

    if (vflags & VNGO_DEBUG_OUTLINE)
        poly_flags |= VNGO_TRITYPE_OUTLINE;

    if (vflags & VNGO_TEXTURE_FILTER)
        poly_flags |= VNGO_TRITYPE_FILTERED;

    vngo_poly(this,count,poly_flags,pts,tex,alpha);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::tpoly_persp_a (int count,VngoPoint pts[],
                                     VngoTexture *tex,
                                     long alpha)
{
    assert (count < VNGO_MAX_VERTCOUNT);

    VngoPointF tpts[VNGO_MAX_VERTCOUNT];

    for (int i = 0; i < count; i++)
    {
        tpts[i].x = float(pts[i].x);
        tpts[i].y = float(pts[i].y);
        tpts[i].z = float(dword(pts[i].z)) / float(0xffffffff);
        tpts[i].u = float(pts[i].u) / float(0x10000);
        tpts[i].v = float(pts[i].v) / float(0x10000);
        tpts[i].w = float(pts[i].w) / float(0x3fffffff);
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = float(pts[i].shade);
    }

    tpoly_persp_a (count,tpts,tex,alpha);
    return VNGO_NO_ERROR;
}


VNGError VngoVVport16::tpoly_persp_a (int count,VngoPointF pts[],
                                     VngoTexture *tex,
                                     long alpha)
{
    assert (count <= VNGO_MAX_VERTCOUNT);
    dword poly_flags = VNGO_TRITYPE_PERSPECTIVE
                       | VNGO_TRITYPE_TEXTURED
                       | VNGO_TRITYPE_ALPHA;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
        poly_flags |= VNGO_TRITYPE_ZBUFFER;

    if (vflags & VNGO_DEBUG_OUTLINE)
        poly_flags |= VNGO_TRITYPE_OUTLINE;

    if (vflags & VNGO_TEXTURE_FILTER)
        poly_flags |= VNGO_TRITYPE_FILTERED;

    vngo_poly(this,count,poly_flags,pts,tex,alpha);

    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::gtpoly_a (int count,VngoPoint pts[],
                                VngoTexture *tex,
                                long alpha)
{
    assert (count < VNGO_MAX_VERTCOUNT);

    VngoPointF tpts[VNGO_MAX_VERTCOUNT];

    for (int i = 0; i < count; i++)
    {
        tpts[i].x = float(pts[i].x);
        tpts[i].y = float(pts[i].y);
        tpts[i].z = float(dword(pts[i].z)) / float(0xffffffff);
        tpts[i].u = float(pts[i].u) / float(0x10000);
        tpts[i].v = float(pts[i].v) / float(0x10000);
        tpts[i].w = float(pts[i].w) / float(0x3fffffff);
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = float(pts[i].shade);
    }

    gtpoly_a(count,tpts,tex,alpha);
    return VNGO_NO_ERROR;
}


VNGError VngoVVport16::gtpoly_a (int count,VngoPointF pts[],
                                VngoTexture *tex,
                                long alpha)
{
    assert (count <= VNGO_MAX_VERTCOUNT);

    dword poly_flags = VNGO_TRITYPE_GOURAUD
                       | VNGO_TRITYPE_TEXTURED
                       | VNGO_TRITYPE_ALPHA;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
        poly_flags |= VNGO_TRITYPE_ZBUFFER;

    if (vflags & VNGO_DEBUG_OUTLINE)
        poly_flags |= VNGO_TRITYPE_OUTLINE;

    if (vflags & VNGO_TEXTURE_FILTER)
        poly_flags |= VNGO_TRITYPE_FILTERED;

    vngo_poly(this,count,poly_flags,pts,tex,alpha);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::gtpoly_persp_a (int count,VngoPoint pts[],
                                      VngoTexture *tex,
                                      long alpha)
{
    assert (count < VNGO_MAX_VERTCOUNT);

    VngoPointF tpts[VNGO_MAX_VERTCOUNT];

    for (int i = 0; i < count; i++)
    {
        tpts[i].x = float(pts[i].x);
        tpts[i].y = float(pts[i].y);
        tpts[i].z = float(dword(pts[i].z)) / float(0xffffffff);
        tpts[i].u = float(pts[i].u) / float(0x10000);
        tpts[i].v = float(pts[i].v) / float(0x10000);
        tpts[i].w = float(pts[i].w) / float(0x3fffffff);
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = float(pts[i].shade);
    }

    gtpoly_persp_a(count,tpts,tex,alpha);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport16::gtpoly_persp_a (int count,VngoPointF pts[],
                                      VngoTexture *tex,
                                      long  alpha)
{
    assert (count <= VNGO_MAX_VERTCOUNT);

    dword poly_flags = VNGO_TRITYPE_GOURAUD
                       | VNGO_TRITYPE_TEXTURED
                       | VNGO_TRITYPE_PERSPECTIVE
                       | VNGO_TRITYPE_ALPHA;

    if (vflags & VNGO_TEXTURE_FILTER)
        poly_flags |= VNGO_TRITYPE_FILTERED;

    if (vflags & VNGO_ZBUFFER_ACTIVE)
        poly_flags |= VNGO_TRITYPE_ZBUFFER;

    if (vflags & VNGO_DEBUG_OUTLINE)
        poly_flags |= VNGO_TRITYPE_OUTLINE;

    vngo_poly(this,count,poly_flags,pts,tex,alpha);
    return VNGO_NO_ERROR;
}

//葦� End of module - vgpoly16.cpp 憶�


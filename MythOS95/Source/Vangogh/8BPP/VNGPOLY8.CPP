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
// vngpoly8.cpp
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

#define MIN(a,b)  ((a) < (b)) ? (a) : (b)


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

VNGError VngoVVport8::poly (int count,VngoPointF pts[])
{
    assert(lock_status);
    assert (count < VNGO_MAX_VERTCOUNT);

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i = 0; i < count; i++)
    {
        tpts[i].x = long(pts[i].x * float(0x10000));
        tpts[i].y = long(pts[i].y * float(0x10000));
        tpts[i].z = dword(pts[i].z * float(0xffffffff));
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = dword(pts[i].shade) << 16;

        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }
    vngo_poly8(this,count,tpts);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport8::poly (int count,VngoPoint pts[])
{
    assert(lock_status);
    assert (count < VNGO_MAX_VERTCOUNT);

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];

    for (int i = 0; i < count; i++)
    {
        tpts[i].x = pts[i].x << 16;
        tpts[i].y = pts[i].y << 16;
        tpts[i].z = pts[i].z;
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = pts[i].shade << 16;

        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }
    vngo_poly8(this,count,tpts);
    return VNGO_NO_ERROR;
}


VNGError VngoVVport8::gpoly (int count,VngoPoint pts[])
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i=0;i < count; i++)
    {
        tpts[i].x = pts[i].x << 16;
        tpts[i].y = pts[i].y << 16;
        tpts[i].z = pts[i].z;
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = pts[i].shade << 16;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }
    vngo_gpoly8(this,count,tpts);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport8::gpoly (int count,VngoPointF pts[])
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i=0;i < count; i++)
    {
        tpts[i].x = long(pts[i].x * float(0x10000));
        tpts[i].y = long(pts[i].y * float(0x10000));
        tpts[i].z = dword(pts[i].z * float(0xffffffff));
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = long(pts[i].shade) << 16;

        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }
    vngo_gpoly8(this,count,tpts);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport8::gpoly_persp (int count,VngoPoint pts[])
{
    assert(lock_status);
    assert(count < VNGO_MAX_VERTCOUNT);
    return (gpoly(count,pts));
}

VNGError VngoVVport8::gpoly_persp (int count,VngoPointF pts[])
{
    assert(lock_status);
    assert(count < VNGO_MAX_VERTCOUNT);
    return (gpoly(count,pts));
}

VNGError VngoVVport8::tpoly (int count,VngoPoint pts[],VngoTexture *tex)
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_MEM_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoMemTexture3D(tex);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoMemTexture3D*)tptr)->vtxt->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i=0;i < count;i++)
    {
        tpts[i].x = pts[i].x << 16;
        tpts[i].y = pts[i].y << 16;
        tpts[i].z = pts[i].z;
        tpts[i].shade = pts[i].shade << 16;
        tpts[i].u = pts[i].u << ((VngoMemTexture3D*)tptr)->widthshift;
        tpts[i].v = pts[i].v << ((VngoMemTexture3D*)tptr)->heightshift;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }

    vngo_tpoly8(this,count,tpts,tptr);
    return VNGO_NO_ERROR;
}


VNGError VngoVVport8::tpoly (int count,VngoPointF pts[],VngoTexture *tex)
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_MEM_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoMemTexture3D(tex);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoMemTexture3D*)tptr)->vtxt->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i=0;i < count;i++)
    {
        tpts[i].x = long(pts[i].x * float(0x10000));
        tpts[i].y = long(pts[i].y * float(0x10000));
        tpts[i].z = dword(pts[i].z * float(0xffffffff));
        tpts[i].shade = long(pts[i].shade) << 16;
        tpts[i].u = long(pts[i].u * float(0x10000)) << ((VngoMemTexture3D*)tptr)->widthshift;
        tpts[i].v = long(pts[i].v * float(0x10000)) << ((VngoMemTexture3D*)tptr)->heightshift;

        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }

    vngo_tpoly8(this,count,tpts,tptr);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport8::tpoly_persp (int count,VngoPoint pts[],VngoTexture *tex)
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_MEM_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoMemTexture3D(tex);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoMemTexture3D*)tptr)->vtxt->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i=0;i < count;i++)
    {
        tpts[i].x = pts[i].x << 16;
        tpts[i].y = pts[i].y << 16;
        tpts[i].z = pts[i].z;
        tpts[i].w = pts[i].w;
        tpts[i].shade = pts[i].shade << 16;
        tpts[i].u = pts[i].u << ((VngoMemTexture3D*)tptr)->widthshift;
        tpts[i].v = pts[i].v << ((VngoMemTexture3D*)tptr)->heightshift;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }

    vngo_tpoly_persp8(this,count,tpts,tptr);
    return VNGO_NO_ERROR;
}


VNGError VngoVVport8::tpoly_persp (int count,VngoPointF pts[],VngoTexture *tex)
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_MEM_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoMemTexture3D(tex);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoMemTexture3D*)tptr)->vtxt->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i=0;i < count;i++)
    {
        tpts[i].x = long(pts[i].x * float(0x10000));
        tpts[i].y = long(pts[i].y * float(0x10000));
        tpts[i].z = dword(pts[i].z * float(0xffffffff));
        tpts[i].w = long(pts[i].w * float(0x3ffffff));
        tpts[i].shade = long(pts[i].shade) << 16;
        tpts[i].u = long(pts[i].u * float(0x10000) * float(tex->width));
        tpts[i].v = long(pts[i].v * float(0x10000) * float(tex->height));
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }

    vngo_tpoly_persp8(this,count,tpts,tptr);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport8::gtpoly (int count,VngoPoint pts[],VngoTexture *tex)
{
    assert( lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_MEM_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoMemTexture3D(tex);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoMemTexture3D*)tptr)->vtxt->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i=0;i < count;i++)
    {
        tpts[i].x = pts[i].x << 16;
        tpts[i].y = pts[i].y << 16;
        tpts[i].z = pts[i].z;
        tpts[i].w = pts[i].w;
        tpts[i].shade = pts[i].shade << 16;
        tpts[i].u = pts[i].u << ((VngoMemTexture3D*)tptr)->widthshift;
        tpts[i].v = pts[i].v << ((VngoMemTexture3D*)tptr)->heightshift;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }
    vngo_tgpoly8(this,count,tpts,tptr);
    return VNGO_NO_ERROR;
}


VNGError VngoVVport8::gtpoly (int count,VngoPointF pts[],VngoTexture *tex)
{
    assert( lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_MEM_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoMemTexture3D(tex);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoMemTexture3D*)tptr)->vtxt->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i=0;i < count;i++)
    {
        tpts[i].x = long(pts[i].x * float(0x10000));
        tpts[i].y = long(pts[i].y * float(0x10000));
        tpts[i].z = dword(pts[i].z * float(0xffffffff));
        tpts[i].w = dword(pts[i].w * float(0x3fffffff));
        tpts[i].shade = long(pts[i].shade) << 16;
        tpts[i].u = long(pts[i].u * float(0x10000) * float(tex->width));
        tpts[i].v = long(pts[i].v * float(0x10000) * float(tex->height));

        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }
    vngo_tgpoly8(this,count,tpts,tptr);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport8::gtpoly_persp (int count,VngoPoint pts[],VngoTexture *tex)
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_MEM_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoMemTexture3D(tex);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoMemTexture3D*)tptr)->vtxt->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i=0;i < count;i++)
    {
        tpts[i].x = pts[i].x << 16;
        tpts[i].y = pts[i].y << 16;
        tpts[i].z = pts[i].z;
        tpts[i].w = pts[i].w;
        tpts[i].shade = pts[i].shade << 16;
        tpts[i].u = pts[i].u << ((VngoMemTexture3D*)tptr)->widthshift;
        tpts[i].v = pts[i].v << ((VngoMemTexture3D*)tptr)->heightshift;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }
    vngo_tgpoly_persp8(this,count,tpts,tptr);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport8::gtpoly_persp (int count,VngoPointF pts[],VngoTexture *tex)
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_MEM_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoMemTexture3D(tex);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoMemTexture3D*)tptr)->vtxt->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i=0;i < count;i++)
    {
        tpts[i].x = long(pts[i].x * float(0x10000));
        tpts[i].y = long(pts[i].y * float(0x10000));
        tpts[i].z = dword(pts[i].z * float(0xffffffff));
        tpts[i].w = long(pts[i].w * float(0x3ffffff));
        tpts[i].shade = long(pts[i].shade) << 16;
        tpts[i].u = long(pts[i].u * float(0x10000) * float(tex->width));
        tpts[i].v = long(pts[i].v * float(0x10000) * float(tex->height));

        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }
    vngo_tgpoly_persp8(this,count,tpts,tptr);
    return VNGO_NO_ERROR;
}



VNGError VngoVVport8::grpoly (int count,VngoPoint pts[])
{
    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    VngoShadePal8   *tp = (VngoShadePal8*)(((VngoPal8*)vbuff.pal)->shd_pal);
    byte            *tc = (byte*)(&(*tp)[0]);
    for (int i=0;i < count;i++)
    {
        tpts[i].x = pts[i].x << 16;
        tpts[i].y = pts[i].y << 16;
        tpts[i].z = pts[i].z;
        if (!(pts[i].clr & VNGO_COLOR_24BIT))
        {
            int t = tc[(pts[i].clr << 5) + (pts[i].shade >> 3)];
            VngoColor24bit tclr= vbuff.pal->get_RGB(t);
            tpts[i].clr = (tclr.r << 16) | (tclr.g << 8) | tclr.b | VNGO_COLOR_24BIT;
        }
        else
        {
            tpts[i].clr = pts[i].clr;
        }
    }
    vngo_grpoly8(this,count,tpts);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport8::grpoly (int count,VngoPointF pts[])
{

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    VngoShadePal8   *tp = (VngoShadePal8*)(((VngoPal8*)vbuff.pal)->shd_pal);
    byte            *tc = (byte*)(&(*tp)[0]);
    for (int i=0;i < count;i++)
    {
        tpts[i].x = long(pts[i].x * float(0x10000));
        tpts[i].y = long(pts[i].y * float(0x10000));
        tpts[i].z = dword(pts[i].z * float(0xffffffff));
        if (!(pts[i].clr & VNGO_COLOR_24BIT))
        {
            int t = tc[(pts[i].clr << 5) + (long(pts[i].shade) >> 3)];
            VngoColor24bit tclr= vbuff.pal->get_RGB(t);
            tpts[i].clr = (tclr.r << 16) | (tclr.g << 8) | tclr.b | VNGO_COLOR_24BIT;
        }
        else
        {
            tpts[i].clr = pts[i].clr;
        }
    }
    vngo_grpoly8(this,count,tpts);
    return VNGO_NO_ERROR;
}

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳
//
// This is the alpa blended portion of the polygon functions.
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳

VNGError VngoVVport8::poly_a (int count,
                              VngoPointF pts[],
                              long alpha)
{
    assert(lock_status);
    assert (count < VNGO_MAX_VERTCOUNT);

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i = 0; i < count; i++)
    {
        tpts[i].x = long(pts[i].x * float(0x10000));
        tpts[i].y = long(pts[i].y * float(0x10000));
        tpts[i].z = dword(pts[i].z * float(0xffffffff));
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = long(pts[i].shade) << 16;

        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }
    vngo_apoly8(this,count,tpts,alpha);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport8::poly_a (int count,
                              VngoPoint pts[],
                              long alpha)
{
    assert(lock_status);
    assert (count < VNGO_MAX_VERTCOUNT);

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];

    for (int i = 0; i < count; i++)
    {
        tpts[i].x = pts[i].x << 16;
        tpts[i].y = pts[i].y << 16;
        tpts[i].z = pts[i].z;
        tpts[i].w = pts[i].w;
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = pts[i].shade << 16;

        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }
    vngo_apoly8(this,count,tpts,alpha);
    return VNGO_NO_ERROR;
}


VNGError VngoVVport8::gpoly_a (int count,
                               VngoPoint pts[],
                               long alpha)
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i=0;i < count; i++)
    {
        tpts[i].x = pts[i].x << 16;
        tpts[i].y = pts[i].y << 16;
        tpts[i].z = pts[i].z;
        tpts[i].w = pts[i].w;
        tpts[i].clr = pts[i].clr;
        tpts[i].shade = pts[i].shade << 16;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }
    vngo_agpoly8(this,count,tpts,alpha);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport8::gpoly_a (int count,
                               VngoPointF pts[],
                               long alpha)
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i=0;i < count; i++)
    {
        tpts[i].x = long(pts[i].x * float(0x10000));
        tpts[i].y = long(pts[i].y * float(0x10000));
        tpts[i].z = dword(pts[i].z * float(0xffffffff));
        tpts[i].w = dword(pts[i].w * float(0x3fffffff));
        tpts[i].shade = long(pts[i].shade) << 16;
        tpts[i].clr = pts[i].clr;

        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width << 16);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height << 16);
    }
    vngo_agpoly8(this,count,tpts,alpha);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport8::gpoly_persp_a (int count,
                                     VngoPoint pts[],
                                     long alpha)
{
    assert(lock_status);
    assert(count < VNGO_MAX_VERTCOUNT);
    return (gpoly_a(count,pts,alpha));
}

VNGError VngoVVport8::gpoly_persp_a (int count,
                                     VngoPointF pts[],
                                     long alpha)
{
    assert(lock_status);
    assert(count < VNGO_MAX_VERTCOUNT);
    return (gpoly_a(count,pts,alpha));
}

VNGError VngoVVport8::tpoly_a (int count,VngoPoint pts[],
                               VngoTexture *tex,
                               long alpha)
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_MEM_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoMemTexture3D(tex);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoMemTexture3D*)tptr)->vtxt->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i=0;i < count;i++)
    {
        tpts[i].x = pts[i].x << 16;
        tpts[i].y = pts[i].y << 16;
        tpts[i].z = pts[i].z;
        tpts[i].w = pts[i].w;
        tpts[i].shade = pts[i].shade << 16;
        tpts[i].u = pts[i].u << ((VngoMemTexture3D*)tptr)->widthshift;
        tpts[i].v = pts[i].v << ((VngoMemTexture3D*)tptr)->heightshift;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }

    vngo_atpoly8(this,count,tpts,tptr,alpha);
    return VNGO_NO_ERROR;
}


VNGError VngoVVport8::tpoly_a (int count,VngoPointF pts[],
                               VngoTexture *tex,
                               long alpha)
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_MEM_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoMemTexture3D(tex);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoMemTexture3D*)tptr)->vtxt->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i=0;i < count;i++)
    {
        tpts[i].x = long(pts[i].x * float(0x10000));
        tpts[i].y = long(pts[i].y * float(0x10000));
        tpts[i].z = dword(pts[i].z * float(0xffffffff));
        tpts[i].w = dword(pts[i].w * float(0x3fffffff));
        tpts[i].shade = long(pts[i].shade) << 16;
        tpts[i].u = long(pts[i].u * float(0x10000) * float(tex->width));
        tpts[i].v = long(pts[i].v * float(0x10000) * float(tex->height));

        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }

    vngo_atpoly8(this,count,tpts,tptr,alpha);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport8::tpoly_persp_a (int count,VngoPoint pts[],
                                     VngoTexture *tex,
                                     long alpha)
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_MEM_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoMemTexture3D(tex);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoMemTexture3D*)tptr)->vtxt->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i=0;i < count;i++)
    {
        tpts[i].x = pts[i].x << 16;
        tpts[i].y = pts[i].y << 16;
        tpts[i].z = pts[i].z;
        tpts[i].w = pts[i].w;
        tpts[i].shade = pts[i].shade << 16;
        tpts[i].u = pts[i].u << ((VngoMemTexture3D*)tptr)->widthshift;
        tpts[i].v = pts[i].v << ((VngoMemTexture3D*)tptr)->heightshift;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }

    vngo_atpoly_persp8(this,count,tpts,tptr,alpha);
    return VNGO_NO_ERROR;
}


VNGError VngoVVport8::tpoly_persp_a (int count,VngoPointF pts[],
                                     VngoTexture *tex,
                                     long alpha)
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_MEM_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoMemTexture3D(tex);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoMemTexture3D*)tptr)->vtxt->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i=0;i < count;i++)
    {
        tpts[i].x = long(pts[i].x * float(0x10000));
        tpts[i].y = long(pts[i].y * float(0x10000));
        tpts[i].z = dword(pts[i].z * float(0xffffffff));
        tpts[i].w = long(pts[i].w * float(0x3ffffff));
        tpts[i].shade = long(pts[i].shade) << 16;
        tpts[i].u = long(pts[i].u * float(0x10000) * float(tex->width));
        tpts[i].v = long(pts[i].v * float(0x10000) * float(tex->height));

        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width << 16);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height << 16);
    }

    vngo_atpoly_persp8(this,count,tpts,tptr,alpha);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport8::gtpoly_a (int count,VngoPoint pts[],
                                VngoTexture *tex,
                                long alpha)
{
    assert( lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_MEM_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoMemTexture3D(tex);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoMemTexture3D*)tptr)->vtxt->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i=0;i < count;i++)
    {
        tpts[i].x = pts[i].x << 16;
        tpts[i].y = pts[i].y << 16;
        tpts[i].z = pts[i].z;
        tpts[i].shade = pts[i].shade << 16;
        tpts[i].u = pts[i].u << ((VngoMemTexture3D*)tptr)->widthshift;
        tpts[i].v = pts[i].v << ((VngoMemTexture3D*)tptr)->heightshift;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }
    vngo_atgpoly8(this,count,tpts,tptr,alpha);
    return VNGO_NO_ERROR;
}


VNGError VngoVVport8::gtpoly_a (int count,VngoPointF pts[],
                                VngoTexture *tex,
                                long alpha)
{
    assert( lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_MEM_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoMemTexture3D(tex);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoMemTexture3D*)tptr)->vtxt->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i=0;i < count;i++)
    {
        tpts[i].x = long(pts[i].x * float(0x10000));
        tpts[i].y = long(pts[i].y * float(0x10000));
        tpts[i].z = dword(pts[i].z * float(0xffffffff));
        tpts[i].shade = long(pts[i].shade) << 16;
        tpts[i].u = long(pts[i].u * float(0x10000) * float(tex->width));
        tpts[i].v = long(pts[i].v * float(0x10000) * float(tex->height));

        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width << 16);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height << 16);
    }
    vngo_atgpoly8(this,count,tpts,tptr,alpha);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport8::gtpoly_persp_a (int count,VngoPoint pts[],
                                      VngoTexture *tex,
                                      long alpha)
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_MEM_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoMemTexture3D(tex);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoMemTexture3D*)tptr)->vtxt->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i=0;i < count;i++)
    {
        tpts[i].x = pts[i].x << 16;
        tpts[i].y = pts[i].y << 16;
        tpts[i].z = pts[i].z;
        tpts[i].w = pts[i].w;
        tpts[i].shade = pts[i].shade << 16;
        tpts[i].u = pts[i].u << ((VngoMemTexture3D*)tptr)->widthshift;
        tpts[i].v = pts[i].v << ((VngoMemTexture3D*)tptr)->heightshift;
        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height);
    }
    vngo_atgpoly_persp8(this,count,tpts,tptr,alpha);
    return VNGO_NO_ERROR;
}

VNGError VngoVVport8::gtpoly_persp_a (int count,VngoPointF pts[],
                                      VngoTexture *tex,
                                      long  alpha)
{
    assert(lock_status);
    assert (count <= VNGO_MAX_VERTCOUNT);

    VngoTexture3D *tptr = tex->vtex3d;

    while(tptr != NULL && tptr->get_type() != VNGO_MEM_TEX)
    {
        tptr = tptr->next;
    }
    if (tptr == NULL)
    {
        tptr = new VngoMemTexture3D(tex);
        if (tptr->get_err_status() != VNGO_NO_ERROR)
        {
            delete tptr;
            return (VNGO_UNSUPPORTED_TEXTURE);
        }
    }


    if (!(((VngoMemTexture3D*)tptr)->vtxt->flags & VNGO_TEXTURE_8BIT))
    {
        return (VNGO_UNSUPPORTED_TEXTURE);
    }

    VngoPoint2 tpts[VNGO_MAX_VERTCOUNT];
    for (int i=0;i < count;i++)
    {
        tpts[i].x = long(pts[i].x * float(0x10000));
        tpts[i].y = long(pts[i].y * float(0x10000));
        tpts[i].z = dword(pts[i].z * float(0xffffffff));
        tpts[i].w = long(pts[i].w * float(0x3ffffff));
        tpts[i].shade = long(pts[i].shade) << 16;
        tpts[i].u = long(pts[i].u * float(0x10000) * float(tex->width));
        tpts[i].v = long(pts[i].v * float(0x10000) * float(tex->height));

        assert (pts[i].x >= 0);
        assert (pts[i].x < vbuff.width << 16);
        assert (pts[i].y >= 0);
        assert (pts[i].y < vbuff.height << 16);
    }
    vngo_atgpoly_persp8(this,count,tpts,tptr,alpha);
    return VNGO_NO_ERROR;
}

//葦� End of module - vngpoly8.cpp 憶�


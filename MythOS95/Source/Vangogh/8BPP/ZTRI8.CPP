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
// ztri8.cpp
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//#include <assert.h>
#include <string.h>

#include "debug.h"
#include "portable.h"
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

extern "C" void scan_zsolid_edge(VngoPoint2 *edge,VngoPoint2 *p1, VngoPoint2 *p2);
extern "C" void draw_zhlines(VngoTriangle *tri);

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

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳
//  void vngo_triangle8(VngoVbuffer *vb,VngoPoint2 *pts,dword color)
//      This routine draws a flat shaded triangle, making the assumption
//      that it has already been clipped.
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳

extern "C" void vngo_ztriangle8 (VngoVbuffer *vb,VngoPoint2 *pts,dword color)
{
    long            mid_y;
    VngoTriangle    tri;
    int             high_pt_idx = 0;
    int             low_pt_idx = 2;
    int             mid_pt_idx = 1;
    VngoPoint2      *edge1 = vb->edge1;
    VngoPoint2      *edge2 = vb->edge2;

    calc_order(high_pt_idx,mid_pt_idx,low_pt_idx,pts);

    VngoPoint2 *high_pt = &pts[high_pt_idx];
    VngoPoint2 *mid_pt = &pts[mid_pt_idx];
    VngoPoint2 *low_pt = &pts[low_pt_idx];

    long    dy1 = ((low_pt->y + 0x8000) >> 16) - ((high_pt->y + 0x8000) >> 16);
    long    dy2 = ((mid_pt->y + 0x8000) >> 16) - ((high_pt->y + 0x8000) >> 16);

    if (dy1 == 0)
    {   // the triangle is completely flat if this is true.
        return;
    }

    if (dy1 > dy2)
        mid_y = dy2;
    else
        mid_y = dy2-1;


    VngoShadePal8   *tp = (VngoShadePal8*)vb->pal->shd_pal;
    VngoColorShade8 *tc = &(*tp)[color];

    tri.start_y = (high_pt->y + 0x8000) >> 16;
    tri.sptr = vb->scrn_ptr + vb->ytable[tri.start_y];
    tri.zptr = (word*)(long(vb->zbuff_ptr) + vb->ztable[tri.start_y]);
    tri.vbuff = vb;
    tri.pitch = vb->pitch;
    tri.zpitch = vb->zpitch;
    tri.color = tc->shl[pts[0].shade >> 19];
    tri.height = dy1;


    scan_zsolid_edge(edge1,high_pt,low_pt);

    scan_zsolid_edge(edge2,high_pt,mid_pt);

    scan_zsolid_edge(&edge2[dy2],mid_pt,low_pt);


    long mid_dx = ((edge2[mid_y].x + 0x8000) >> 16) - ((edge1[mid_y].x + 0x8000) >> 16);

    if (mid_dx >= 0)
    {
        tri.left_edge = edge1;
        tri.right_edge = edge2;
        if (mid_dx)
            tri.zstep_dx1 = (long(edge2[mid_y].z) - long(edge1[mid_y].z)) / mid_dx;
        else
            tri.zstep_dx1 = 0;
    }
    else
    {
        tri.left_edge = edge2;
        tri.right_edge = edge1;

        tri.zstep_dx1 = (long(edge1[mid_y].z) - long(edge2[mid_y].z)) / -mid_dx;
    }
    draw_zhlines(&tri);
}

extern "C" void scan_zsolid_edge(VngoPoint2 *edge,VngoPoint2 *p1, VngoPoint2 *p2)
{
    Flx16 xstep;
    Flx16 zstep;
    Flx16 dy = Flx16(p2->y - p1->y,0);
    long  count = ((p2->y + 0x8000) >> 16) - ((p1->y + 0x8000) >> 16);
    if (count)
    {
        Flx16 dz = Flx16(long(ulong(p2->z) >> 1),0) - Flx16(long(ulong(p1->z) >> 1),0);
        Flx16 dx = Flx16(p2->x - p1->x,0);
        if (dy.flx < 0x10000)
        {
            xstep = dx;
            zstep = dz;
        }
        else
        {
            xstep = dx / dy;
            zstep = dz / dy;
        }
        Flx16 wx = Flx16(p1->x,0);
        Flx16 wz = Flx16(long(ulong(p1->z) >> 1), 0);

        count++;
        while (count--)
        {
            edge->x = wx.flx;
            edge->z = wz.flx;
            edge++;
            wx += xstep;
            wz += zstep;
        }
    }
}



extern "C" void draw_zhlines(VngoTriangle *tri)
{
    long        count = tri->height;
    long        pitch = tri->pitch;
    long        zpitch = tri->zpitch >> 1;
    long        zstep_dx1 = tri->zstep_dx1;
    byte        *scrn = (byte*)tri->sptr;
    word        *zbuff = (word*)tri->zptr;
    VngoPoint2  *edge1 = tri->left_edge;
    VngoPoint2  *edge2 = tri->right_edge;
    byte        clr = (byte)tri->color;

    for (long y=0;y <= count;y++)
    {
        long tz = edge1->z;
        long tx = (edge1->x + 0x8000) >> 16;
        byte *ptr = scrn + tx;
        word *zptr = zbuff + tx;
        int dx = ((edge2->x + 0x8000) >> 16) - tx;

        for (int x = 0;x <= dx; x++)
        {
            word wz = word(tz >> 15);
            if (wz < *zptr)
            {
                *zptr = wz;
                *ptr = clr;
            }
            ptr++;
            zptr++;
            tz += zstep_dx1;
        }
        scrn += pitch;
        zbuff += zpitch;
        edge1++;
        edge2++;
    }
}

//葦� End of module - ztri8.cpp 憶�

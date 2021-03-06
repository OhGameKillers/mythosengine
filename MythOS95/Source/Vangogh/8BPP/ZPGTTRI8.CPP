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
// zpgttri8.cpp
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
#include <assert.h>
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

extern "C" void scan_zpgouraud_edge(VngoPoint2 *edge,VngoPointF2 *p1, VngoPointF2 *p2);
extern "C" void draw_zpghlines(VngoTriangle *tri);
extern "C" void draw_zpghlines_256x256_ntrans(VngoTriangle *tri);
extern "C" void draw_zpghlines_128x128_ntrans(VngoTriangle *tri);

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

extern "C" void vngo_ztgtriangle8_persp (VngoVbuffer *vb,VngoPoint2 *pts,
                                        VngoTexture3D *tex)
{
    long            mid_y;
    VngoTriangle    tri;
    int             high_pt_idx = 0;
    int             low_pt_idx = 2;
    int             mid_pt_idx = 1;
    VngoPoint2      *edge1 = vb->edge1;
    VngoPoint2      *edge2 = vb->edge2;

    calc_order(high_pt_idx,mid_pt_idx,low_pt_idx,pts);

    float       flxconv = 1.f / 65536.f;
    VngoPointF2  high_pt;
    high_pt.x = pts[high_pt_idx].x;
    high_pt.y = pts[high_pt_idx].y;
    high_pt.z = pts[high_pt_idx].z;
    high_pt.shade = pts[high_pt_idx].shade;
    high_pt.w = float(pts[high_pt_idx].w) / float(1 << 30);
    high_pt.u = (float(pts[high_pt_idx].u) * flxconv) * high_pt.w;
    high_pt.v = (float(pts[high_pt_idx].v) * flxconv) * high_pt.w;

    VngoPointF2  mid_pt;
    mid_pt.x = pts[mid_pt_idx].x;
    mid_pt.y = pts[mid_pt_idx].y;
    mid_pt.z = pts[mid_pt_idx].z;
    mid_pt.shade = pts[mid_pt_idx].shade;
    mid_pt.w = float(pts[mid_pt_idx].w) / float(1 << 30);
    mid_pt.u = (float(pts[mid_pt_idx].u) * flxconv) * mid_pt.w;
    mid_pt.v = (float(pts[mid_pt_idx].v) * flxconv) * mid_pt.w;

    VngoPointF2  low_pt;
    low_pt.x = pts[low_pt_idx].x;
    low_pt.y = pts[low_pt_idx].y;
    low_pt.z = pts[low_pt_idx].z;
    low_pt.shade = pts[low_pt_idx].shade;
    low_pt.w = float(pts[low_pt_idx].w) / float(1 << 30);
    low_pt.u = (float(pts[low_pt_idx].u) * flxconv) * low_pt.w;
    low_pt.v = (float(pts[low_pt_idx].v) * flxconv) * low_pt.w;

    long    dy1 = ((low_pt.y + 0x8000) >> 16) - ((high_pt.y + 0x8000) >> 16);
    long    dy2 = ((mid_pt.y + 0x8000) >> 16) - ((high_pt.y + 0x8000) >> 16);

    if (dy1 == 0)
    {   // the triangle is completely flat if this is true.
        return;
    }

    tri.start_y = (high_pt.y + 0x8000) >> 16;
    tri.color = pts[0].clr;
    tri.sptr  = vb->scrn_ptr + vb->ytable[tri.start_y];
    tri.zptr  = (word*)(long(vb->zbuff_ptr) + vb->ztable[tri.start_y]);

    scan_zpgouraud_edge(edge1,&high_pt,&low_pt);

    scan_zpgouraud_edge(edge2,&high_pt,&mid_pt);

    scan_zpgouraud_edge(&edge2[dy2],&mid_pt,&low_pt);

    tri.vbuff = vb;
    tri.pitch = vb->pitch;
    tri.zpitch = vb->zpitch;
    tri.height = dy1;

    assert (tex->get_type()==VNGO_MEM_TEX);
    tri.tex = (VngoMemTexture3D*)tex;
    tri.shade = pts[0].shade;

    if (dy1 > dy2)
    {
        mid_y = dy2;
    }
    else
    {
        mid_y = dy2 - 1;
    }
    long mid_dx = ((edge2[mid_y].x + 0x8000) >> 16)
                  - ((edge1[mid_y].x + 0x8000) >> 16);


    mid_dx = ((edge2[mid_y].x + 0x8000) >> 16)
             - ((edge1[mid_y].x + 0x8000) >> 16);


    if (mid_dx >= 0)
    {
        tri.left_edge = edge1;
        tri.right_edge = edge2;
        if (mid_dx)
        {
            tri.zstep_dx1 = (long(edge2[mid_y].z) - long(edge1[mid_y].z)) / mid_dx;
            tri.sstep_dx1 = (long(edge2[mid_y].shade) - long(edge1[mid_y].shade)) / mid_dx;
        }
        else
        {
            tri.zstep_dx1 = 0;
            tri.sstep_dx1 = 0;
        }
    }
    else
    {
        tri.left_edge = edge2;
        tri.right_edge = edge1;

        tri.zstep_dx1 = (long(edge1[mid_y].z) - long(edge2[mid_y].z)) / -mid_dx;
        tri.sstep_dx1 = (long(edge1[mid_y].shade) - long(edge2[mid_y].shade)) / -mid_dx;
    }

    if (tri.tex->vtxt->width == tri.tex->vtxt->height)
    {

        if (tri.tex->vtxt->width == 128 && !(tri.tex->vtxt->flags & VNGO_TEXTURE_TRANSPARENT))
        {
            draw_zpghlines_128x128_ntrans(&tri);
        }
        else if (tri.tex->vtxt->width == 256 && !(tri.tex->vtxt->flags & VNGO_TEXTURE_TRANSPARENT))
        {
            draw_zpghlines_256x256_ntrans(&tri);
        }
        else
        {
            draw_zpghlines(&tri);
        }
    }
    else
    {
        draw_zpghlines(&tri);
    }
}

extern "C" void scan_zpgouraud_edge(VngoPoint2 *edge,VngoPointF2 *p1, VngoPointF2 *p2)
{
    Flx16 xstep;
    Flx16 zstep;
    Flx16 sstep;
    float ustep;
    float vstep;
    float wstep;

    Flx16 dy = Flx16(p2->y - p1->y,0);
    float fdy = float(dy);

    long  count = ((p2->y + 0x8000) >> 16) - ((p1->y + 0x8000) >> 16);
    if (count)
    {
        Flx16 dz = Flx16(long(ulong(p2->z) >> 1),0) - Flx16(long(ulong(p1->z) >> 1),0);
        Flx16 dx = Flx16(p2->x - p1->x,0);
        Flx16 ds = Flx16(p2->shade,0) - Flx16(p1->shade,0);
        float du = p2->u - p1->u;
        float dv = p2->v - p1->v;
        float dw = p2->w - p1->w;

        if (dy.flx < 0x10000)
        {
            xstep = dx;
            zstep = dz;
            sstep = ds;
            ustep = du;
            vstep = dv;
            wstep = dw;
        }
        else
        {
            xstep = dx / dy;
            zstep = dz / dy;
            sstep = ds / dy;
            ustep = du / fdy;
            vstep = dv / fdy;
            wstep = dw / fdy;
        }
        Flx16 wx = Flx16(p1->x,0);
        Flx16 wz = Flx16(long(ulong(p1->z) >> 1), 0);
        Flx16 ws = Flx16(p1->shade,0);
        float wu = p1->u;
        float wv = p1->v;
        float ww = p1->w;

        count++;
        while (count--)
        {
            edge->x = wx.flx;
            edge->z = wz.flx;
            edge->shade = ws.flx;
            edge->w = long(ww * float(1<<30));
            edge->u = Flx16(wu / ww).flx;
            edge->v = Flx16(wv / ww).flx;

            edge++;
            wx.flx += xstep.flx;
            wz.flx += zstep.flx;
            ws.flx += sstep.flx;
            wu += ustep;
            wv += vstep;
            ww += wstep;
        }
    }
}


extern long DitherMatrix[4][4];

extern "C" void draw_zpghlines(VngoTriangle *tri)
{
    VngoShadePal8   *tp = (VngoShadePal8 *)tri->vbuff->pal->shd_pal;
    VngoColorShade8 *tc = &(*tp)[0];
    byte            *stable = &tc->shl[0];

    long            count = tri->height;
    long            pitch = tri->pitch;
    long            zpitch = tri->zpitch >> 1;

    long            sstep_dx1 = tri->sstep_dx1;
    long            zstep_dx1 = tri->zstep_dx1;
    long            ustep_dx1 = tri->ustep_dx1;
    long            ustep_dx2 = tri->ustep_dx2;
    long            vstep_dx1 = tri->vstep_dx1;
    long            vstep_dx2 = tri->vstep_dx2;

    byte            *scrn = (byte*)tri->sptr;
    word            *zbuff = (word*)tri->zptr;
    VngoPoint2      *edge1 = tri->left_edge;
    VngoPoint2      *edge2 = tri->right_edge;
    long            uup = tri->tex->u_upshift;
    long            vup = tri->tex->v_upshift;
    long            udown = tri->tex->u_downshift;
    long            vdown = tri->tex->v_downshift - tri->tex->widthshift;
    long            start_y = tri->start_y;
    byte            *tptr = (byte*)tri->tex->vtxt->tex;
    long            mask = ~((1 << tri->tex->widthshift) - 1);
    byte            clr;

    for (long y=0;y <= count;y++)
    {
        long tz = edge1->z;
        long ts = edge1->shade;
        long tu = edge1->u << uup;
        long tv = edge1->v << vup;

        long tx = (edge1->x + 0x8000) >> 16;
        byte *ptr = scrn + tx;
        word *zptr = zbuff + tx;
        long *dmatrix = &DitherMatrix[(start_y+y)&3][0];
        int dx = ((edge2->x + 0x8000) >> 16);
        int ldx = dx - tx;

        if (ldx > 0)
        {
            vngo_calc_quadratic2(edge1->w,edge2->w,edge1->u,edge2->u,ldx,
                                &ustep_dx1,&ustep_dx2,uup);
            vngo_calc_quadratic2(edge1->w,edge2->w,edge1->v,edge2->v,ldx,
                                &vstep_dx1,&vstep_dx2,vup);
        }
        else
        {
            ustep_dx1=0;
            ustep_dx2=0;
            vstep_dx1=0;
            vstep_dx2=0;
        }

        for (int x = tx;x <= dx; x++)
        {
            word wz = word(tz >> 15);
            if (wz < *zptr)
            {
                clr = tptr[(((dword)tv >> vdown) & mask)
                           + ((dword)tu >> udown)];

                if (clr != VNGO_TRANSPARENT_COLOR)
                {
                    *zptr = wz;
                    int ws = (ts + dmatrix[x&3]) >> 19;
                    if (ws > 31)
                        ws = 31;
                    else if (ws < 0)
                        ws =0;

                    *ptr = stable[(clr << 5) + ws];
                }
            }
            ptr++;
            zptr++;
            tz += zstep_dx1;
            ts += sstep_dx1;
            tu += ustep_dx1;
            tv += vstep_dx1;
            ustep_dx1 += ustep_dx2;
            vstep_dx1 += vstep_dx2;
        }
        scrn += pitch;
        zbuff += zpitch;
        edge1++;
        edge2++;
    }
}

#if 1
extern "C" void draw_zpghlines_256x256_ntrans(VngoTriangle *tri)
{
    VngoShadePal8   *tp = (VngoShadePal8 *)tri->vbuff->pal->shd_pal;
    VngoColorShade8 *tc = &(*tp)[0];
    byte            *stable = &tc->shl[0];

    long            count = tri->height;
    long            pitch = tri->pitch;
    long            zpitch = tri->zpitch >> 1;

    long            sstep_dx1 = tri->sstep_dx1;
    long            zstep_dx1 = tri->zstep_dx1;
    long            ustep_dx1 = tri->ustep_dx1;
    long            ustep_dx2 = tri->ustep_dx2;
    long            vstep_dx1 = tri->vstep_dx1;
    long            vstep_dx2 = tri->vstep_dx2;

    byte            *scrn = (byte*)tri->sptr;
    word            *zbuff = (word*)tri->zptr;
    VngoPoint2      *edge1 = tri->left_edge;
    VngoPoint2      *edge2 = tri->right_edge;
    long            uup = tri->tex->u_upshift;
    long            vup = tri->tex->v_upshift;
    long            start_y = tri->start_y;
    byte            *tptr = (byte*)tri->tex->vtxt->tex;
    byte            clr;

    for (long y=0;y <= count;y++)
    {
        long tz = edge1->z;
        long ts = edge1->shade;
        long tu = edge1->u << uup;
        long tv = edge1->v << vup;

        long tx = (edge1->x + 0x8000) >> 16;
        byte *ptr = scrn + tx;
        word *zptr = zbuff + tx;
        long *dmatrix = &DitherMatrix[(start_y+y)&3][0];
        int dx = ((edge2->x + 0x8000) >> 16);
        int ldx = dx - tx;

        if (ldx > 0)
        {
            vngo_calc_quadratic2(edge1->w,edge2->w,edge1->u,edge2->u,ldx,
                                &ustep_dx1,&ustep_dx2,uup);
            vngo_calc_quadratic2(edge1->w,edge2->w,edge1->v,edge2->v,ldx,
                                &vstep_dx1,&vstep_dx2,vup);
        }
        else
        {
            ustep_dx1=0;
            ustep_dx2=0;
            vstep_dx1=0;
            vstep_dx2=0;
        }

        for (int x = tx;x <= dx; x++)
        {
            word wz = word(tz >> 15);
            if (wz < *zptr)
            {
                *zptr = wz;

                int ws = (ts + dmatrix[x&3]) >> 19;
                if (ws > 31)
                    ws = 31;
                else if (ws < 0)
                    ws =0;

                clr = tptr[(((dword)tv >> 16) & 0xff00)
                           + ((dword)tu >> 24)];

                *ptr = stable[(clr << 5) + ws];
            }
            ptr++;
            zptr++;
            tz += zstep_dx1;
            ts += sstep_dx1;
            tu += ustep_dx1;
            tv += vstep_dx1;
            ustep_dx1 += ustep_dx2;
            vstep_dx1 += vstep_dx2;
        }
        scrn += pitch;
        zbuff += zpitch;
        edge1++;
        edge2++;
    }
}

extern "C" void draw_zpghlines_128x128_ntrans(VngoTriangle *tri)
{
    VngoShadePal8   *tp = (VngoShadePal8 *)tri->vbuff->pal->shd_pal;
    VngoColorShade8 *tc = &(*tp)[0];
    byte            *stable = &tc->shl[0];

    long            count = tri->height;
    long            pitch = tri->pitch;
    long            zpitch = tri->zpitch >> 1;

    long            sstep_dx1 = tri->sstep_dx1;
    long            zstep_dx1 = tri->zstep_dx1;
    long            ustep_dx1 = tri->ustep_dx1;
    long            ustep_dx2 = tri->ustep_dx2;
    long            vstep_dx1 = tri->vstep_dx1;
    long            vstep_dx2 = tri->vstep_dx2;

    byte            *scrn = (byte*)tri->sptr;
    word            *zbuff = (word*)tri->zptr;
    VngoPoint2      *edge1 = tri->left_edge;
    VngoPoint2      *edge2 = tri->right_edge;
    long            uup = tri->tex->u_upshift;
    long            vup = tri->tex->v_upshift;
    long            start_y = tri->start_y;
    byte            *tptr = (byte*)tri->tex->vtxt->tex;
    byte            clr;

    for (long y=0;y <= count;y++)
    {
        long tz = edge1->z;
        long ts = edge1->shade;
        long tu = edge1->u << uup;
        long tv = edge1->v << vup;

        long tx = (edge1->x + 0x8000) >> 16;
        byte *ptr = scrn + tx;
        word *zptr = zbuff + tx;
        long *dmatrix = &DitherMatrix[(start_y+y)&3][0];
        int dx = ((edge2->x + 0x8000) >> 16);
        int ldx = dx - tx;

        if (ldx > 0)
        {
            vngo_calc_quadratic2(edge1->w,edge2->w,edge1->u,edge2->u,ldx,
                                &ustep_dx1,&ustep_dx2,uup);
            vngo_calc_quadratic2(edge1->w,edge2->w,edge1->v,edge2->v,ldx,
                                &vstep_dx1,&vstep_dx2,vup);
        }
        else
        {
            ustep_dx1=0;
            ustep_dx2=0;
            vstep_dx1=0;
            vstep_dx2=0;
        }

        for (int x = tx;x <= dx; x++)
        {
            word wz = word(tz >> 15);
            if (wz < *zptr)
            {
                *zptr = wz;

                int ws = (ts + dmatrix[x&3]) >> 19;
                if (ws > 31)
                    ws = 31;
                else if (ws < 0)
                    ws =0;

                clr = tptr[(((dword)tv >> 18) & 0xff80)
                           + ((dword)tu >> 25)];

                *ptr = stable[(clr << 5) + ws];
            }
            ptr++;
            zptr++;
            tz += zstep_dx1;
            ts += sstep_dx1;
            tu += ustep_dx1;
            tv += vstep_dx1;
            ustep_dx1 += ustep_dx2;
            vstep_dx1 += vstep_dx2;
        }
        scrn += pitch;
        zbuff += zpitch;
        edge1++;
        edge2++;
    }
}
#endif
//葦� End of module - zlttri8.cpp 憶�

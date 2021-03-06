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
// vngttri8.cpp
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
#include <assert.h>

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

extern "C" void vngo_ttriangle8 (VngoVbuffer *vb,VngoPoint2 *pts,
                                 VngoTexture3D *tex);
extern "C" void vngo_zttriangle8 (VngoVbuffer *vbb,VngoPoint2 *pts,
                                  VngoTexture3D *tex);
extern "C" void vngo_tgtriangle8 (VngoVbuffer *vb,VngoPoint2 *pts,
                                   VngoTexture3D *tex);
extern "C" void vngo_ztgtriangle8 (VngoVbuffer *vb,VngoPoint2 *pts,
                                   VngoTexture3D *tex);
extern "C" void vngo_aztgtriangle8 (VngoVbuffer *vb,VngoPoint2 *pts,
                                    VngoTexture3D *tex,long alpha);
extern "C" void vngo_azttriangle8 (VngoVbuffer *vb,VngoPoint2 *pts,
                                   VngoTexture3D *tex, long alpha);
extern "C" void vngo_attriangle8 (VngoVbuffer *vb,VngoPoint2 *pts,
                                  VngoTexture3D *tex,long alpha);
extern "C" void vngo_atgtriangle8 (VngoVbuffer *vb,VngoPoint2 *pts,
                                    VngoTexture3D *tex,long alpha);

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
//  vngo_tpoly(VngoVport *vb, int count, VngoPoint2 *pts,
//              VngoTexture3D *tex);
//      Draws an N sided convex polygon, by breaking it down into triangles
//      if it is not already a triangle.  It draws with flat shading, and
//      texture mapping.
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void vngo_tpoly8 (VngoVport *vp,int count,VngoPoint2 *pts, VngoTexture3D *tex)
{
    if (count != 3)
    {
        if (count > 3)
        {
            // if there are more than three vertices, break it into a series
            // of triangles.
            for (int i=1;i < count-1;i++)
            {
                VngoPoint2 tpts[3];
                tpts[0] = pts[0];
                tpts[1] = pts[i];
                tpts[2] = pts[i+1];
                if (vp->vflags & VNGO_ZBUFFER_ACTIVE)
                    vngo_zttriangle8 (&vp->vbuff,tpts,tex);
                else
                    vngo_ttriangle8 (&vp->vbuff,tpts,tex);
            }
        }
    }
    else
    {
        if (vp->vflags & VNGO_ZBUFFER_ACTIVE)
            vngo_zttriangle8 (&vp->vbuff,pts,tex);
        else
            vngo_ttriangle8 (&vp->vbuff,pts,tex);
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  vngo_tpoly(VngoVport *vb, int count, VngoPoint2 *pts,
//              VngoTexture3D *tex);
//      Draws an N sided convex polygon, by breaking it down into triangles
//      if it is not already a triangle.  It draws with flat shading, and
//      texture mapping.
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void vngo_atpoly8 (VngoVport *vp,int count,VngoPoint2 *pts,
                   VngoTexture3D *tex, long alpha)
{
    if (count != 3)
    {
        if (count > 3)
        {
            // if there are more than three vertices, break it into a series
            // of triangles.
            for (int i=1;i < count-1;i++)
            {
                VngoPoint2 tpts[3];
                tpts[0] = pts[0];
                tpts[1] = pts[i];
                tpts[2] = pts[i+1];
                if (vp->vflags & VNGO_ZBUFFER_ACTIVE)
                    vngo_azttriangle8 (&vp->vbuff,tpts,tex,alpha);
                else
                    vngo_attriangle8 (&vp->vbuff,tpts,tex,alpha);
            }
        }
    }
    else
    {
        if (vp->vflags & VNGO_ZBUFFER_ACTIVE)
            vngo_azttriangle8 (&vp->vbuff,pts,tex,alpha);
        else
            vngo_attriangle8 (&vp->vbuff,pts,tex,alpha);
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  vngo_tgpoly(VngoVport *vp, int count, VngoPoint2 *pts,
//              VngoTexture3D *tex);
//      Draws an N sided convex polygon, by breaking it down into triangles
//      if it is not already a triangle.  It draws with Gouraud shading and
//      texture mapping.
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void vngo_tgpoly8 (VngoVport *vp,int count,VngoPoint2 *pts, VngoTexture3D *tex)
{
    if (count != 3)
    {
        if (count > 3)
        {
            // if there are more than three vertices, break it into a series
            // of triangles.
            for (int i=1;i < count-1;i++)
            {
                VngoPoint2 tpts[3];
                tpts[0] = pts[0];
                tpts[1] = pts[i];
                tpts[2] = pts[i+1];
                if (vp->vflags & VNGO_ZBUFFER_ACTIVE)
                    vngo_ztgtriangle8 (&vp->vbuff,tpts,tex);
                else
                    vngo_tgtriangle8 (&vp->vbuff,tpts,tex);
            }
        }
    }
    else
    {
        if (vp->vflags & VNGO_ZBUFFER_ACTIVE)
            vngo_ztgtriangle8 (&vp->vbuff,pts,tex);
        else
            vngo_tgtriangle8 (&vp->vbuff,pts,tex);
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  vngo_tgpoly(VngoVport *vp, int count, VngoPoint2 *pts,
//              VngoTexture3D *tex);
//      Draws an N sided convex polygon, by breaking it down into triangles
//      if it is not already a triangle.  It draws with Gouraud shading and
//      texture mapping.
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void vngo_atgpoly8 (VngoVport *vp,int count,VngoPoint2 *pts,
                    VngoTexture3D *tex, long alpha)
{
    if (count != 3)
    {
        if (count > 3)
        {
            // if there are more than three vertices, break it into a series
            // of triangles.
            for (int i=1;i < count-1;i++)
            {
                VngoPoint2 tpts[3];
                tpts[0] = pts[0];
                tpts[1] = pts[i];
                tpts[2] = pts[i+1];
                if (vp->vflags & VNGO_ZBUFFER_ACTIVE)
                    vngo_aztgtriangle8 (&vp->vbuff,tpts,tex,alpha);
                else
                    vngo_atgtriangle8 (&vp->vbuff,tpts,tex,alpha);
            }
        }
    }
    else
    {
        if (vp->vflags & VNGO_ZBUFFER_ACTIVE)
            vngo_aztgtriangle8 (&vp->vbuff,pts,tex,alpha);
        else
            vngo_atgtriangle8 (&vp->vbuff,pts,tex,alpha);
    }
}







//葦� End of module - vngttri.cpp 憶�

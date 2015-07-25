//���������������������������������������������������������������������������
//
//                                                           %__________%
//                                                          %/ . .  .   \%
//           Van Gogh 2D-Display Library                     |  . .  o. |
//                                                           |. _  .   .|
//          Microsoft Windows '95 Version                    | / \   .  |
//                                                           |_|_|_._._.|
// Copyright (c) 1994-1997 by Charybdis Enterprises, Inc.    |.-.-.-.-..|
//              All rights reserved.                        %\__________/%
//                                                           %          %
//
//���������������������������������������������������������������������������
//
//           *** Charybdis Enterprises, Inc. Company Confidential ***
//
//  This file and all associated files are the company proprietary property
//        of Charybdis Enterprises, Inc.  Unauthorized use prohibited.
//
// CHARYBDIS ENTERPRISES, INC. MAKES NO WARRANTIES, EXPRESS OR IMPLIED, AS
// TO THE CORRECTNESS OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE
// IT.  CHARYBDIS ENTERPRISES, INC. PROVIDES THE CODE ON AN "AS-IS" BASIS
// AND EXPLICITLY DISCLAIMS ANY LIABILITY, INCLUDING CONSEQUENTIAL AND
// INCIDENTAL DAMAGES FOR ERRORS, OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//���������������������������������������������������������������������������
//
// vngd3d.hpp
//
// Contains the Direct3D viewport class definition
//
//���������������������������������������������������������������������������

#ifdef  _D3D
#ifndef __VNGD3D_HPP
#define __VNGD3D_HPP  1

//���������������������������������������������������������������������������
//
//                                Includes
//
//���������������������������������������������������������������������������

#include "portable.h"
#include "vngdefs.h"
#include "vngvp.hpp"
#include "vngstrct.hpp"
#include "vngscrn.hpp"

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//���������������������������������������������������������������������������
//
//                                Classes
//
//���������������������������������������������������������������������������

class VngoVportD3D : public VngoVport
{
    long            left,top;
    VngoDirect3D    *screen;

    int plock();
    int punlock();
public:
    VngoVportD3D() {};
    VngoVportD3D(long,long,long,long,VngoPal *,dword,VngoScreenManager *_screen);
    virtual ~VngoVportD3D();

    virtual VNGError init (long,long,long,long,VngoPal *,dword,VngoScreenManager *_screen);

    // All of these functions will be virtuals eventualy.
    virtual void zbuffer_on();
    virtual void zbuffer_off();
    virtual void reset(dword c=0,dword farz=0xffffffff);


    virtual VNGError vpcopy (int destx,int desty,VngoVport *dest);
//            {return VNGO_NOT_SUPPORTED;};

    virtual VNGError pixel (VngoPoint *pt, VngoColor24bit *rgb_val = NULL)
            {return VNGO_NOT_SUPPORTED;};
    virtual VNGError pixel (VngoPointF *pt, VngoColor24bit *rgb_val = NULL)
            {return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_pixel (VngoPoint *pt, VngoColor24bit *rgb_val = NULL,
                                 VngoRect *clip_rect=NULL)
            {return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_pixel (VngoPointF *pt, VngoColor24bit *rgb_val = NULL,
                                 VngoRect *clip_rect=NULL)
            {return VNGO_NOT_SUPPORTED;};
    virtual dword read_pixel (VngoPoint *pt, VngoPoint *dest)
            {return VNGO_NOT_SUPPORTED;};
    virtual dword read_pixel (int x, int y, VngoPoint *dest)
            {return VNGO_NOT_SUPPORTED;};

    virtual VNGError frect (VngoRect *rect, dword color);
    virtual VNGError frect (VngoRect *rect, VngoColor24bit *rgb_val);
    virtual VNGError clip_frect (VngoRect *rect,
                                 dword color,
                                 VngoRect *clip_rect=NULL);
    virtual VNGError clip_frect (VngoRect *rect,
                                 VngoColor24bit *rgb_val,
                                 VngoRect *clip_rect=NULL);

    virtual VNGError line (VngoPoint *p1, VngoPoint *p2,
                           VngoColor24bit *rgb_val=NULL);
    virtual VNGError line (VngoPointF *p1, VngoPointF *p2,
                           VngoColor24bit *rgb_val=NULL);
    virtual VNGError gline (VngoPoint *p1, VngoPoint *p2);
    virtual VNGError gline (VngoPointF *p1, VngoPointF *p2);
    virtual VNGError gline_persp (VngoPoint *p1, VngoPoint *p2);
    virtual VNGError gline_persp (VngoPointF *p1, VngoPointF *p2);

    virtual VNGError clip_line (VngoPoint *p1, VngoPoint *p2,
                                VngoColor24bit *rgb_val=NULL,
                                VngoRect *clip_rect=NULL)
            {return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_line (VngoPointF *p1, VngoPointF *p2,
                                VngoColor24bit *rgb_val=NULL,
                                VngoRect *clip_rect=NULL)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_gline (VngoPoint *p1, VngoPoint *p2,
                                 VngoRect *clip_rect=NULL)
            {return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_gline (VngoPointF *p1, VngoPointF *p2,
                                 VngoRect *clip_rect=NULL)
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_gline_persp (VngoPoint *p1, VngoPoint *p2,
                                       VngoRect *clip_rect=NULL)
            {return VNGO_NOT_SUPPORTED;};
    virtual VNGError clip_gline_persp (VngoPointF *p1, VngoPointF *p2,
                                       VngoRect *clip_rect=NULL)
            { return VNGO_NOT_SUPPORTED;};

// Polygon functions.
    virtual VNGError poly (int count, VngoPoint pts[]);
    virtual VNGError poly (int count, VngoPointF pts[]);
    virtual VNGError gpoly (int count, VngoPoint pts[]);
    virtual VNGError gpoly (int count, VngoPointF pts[]);

    virtual VNGError gpoly_persp (int count, VngoPoint pts[]);
    virtual VNGError gpoly_persp (int count, VngoPointF pts[]);
    virtual VNGError tpoly (int count, VngoPoint pts[],VngoTexture *tex);
//            {return VNGO_NOT_SUPPORTED;};
    virtual VNGError tpoly (int count, VngoPointF pts[],VngoTexture *tex);
//            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError tpoly_persp (int count, VngoPoint pts[],VngoTexture *tex);
//            {return VNGO_NOT_SUPPORTED;};
    virtual VNGError tpoly_persp (int count, VngoPointF pts[],VngoTexture *tex);
//            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError gtpoly (int count, VngoPoint pts[],VngoTexture *tex);
//            {return VNGO_NOT_SUPPORTED;};
    virtual VNGError gtpoly (int count, VngoPointF pts[],VngoTexture *tex);
//            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError gtpoly_persp (int count, VngoPoint pts[],VngoTexture *tex);
//            {return VNGO_NOT_SUPPORTED;};
    virtual VNGError gtpoly_persp (int count, VngoPointF pts[],VngoTexture *tex);
//            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError grpoly (int count,VngoPoint pts[])
            { return VNGO_NOT_SUPPORTED;};
    virtual VNGError grpoly (int count,VngoPointF pts[])
            { return VNGO_NOT_SUPPORTED;};

// Alpha blended versions
    virtual VNGError poly_a (int count, VngoPoint pts[],long alpha=127);
    virtual VNGError poly_a (int count, VngoPointF pts[],long alpha=127);
    virtual VNGError gpoly_a (int count, VngoPoint pts[],long alpha=127);
    virtual VNGError gpoly_a (int count, VngoPointF pts[],long alpha=127);
    virtual VNGError gpoly_persp_a (int count, VngoPoint pts[],long alpha=127);
    virtual VNGError gpoly_persp_a (int count, VngoPointF pts[],long alpha=127);
    virtual VNGError tpoly_a (int count, VngoPoint pts[],VngoTexture *tex,
                              long alpha=127);
    virtual VNGError tpoly_a (int count, VngoPointF pts[],VngoTexture *tex,
                              long alpha=127);
    virtual VNGError tpoly_persp_a (int count, VngoPoint pts[],
                                    VngoTexture *tex,long alpha=127);
    virtual VNGError tpoly_persp_a (int count, VngoPointF pts[],
                                    VngoTexture *tex,long alpha=127);
    virtual VNGError gtpoly_a (int count, VngoPoint pts[],VngoTexture *tex,
                               long alpha=127);
    virtual VNGError gtpoly_a (int count, VngoPointF pts[],VngoTexture *tex,
                               long alpha=127);
    virtual VNGError gtpoly_persp_a (int count, VngoPoint pts[],
                                     VngoTexture *tex,long alpha=127);
    virtual VNGError gtpoly_persp_a (int count, VngoPointF pts[],
                                     VngoTexture *tex,long alpha=127);

    virtual VNGError image_trans (VngoRect *dest_rect,VngoTexture *img,
                                  dword flags=0);
    virtual VNGError image_trans_mono (VngoRect *dest_rect,VngoTexture *img,
                                       dword fgcol,dword bgcol=VNGO_TRANSPARENT);
    virtual VNGError zblit_mono (VngoRect *dest_rect,VngoZMap *zmp,dword fdist,
                                 dword ndist=0);

    virtual VNGError image_trans_a (VngoRect *dest_rect,VngoTexture *img,
                                    long alpha=127, dword flags=0)
    {
        return VNGO_NOT_SUPPORTED;
    }
    virtual VNGError image_trans_mono_a (VngoRect *dest_rect,VngoTexture *img,
                                         dword fgcol,dword bgcol=VNGO_TRANSPARENT,
                                         long alpha=127)
    {
        return VNGO_NOT_SUPPORTED;
    }

    virtual VNGError haze(VngoShadePal *hazepal,long startZ=0,VngoRect *rect=NULL)
    {
        return VNGO_NOT_SUPPORTED;
    }
};

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif          // __VNGD3D_HPP
#endif          // _D3D

//��� End of module - vngd3d.hpp ���

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
// vngvp.hpp
//
// Contains the base viewport class definition
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

#ifndef __VNGVP_HPP
#define __VNGVP_HPP  1

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include "portable.h"
#include "vngdefs.h"
#include "vngstrct.hpp"

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

extern VngoSystem *VgSystem;

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Classes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

class VngoVport
{
protected:
    dword               size_in_bytes;
    int                 lock_status;
    VNGError            init_status;
    VngoZMap            *zmap;

public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Public data members                                                  �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    dword               vflags;
    int                 vzdepth_in_bits;
    VngoVbuffer         vbuff;
    float               persp_pixcount;
    float               persp_pixcount2;

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    VngoVport() :
        zmap(0),
        persp_pixcount(VNGO_PERSP_PRECISION)
    {}

    virtual ~VngoVport()
    {}

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Accessor functions                                                   �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    inline VngoVbuffer *get_vbuff() {return &vbuff;}
    inline int get_zbuffer_precision()
    {
        if (vflags &= VNGO_ZBUFFER_ACTIVE)
            return (vzdepth_in_bits);
        else
            return (0);
    }

    inline VNGError get_init_state() { return (init_status); }

    inline VngoZMap * get_zmap() { return zmap; }
    inline int skips_last_pix() { return ((vflags & VNGO_SKIPS_LAST_PIX) ? 1:0);}

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Utility functions.                                                   �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    inline void clear_screen_on() { vflags &= ~VNGO_NOCLEAR_VBUFFER;}
    inline void clear_screen_off() { vflags |= VNGO_NOCLEAR_VBUFFER;}

    inline void set_zmap(VngoZMap *_zmap)
    {
        zmap = _zmap;
        vflags |= VNGO_ZMAP_DEV | VNGO_ZMAP_ACTIVE;
    }
    inline void zmap_on()
    {
        if (vflags & VNGO_ZMAP_DEV)
            vflags |= VNGO_ZMAP_ACTIVE;
    }
    inline void zmap_off() { vflags &= ~VNGO_ZMAP_ACTIVE;}
    inline void filter_auto_correct_on() { vflags |= VNGO_FILTER_AUTOCORRECT; }
    inline void filter_auto_correct_off() { vflags &= ~VNGO_FILTER_AUTOCORRECT; }
    inline void set_perspective (float percent)
    {
        if (percent > 100.f)
            percent = 100.f;
        else if (percent < 1.f)
            percent = 1.f;

        persp_pixcount = (float(vbuff.width) * percent) / 100.f;
        persp_pixcount2 = persp_pixcount * 4.f;
    }

    inline float get_perspective ()
    {
        return ((persp_pixcount / float(vbuff.width)) * 100.f);
    }

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    virtual void sync() {}

    virtual void zbuffer_on()
    {
        if (vflags & VNGO_ZBUFFER_DEV)
            vflags |= VNGO_ZBUFFER_ACTIVE;
    }
    virtual void zbuffer_off() {vflags &= ~VNGO_ZBUFFER_ACTIVE;}

    virtual void texture_filter_on() {vflags |= VNGO_TEXTURE_FILTER;}
    virtual void texture_filter_off() {vflags &= ~VNGO_TEXTURE_FILTER;}

    virtual void true_alpha_on() {vflags |= VNGO_TRUE_ALPHA;}
    virtual void true_alpha_off() {vflags &= ~VNGO_TRUE_ALPHA;}

    virtual void haze_on() {vflags |= VNGO_HAZE_ON;}
    virtual void haze_off() {vflags &= ~VNGO_HAZE_ON;}

    virtual void make_current() { VgSystem->cur_vport = this; }

    virtual VNGError capture(XFBitmap *bm);

    virtual int  lock()
    {
        int ret_val = lock_status;
        lock_status = 1;
        return (ret_val);
    }
    virtual int  unlock()
    {
        int ret_val = lock_status;
        lock_status = 0;
        return (ret_val);
    }

    //陳� Basic drawing functions
    virtual void reset(dword c=0,dword farz=0xffffffff)=0;
    virtual VNGError vpcopy (int destx,int desty,VngoVport *dest)=0;

    //陳� Rectangle drawing functions
    virtual VNGError frect (VngoRect *rect,dword color) = 0;
    virtual VNGError frect (VngoRect *rect,VngoColor24bit *rgb_val = NULL) = 0;
    virtual VNGError clip_frect (VngoRect *rect,dword color, VngoRect *clip=NULL) = 0;
    virtual VNGError clip_frect (VngoRect *rect,VngoColor24bit *rgb_val, VngoRect *clip=NULL) = 0;

    //陳� Pixel drawing functions
    virtual VNGError pixel (VngoPoint *pt, VngoColor24bit *rgb_val = NULL) = 0;
    virtual VNGError pixel (VngoPointF *pt, VngoColor24bit *rgb_val = NULL) = 0;
    virtual VNGError clip_pixel (VngoPoint *pt, VngoColor24bit *rgb_val = NULL, VngoRect *clip_rect=NULL) = 0;
    virtual VNGError clip_pixel (VngoPointF *pt, VngoColor24bit *rgb_val = NULL, VngoRect *clip_rect=NULL) = 0;
    virtual dword read_pixel (VngoPoint *pt, VngoPoint *dest)=0;
    virtual dword read_pixel (int x, int y, VngoPoint *dest)=0;

    //陳� Image transfer functions
    virtual VNGError image_trans (VngoRect *dest_rect,VngoTexture *img,dword flags=0) = 0;
    virtual VNGError image_trans_a (VngoRect *dest_rect,VngoTexture *img,
                                    long alpha=127, dword flags=0) = 0;

    virtual VNGError image_trans_mono (VngoRect *dest_rect,VngoTexture *img,dword fgcol,dword bgcol=VNGO_TRANSPARENT) = 0;
    virtual VNGError zblit_mono (VngoRect *dest_rect,VngoZMap *zmp,dword fdist,dword ndist=0) = 0;

    //陳� Line drawing functions
    virtual VNGError line (VngoPoint *p1,VngoPoint *p2,
                           VngoColor24bit *rgb_val=NULL) = 0;
    virtual VNGError line (VngoPointF *p1,VngoPointF *p2,
                           VngoColor24bit *rgb_val=NULL) = 0;
    virtual VNGError gline (VngoPoint *p1,VngoPoint *p2) = 0;
    virtual VNGError gline (VngoPointF *p1,VngoPointF *p2) = 0;
    virtual VNGError gline_persp (VngoPoint *p1,VngoPoint *p2) = 0;
    virtual VNGError gline_persp (VngoPointF *p1,VngoPointF *p2) = 0;

    virtual VNGError clip_line (VngoPoint *p1,VngoPoint *p2,
                                VngoColor24bit *rgb_val=NULL,
                                VngoRect *clip_rect = NULL) = 0;
    virtual VNGError clip_line (VngoPointF *p1,VngoPointF *p2,
                                VngoColor24bit *rgb_val=NULL,
                                VngoRect *clip_rect = NULL) = 0;
    virtual VNGError clip_gline (VngoPoint *p1,VngoPoint *p2,
                                 VngoRect *clip_rect = NULL) = 0;
    virtual VNGError clip_gline (VngoPointF *p1,VngoPointF *p2,
                                 VngoRect *clip_rect = NULL) = 0;
    virtual VNGError clip_gline_persp (VngoPoint *p1,VngoPoint *p2,
                                       VngoRect *clip_rect = NULL) = 0;
    virtual VNGError clip_gline_persp (VngoPointF *p1,VngoPointF *p2,
                                       VngoRect *clip_rect = NULL) = 0;

    //陳� Polygon drawing functions
    virtual VNGError poly (int count,VngoPoint pts[]) = 0;
    virtual VNGError poly (int count,VngoPointF pts[]) = 0;
    virtual VNGError gpoly (int count,VngoPoint pts[]) = 0;
    virtual VNGError gpoly (int count,VngoPointF pts[]) = 0;
    virtual VNGError gpoly_persp (int count,VngoPoint pts[]) = 0;
    virtual VNGError gpoly_persp (int count,VngoPointF pts[]) = 0;
    virtual VNGError tpoly (int count,VngoPoint pts[],
                            VngoTexture *tex) = 0;
    virtual VNGError tpoly (int count,VngoPointF pts[],
                            VngoTexture *tex) = 0;
    virtual VNGError tpoly_persp (int count,VngoPoint pts[],
                                  VngoTexture *tex) = 0;
    virtual VNGError tpoly_persp (int count,VngoPointF pts[],
                                  VngoTexture *tex) = 0;
    virtual VNGError gtpoly (int count,VngoPoint pts[],
                             VngoTexture *tex) = 0;
    virtual VNGError gtpoly (int count,VngoPointF pts[],
                             VngoTexture *tex) = 0;
    virtual VNGError gtpoly_persp (int count,VngoPoint pts[],
                                   VngoTexture *tex) = 0;
    virtual VNGError gtpoly_persp (int count,VngoPointF pts[],
                                   VngoTexture *tex) = 0;

    virtual VNGError grpoly (int count,VngoPoint pts[])=0;
    virtual VNGError grpoly (int count,VngoPointF pts[])=0;

    //陳� Alpha-blended polygon drawing functions
    virtual VNGError poly_a (int count,VngoPoint pts[],
                             long alpha=127) = 0;
    virtual VNGError poly_a (int count,VngoPointF pts[],
                             long alpha=127) = 0;
    virtual VNGError gpoly_a (int count,VngoPoint pts[],
                              long alpha=127) = 0;
    virtual VNGError gpoly_a (int count,VngoPointF pts[],
                              long alpha=127) = 0;
    virtual VNGError gpoly_persp_a (int count,VngoPoint pts[],
                                    long alpha=127) = 0;
    virtual VNGError gpoly_persp_a (int count,VngoPointF pts[],
                                    long alpha=127) = 0;
    virtual VNGError tpoly_a (int count,VngoPoint pts[],VngoTexture *tex,
                              long alpha=127) = 0;
    virtual VNGError tpoly_a (int count,VngoPointF pts[],VngoTexture *tex,
                              long alpha=127) = 0;
    virtual VNGError tpoly_persp_a (int count,VngoPoint pts[],VngoTexture *tex,
                                    long alpha=127) = 0;
    virtual VNGError tpoly_persp_a (int count,VngoPointF pts[],VngoTexture *tex,
                                    long alpha=127) = 0;
    virtual VNGError gtpoly_a (int count,VngoPoint pts[],VngoTexture *tex,
                               long alpha=127) = 0;
    virtual VNGError gtpoly_a (int count,VngoPointF pts[],VngoTexture *tex,
                               long alpha=127) = 0;
    virtual VNGError gtpoly_persp_a (int count,VngoPoint pts[],VngoTexture *tex,
                                     long alpha=127) = 0;
    virtual VNGError gtpoly_persp_a (int count,VngoPointF pts[],
                                     VngoTexture *tex,long alpha=127) = 0;

    //陳� Fogging/hazing functions
    virtual VNGError set_haze(VngoHazeInfo *haze_info) = 0;
    virtual VNGError haze() = 0;
};

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif          // __VNGVP_HPP

//葦� End of module - vngvp.hpp 憶�


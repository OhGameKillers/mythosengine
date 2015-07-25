//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//�����������Copyright�(c)�1994-1997�by�Charybdis�Enterprises,�Inc.����������
//��������������������������All�Rights�Reserved.�����������������������������
//���������������������������������������������������������������������������
//��������������������� Microsoft Windows '95 Version �����������������������
//���������������������������������������������������������������������������
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
// Created by Tim Little & Chuck Walbourn
//
// esbasic.hpp
//
// Contains some basic draw classes.
//
// EschPointDraw is a single unlit colored point in 3-space.
//
// EschLineDraw is a single unlit colored line in 3-space.
//
// EschSprite is a 2D bitmap always facing the viewer.
//
//���������������������������������������������������������������������������

#ifndef __ESBASIC_HPP
#define __ESBASIC_HPP    1

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//���������������������������������������������������������������������������
//             
//                                Includes
//                                
//���������������������������������������������������������������������������

#include "esdraw.hpp"

//���������������������������������������������������������������������������
//
//                                Classes
//
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschPointDraw -  Single colored point in 3-space.                        �
//���������������������������������������������������������������������������
class EschPointDraw : public EschDrawable
{
public:
    //���������������������������������������������������������������������Ŀ
    // Public data members                                                  �
    //�����������������������������������������������������������������������
    EschPoint   pos;                        // Position
    dword       color;                      // Color

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    EschPointDraw() : EschDrawable(ESCH_DRWT_POINTDRAW) {}

    EschPointDraw(Flx16 ix, Flx16 iy, Flx16 iz, dword c) :
        EschDrawable(ESCH_DRWT_POINTDRAW),
        pos(ix,iy,iz), color(c) {}

    EschPointDraw(const EschPoint *p, dword c, ulong l=0) :
        EschDrawable(ESCH_DRWT_POINTDRAW),
        pos(*p), color(c) {}

    virtual ~EschPointDraw() {}

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    virtual void draw();

    //���������������������������������������������������������������������Ŀ
    // Utility routines.                                                    �
    //�����������������������������������������������������������������������
    void set_position(Flx16 ix, Flx16 iy, Flx16 iz)
    {
        pos.x = ix;  pos.y = iy;  pos.z = iz;
    }
    void set_position(const EschPoint *pnt)
    {
        pos.x = pnt->x;  pos.y = pnt->y;  pos.z = pnt->z;
    }

    void set_color(dword c) { color = c; }
};


//�������������������������������������������������������������������������Ŀ
// EschLineDraw -  Single colored line in 3-space.                          �
//���������������������������������������������������������������������������
class EschLineDraw : public EschDrawable
{
public:
    //���������������������������������������������������������������������Ŀ
    // Public data members                                                  �
    //�����������������������������������������������������������������������
    EschPoint   pos1;                       // End-positions
    EschPoint   pos2;
    dword       color;                      // Color

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    EschLineDraw() : EschDrawable(ESCH_DRWT_LINEDRAW) {}

    EschLineDraw(Flx16 ix1, Flx16 iy1, Flx16 iz1,
                 Flx16 ix2, Flx16 iy2, Flx16 iz2,
                 dword c) :
        EschDrawable(ESCH_DRWT_LINEDRAW),
        pos1(ix1,iy1,iz1), pos2(ix2,iy2,iz2), color(c) {}

    EschLineDraw(const EschPoint *p1, const EschPoint *p2, dword c, ulong l=0) :
        EschDrawable(ESCH_DRWT_LINEDRAW),
        pos1(*p1), pos2(*p2), color(c) {}

    virtual ~EschLineDraw() {}

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    virtual void draw();

    //���������������������������������������������������������������������Ŀ
    // Utility routines.                                                    �
    //�����������������������������������������������������������������������
    void set_position(Flx16 ix1, Flx16 iy1, Flx16 iz1,
                      Flx16 ix2, Flx16 iy2, Flx16 iz2)
    {
        pos1.x = ix1;  pos1.y = iy1;  pos1.z = iz1;
        pos2.x = ix2;  pos2.y = iy2;  pos2.z = iz2;
    }
    void set_position(const EschPoint *pnt1, const EschPoint *pnt2)
    {
        pos1.x = pnt1->x;  pos1.y = pnt1->y;  pos1.z = pnt1->z;
        pos2.x = pnt2->x;  pos2.y = pnt2->y;  pos2.z = pnt2->z;
    }

    void set_color(dword c) { color = c; }
};


//�������������������������������������������������������������������������Ŀ
// EschSprite - 2D bitmap always drawn facing the viewer.                   �
//���������������������������������������������������������������������������
class EschSprite : public EschDrawable
{
protected:
    EschTexture     *txt;
    long            alpha_level;

public:
    //���������������������������������������������������������������������Ŀ
    // Public data members                                                  �
    //�����������������������������������������������������������������������
    EschPoint       pos;
    Flx16           width;
    Flx16           height;

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    EschSprite() :
        EschDrawable(ESCH_DRWT_SPRITE),
        txt(0),
        alpha_level(255) {};
    EschSprite(Flx16 ix, Flx16 iy, Flx16 iz, Flx16 w, Flx16 h) :
        EschDrawable(ESCH_DRWT_SPRITE),
        pos(ix,iy,iz),
        width(w), height(h),
        txt(0),
        alpha_level(255) {};

    virtual ~EschSprite();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    const EschSprite &operator = (const EschSprite &s);

    virtual void draw();
    virtual int get_extents(EschSphereExtents *sp) const;
    virtual void animate();

    virtual void release();

    //���������������������������������������������������������������������Ŀ
    // Utility functions.                                                   �
    //�����������������������������������������������������������������������
    void set_position(Flx16 ix, Flx16 iy, Flx16 iz)
    {
        pos.x = ix;
        pos.y = iy;
        pos.z = iz;
    }
    void set_position(const EschPoint *pnt)
    {
        pos.x = pnt->x;
        pos.y = pnt->y;
        pos.z = pnt->z;
    }

    void set_size(Flx16 w, Flx16 h)
    {
        width=w;
        height=h;
    }

    void set_alpha(long alpha) { alpha_level = alpha; }
    long get_alpha() const { return alpha_level; }

    void attach(EschTexture *t);

    esch_error_codes create(XFBitmap *bm, Flx16 w, Flx16 h);
};

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//��� End of header - esbasic.hpp ���

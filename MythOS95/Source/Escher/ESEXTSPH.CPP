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
// esextsph.cpp
//
// EschSphereExtents is the container type for spherical extents.
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//                                
//���������������������������������������������������������������������������

#include "escher.hpp"

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//�����������������������������  Operations  ��������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschSphereExtents - draw                                                 �
//                                                                          �
// Draws the spherical extents of the object.                               �
//���������������������������������������������������������������������������
void EschSphereExtents::draw(const EschFrameRef *fr, dword clr) const
{
    EschCamera          *cam;
    EschPoint           p;
    EschFrameRef        frame(0);

//��� Setup local pointers to current camera and Van Gogh viewport.
    assertMyth("EschSphereExtents::draw needs camera in current context",
               EschCurrent != NULL && EschCurrent->camera != NULL);

    cam=EschCurrent->camera;

    assertMyth("EschSphereExtents::draw needs a viewport in current context's camera",
               cam->vport != NULL);

//��� Create local->world->eye transform (ignore inverse)
    if (fr)
        fr->orient.concat(&cam->eye.iorient,&frame.orient);
    else
        frame.orient = cam->eye.iorient;

//��� Setup for compare
    Flx16 yon = cam->yon;
    Flx16 hither = cam->hither;
    
//��� Transform center into view
    center.transform(&frame,&p);

//��� Scale radius
    Flx16 r = flx_16mul16( radius, 
              flx_16mul16( fr->scalef, 
                           cam->radius_factor ) );

    assertMyth("EschSphereExtents::draw scaled to a negative radius",
               r.flx >= 0);

//��� Check for fully invisible against hither/yon
    if ( (p.z.flx < hither.flx)
         || (p.z.flx > yon.flx)
         || ((p.z.flx + r.flx) < hither.flx)
         || ((p.z.flx - r.flx) > yon.flx) )
        return;

//��� Draw radial extent
    long x = (flx_muldiv(p.x, cam->xscalar, p.z).flx
             + (cam->vport->get_vbuff()->width<<15)) >> 16;
    long y = ((cam->vport->get_vbuff()->height<<15)
             - flx_muldiv(p.y, cam->yscalar, p.z).flx) >> 16;
    long rd = ((flx_muldiv(p.x + r, cam->xscalar, p.z).flx
               + (cam->vport->get_vbuff()->width<<15)) >> 16) - x;

    vngo_clip_circle(cam->vport,x,y,rd,clr);
}


//�������������������������������������������������������������������������Ŀ
// EschSphereExtents - hit                                                  �
//                                                                          �
// Performs an intersection test input in the same coordinate system of the �
// extents.                                                                 �
//���������������������������������������������������������������������������
int EschSphereExtents::hit(const EschPoint *pt) const
{
    assertMyth("EschSphereExtents::hit needs point",
               pt != 0);

    EschVector  p(pt->x - center.x,
                  pt->y - center.y,
                  pt->z - center.z);

//��� Check for trivial reject
    Flx16 r = radius;
    Flx16 nr = - r;

    if (p.i.flx > r.flx
        || p.i.flx < nr.flx
        || p.k.flx > r.flx
        || p.k.flx < nr.flx
        || p.j.flx > r.flx
        || p.j.flx < nr.flx)
        return 0;

//��� Check with true magnitude
    return  (((p.magnitude()).flx < r.flx) ? 1 : 0);
}

int EschSphereExtents::hit(const EschPoint *pt, const Flx16 r) const
{
    assertMyth("EschSphereExtents::hit needs point and radius",
               pt != 0 && r >= 0);

    EschVector  p(pt->x - center.x,
                  pt->y - center.y,
                  pt->z - center.z);

//��� Check for trivial reject
    Flx16 rs = radius + r;
    Flx16 nrs = - rs;

    if (p.i.flx > rs.flx
        || p.i.flx < nrs.flx
        || p.k.flx > rs.flx
        || p.k.flx < nrs.flx
        || p.j.flx > rs.flx
        || p.j.flx < nrs.flx)
        return 0;

//��� Check with true magnitude
    return  (( (p.magnitude()).flx < rs.flx )
             ? 1 : 0);
}

//��� End of module - esextsph.cpp ���

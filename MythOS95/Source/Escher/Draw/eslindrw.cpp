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
// eslindrw.cpp
//
// Contains the code for the EschLineDraw class which is a colored line
// in 3-space.  The line is not lit.
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
//                                 Data
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//�����������������������������  Operations  ��������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschLineDraw - draw                                                      �
//                                                                          �
// Draws the given point using the current drawing context.                 �
//���������������������������������������������������������������������������
void EschLineDraw::draw()
{
    EschCamera          *cam;
    EschPoint           pnt[2];
    VngoPoint           vpt[2];

//��� Setup local pointers to current camera and Van Gogh viewport.
    assertMyth("EschLineDraw::draw needs camera in current context",
               EschCurrent != NULL && EschCurrent->camera != NULL);

    cam=EschCurrent->camera;

    assertMyth("EschLineDraw::draw needs a viewport in current context's camera",
               cam->vport != NULL);

//��� Transform into copy of point
    pos1.transform(&cam->eye.iorient,pnt);
    pos2.transform(&cam->eye.iorient,&pnt[1]);

//��� Clip against view volume

    // Near/far clipping
    if (pnt[0].z.flx > cam->yon.flx
        || pnt[1].z.flx > cam->yon.flx)
        return;

    if (pnt[0].z.flx < cam->hither.flx
        || pnt[1].z.flx < cam->hither.flx)
        return;

    // Left/right/top/bottom plane clipping
    Flx16 zx1 = flx_16mul16(pnt[0].z,cam->xsize);
    Flx16 zx2 = flx_16mul16(pnt[1].z,cam->xsize);

    Flx16 zy1 = flx_16mul16(pnt[0].z,cam->ysize);
    Flx16 zy2 = flx_16mul16(pnt[1].z,cam->ysize);

    if (pnt[0].x.flx < -zx1.flx
        && pnt[1].x.flx < -zx2.flx)
        return;

    if (pnt[0].x.flx > zx1.flx
        && pnt[1].x.flx > zx2.flx)
        return;

    if (pnt[0].y.flx < -zy1.flx
        && pnt[1].y.flx < -zy2.flx)
        return;

    if (pnt[0].y.flx > zy1.flx
        && pnt[1].y.flx > zy2.flx)
        return;

    flags |= ESCH_DRW_VISIBLE;

//��� Project 
    VngoVport *vport = cam->vport;

    assertMyth("EschLineDraw::draw needs palette in viewport",
               vport->vbuff.pal != 0);

    int mp = vport->vbuff.pal->shd_pal->mid_point;

    for(int i=0; i < 2; i++)
    {
        vpt[i].x = (flx_muldiv(pnt[i].x, cam->xscalar,
                               pnt[i].z).flx
                               + (cam->vport->vbuff.width<<15)) >> 16;
        vpt[i].y = ((cam->vport->vbuff.height<<15)
                     - flx_muldiv(pnt[i].y,
                                  cam->yscalar,
                                  pnt[i].z).flx) >> 16;
        vpt[i].z = flx_16mul16(pnt[i].z,cam->z_factor).flx << 1;
        vpt[i].clr = color;
        vpt[i].shade = mp;
    }

//��� Draw line
    vport->clip_line(vpt, &vpt[1]);
}

//��� End of module - eslindrw.cpp ���

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
    if (pnt[0].z > cam->yon
        || pnt[1].z > cam->yon)
        return;

    if (pnt[0].z < cam->hither
        || pnt[1].z < cam->hither)
        return;

    // Left/right/top/bottom plane clipping
    float zx1 = pnt[0].z * cam->xsize;
    float zx2 = pnt[1].z * cam->xsize;

    float zy1 = pnt[0].z * cam->ysize;
    float zy2 = pnt[1].z * cam->ysize;

    if (pnt[0].x < -zx1
        && pnt[1].x < -zx2)
        return;

    if (pnt[0].x > zx1
        && pnt[1].x > zx2)
        return;

    if (pnt[0].y < -zy1
        && pnt[1].y < -zy2)
        return;

    if (pnt[0].y > zy1
        && pnt[1].y > zy2)
        return;

    flags |= ESCH_DRW_VISIBLE;

//��� Project 
    VngoVport *vport = cam->vport;

    assertMyth("EschLineDraw::draw needs palette in viewport",
               vport->vbuff.pal != 0);

    int mp = vport->vbuff.pal->shd_pal->mid_point;

    for(int i=0; i < 2; i++)
    {
        vpt[i].x = long((pnt[i].x * cam->xscalar) / pnt[i].z)
                   + (cam->vport->vbuff.width >> 1);
        vpt[i].y = (cam->vport->vbuff.height >> 1)
                   - long((pnt[i].y * cam->yscalar) / pnt[i].z);
        vpt[i].z = ulong(pnt[i].z * cam->z_factor);
        vpt[i].clr = color;
        vpt[i].shade = mp;
    }

//��� Draw line
    vport->clip_line(vpt, &vpt[1]);
}

//��� End of module - eslindrw.cpp ���

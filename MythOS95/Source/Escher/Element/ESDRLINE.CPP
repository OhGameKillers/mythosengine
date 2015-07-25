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
// esdrline.cpp
//
// Contains the C++ implementation of the clip/draw function for lines.
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
//                                Equates
//
//���������������������������������������������������������������������������

#define ES_SNAP_VERTS

//���������������������������������������������������������������������������
//
//                                 Data
//
//���������������������������������������������������������������������������

extern VngoPointF EschTempVPointF;

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// esch_clipdraw_line                                                       �
//                                                                          �
// Draws a line using the current object information in the context and the �
// global EschTempVPointF and the passed second point as end-points.        �
//���������������������������������������������������������������������������
extern "C" void esch_clipdraw_line(VngoPointF *vpt2, dword ctrlfl)
{
//��� Setup local pointer to current camera
    assertMyth("esch_clipdraw_point needs camera in current context",
               EschCurrent != 0 && EschCurrent->camera != 0);
    
    EschCamera *cam = EschCurrent->camera;

//��� Perform Clip
    if (ctrlfl & ESCH_CDF_CLIP)
    {

//
// Simple rejection clip for now... needs to do a true 3D line clip.
//

        //��� Near/far clipping
        if (EschTempVPointF.z > cam->yon
            || vpt2->z > cam->yon)
            return;

        if (EschTempVPointF.z < cam->hither
            || vpt2->z < cam->hither)
            return;

        //��� Left/right/top/bottom plane clipping
        float zx1 = EschTempVPointF.z * cam->xsize;
        float zx2 = vpt2->z * cam->xsize;

        float zy1 = EschTempVPointF.z * cam->ysize;
        float zy2 = vpt2->z * cam->ysize;

        if (EschTempVPointF.x < -zx1
            && vpt2->x < -zx2)
            return;

        if (EschTempVPointF.x > zx1
            && vpt2->x > zx2)
            return;

        if (EschTempVPointF.y < -zy1
            && vpt2->y < -zy2)
            return;

        if (EschTempVPointF.y > zy1
            && vpt2->y > zy2)
            return;
    }

//��� Project end-points
#ifdef ES_SNAP_VERTS
    long hwidth = cam->vport->vbuff.width >> 1;
    long hheight = cam->vport->vbuff.height >> 1;

    EschTempVPointF.x = float(long((EschTempVPointF.x * cam->xscalar)
                                   / EschTempVPointF.z)
                              + hwidth);
    vpt2->x = float(long((vpt2->x * cam->xscalar) / vpt2->z) + hwidth);

    EschTempVPointF.y = float(hheight
                              - long((EschTempVPointF.y * cam->yscalar)
                                     / EschTempVPointF.z));
    vpt2->y = float(hheight - long((vpt2->y * cam->yscalar) / vpt2->z));
#else
    float hwidth = float(cam->vport->vbuff.width >> 1);
    float hheight = float(cam->vport->vbuff.height >> 1);

    EschTempVPointF.x = ((EschTempVPointF.x * cam->xscalar)
                         / EschTempVPointF.z) + hwidth;
    vpt2->x = ((vpt2->x * cam->xscalar) / vpt2->z) + hwidth;

    EschTempVPointF.y = hheight - ((EschTempVPointF.y * cam->yscalar)
                                   / EschTempVPointF.z);
    vpt2->y = hheight - ((vpt2->y * cam->yscalar) / vpt2->z);
#endif

    EschTempVPointF.z = (ctrlfl & ESCH_CDF_INFINITEZ)
                        ? 0.99998f : (EschTempVPointF.z * cam->z_factor);
    vpt2->z = (ctrlfl & ESCH_CDF_INFINITEZ)
              ? 0.99998f : (vpt2->z * cam->z_factor);

//��� Mark as visible
    assertMyth("esch_clipdraw_point needs valid draw data in context",
               EschCurrent != 0 && EschCurrent->current != 0);
    EschDrawable *current=EschCurrent->current;
    current->flags |= ESCH_DRW_VISIBLE;

//��� Draw line
    if ((ctrlfl & ESCH_CDF_DONTSORT) || !(cam->flags & ESCH_CAM_SORT))
    {
        cam->vport->clip_line(&EschTempVPointF,vpt2);
    }
    else
    {
        assertMyth("esch_clipdraw_line() needs EschSysInstance and sort area",
                   EschSysInstance && EschSysInstance->sspace);

        EschElement *elm = new (EschSysInstance->sspace)
                           EschLineElement(&EschTempVPointF,vpt2);

        assertMyth("esch_clipdraw_line() can't allocate sort area memory",
                   elm != 0);
        if (elm)
            elm->insert();
    }
}

//��� End of module - esdrline.cpp ���

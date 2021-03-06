//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//���������������������������������������������������������������������������
//����������旭旭旭旭旭�旭旭旭旭���旭旭旭旭��旭姻���旭姻旭旭旭旭旭�旭旭旭旭姻�
//���������葦姻������葦姻���葦姻葦姻���葦姻葦姻���葦姻葦姻�������葦姻���葦姻�
//��������碓甥������碓甥�������碓甥�������碓甥���碓甥碓甥�������碓甥���碓甥��
//�������渦臼葦渦��渦臼葦渦臼�渦甥�������渦臼葦渦臼�渦臼葦渦���渦臼葦渦姻����
//������渦甥�������������渦甥渦甥�������渦甥���渦甥渦甥�������渦甥���渦甥����
//�����憶悔������憶悔���憶悔憶悔���憶悔憶悔���憶悔憶悔�������憶悔���憶悔�����
//����臆臆臆臆臆�臆臆臆臆���臆臆臆臆��臆悔���臆悔臆臆臆臆臆�臆悔���臆悔������
//���������������������������������������������������������������������������
//����������������� Microsoft Windows 95/98/NT Version ����������������������
//���������������������������������������������������������������������������
//���Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn���
//���������������������������������������������������������������������������
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
// Created by Tim Little & Chuck Walbourn
//
// esdrline.cpp
//
// Contains the C++ implementation of the clip/draw function for lines.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include "escher.hpp"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#define ES_SNAP_VERTS

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

extern VngoPointF EschTempVPointF;

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// esch_clipdraw_line                                                       �
//                                                                          �
// Draws a line using the current object information in the context and the �
// global EschTempVPointF and the passed second point as end-points.        �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
extern "C" void esch_clipdraw_line(VngoPointF *vpt2, dword ctrlfl)
{
    EschCamera  *cam;
    dword       cflags;

//陳� Setup local pointer to current camera
    assertMyth("esch_clipdraw_point needs camera in current context",
               EschCurrent != 0 && EschCurrent->camera != 0);

    cam = EschCurrent->camera;

    cflags = cam->flags;

//陳� Perform Clip
    if (ctrlfl & ESCH_CDF_CLIP)
    {
#if 1
        ulong count = 2;

        static VngoPointF3  vpoly[2];
        static VngoPointF3  tvpoly[2];

        tvpoly[0].wx = EschTempVPointF.x;
        tvpoly[0].wy = EschTempVPointF.y;
        tvpoly[0].wz = EschTempVPointF.z;
        tvpoly[0].x = EschTempVPointF.x;
        tvpoly[0].y = EschTempVPointF.y;
        tvpoly[0].z = EschTempVPointF.z;
        tvpoly[0].shade  = long(EschTempVPointF.shade);

        tvpoly[1].wx = vpt2->x;
        tvpoly[1].wy = vpt2->y;
        tvpoly[1].wz = vpt2->z;
        tvpoly[1].x = vpt2->x;
        tvpoly[1].y = vpt2->y;
        tvpoly[1].z = vpt2->z;
        tvpoly[1].shade  = long(vpt2->shade);

        int cstate = esch_clip_to_frustrum(&count, tvpoly, vpoly,
                                           cam,
                                           cam->flags
                                           & EschCurrent->current->limits);
        if (cstate == 1)        // Was clipped
        {
            EschTempVPointF.x = vpoly[0].wx;
            EschTempVPointF.y = vpoly[0].wy;
            EschTempVPointF.z = vpoly[0].wz;
            EschTempVPointF.shade = float(vpoly[0].shade);

            vpt2->x = vpoly[1].wx;
            vpt2->y = vpoly[1].wy;
            vpt2->z = vpoly[1].wz;
            vpt2->shade = float(vpoly[1].shade);
        }
        else if (cstate == 0)   // It is fully clipped.
        {
            return;
        }
#endif
    }

//陳� Project end-points
    if (cflags & ESCH_CAM_ORTHO)
    {
#ifdef ES_SNAP_VERTS
        long hwidth = cam->vport->vbuff.width >> 1;
        long hheight = cam->vport->vbuff.height >> 1;

        EschTempVPointF.x = float(long(EschTempVPointF.x * cam->xscalar)
                                  + hwidth);
        vpt2->x = float(long((vpt2->x * cam->xscalar) / vpt2->z) + hwidth);

        EschTempVPointF.y = float(hheight
                                  - long(EschTempVPointF.y * cam->yscalar));
        vpt2->y = float(hheight - long(vpt2->y * cam->yscalar));
#else
        float hwidth = float(cam->vport->vbuff.width >> 1);
        float hheight = float(cam->vport->vbuff.height >> 1);

        EschTempVPointF.x = (EschTempVPointF.x * cam->xscalar) + hwidth;
        vpt2->x = (vpt2->x * cam->xscalar) + hwidth;

        EschTempVPointF.y = hheight - (EschTempVPointF.y * cam->yscalar);
        vpt2->y = hheight - (vpt2->y * cam->yscalar);
#endif

        EschTempVPointF.z = (ctrlfl & ESCH_CDF_INFINITEZ)
                            ? 0.99998f : (EschTempVPointF.z * cam->z_factor);
        vpt2->z = (ctrlfl & ESCH_CDF_INFINITEZ)
                ? 0.99998f : (vpt2->z * cam->z_factor);
    }
    else
    {
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
    }

//陳� Mark as visible
    assertMyth("esch_clipdraw_point needs valid draw data in context",
               EschCurrent != 0 && EschCurrent->current != 0);
    EschDrawable *current=EschCurrent->current;
    current->flags |= ESCH_DRW_VISIBLE;

//陳� Draw line
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

//葦� End of module - esdrline.cpp 憶�


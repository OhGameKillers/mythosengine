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

extern VngoPointF EschTempVPointF;

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
    VngoPointF      vpt2;

//��� Setup local pointers to current camera and Van Gogh viewport.
    assertMyth("EschLineDraw::draw needs camera in current context",
               EschCurrent != NULL && EschCurrent->camera != NULL);

    EschCamera *cam=EschCurrent->camera;

    assertMyth("EschLineDraw::draw needs a viewport in current context's camera",
               cam->vport != NULL);

//��� Setup Context
    EschContext ec(EschCurrent);
    ec.current = this;
    ec.push();

//��� Transform end points
    pos1.transform(&cam->eye.iorient,(EschPoint*)&EschTempVPointF);
    pos2.transform(&cam->eye.iorient,(EschPoint*)&vpt2);

//��� Light (normal shade value)
    float mp = float(cam->vport->vbuff.pal->shd_pal->mid_point);

    EschTempVPointF.clr = color;
    EschTempVPointF.shade = mp;

    vpt2.clr = color;
    vpt2.shade = mp;

//��� Draw line
    esch_clipdraw_line(&vpt2, ESCH_CDF_CLIP);

//��� Cleanup
    ec.pop();
}

//��� End of module - eslindrw.cpp ���

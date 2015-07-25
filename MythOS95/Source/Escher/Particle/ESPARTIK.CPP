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
// espartik.cpp
//
// Contains the code for the EschParticle class which is a colored point
// in 3-space with various control attributes.
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
//�����������������������  Constructors/Destructors  ������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschParticle - Constructor                                               �
//                                                                          �
// Initializes the particle.                                                �
//���������������������������������������������������������������������������
EschParticle::EschParticle(float ix, float iy, float iz,
                           dword c, float l) :
    EschDrawable(ESCH_DRWT_PARTICLE),
    pos(ix,iy,iz),
    color(c),
    life(l),
    velocity(0,0,0),
    acceleration(0,0,0)
{
}

EschParticle::EschParticle(float ix, float iy, float iz,
                           float ii, float ij, float ik,
                           dword c, float l) :
    EschDrawable(ESCH_DRWT_PARTICLE),
    pos(ix,iy,iz),
    color(c),
    life(l),
    velocity(ii,ij,ik),
    acceleration(0,0,0)
{
}

EschParticle::EschParticle(const EschPoint *p,
                           const EschVector *v,
                           dword c, float l) :
    EschDrawable(ESCH_DRWT_PARTICLE),
    pos(p->x,p->y,p->z),
    color(c),
    life(l),
    velocity(v->i,v->j,v->k),
    acceleration(0,0,0)
{
}



//���������������������������������������������������������������������������
//�����������������������������  Operations  ��������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschParticle - draw                                                      �
//                                                                          �
// Draws the given particle using the current drawing context at the        �
// current position.                                                        �
//���������������������������������������������������������������������������
void EschParticle::draw()
{
    EschCamera          *cam;

//��� Setup local pointers to current camera and Van Gogh viewport.
    assertMyth("EschParticle::draw needs camera in current context",
               EschCurrent != NULL && EschCurrent->camera != NULL);

    cam=EschCurrent->camera;

    assertMyth("EschParticle::draw needs a viewport in current context's camera",
               cam->vport != NULL);

//��� Setup Context
    EschContext ec(EschCurrent);
    ec.current = this;
    ec.push();

//��� Transform into copy of point
    pos.transform(&cam->eye.iorient,(EschPoint*)&EschTempVPointF);

//��� Light (normal shade value)
    assertMyth("EschPointDraw::draw needs palette in viewport",
               cam->vport->vbuff.pal != 0);

    EschTempVPointF.clr = color;
    EschTempVPointF.shade = float(cam->vport->vbuff.pal->shd_pal->mid_point);

//��� Draw
    esch_clipdraw_point(ESCH_CDF_CLIP);

//��� Cleanup
    ec.pop();
}


//�������������������������������������������������������������������������Ŀ
// EschParticle - animate                                                   �
//                                                                          �
// Performs any operations needed to move the particle to the next frame,   �
// including life tests for death of the particle.                          �
//���������������������������������������������������������������������������
void EschParticle::animate()
{
//�� Perform life test, if not unlimited
    if (life > 0)
    {
        if (flags & ESCH_PRT_TIMEBASED)
            life -= interval;
        else
            life -= 1.0f;

        if (life <= 0)
            flags |= ESCH_DRW_SKIP;
    }

//�� Compute next position (if we have a valid time interval)
    if (interval == 0)
        return;

//�� Calculate the new velocity (based on acceleration)
    velocity.i += acceleration.i * interval;
    velocity.j += acceleration.j * interval;
    velocity.k += acceleration.k * interval;

//�� Calculate the new position (based on velocity)
    pos.x += velocity.i * interval;
    pos.y += velocity.j * interval;
    pos.z += velocity.k * interval;
}

//��� End of module - espartik.cpp ���

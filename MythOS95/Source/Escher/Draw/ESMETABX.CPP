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
// esmetabx.cpp
//
// Contains the code for the EschMetabox class.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include "escher.hpp"

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭�  Constructors/Destructors  碓旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschMetabox - Constructor                                                �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschMetabox::EschMetabox() :
    EschDrawable(ESCH_DRWT_METABOX),
    alpha_level(255)
{
    check_workspace();
    for(int i=0; i < (sizeof(txt) / sizeof(EschTexture*)); i++)
        txt[i];

    u[0] = float(0.01);
    u[1] = float(0.90);
    u[2] = float(0.01);
    u[3] = float(0.90);

    v[0] = float(0.01);
    v[1] = float(0.01);
    v[2] = float(0.90);
    v[3] = float(0.90);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschMetabox - Destructor                                                 �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschMetabox::~EschMetabox()
{
    release();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//                          旭� Protected 旭�                               �
// EschMetabox - check_workspace                                            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschMetabox::check_workspace()
{
    assertMyth("EschMetabox needs Escher initialized",EschSysInstance != 0);

    //陳 Update wspace_mbytes diags
    dword needed = (sizeof(VngoPoint)+sizeof(dword)+(sizeof(EschVertex)))*8;

    assertMyth("EschMetabox needs more workspace than is available",
               needed <= EschSysInstance->wspace_sbytes);

    if (needed > EschSysInstance->wspace_mbytes)
        EschSysInstance->wspace_mbytes = needed;
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  Operations  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschMetabox - operator =                                                 �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
const EschMetabox &EschMetabox::operator = (const EschMetabox &that)
{
    if (this != &that)
    {
        release();

        EschDrawable::operator = (that);

        world = that.world;
        memcpy(corner,that.corner,sizeof(corner));
        memcpy(color,that.color,sizeof(color));
        memcpy(txt,that.txt,sizeof(txt));
        memcpy(u,that.u,sizeof(u));
        memcpy(v,that.v,sizeof(v));
    }
    return *this;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschMetabox - draw                                                       �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschMetabox::draw()
{
    ulong           i;
    dword           cflags;
    dword           level;
    dword           *vflags;
    VngoPoint       *vpt;
    EschCamera      *cam;
    EschFace        face;
    EschFrameRef    frame(0);

//陳� Clear arena
    ivory_arena_clear(EschSysInstance->wspace);

//陳� Setup local pointers to current camera and Van Gogh viewport.
    assertMyth("EschMetabox::draw needs camera in current context",
               EschCurrent != NULL && EschCurrent->camera != NULL);

    cam=EschCurrent->camera;

    assertMyth("EschMetabox::draw needs a viewport in current context's camera",
               cam->vport != NULL);

    cflags = cam->flags;
    level = cflags & limits;

    assertMyth("EschMetabox::draw needs a palette in current context's camera",
               cam->vport->vbuff.pal != NULL);

    int mp = cam->vport->vbuff.pal->shd_pal->mid_point;

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Setup Context
    EschContext ec(EschCurrent);
    ec.current = this;
    ec.verts = new (EschSysInstance->wspace) EschVertex[8];
    ec.vflags = vflags = (dword*)ivory_arena_zalloc(EschSysInstance->wspace,sizeof(dword) * 8);
    ec.vpoints = vpt = new (EschSysInstance->wspace) VngoPoint[8];
    ec.faces = &face;
    ec.fflags = 0;
    ec.txts = txt;
    ec.push();

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Misc Setup
    //陳� Create local->world->eye transform
    world.orient.concat(&cam->eye.iorient,&frame.orient);
    cam->eye.orient.concat(&world.iorient,&frame.iorient);

    face.flags = (limits & (ESCH_FACE_WIRE
                            | ESCH_FACE_SOLID
                            | ESCH_FACE_ONESIDED
                            | ESCH_FACE_ALLOWPERSP))
                 | ESCH_FACE_ABLINE
                 | ESCH_FACE_BCLINE
                 | ESCH_FACE_CALINE;

    if ((limits & ESCH_FACE_ALPHA) && alpha_level < 255)
    {
        face.flags |= ESCH_FACE_ALPHA;
        face.set_alpha(alpha_level);
    }

    dword ctrlfl = ESCH_CDF_CLIP | ((cam->flags & face.flags & ESCH_FACE_ONESIDED)
                                    ? ESCH_CDF_BFCULL : 0);

//陳� Transform and light (if possible) the verticies
    for(i=0; i < 8; i++)
    {
        ec.verts[i].x = corner[i].x;
        ec.verts[i].y = corner[i].y;
        ec.verts[i].z = corner[i].z;

        ec.verts[i].transform(&frame,(EschPoint*)(&vpt[i]));
        vpt[i].shade=mp;
    }

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Setup/Draw Faces
    if (flags & ESCH_MBOX_TOP)
    {
        if ((limits & ESCH_FACE_TEXTURED) && txt[ESCH_MBOX_FACE_TOP])
            face.flags |= ESCH_FACE_TEXTURED;
        else
            face.flags &= ~ESCH_FACE_TEXTURED;

        face.txt   = 1;

        face.a     = 0;
        face.u[0]  = u[0];
        face.v[0]  = v[0];
        face.b     = 3;
        face.u[1]  = u[1];
        face.v[1]  = v[1];
        face.c     = 1;
        face.u[2]  = u[2];
        face.v[2]  = v[2];

        vpt[face.a].clr = color[ESCH_MBOX_FACE_TOP];
        esch_clipdraw_face(0,ctrlfl);

        face.a     = 3;
        face.u[0]  = u[1];
        face.v[0]  = v[1];
        face.b     = 2;
        face.u[1]  = u[3];
        face.v[1]  = v[3];
        face.c     = 1;
        face.u[2]  = u[2];
        face.v[2]  = v[2];

        vpt[face.a].clr = color[ESCH_MBOX_FACE_TOP];
        esch_clipdraw_face(0,ctrlfl);
    }

    if (flags & ESCH_MBOX_BOTTOM)
    {
        if ((limits & ESCH_FACE_TEXTURED) && txt[ESCH_MBOX_FACE_BOTTOM])
            face.flags |= ESCH_FACE_TEXTURED;
        else
            face.flags &= ~ESCH_FACE_TEXTURED;

        face.txt   = 2;

        face.a     = 5;
        face.u[0]  = u[0];
        face.v[0]  = v[0];
        face.b     = 6;
        face.u[1]  = u[1];
        face.v[1]  = v[1];
        face.c     = 4;
        face.u[2]  = u[2];
        face.v[2]  = v[2];

        vpt[face.a].clr = color[ESCH_MBOX_FACE_BOTTOM];
        esch_clipdraw_face(0,ctrlfl);

        face.a     = 6;
        face.u[0]  = u[1];
        face.v[0]  = v[1];
        face.b     = 7;
        face.u[1]  = u[3];
        face.v[1]  = v[3];
        face.c     = 4;
        face.u[2]  = u[2];
        face.v[2]  = v[2];

        vpt[face.a].clr = color[ESCH_MBOX_FACE_BOTTOM];
        esch_clipdraw_face(0,ctrlfl);
    }

    if (flags & ESCH_MBOX_FRONT)
    {
        if ((limits & ESCH_FACE_TEXTURED) && txt[ESCH_MBOX_FACE_FRONT])
            face.flags |= ESCH_FACE_TEXTURED;
        else
            face.flags &= ~ESCH_FACE_TEXTURED;

        face.txt   = 3;

        face.a     = 0;
        face.u[0]  = u[0];
        face.v[0]  = v[0];
        face.b     = 1;
        face.u[1]  = u[1];
        face.v[1]  = v[1];
        face.c     = 4;
        face.u[2]  = u[2];
        face.v[2]  = v[2];

        vpt[face.a].clr = color[ESCH_MBOX_FACE_FRONT];
        esch_clipdraw_face(0,ctrlfl);

        face.a     = 1;
        face.u[0]  = u[1];
        face.v[0]  = v[1];
        face.b     = 5;
        face.u[1]  = u[3];
        face.v[1]  = v[3];
        face.c     = 4;
        face.u[2]  = u[2];
        face.v[2]  = v[2];

        vpt[face.a].clr = color[ESCH_MBOX_FACE_FRONT];
        esch_clipdraw_face(0,ctrlfl);
    }

    if (flags & ESCH_MBOX_BACK)
    {
        if ((limits & ESCH_FACE_TEXTURED) && txt[ESCH_MBOX_FACE_BACK])
            face.flags |= ESCH_FACE_TEXTURED;
        else
            face.flags &= ~ESCH_FACE_TEXTURED;

        face.txt   = 4;

        face.a     = 2;
        face.u[0]  = u[0];
        face.v[0]  = v[0];
        face.b     = 3;
        face.u[1]  = u[1];
        face.v[1]  = v[1];
        face.c     = 6;
        face.u[2]  = u[2];
        face.v[2]  = v[2];

        vpt[face.a].clr = color[ESCH_MBOX_FACE_BACK];
        esch_clipdraw_face(0,ctrlfl);

        face.a     = 3;
        face.u[0]  = u[1];
        face.v[0]  = v[1];
        face.b     = 7;
        face.u[1]  = u[3];
        face.v[1]  = v[3];
        face.c     = 6;
        face.u[2]  = u[2];
        face.v[2]  = v[2];

        vpt[face.a].clr = color[ESCH_MBOX_FACE_BACK];
        esch_clipdraw_face(0,ctrlfl);
    }

    if (flags & ESCH_MBOX_LEFT)
    {
        if ((limits & ESCH_FACE_TEXTURED) && txt[ESCH_MBOX_FACE_LEFT])
            face.flags |= ESCH_FACE_TEXTURED;
        else
            face.flags &= ~ESCH_FACE_TEXTURED;

        face.txt   = 5;

        face.a     = 3;
        face.u[0]  = u[0];
        face.v[0]  = v[0];
        face.b     = 0;
        face.u[1]  = u[1];
        face.v[1]  = v[1];
        face.c     = 7;
        face.u[2]  = u[2];
        face.v[2]  = v[2];

        vpt[face.a].clr = color[ESCH_MBOX_FACE_LEFT];
        esch_clipdraw_face(0,ctrlfl);

        face.a     = 0;
        face.u[0]  = u[1];
        face.v[0]  = v[1];
        face.b     = 4;
        face.u[1]  = u[3];
        face.v[1]  = v[3];
        face.c     = 7;
        face.u[2]  = u[2];
        face.v[2]  = v[2];

        vpt[face.a].clr = color[ESCH_MBOX_FACE_LEFT];
        esch_clipdraw_face(0,ctrlfl);
    }

    if (flags & ESCH_MBOX_RIGHT)
    {
        if ((limits & ESCH_FACE_TEXTURED) && txt[ESCH_MBOX_FACE_RIGHT])
            face.flags |= ESCH_FACE_TEXTURED;
        else
            face.flags &= ~ESCH_FACE_TEXTURED;

        face.txt   = 6;

        face.a     = 1;
        face.u[0]  = u[0];
        face.v[0]  = v[0];
        face.b     = 2;
        face.u[1]  = u[1];
        face.v[1]  = v[1];
        face.c     = 5;
        face.u[2]  = u[2];
        face.v[2]  = v[2];

        vpt[face.a].clr = color[ESCH_MBOX_FACE_RIGHT];
        esch_clipdraw_face(0,ctrlfl);

        face.a     = 2;
        face.u[0]  = u[1];
        face.v[0]  = v[1];
        face.b     = 6;
        face.u[1]  = u[3];
        face.v[1]  = v[3];
        face.c     = 5;
        face.u[2]  = u[2];
        face.v[2]  = v[2];

        vpt[face.a].clr = color[ESCH_MBOX_FACE_RIGHT];
        esch_clipdraw_face(0,ctrlfl);
    }

//陳� Pop drawing context
    ec.pop();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschMetabox - animate                                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschMetabox::animate()
{
    for(int i=0; i < 6; i++)
    {
        if (txt[i] && !(txt[i]->flags & ESCH_TXT_SKIPANIMATE))
            txt[i]->animate();
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschMetabox - release                                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschMetabox::release()
{
    for(int i=0; i < (sizeof(txt) / sizeof(EschTexture*)); i++)
    {
        if (!txt[i])
            continue;

        if (flags & ESCH_DRW_OWNSDATA)
            delete txt[i];

        txt[i]=0;
    }
    flags &= ~ESCH_DRW_OWNSDATA;
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭�  Utility Routines  碓旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschMetabox - set_color                                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschMetabox::set_color(dword clr, int face)
{
    if (face > 5)
        return;

    if (face >= 0)
    {
        color[face] = clr;
    }
    else
    {
        for(int i=0; i < 6; i++)
            color[i] = clr;
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschMetabox - set_texture                                                �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschMetabox::set_texture(EschTexture *t, int face)
{
    if (face > 5)
        return;

    if (face >= 0)
    {
        txt[face] = t;
    }
    else
    {
        for(int i=0; i < 6; i++)
        {
            txt[i] = t;
        }
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschMetabox - create_cube                                                �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschMetabox::create_cube(float size)
{
    flags |= ESCH_MBOX_TOP
             | ESCH_MBOX_BOTTOM
             | ESCH_MBOX_FRONT
             | ESCH_MBOX_BACK
             | ESCH_MBOX_LEFT
             | ESCH_MBOX_RIGHT;

    float s = size / 2;

    corner[0].x = -s;
    corner[0].y = s;
    corner[0].z = -s;

    corner[1].x = s;
    corner[1].y = s;
    corner[1].z = -s;

    corner[2].x = s;
    corner[2].y = s;
    corner[2].z = s;

    corner[3].x = -s;
    corner[3].y = s;
    corner[3].z = s;

    corner[4].x = -s;
    corner[4].y = -s;
    corner[4].z = -s;

    corner[5].x = s;
    corner[5].y = -s;
    corner[5].z = -s;

    corner[6].x = s;
    corner[6].y = -s;
    corner[6].z = s;

    corner[7].x = -s;
    corner[7].y = -s;
    corner[7].z = s;
}

//葦� End of module - esmetabx.cpp 憶�


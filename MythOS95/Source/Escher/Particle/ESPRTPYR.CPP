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
// esprtpyr.cpp
//
// Contains the code for the EschParticlePyramid class which is a
// colored polygonal pyramid in 3-space with various control attributes.
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
// EschParticlePyramid - Constructor                                        �
//                                                                          �
// Initializes the particle.                                                �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschParticlePyramid::EschParticlePyramid(float s, float ix, float iy, float iz,
                           dword c, float l) :
    EschParticle(ix,iy,iz,c,l),
    size(s),
    rotate_i(0),
    rotate_j(0),
    rotate_k(0),
    alpha(255)
{
    dtyp = ESCH_DRWT_PRTPYRAMID;
    alpha_rate = (l > 0) ? (alpha / l) : 0;
    check_workspace();
}

EschParticlePyramid::EschParticlePyramid(float s, float ix, float iy, float iz,
                           float ii, float ij, float ik,
                           dword c, float l) :
    EschParticle(ix,iy,iz,ii,ij,ik,c,l),
    size(s),
    rotate_i(0),
    rotate_j(0),
    rotate_k(0),
    alpha(255)
{
    dtyp = ESCH_DRWT_PRTPYRAMID;
    alpha_rate = (l > 0) ? (alpha / l) : 0;
    check_workspace();
}

EschParticlePyramid::EschParticlePyramid(float s, const EschPoint *p,
                           const EschVector *v,
                           dword c, float l) :
    EschParticle(p,v,c,l),
    size(s),
    rotate_i(0),
    rotate_j(0),
    rotate_k(0),
    alpha(255)
{
    dtyp = ESCH_DRWT_PRTPYRAMID;
    alpha_rate = (l > 0) ? (alpha / l) : 0;
    check_workspace();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//                          旭� Protected 旭�                               �
// EschParticlePyramid - check_workspace                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschParticlePyramid::check_workspace()
{
    assertMyth("EschPariticlePyramid needs Escher initialized",EschSysInstance != 0);

    //陳 Update wspace_mbytes diags
    dword needed = (sizeof(VngoPoint)+sizeof(dword)+(2*sizeof(EschVertex))
                    +sizeof(EschFace))
                   *4;

    assertMyth("EschParticlePryamid needs more workspace than is available",
               needed <= EschSysInstance->wspace_sbytes);

    if (needed > EschSysInstance->wspace_mbytes)
        EschSysInstance->wspace_mbytes = needed;
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  Operations  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschParticlePyramid - draw                                               �
//                                                                          �
// Draws the given particle using the current drawing context at the        �
// current position.                                                        �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschParticlePyramid::draw()
{
    int             i;
    dword           ctrlfl;
    dword           *vflags;
    VngoPoint       *vpt;
    EschFace        *face;
    EschVertex      *vn;
    EschCamera      *cam;
    EschLight       *lights;
    EschPoint       p;
    EschPoint       eyep(0,0,0);
    EschFrameRef    frame(0);

    assertMyth("EschParticlePyramid::draw needs valid size", size > 0);

//陳� Setup local pointers to current camera and Van Gogh viewport.
    assertMyth("EschParticlePyramid::draw needs camera in current context",
               EschCurrent != NULL && EschCurrent->camera != NULL);

    cam=EschCurrent->camera;

    assertMyth("EschParticlePyramid::draw needs a viewport in current context's camera",
               cam->vport != NULL);

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Perform radial extents check
    // Transform center into view
    p.x = 0;  p.y = 0;  p.z = 0;
    p.transform(&world);
    p.transform(&cam->eye.iorient);

    // Scale radius
    float r = size * world.scalef * cam->radius_factor * 1.05f;

    assertMyth("EschParticlePyramid::draw radius scale resulted in negative radius",
               r >= 0);

    // Setup for compare
    float yon = cam->yon;
    float hither = cam->hither;

    // Check for fully invisible against hither/yon
    if ( ((p.z + r) < hither)
         || ((p.z - r) > yon) )
    {
        // Since the extents are inclusive of children, don't
        // need to do anything for children meshes.
        return;
    }

    // If center is positive, then we can check against other planes
    // and for fully visible (will need changing later for more general
    // case)
    if (p.z > 0)
    {
        float tx = p.z * cam->xsize;
        float ty = p.z * cam->ysize;

        // Check for fully invisible against left/right/top/bottom
        if ( ((p.x + r) < -tx)
             || ((p.x - r) > tx)
             || ((p.y + r) < -ty)
             || ((p.y - r) > ty) )
        {
            return;
        }

        // See if fully visible or needs clipping
        ctrlfl = ( ((p.z - r) > hither)
                    && ((p.z + r) < yon)
                    && ((p.x - r) > -tx)
                    && ((p.x + r) < tx)
                    && ((p.y - r) > -ty)
                    && ((p.y + r) < ty) ) ? 0 : ESCH_CDF_CLIP;

    }
    else ctrlfl = ESCH_CDF_CLIP;

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Setup
    dword cflags = cam->flags;
    dword level = cflags & limits;

    assertMyth("EschParticlePyramid::draw needs a palette in current context's camera",
               cam->vport->vbuff.pal != NULL);

    int mp = cam->vport->vbuff.pal->shd_pal->mid_point;

    //陳� Clear arena
    ivory_arena_clear(EschSysInstance->wspace);

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Setup Context
    EschContext ec(EschCurrent);
    ec.current = this;
    ec.verts = new (EschSysInstance->wspace) EschVertex[4];
    ec.vflags = vflags = (dword*)ivory_arena_zalloc(EschSysInstance->wspace,sizeof(dword) * 4);
    ec.vpoints = vpt = new (EschSysInstance->wspace) VngoPoint[4];
    ec.faces = new (EschSysInstance->wspace) EschFace[4];
    ec.fflags = 0;
    ec.txts = 0;
    ec.push();

    //陳� Workspace for shadeing values, if not shading in modelspace.
    if (!(cflags & ESCH_CAM_MODELSPACE)
        && (cflags & (ESCH_CAM_SHADE_SMOOTH|ESCH_CAM_SHADE_SPECULAR)))
    {
        vn = (EschVertex*) new (EschSysInstance->wspace) EschVertex[4];
    }

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Misc Setup
    //陳� Create local->world->eye transform
    world.orient.concat(&cam->eye.iorient,&frame.orient);
    cam->eye.orient.concat(&world.iorient,&frame.iorient);

    //陳� Get camera into object coords if needed for backculling.
    if (cflags & ESCH_CAM_BACKCULL)
    {
        eyep.transform(&frame.iorient);
    }

    //陳� Setup lights, if any
    lights = EschCurrent->lights;
    if (lights)
    {
        lights->setup(&world);
    }

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Setup Pyramid

//陳� Create 4 verticies
//
// (X/Y plane)
//
//      0
//      |
//      |
//      +--*--2
//      | [3]
//      |
//      1
//

    float size_half = size / 2;;

    ec.verts[0].x = -size_half;
    ec.verts[0].y = size_half;
    ec.verts[0].z = -size_half;
    ec.verts[0].normal.i = float(0.440094);
    ec.verts[0].normal.j = float(-0.838745);
    ec.verts[0].normal.k = float(0.321503);

    ec.verts[1].x = -size_half;
    ec.verts[1].y = -size_half;
    ec.verts[1].z = -size_half;
    ec.verts[1].normal.i = float(0.440094);
    ec.verts[1].normal.j = float(0.838745);
    ec.verts[1].normal.k = float(0.321503);

    ec.verts[2].x = size_half;
    ec.verts[2].y = 0;
    ec.verts[2].z = -size_half;
    ec.verts[2].normal.i = float(-0.840271);
    ec.verts[2].normal.j = float(0);
    ec.verts[2].normal.k = float(0.542511);

    ec.verts[3].x = 0;
    ec.verts[3].y = 0;
    ec.verts[3].z = size_half;
    ec.verts[3].normal.i = float(0.024384);
    ec.verts[3].normal.j = float(0);
    ec.verts[3].normal.k = float(-0.999710);

//陳� Create 4 faces
    dword fflags = (limits & (ESCH_FACE_WIRE
                              | ESCH_FACE_SOLID
                              | ESCH_FACE_FLAT
                              | ESCH_FACE_SMOOTH
                              | ESCH_FACE_SPECULAR
                              | ESCH_FACE_ONESIDED))
                   | ESCH_FACE_ABLINE
                   | ESCH_FACE_BCLINE
                   | ESCH_FACE_CALINE;

    if ((limits & ESCH_FACE_ALPHA) && alpha < 255)
    {
        fflags |= ESCH_FACE_ALPHA;
        ec.faces[0].set_alpha((byte)alpha);
        ec.faces[1].set_alpha((byte)alpha);
        ec.faces[2].set_alpha((byte)alpha);
        ec.faces[3].set_alpha((byte)alpha);
    }

    ec.faces[0].color = color;
    ec.faces[0].flags = fflags;
    ec.faces[0].a = 0;
    ec.faces[0].b = 1;
    ec.faces[0].c = 2;
    ec.faces[0].normal.i = float(0);
    ec.faces[0].normal.j = float(0);
    ec.faces[0].normal.k = float(1);

    ec.faces[1].color = color;
    ec.faces[1].flags = fflags;
    ec.faces[1].a = 3;
    ec.faces[1].b = 0;
    ec.faces[1].c = 2;
    ec.faces[1].normal.i = float(-0.436432);
    ec.faces[1].normal.j = float(-0.872864);
    ec.faces[1].normal.k = float(-0.218216);

    ec.faces[2].color = color;
    ec.faces[2].flags = fflags;
    ec.faces[2].a = 3;
    ec.faces[2].b = 2;
    ec.faces[2].c = 1;
    ec.faces[2].normal.i = float(-0.436432);
    ec.faces[2].normal.j = float(0.872864);
    ec.faces[2].normal.k = float(-0.218216);

    ec.faces[3].color = color;
    ec.faces[3].flags = fflags;
    ec.faces[3].a = 3;
    ec.faces[3].b = 1;
    ec.faces[3].c = 0;
    ec.faces[3].normal.i = float(0.894424);
    ec.faces[3].normal.j = float(0);
    ec.faces[3].normal.k = float(-0.447205);

//陳� Transform and light (if possible) the verticies
    for(i=0; i < 4; i++)
    {
        ec.verts[i].transform(&frame,(EschPoint*)(&vpt[i]));
        vpt[i].clr=color;
        vpt[i].shade=mp;

        // Transform vertex to world, if needed, for shading
        if (!(cflags & ESCH_CAM_MODELSPACE)
            && (level & ESCH_CAM_SHADE_SMOOTH))
        {
            ec.verts[i].transform(&world,&vn[i]);
            ec.verts[i].normal.transform(&world,&vn[i].normal);
            if (world.scalef != 1.0)
                vn[i].normal.normalize();
        }

        if (lights)
        {
            //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Smooth/Specular shading
            if (level & (ESCH_CAM_SHADE_SPECULAR|ESCH_CAM_SHADE_SMOOTH))
            {
                vpt[i].shade=0;

                if (level & ESCH_CAM_SHADE_SPECULAR)
                {
                    lights->hishine((cflags & ESCH_CAM_MODELSPACE) ?
                                    &ec.verts[i]
                                    : &vn[i],&vpt[i]);
                }
                else
                {
                    lights->shine((cflags & ESCH_CAM_MODELSPACE) ?
                                    &ec.verts[i]
                                    : &vn[i],&vpt[i]);
                }
            }
        }
    }

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Draw Face Loop
    flags &= ~ESCH_DRW_VISIBLE;
    for(i=0, face=ec.faces; i < 4; i++, face++)
    {
        //陳� Perform backface culling, if allowed, in object space.
        if (level & ESCH_CAM_BACKCULL)
        {
            EschVector fview;
            fview.i = ec.verts[face->a].x - eyep.x;
            fview.j = ec.verts[face->a].y - eyep.y;
            fview.k = ec.verts[face->a].z - eyep.z;

            if ((fview DOT face->normal) > 0)
                continue;
        }

        //陳� Compute shading (only if we couldn't above)
        if (lights)
        {
            if (level & ESCH_CAM_SHADE_FLAT)
            {
                EschVertex  fnormal;

                if (cflags & ESCH_CAM_MODELSPACE)
                {
                    fnormal.x = ec.verts[face->a].x;
                    fnormal.y = ec.verts[face->a].y;
                    fnormal.z = ec.verts[face->a].z;
                    fnormal.normal.i = face->normal.i;
                    fnormal.normal.j = face->normal.j;
                    fnormal.normal.k = face->normal.k;
                }
                else
                {
                    ec.verts[face->a].transform(&world,&fnormal);
                    face->normal.transform(&world,&fnormal.normal);
                }

                vpt[face->a].shade=0;
                lights->shine(&fnormal,&vpt[face->a]);
            }
        }

        //陳� Call clip draw
        esch_clipdraw_face(i,ctrlfl);
    }

//陳� Pop drawing context
    ec.pop();

//陳� Do CULL option...
    if (!(flags & ESCH_DRW_VISIBLE))
    {
        if ((flags & ESCH_PRT_CULLIFOUTOFVIEW)
            && (flags & ESCH_PRT_WASVISIBLE))
        {
            life = 0;
            flags |= ESCH_DRW_SKIP;
        }
    }
    else
        flags |= ESCH_PRT_WASVISIBLE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschParticlePyramid - animate                                            �
//                                                                          �
// Performs any operations needed to move the particle to the next frame,   �
// including life tests for death of the particle.                          �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschParticlePyramid::animate()
{
    EschParticle::animate();

    if (interval == 0)
        return;

    if (rotate_i != 0)
        world.pitch(rotate_i * interval,0);

    if (rotate_j != 0)
        world.yaw(rotate_j * interval,0);

    if (rotate_k != 0)
        world.roll(rotate_k * interval,0);

    world.set_position(pos.x, pos.y, pos.z);

    if (limits & ESCH_FACE_ALPHA)
    {
        if (flags & ESCH_PRT_TIMEBASED)
            alpha -= alpha_rate * interval;
        else
            alpha -= alpha_rate;

        if (alpha < 0)
            alpha = 0;
    }
}

//葦� End of module - espartik.cpp 憶�


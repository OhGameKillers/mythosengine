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
// esbldmsh.cpp
//
// The EschBuildMesh class provides a method for creating polygonal
// meshes manually.  The class can write a data file for later use.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <float.h>

#include "escher.hpp"
#include "esfile.hpp"

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

extern char EschNoName[];

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭�  Constructors/Destructors  碓旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschBuildMesh - Constructor                                              �
//                                                                          �
// Intializes the instance                                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschBuildMesh::EschBuildMesh() :
    mflags(0),
    fflags(ESCH_FACE_ABLINE
           | ESCH_FACE_BCLINE
           | ESCH_FACE_CALINE
           | ESCH_FACE_WIRE
           | ESCH_FACE_SOLID
           | ESCH_FACE_ALLOWPERSP
           | ESCH_FACE_ONESIDED
           | ESCH_FACE_SPECULAR
           | ESCH_FACE_SMOOTH
           | ESCH_FACE_FLAT),
    selfi(0),
    alpha_a(255),
    alpha_b(255),
    alpha_c(255),
    v(0),
    f(0),
    txt(0)
{
    strcpy(name,EschNoName);
}

EschBuildMesh::EschBuildMesh(ulong mv, ulong mf, ulong mt) :
    mflags(0),
    fflags(ESCH_FACE_ABLINE
           | ESCH_FACE_BCLINE
           | ESCH_FACE_CALINE
           | ESCH_FACE_WIRE
           | ESCH_FACE_SOLID
           | ESCH_FACE_ALLOWPERSP
           | ESCH_FACE_ONESIDED
           | ESCH_FACE_SPECULAR
           | ESCH_FACE_SMOOTH
           | ESCH_FACE_FLAT),
    selfi(0),
    alpha_a(255),
    alpha_b(255),
    alpha_c(255),
    v(0),
    f(0),
    txt(0)
{
    strcpy(name,EschNoName);

    init(mv,mf,mt);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschBuildMesh - Destructor                                               �
//                                                                          �
// Ensures data is released.                                                �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschBuildMesh::~EschBuildMesh()
{
    release();
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  Operations  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschBuildMesh - init                                                     �
//                                                                          �
// Initializes the instance, creating needed memory pools.                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
esch_error_codes EschBuildMesh::init(ulong mv, ulong mf, ulong mt)
{
    if (!mv || !mf)
        return ESCH_ERR_INVALIDPARMS;

    release();

//陳� Verticies
    nverts = 0;
    maxverts = mv;
    v = new EschVertex[mv];
    if (!v)
        return ESCH_ERR_NOMEMORY;

//陳� Faces
    nfaces = 0;
    maxfaces = mf;
    f = new EschFace[mf];
    if (!f)
        return ESCH_ERR_NOMEMORY;

//陳� Textures
    ntxts = 0;
    maxtxts = mt;
    if (mt > 0)
    {
        txt = new EschBuildTexture *[mt];
        if (!txt)
            return ESCH_ERR_NOMEMORY;
    }

    return ESCH_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschBuildMesh - release                                                  �
//                                                                          �
// Frees all used memory.                                                   �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschBuildMesh::release(int freetxts)
{
    if (v)
    {
        delete [] v;
        v=0;
    }
    if (f)
    {
        delete [] f;
        f=0;
    }
    if (txt)
    {
        for(ulong i=0; i < ntxts; i++)
        {
            if (freetxts && txt[i])
                delete txt[i];
        }
        delete [] txt;
        txt=0;
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschBuildMesh - save                                                     �
//                                                                          �
// Saves data to a data file base on data in builder.                       �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
esch_error_codes EschBuildMesh::save(const char *fname, dword ctrlfl,
                                     dword tcfl, VngoPal *pal)
{
    XFParseIFF  iff;

    if (iff.create(fname,0))
    {
        return ESCH_ERR_FILEERROR;
    }

    esch_error_codes err = save(&iff,ctrlfl,tcfl,pal);
    if (err)
        return err;

    iff.close();

    return ESCH_ERR_NONE;
}

esch_error_codes EschBuildMesh::save(XFParseIFF *iff, dword ctrlfl,
                                     dword tcfl, VngoPal *pal)
{
    if (!v || !f || !nverts || !nfaces)
        return ESCH_ERR_MISSINGDATA;

    if (ctrlfl & ESCH_MBLD_INSCENE)
    {
        if (iff->newform(iff->makeid('E','S','E','N')))
            return ESCH_ERR_FILEERROR;

        EschFileSceneHDR    header;
        memset(&header,0,sizeof(header));
        strncpy(header.name,name,sizeof(header.name));
        header.nobjects = 1;

        if (iff->write(iff->makeid('H','D','R',' '),
                       &header,sizeof(header)))
            return ESCH_ERR_FILEERROR;
    }

//陳� Create form
    if (iff->newform(iff->makeid('E','M','S','H')))
        return ESCH_ERR_FILEERROR;

//陳� Write header
    {
        EschFileMeshHDR     header;
        memset(&header,0,sizeof(header));

        strncpy(header.name,name,sizeof(header.name));
        header.flags = mflags;
        header.nverts = nverts;
        header.nfaces = nfaces;

        if (iff->write(iff->makeid('H','D','R',' '),
                       &header,sizeof(header)))
            return ESCH_ERR_FILEERROR;
    }

//陳� Write matrix
    if (ctrlfl & ESCH_MBLD_MATRIX)
    {
        if (ctrlfl & ESCH_MBLD_FIXED)
        {
            EschMatrixV1    v1;

            for(int i=0; i < ESCH_MTX_NUM; i++)
                v1.mtx[i] = long(orient.orient.mtx[i] * 65536.0f);

            if (iff->write(iff->makeid('M','T','R','X'),
                           &v1,sizeof(v1)))
                return ESCH_ERR_FILEERROR;
        }
        else
        {
            if (iff->write(iff->makeid('M','T','R','1'),
                           &orient.orient.mtx,sizeof(orient.orient.mtx)))
                return ESCH_ERR_FILEERROR;
        }
    }

//陳� Write extents
    if (ctrlfl & ESCH_MBLD_EXTENTS)
    {
        if (ctrlfl & ESCH_MBLD_FIXED)
        {
            EschFileMeshEXNTV1  exts;
            memset(&exts,0,sizeof(exts));

            exts.cenx = long(sphere.center.x * 65536.0f);
            exts.ceny = long(sphere.center.y * 65536.0f);
            exts.cenz = long(sphere.center.z * 65536.0f);
            exts.extent_radius = long(sphere.radius * 65536.0f);
            exts.minx = long(box.mins[0] * 65536.0f);
            exts.miny = long(box.mins[1] * 65536.0f);
            exts.minz = long(box.mins[2] * 65536.0f);
            exts.maxx = long(box.maxs[0] * 65536.0f);
            exts.maxy = long(box.maxs[1] * 65536.0f);
            exts.maxz = long(box.maxs[2] * 65536.0f);

            if (iff->write(iff->makeid('E','X','N','T'),
                           &exts,sizeof(exts)))
                return ESCH_ERR_FILEERROR;
        }
        else
        {
            EschFileMeshEXNT    exts;
            memset(&exts,0,sizeof(exts));

            exts.cenx = sphere.center.x;
            exts.ceny = sphere.center.y;
            exts.cenz = sphere.center.z;
            exts.extent_radius = sphere.radius;
            exts.minx = box.mins[0];
            exts.miny = box.mins[1];
            exts.minz = box.mins[2];
            exts.maxx = box.maxs[0];
            exts.maxy = box.maxs[1];
            exts.maxz = box.maxs[2];

            if (iff->write(iff->makeid('E','X','N','1'),
                           &exts,sizeof(exts)))
                return ESCH_ERR_FILEERROR;
        }
    }

//陳� Write heirarchy

//陳� Write verticies
    if (ctrlfl & ESCH_MBLD_FIXED)
    {
        EschVertexV1 *vtemp = new EschVertexV1[nverts];
        if (!vtemp)
            return ESCH_ERR_NOMEMORY;

        EschVertex *tptr = v;
        EschVertexV1 *tmpptr = vtemp;
        for(ulong i=0; i < nverts; i++, tptr++, tmpptr++)
        {
            tmpptr->x = long(tptr->x * 65536.0f);
            tmpptr->y = long(tptr->y * 65536.0f);
            tmpptr->z = long(tptr->z * 65536.0f);
            tmpptr->normal.i = long(tptr->normal.i * 65536.0f);
            tmpptr->normal.j = long(tptr->normal.j * 65536.0f);
            tmpptr->normal.k = long(tptr->normal.k * 65536.0f);
        }

        if (iff->write(iff->makeid('V','E','R','T'),
                       vtemp,sizeof(EschVertexV1) * nverts))
        {
            delete [] vtemp;
            return ESCH_ERR_FILEERROR;
        }

        delete [] vtemp;
    }
    else
    {
        if (iff->write(iff->makeid('V','E','R','1'),
                       v,sizeof(EschVertex) * nverts))
            return ESCH_ERR_FILEERROR;
    }

//陳� Write material names
    if (txt && ntxts)
    {
        EschFileMeshMTL *mtl = new EschFileMeshMTL[ntxts];
        if (!mtl)
            return ESCH_ERR_NOMEMORY;

        for(ulong i=0; i < ntxts; i++)
        {
            strncpy(mtl[i].name,
                    (txt[i]) ? txt[i]->name : EschNoName, ESCH_MAX_NAME);
        }

        if (iff->write(iff->makeid('M','T','L',' '),
                       mtl,sizeof(EschFileMeshMTL)*ntxts))
        {
            delete mtl;
            return ESCH_ERR_FILEERROR;
        }

        delete mtl;
    }

//陳� Write faces
    if (ctrlfl & ESCH_MBLD_FIXED)
    {
        EschFaceV1 *ftemp = new EschFaceV1[nfaces];
        if (!ftemp)
            return ESCH_ERR_NOMEMORY;

        EschFace *tptr = f;
        EschFaceV1 *tmpptr = ftemp;
        for(ulong i=0; i < nfaces; i++, tptr++, tmpptr++)
        {
            dword flags = tptr->flags;
            if (tptr->self_illum)
                flags |= (tptr->self_illum << 16) & ESCH_FACEV1_SILLUM_MASK;
            if (flags & ESCH_FACE_ALPHA)
                flags |= (tptr->alpha_a << 20) & ESCH_FACEV1_ALPHA_MASK;
            tmpptr->flags = flags;

            tmpptr->a = tptr->a;
            tmpptr->b = tptr->b;
            tmpptr->c = tptr->c;
            tmpptr->txt = tptr->txt;
            tmpptr->u[0] = long(tptr->u[0] * 65536.0f);
            tmpptr->u[1] = long(tptr->u[1] * 65536.0f);
            tmpptr->u[2] = long(tptr->u[2] * 65536.0f);
            tmpptr->v[0] = long(tptr->v[0] * 65536.0f);
            tmpptr->v[1] = long(tptr->v[1] * 65536.0f);
            tmpptr->v[2] = long(tptr->v[2] * 65536.0f);
            tmpptr->color = tptr->color;
            tmpptr->normal.i = long(tptr->normal.i * 65536.0f);
            tmpptr->normal.j = long(tptr->normal.j * 65536.0f);
            tmpptr->normal.k = long(tptr->normal.k * 65536.0f);
        }

        if (iff->write(iff->makeid('F','A','C','E'),
                       ftemp,sizeof(EschFaceV1) * nfaces))
        {
            delete [] ftemp;
            return ESCH_ERR_FILEERROR;
        }

        delete [] ftemp;
    }
    else if (ctrlfl & ESCH_MBLD_OLDFLOAT)
    {
        EschFaceV2 *ftemp = new EschFaceV2[nfaces];
        if (!ftemp)
            return ESCH_ERR_NOMEMORY;

        EschFace *tptr = f;
        EschFaceV2 *tmpptr = ftemp;
        for(ulong i=0; i < nfaces; i++, tptr++, tmpptr++)
        {
            dword flags = tptr->flags;
            if (tptr->self_illum)
                flags |= (tptr->self_illum << 16) & ESCH_FACEV2_SILLUM_MASK;
            if (flags & ESCH_FACE_ALPHA)
                flags |= (tptr->alpha_a << 20) & ESCH_FACEV2_ALPHA_MASK;
            tmpptr->flags = flags;

            tmpptr->a = tptr->a;
            tmpptr->b = tptr->b;
            tmpptr->c = tptr->c;
            tmpptr->txt = tptr->txt;
            tmpptr->u[0] = tptr->u[0];
            tmpptr->u[1] = tptr->u[1];
            tmpptr->u[2] = tptr->u[2];
            tmpptr->v[0] = tptr->v[0];
            tmpptr->v[1] = tptr->v[1];
            tmpptr->v[2] = tptr->v[2];
            tmpptr->color = tptr->color;
            tmpptr->normal.i = tptr->normal.i;
            tmpptr->normal.j = tptr->normal.j;
            tmpptr->normal.k = tptr->normal.k;
        }

        if (iff->write(iff->makeid('F','A','C','1'),
                       ftemp,sizeof(EschFaceV2) * nfaces))
        {
            delete [] ftemp;
            return ESCH_ERR_FILEERROR;
        }

        delete [] ftemp;
    }
    else
    {
        if (iff->write(iff->makeid('F','A','C','2'),
                       f,sizeof(EschFace) * nfaces))
            return ESCH_ERR_FILEERROR;
    }

//陳� Write materials
    if (txt && ntxts)
    {
        for(ulong i=0; i < ntxts; i++)
        {
            if (txt[i])
            {
                esch_error_codes err=txt[i]->save(iff,tcfl,pal);
                if (err)
                    return err;
            }
        }
    }

    iff->leaveform();

    if (ctrlfl & ESCH_MBLD_INSCENE)
        iff->leaveform();

    return ESCH_ERR_NONE;
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭�  Utility Routines  碓旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschBuildMesh - add_vertex                                               �
//                                                                          �
// Addes a new vertex to the mesh.                                          �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
esch_error_codes EschBuildMesh::add_vertex(const EschVertex *vtx)
{
    assertMyth("EschBuildMesh::add_vertex must be called after init",v != 0);

    if (nverts >= maxverts)
        return ESCH_ERR_NOMORE;

    v[nverts++] = *vtx;

    return ESCH_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschBuildMesh - set_vertex                                               �
//                                                                          �
// Changes a vertex for the mesh.                                           �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
esch_error_codes EschBuildMesh::set_vertex(ulong i, const EschVertex *vtx)
{
    assertMyth("EschBuildMesh::set_vertex must be called after init",v != 0);

    if (i >= nverts)
        return ESCH_ERR_INVALIDPARMS;

    v[i] = *vtx;

    return ESCH_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschBuildMesh - add_face                                                 �
//                                                                          �
// Addes a new face to the mesh.                                            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
esch_error_codes EschBuildMesh::add_face(const EschFace *face)
{
    assertMyth("EschBuildMesh::add_face must be called after init",f != 0);

    if (nfaces >= maxfaces)
        return ESCH_ERR_NOMORE;

    if (face->a >= nverts
        || face->b >= nverts
        || face->c >= nverts
        || (face->flags & ESCH_FACE_TEXTURED
            && face->txt >= ntxts))
        return ESCH_ERR_INVALIDPARMS;

    f[nfaces] = *face;
    f[nfaces].app_data = 0;
    if (!(f[nfaces].flags & ESCH_FACE_ALPHA))
    {
        f[nfaces].alpha_a =
        f[nfaces].alpha_b =
        f[nfaces].alpha_c = 255;
    }

    nfaces++;

    return ESCH_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschBuildMesh - set_face                                                 �
//                                                                          �
// Changes a face for the mesh.                                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
esch_error_codes EschBuildMesh::set_face(ulong i, const EschFace *face)
{
    assertMyth("EschBuildMesh::set_face must be called after init",f != 0);

    if (i >= nfaces
        || face->a >= nverts
        || face->b >= nverts
        || face->c >= nverts
        || (face->flags & ESCH_FACE_TEXTURED
            && face->txt >= ntxts))
        return ESCH_ERR_INVALIDPARMS;

    f[i] = *face;
    f[i].app_data = 0;
    if (!(f[i].flags & ESCH_FACE_ALPHA))
    {
        f[i].alpha_a =
        f[i].alpha_b =
        f[i].alpha_c = 255;
    }

    return ESCH_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschBuildMesh - add_texture                                              �
//                                                                          �
// Adds a texture to the mesh.                                              �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
esch_error_codes EschBuildMesh::add_texture(EschBuildTexture *t)
{
    if (!txt || ntxts >= maxtxts)
        return ESCH_ERR_NOMORE;

    if (!t)
        return ESCH_ERR_INVALIDPARMS;

    txt[ntxts++] = t;

    return ESCH_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschBuildMesh - set_texture                                              �
//                                                                          �
// Changes a texture for the mesh.                                          �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
esch_error_codes EschBuildMesh::set_texture(ulong i,
                                            EschBuildTexture *t, int freeold)
{
    if (!t || i >= ntxts)
        return ESCH_ERR_INVALIDPARMS;

    if (freeold && txt[i])
        delete txt[i];

    txt[i] = t;

    return ESCH_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschBuildMesh - compute_extents                                          �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
esch_error_codes EschBuildMesh::compute_extents(int optimal, int sph_only)
{
    if (!v || !f || !nverts || !nfaces)
        return ESCH_ERR_MISSINGDATA;

//陳� Compute spherical extent
    if (optimal)
    {
        // Loop through all looking for maximal distance

        EschPoint dia1(0,0,0);
        EschPoint dia2(0,0,0);

        float maxd = 0.0;
        for(ulong i=0; i < nverts; i++)
        {
            EschVertex *vtx = &v[i];

            for(ulong j=i+1; j < nverts; j++)
            {
                EschVertex *vtx2 = &v[j];

                float dist = EschVector( vtx->x - vtx2->x,
                                         vtx->y - vtx2->y,
                                         vtx->z - vtx2->z ).magnitude();
                if (dist > maxd)
                {
                    maxd = dist;

                    dia1.x = vtx->x;
                    dia1.y = vtx->y;
                    dia1.z = vtx->z;

                    dia2.x = vtx2->x;
                    dia2.y = vtx2->y;
                    dia2.z = vtx2->z;
                }
            }
        }

        EschPoint center( (dia1.x + dia2.x) / 2,
                          (dia1.y + dia2.y) / 2,
                          (dia1.z + dia2.z) / 2 );

        sphere.center = center;
        sphere.radius = maxd / 2;
    }
    else
    {
        EschPoint   xmin(FLT_MAX,
                         FLT_MAX,
                         FLT_MAX);
        EschPoint   ymin(xmin);
        EschPoint   zmin(xmin);

        EschPoint   xmax(-FLT_MAX,
                         -FLT_MAX,
                         -FLT_MAX);
        EschPoint   ymax(xmax);
        EschPoint   zmax(xmax);

        // Pass 1 (find minimums/maximums in each axis
        for(ulong i=0; i < nverts; i++)
        {
            EschVertex *vtx = &v[i];

            if (vtx->x < xmin.x)
            {
                xmin.x = vtx->x;
                xmin.y = vtx->y;
                xmin.z = vtx->z;
            }
            if (vtx->x > xmax.x)
            {
                xmax.x = vtx->x;
                xmax.y = vtx->y;
                xmax.z = vtx->z;
            }

            if (vtx->y < ymin.y)
            {
                ymin.x = vtx->x;
                ymin.y = vtx->y;
                ymin.z = vtx->z;
            }
            if (vtx->y > ymax.y)
            {
                ymax.x = vtx->x;
                ymax.y = vtx->y;
                ymax.z = vtx->z;
            }

            if (vtx->z < zmin.z)
            {
                zmin.x = vtx->x;
                zmin.y = vtx->y;
                zmin.z = vtx->z;
            }
            if (vtx->z > zmax.z)
            {
                zmax.x = vtx->x;
                zmax.y = vtx->y;
                zmax.z = vtx->z;
            }
        }

        // Compute spans
        float xspan = (xmax.x - xmin.x)*(xmax.x - xmin.x)
                      + (xmax.y - xmin.y)*(xmax.y - xmin.y)
                      + (xmax.z - xmin.z)*(xmax.z - xmin.z);
        float yspan = (ymax.x - ymin.x)*(ymax.x - ymin.x)
                      + (ymax.y - ymin.y)*(ymax.y - ymin.y)
                      + (ymax.z - ymin.z)*(ymax.z - ymin.z);
        float zspan = (zmax.x - zmin.x)*(zmax.x - zmin.x)
                      + (zmax.y - zmin.y)*(zmax.y - zmin.y)
                      + (zmax.z - zmin.z)*(zmax.z - zmin.z);

        // Set dia1 & dia2 to maximally seperate pair
        EschPoint dia1(xmin);
        EschPoint dia2(xmax);

        float maxspan = xspan;
        if (yspan > maxspan)
        {
            maxspan = yspan;
            dia1 = ymin; dia2 = ymax;
        }
        if (zspan > maxspan)
        {
            dia1 = zmin; dia2 = zmax;
        }

        // Compute values from initial diameter guess
        EschPoint center( (dia1.x + dia2.x) / 2,
                          (dia1.y + dia2.y) / 2,
                          (dia1.z + dia2.z) / 2 );

        float radius = EschVector( (dia2.x - center.x),
                                   (dia2.y - center.y),
                                   (dia2.z - center.z) ).magnitude();

        //陳� Pass 2 (ensure all points fit within sphere)
        for(i=0; i < nverts; i++)
        {
            EschVertex *vtx = &v[i];

            float old_to_p = EschVector( vtx->x - center.x,
                                         vtx->y - center.y,
                                         vtx->z - center.z ).magnitude();

            if (old_to_p > radius)
            {
                // Calc new radius
                radius = (radius + old_to_p) / 2;

                float old_to_new = old_to_p - radius;

                // Calc new center
                center.x = (radius*center.x + old_to_new*vtx->x) / old_to_p;
                center.y = (radius*center.y + old_to_new*vtx->y) / old_to_p;
                center.z = (radius*center.z + old_to_new*vtx->z) / old_to_p;
            }
        }

        sphere.radius = radius;
        sphere.center = center;
    }

//陳� Compute box extent
    if (!sph_only)
    {
        box.mins[0] =
        box.mins[1] =
        box.mins[2] = FLT_MAX;

        box.maxs[0] =
        box.maxs[1] =
        box.maxs[2] = -FLT_MAX;

        for(ulong i=0; i < nverts; i++)
        {
            float x = v[i].x;
            if (x < box.mins[0])
                box.mins[0] = x;
            if (x > box.maxs[0])
                box.maxs[0] = x;

            float y = v[i].y;
            if (y < box.mins[1])
                box.mins[1] = y;
            if (y > box.maxs[1])
                box.maxs[1] = y;

            float z = v[i].z;
            if (z < box.mins[2])
                box.mins[2] = z;
            if (z > box.maxs[2])
                box.maxs[2] = z;
        }
    }

    return ESCH_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschBuildMesh - compute_normals                                          �
//                                                                          �
// Computes the face normals (unless vtx_only is set) and then computes     �
// the vertex normals based on the face normals assuming faces are given    �
// in clockwise order.                                                      �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
esch_error_codes EschBuildMesh::compute_normals(int vtx_only)
{
    if (!v || !f || !nverts || !nfaces)
        return ESCH_ERR_MISSINGDATA;

//陳� Compute face normals
    if (!vtx_only)
    {
        for(ulong i=0; i < nfaces; i++)
        {
            EschFace *face = &f[i];

            EschVector v1(v[face->a].x - v[face->b].x,
                          v[face->a].y - v[face->b].y,
                          v[face->a].z - v[face->b].z);

            EschVector v2(v[face->c].x - v[face->b].x,
                          v[face->c].y - v[face->b].y,
                          v[face->c].z - v[face->b].z);

            EschVector v = v2 CROSS v1;
            v.normalize();

            face->normal = v;
        }
    }

//陳� Compute vertex normals
    {
        for(ulong i=0; i < nverts; i++)
        {
            EschVector  normal(0,0,0);

            for(ulong j=0; j < nfaces; j++)
            {
                EschFace *face = &f[j];
                if (face->a == i
                    || face->b == i
                    || face->c == i)
                {
                    normal.i += face->normal.i;
                    normal.j += face->normal.j;
                    normal.k += face->normal.k;
                }
            }

            normal.normalize();

            v[i].normal = normal;
        }
    }

    return ESCH_ERR_NONE;
}

//葦� End of module - esbldmsh.cpp 憶�


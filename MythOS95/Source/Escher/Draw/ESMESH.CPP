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
// esmesh.cpp
//
// Contains the code for the EschMesh container class.  This class is
// used to contain the original polygonal object data and is referred to
// and used by one ore more EschMeshDraw objects, thus reducing memory
// usage for multiple copies of the same mesh display simultaneously.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

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
// EschMesh - Constructor                                                   �
//                                                                          �
// Initializes the internal data pointers to empty values.  If a file name  �
// is given, then it attempts to load the mesh.                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschMesh::EschMesh() :
    ref_count(0),
    flags(0),
    v(0),
    f(0),
    txt(0)
{
    strcpy(name,EschNoName);
}

EschMesh::EschMesh(const char *fname, const char *oname,
                   VngoPal *pal, EschMatrix *m, char *pn,
                   dword ctrlfl) :
    ref_count(0),
    flags(0),
    v(0),
    f(0),
    txt(0)
{
    strcpy(name,EschNoName);

    load(fname,oname,pal,m,pn,ctrlfl);
}

EschMesh::EschMesh(const EschMesh &msh) :
    ref_count(0),
    flags(msh.flags & ~(ESCH_MSH_OWNSDATA | ESCH_MSH_OWNSTEXTURE)),
    sphere(msh.sphere),
    box(msh.box),
    nverts(msh.nverts),
    v(msh.v),
    nfaces(msh.nfaces),
    f(msh.f),
    tmax(msh.tmax),
    txt(msh.txt)
{
    strncpy(name,msh.name,ESCH_MAX_NAME);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschMesh - Destructor                                                    �
//                                                                          �
// Calls the release function.                                              �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschMesh::~EschMesh()
{
    assertMyth("~EschMesh expects that there are no references active",
               !ref_count);

    release();
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  Operations  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschMesh - operator =                                                    �
//                                                                          �
// Copies the data from another mesh.                                       �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
const EschMesh &EschMesh::operator = (const EschMesh &msh)
{
    if (this != &msh)
    {
        assertMyth("EschMesh::operator = expects that there are no references active",
                   !ref_count);

        release();

        flags = msh.flags & ~(ESCH_MSH_OWNSDATA | ESCH_MSH_OWNSTEXTURE);
        sphere = msh.sphere;
        box = msh.box;
        nverts = msh.nverts;
        v = msh.v;
        nfaces = msh.nfaces;
        f = msh.f;
        tmax = msh.tmax;
        txt = msh.txt;

        strncpy(name,msh.name,ESCH_MAX_NAME);
    }
    return *this;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschMesh - release                                                       �
//                                                                          �
// Frees associated data, if owned by the mesh.  Returns an error if the    �
// object is referenced.                                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
esch_error_codes EschMesh::release()
{
    if (ref_count)
        return ESCH_ERR_REFERENCED;

    if (flags & ESCH_MSH_OWNSDATA)
    {
        if (v)
        {
            ivory_hfree(&v);
        }

        if (f)
        {
            ivory_hfree(&f);
        }

        //陳 Update diags
        assertMyth("EschMesh needs Escher initialized",EschSysInstance != 0);
        EschSysInstance->diag_faces -= nfaces;
        EschSysInstance->diag_verts -= nverts;
    }
    v=0;
    f=0;
    nverts=nfaces=0;

    if (flags & ESCH_MSH_OWNSTEXTURE)
    {
        for(ulong i=0; i < tmax; i++)
        {
            if (txt[i])
                delete txt[i];
        }
        delete [] txt;
    }
    txt=0;
    tmax=0;

    flags &= ~(ESCH_MSH_OWNSDATA | ESCH_MSH_OWNSTEXTURE);

    return ESCH_ERR_NONE;
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  I/O Routines  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschMesh - load                                                          �
//                                                                          �
// This loads data for the EschMesh object from an IFF file, optionally     �
// returning any orientation matrix contained within the mesh record.       �
//                                                                          �
// The IFF version assumes that the IFF is open and pointing at the proper  �
// chunk.  If a 'oname' is given and the name doesn't match that in the     �
// form, an error is returned.                                              �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
esch_error_codes EschMesh::load(const char *fname, const char *oname,
                                VngoPal *pal, EschMatrix *m, char *pn,
                                dword ctrlfl)
{
    esch_error_codes    err;
    XFParseIFF          iff;

    assertMyth("EschMesh::load expects that there are no references active",
               !ref_count);

    release();

//陳 Open file
    if (iff.open(fname,XF_OPEN_READ | XF_OPEN_DENYWRITE))
        return ESCH_ERR_FILEERROR;

//陳 Loop until a header with the correct name is found
    err=ESCH_ERR_NONE;

    for(;;)
    {
        if (iff.next() != XF_ERR_NONE)
        {
            if (!iff.depth)
                return ESCH_ERR_NOTFOUND;
            iff.leaveform();
            continue;
        }

        if (iff.chunkid == iff.makeid('F','O','R','M'))
        {
            if (iff.formid == iff.makeid('E','M','S','H'))
            {
                err=load(&iff,oname,pal,m,pn,ctrlfl);
                if (!err
                    || err != ESCH_ERR_NOTFOUND)
                    break;
            }

            // Must scan inside any ESEN Scene forms.
            else if (iff.formid == iff.makeid('E','S','E','N'))
            {
                iff.enterform();
            }
        }
    }

//陳 Return ok
    iff.close();
    return err;
}

esch_error_codes EschMesh::load(XFParseIFF *iff,
                                const char *oname,
                                VngoPal *pal,
                                EschMatrix *m, char *pn,
                                dword ctrlfl)
{
    ulong               i;
    esch_error_codes    err;
    EschFileMeshHDR     header;
    EschFileMeshMTL     *emtl=0;

    assertMyth("EschMesh::load expects that there are no references active",
               !ref_count);

    release();

    assertMyth("EschMesh::load needs a valid iff pointer",
               iff);

//陳 Verify correct form name
    if (iff->chunkid != iff->makeid('F','O','R','M')
        || iff->formid != iff->makeid('E','M','S','H'))
        return ESCH_ERR_NOTFOUND;

//陳 Enter FORM, find header, verify name if any.
    iff->enterform();

    if (iff->seekchunk(iff->makeid('H','D','R',' '))
        || iff->chunkSize != sizeof(EschFileMeshHDR))
    {
        iff->leaveform();
        return ESCH_ERR_INVALIDDATA;
    }

    if (iff->read(&header))
    {
        iff->leaveform();
        return ESCH_ERR_FILEERROR;
    }

    if (oname && strncmp(oname,header.name,ESCH_MAX_NAME))
    {
        iff->leaveform();
        return ESCH_ERR_NOTFOUND;
    }

    if (!header.nverts || !header.nfaces)
    {
        iff->leaveform();
        return ESCH_ERR_INVALIDDATA;
    }

//陳 Found, so setup mesh

    strncpy(name,header.name,ESCH_MAX_NAME);
    flags = header.flags | ESCH_MSH_OWNSDATA;

    nverts = header.nverts;
    nfaces = header.nfaces;

    if (pn)
        *pn=0;

    //陳 Scan and load chunks in form
    while (!iff->next())
    {

        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Verticies
        if (iff->chunkid == iff->makeid('V','E','R','1'))
        {
            //陳� Data in floating-point
            if (v || iff->chunkSize != (nverts * sizeof(EschVertex)))
            {
                err=ESCH_ERR_INVALIDVDATA;
                goto error_exit;
            }
            v = ivory_halloc( sizeof(EschVertex) * nverts );
            if (!v)
            {
                err=ESCH_ERR_NOMEMORY;
                goto error_exit;
            }

            EschVertex *ptr = (EschVertex*)ivory_hlock(v);
            if (!ptr)
            {
                err=ESCH_ERR_LOCKFAILED;
                goto error_exit;
            }
            if (iff->read(ptr))
            {
                err=ESCH_ERR_FILEERROR;
                goto error_exit;
            }
            ivory_hunlock(v);
        }
        else if (iff->chunkid == iff->makeid('V','E','R','T'))
        {
            //陳� Data in fixed-point
            if (v || iff->chunkSize != (nverts * sizeof(EschVertexV1)))
            {
                err=ESCH_ERR_INVALIDVDATA;
                goto error_exit;
            }
            v = ivory_halloc( sizeof(EschVertex) * nverts );
            if (!v)
            {
                err=ESCH_ERR_NOMEMORY;
                goto error_exit;
            }

            EschVertex *ptr = (EschVertex*)ivory_hlock(v);
            if (!ptr)
            {
                err=ESCH_ERR_LOCKFAILED;
                goto error_exit;
            }

            EschVertexV1 *vtemp = new EschVertexV1[nverts];
            if (!vtemp)
            {
                err=ESCH_ERR_NOMEMORY;
                goto error_exit;
            }

            if (iff->read(vtemp))
            {
                delete [] vtemp;
                err=ESCH_ERR_FILEERROR;
                goto error_exit;
            }

            EschVertex *tptr = ptr;
            EschVertexV1 *tmpptr = vtemp;
            for(ulong i=0; i < nverts; i++, tptr++, tmpptr++)
            {
                tptr->x = tmpptr->x / 65536.0f;
                tptr->y = tmpptr->y / 65536.0f;
                tptr->z = tmpptr->z / 65536.0f;
                tptr->normal.i = tmpptr->normal.i / 65536.0f;
                tptr->normal.j = tmpptr->normal.j / 65536.0f;
                tptr->normal.k = tmpptr->normal.k / 65536.0f;
            }

            delete [] vtemp;
            ivory_hunlock(v);
        }

        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Faces
        else if (iff->chunkid == iff->makeid('F','A','C','2'))
        {
            //陳� Data in floating-point
            if (f || iff->chunkSize != (nfaces * sizeof(EschFace)))
            {
                err=ESCH_ERR_INVALIDFDATA;
                goto error_exit;
            }
            f = ivory_halloc( sizeof(EschFace) * nfaces );
            if (!f)
            {
                err=ESCH_ERR_NOMEMORY;
                goto error_exit;
            }

            EschFace *ptr = (EschFace*)ivory_hlock(f);
            if (!ptr)
            {
                err=ESCH_ERR_LOCKFAILED;
                goto error_exit;
            }
            if (iff->read(ptr))
            {
                err=ESCH_ERR_FILEERROR;
                goto error_exit;
            }

            EschFace *tptr = ptr;
            for(i=0; i < nfaces; i++, tptr++)
                tptr->app_data = 0;

            ivory_hunlock(f);
        }
        else if (iff->chunkid == iff->makeid('F','A','C','1'))
        {
            //陳� Data in older floating-point format
            if (f || iff->chunkSize != (nfaces * sizeof(EschFaceV2)))
            {
                err=ESCH_ERR_INVALIDFDATA;
                goto error_exit;
            }
            f = ivory_halloc( sizeof(EschFace) * nfaces );
            if (!f)
            {
                err=ESCH_ERR_NOMEMORY;
                goto error_exit;
            }

            EschFace *ptr = (EschFace*)ivory_hlock(f);
            if (!ptr)
            {
                err=ESCH_ERR_LOCKFAILED;
                goto error_exit;
            }

            EschFaceV2 *ftemp = new EschFaceV2[nfaces];
            if (!ftemp)
            {
                err=ESCH_ERR_NOMEMORY;
                goto error_exit;
            }

            if (iff->read(ftemp))
            {
                delete [] ftemp;
                err=ESCH_ERR_FILEERROR;
                goto error_exit;
            }

            EschFace *tptr = ptr;
            EschFaceV2 *tmpptr = ftemp;
            for(ulong i=0; i < nfaces; i++, tptr++, tmpptr++)
            {
                tptr->flags = tmpptr->flags & ~(ESCH_FACEV2_SILLUM_MASK
                                                | ESCH_FACEV2_ALPHA_MASK);
                tptr->a = tmpptr->a;
                tptr->b = tmpptr->b;
                tptr->c = tmpptr->c;
                tptr->txt = tmpptr->txt;
                tptr->u[0] = tmpptr->u[0];
                tptr->u[1] = tmpptr->u[1];
                tptr->u[2] = tmpptr->u[2];
                tptr->v[0] = tmpptr->v[0];
                tptr->v[1] = tmpptr->v[1];
                tptr->v[2] = tmpptr->v[2];
                tptr->color = tmpptr->color;
                tptr->normal.i = tmpptr->normal.i;
                tptr->normal.j = tmpptr->normal.j;
                tptr->normal.k = tmpptr->normal.k;

                tptr->self_illum = byte((tmpptr->flags & ESCH_FACEV2_SILLUM_MASK) >> 16);

                if (tmpptr->flags & ESCH_FACE_ALPHA)
                {
                    tptr->alpha_a =
                    tptr->alpha_b =
                    tptr->alpha_c = byte((tmpptr->flags & ESCH_FACEV2_ALPHA_MASK) >> 20);
                }
                else
                {
                    tptr->alpha_a =
                    tptr->alpha_b =
                    tptr->alpha_c = 255;
                }

                tptr->app_data = 0;
            }

            delete [] ftemp;
            ivory_hunlock(f);
        }
        else if (iff->chunkid == iff->makeid('F','A','C','E'))
        {
            //陳� Data in fixed-point
            if (f || iff->chunkSize != (nfaces * sizeof(EschFaceV1)))
            {
                err=ESCH_ERR_INVALIDFDATA;
                goto error_exit;
            }
            f = ivory_halloc( sizeof(EschFace) * nfaces );
            if (!f)
            {
                err=ESCH_ERR_NOMEMORY;
                goto error_exit;
            }

            EschFace *ptr = (EschFace*)ivory_hlock(f);
            if (!ptr)
            {
                err=ESCH_ERR_LOCKFAILED;
                goto error_exit;
            }

            EschFaceV1 *ftemp = new EschFaceV1[nfaces];
            if (!ftemp)
            {
                err=ESCH_ERR_NOMEMORY;
                goto error_exit;
            }

            if (iff->read(ftemp))
            {
                delete [] ftemp;
                err=ESCH_ERR_FILEERROR;
                goto error_exit;
            }

            EschFace *tptr = ptr;
            EschFaceV1 *tmpptr = ftemp;
            for(ulong i=0; i < nfaces; i++, tptr++, tmpptr++)
            {
                tptr->flags = tmpptr->flags & ~(ESCH_FACEV1_SILLUM_MASK
                                                | ESCH_FACEV1_ALPHA_MASK);
                tptr->a = tmpptr->a;
                tptr->b = tmpptr->b;
                tptr->c = tmpptr->c;
                tptr->txt = tmpptr->txt;
                tptr->u[0] = tmpptr->u[0] / 65536.0f;
                tptr->u[1] = tmpptr->u[1] / 65536.0f;
                tptr->u[2] = tmpptr->u[2] / 65536.0f;
                tptr->v[0] = tmpptr->v[0] / 65536.0f;
                tptr->v[1] = tmpptr->v[1] / 65536.0f;
                tptr->v[2] = tmpptr->v[2] / 65536.0f;
                tptr->color = tmpptr->color;
                tptr->normal.i = tmpptr->normal.i / 65536.0f;
                tptr->normal.j = tmpptr->normal.j / 65536.0f;
                tptr->normal.k = tmpptr->normal.k / 65536.0f;

                tptr->self_illum = byte((tmpptr->flags & ESCH_FACEV1_SILLUM_MASK) >> 16);
                if (tmpptr->flags & ESCH_FACE_ALPHA)
                {
                    tptr->alpha_a =
                    tptr->alpha_b =
                    tptr->alpha_c = byte((tmpptr->flags & ESCH_FACEV1_ALPHA_MASK) >> 20);
                }
                else
                {
                    tptr->alpha_a =
                    tptr->alpha_b =
                    tptr->alpha_c = 255;
                }

                tptr->app_data = 0;
            }

            delete [] ftemp;
            ivory_hunlock(f);
        }

        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Extents
        else if (iff->chunkid == iff->makeid('E','X','N','1'))
        {
            //陳� Data in floating-point
            EschFileMeshEXNT ext;

            if (iff->chunkSize != sizeof(ext))
            {
                err=ESCH_ERR_INVALIDDATA;
                goto error_exit;
            }
            if (iff->read(&ext))
            {
                err=ESCH_ERR_FILEERROR;
                goto error_exit;
            }

            sphere.center.x=ext.cenx;
            sphere.center.y=ext.ceny;
            sphere.center.z=ext.cenz;
            sphere.radius=ext.extent_radius;
            box.mins[0]=ext.minx;
            box.mins[1]=ext.miny;
            box.mins[2]=ext.minz;
            box.maxs[0]=ext.maxx;
            box.maxs[1]=ext.maxy;
            box.maxs[2]=ext.maxz;
        }
        else if (iff->chunkid == iff->makeid('E','X','N','T'))
        {
            //陳� Data in fixed-point
            EschFileMeshEXNTV1 ext;

            if (iff->chunkSize != sizeof(ext))
            {
                err=ESCH_ERR_INVALIDDATA;
                goto error_exit;
            }
            if (iff->read(&ext))
            {
                err=ESCH_ERR_FILEERROR;
                goto error_exit;
            }

            sphere.center.x=ext.cenx / 65536.0f;
            sphere.center.y=ext.ceny / 65536.0f;
            sphere.center.z=ext.cenz / 65536.0f;
            sphere.radius=ext.extent_radius / 65536.0f;
            box.mins[0]=ext.minx / 65536.0f;
            box.mins[1]=ext.miny / 65536.0f;
            box.mins[2]=ext.minz / 65536.0f;
            box.maxs[0]=ext.maxx / 65536.0f;
            box.maxs[1]=ext.maxy / 65536.0f;
            box.maxs[2]=ext.maxz / 65536.0f;
        }

        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Orientation Matrix
        else if (m && iff->chunkid == iff->makeid('M','T','R','1'))
        {
            //陳� Data in floating-point
            if (iff->chunkSize != sizeof(EschMatrix))
            {
                err=ESCH_ERR_INVALIDDATA;
                goto error_exit;
            }
            if (iff->read(m))
            {
                err=ESCH_ERR_FILEERROR;
                goto error_exit;
            }
        }
        else if (m && iff->chunkid == iff->makeid('M','T','R','X'))
        {
            //陳� Data in fixed-point
            EschMatrixV1 mtx;

            if (iff->chunkSize != sizeof(mtx))
            {
                err=ESCH_ERR_INVALIDDATA;
                goto error_exit;
            }
            if (iff->read(&mtx))
            {
                err=ESCH_ERR_FILEERROR;
                goto error_exit;
            }

            for(int i=0; i < ESCH_MTX_NUM; i++)
                m->mtx[i] = mtx.mtx[i] / 65536.0f;
        }

        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Hiearchy
        else if (pn && iff->chunkid == iff->makeid('H','I','E','R'))
        {
            if (iff->chunkSize != sizeof(EschFileMeshHIER))
            {
                err=ESCH_ERR_INVALIDHIER;
                goto error_exit;
            }
            if (iff->read(pn))
            {
                err=ESCH_ERR_FILEERROR;
                goto error_exit;
            }
        }

        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Materials
        else if (header.nmtls
                 && (iff->chunkid == iff->makeid('M','T','L',' ')))
        {
            if (emtl || txt
                || iff->chunkSize != (sizeof(EschFileMeshMTL)*header.nmtls))
            {
                err=ESCH_ERR_INVALIDDATA;
                goto error_exit;
            }
            emtl = new EschFileMeshMTL[header.nmtls];
            if (!emtl)
            {
                err=ESCH_ERR_NOMEMORY;
                goto error_exit;
            }
            if (iff->read(emtl))
            {
                err=ESCH_ERR_FILEERROR;
                goto error_exit;
            }

            //陳� Allocate texture array
            txt = new EschTexture*[header.nmtls];
            if (!txt)
            {
                err=ESCH_ERR_NOMEMORY;
                goto error_exit;
            }
            tmax = header.nmtls;
            flags |= ESCH_MSH_OWNSTEXTURE;

            //陳� Fill out from texture cache/file systems
            for(i=0; i < header.nmtls; i++)
            {
                txt[i] = 0;

                if (ctrlfl & ESCH_MSHLD_SHARETXT)
                    txt[i] = EschTexture::cache_new(emtl[i].name);

                if (!txt[i] && (ctrlfl & ESCH_MSHLD_FILETXT))
                {
                    dword tfl = ESCH_TXTLD_ALL;
                    if (!(ctrlfl & ESCH_MSHLD_SHARETXT))
                        tfl &= ~ESCH_TXTLD_SHARE;
                    if (ctrlfl & ESCH_MSHLD_TXTTCBM)
                        tfl |= ESCH_TXTLD_TCBITMAP;

                    txt[i] = EschTexture::file_load(emtl[i].name,pal,tfl);
                }
            }
        }

        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Material Form
        else if (header.nmtls
                 && (iff->chunkid == iff->makeid('F','O','R','M'))
                 && (iff->formid == iff->makeid('E','M','T','L')
                     || iff->formid == iff->makeid('E','M','T','1')))
        {
            //陳� Allocate texture memory, if not already allocated.
            if (!txt)
            {
                txt = new EschTexture*[header.nmtls];
                if (!txt)
                {
                    err=ESCH_ERR_NOMEMORY;
                    goto error_exit;
                }
                memset(txt,0,sizeof(EschTexture*)*header.nmtls);
                tmax = header.nmtls;
                flags |= ESCH_MSH_OWNSTEXTURE;
            }

            //陳� Figure out next texture we are looking for.
            for(i=0; i < header.nmtls; i++)
            {
                if (!txt[i])
                    break;
            }

            //陳� Load texture
            if (i < header.nmtls)
            {
                EschTexture *t = ((ctrlfl & ESCH_MSHLD_USEMFTXT)
                                   && iff->formid == iff->makeid('E','M','T','1'))
                                  ? (EschTexture *) new EschMultiFrameTexture
                                  : (EschTexture *) new EschStaticTexture;
                if (!t)
                {
                    err=ESCH_ERR_NOMEMORY;
                    goto error_exit;
                }

                dword tfl = ESCH_TXTLD_ALL;
                if (!(ctrlfl & ESCH_MSHLD_SHARETXT))
                    tfl &= ~ESCH_TXTLD_SHARE;
                if (ctrlfl & ESCH_MSHLD_TXTTCBM)
                    tfl |= ESCH_TXTLD_TCBITMAP;

                err=t->load(iff, (emtl) ? emtl[i].name : 0, tfl, pal);

                if (!err)
                    txt[i]=t;
                else
                {
                    delete t;
                    if (err != ESCH_ERR_NOTFOUND)
                        goto error_exit;
                }
            }
        }
    }

    if (txt)
    {
        for(i=0; i < header.nmtls; i++)
        {
            if (!txt[i])
            {
                err=ESCH_ERR_MISSINGDATA;
                goto error_exit;
            }
        }
    }
    else
    {
//陳 Process texture/materials

        EschFace *ptr = (EschFace*)ivory_hlock(f);
        if (!ptr)
        {
            err=ESCH_ERR_LOCKFAILED;
            goto error_exit;
        }

        for(i=0; i < nfaces; i++)
        {
            ptr[i].txt=0;
            ptr[i].flags &= ~ESCH_FACE_TEXTURED;
        }
        ivory_hunlock(f);
    }

    if (emtl)
    {
        delete [] emtl;
        emtl=0;
    }

//陳 Update diags
    assertMyth("EschMesh needs Escher initialized",EschSysInstance != 0);
    EschSysInstance->diag_faces += nfaces;
    EschSysInstance->diag_verts += nverts;

//陳 Translate colors if a palette is given.
    if (pal)
    {
        EschFace *ptr = (EschFace*)ivory_hlock(f);
        if (!ptr)
        {
            err=ESCH_ERR_LOCKFAILED;
            goto error_exit;
        }

        for(i=0; i < nfaces; i++)
        {
            ptr[i].color = pal->get_index(*((VngoColor24bit*)&ptr[i].color));
        }
        ivory_hunlock(f);
    }

//陳 Return ok
    iff->leaveform();
    return ESCH_ERR_NONE;

//陳 Return error
error_exit : ;
    if (v)
        ivory_hfree(&v);
    if (f)
        ivory_hfree(&f);
    if (txt)
    {
        for(i=0; i < tmax; i++)
        {
            if (txt[i])
                delete txt[i];
        }
        delete [] txt;
        txt=0;
    }
    if (emtl)
        delete [] emtl;

    iff->leaveform();
    return err;
}

//葦� End of module - esmesh.cpp 憶�


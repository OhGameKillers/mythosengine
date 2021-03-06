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
// essystem.cpp
//
// Contains the code for the EschSystem library control class.
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
//                               Routines
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

extern "C" int mythos_detect_mmx();
extern "C" int mythos_detect_amd3d();

//陳� Float math routines
extern "C" void esch_flt_transform(const void *s,
                                   const EschMatrix *m, void *d);
extern "C" void esch_flt_transform_notran(const void *s,
                                          const EschMatrix *m, void *d);
extern "C" EschVector *esch_flt_cross(const EschVector *v1,
                                      const EschVector *v2,
                                      EschVector *dest);
extern "C" void esch_flt_normalize(EschVector *vect);
extern "C" void esch_flt_concatmatrix(const EschMatrix *s,
                                      const EschMatrix *m,
                                      EschMatrix *d);

//陳� AMD-3D Specific routines
extern "C" void esch_amd3d_transform(const void *s,
                                     const EschMatrix *m, void *d);
extern "C" void esch_amd3d_transform_notran(const void *s,
                                            const EschMatrix *m, void *d);
extern "C" EschVector *esch_amd3d_cross(const EschVector *v1,
                                        const EschVector *v2,
                                        EschVector *dest);
extern "C" void esch_amd3d_normalize(EschVector *vect);
extern "C" void esch_amd3d_concatmatrix(const EschMatrix *s,
                                        const EschMatrix *m,
                                        EschMatrix *d);

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//陳� Point and vector operations
void (*esch_transform)(const void *s,
                       const EschMatrix *m, void *d) = esch_flt_transform;
void (*esch_transform_notran)(const void *s,
                              const EschMatrix *m,
                              void *d) = esch_flt_transform_notran;

//陳 Vector functions
EschVector *(*esch_cross)(const EschVector *v1,
                          const EschVector *v2,
                          EschVector *dest) = esch_flt_cross;
extern "C" void (*esch_normalize)(EschVector *vect) = esch_flt_normalize;

//陳 Matrix functions
extern "C" void (*esch_concatmatrix)(const EschMatrix *s,
                                     const EschMatrix *m,
                                     EschMatrix *d) = esch_flt_concatmatrix;

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭�  Constructors/Destructors  碓旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschSystem - Constructor                                                 �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschSystem::EschSystem(ulong arena_size, ulong sort_size) :
    flags(0),
    wspace_mbytes(0),
    wspace_sbytes(0),
    wspace(0),
    sspace_mdepth(0),
    sspace_mbytes(0),
    sspace_sbytes(0),
    sspace(0),
    sroot(0),
    diag_faces(0),
    diag_verts(0),
    diag_ifaces(0),
    diag_iverts(0),
    diag_ntxts(0),
    tcache_hi(0),
    tcache_max(0),
    tcache(0),
    tfile_hi(0),
    tfile_max(0),
    tfile(0)
{
    esch_error_codes    err;

    assertMyth("EschSystem: Only one instance is allowed.",
               !EschSysInstance);

    EschSysInstance=this;

    //陳 Create workspace, if arena_size given
    if (arena_size)
    {
        err=init(arena_size,sort_size);
        assertMyth ("EschSystem constructor failed init()",
                    err == ESCH_ERR_NONE);
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschSystem - Destructor                                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschSystem::~EschSystem()
{
    assertMyth("~EschSystem: EschSysInstance points to invalid data",
               EschSysInstance == this);

    release();

    EschSysInstance=0;
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  Operations  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschSystem - init                                                        �
//                                                                          �
// Initializes the library, created required global data.                   �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
esch_error_codes EschSystem::init(ulong arena_size, ulong sort_size)
{
    assertMyth("EschSystem::init requires a positive arena and sort size",
               arena_size > 0 && sort_size > 0);

    release();

//陳 Setup initial flags
    if (mythos_detect_amd3d())
    {
        flags = ESCH_SYS_MMX_FOUND
                | ESCH_SYS_AMD3D_FOUND;
    }
    else if (mythos_detect_mmx())
    {
        flags = ESCH_SYS_MMX_FOUND;
    }

//陳 Create workspace arena
    wspace=(IvoryArena*)ivory_alloc(arena_size);
    if (!wspace)
        return ESCH_ERR_NOMEMORY;

    wspace_sbytes = arena_size;
    wspace_mbytes = 0;

    if (!ivory_arena_initialize(wspace,arena_size))
        return ESCH_ERR_NOMEMORY;

//陳 Create sort arena
    sspace=(IvoryArena*)ivory_alloc(sort_size);
    if (!sspace)
        return ESCH_ERR_NOMEMORY;

    sspace_sbytes = sort_size;
    sspace_mbytes = 0;
    sspace_mdepth = 0;

    if (!ivory_arena_initialize(sspace,sort_size))
        return ESCH_ERR_NOMEMORY;

    sroot = 0;

    return ESCH_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschSystem - release                                                     �
//                                                                          �
// Releases the global data space for Escher.                               �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschSystem::release()
{
//陳 Destroy texture cache
    if (tcache)
    {
        for(ulong i=0; i < tcache_hi; i++)
        {
            assertMyth("~EschSystem:  Texture cache not empty",
                       tcache[i].handle == 0);

            if (tcache[i].handle)
            {
                ivory_hfree(&tcache[i].handle);
            }
            if (tcache[i].name)
            {
                delete [] tcache[i].name;
                tcache[i].name = 0;
            }
        }

        delete [] tcache;
        tcache=0;
    }

//陳 Destroy texture file list
    if (tfile)
    {
        for(ulong i=0; i < tfile_hi; i++)
        {
            if (tfile[i].names)
                delete [] tfile[i].names;
            if (tfile[i].iff)
                delete tfile[i].iff;
        }

        delete [] tfile;
        tfile=0;
    }

//陳 Destroy arenas
    if (wspace)
    {
        ivory_free((void**)&wspace);
    }
    if (sspace)
    {
        ivory_free((void**)&sspace);
    }
    sroot=0;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschSystem - enable/disable_amd3d                                        �
//                                                                          �
// Turns on or off the AMD-3D optimized versions of routines.               �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
esch_error_codes EschSystem::enable_amd3d()
{
    if (!(flags & ESCH_SYS_AMD3D_FOUND))
        return ESCH_ERR_NOTSUPPORTED;

    flags |= ESCH_SYS_AMD3D;

    esch_transform          = esch_amd3d_transform;
    esch_transform_notran   = esch_amd3d_transform_notran;

    esch_cross              = esch_amd3d_cross;
    esch_normalize          = esch_amd3d_normalize;
    esch_concatmatrix       = esch_amd3d_concatmatrix;

    return ESCH_ERR_NONE;
}

void EschSystem::disable_amd3d()
{
    flags &= ~ESCH_SYS_AMD3D;

    esch_transform          = esch_flt_transform;
    esch_transform_notran   = esch_flt_transform_notran;

    esch_cross              = esch_flt_cross;
    esch_normalize          = esch_flt_normalize;
    esch_concatmatrix       = esch_flt_concatmatrix;
}

//葦� End of module - essystem.cpp 憶�


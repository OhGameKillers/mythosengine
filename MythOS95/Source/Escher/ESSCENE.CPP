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
// esscene.cpp
//
// The EschScene class is used to load and manage a collection of
// cameras, lights, and objects all defined together.  Scenes can
// be loaded from files with their object relations intact.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include "escher.hpp"

#include "esfile.hpp"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Structures
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

struct hier_type
{
    char            pname[ESCH_MAX_NAME];
    EschMeshDraw    *m;
};

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
// EschScene - Constructor                                                  �
//                                                                          �
// Initializes the scene pointers, loading from a file if a filename is     �
// given.                                                                   �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschScene::EschScene() :
    flags(0),
    cameras(0),
    lights(0),
    meshes(0)
{
    strcpy(name,EschNoName);
}


EschScene::EschScene(const char *fname, const char *sname,
                     VngoPal *pal, dword flgs) :
    flags(0),
    cameras(0),
    lights(0),
    meshes(0)
{
    strcpy(name,EschNoName);

    if (fname)
        load(fname,sname,pal,flgs);
}


EschScene::EschScene(const EschScene &s) :
    flags(s.flags & ~ESCH_SCENE_OWNSDATA),
    ncameras(s.ncameras),
    cameras(s.cameras),
    nlights(s.nlights),
    lights(s.lights),
    nmeshes(s.nmeshes),
    meshes(s.meshes)
{
    strncpy(name,s.name,ESCH_MAX_NAME);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschScene - Destructor                                                   �
//                                                                          �
// Calls release.                                                           �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschScene::~EschScene()
{
    release();
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  Operations  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschScene - operator =                                                   �
//                                                                          �
// Copies the data from another scene.                                      �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
const EschScene &EschScene::operator = (const EschScene &s)
{
    if (this != &s)
    {
        flags = s.flags & ~ESCH_SCENE_OWNSDATA;
        ncameras = s.ncameras;
        cameras = s.cameras;
        nlights = s.nlights;
        lights = s.lights;
        nmeshes = s.nmeshes;
        meshes = s.meshes;

        strncpy(name,s.name,ESCH_MAX_NAME);
    }
    return *this;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschScene - release                                                      �
//                                                                          �
// Frees any data owned by the scene.                                       �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschScene::release()
{
    if (flags & ESCH_SCENE_OWNSDATA)
    {
        for (EschLight *lptr=lights; lptr;)
        {
            EschLight   *t=lptr;
            lptr = lptr->next();
            delete t;
        }

        for (EschCamera *cptr=cameras; cptr;)
        {
            EschCamera  *t=cptr;
            cptr = cptr->next();
            delete t;
        }

        for (EschMeshDraw *mptr=meshes; mptr;)
        {
            EschMeshDraw    *t=mptr;
            mptr = (EschMeshDraw*) mptr->next();
            t->remove(1);
            delete t;
        }
    }

    flags &= ~ESCH_SCENE_OWNSDATA;

    cameras=0;
    lights=0;
    meshes=0;
    ncameras=nlights=nmeshes=0;

    strcpy(name,EschNoName);
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  I/O Routines  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschScene - load                                                         �
//                                                                          �
// Loads a scene from an IFF file out of an ESEN form.                      �
//                                                                          �
// The IFF version assumes that the IFF is open and pointing at the proper  �
// form.  If a 'sname' is given and the name doesn't match that in the      �
// form, an error is returned.                                              �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
esch_error_codes EschScene::load(const char *fname, const char *sname,
                                 VngoPal *pal, dword flgs)
{
    esch_error_codes    err;
    XFParseIFF          iff;

//陳 Open file
    if (iff.open(fname,XF_OPEN_READ | XF_OPEN_DENYWRITE))
        return ESCH_ERR_FILEERROR;

//陳 Loop until an 'ESEN' FORM with correct name is found.
    err=ESCH_ERR_NONE;

    for(;;)
    {
        if (iff.next() != XF_ERR_NONE)
        {
            return ESCH_ERR_NOTFOUND;
        }

        if (iff.chunkid == iff.makeid('F','O','R','M')
            && iff.formid == iff.makeid('E','S','E','N'))
        {
            err=load(&iff,sname,pal,flgs);
            if (!err
                || err != ESCH_ERR_NOTFOUND)
                break;
        }
    }

//陳 Return ok
    iff.close();
    return err;
}

esch_error_codes EschScene::load(XFParseIFF *iff, const char *sname,
                                 VngoPal *pal, dword flgs)
{
    ulong               i;
    esch_error_codes    err;
    ulong               ncams=0;
    ulong               nmshs=0;
    ulong               nlgts=0;
    struct hier_type    *hier=0;
    EschFileSceneHDR    header;
    char                pname[ESCH_MAX_NAME];

    assertMyth("EschScene::load requires an iff pointer",
               iff);

    release();

//陳 Verify correct form
    if (iff->chunkid != iff->makeid('F','O','R','M')
        || iff->formid != iff->makeid('E','S','E','N'))
    {
        return ESCH_ERR_NOTFOUND;
    }

//陳 Enter FORM, find header, verify name if any.
    iff->enterform();

    if (iff->seekchunk(iff->makeid('H','D','R',' '))
        || iff->chunkSize != sizeof(EschFileSceneHDR))
    {
        iff->leaveform();
        return ESCH_ERR_INVALIDDATA;
    }

    if (iff->read(&header))
    {
        iff->leaveform();
        return ESCH_ERR_FILEERROR;
    }

    if (sname && strcmp(sname,header.name))
    {
        iff->leaveform();
        return ESCH_ERR_NOTFOUND;
    }

//陳 Found

    //陳 Setup
    strcpy(name,header.name);
    flags |= ESCH_SCENE_OWNSDATA;

    //陳 Setup counters
    if (flgs & (ESCH_SCENELD_MESHES|ESCH_SCENELD_SKELETON) && header.nobjects)
    {
        nmeshes = header.nobjects;

        if (flgs & ESCH_SCENELD_HIERARCHY)
        {
            hier = new hier_type[nmeshes];
            if (!hier)
            {
                iff->leaveform();
                return ESCH_ERR_NOMEMORY;
            }
            memset(hier,0,sizeof(hier_type)*nmeshes);
        }
    }

    if (flgs & ESCH_SCENELD_CAMERAS && header.ncameras)
    {
        ncameras = header.ncameras;
    }

    if (flgs & ESCH_SCENELD_LIGHTS)
    {
        nlights = header.nvectorlights
                  + header.npointlights
                  + header.nfpointlights
                  + header.nattenlights
                  + header.nfattenlights
                  + header.nspotlights
                  + header.nfspotlights;
    }

    //陳 Scan and load chunks in form
    while (iff->next() == XF_ERR_NONE)
    {

        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Meshes
        if (iff->chunkid == iff->makeid('F','O','R','M')
            && iff->formid == iff->makeid('E','M','S','H')
            && (flgs & ESCH_SCENELD_SKELETON))
        {
            EschKeyframeDraw    *m;

            m = new EschKeyframeDraw;
            if (!m)
            {
                err=ESCH_ERR_NOMEMORY;
                goto error_exit;
            }

            dword ctrlfl = ESCH_MSHLD_ALL;

            if (flgs & ESCH_SCENELD_NOMFTXT)
                ctrlfl &= ~ESCH_MSHLD_USEMFTXT;

            if (flgs & ESCH_SCENELD_NOSHARETXT)
                ctrlfl &= ~ESCH_MSHLD_SHARETXT;

            if (flgs & ESCH_SCENELD_NOFILETXT)
                ctrlfl &= ~ESCH_MSHLD_FILETXT;

            err=m->load(iff,0,pal,0,pname,ctrlfl);
            if (err)
            {
                delete m;
                goto error_exit;
            }

            if (!*pname || !hier)
            {
                // Root object or not using hierarchies

                if (meshes)
                    m->sibling(meshes);
                else
                    meshes=m;
            }
            else
            {
                // Need to save for later patchup

                strncpy(hier[nmshs].pname,pname,ESCH_MAX_NAME);
                hier[nmshs].m = m;
            }

            nmshs++;
        }
        else if (iff->chunkid == iff->makeid('F','O','R','M')
                 && iff->formid == iff->makeid('E','M','S','H')
                 && flgs & (ESCH_SCENELD_MESHES))
        {
            EschMeshDraw    *m;

            m = new EschMeshDraw;
            if (!m)
            {
                err=ESCH_ERR_NOMEMORY;
                goto error_exit;
            }

            dword ctrlfl = ESCH_MSHLD_ALL;

            if (flgs & ESCH_SCENELD_NOMFTXT)
                ctrlfl &= ~ESCH_MSHLD_USEMFTXT;

            if (flgs & ESCH_SCENELD_NOSHARETXT)
                ctrlfl &= ~ESCH_MSHLD_SHARETXT;

            if (flgs & ESCH_SCENELD_NOFILETXT)
                ctrlfl &= ~ESCH_MSHLD_FILETXT;

            err=m->load(iff,0,pal,0,pname,ctrlfl);
            if (err)
            {
                delete m;
                goto error_exit;
            }

            if (!*pname || !hier)
            {
                // Root object or not using hierarchies

                if (meshes)
                    m->sibling(meshes);
                else
                    meshes=m;
            }
            else
            {
                // Need to save for later patchup

                strncpy(hier[nmshs].pname,pname,ESCH_MAX_NAME);
                hier[nmshs].m = m;
            }

            nmshs++;
        }

        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Cameras
        else if ((iff->chunkid == iff->makeid('E','C','A','M')
                  || iff->chunkid == iff->makeid('E','C','A','1'))
                 && flgs & (ESCH_SCENELD_CAMERAS))
        {
            EschCamera  *c;

            if (flgs & ESCH_SCENELD_CAMSEX)
                c = new EschCameraEx;
            else
                c = new EschCamera;
            if (!c)
            {
                err=ESCH_ERR_NOMEMORY;
                goto error_exit;
            }

            if ((err=c->load(iff))!=0)
            {
                delete c;
                goto error_exit;
            }

            if (cameras)
                c->sibling(cameras);
            else
                cameras=c;

            ncams++;
        }

        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Lights
        else if (( iff->chunkid == iff->makeid('E','A','M','B')
                   || iff->chunkid == iff->makeid('E','V','E','C')
                   || iff->chunkid == iff->makeid('E','V','E','1')
                   || iff->chunkid == iff->makeid('E','F','P','T')
                   || iff->chunkid == iff->makeid('E','F','P','1')
                   || iff->chunkid == iff->makeid('E','F','A','T')
                   || iff->chunkid == iff->makeid('E','F','A','1')
                   || iff->chunkid == iff->makeid('E','F','S','P')
                   || iff->chunkid == iff->makeid('E','F','S','1')
                   || iff->chunkid == iff->makeid('E','P','N','T')
                   || iff->chunkid == iff->makeid('E','P','N','1')
                   || iff->chunkid == iff->makeid('E','A','T','N')
                   || iff->chunkid == iff->makeid('E','A','T','1')
                   || iff->chunkid == iff->makeid('E','S','P','T')
                   || iff->chunkid == iff->makeid('E','S','P','1') )
                 && (flgs & ESCH_SCENELD_LIGHTS))
        {
            EschLight   *l=0;

            if (iff->chunkid == iff->makeid('E','A','M','B'))
            {
                l = new EschLight;
            }
            else if (iff->chunkid == iff->makeid('E','V','E','C')
                     || iff->chunkid == iff->makeid('E','V','E','1'))
            {
                l = (EschLight*)new EschVectorLight;
            }
            else if (iff->chunkid == iff->makeid('E','F','P','T')
                     || iff->chunkid == iff->makeid('E','F','P','1'))
            {
                l = (EschLight*)new EschFastPointLight;
            }
            else if (iff->chunkid == iff->makeid('E','F','A','T')
                     || iff->chunkid == iff->makeid('E','F','A','1'))
            {
                l = (EschLight*)new EschFastAttenLight;
            }
            else if (iff->chunkid == iff->makeid('E','F','S','P')
                     || iff->chunkid == iff->makeid('E','F','S','1'))
            {
               l = (EschLight*)new EschFastSpotLight;
            }
            else if (iff->chunkid == iff->makeid('E','P','N','T')
                     || iff->chunkid == iff->makeid('E','P','N','1'))
            {
                l = (EschLight*)new EschPointLight;
            }
            else if (iff->chunkid == iff->makeid('E','A','T','N')
                     || iff->chunkid == iff->makeid('E','A','T','1'))
            {
                l = (EschLight*)new EschAttenLight;
            }
            else if (iff->chunkid == iff->makeid('E','S','P','T')
                     || iff->chunkid == iff->makeid('E','S','P','1'))
            {
                l = (EschLight*)new EschSpotLight;
            }

            if (!l)
            {
                err=ESCH_ERR_NOMEMORY;
                goto error_exit;
            }

            if ((err=l->load(iff))!=0)
            {
                delete l;
                goto error_exit;
            }

            if (lights)
                l->sibling(lights);
            else
                lights = l;

            if (iff->chunkid != iff->makeid('E','A','M','B'))
                nlgts++;
        }
        else if (iff->chunkid == iff->makeid('F','O','R','M')
                 && iff->formid == iff->makeid('K','E','Y','F'))
        {
            if (EschKeyframeMan)
            {
                err=EschKeyframeMan->load(iff);
                if (err)
                {
                    goto error_exit;
                }
            }
        }
    }

    iff->leaveform();

    //陳 Handle hierarchy patchup, if requested
    if (hier)
    {
        int             changed;
        EschMeshDraw    *m;

        // Looping, inserting objects that have parents already in drawable
        // tree.
        for(;;)
        {
            changed=0;
            for(i=0; i < nmeshes; i++)
            {
                if (hier[i].m)
                {
                    m=(EschMeshDraw*)meshes->find(hier[i].pname);
                    if (m)
                    {
                        changed=1;
                        hier[i].m->adopt(m);
                        hier[i].m=0;
                    }
                }
            }

            if (!changed)
                break;
        }

        // See if any objects are still not attached
        for(err=ESCH_ERR_NONE, i=0; i < nmeshes; i++)
        {
            if (hier[i].m)
            {
                delete hier[i].m;
                err=ESCH_ERR_INVALIDHIER;
            }
        }

        delete [] hier;

        if (err)
            return err;
    }

    //陳 Verify counts are as expected
    if (ncams != ncameras || nmshs != nmeshes || nlgts != nlights)
        return ESCH_ERR_MISSINGITEMS;

    return ESCH_ERR_NONE;

    // Handle error return during load, must free partial data
error_exit: ;

    if (hier)
        delete [] hier;
    iff->leaveform();
    release();
    return err;
}

//葦� End of module - esscene.cpp 憶�


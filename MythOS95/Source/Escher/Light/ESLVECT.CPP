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
// esllvect.cpp
//
// The EschLight and associated classes are used for implementing the
// lighting model.  EschLights affect objects by controlling the
// shade level and potentially color of a vertex.  EschLight objects
// are maintained in a linked list.
//
// An EschVectorLight shines in a specific direction, but has no
// definitive location in 3-space.
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
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#define max(a,b)  (((a) > (b)) ? (a) : (b))

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭�  Constructors/Destructors  碓旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschVectorLight - Constructor                                            �
//                                                                          �
// Initializes the light object with full intesity and sets type.           �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschVectorLight::EschVectorLight(const char *fname, const char *lname) :
    EschLight(),
    dir(0,0,1)
{
    ltyp = ESCH_LGTT_VECTOR;
    intensity = 255;

    if (fname)
    {
        load(fname,lname);
    }
};

EschVectorLight::EschVectorLight(const EschVector *vec) :
    EschLight(),
    dir(*vec)
{
    ltyp = ESCH_LGTT_VECTOR;
    intensity = 255;

    dir.normalize();
};

EschVectorLight::EschVectorLight(float ii, float ij, float ik) :
    EschLight(),
    dir(ii,ij,ik)
{
    ltyp = ESCH_LGTT_VECTOR;
    intensity = 255;

    dir.normalize();
};



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  Operations  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschVectorLight - setup                                                  �
//                                                                          �
// Performs the setup of the light on an object by object basis.            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschVectorLight::setup(const EschFrameRef *fr)
{
    if (fr
        && EschCurrent
        && EschCurrent->camera
        && EschCurrent->camera->flags & ESCH_CAM_MODELSPACE)
    {
        dir.transform(&fr->iorient,&tdir);
        tdir = -tdir;
    }
    else
    {
        tdir = -dir;
    }

    EschLight::setup(fr);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschVectorLight - shine                                                  �
//                                                                          �
// Sets the shade level in the Van Gogh Vector based on the intesity of the �
// light and the given vertex information.                                  �
//                                                                          �
// The vector light source computes a dot product.                          �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschVectorLight::shine(const EschVertex *v, VngoPoint *vpt, int revnrml) const
{
    if (!(flags & ESCH_LGT_OFF))
    {
        // Compute dot product
        float dot = v->normal DOT tdir;

        if (dot < 0)
        {
            dot = (revnrml) ? -dot : 0;
        }

        // Compute shade level
        vpt->shade += long(dot * _intensity);
    }

//陳� Chain for true multiple lights
    if (inext)
    {
        inext->shine(v,vpt,revnrml);
    }
//陳� Clamp shade value
    else
    {
        if (vpt->shade > mp)
            vpt->shade = mp;
        else if (vpt->shade < 0)
            vpt->shade = 0;
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschPointLight - hishine                                                 �
//                                                                          �
// Sets the shade level, allowing specular highlights to overdrive the      �
// color based on the intensity of the light and the given vertex info.     �
//                                                                          �
// The vector light source computes a dot product.                          �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschVectorLight::hishine(const EschVertex *v, VngoPoint *vpt, int revnrml) const
{
    if (!(flags & ESCH_LGT_OFF))
    {
        // Compute shade value
        float dot = v->normal DOT tdir;

        if (dot < 0)
        {
            dot = (revnrml) ? -dot : 0;
        }

        // Compute shade level
        vpt->shade += long(dot * _hintensity);
    }

//陳� Chain for true multiple lights
    if (inext)
    {
        inext->hishine(v,vpt,revnrml);
    }
//陳� Clamp shade value
    else
    {
        if (vpt->shade > VNGO_SHADE_FULL)
            vpt->shade = VNGO_SHADE_FULL;
        else if (vpt->shade < 0)
            vpt->shade = 0;
    }
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  I/O Routines  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschVectorLight - load                                                   �
//                                                                          �
// Loads the position and other data of the vector light from an IFF file.  �
//                                                                          �
// The IFF version assumes that the IFF is open and Vectoring at the proper �
// chunk.  If a 'lname' is given and the name doesn't match that in the     �
// chunk, an error is returned.                                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
esch_error_codes EschVectorLight::load(const char *fname, const char *lname)
{
    esch_error_codes    err;
    XFParseIFF          iff;

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

        if (iff.chunkid == iff.makeid('E','V','E','C')
            || iff.chunkid == iff.makeid('E','V','E','1'))
        {
            err=load(&iff,lname);
            if (!err
                || err != ESCH_ERR_NOTFOUND)
                break;
        }

        // Must scan inside any ESEN Scene forms.
        else if (iff.chunkid == iff.makeid('F','O','R','M')
                 && iff.formid == iff.makeid('E','S','E','N'))
        {
            iff.enterform();
        }
    }

//陳 Return ok
    iff.close();
    return err;
}

esch_error_codes EschVectorLight::load(XFParseIFF *iff, const char *lname)
{
    assertMyth("EschVectorLight::load requries iff pointer",
               iff);

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Floating-point format
    if (iff->chunkid == iff->makeid('E','V','E','1'))
    {
        EschFileLightVect   vec;

        if (iff->chunkSize != sizeof(vec))
            return ESCH_ERR_INVALIDDATA;

        //陳 Read chunk and verify name, if given.
        if (iff->read(&vec))
            return ESCH_ERR_FILEERROR;

        if (lname && strcmp(lname,vec.name))
            return ESCH_ERR_NOTFOUND;

        //陳 Found, so setup Vector Light
        strcpy(name,vec.name);
        flags = vec.flags;

        VngoColor24bit  c(vec.color);
        set_intensity( max( max(c.r, c.g), c.b ) );

        dir.i = vec.i;
        dir.j = vec.j;
        dir.k = vec.k;
        dir.normalize();
    }
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Fixed-point format
    else if (iff->chunkid == iff->makeid('E','V','E','C'))
    {
        EschFileLightVectV1   vec;

        if (iff->chunkSize != sizeof(vec))
            return ESCH_ERR_INVALIDDATA;

        //陳 Read chunk and verify name, if given.
        if (iff->read(&vec))
            return ESCH_ERR_FILEERROR;

        if (lname && strcmp(lname,vec.name))
            return ESCH_ERR_NOTFOUND;

        //陳 Found, so setup Vector Light
        strcpy(name,vec.name);
        flags = vec.flags;

        VngoColor24bit  c(vec.color);
        set_intensity( max( max(c.r, c.g), c.b ) );

        dir.i = vec.i / 65536.0f;
        dir.j = vec.j / 65536.0f;
        dir.k = vec.k / 65536.0f;
        dir.normalize();
    }
    else
    {
        return ESCH_ERR_NOTFOUND;
    }

//陳 Return ok
    return ESCH_ERR_NONE;
}

//葦� End of module - eslvect.cpp 憶�


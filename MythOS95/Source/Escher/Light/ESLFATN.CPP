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
// eslfatn.cpp
//
// The EschLight and associated classes are used for implementing the
// lighting model.  EschLights affect objects by controlling the
// shade level and potentially color of a vertex.  EschLight objects
// are maintained in a linked list.
//
// An EschFastAttenLight is an approximation of point sources in
// 3-space using the target frame-reference to form a 'local' vector source
// with intensity attenuated by distance.
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
// EschFastAttenLight - Constructor                                         �
//                                                                          �
// Initializes the light object with full intesity and sets type.           �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschFastAttenLight::EschFastAttenLight(const char *fname, const char *lname) :
    EschFastPointLight(),
    inner(0),
    outer(0x1000)
{
    ltyp = ESCH_LGTT_FATTEN;
    flags |= ESCH_LGT_ATTEN;

    if (fname)
    {
        load(fname,lname);
    }
};

EschFastAttenLight::EschFastAttenLight(const EschPoint *pnt, float i, float o) :
    EschFastPointLight(pnt),
    inner(i),
    outer(o)
{
    ltyp = ESCH_LGTT_FATTEN;
    flags |= ESCH_LGT_ATTEN;
};

EschFastAttenLight::EschFastAttenLight(float ix, float iy, float iz,
                                       float i, float o) :
    EschFastPointLight(ix,iy,iz),
    inner(i),
    outer(o)
{
    ltyp = ESCH_LGTT_FATTEN;
    flags |= ESCH_LGT_ATTEN;
};



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  Operations  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschFastAttenLight - setup                                               �
//                                                                          �
// Performs the setup of the light on an object by object basis.            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschFastAttenLight::setup(const EschFrameRef *fr)
{
    if (fr)
    {
        EschPoint   tpnt;

        if (EschCurrent
            && EschCurrent->camera
            && EschCurrent->camera->flags & ESCH_CAM_MODELSPACE)
        {
            pos.transform(&fr->iorient,&tpnt);
            tdir.i = tpnt.x;
            tdir.j = tpnt.y;
            tdir.k = tpnt.z;
        }
        else
        {
            fr->get_position(&tpnt);
            tdir.i = pos.x - tpnt.x;
            tdir.j = pos.y - tpnt.y;
            tdir.k = pos.z - tpnt.z;
        }
    }
    else
    {
        // If there is no reference, we assume the object is at 0,0,0
        // since we have no other valid interpretation

        tdir.i = pos.x;
        tdir.j = pos.y;
        tdir.k = pos.z;
    }

    EschLight::setup(fr);

    float mag = tdir.magnitude();
    if (mag >= outer)
    {
        _intensity = 0;
        _hintensity = 0;
    }
    else
    {
        // Complete normalization
        if (mag > 0)
        {
            tdir.i /= mag;
            tdir.j /= mag;
            tdir.k /= mag;
        }

        // Attenuate intensity, if allowed
        if ((flags & ESCH_LGT_ATTEN)
            && (outer-inner) > 0
            && (mag > inner))
        {
            _intensity -=  ((mag - inner) * _intensity) / (outer - inner);
            _hintensity -= ((mag - inner) * _hintensity) / (outer - inner);
        }
    }
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  I/O Routines  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschFastAttenLight - load                                                �
//                                                                          �
// Loads the position and other data of the fast atten light from an IFF    �
// file.                                                                    �
//                                                                          �
// The IFF version assumes that the IFF is open and pointing at the proper  �
// chunk.  If a 'lname' is given and the name doesn't match that in the     �
// chunk, an error is returned.                                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
esch_error_codes EschFastAttenLight::load(const char *fname, const char *lname)
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

        if (iff.chunkid == iff.makeid('E','F','A','T')
            || iff.chunkid == iff.makeid('E','F','A','1'))
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

esch_error_codes EschFastAttenLight::load(XFParseIFF *iff, const char *lname)
{
    assertMyth("EschFastAttenLight::load requries iff pointer",
               iff);

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Floating-point format
    if (iff->chunkid == iff->makeid('E','F','A','1'))
    {
        EschFileLightAtten fatn;

        if (iff->chunkSize != sizeof(fatn))
            return ESCH_ERR_INVALIDDATA;

        //陳 Read chunk and verify name, if given.
        if (iff->read(&fatn))
            return ESCH_ERR_FILEERROR;

        if (lname && strcmp(lname,fatn.name))
            return ESCH_ERR_NOTFOUND;

        //陳 Found, so setup Fast Atten Light
        strcpy(name,fatn.name);
        flags = fatn.flags;

        VngoColor24bit  c(fatn.color);
        set_intensity( max( max(c.r, c.g), c.b ) );

        set_position(fatn.x,fatn.y,fatn.z);

        set_inner( fatn.inner );
        set_outer( fatn.outer );
    }
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Fixed-point format
    else if (iff->chunkid == iff->makeid('E','F','A','T'))
    {
        EschFileLightAttenV1 fatn;

        if (iff->chunkSize != sizeof(fatn))
            return ESCH_ERR_INVALIDDATA;

        //陳 Read chunk and verify name, if given.
        if (iff->read(&fatn))
            return ESCH_ERR_FILEERROR;

        if (lname && strcmp(lname,fatn.name))
            return ESCH_ERR_NOTFOUND;

        //陳 Found, so setup Fast Atten Light
        strcpy(name,fatn.name);
        flags = fatn.flags;

        VngoColor24bit  c(fatn.color);
        set_intensity( max( max(c.r, c.g), c.b ) );

        set_position(fatn.x / 65536.0f,fatn.y / 65536.0f,fatn.z / 65536.0f);

        set_inner( fatn.inner / 65536.0f );
        set_outer( fatn.outer / 65536.0f );
    }
    else
    {
        return ESCH_ERR_NOTFOUND;
    }

//陳 Return ok
    return ESCH_ERR_NONE;
}

//葦� End of module - eslfatn.cpp 憶�


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
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//                                
//���������������������������������������������������������������������������

#include "escher.hpp"
#include "esfile.hpp"

//���������������������������������������������������������������������������
//
//                                Equates
//
//���������������������������������������������������������������������������

#define max(a,b)  (((a) > (b)) ? (a) : (b))

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//�����������������������  Constructors/Destructors  ������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschFastAttenLight - Constructor                                         �
//                                                                          �
// Initializes the light object with full intesity and sets type.           �
//���������������������������������������������������������������������������
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

EschFastAttenLight::EschFastAttenLight(const EschPoint *pnt, Flx16 i, Flx16 o) :
    EschFastPointLight(pnt),
    inner(i),
    outer(o)
{
    ltyp = ESCH_LGTT_FATTEN;
    flags |= ESCH_LGT_ATTEN;
};

EschFastAttenLight::EschFastAttenLight(Flx16 ix, Flx16 iy, Flx16 iz,
                                       Flx16 i, Flx16 o) : 
    EschFastPointLight(ix,iy,iz),
    inner(i),
    outer(o)
{
    ltyp = ESCH_LGTT_FATTEN;
    flags |= ESCH_LGT_ATTEN;
};



//���������������������������������������������������������������������������
//�����������������������������  Operations  ��������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschFastAttenLight - setup                                               �
//                                                                          �
// Performs the setup of the light on an object by object basis.            �
//���������������������������������������������������������������������������
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

    Flx16 mag = tdir.magnitude();
    if (mag.flx >= outer.flx)
    {
        _intensity = 0;
        _hintensity = 0;
    }
    else
    {
        // Complete normalization
        if (mag.flx > 0)
        {
            tdir.i /= mag;
            tdir.j /= mag;
            tdir.k /= mag;
        }

        // Attenuate intensity, if allowed
        if ((flags & ESCH_LGT_ATTEN)
            && (outer-inner).flx > 0
            && (mag.flx > inner.flx))
        {
            _intensity -= flx_muldiv( (mag - inner), _intensity, (outer - inner) );
            _hintensity -= flx_muldiv( (mag - inner), _hintensity, (outer - inner) );
        }
    }
}



//���������������������������������������������������������������������������
//�����������������������������  I/O Routines  ������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschFastAttenLight - load                                                �
//                                                                          �
// Loads the position and other data of the fast atten light from an IFF    �
// file.                                                                    �
//                                                                          �
// The IFF version assumes that the IFF is open and pointing at the proper  �
// chunk.  If a 'lname' is given and the name doesn't match that in the     �
// chunk, an error is returned.                                             �
//���������������������������������������������������������������������������
esch_error_codes EschFastAttenLight::load(const char *fname, const char *lname)
{
    esch_error_codes    err;
    XFParseIFF          iff;

//�� Open file
    if (iff.open(fname,XF_OPEN_READ))
        return ESCH_ERR_FILEERROR;

//�� Loop until a header with the correct name is found
    err=ESCH_ERR_NONE;

    for(;;)
    {
        if (iff.next() != XF_ERR_NONE)
        {
            if (!iff.depth)
                return ESCH_ERR_NOTFOUND;
            iff.leaveform();
        }

        if (iff.chunkid == iff.makeid('E','F','A','T'))
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

//�� Return ok
    iff.close();
    return err;
}

esch_error_codes EschFastAttenLight::load(XFParseIFF *iff, const char *lname)
{
    EschFileLightAtten fatn;

    assertMyth("EschFastAttenLight::load requries iff pointer",
               iff);

//�� Verify correct chunk name and size
    if (iff->chunkid != iff->makeid('E','F','A','T'))
        return ESCH_ERR_NOTFOUND;

    if (iff->chunkSize != sizeof(EschFileLightAtten))
        return ESCH_ERR_INVALIDDATA;

//�� Read chunk and verify name, if given.
    if (iff->read(&fatn))
        return ESCH_ERR_FILEERROR;

    if (lname && strcmp(lname,fatn.name))
        return ESCH_ERR_NOTFOUND;

//�� Found, so setup Fast Atten Light

    strcpy(name,fatn.name);
    flags = fatn.flags;

    VngoColor24bit  c(fatn.color);
    set_intensity( max( max(c.r, c.g), c.b ) );

    set_position(fatn.x,fatn.y,fatn.z);

    set_inner( fatn.inner );
    set_outer( fatn.outer );

//�� Return ok
    return ESCH_ERR_NONE;
}

//��� End of module - eslfatn.cpp ���

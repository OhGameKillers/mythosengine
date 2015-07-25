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
// eslpoint.cpp
//
// The EschLight and associated classes are used for implementing the
// lighting model.  EschLights affect objects by controlling the
// shade level and potentially color of a vertex.  EschLight objects
// are maintained in a linked list.
//
// An EschPointLight shines in all directions equally, but has a specific
// location in 3-space.
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
// EschPointLight - Constructor                                             �
//                                                                          �
// Initializes the light object with full intesity and sets type.           �
//���������������������������������������������������������������������������
EschPointLight::EschPointLight(const char *fname, const char *lname) :
    EschLight(),
    pos(0,0,0)
{
    ltyp = ESCH_LGTT_POINT;
    intensity = 255;

    if (fname)
    {
        load(fname,lname);
    }
};

EschPointLight::EschPointLight(const EschPoint *pnt) :
    EschLight(),
    pos(*pnt)
{
    ltyp = ESCH_LGTT_POINT;
    intensity = 255;
};

EschPointLight::EschPointLight(Flx16 ix, Flx16 iy, Flx16 iz) : 
    EschLight(),
    pos(ix,iy,iz)
{
    ltyp = ESCH_LGTT_POINT;
    intensity = 255;
};



//���������������������������������������������������������������������������
//�����������������������������  Operations  ��������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschPointLight - setup                                                   �
//                                                                          �
// Performs the setup of the light on an object by object basis.            �
//���������������������������������������������������������������������������
void EschPointLight::setup(const EschFrameRef *fr)
{
    if (fr
        && EschCurrent
        && EschCurrent->camera
        && EschCurrent->camera->flags & ESCH_CAM_MODELSPACE)
    {
        pos.transform(&fr->iorient,&tpos);
    }
    else
    {
        tpos = pos;
    }

    EschLight::setup(fr);
}


//�������������������������������������������������������������������������Ŀ
// EschPointLight - shine                                                   �
//                                                                          �
// Sets the shade level in the Van Gogh point based on the intesity of the  �
// light and the given vertex information.                                  �
//                                                                          �
// The point light source computes a direction vector relative to the       �
// vertex and then computes a dot product.                                  �
//���������������������������������������������������������������������������
void EschPointLight::shine(const EschVertex *v, VngoPoint *vpt, int revnrml) const 
{
    if (!(flags & ESCH_LGT_OFF))
    {
        // Compute point source lighting vector
        EschVector vtx(tpos.x - v->x,
                       tpos.y - v->y,
                       tpos.z - v->z);
        vtx.normalize();
        
        // Compute dot product
        Flx16 dot = v->normal DOT vtx;

        if (dot.flx < 0)
        {
            dot.flx = (revnrml) ? -dot.flx : 0;
        }
        
        if (dot.flx > (1<<16))
            dot.flx = (1<<16);
        
        // Compute shade value
        long i = (dot.flx * (_intensity.flx >> 16)) >> 16;
        if (vpt->shade < i)
            vpt->shade = i;
    }

//��� Chain for true multiple lights
    if (inext)
        inext->shine(v,vpt,revnrml);
}


//�������������������������������������������������������������������������Ŀ
// EschPointLight - hishine                                                 �
//                                                                          �
// Sets the shade level, allowing specular highlights to overdrive the      �
// color based on the intensity of the light and the given vertex info.     �
//                                                                          �
// The point light source computes a direction vector relative to the       �
// vertex and then computes a dot product.                                  �
//���������������������������������������������������������������������������
void EschPointLight::hishine(const EschVertex *v, VngoPoint *vpt, int revnrml) const 
{                                                           
    if (!(flags & ESCH_LGT_OFF))
    {
        // Compute point source lighting vector
        EschVector vtx(tpos.x - v->x,
                       tpos.y - v->y,
                       tpos.z - v->z);
        vtx.normalize();

        // Compute dot product
        Flx16 dot = v->normal DOT vtx;

        if (dot.flx < 0)
        {
            dot.flx = (revnrml) ? -dot.flx : 0;
        }

        if (dot.flx > (1<<16))
            dot.flx = (1<<16);
        
        // Compute shade value
        long i = (dot.flx * (_hintensity.flx >> 16)) >> 16;
        if (vpt->shade < i)
            vpt->shade = i;
    }

//��� Chain for true multiple lights
    if (inext)
        inext->hishine(v,vpt,revnrml);
}



//���������������������������������������������������������������������������
//�����������������������������  I/O Routines  ������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschPointLight - load                                                    �
//                                                                          �
// Loads the position and other data of the point light from an IFF file.   �
//                                                                          �
// The IFF version assumes that the IFF is open and pointing at the proper  �
// chunk.  If a 'lname' is given and the name doesn't match that in the     �
// chunk, an error is returned.                                             �
//���������������������������������������������������������������������������
esch_error_codes EschPointLight::load(const char *fname, const char *lname)
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

        if (iff.chunkid == iff.makeid('E','P','N','T'))
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

esch_error_codes EschPointLight::load(XFParseIFF *iff, const char *lname)
{
    EschFileLightPoint  pnt;

    assertMyth("EschPointLight::load requries iff pointer",
               iff);

//�� Verify correct chunk name and size
    if (iff->chunkid != iff->makeid('E','P','N','T'))
        return ESCH_ERR_NOTFOUND;

    if (iff->chunkSize != sizeof(EschFileLightPoint))
        return ESCH_ERR_INVALIDDATA;

//�� Read chunk and verify name, if given.
    if (iff->read(&pnt))
        return ESCH_ERR_FILEERROR;

    if (lname && strcmp(lname,pnt.name))
        return ESCH_ERR_NOTFOUND;

//�� Found, so setup Point Light

    strcpy(name,pnt.name);
    flags = pnt.flags;

    VngoColor24bit  c(pnt.color);
    set_intensity( max( max(c.r, c.g), c.b ) );

    set_position( pnt.x, pnt.y, pnt.z );

//�� Return ok
    return ESCH_ERR_NONE;
}

//��� End of module - eslpoint.cpp ���

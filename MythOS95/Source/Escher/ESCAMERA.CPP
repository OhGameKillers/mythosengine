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
// escamera.cpp
//
// The EschCamera class is the information class for the viewing of
// the drawable objects.  The EschCamera has associated viewing
// parameters to provide the needed transformation information.
// EschCameras can be linked into lists and loaded from files.
//
// A Van Gogh viewport is required for the camera to operate, so
// one should be created and attached to the camera.  The camera
// can only be attached to a single Van Gogh viewport at any given
// time.
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
// EschCamera - Constructor                                                 �
//                                                                          �
// Initializes the camera object, attaching the Van Gogh viewport, if       �
// given -or- loads the camera from the given file/name.                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschCamera::EschCamera(VngoVport *vp) :
    iprev(0),
    inext(0),
    flags(0),
    vport(0),
    aspect_ratio(1.0),
    bcolor(0),
    app_data(0)
{
    strcpy(name,EschNoName);

//陳� Default camera parameters 陳�
    reset();

    if (vp)
        attach(vp);
};

EschCamera::EschCamera(const char *fname, const char *cname) :
    iprev(0),
    inext(0),
    flags(0),
    vport(0),
    aspect_ratio(1.0),
    factor(1.0),
    hither(1.0),
    yon(4096.0),
    width(100.0),
    height(0),
    bcolor(0),
    app_data(0)
{
    strncpy(name,cname ? cname : EschNoName,ESCH_MAX_NAME);

    if (load(fname,cname))
        reset();
};

EschCamera::EschCamera(const EschCamera &cam) :
    iprev(0),
    inext(0),
    eye(cam.eye),
    top(cam.top),
    flags(cam.flags),
    vport(cam.vport),
    xscalar(cam.xscalar),
    yscalar(cam.yscalar),
    xsize(cam.xsize),
    ysize(cam.ysize),
    aspect_ratio(cam.aspect_ratio),
    factor(cam.factor),
    hither(cam.hither),
    yon(cam.yon),
    fov(cam.fov),
    width(cam.width),
    height(cam.height),
    bcolor(cam.bcolor),
    radius_factor(cam.radius_factor),
    z_factor(cam.z_factor),
    app_data(cam.app_data)
{
    strncpy(name,cam.name,ESCH_MAX_NAME);
    memcpy(&frustrum,&cam.frustrum,sizeof(frustrum));
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschCamera - Destructor                                                  �
//                                                                          �
// Ensure the camera is removed from any list it is linked into.            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschCamera::~EschCamera()
{
    remove();
};



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  Operations  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschCamera - operator =                                                  �
//                                                                          �
// Copies the data from another camera.                                     �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
const EschCamera &EschCamera::operator = (const EschCamera &cam)
{
    if (this != &cam)
    {
        eye = cam.eye;
        top = cam.top;
        flags = cam.flags;
        vport = cam.vport;
        xscalar = cam.xscalar;
        yscalar = cam.yscalar;
        xsize = cam.xsize;
        ysize = cam.ysize;
        aspect_ratio = cam.aspect_ratio;
        factor = cam.factor;
        hither = cam.hither;
        yon = cam.yon;
        fov = cam.fov;
        width = cam.width;
        height = cam.height;
        bcolor = cam.bcolor;
        radius_factor = cam.radius_factor;
        z_factor = cam.z_factor;
        strncpy(name,cam.name,ESCH_MAX_NAME);
        memcpy(&frustrum,&cam.frustrum,sizeof(frustrum));
        app_data = cam.app_data;
    }
    return *this;
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschCamera - attach                                                      �
//                                                                          �
// Attaches the camera to a Van Gogh viewport.  This sets the internal      �
// viewport pointer and calls the scalar compute function.                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschCamera::attach(VngoVport *vp)
{
    vport=vp;

    if (!vp)
        return;

    if (vp->vflags & VNGO_ZBUFFER_DEV)
        flags &= ~ESCH_CAM_SORT;
    else
        flags |= ESCH_CAM_SORT;

    compute_scalar();
    compute_frustrum();
    compute_z_factor();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschCamera - sibling                                                     �
//                                                                          �
// Makes the camera a sibling of the 'myprev.' object.  This assumes that   �
// the object is not currently attached to anything.                        �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschCamera::sibling(EschCamera *myprev)
{
    assertMyth("EschCamera::sibling must have myprev",
               myprev);

    assertMyth("EschCamera::sibling requires that object not already be in a list",
               inext == 0 && iprev == 0);

    iprev=myprev;
    inext=myprev->inext;

    myprev->inext = this;
    if (inext)
        inext->iprev = this;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschCamera - remove                                                      �
//                                                                          �
// Removes the camera from the list of cameras.                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschCamera::remove()
{
    if (iprev)
    {
        iprev->inext = inext;
    }

    if (inext)
    {
        inext->iprev = iprev;
    }

    inext=0;
    iprev=0;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschCamera - find                                                        �
//                                                                          �
// Searches the siblings of the given camera and returns the camera object  �
// with the given name, or 0 if not found.                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschCamera *EschCamera::find(const char *cname) const
{
    if (!cname)
        return 0;

    if (!strncmp(cname,name,ESCH_MAX_NAME))
        return (EschCamera*)this;

    if (!inext)
        return 0;

    return inext->find(cname);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschCamera - pre_rend                                                    �
//                                                                          �
// Prepares a render, returning a 0 on success or non-zero otherwise.       �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int EschCamera::pre_rend()
{
    flags &= ~ESCH_CAM_VPWASLOCKED;

    if (!vport)
        return 1;

//陳� Lock viewport (save old state)
    int waslocked = vport->lock();

        if (waslocked == -1)
                return 1;

    if (waslocked)
        flags |= ESCH_CAM_VPWASLOCKED;

//陳� Clear viewport/reset z-buffer
    if (!(flags & ESCH_CAM_NOCLEAR))
    {
        vport->clear_screen_on();
        vport->reset(bcolor);
    }

    return 0;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschCamera - rend                                                        �
//                                                                          �
// Renders the current context to the camera, assuming a successful pre_rend�
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschCamera::rend()
{
    EschDrawable    *ptr;

//陳� Draw list of EschDrawables
    for(ptr=EschCurrent->eschs; ptr != NULL; ptr = ptr->next())
    {
        if (!(ptr->flags & ESCH_DRW_SKIP))
            ptr->draw();
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschCamera - post_rend                                                   �
//                                                                          �
// Performs post render processing.                                         �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschCamera::post_rend()
{
//陳� Flush element buffer (if not forcing skip of this step)
    if (!(flags & ESCH_CAM_NOFLUSH))
    {
        if (flags & ESCH_CAM_TRUESORT)
            EschElement::flush_truesort();
        else
            EschElement::flush();
    }

//陳� Unlock (if old state was unlocked)
    if (!(flags & ESCH_CAM_VPWASLOCKED))
        vport->unlock();

    flags &= ~ESCH_CAM_VPWASLOCKED;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschCamera - reset                                                       �
//                                                                          �
// Sets the camera up to default parameters.                                �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschCamera::reset()
{
//陳� Default camera parameters 陳�
    eye.set_position(0.0,0.0,0.0);

    eye.dir.i = 0.0;                        // Looking down positive Z.
    eye.dir.j = 0.0;
    eye.dir.k = 1.0;

    top.i=0.0;                              // Head is positive Y.
    top.j=1.0;
    top.k=0.0;

    hither=1.0;                             // Arbitrary start values.
    yon=4096.0;

    fov=48.0;                               // Default used by 3DS, so why not?

    width=100.0;
    height=0;

    factor=1.0;                             // No user zoom factor by default.


//陳� Call computation functions
    compute_scalar();
    compute_frustrum();
    compute_z_factor();
    compute_eye();
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭�  Utility Routines  碓旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschCamera - set_top                                                     �
//                                                                          �
// Sets the camera based on a new top vector.                               �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschCamera::set_top(const EschVector *t, dword update)
{
    top=*t;
    top.normalize();

//陳� Call computation function
    if (update & ESCH_UPD_ORTHO)
        orthogonalize(update);
    else if (update & ESCH_UPD_EYE)
        compute_eye(update);
}

void EschCamera::set_top(const float ii, const float ij, const float ik,
                         dword update)
{
    top.i=ii;
    top.j=ij;
    top.k=ik;
    top.normalize();

//陳� Call computation function
    if (update & ESCH_UPD_ORTHO)
        orthogonalize(update);
    else if (update & ESCH_UPD_EYE)
        compute_eye(update);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschCamera - set_top                                                     �
//                                                                          �
// Sets the camera based on a new direction vector.                         �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschCamera::set_dir(const EschVector *d, dword update)
{
    eye.dir=*d;
    eye.dir.normalize();

//陳� Call computation function
    if (update & ESCH_UPD_ORTHO)
        orthogonalize(update);
    else if (update & ESCH_UPD_EYE)
        compute_eye(update);
}

void EschCamera::set_dir(const float ii, const float ij, const float ik,
                         dword update)
{
    eye.dir.i=ii;
    eye.dir.j=ij;
    eye.dir.k=ik;
    eye.dir.normalize();

//陳� Call computation function
    if (update & ESCH_UPD_ORTHO)
        orthogonalize(update);
    else if (update & ESCH_UPD_EYE)
        compute_eye(update);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschCamera - set_vects                                                   �
//                                                                          �
// Sets the camera based on new direction and top vectors.                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschCamera::set_vects(const EschVector *t, const EschVector *d,
                           dword update)
{
    top=*t;
    top.normalize();

    eye.dir=*d;
    eye.dir.normalize();

//陳� Call computation function
    if (update & ESCH_UPD_ORTHO)
        orthogonalize(update);
    else if (update & ESCH_UPD_EYE)
        compute_eye(update);
}

void EschCamera::set_vects(const float ti, const float tj, const float tk,
                           const float di, const float dj, const float dk,
                           dword update)
{
    top.i = ti;
    top.j = tj;
    top.k = tk;
    top.normalize();

    eye.dir.i = di;
    eye.dir.j = dj;
    eye.dir.k = dk;
    eye.dir.normalize();

//陳� Call computation function
    if (update & ESCH_UPD_ORTHO)
        orthogonalize(update);
    else if (update & ESCH_UPD_EYE)
        compute_eye(update);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschCamera - set_lookat                                                  �
//                                                                          �
// Sets the direction and top vector based on a look-at point.              �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschCamera::set_lookat(const EschPoint *pt, dword update)
{
    EschPoint   pos;

    get_position(&pos);

//陳� Determine direction from lookat point and position
    eye.dir.i = pt->x - pos.x;
    eye.dir.j = pt->y - pos.y;
    eye.dir.k = pt->z - pos.z;
    eye.dir.normalize();

//陳� Call orthogonalize function
    if (update & ESCH_UPD_ORTHO)
        orthogonalize(update);
    else if (update & ESCH_UPD_EYE)
        compute_eye(update);
}

void EschCamera::set_lookat(const float ix, const float iy, const float iz,
                            dword update)
{
    EschPoint   pos;

    get_position(&pos);

//陳� Determine direction from lookat point and position
    eye.dir.i = ix - pos.x;
    eye.dir.j = iy - pos.y;
    eye.dir.k = iz - pos.z;
    eye.dir.normalize();

//陳� Call orthogonalize function
    if (update & ESCH_UPD_ORTHO)
        orthogonalize(update);
    else if (update & ESCH_UPD_EYE)
        compute_eye(update);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschCamera - rotatex                                                     �
//                                                                          �
// Addes a rotation of 'degrees' degrees to the frame of reference about the�
// X-axis.                                                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschCamera::rotatex(const float degrees, dword update)
{
    eye.rotatex(degrees,update & ~ESCH_UPD_ORTHO);

    if ((update & ESCH_UPD_ORTHO) && (eye.ortho_count > ESCH_MAX_ORTHOCOUNT))
    {
        orthogonalize(update);
    }

//陳� Update top vector
    top.i = eye.orient.mtx[ESCH_MTX_D];
    top.j = eye.orient.mtx[ESCH_MTX_E];
    top.k = eye.orient.mtx[ESCH_MTX_F];
    top.normalize();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschCamera - rotatey                                                     �
//                                                                          �
// Addes a rotation of 'degrees' degrees to the frame of reference about the�
// Y-axis.                                                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschCamera::rotatey(const float degrees, dword update)
{
    eye.rotatey(degrees,update & ~ESCH_UPD_ORTHO);

    if ((update & ESCH_UPD_ORTHO) && (eye.ortho_count > ESCH_MAX_ORTHOCOUNT))
    {
        orthogonalize(update);
    }

//陳� Update top vector
    top.i = eye.orient.mtx[ESCH_MTX_D];
    top.j = eye.orient.mtx[ESCH_MTX_E];
    top.k = eye.orient.mtx[ESCH_MTX_F];
    top.normalize();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschCamera - rotatez                                                     �
//                                                                          �
// Addes a rotation of 'degrees' degrees to the frame of reference about the�
// Z-axis.                                                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschCamera::rotatez(const float degrees, dword update)
{
    eye.rotatez(degrees,update & ~ESCH_UPD_ORTHO);

    if ((update & ESCH_UPD_ORTHO) && (eye.ortho_count > ESCH_MAX_ORTHOCOUNT))
    {
        orthogonalize(update);
    }

//陳� Update top vector
    top.i = eye.orient.mtx[ESCH_MTX_D];
    top.j = eye.orient.mtx[ESCH_MTX_E];
    top.k = eye.orient.mtx[ESCH_MTX_F];
    top.normalize();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschCamera - pitch                                                       �
//                                                                          �
// Addes a rotation of 'degrees' degrees to the frame of reference about the�
// relative X-axis.                                                         �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschCamera::pitch(const float degrees, dword update)
{
    eye.pitch(degrees,update & ~ESCH_UPD_ORTHO);

    if ((update & ESCH_UPD_ORTHO) && (eye.ortho_count > ESCH_MAX_ORTHOCOUNT))
    {
        orthogonalize(update);
    }

//陳� Update top vector
    top.i = eye.orient.mtx[ESCH_MTX_D];
    top.j = eye.orient.mtx[ESCH_MTX_E];
    top.k = eye.orient.mtx[ESCH_MTX_F];
    top.normalize();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschCamera - yaw                                                         �
//                                                                          �
// Addes a rotation of 'degrees' degrees to the frame of reference about the�
// relative Y-axis.                                                         �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschCamera::yaw(const float degrees, dword update)
{
    eye.yaw(degrees,update & ~ESCH_UPD_ORTHO);

    if ((update & ESCH_UPD_ORTHO) && (eye.ortho_count > ESCH_MAX_ORTHOCOUNT))
    {
        orthogonalize(update);
    }

//陳� Update top vector
    top.i = eye.orient.mtx[ESCH_MTX_D];
    top.j = eye.orient.mtx[ESCH_MTX_E];
    top.k = eye.orient.mtx[ESCH_MTX_F];
    top.normalize();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschCamera - roll                                                        �
//                                                                          �
// Addes a rotation of 'degrees' degrees to the frame of reference about the�
// relative Z-axis.                                                         �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschCamera::roll(const float degrees, dword update)
{
    eye.roll(degrees,update & ~ESCH_UPD_ORTHO);

    if ((update & ESCH_UPD_ORTHO) && (eye.ortho_count > ESCH_MAX_ORTHOCOUNT))
    {
        orthogonalize(update);
    }

//陳� Update top vector
    top.i = eye.orient.mtx[ESCH_MTX_D];
    top.j = eye.orient.mtx[ESCH_MTX_E];
    top.k = eye.orient.mtx[ESCH_MTX_F];
    top.normalize();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschCamera - orthogonalize                                               �
//                                                                          �
// Ensures that the matrix is an orthonormal basis, ensuring that no        �
// undesired scaling or shearing occurrs due to accumulated error in updates�
// from rotations, using the direction as the first basis.                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschCamera::orthogonalize(dword update)
{
    eye.ortho_count=0;

    eye.dir.normalize();

    float dot = top DOT eye.dir;

    top.i = top.i - (eye.dir.i * dot);
    top.j = top.j - (eye.dir.j * dot);
    top.k = top.k - (eye.dir.k * dot);
    top.normalize();

    if (update & ESCH_UPD_EYE)
        compute_eye(update);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschCamera - orthogonalize_top                                           �
//                                                                          �
// Ensures that the matrix is an orthonormal basis, ensuring that no        �
// undesired scaling or shearing occurrs due to accumulated error in updates�
// from rotations, using the top vector as the first basis.                 �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschCamera::orthogonalize_top(dword update)
{
    eye.ortho_count=0;

    top.normalize();

    float dot = top DOT eye.dir;

    eye.dir.i = eye.dir.i - (top.i * dot);
    eye.dir.j = eye.dir.j - (top.j * dot);
    eye.dir.k = eye.dir.k - (top.k * dot);
    eye.dir.normalize();

    if (update & ESCH_UPD_EYE)
        compute_eye(update);
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭�  Compute Functions  碓旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschCamera - compute_scalar                                              �
//                                                                          �
// Recomputes the xsize, ysize, xscalar, yscalar, and radius_factor from    �
// the aspect_ratio, viewport dimensions, and either the field-of-view      �
// for perspective cameras or the width and height for orthogonal cameras.  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschCamera::compute_scalar()
{
    if (!vport)
        return;

    assertMyth("EschCamera::compute_scalar requires factor > 0",
                factor > 0);

//陳� Orthographic projection
    if (flags & ESCH_CAM_ORTHO)
    {
        float hw, hh;

        assertMyth("EschCamera::compute_scalar needs valid width and height",
                   width > 0 && height >= 0);

        hw = float((width + vport->skips_last_pix()) / 2.0f);
        hh = float((height + vport->skips_last_pix()) / 2.0f);

        radius_factor = factor;

        //陳� Set projection size based on factor & width/height
        //陳� (a 0 height means set based on aspect-ratio)

        xsize = hw / factor;

        if (height > 0.0)
            ysize = hh / factor;
        else
            ysize = ((xsize * float(vport->vbuff.height + vport->skips_last_pix()))
                    / float(vport->vbuff.width + vport->skips_last_pix()))
                    * aspect_ratio;

        //陳� Compute scalar values for X and Y to get pixel locations.
        xscalar = (float((vport->vbuff.width + vport->skips_last_pix()) / 2.f) * factor) / hw;

        if (height > 0.0)
            yscalar = (float((vport->vbuff.height + vport->skips_last_pix()) / 2.f) * factor) / hh;
        else
            yscalar = xscalar / aspect_ratio;
    }
//陳� Perspective projection
    else
    {
        assertMyth("EschCamera::compute_scalar only allows 1 <= fov <= 175",
                   ((fov >= 1) && (fov <= 175)));

        // angle is fov / 2
        float angle = fov / 2.0f;

        // Save off radius factor.
        radius_factor = factor / esch_cos(angle);

        //陳� Compute 1/2 size of projection-plane from FOV angle
        //
        //                         /|
        //                        / |
        //                       /  |
        //                      /   | 1/2 size projection plane (unknown)
        //                     /    |
        //        1/2 of FOV  /     |
        //         is this   *______|
        //          angle      ^
        //                     | Projection-plane distance (always 1)
        //

        float size = esch_sin(angle) / esch_cos(angle);

        assertMyth("EschCamera::compute_scalar requires FOV to result in non-zero size",
                   size != 0);

        //陳� Save 1/2 size of projection-plane in X and compute Y.
        xsize = size / factor;
        ysize = ((xsize * float(vport->vbuff.height + vport->skips_last_pix()) )
                / float(vport->vbuff.width + vport->skips_last_pix()))
                * aspect_ratio;

        //陳� Compute scalar values for X and Y to get pixel locations.
        xscalar = ((float(vport->vbuff.width + vport->skips_last_pix()) / 2.f) * factor) / size;
        yscalar = xscalar / aspect_ratio;
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschCamera - compute_frustrum                                            �
//                                                                          �
// Recomputes the planes for the view frustrum, which are used for 3D       �
// clipping.  This routine depends on xsize/ysize computed by               �
// compute_scalar()                                                         �
//                                                                          �
// The distances are pre-negated for faster processing in the clipping code!�
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
#define EPSILON     0.001f

void EschCamera::compute_frustrum()
{
//陳� Orthographic projection
    if (flags & ESCH_CAM_ORTHO)
    {
        // Left
        frustrum[ESCH_CAM_FRUSTRUM_LEFT].normal.i = 1;
        frustrum[ESCH_CAM_FRUSTRUM_LEFT].normal.j = 0;
        frustrum[ESCH_CAM_FRUSTRUM_LEFT].normal.k = 0;
        frustrum[ESCH_CAM_FRUSTRUM_LEFT].dist = -xsize;

        // Right
        frustrum[ESCH_CAM_FRUSTRUM_RIGHT].normal.i = -1;
        frustrum[ESCH_CAM_FRUSTRUM_RIGHT].normal.j = 0;
        frustrum[ESCH_CAM_FRUSTRUM_RIGHT].normal.k = 0;
        frustrum[ESCH_CAM_FRUSTRUM_RIGHT].dist = -xsize;

        // Top
        frustrum[ESCH_CAM_FRUSTRUM_TOP].normal.i = 0;
        frustrum[ESCH_CAM_FRUSTRUM_TOP].normal.j = -1;
        frustrum[ESCH_CAM_FRUSTRUM_TOP].normal.k = 0;
        frustrum[ESCH_CAM_FRUSTRUM_TOP].dist = -ysize;

        // Bottom
        frustrum[ESCH_CAM_FRUSTRUM_BOTTOM].normal.i = 0;
        frustrum[ESCH_CAM_FRUSTRUM_BOTTOM].normal.j = 1;
        frustrum[ESCH_CAM_FRUSTRUM_BOTTOM].normal.k = 0;
        frustrum[ESCH_CAM_FRUSTRUM_BOTTOM].dist = -ysize;
    }
//陳� Perspective projection
    else
    {
        float   xangle = esch_atan(xsize);
        float   yangle = esch_atan(ysize);

        xangle = (90.0f - xangle);  // Get the perpendicular to the frustrum.
        yangle = (90.0f - yangle);  // Get the perpendicular to the frustrum.

        float   top_cos = esch_cos(yangle);
        float   top_sin = esch_sin(yangle);
        float   left_cos = esch_cos(xangle);
        float   left_sin = esch_sin(xangle);

        // Left
        frustrum[ESCH_CAM_FRUSTRUM_LEFT].normal.i = left_sin;
        frustrum[ESCH_CAM_FRUSTRUM_LEFT].normal.j = 0;
        frustrum[ESCH_CAM_FRUSTRUM_LEFT].normal.k = left_cos;
        frustrum[ESCH_CAM_FRUSTRUM_LEFT].dist = -EPSILON;

        // Right
        frustrum[ESCH_CAM_FRUSTRUM_RIGHT].normal.i = -left_sin;
        frustrum[ESCH_CAM_FRUSTRUM_RIGHT].normal.j = 0;
        frustrum[ESCH_CAM_FRUSTRUM_RIGHT].normal.k = left_cos;
        frustrum[ESCH_CAM_FRUSTRUM_RIGHT].dist = -EPSILON;

        // Top
        frustrum[ESCH_CAM_FRUSTRUM_TOP].normal.i = 0;
        frustrum[ESCH_CAM_FRUSTRUM_TOP].normal.j = -top_sin;
        frustrum[ESCH_CAM_FRUSTRUM_TOP].normal.k = top_cos;
        frustrum[ESCH_CAM_FRUSTRUM_TOP].dist = -EPSILON;

        // Bottom
        frustrum[ESCH_CAM_FRUSTRUM_BOTTOM].normal.i = 0;
        frustrum[ESCH_CAM_FRUSTRUM_BOTTOM].normal.j = top_sin;
        frustrum[ESCH_CAM_FRUSTRUM_BOTTOM].normal.k = top_cos;
        frustrum[ESCH_CAM_FRUSTRUM_BOTTOM].dist = -EPSILON;
    }

//陳� Near/Far planes not based on projection mode
    // Near
    frustrum[ESCH_CAM_FRUSTRUM_HITHER].normal.i = 0;
    frustrum[ESCH_CAM_FRUSTRUM_HITHER].normal.j = 0;
    frustrum[ESCH_CAM_FRUSTRUM_HITHER].normal.k = 1;
    frustrum[ESCH_CAM_FRUSTRUM_HITHER].dist = hither;

    // Far
    frustrum[ESCH_CAM_FRUSTRUM_YON].normal.i = 0;
    frustrum[ESCH_CAM_FRUSTRUM_YON].normal.j = 0;
    frustrum[ESCH_CAM_FRUSTRUM_YON].normal.k = -1;
    frustrum[ESCH_CAM_FRUSTRUM_YON].dist = -yon - EPSILON;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschCamera - compute_z_factor                                            �
//                                                                          �
// Recompute the scale factor for Z to get maximum resolution in the        �
// Z-Buffer.                                                                �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschCamera::compute_z_factor()
{
    assertMyth("EschCamera::compute_z_factor assumes yon greater than hither",
               yon > hither);

    // go ahead and normalize Z between 0 and 1.
    z_factor = (0.9999f / (yon - hither + 1.0f));
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschCamera - compute_eye                                                 �
//                                                                          �
// Recomputes the matrix based on the current eye.dir and top vectors for   �
// the rotation component of the matrix.  This will destroy any scales or   �
// rotations in the eye transform matrix, but will include the user-set     �
// factor.                                                                  �
//                                                                          �
// Assumes that the eye.dir and top vectors are normalized.                 �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschCamera::compute_eye(dword update)
{
    EschVector  right;

    eye.ortho_count=0;

//陳� Create right vector
    right = top CROSS eye.dir;

//陳� Fill in matrix for ortho rotation

    //陳� Transform
    eye.orient.mtx[ESCH_MTX_A] = right.i;
    eye.orient.mtx[ESCH_MTX_B] = right.j;
    eye.orient.mtx[ESCH_MTX_C] = right.k;

    eye.orient.mtx[ESCH_MTX_D] = top.i;
    eye.orient.mtx[ESCH_MTX_E] = top.j;
    eye.orient.mtx[ESCH_MTX_F] = top.k;

    eye.orient.mtx[ESCH_MTX_G] = eye.dir.i;
    eye.orient.mtx[ESCH_MTX_H] = eye.dir.j;
    eye.orient.mtx[ESCH_MTX_I] = eye.dir.k;

    //陳� Inverse Transform
    if (update & ESCH_UPD_INVERSE)
        eye.orient.inverse(&eye.iorient);
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  I/O Routines  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschCamera - load                                                        �
//                                                                          �
// Loads the position and other data of the camera from an IFF file.        �
//                                                                          �
// The IFF version assumes that the IFF is open and pointing at the proper  �
// chunk.  If a 'cname' is given and the name doesn't match that in the     �
// chunk, an error is returned.                                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
esch_error_codes EschCamera::load(const char *fname, const char *cname)
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

        if (iff.chunkid == iff.makeid('E','C','A','M')
            || iff.chunkid == iff.makeid('E','C','A','1'))
        {
            err=load(&iff,cname);
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

esch_error_codes EschCamera::load(XFParseIFF *iff, const char *cname)
{
    assertMyth("EschCamera::load requries iff pointer",
               iff);

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Floating-point format
    if (iff->chunkid == iff->makeid('E','C','A','1'))
    {
        EschFileCamera  cam;

        if (iff->chunkSize != sizeof(cam))
            return ESCH_ERR_INVALIDDATA;

        //陳 Read chunk and verify name, if given.
        if (iff->read(&cam))
            return ESCH_ERR_FILEERROR;

        if (cname && strcmp(cname,cam.name))
            return ESCH_ERR_NOTFOUND;

        //陳 Found, so setup camera
        strcpy(name,cam.name);
        flags = cam.flags;

        set_position(cam.x,cam.y,cam.z);

        fov=cam.fov;

        eye.dir.i = cam.diri;
        eye.dir.j = cam.dirj;
        eye.dir.k = cam.dirk;

        top.i = cam.topi;
        top.j = cam.topj;
        top.k = cam.topk;
    }
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Fixed-point format
    else if (iff->chunkid == iff->makeid('E','C','A','M'))
    {
        EschFileCameraV1  cam;

        if (iff->chunkSize != sizeof(cam))
            return ESCH_ERR_INVALIDDATA;

        //陳 Read chunk and verify name, if given.
        if (iff->read(&cam))
            return ESCH_ERR_FILEERROR;

        if (cname && strcmp(cname,cam.name))
            return ESCH_ERR_NOTFOUND;

        //陳 Found, so setup camera
        strcpy(name,cam.name);
        flags = cam.flags;

        set_position(cam.x / 65536.0f,cam.y / 65536.0f,cam.z / 65536.0f);

        fov=cam.fov / 65536.0f;

        eye.dir.i = cam.diri / 65536.0f;
        eye.dir.j = cam.dirj / 65536.0f;
        eye.dir.k = cam.dirk / 65536.0f;

        top.i = cam.topi / 65536.0f;
        top.j = cam.topj / 65536.0f;
        top.k = cam.topk / 65536.0f;
    }
    else
    {
        return ESCH_ERR_NOTFOUND;
    }

    factor=1.0;

//陳� Call computation functions
    compute_scalar();
    compute_frustrum();
    compute_z_factor();
    compute_eye();

//陳 Return ok
    return ESCH_ERR_NONE;
}

//葦� End of module - escamera.cpp 憶�


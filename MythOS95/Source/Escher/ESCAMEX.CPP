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
// escamex.cpp
//
// The EschCameraEx class is an extended camera which handles
// bitmap backgrounds and hazing.
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
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#define ES_MAX_VERTS    9

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭�  Constructors/Destructors  碓旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschCameraEx - Constructor                                               �
//                                                                          �
// Initializes the camera object                                            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschCameraEx::EschCameraEx(VngoVport *vp) :
    EschCamera(vp),
    bg_bitmap(0)
{
};

EschCameraEx::EschCameraEx(const char *fname, const char *cname) :
    EschCamera(fname,cname),
    bg_bitmap(0)
{
};

EschCameraEx::EschCameraEx(const EschCamera &cam) :
    EschCamera(cam),
    bg_bitmap(0)
{
};

EschCameraEx::EschCameraEx(const EschCameraEx &cam) :
    EschCamera(cam),
    bg_bitmap(cam.bg_bitmap)
{
    flags &= ~(ESCH_CAM_OWNSBITMAP);
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschCameraEx - Destructor                                                �
//                                                                          �
// Releases any associated data for the camera object.                      �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschCameraEx::~EschCameraEx()
{
    release();
};



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  Operations  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschCameraEx - operator =                                                �
//                                                                          �
// Copies the data from another camera.                                     �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
const EschCameraEx &EschCameraEx::operator = (const EschCamera &cam)
{
    if (this != &cam)
    {
        release();

        EschCamera::operator = (cam);
    }
    return *this;
}

const EschCameraEx &EschCameraEx::operator = (const EschCameraEx &cam)
{
    if (this != &cam)
    {
        release();

        EschCamera::operator = (cam);

        bg_bitmap = cam.bg_bitmap;
        flags &= ~(ESCH_CAM_OWNSBITMAP);
    }
    return *this;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschCameraEx - release                                                   �
//                                                                          �
// Release any data owned by the camera.                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschCameraEx::release()
{
//陳� Release bitmap background
    if ((flags & ESCH_CAM_OWNSBITMAP) && bg_bitmap)
    {
        if (bg_bitmap->tex)
            delete [] bg_bitmap->tex;
        delete bg_bitmap;
    }
    bg_bitmap=0;

//陳� Clear any owns bits
    flags &= ~(ESCH_CAM_OWNSBITMAP);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschCameraEx - pre_rend                                                  �
//                                                                          �
// Prepares a render, returning a 0 on success or non-zero otherwise.       �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int EschCameraEx::pre_rend()
{
    static VngoPointF   vpt[ES_MAX_VERTS];
    static VngoPointF3  ivpt[ES_MAX_VERTS];
    static VngoPointF3  ovpt[ES_MAX_VERTS];
    static VngoPointF3  cvpt[10];

    assertMyth("EschCameraEx::pre_rend needs viewport & palette",
               vport != 0 && vport->vbuff.pal != 0);

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
        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Bitmap Background
        if ( (!(flags & ESCH_CAM_IGNORE_BMAP)) && bg_bitmap)
        {
            VngoRect rect(-bg_offx,
                          -bg_offy,
                          bg_bitmap->width,
                          bg_bitmap->height);

            //陳� Don't clear screen if the image covers entire viewport
            if (bg_offx < 0
                || bg_offy < 0
                || (rect.dx-bg_offx) < vport->vbuff.width
                || (rect.dy-bg_offy) < vport->vbuff.height)
                vport->clear_screen_on();
            else
                vport->clear_screen_off();

            vport->reset(bcolor);

            assert(bg_bitmap->tex != 0);
            vport->image_trans(&rect,bg_bitmap);
        }
        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Gradient Background
        else if (flags & ESCH_CAM_GRADIENT)
        {
            int     turnonz=0, turnonhaze=0, edge_adj, swidth, sheight;
            float   tx, ty, tv, width, height;

            //陳� Just clear Z-buffer
            vport->clear_screen_off();
            vport->reset();
            if (vport->vflags & VNGO_ZBUFFER_ACTIVE)
            {
                turnonz = 1;
                vport->zbuffer_off();
            }
            if (vport->vflags & VNGO_HAZE_ON)
            {
                turnonhaze = 1;
                vport->haze_off();
            }

            //陳� Determine position of 'level-line'
            EschVector tdir(eye.dir.i, 0, eye.dir.k);
            float mag = tdir.magnitude();
            if (mag <= 0)
            {
                if (eye.dir.j > 0)
                {
                    VngoRect    rect(0,0,vport->vbuff.width,vport->vbuff.height);
                    vport->frect(&rect, grd_top);
                }
                else
                {
                    VngoRect    rect(0,0,vport->vbuff.width,vport->vbuff.height);
                    vport->frect(&rect, grd_bottom);
                }
            }
            else
            {
                // Don't think this is right for ORTHO cameras...

                tdir /= mag;

                tdir *= (((yon-hither) * 0.25f) + hither);

                EschVector left = tdir;
                left.rotatey(88);

                EschVector right = tdir;
                right.rotatey(-88);

                // 0  grd_top       1
                // 2                3
                // 4  grd_mid       5
                // 6                7
                // 8  grd_bottom    9

                tv = grd_topy;
                if (flags & ESCH_CAM_GRADIENT_FIXED)
                    tv -= eye.orient.mtx[ESCH_MTX_K];

                cvpt[0].wx = left.i;
                cvpt[0].wy = left.j + ((tv > yon) ? tv : yon);
                cvpt[0].wz = left.k;
                cvpt[0].clr = grd_top;

                cvpt[1].wx = right.i;
                cvpt[1].wy = right.j + ((tv > yon) ? tv : yon);
                cvpt[1].wz = right.k;
                cvpt[1].clr = grd_top;

                cvpt[2].wx = left.i;
                cvpt[2].wy = left.j + tv;
                cvpt[2].wz = left.k;
                cvpt[2].clr = grd_top;

                cvpt[3].wx = right.i;
                cvpt[3].wy = right.j + tv;
                cvpt[3].wz = right.k;
                cvpt[3].clr = grd_top;

                tv = grd_midy;
                if (flags & ESCH_CAM_GRADIENT_FIXED)
                    tv -= eye.orient.mtx[ESCH_MTX_K];

                cvpt[4].wx = left.i;
                cvpt[4].wy = left.j + tv;
                cvpt[4].wz = left.k;
                cvpt[4].clr = grd_mid;

                cvpt[5].wx = right.i;
                cvpt[5].wy = right.j + tv;
                cvpt[5].wz = right.k;
                cvpt[5].clr = grd_mid;

                tv = grd_bottomy;
                if (flags & ESCH_CAM_GRADIENT_FIXED)
                    tv -= eye.orient.mtx[ESCH_MTX_K];

                cvpt[6].wx = left.i;
                cvpt[6].wy = left.j + tv;
                cvpt[6].wz = left.k;
                cvpt[6].clr = grd_bottom;

                cvpt[7].wx = right.i;
                cvpt[7].wy = right.j + tv;
                cvpt[7].wz = right.k;
                cvpt[7].clr = grd_bottom;

                cvpt[8].wx = left.i;
                cvpt[8].wy = left.j + ((tv < -yon) ? tv : -yon);
                cvpt[8].wz = left.k;
                cvpt[8].clr = grd_bottom;

                cvpt[9].wx = right.i;
                cvpt[9].wy = right.j + ((tv < -yon) ? tv : -yon);
                cvpt[9].wz = right.k;
                cvpt[9].clr = grd_bottom;

                for(int i=0; i < 10; i++)
                {
                    ((EschVector*)&cvpt[i])->transform(&eye.iorient);
                }

                tx = xscalar;
                ty = yscalar;

                edge_adj = vport->skips_last_pix();
                swidth = vport->vbuff.width + edge_adj;
                sheight = vport->vbuff.height + edge_adj;

                height = float(vport->vbuff.height >> 1);
                width = float(vport->vbuff.width >> 1);

                for(i=0; i < 8; i++)
                {
                    ulong count=3;
                    for(int j=0; j < 3; j++)
                        ivpt[j] = cvpt[i+j];

                    int clip = esch_clip_to_frustrum(&count, ivpt, ovpt, this, 0);

                    if (clip != 0)
                    {
                        if (clip == -1)
                        {
                            count = 3;
                            for(ulong j=0; j < 3; j++)
                            {
                                tv = (ivpt[j].wx * tx) / ivpt[j].wz;

                                vpt[j].x = float(floor(tv + width + 0.5f));

                                tv = (ivpt[j].wy * ty) / ivpt[j].wz;

                                vpt[j].y = float(floor(height - tv + 0.5f));

                                vpt[j].z = 0.99998f;

                                vpt[j].clr = ivpt[j].clr;

                                if (vpt[j].x < 0.f)
                                    vpt[j].x = 0.f;
                                else if (vpt[j].x >= swidth)
                                    vpt[j].x = float(swidth-1);
                                if (vpt[j].y < 0.f)
                                    vpt[j].y = 0.f;
                                else if (vpt[j].y >= sheight)
                                    vpt[j].y = float(sheight - 1);
                            }
                        }
                        else
                        {
                            for(ulong j=0; j < count; j++)
                            {
                                tv = (ovpt[j].wx * tx) / ovpt[j].wz;

                                vpt[j].x = float(floor(tv + width + 0.5f));

                                tv = (ovpt[j].wy * ty) / ovpt[j].wz;

                                vpt[j].y = float(floor(height - tv + 0.5f));

                                vpt[j].z = 0.99998f;

                                vpt[j].clr = ovpt[j].clr;

                                if (vpt[j].x < 0.f)
                                    vpt[j].x = 0.f;
                                else if (vpt[j].x >= swidth)
                                    vpt[j].x = float(swidth-1);
                                if (vpt[j].y < 0.f)
                                    vpt[j].y = 0.f;
                                else if (vpt[j].y >= sheight)
                                    vpt[j].y = float(sheight - 1);
                            }
                        }

                        if (count >= 3)
                            vport->grpoly(count, vpt);
                    }
                }
            }

            //陳� Cleanup
            if (turnonz)
                vport->zbuffer_on();
            if (turnonhaze)
                vport->haze_on();
        }
        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Solid Color Background
        else
        {
            vport->clear_screen_on();
            vport->reset(bcolor);
        }
    }

    return 0;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschCameraEx - post_rend                                                 �
//                                                                          �
// Performs post render processing.                                         �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschCameraEx::post_rend()
{
    assertMyth("EschCameraEx::post_rend needs viewport & palette",
               vport != 0 && vport->vbuff.pal != 0);

//陳� Flush element buffer (if not forcing skip of this step)
    if (!(flags & ESCH_CAM_NOFLUSH))
        EschElement::flush();

//陳� Handle hazing
    vport->haze();

//陳� Unlock (if old state was unlocked)
    if (!(flags & ESCH_CAM_VPWASLOCKED))
        vport->unlock();

    flags &= ~ESCH_CAM_VPWASLOCKED;
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭�  Utility Routines  碓旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschCameraEx - set_bg_bitmap                                             �
//                                                                          �
// Sets up the bitmap background, freeing the old one if owned by the camera�
// returning 0 on success, or 1 if setting the bitmap failed.               �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int EschCameraEx::set_bg_bitmap(VngoTexture *tex, int owns)
{
//陳� Free old bitmap, if owned by Camera
    if ((flags & ESCH_CAM_OWNSBITMAP) && bg_bitmap)
    {
        if (bg_bitmap->tex)
            delete [] bg_bitmap->tex;
        delete bg_bitmap;
    }
    bg_bitmap=0;

//陳� Clear flag & reset offset.
    flags &= ~ESCH_CAM_OWNSBITMAP;

    bg_offx=bg_offy=0;

//陳� Test for valid bitmap
    if (!tex)
        return 1;

//陳� Setup bitmap, if valid.
    bg_bitmap = tex;
    if (owns)
        flags |= ESCH_CAM_OWNSBITMAP;

    return 0;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschCameraEx - create_bg_bitmap                                          �
//                                                                          �
// Creates a bitmap background from the input XFBitmap instance and sets it �
// as the new current bitmap owned by the camera.  Any previous owned       �
// instance is freed.  Returns 0 on success, 1 if failed.                   �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int EschCameraEx::create_bg_bitmap(XFBitmap *bm)
{
    assertMyth("EschCameraEx::create_bg_bitmap needs viewport & palette",
               vport != 0 && vport->vbuff.pal != 0);

    if (!bm)
        return 1;

    VngoTexture *tex = new VngoTexture;
    if (!tex)
        return 1;

    VngoPal *pal = vport->vbuff.pal;
    if (pal->flags & VNGO_16BIT)
    {
        if ((tex->create(bm->width, bm->height, 16, 0) != VNGO_NO_ERROR)
            || (tex->convert(bm,pal) != VNGO_NO_ERROR))
        {
            if (tex->tex)
                delete [] tex->tex;
            delete tex;
            return 1;
        }
    }
    else if (pal->flags & VNGO_15BIT)
    {
        if ((tex->create(bm->width, bm->height, 15, 0) != VNGO_NO_ERROR)
            || (tex->convert(bm,pal) != VNGO_NO_ERROR))
        {
            if (tex->tex)
                delete [] tex->tex;
            delete tex;
            return 1;
        }
    }
    else
    {
        if ((tex->create(bm->width, bm->height, 8, 0) != VNGO_NO_ERROR)
            || (tex->convert(bm,pal) != VNGO_NO_ERROR))
        {
            if (tex->tex)
                delete [] tex->tex;
            delete tex;
            return 1;
        }
    }

    if (set_bg_bitmap(tex,1))
    {
        if (tex->tex)
            delete [] tex->tex;
        delete tex;
        return 1;
    }

    return 0;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschCameraEx - set_haze                                                  �
//                                                                          �
// Sets up hazing information in viewport.                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int EschCameraEx::set_haze(float start, float mid)
{
    assertMyth("EschCameraEx::set_haze needs viewport & palette",
               vport != 0 && vport->vbuff.pal != 0);

    VngoHazeInfo hinfo;
    hinfo.start_depth = start;
    hinfo.mid_depth = mid;
    hinfo.target_color = vport->vbuff.pal->get_RGB(bcolor);
    if (vport->set_haze(&hinfo) != VNGO_NO_ERROR)
        return 1;

    vport->haze_on();

    return 0;
}

int EschCameraEx::set_haze(float start, float mid, VngoColor24bit tcolor)
{
    assertMyth("EschCameraEx::set_haze(2) needs viewport & palette",
               vport != 0 && vport->vbuff.pal != 0);

    VngoHazeInfo hinfo;
    hinfo.start_depth = start;
    hinfo.mid_depth = mid;
    hinfo.target_color = tcolor;
    if (vport->set_haze(&hinfo) != VNGO_NO_ERROR)
        return 1;

    vport->haze_on();

    return 0;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschCameraEx - set_haze                                                  �
//                                                                          �
// Sets up hazing information in viewport.                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschCameraEx::set_gradient(VngoColor24bit top, float topy,
                                VngoColor24bit mid, float midy,
                                VngoColor24bit bottom, float bottomy,
                                int fixed)
{
    grd_top = top.b | (top.g << 8) | (top.r << 16) | VNGO_COLOR_24BIT;
    grd_mid = mid.b | (mid.g << 8) | (mid.r << 16) | VNGO_COLOR_24BIT;
    grd_bottom = bottom.b | (bottom.g << 8) | (bottom.r << 16)
                 | VNGO_COLOR_24BIT;

    grd_topy = topy;
    grd_midy = midy;
    grd_bottomy = bottomy;

    flags |= ESCH_CAM_GRADIENT;
    if (fixed)
        flags |= ESCH_CAM_GRADIENT_FIXED;
    else
        flags &= ~ESCH_CAM_GRADIENT_FIXED;
}

//葦� End of module - escamex.cpp 憶�

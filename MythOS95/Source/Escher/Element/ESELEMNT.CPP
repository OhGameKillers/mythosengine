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
// eselemnt.cpp
//
// Contains the implementation of the element sort area routines.
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//
//���������������������������������������������������������������������������

#include "escher.hpp"

//���������������������������������������������������������������������������
//
//                                 Data
//
//���������������������������������������������������������������������������

ulong EschElementDepth=0;               // Depth of current element tree
ulong EschElementSize=0;                // Size of current element tree

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//����������������������������� EschElement ���������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschElement - insert                                                     �
//                                                                          �
// Inserts the element into the binary tree.                                �
//���������������������������������������������������������������������������
void EschElement::insert()
{
    assertMyth("EschElement::insert() needs sort area",
               EschSysInstance != 0 && EschSysInstance->sspace != 0);

    EschElement *elm = EschSysInstance->sroot;

//��� Check for empty tree
    if (!elm)
    {
        EschSysInstance->sroot = this;
        return;
    }

//��� Walk down until we can insert as left or right leaf
    for(ulong depth=1;; depth++)
    {
#if 0
        //������������������������������ Check Z extents for clear front/back
        if (maxz < elm->minz)
        {
            if (!elm->left)                     //��� Closer
            {
                elm->left = this;
                break;
            }
            elm = elm->left;
        }
        else if (minz > elm->maxz)
        {
            if (!elm->right)                    //��� Further
            {
                elm->right = this;
                break;
            }
            elm = elm->right;
        }
        //��������������������������������� Check X/Y extents for no obscure
        else if ((maxx < elm->minx)
                 || (minx > elm->maxx)
                 || (maxy < elm->miny)
                 || (miny > elm->maxy))
        {
            if (maxz < elm->maxz)
            {
                if (!elm->left)                 //��� Closer
                {
                    elm->left = this;
                    break;
                }
                elm = elm->left;
            }
            else
            {
                if (!elm->right)                //��� Further
                {
                    elm->right = this;
                    break;
                }
                elm = elm->right;
            }
        }
        //������������������������� Extents overlap, perform point/plane test
        else
        {
            EschPoint   pt;

            elm->prepare_test(&pt);

            if (perform_test(&pt))
            {
                if (!elm->left)                 //��� Closer
                {
                    elm->left = this;
                    break;
                }
                elm = elm->left;
            }
            else
            {
                if (!elm->right)                //��� Further
                {
                    elm->right = this;
                    break;
                }
                elm = elm->right;
            }
        }
#else
        //��� Insert by maximum z
        if (maxz <= elm->maxz)
        {
            if (!elm->left)                     //��� Closer
            {
                elm->left = this;
                break;
            }
            elm = elm->left;
        }
        else
        {
            if (!elm->right)                    //��� Further
            {
                elm->right = this;
                break;
            }
            elm = elm->right;
        }
#endif
    }

//��� Update stats
    if (depth > EschElementDepth)
        EschElementDepth = depth;
}


//�������������������������������������������������������������������������Ŀ
//                            ��� Protected ���                             �
// EschElement - draw_tree                                                  �
//                                                                          �
// Draws recursively using Painter's algorithm (furtherest to closest)      �
//���������������������������������������������������������������������������
void EschElement::draw_tree(EschElement *elm)
{
    assertMyth("EschElement::draw_tree() needs valid input", elm != 0);

    if (elm->right)
        draw_tree(elm->right);

    elm->draw();

    if (elm->left)
        draw_tree(elm->left);
}


//�������������������������������������������������������������������������Ŀ
// EschElement - flush                                                      �
//                                                                          �
// Draws any pending element entries and clears the arena.                  �
//���������������������������������������������������������������������������
void EschElement::flush()
{
    assertMyth("EschElement::flush() needs sort area",
               EschSysInstance != 0 && EschSysInstance->sspace != 0);

//��� Perform draw of any pending elements
    if (EschSysInstance->sroot)
        draw_tree(EschSysInstance->sroot);

//��� Clear sort area
    ivory_arena_clear(EschSysInstance->sspace);
    EschSysInstance->sroot=0;

//��� Update stats
    if (EschElementDepth > EschSysInstance->sspace_mdepth)
        EschSysInstance->sspace_mdepth = EschElementDepth;

    if (EschElementSize > EschSysInstance->sspace_mbytes)
        EschSysInstance->sspace_mbytes = EschElementSize;

    EschElementDepth=0;
    EschElementSize=0;
}



//���������������������������������������������������������������������������
//��������������������������� EschPixelElement ������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschPixelElement - draw                                                  �
//���������������������������������������������������������������������������
void EschPixelElement::draw()
{
    assertMyth("EschPixelElement::draw() needs current context camera",
               EschCurrent != 0 && EschCurrent->camera != 0);

    assertMyth("EschPixelElement::draw() camera needs viewport",
               EschCurrent->camera->vport != 0);

#if 1
    // HACK: Van Gogh bug workaround until fixed...
    VngoPoint   tpt;
    tpt.x = long(pnt.x + .5f);
    tpt.y = long(pnt.y + .5f);
    tpt.z = dword(pnt.z * float(0xffffffff));
    tpt.clr = pnt.clr;
    tpt.shade = long(pnt.shade);
    EschCurrent->camera->vport->pixel(&tpt);
#else
    EschCurrent->camera->vport->pixel(&pnt);
#endif
}


//�������������������������������������������������������������������������Ŀ
// EschPixelElement - prepare_test                                          �
//���������������������������������������������������������������������������
void EschPixelElement::prepare_test(EschPoint *pt) const
{
    assertMyth("EschPixelElement::prepare_test() needs point", pt != 0);

    // Test point is point itself
    pt->x = pnt.x;
    pt->y = pnt.y;
    pt->z = pnt.z;
}


//�������������������������������������������������������������������������Ŀ
// EschPixelElement - perform_test                                          �
//���������������������������������������������������������������������������
BOOL EschPixelElement::perform_test(const EschPoint *pt) const
{
    assertMyth("EschPixelElement::perform_test() needs point", pt != 0);

    // Test point is point itself
    return ((pnt.z < pt->z) ? TRUE : FALSE);
}



//���������������������������������������������������������������������������
//���������������������������� EschLineElement ������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschLineElement - draw                                                   �
//���������������������������������������������������������������������������
void EschLineElement::draw()
{
    assertMyth("EschLineElement::draw() needs current context camera",
               EschCurrent != 0 && EschCurrent->camera != 0);

    assertMyth("EschLineElement::draw() camera needs viewport",
               EschCurrent->camera->vport != 0);

//!!! Need to change clipdraw_line to actually clip! so we can use line

    EschCurrent->camera->vport->clip_line(&pnt1, &pnt2);
}


//�������������������������������������������������������������������������Ŀ
// EschLineElement - prepare_test                                           �
//���������������������������������������������������������������������������
void EschLineElement::prepare_test(EschPoint *pt) const
{
    assertMyth("EschLineElement::prepare_test() needs point", pt != 0);

    // Test point is midpoint
    pt->x = pnt1.x + (pnt2.x - pnt1.x) / 2;
    pt->y = pnt1.y + (pnt2.y - pnt1.y) / 2;
    pt->z = pnt1.z + (pnt2.z - pnt1.z) / 2;
}


//�������������������������������������������������������������������������Ŀ
// EschLineElement - perform_test                                           �
//���������������������������������������������������������������������������
BOOL EschLineElement::perform_test(const EschPoint *pt) const
{
    assertMyth("EschLineElement::perform_test() needs point", pt != 0);

    // Test point is midpoint
    float z = pnt1.z + ((pnt2.z - pnt1.z) / 2);

    return ((z < pt->z) ? TRUE : FALSE);
}



//���������������������������������������������������������������������������
//���������������������������� EschPolyElement ������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschPolyElement - draw                                                   �
//���������������������������������������������������������������������������
void EschPolyElement::draw()
{
    assertMyth("EschPolyElement::draw() needs current context camera",
               EschCurrent != 0 && EschCurrent->camera != 0);

    assertMyth("EschPolyElement::draw() camera needs viewport",
               EschCurrent->camera->vport != 0);

    switch (typ)
    {
        case ESCH_ELMNT_POLY:
            EschCurrent->camera->vport->poly(count,vpoly);
            return;

        case ESCH_ELMNT_GPOLY:
            EschCurrent->camera->vport->gpoly(count,vpoly);
            return;

        case ESCH_ELMNT_GPOLY_PERSP:
            EschCurrent->camera->vport->gpoly_persp(count,vpoly);
            return;

        default:
            assertMyth("EschPolyElement::draw() found unknown typ",
                       0);
            break;
    }
}


//�������������������������������������������������������������������������Ŀ
// EschPolyElement - prepare_test                                           �
//���������������������������������������������������������������������������
void EschPolyElement::prepare_test(EschPoint *pt) const
{
    assertMyth("EschPolyElement::prepare_test() needs point", pt != 0);

    // Test point is first vertex
    pt->x = vpoly[0].x;
    pt->y = vpoly[0].y;
    pt->z = vpoly[0].z;
}


//�������������������������������������������������������������������������Ŀ
// EschPolyElement - perform_test                                           �
//���������������������������������������������������������������������������
BOOL EschPolyElement::perform_test(const EschPoint *pt) const
{
    assertMyth("EschPolyElement::perform_test() needs point and valid count",
               pt != 0 && (count >= 3));

    // Make a vector from first vertex to test point
    EschVector v1(pt->x - vpoly[0].x,
                  pt->y - vpoly[0].y, 
                  pt->z - vpoly[0].z);

    // Create plane normal by crossing two endpoints
    EschVector v2 = EschVector(vpoly[1].x - vpoly[0].x,
                               vpoly[1].y - vpoly[0].y,
                               vpoly[1].z - vpoly[0].z)
                    CROSS EschVector(vpoly[2].x - vpoly[0].x,
                                     vpoly[2].y - vpoly[0].y,
                                     vpoly[2].z - vpoly[0].z);

    // Determine closeness by sign of dot product
    return (((v1 DOT v2) < 0) ? TRUE : FALSE);
}



//���������������������������������������������������������������������������
//��������������������������� EschPolyAElement ������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschPolyAElement - draw                                                  �
//���������������������������������������������������������������������������
void EschPolyAElement::draw()
{
    assertMyth("EschPolyAElement::draw() needs current context camera",
               EschCurrent != 0 && EschCurrent->camera != 0);

    assertMyth("EschPolyAElement::draw() camera needs viewport",
               EschCurrent->camera->vport != 0);

    switch (typ)
    {
        case ESCH_ELMNT_POLY_A:
            EschCurrent->camera->vport->poly_a(count,vpoly,alpha);
            return;

        case ESCH_ELMNT_GPOLY_A:
            EschCurrent->camera->vport->gpoly_a(count,vpoly,alpha);
            return;

        case ESCH_ELMNT_GPOLY_PERSP_A:
            EschCurrent->camera->vport->gpoly_persp_a(count,vpoly,alpha);
            return;

        default:
            assertMyth("EschPolyAElement::draw() found unknown typ",
                       0);
            break;
    }
}


//�������������������������������������������������������������������������Ŀ
// EschPolyAElement - prepare_test                                          �
//���������������������������������������������������������������������������
void EschPolyAElement::prepare_test(EschPoint *pt) const
{
    assertMyth("EschPolyAElement::prepare_test() needs point", pt != 0);

    // Test point is first vertex
    pt->x = vpoly[0].x;
    pt->y = vpoly[0].y;
    pt->z = vpoly[0].z;
}


//�������������������������������������������������������������������������Ŀ
// EschPolyAElement - perform_test                                          �
//���������������������������������������������������������������������������
BOOL EschPolyAElement::perform_test(const EschPoint *pt) const
{
    assertMyth("EschPolyAElement::perform_test() needs point and valid count",
               pt != 0 && (count >= 3));

    // Make a vector from first vertex to test point
    EschVector v1(pt->x - vpoly[0].x,
                  pt->y - vpoly[0].y, 
                  pt->z - vpoly[0].z);

    // Create plane normal by crossing two endpoints
    EschVector v2 = EschVector(vpoly[1].x - vpoly[0].x,
                               vpoly[1].y - vpoly[0].y,
                               vpoly[1].z - vpoly[0].z)
                    CROSS EschVector(vpoly[2].x - vpoly[0].x,
                                     vpoly[2].y - vpoly[0].y,
                                     vpoly[2].z - vpoly[0].z);

    // Determine closeness by sign of dot product
    return (((v1 DOT v2) < 0) ? TRUE : FALSE);
}



//���������������������������������������������������������������������������
//�������������������������� EschPolyTxtElement �����������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschPolyTxtElement - draw                                                �
//���������������������������������������������������������������������������
void EschPolyTxtElement::draw()
{
    assertMyth("EschPolyTxtElement::draw() needs current context camera",
               EschCurrent != 0 && EschCurrent->camera != 0);

    assertMyth("EschPolyTxtElement::draw() camera needs viewport",
               EschCurrent->camera->vport != 0);

    assertMyth("EschPolyTxtElement::draw() needs texture", txt != 0);

    txt->lock();

    switch (typ)
    {
        case ESCH_ELMNT_TXTPOLY:
            EschCurrent->camera->vport->tpoly(count,vpoly,txt->ptr);
            break;

        case ESCH_ELMNT_TXTPOLY_PERSP:
            EschCurrent->camera->vport->tpoly_persp(count,vpoly,txt->ptr);
            break;

        case ESCH_ELMNT_GTXTPOLY:
            EschCurrent->camera->vport->gtpoly(count,vpoly,txt->ptr);
            break;

        case ESCH_ELMNT_GTXTPOLY_PERSP:
            EschCurrent->camera->vport->gtpoly_persp(count,vpoly,txt->ptr);
            break;

        default:
            assertMyth("EschPolyTxtElement::draw() found unknown typ",
                       0);
            break;
    }

    txt->unlock();
}


//�������������������������������������������������������������������������Ŀ
// EschPolyTxtElement - prepare_test                                        �
//���������������������������������������������������������������������������
void EschPolyTxtElement::prepare_test(EschPoint *pt) const
{
    assertMyth("EschPolyTxtElement::prepare_test() needs point", pt != 0);

    // Test point is first vertex
    pt->x = vpoly[0].x;
    pt->y = vpoly[0].y;
    pt->z = vpoly[0].z;
}


//�������������������������������������������������������������������������Ŀ
// EschPolyTxtElement - perform_test                                        �
//���������������������������������������������������������������������������
BOOL EschPolyTxtElement::perform_test(const EschPoint *pt) const
{
    assertMyth("EschPolyTxtElement::perform_test() needs point and valid count",
               pt != 0 && (count >= 3));

    // Make a vector from first vertex to test point
    EschVector v1(pt->x - vpoly[0].x,
                  pt->y - vpoly[0].y, 
                  pt->z - vpoly[0].z);

    // Create plane normal by crossing two endpoints
    EschVector v2 = EschVector(vpoly[1].x - vpoly[0].x,
                               vpoly[1].y - vpoly[0].y,
                               vpoly[1].z - vpoly[0].z)
                    CROSS EschVector(vpoly[2].x - vpoly[0].x,
                                     vpoly[2].y - vpoly[0].y,
                                     vpoly[2].z - vpoly[0].z);

    // Determine closeness by sign of dot product
    return (((v1 DOT v2) < 0) ? TRUE : FALSE);
}



//���������������������������������������������������������������������������
//������������������������� EschPolyTxtAElement �����������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschPolyTxtAElement - draw                                               �
//���������������������������������������������������������������������������
void EschPolyTxtAElement::draw()
{
    assertMyth("EschPolyTxtAElement::draw() needs current context camera",
               EschCurrent != 0 && EschCurrent->camera != 0);

    assertMyth("EschPolyTxtAElement::draw() camera needs viewport",
               EschCurrent->camera->vport != 0);

    assertMyth("EschPolyTxtAElement::draw() needs texture", txt != 0);

    txt->lock();

    switch (typ)
    {
        case ESCH_ELMNT_TXTPOLY_A:
            EschCurrent->camera->vport->tpoly_a(count,vpoly,
                                                txt->ptr,alpha);
            break;

        case ESCH_ELMNT_TXTPOLY_PERSP_A:
            EschCurrent->camera->vport->tpoly_persp_a(count,vpoly,
                                                      txt->ptr,alpha);
            break;

        case ESCH_ELMNT_GTXTPOLY_A:
            EschCurrent->camera->vport->gtpoly_a(count,vpoly,
                                                 txt->ptr,alpha);
            break;

        case ESCH_ELMNT_GTXTPOLY_PERSP_A:
            EschCurrent->camera->vport->gtpoly_persp_a(count,vpoly,
                                                       txt->ptr,alpha);
            break;

        default:
            assertMyth("EschPolyTxtAElement::draw() found unknown typ",
                       0);
            break;
    }

    txt->unlock();
}


//�������������������������������������������������������������������������Ŀ
// EschPolyTxtAElement - prepare_test                                       �
//���������������������������������������������������������������������������
void EschPolyTxtAElement::prepare_test(EschPoint *pt) const
{
    assertMyth("EschPolyTxtAElement::prepare_test() needs point", pt != 0);

    // Test point is first vertex
    pt->x = vpoly[0].x;
    pt->y = vpoly[0].y;
    pt->z = vpoly[0].z;
}


//�������������������������������������������������������������������������Ŀ
// EschPolyTxtAElement - perform_test                                       �
//���������������������������������������������������������������������������
BOOL EschPolyTxtAElement::perform_test(const EschPoint *pt) const
{
    assertMyth("EschPolyTxtAElement::perform_test() needs point and valid count",
               pt != 0 && (count >= 3));

    // Make a vector from first vertex to test point
    EschVector v1(pt->x - vpoly[0].x,
                  pt->y - vpoly[0].y, 
                  pt->z - vpoly[0].z);

    // Create plane normal by crossing two endpoints
    EschVector v2 = EschVector(vpoly[1].x - vpoly[0].x,
                               vpoly[1].y - vpoly[0].y,
                               vpoly[1].z - vpoly[0].z)
                    CROSS EschVector(vpoly[2].x - vpoly[0].x,
                                     vpoly[2].y - vpoly[0].y,
                                     vpoly[2].z - vpoly[0].z);

    // Determine closeness by sign of dot product
    return (((v1 DOT v2) < 0) ? TRUE : FALSE);
}

//��� End of module - eselemnt.cpp ���
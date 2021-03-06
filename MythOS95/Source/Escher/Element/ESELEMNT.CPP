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
// eselemnt.cpp
//
// Contains the implementation of the element sort area routines.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include "escher.hpp"

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

ulong EschElementDepth=0;               // Depth of current element tree
ulong EschElementSize=0;                // Size of current element tree

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭� EschElement 旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschElement - insert                                                     �
//                                                                          �
// Inserts the element into the binary tree.                                �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschElement::insert()
{
    assertMyth("EschElement::insert() needs sort area",
               EschSysInstance != 0 && EschSysInstance->sspace != 0);

    EschElement *elm = EschSysInstance->sroot;

//陳� Check for empty tree
    if (!elm)
    {
        EschSysInstance->sroot = this;
        return;
    }

//陳� Walk down until we can insert as left or right leaf
    for(ulong depth=1;; depth++)
    {
        //陳� Insert by maximum z
        if (maxz <= elm->maxz)
        {
            if (!elm->left)                     //陳� Closer
            {
                elm->left = this;
                break;
            }
            elm = elm->left;
        }
        else
        {
            if (!elm->right)                    //陳� Further
            {
                elm->right = this;
                break;
            }
            elm = elm->right;
        }
    }

//陳� Update stats
    if (depth > EschElementDepth)
        EschElementDepth = depth;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//                            旭� Protected 旭�                             �
// EschElement - draw_tree                                                  �
//                                                                          �
// Draws recursively using Painter's algorithm (furtherest to closest)      �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschElement::draw_tree(EschElement *elm)
{
    assertMyth("EschElement::draw_tree() needs valid input", elm != 0);

    if (elm->right)
        draw_tree(elm->right);

    elm->draw();

    if (elm->left)
        draw_tree(elm->left);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschElement - flush                                                      �
//                                                                          �
// Draws any pending element entries and clears the arena.                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschElement::flush()
{
    assertMyth("EschElement::flush() needs sort area",
               EschSysInstance != 0 && EschSysInstance->sspace != 0);

//陳� Perform draw of any pending elements
    if (EschSysInstance->sroot)
        draw_tree(EschSysInstance->sroot);

//陳� Clear sort area
    ivory_arena_clear(EschSysInstance->sspace);
    EschSysInstance->sroot=0;

//陳� Update stats
    if (EschElementDepth > EschSysInstance->sspace_mdepth)
        EschSysInstance->sspace_mdepth = EschElementDepth;

    if (EschElementSize > EschSysInstance->sspace_mbytes)
        EschSysInstance->sspace_mbytes = EschElementSize;

    EschElementDepth=0;
    EschElementSize=0;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//                            旭� Protected 旭�                             �
// EschElement - link_tree                                                  �
//                                                                          �
// Creates a linked-list from the tree (destroying the tree).               �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschElement *EschElement::link_tree(EschElement *elm)
{
    assertMyth("EschElement::draw_tree() needs valid input", elm != 0);

    EschElement *right = (elm->right) ? link_tree(elm->right) : 0;
    EschElement *left = (elm->left) ? link_tree(elm->left) : 0;

    if (right)
    {
        for(EschElement *e = right; e->right != 0; e = e->right);

        e->right = elm;
        elm->left = e;

        elm->right = left;
        if (left)
            left->left = elm;

        return right;
    }
    else if (left)
    {
        elm->left = 0;
        elm->right = left;
        if (left)
            left->left = elm;

        return elm;
    }
    else
    {
        elm->left = elm->right = 0;
        return elm;
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschElement - flush_truesort                                             �
//                                                                          �
// Draws any pending element entries using a more complex sort and clears   �
// the arena.                                                               �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschElement::flush_truesort()
{
    assertMyth("EschElement::flush_truesort() needs sort area",
               EschSysInstance != 0 && EschSysInstance->sspace != 0);

//陳� Perform draw of any pending elements
    if (EschSysInstance->sroot)
    {
        //陳� Create linked-list of elements sorted by Z-max
        //陳� with right as next, left as prev.
        EschElement *head = link_tree(EschSysInstance->sroot);
        assert(head != 0);

        //陳� Start from end of list
        for(EschElement *elm=head; elm->right != 0; elm = elm->right);

        //陳� Process each polygon from back to front
        while(elm != 0)
        {
            // for now just draw...
            elm->draw();
        }
    }

//陳� Clear sort area
    ivory_arena_clear(EschSysInstance->sspace);
    EschSysInstance->sroot=0;

//陳� Update stats
    if (EschElementDepth > EschSysInstance->sspace_mdepth)
        EschSysInstance->sspace_mdepth = EschElementDepth;

    if (EschElementSize > EschSysInstance->sspace_mbytes)
        EschSysInstance->sspace_mbytes = EschElementSize;

    EschElementDepth=0;
    EschElementSize=0;
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭� EschPixelElement 旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschPixelElement - draw                                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschPixelElement::draw()
{
    assertMyth("EschPixelElement::draw() needs current context camera",
               EschCurrent != 0 && EschCurrent->camera != 0);

    assertMyth("EschPixelElement::draw() camera needs viewport",
               EschCurrent->camera->vport != 0);

    EschCurrent->camera->vport->pixel(&pnt);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschPixelElement - prepare_test                                          �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschPixelElement::prepare_test(EschPoint *pt) const
{
    assertMyth("EschPixelElement::prepare_test() needs point", pt != 0);

    // Test point is point itself
    pt->x = pnt.x;
    pt->y = pnt.y;
    pt->z = pnt.z;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschPixelElement - perform_test                                          �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
BOOL EschPixelElement::perform_test(const EschPoint *pt) const
{
    assertMyth("EschPixelElement::perform_test() needs point", pt != 0);

    // Test point is point itself
    return ((pnt.z < pt->z) ? TRUE : FALSE);
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭 EschLineElement 旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschLineElement - draw                                                   �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschLineElement::draw()
{
    assertMyth("EschLineElement::draw() needs current context camera",
               EschCurrent != 0 && EschCurrent->camera != 0);

    assertMyth("EschLineElement::draw() camera needs viewport",
               EschCurrent->camera->vport != 0);

//!!! Need to change clipdraw_line to actually clip! so we can use line

    EschCurrent->camera->vport->clip_line(&pnt1, &pnt2);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschLineElement - prepare_test                                           �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschLineElement::prepare_test(EschPoint *pt) const
{
    assertMyth("EschLineElement::prepare_test() needs point", pt != 0);

    // Test point is midpoint
    pt->x = pnt1.x + (pnt2.x - pnt1.x) / 2;
    pt->y = pnt1.y + (pnt2.y - pnt1.y) / 2;
    pt->z = pnt1.z + (pnt2.z - pnt1.z) / 2;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschLineElement - perform_test                                           �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
BOOL EschLineElement::perform_test(const EschPoint *pt) const
{
    assertMyth("EschLineElement::perform_test() needs point", pt != 0);

    // Test point is midpoint
    float z = pnt1.z + ((pnt2.z - pnt1.z) / 2);

    return ((z < pt->z) ? TRUE : FALSE);
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭 EschPolyElement 旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschPolyElement - draw                                                   �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschPolyElement - prepare_test                                           �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschPolyElement::prepare_test(EschPoint *pt) const
{
    assertMyth("EschPolyElement::prepare_test() needs point", pt != 0);

    // Test point is first vertex
    pt->x = vpoly[0].x;
    pt->y = vpoly[0].y;
    pt->z = vpoly[0].z;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschPolyElement - perform_test                                           �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭� EschPolyAElement 旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschPolyAElement - draw                                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschPolyAElement - prepare_test                                          �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschPolyAElement::prepare_test(EschPoint *pt) const
{
    assertMyth("EschPolyAElement::prepare_test() needs point", pt != 0);

    // Test point is first vertex
    pt->x = vpoly[0].x;
    pt->y = vpoly[0].y;
    pt->z = vpoly[0].z;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschPolyAElement - perform_test                                          �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭 EschPolyTxtElement 旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschPolyTxtElement - draw                                                �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschPolyTxtElement - prepare_test                                        �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschPolyTxtElement::prepare_test(EschPoint *pt) const
{
    assertMyth("EschPolyTxtElement::prepare_test() needs point", pt != 0);

    // Test point is first vertex
    pt->x = vpoly[0].x;
    pt->y = vpoly[0].y;
    pt->z = vpoly[0].z;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschPolyTxtElement - perform_test                                        �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭� EschPolyTxtAElement 旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschPolyTxtAElement - draw                                               �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschPolyTxtAElement - prepare_test                                       �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void EschPolyTxtAElement::prepare_test(EschPoint *pt) const
{
    assertMyth("EschPolyTxtAElement::prepare_test() needs point", pt != 0);

    // Test point is first vertex
    pt->x = vpoly[0].x;
    pt->y = vpoly[0].y;
    pt->z = vpoly[0].z;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschPolyTxtAElement - perform_test                                       �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
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

//葦� End of module - eselemnt.cpp 憶�

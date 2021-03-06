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
// esmath.cpp
//
// Contains the various arithmetic operations for the EschPoint and
// EschVector classes in the 'math' header.
//
//      esch_rotatex
//      esch_rotatey
//      esch_rotatez
//      esch_flt_transform
//      esch_flt_transform_notran
//
// These routines assume that the EschPoint and EschVector classes are
// identical to the assembly routine with x/i, y/j, z/k as the first
// three dwords, represented as single-precision floats math.
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
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// esch_rotatex                                                             �
//                                                                          �
// This function rotates the passed in vector/point about the X-axis        �
// by the number of degrees passed in deg.                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
extern "C" void esch_rotatex(const void *s, const float deg, void *d)
{
//
//  (i', j', k') = rotate-about-x (i, j, k)
//
//      i' = i
//      j' = j * c + k * s
//      k' = k * c - j * s
//

    float sn = esch_sin(deg);
    float cn = esch_cos(deg);

    float newj = ((const EschVector*)s)->j*cn + ((const EschVector*)s)->k*sn;
    float newk = ((const EschVector*)s)->k*cn - ((const EschVector*)s)->j*sn;

    ((EschVector*)d)->i = ((const EschVector*)s)->i;
    ((EschVector*)d)->j = newj;
    ((EschVector*)d)->k = newk;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// esch_rotatey                                                             �
//                                                                          �
// This function rotates the passed in vector/point about the Y-axis        �
// by the number of degrees passed in deg.                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
extern "C" void esch_rotatey(const void *s, const float deg, void *d)
{
//
//  (i', j', k') = rotate-about-y (i, j, k)
//
//       i' = i * c - k * s
//       j' = j
//       k' = i * s + k * c
//

    float sn = esch_sin(deg);
    float cn = esch_cos(deg);

    float newi = ((const EschVector*)s)->i*cn - ((const EschVector*)s)->k*sn;
    float newk = ((const EschVector*)s)->i*sn + ((const EschVector*)s)->k*cn;

    ((EschVector*)d)->i = newi;
    ((EschVector*)d)->j = ((const EschVector*)s)->j;
    ((EschVector*)d)->k = newk;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// esch_rotatez                                                             �
//                                                                          �
// This function rotates the passed in vector/point about the Z-axis        �
// by the number of degrees passed in deg.                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
extern "C" void esch_rotatez(const void *s,const float deg, void *d)
{
//
//  (i', j', k') = rotate-about-x (i, j, k)
//
//       i' = i * c + j * s
//       j' = j * c - i * s
//       k' = k
//

    float sn = esch_sin(deg);
    float cn = esch_cos(deg);

    float newi = ((const EschVector*)s)->i*cn + ((const EschVector*)s)->j*sn;
    float newj = ((const EschVector*)s)->j*cn - ((const EschVector*)s)->i*sn;

    ((EschVector*)d)->i = newi;
    ((EschVector*)d)->j = newj;
    ((EschVector*)d)->k = ((const EschVector*)s)->k;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// esch_flt_transform                                                       �
//                                                                          �
// This transforms the vector/point by the matrix 'm'.                      �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
extern "C" void esch_flt_transform(const void *s, const EschMatrix *m, void *d)
{
//
//             [A B C 0]   [ Ai+Dj+Gk+J ]
// [i j k 1] * [D E F 0] = [ Bi+Ej+Hk+K ]
//             [G H I 0]   [ Ci+Fj+Ik+L ]
//             [J K L 1]   [      1     ]
//

    float newi = m->mtx[ESCH_MTX_A]*((const EschVector*)s)->i
                 + m->mtx[ESCH_MTX_D]*((const EschVector*)s)->j
                 + m->mtx[ESCH_MTX_G]*((const EschVector*)s)->k
                 + m->mtx[ESCH_MTX_J];

    float newj = m->mtx[ESCH_MTX_B]*((const EschVector*)s)->i
                 + m->mtx[ESCH_MTX_E]*((const EschVector*)s)->j
                 + m->mtx[ESCH_MTX_H]*((const EschVector*)s)->k
                 + m->mtx[ESCH_MTX_K];

    float newk = m->mtx[ESCH_MTX_C]*((const EschVector*)s)->i
                 + m->mtx[ESCH_MTX_F]*((const EschVector*)s)->j
                 + m->mtx[ESCH_MTX_I]*((const EschVector*)s)->k
                 + m->mtx[ESCH_MTX_L];

    ((EschVector*)d)->i = newi;
    ((EschVector*)d)->j = newj;
    ((EschVector*)d)->k = newk;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// esch_flt_transform_notran                                                �
//                                                                          �
// This transforms the vector/point by the matrix 'm' ignoring translation. �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
extern "C" void esch_flt_transform_notran(const void *s,const EschMatrix *m,
                                      void *d)
{
//
//             [A B C 0]   [ Ai+Dj+Gk ]
// [i j k 1] * [D E F 0] = [ Bi+Ej+Hk ]
//             [G H I 0]   [ Ci+Fj+Ik ]
//             [J K L 1]   [    1     ]
//

    float newi = m->mtx[ESCH_MTX_A]*((const EschVector*)s)->i
                 + m->mtx[ESCH_MTX_D]*((const EschVector*)s)->j
                 + m->mtx[ESCH_MTX_G]*((const EschVector*)s)->k;

    float newj = m->mtx[ESCH_MTX_B]*((const EschVector*)s)->i
                 + m->mtx[ESCH_MTX_E]*((const EschVector*)s)->j
                 + m->mtx[ESCH_MTX_H]*((const EschVector*)s)->k;

    float newk = m->mtx[ESCH_MTX_C]*((const EschVector*)s)->i
                 + m->mtx[ESCH_MTX_F]*((const EschVector*)s)->j
                 + m->mtx[ESCH_MTX_I]*((const EschVector*)s)->k;

    ((EschVector*)d)->i = newi;
    ((EschVector*)d)->j = newj;
    ((EschVector*)d)->k = newk;
}

//葦� End of module - esmath.cpp 憶�


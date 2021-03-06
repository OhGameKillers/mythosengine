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
// esmatrix.cpp
//
// Contains the functions that are called by the EschMatrix class
// in the 'math' header.
//
//         esch_flt_concatmatrix
//         esch_detmatrix
//         esch_inversematrix
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
// esch_flt_concatmatrix                                                    �
//                                                                          �
// This contatenates matrix 'm' to the matrix 's' and puts the results into �
// matrix 'd' assuming the implied last column is [0 0 0 1].                �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
extern "C" void esch_flt_concatmatrix(const EschMatrix *s,
                                      const EschMatrix *m,
                                      EschMatrix *d)
{
// [A B C 0]      [a b c 0]    [Aa+Bd+Cg   Ab+Be+Ch   Ac+Bf+Ci   0]
// [D E F 0]      [d e f 0]    [Da+Ed+Fg   Db+Ee+Fh   Dc+Ef+Fi   0]
// [G H I 0]  *   [g h i 0] =  [Ga+Hd+Ig   Gb+He+Ih   Gc+Hf+Ii   0]
// [J K L 1]      [j k l 1]    [Ja+Kd+Lg+j Jb+Ke+Lh+k Jc+Kf+Li+l 1]

    EschMatrix mtx;
    memcpy(&mtx,s,sizeof(mtx));

    // Aa+Bd+Cg
    d->mtx[ESCH_MTX_A] = mtx.mtx[ESCH_MTX_A]*m->mtx[ESCH_MTX_A]
                         + mtx.mtx[ESCH_MTX_B]*m->mtx[ESCH_MTX_D]
                         + mtx.mtx[ESCH_MTX_C]*m->mtx[ESCH_MTX_G];

    // Ab+Be+Ch
    d->mtx[ESCH_MTX_B] = mtx.mtx[ESCH_MTX_A]*m->mtx[ESCH_MTX_B]
                         + mtx.mtx[ESCH_MTX_B]*m->mtx[ESCH_MTX_E]
                         + mtx.mtx[ESCH_MTX_C]*m->mtx[ESCH_MTX_H];

    // Ac+Bf+Ci
    d->mtx[ESCH_MTX_C] = mtx.mtx[ESCH_MTX_A]*m->mtx[ESCH_MTX_C]
                         + mtx.mtx[ESCH_MTX_B]*m->mtx[ESCH_MTX_F]
                         + mtx.mtx[ESCH_MTX_C]*m->mtx[ESCH_MTX_I];

    // Da+Ed+Fg
    d->mtx[ESCH_MTX_D] = mtx.mtx[ESCH_MTX_D]*m->mtx[ESCH_MTX_A]
                         + mtx.mtx[ESCH_MTX_E]*m->mtx[ESCH_MTX_D]
                         + mtx.mtx[ESCH_MTX_F]*m->mtx[ESCH_MTX_G];

    // Db+Ee+Fh
    d->mtx[ESCH_MTX_E] = mtx.mtx[ESCH_MTX_D]*m->mtx[ESCH_MTX_B]
                         + mtx.mtx[ESCH_MTX_E]*m->mtx[ESCH_MTX_E]
                         + mtx.mtx[ESCH_MTX_F]*m->mtx[ESCH_MTX_H];

    // Dc+Ef+Fi
    d->mtx[ESCH_MTX_F] = mtx.mtx[ESCH_MTX_D]*m->mtx[ESCH_MTX_C]
                         + mtx.mtx[ESCH_MTX_E]*m->mtx[ESCH_MTX_F]
                         + mtx.mtx[ESCH_MTX_F]*m->mtx[ESCH_MTX_I];

    // Ga+Hd+Ig
    d->mtx[ESCH_MTX_G] = mtx.mtx[ESCH_MTX_G]*m->mtx[ESCH_MTX_A]
                         + mtx.mtx[ESCH_MTX_H]*m->mtx[ESCH_MTX_D]
                         + mtx.mtx[ESCH_MTX_I]*m->mtx[ESCH_MTX_G];

    // Gb+He+Ih
    d->mtx[ESCH_MTX_H] = mtx.mtx[ESCH_MTX_G]*m->mtx[ESCH_MTX_B]
                         + mtx.mtx[ESCH_MTX_H]*m->mtx[ESCH_MTX_E]
                         + mtx.mtx[ESCH_MTX_I]*m->mtx[ESCH_MTX_H];

    // Gc+Hf+Ii
    d->mtx[ESCH_MTX_I] = mtx.mtx[ESCH_MTX_G]*m->mtx[ESCH_MTX_C]
                         + mtx.mtx[ESCH_MTX_H]*m->mtx[ESCH_MTX_F]
                         + mtx.mtx[ESCH_MTX_I]*m->mtx[ESCH_MTX_I];

    // Ja+Kd+Lg+j
    d->mtx[ESCH_MTX_J] = mtx.mtx[ESCH_MTX_J]*m->mtx[ESCH_MTX_A]
                         + mtx.mtx[ESCH_MTX_K]*m->mtx[ESCH_MTX_D]
                         + mtx.mtx[ESCH_MTX_L]*m->mtx[ESCH_MTX_G]
                         + m->mtx[ESCH_MTX_J];

    // Jb+Ke+Lh+k
    d->mtx[ESCH_MTX_K] = mtx.mtx[ESCH_MTX_J]*m->mtx[ESCH_MTX_B]
                         + mtx.mtx[ESCH_MTX_K]*m->mtx[ESCH_MTX_E]
                         + mtx.mtx[ESCH_MTX_L]*m->mtx[ESCH_MTX_H]
                         + m->mtx[ESCH_MTX_K];

    // Jc+Kf+Li+l
    d->mtx[ESCH_MTX_L] = mtx.mtx[ESCH_MTX_J]*m->mtx[ESCH_MTX_C]
                         + mtx.mtx[ESCH_MTX_K]*m->mtx[ESCH_MTX_F]
                         + mtx.mtx[ESCH_MTX_L]*m->mtx[ESCH_MTX_I]
                         + m->mtx[ESCH_MTX_L];
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// esch_detmatrix                                                           �
//                                                                          �
// This function computes the determinant of the matrix 'm', which is a     �
// single scalar value (treats implied last column as 0 0 0 1).             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
extern "C" float esch_detmatrix(const EschMatrix *m)
{
//     [A B C 0]
// det [D E F 0] =  A |E F 0|  - B |D F 0|  + C |D E 0|   - 0 |D E F|
//     [G H I 0]      |H I 0|      |G I 0|      |G H 0|       |G H I|
//     [J K L 1]      |K L 1|      |J L 1|      |J K 1|       |H K L|
//
//
//               =  A(                )
//                   ( E|I 0| - F|H 0|)
//                   (  |L 1|    |K 1|)
//
//                 -B(                )
//                   ( D|I 0| - F|G 0|)
//                   (  |L 1|    |J 1|)
//
//                 +C(                )
//                   ( D|H 0| - E|G 0|)
//                   (  |K 1|    |J 1|)
//
//               =  A(EI - FH) - B(DI - FG) + C(DH - EG)
//

// A |E F 0|
//   |H I 0| = A (EI - FH)
//   |K L 1|

    float det = m->mtx[ESCH_MTX_A]
                * (m->mtx[ESCH_MTX_E]*m->mtx[ESCH_MTX_I] - m->mtx[ESCH_MTX_F]*m->mtx[ESCH_MTX_H]);

// - B |D F 0|
//     |G I 0| = - B (DI - FG)
//     |J L 1|

    det -= m->mtx[ESCH_MTX_B]
           * (m->mtx[ESCH_MTX_D]*m->mtx[ESCH_MTX_I] - m->mtx[ESCH_MTX_F]*m->mtx[ESCH_MTX_G]);

// C |D E 0|
//   |G H 0| = C (DH - EG)
//   |J K 1|

    return (det
            + m->mtx[ESCH_MTX_C]
              * (m->mtx[ESCH_MTX_D]*m->mtx[ESCH_MTX_H] - m->mtx[ESCH_MTX_E]*m->mtx[ESCH_MTX_G]));
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// esch_inversematrix                                                       �
//                                                                          �
// This function inverse matrix 'm' to the matrix 'd' (treating last column �
// as implied 0 0 0 1).                                                     �
//                                                                          �
// Returns 0 if ok, non-zero if inverse doesn't exist (determinant is 0).   �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
extern "C" int esch_inversematrix(const EschMatrix *m, EschMatrix *d)
{
// [A B C 0]      det is A(EI - FH) - B(DI - FG) + C(DH - EG)
// [D E F 0]
// [G H I 0]
// [J K L 1]      The inverse is :-
//
//
//                [ |E F 0|   |B C 0|   |B C 0|   |B C 0| ]
//                [ |H I 0|  -|H I 0|   |E F 0|  -|E F 0| ]
//                [ |K L 1|   |K L 1|   |K L 1|   |H I 0| ]
//                [                                       ]
//                [ |D F 0|   |A C 0|   |A C 0|   |A C 0| ]
//          1     [-|G I 0|   |G I 0|  -|D F 0|   |D F 0| ]
//        ----- * [ |J L 1|   |J L 1|   |J L 1|   |G I 0| ]
//         det    [                                       ]
//                [ |D E 0|   |A B 0|   |A B 0|   |A B 0| ]
//                [ |G H 0|  -|G H 0|   |D E 0|  -|D E 0| ]
//                [ |J K 1|   |J K 1|   |J K 1|   |G H 0| ]
//                [                                       ]
//                [ |D E F|   |A B C|   |A B C|   |A B C| ]
//                [-|G H I|   |G H I|  -|D E F|   |D E F| ]
//                [ |J K L|   |J K L|   |J K L|   |G H I| ]
//
//    |E F 0|
//    |H I 0| =  E|I 0| - F|H 0| + 0|H I| = EI - FH
//    |K L 1|     |L 1|    |K 1|    |K L|
//
//    |D F 0|
//   -|G I 0| = -D|I 0| + F|G 0| - 0|G I| = -DI + FG
//    |J L 1|     |L 1|    |J 1|    |J L|
//
//    |D E 0|
//    |G H 0| =  D|H 0| - E|G 0| + 0|G H| = DH - EG
//    |J K 1|     |K 1|    |J 1|    |J K|
//
//    |D E F|
//   -|G H I| = -D|H I| + E|G I| - F|G H| = -D(HL-KI) + E(GL-IJ) - F(GK-JH)
//    |J K L|     |K L|    |J L|    |J K|
//
//    |B C 0|
//   -|H I 0| = -B|I 0| + C|H 0| - 0|H I| = -BI + CH
//    |K L 1|     |L 1|    |K 1|    |K L|
//
//    |A C 0|
//    |G I 0| =  A|I 0| - C|G 0| + 0|G I| = AI - CG
//    |J L 1|     |L 1|    |J 1|    |J L|
//
//    |A B 0|
//   -|G H 0| = -A|H 0| + B|G 0| - 0|G H| = -AH + BG
//    |J K 1|     |K 1|    |J 1|    |J K|
//
//    |A B C|
//    |G H I| =  A|H I| - B|G I| + C|G H| = A(HL-KI) - B(GL-JI) + C(GK-JH)
//    |J K L|     |K L|    |J L|    |J K|
//
//    |B C 0|
//    |E F 0| =  B|F 0| - C|E 0| + 0|E F| = BF - CE
//    |K L 1|     |L 1|    |K 1|    |K L|
//
//    |A C 0|
//   -|D F 0| = -A|F 0| + C|D 0| - 0|D F| = -AF + CD
//    |J L 1|     |L 1|    |J 1|    |J L|
//
//    |A B 0|
//    |D E 0| =  A|E 0| - B|D 0| + 0|D E| = AE - BD
//    |J K 1|     |K 1|    |J 1|    |J K|
//
//    |A B C|
//   -|D E F| = -A|E F| + B|D F| - C|D E| = -A(EL-KF) + B(DL-JF) - C(DK-JE)
//    |J K L|     |K L|    |J L|    |J K|
//
//    |B C 0|
//   -|E F 0| = 0
//    |H I 0|
//
//    |A C 0|
//    |D F 0| = 0
//    |G I 0|
//
//    |A B 0|
//   -|D E 0| = 0
//    |G H 0|
//
//    |A B C|
//    |D E F| = det
//    |G H I|
//

    float det = esch_detmatrix(m);
    if (!det)
        return 1;

    EschMatrix  mtx;
    memcpy(&mtx,m,sizeof(mtx));

// <A>
//     1      |E F 0|
//   ----- *  |H I 0| = ( EI - FH ) / det
//    det     |K L 1|

    d->mtx[ESCH_MTX_A] = (mtx.mtx[ESCH_MTX_E]*mtx.mtx[ESCH_MTX_I]
                          - mtx.mtx[ESCH_MTX_F]*mtx.mtx[ESCH_MTX_H]) / det;

// <D>
//     1      |D F 0|
//   ----- * -|G I 0| = ( FG - DI ) / det
//    det     |J L 1|

    d->mtx[ESCH_MTX_D] = (mtx.mtx[ESCH_MTX_F]*mtx.mtx[ESCH_MTX_G]
                          - mtx.mtx[ESCH_MTX_D]*mtx.mtx[ESCH_MTX_I]) / det;

// <G>
//     1      |D E 0|
//   ----- *  |G H 0| = ( DH - EG ) / det
//    det     |J K 1|

    d->mtx[ESCH_MTX_G] = (mtx.mtx[ESCH_MTX_D]*mtx.mtx[ESCH_MTX_H]
                          - mtx.mtx[ESCH_MTX_E]*mtx.mtx[ESCH_MTX_G]) / det;

// <J>
//     1      |D E F|       <IV1>      <IV2>      <IV3>
//   ----- * -|G H I| = ( E(GL-IJ) - D(HL-KI) - F(GK-JH) ) / det
//    det     |J K L|

    float iv1 = mtx.mtx[ESCH_MTX_G]*mtx.mtx[ESCH_MTX_L]
                - mtx.mtx[ESCH_MTX_I]*mtx.mtx[ESCH_MTX_J];

    float iv2 = mtx.mtx[ESCH_MTX_H]*mtx.mtx[ESCH_MTX_L]
                - mtx.mtx[ESCH_MTX_K]*mtx.mtx[ESCH_MTX_I];

    float iv3 = mtx.mtx[ESCH_MTX_G]*mtx.mtx[ESCH_MTX_K]
                - mtx.mtx[ESCH_MTX_J]*mtx.mtx[ESCH_MTX_H];

    d->mtx[ESCH_MTX_J] = (mtx.mtx[ESCH_MTX_E]*iv1
                          - mtx.mtx[ESCH_MTX_D]*iv2
                          - mtx.mtx[ESCH_MTX_F]*iv3) / det;

// <B>
//     1      |B C 0|
//   ----- * -|H I 0| = ( CH - BI ) / det
//    det     |K L 1|

    d->mtx[ESCH_MTX_B] = (mtx.mtx[ESCH_MTX_C]*mtx.mtx[ESCH_MTX_H]
                          - mtx.mtx[ESCH_MTX_B]*mtx.mtx[ESCH_MTX_I]) / det;

// <E>
//     1      |A C 0|
//   ----- *  |G I 0| = ( AI - CG ) / det
//    det     |J L 1|

    d->mtx[ESCH_MTX_E] = (mtx.mtx[ESCH_MTX_A]*mtx.mtx[ESCH_MTX_I]
                          - mtx.mtx[ESCH_MTX_C]*mtx.mtx[ESCH_MTX_G]) / det;

// <H>
//     1      |A B 0|
//   ----- * -|G H 0| = ( BG - AH ) / det
//    det     |J K 1|

    d->mtx[ESCH_MTX_H] = (mtx.mtx[ESCH_MTX_B]*mtx.mtx[ESCH_MTX_G]
                          - mtx.mtx[ESCH_MTX_A]*mtx.mtx[ESCH_MTX_H]) / det;

// <K>
//     1      |A B C|       <IV2>      <IV1>      <IV3>
//   ----- *  |G H I| = ( A(HL-KI) - B(GL-JI) + C(GK-JH) ) / det
//    det     |J K L|

    d->mtx[ESCH_MTX_K] = (mtx.mtx[ESCH_MTX_A]*iv2
                          - mtx.mtx[ESCH_MTX_B]*iv1
                          + mtx.mtx[ESCH_MTX_C]*iv3) / det;

// <C>
//     1      |B C 0|
//   ----- *  |E F 0| = ( BF - CE ) / det
//    det     |K L 1|

    d->mtx[ESCH_MTX_C] = (mtx.mtx[ESCH_MTX_B]*mtx.mtx[ESCH_MTX_F]
                          - mtx.mtx[ESCH_MTX_C]*mtx.mtx[ESCH_MTX_E]) / det;

// <F>
//     1      |A C 0|
//   ----- * -|D F 0| = ( CD - AF ) / det
//    det     |J L 1|

    d->mtx[ESCH_MTX_F] = (mtx.mtx[ESCH_MTX_C]*mtx.mtx[ESCH_MTX_D]
                          - mtx.mtx[ESCH_MTX_A]*mtx.mtx[ESCH_MTX_F]) / det;

// <I>
//     1      |A B 0|
//   ----- *  |D E 0| = ( AE - BD ) / det
//    det     |J K 1|

    d->mtx[ESCH_MTX_I] = (mtx.mtx[ESCH_MTX_A]*mtx.mtx[ESCH_MTX_E]
                          - mtx.mtx[ESCH_MTX_B]*mtx.mtx[ESCH_MTX_D]) / det;

// <L>
//     1      |A B C|
//   ----- * -|D E F| = ( B(DL-JF) - A(EL-KF) - C(DK-JE) ) / det
//    det     |J K L|

    iv1 = (mtx.mtx[ESCH_MTX_D]*mtx.mtx[ESCH_MTX_L]
           - mtx.mtx[ESCH_MTX_J]*mtx.mtx[ESCH_MTX_F]);

    iv2 = (mtx.mtx[ESCH_MTX_E]*mtx.mtx[ESCH_MTX_L]
           - mtx.mtx[ESCH_MTX_K]*mtx.mtx[ESCH_MTX_F]);

    iv3 = (mtx.mtx[ESCH_MTX_D]*mtx.mtx[ESCH_MTX_K]
           - mtx.mtx[ESCH_MTX_J]*mtx.mtx[ESCH_MTX_E]);

    d->mtx[ESCH_MTX_L] = (mtx.mtx[ESCH_MTX_B]*iv1
                          - mtx.mtx[ESCH_MTX_A]*iv2
                          - mtx.mtx[ESCH_MTX_C]*iv3) / det;

    return 0;
}

//葦� End of module - esmatrix.cpp 憶�


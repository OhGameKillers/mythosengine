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
// esmath.hpp
//
//      EschPoint is a 3D point with an optional color, which can be operated
//      on in various ways including addition, transformation, and
//      rotation.
//
//      EschVector is a 3D vector which can be operated in various ways,
//      including addition, transformation, rotation, and forming dot/cross
//      products.
//
//      EschPlane is a 3D plane.
//
//      EschVertex is a 3D point with a normal.
//
//      EschMatrix is a special case 4x4 matrix where the last column is
//      always 0 0 0 1, resulting a 3x4 representation.
//
//      EschFrameRef is a 3x4 transform matrix with a direction vector, and
//      associated inverse transform matrix.  Includes utility routines
//      to perform various affine transformations.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

#ifndef __ESMATH_HPP
#define __ESMATH_HPP    1

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <math.h>

#include <portable.h>

#include "esdefs.h"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#define DOT    |
#define CROSS  &

//陳 EschMatrix layout
//
// [A B C 0]
// [D E F 0]
// [G H I 0]
// [J K L 1]

#define ESCH_MTX_A      0
#define ESCH_MTX_B      1
#define ESCH_MTX_C      2
#define ESCH_MTX_D      3
#define ESCH_MTX_E      4
#define ESCH_MTX_F      5
#define ESCH_MTX_G      6
#define ESCH_MTX_H      7
#define ESCH_MTX_I      8
#define ESCH_MTX_J      9
#define ESCH_MTX_K      10
#define ESCH_MTX_L      11

#define ESCH_MTX_NUM    12

//#define ESCH_INLINE_MATH 1
//#define ESCH_NEVER_INLINE_MATH 1

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Prototypes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

class EschVector;
class EschMatrix;
class EschFrameRef;

//陳 Point and vector operations
extern "C" void esch_rotatex(const void *s, const float deg, void *d);
extern "C" void esch_rotatey(const void *s, const float deg, void *d);
extern "C" void esch_rotatez(const void *s, const float deg, void *d);
extern "C" void (*esch_transform)(const void *s,
                                  const EschMatrix *m, void *d);
extern "C" void (*esch_transform_notran)(const void *s,
                                         const EschMatrix *m, void *d);

//陳 Vector functions
extern "C" EschVector *(*esch_cross)(const EschVector *v1,
                                     const EschVector *v2,
                                     EschVector *dest);
extern "C" float esch_dot(const EschVector *v1, const EschVector *v2);
extern "C" float esch_magnitude(const EschVector *vect);
extern "C" void (*esch_normalize)(EschVector *vect);

//陳 Matrix functions
extern "C" void (*esch_concatmatrix)(const EschMatrix *s,
                                     const EschMatrix *m,
                                     EschMatrix *d);
extern "C" float esch_detmatrix(const EschMatrix *m);
extern "C" int esch_inversematrix(const EschMatrix *m, EschMatrix *d);

//陳 Trig functions
inline float esch_sin(float degrees) { return float(sin(degrees * 0.017453292f)); }
inline float esch_cos(float degrees) { return float(cos(degrees * 0.017453292f)); }
inline float esch_tan(float degrees) { return float(tan(degrees * 0.017453292f)); }
inline float esch_asin(float n) { return (float(asin(n)) * 57.29577951f); }
inline float esch_acos(float n) { return (float(acos(n)) * 57.29577951f); }
inline float esch_atan(float n) { return (float(atan(n)) * 57.29577951f); }

//陳 AMD-3D batch functions
extern "C" void esch_amd3d_fpureset();
extern "C" void esch_amd3d_nofpu_transform(const void *s,
                                           const EschMatrix *m, void *d);
extern "C" void esch_amd3d_nofpu_transform_notran(const void *s,
                                           const EschMatrix *m, void *d);
extern "C" void esch_amd3d_nofpu_normalize(EschVector *vect);

//陳 Misc functions
inline float esch_sqrt(float n) { return float(sqrt(n)); }

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Classes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschPoint - 3D point (needs to match first three members of VngoPoint)   �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class EschPoint {

public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Public data members                                                  �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    float   x;                          // Must match VngoPoint.wx
    float   y;                          // Must match VngoPoint.wy
    float   z;                          // Must match VngoPoint.wz
    dword   na;

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschPoint() {}
    EschPoint(float ix, float iy, float iz) : x(ix), y(iy), z(iz) {}

    ~EschPoint() {}

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Arithmetic operators on points.                                      �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

    //陳� Addition/Subtraction of points.
    EschPoint operator + (const EschVector &v) const;
    EschPoint operator + (const EschPoint &b) const
    {
        return EschPoint(x + b.x,
                         y + b.y,
                         z + b.z);
    }

    EschPoint operator += (const EschVector &v);
    EschPoint operator += (const EschPoint &b)
    {
        x = x + b.x;
        y = y + b.y;
        z = z + b.z;
        return (*this);
    }

    EschPoint operator - (const EschVector &v) const;
    EschPoint operator - (const EschPoint &b) const
    {
        return EschPoint(x - b.x,
                         y - b.y,
                         z - b.z);
    }

    EschPoint operator -= (const EschVector &v);
    EschPoint operator -= (const EschPoint &b)
    {
        x = x - b.x;
        y = y - b.y;
        z = z - b.z;
        return (*this);
    }

    //陳� Negation
    EschPoint operator - () const
    {
        return EschPoint(-x,-y,-z);
    }

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Point operations                                                     �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

    float distance(const EschPoint *p) const;

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Transformation operations.                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    void transform(const EschMatrix *m);
    void transform(const EschFrameRef *m) { transform((EschMatrix*)m); }

    void transform(const EschMatrix *m, EschPoint *result) const;
    void transform(const EschFrameRef *m, EschPoint *result) const
    {
        transform((EschMatrix*)m,result);
    }

    void rotatex(const float degrees) { ::esch_rotatex(this,degrees,this); }
    void rotatex(const float degrees, EschPoint *result) const
    {
        ::esch_rotatex(this,degrees,result);
    }

    void rotatey(const float degrees) { ::esch_rotatey(this,degrees,this); }
    void rotatey(const float degrees, EschPoint *result) const
    {
        ::esch_rotatey(this,degrees,result);
    }

    void rotatez(const float degrees) { ::esch_rotatez(this,degrees,this); }
    void rotatez(const float degrees, EschPoint *result) const
    {
        ::esch_rotatez(this,degrees,result);
    }
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschVector - 3D i,j,k vector.                                            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class EschVector {

public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Public data members                                                  �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    float   i;
    float   j;
    float   k;
    dword   na;

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschVector() {}
    EschVector(float ii, float ij, float ik) : i(ii), j(ij), k(ik) {}
    EschVector(const EschPoint &p1, const EschPoint &p2) :
        i(p2.x - p1.x), j(p2.y - p1.y), k(p2.z - p1.z) {}

    ~EschVector() {}

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Arithmetic operations on vectors                                     �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

    //陳� Addition/Subtraction of vectors.
    EschVector operator + (const EschVector &b) const
    {
        return EschVector(i + b.i,
                          j + b.j,
                          k + b.k);
    }
    EschVector operator += (const EschVector &b)
    {
        i = i + b.i;
        j = j + b.j;
        k = k + b.k;
        return (*this);
    }

    EschVector operator - (const EschVector &b) const
    {
        return EschVector(i - b.i,
                          j - b.j,
                          k - b.k);
    }
    EschVector operator -= (const EschVector &b)
    {
        i = i - b.i;
        j = j - b.j;
        k = k - b.k;
        return (*this);
    }

    //陳� Negation
    EschVector operator - () const
    {
        return EschVector(-i,-j,-k);
    }

    //陳� Addition/Subtraction with a scalar.
    EschVector operator + (const float scalar) const
    {
        return EschVector(i + scalar,
                          j + scalar,
                          k + scalar);
    }
    EschVector operator += (const float scalar)
    {
        i = i + scalar;
        j = j + scalar;
        k = k + scalar;
        return (*this);
    }

    EschVector operator - (const float scalar) const
    {
        return EschVector(i - scalar,
                          j - scalar,
                          k - scalar);
    }
    EschVector operator -= (const float scalar)
    {
        i = i - scalar;
        j = j - scalar;
        k = k - scalar;
        return (*this);
    }

    //陳� Multiplication/Division by a scalar.
    EschVector operator * (const float scalar) const
    {
        return EschVector(i * scalar,
                          j * scalar,
                          k * scalar);
    }

    EschVector operator *= (const float scalar)
    {
        i = i * scalar;
        j = j * scalar;
        k = k * scalar;
        return (*this);
    }

    EschVector operator / (const float scalar) const
    {
        return EschVector(i / scalar,
                          j / scalar,
                          k / scalar);
    }

    EschVector operator /= (const float scalar)
    {
        i = i / scalar;
        j = j / scalar;
        k = k / scalar;
        return (*this);
    }

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Vector operations                                                    �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

    EschVector operator CROSS (const EschVector &v) const
    {
#ifdef ESCH_INLINE_MATH
        return EschVector((j*v.k) - (k*v.j),
                          (k*v.i) - (i*v.k),
                          (i*v.j) - (j*v.i));
#else
        EschVector result;
        return (*::esch_cross(this,&v,&result));
#endif
    }

    float operator DOT (const EschVector &v) const
    {
#ifndef ESCH_NEVER_INLINE_MATH
        return ((i*v.i) + (j*v.j) + (k*v.k));
#else
        return ::esch_dot(this,&v);
#endif
    }

    float magnitude() const
    {
#ifndef ESCH_NEVER_INLINE_MATH
        return esch_sqrt((i*i) + (j*j) + (k*k));
#else
        return (esch_magnitude(this));
#endif
    }

    void normalize()
    {
#ifdef ESCH_INLINE_MATH
        float   mag;
        mag = magnitude();

#ifdef assertMyth
        assertMyth("EschVector::normalize found magnitude of zero",
                   mag > 0);
#endif

        if (mag)    // can't normalize a vector of magnitude 0.
        {
            i = i / mag;
            j = j / mag;
            k = k / mag;
        }
#else
        ::esch_normalize(this);
#endif
    }

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Transformation operations                                            �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

    //陳� Scale vector
    void scale(float scale)
    {
        i = i * scale;
        j = j * scale;
        k = k * scale;
    }

    //陳� Translate vector
    void translate(float ix, float iy, float iz)
    {
        i = i + ix;
        j = j + iy;
        k = k + iz;
    }
    void translate(const EschVector *v)
    {
        i = i + v->i;
        j = j + v->j;
        k = k + v->k;
    }

    //陳� Transform by a matrix
    void transform(const EschMatrix *m);
    void transform(const EschFrameRef *m) { transform((EschMatrix*)m); }

    void transform(const EschMatrix *m, EschVector *result) const;
    void transform(const EschFrameRef *m, EschVector *result) const
    {
        transform((EschMatrix*)m,result);
    }

    //陳� Rotate vector
    void rotatex(const float degrees) { ::esch_rotatex(this,degrees,this); }
    void rotatex(const float degrees, EschVector *result) const
    {
        ::esch_rotatex(this,degrees,result);
    }

    void rotatey(const float degrees) { ::esch_rotatey(this,degrees,this); }
    void rotatey(const float degrees, EschVector *result) const
    {
        ::esch_rotatey(this,degrees,result);
    }

    void rotatez(const float degrees) { ::esch_rotatez(this,degrees,this); }
    void rotatez(const float degrees, EschVector *result) const
    {
        ::esch_rotatez(this,degrees,result);
    }
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschPlane - 3D plane.                                                    �
//                                                                          �
// normal.i*X + normal.j*Y + normal.k*Z + dist = 0                          �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class EschPlane {

public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Public data members                                                  �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschVector  normal;
    float       dist;

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschPlane() {}
    EschPlane(float ia, float ib, float ic, float ix, float iy, float iz) :
        normal(ia,ib,ic), dist(-(ia*ix + ib*iy + ic*iz)) {}
    EschPlane(float ia, float ib, float ic, float id) :
        normal(ia,ib,ic), dist(id) {}
    EschPlane(const EschVector &in, float id) :
        normal(in), dist(id) {}

    ~EschPlane() {}

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Plane operations                                                     �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    void normalize()
    {
        float mag = normal.magnitude();

#ifdef assertMyth
        assertMyth("EschPlane::normalize found magnitude of zero",
                   mag > 0);
#endif

        if (mag)
        {
            normal.i /= mag;
            normal.j /= mag;
            normal.k /= mag;
            dist /= mag;
        }
    }

    void nearest(const EschPoint *p, EschPoint *result) const
    {
#ifdef assertMyth
        assertMyth("EschPlane::nearest needs valid input", p!=0 && result!=0);
#endif

        float d = ::esch_dot(&normal,(EschVector*)p) + dist;

        result->x = p->x - (d * normal.i);
        result->y = p->y - (d * normal.j);
        result->z = p->z - (d * normal.k);
    }

    float distance(const EschPoint *p) const
    {
        return (::esch_dot(&normal,(EschVector*)p) + dist);
    }

    void project(EschVector *v, EschVector *result) const
    {
#ifdef assertMyth
        assertMyth("EschPlane::project needs valid input", v!=0 && result!=0);
#endif
        float dot = ::esch_dot(&normal,v);

        result->i = v->i - (dot * normal.i);
        result->j = v->j - (dot * normal.j);
        result->k = v->k - (dot * normal.k);
    }

    float ray(const EschPoint *pt, const EschVector *v) const
    {
#ifdef assertMyth
        assertMyth("EschPlane::ray needs valid input", pt != 0 && v != 0);
#endif
        float dot = ::esch_dot(&normal,v);
        if (dot == 0)
            return -1;

        float t = - ((dist + ::esch_dot(&normal,(EschVector*)pt)) / dot);

        if (t < 0)
            return -1;

        return t;
    }

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Transformation operations                                            �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

    //陳� Transform by a matrix
    void transform(const EschMatrix *m, const EschMatrix *im);
    void transform(const EschFrameRef *m);

    void transform(const EschMatrix *m, const EschMatrix *im, EschPlane *result) const;
    void transform(const EschFrameRef *m, EschPlane *result) const;
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschVertex - A 3D point and a normal at the point.                       �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class EschVertex : public EschPoint {

public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Public data member                                                   �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschVector  normal;

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschVertex() {}
    EschVertex(float ix, float iy, float iz,
               float ii, float ij, float ik)
               : EschPoint(ix,iy,iz), normal(ii,ij,ik) {}
    EschVertex(float ix, float iy, float iz, const EschVector *n)
               : EschPoint(ix,iy,iz) { normal=*n; }
    EschVertex(const EschPoint *p, const EschVector *n)
               : EschPoint(*p) { normal=*n; }
    EschVertex(const EschPoint *p, float ii, float ij, float ik)
               : EschPoint(*p), normal(ii,ij,ik) {}

    ~EschVertex() {}
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschMatrix - A matrix is a 4x3 homogenous matrix.                        �
//                                                                          �
// [A B C 0]                                                                �
// [D E F 0]                                                                �
// [G H I 0]                                                                �
// [J K L 1]                                                                �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class EschMatrix {

public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Public data member                                                   �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    float   mtx[3*4];

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschMatrix() { reset(); }
    EschMatrix(int dummy) {}
    EschMatrix(float a, float b, float c, float d, float e, float f,
               float g, float h, float i, float j, float k, float l)
               { mtx[ESCH_MTX_A]=a; mtx[ESCH_MTX_B]=b; mtx[ESCH_MTX_C]=c;
                 mtx[ESCH_MTX_D]=d; mtx[ESCH_MTX_E]=e; mtx[ESCH_MTX_F]=f;
                 mtx[ESCH_MTX_G]=g; mtx[ESCH_MTX_H]=h; mtx[ESCH_MTX_I]=i;
                 mtx[ESCH_MTX_J]=j; mtx[ESCH_MTX_K]=k; mtx[ESCH_MTX_L]=l; }

    ~EschMatrix() {}

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Arithmetic operations on matricies                                   �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

    //陳� Multiplication by a matrix.
    EschMatrix operator * (const EschMatrix &b) const
    {
        EschMatrix m;
        ::esch_concatmatrix(this,&b,&m);
        return m;
    }
    EschMatrix operator *= (const EschMatrix &b)
    {
        ::esch_concatmatrix(this,&b,this);
        return (*this);
    }

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations on matrix objects.                                        �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

    //陳� Matrix math operations
    void concat(const EschMatrix *m)
    {
        ::esch_concatmatrix(this,m,this);
    }
    void concat(const EschMatrix *m, EschMatrix *result) const
    {
        ::esch_concatmatrix(this,m,result);
    }

    float det() { return (esch_detmatrix(this)); }

    int inverse() { return ::esch_inversematrix(this,this); }
    int inverse(EschMatrix *result) const
    {
        return ::esch_inversematrix(this,result);
    }

    //陳� Reset to identity.
    void reset()
    {
        for(int i=0; i < ESCH_MTX_NUM; i++)
            mtx[i]=0;
        mtx[ESCH_MTX_A]=mtx[ESCH_MTX_E]=mtx[ESCH_MTX_I]=1;
    }
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschFrameRef - Frame of reference                                        �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class EschFrameRef {

public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Public data members                                                  �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschMatrix      orient;                 // Transform matrix
    EschVector      dir;
    EschMatrix      iorient;                // Inverse matrix
    float           scalef;                 // Scale factor (saved for
                                            // orthogonalization)
    dword           ortho_count;

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschFrameRef() : orient(), iorient(), dir(0,0,1),
                     scalef(1), ortho_count(0) {}
    EschFrameRef(int dummy) : orient(0), iorient(0) {};
    EschFrameRef(float a, float b, float c, float d, float e, float f,
                 float g, float h, float i, float j, float k, float l,
                 float s=1) :
                dir(g,h,i), scalef(s), ortho_count(0)
    {
        orient.mtx[ESCH_MTX_A]=a; orient.mtx[ESCH_MTX_D]=d;
        orient.mtx[ESCH_MTX_B]=b; orient.mtx[ESCH_MTX_E]=e;
        orient.mtx[ESCH_MTX_C]=c; orient.mtx[ESCH_MTX_F]=f;
        orient.mtx[ESCH_MTX_G]=g; orient.mtx[ESCH_MTX_J]=j;
        orient.mtx[ESCH_MTX_H]=h; orient.mtx[ESCH_MTX_K]=k;
        orient.mtx[ESCH_MTX_I]=i; orient.mtx[ESCH_MTX_L]=l;
        compute_inverse();
    }
    EschFrameRef(EschMatrix *m, float s=1) :
                scalef(s), ortho_count(0)
    {
        orient=*m;
        dir.i=m->mtx[ESCH_MTX_G];
        dir.j=m->mtx[ESCH_MTX_H];
        dir.k=m->mtx[ESCH_MTX_I];
        compute_inverse();
    }

    ~EschFrameRef() {}

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Utility functions for working with frames of reference.              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    void get_position(EschPoint *pt) const
    {
        pt->x = orient.mtx[ESCH_MTX_J];
        pt->y = orient.mtx[ESCH_MTX_K];
        pt->z = orient.mtx[ESCH_MTX_L];
    }
    void get_position(float *ix, float *iy, float *iz) const
    {
        *ix = orient.mtx[ESCH_MTX_J];
        *iy = orient.mtx[ESCH_MTX_K];
        *iz = orient.mtx[ESCH_MTX_L];
    }

    void set_position(const EschPoint *pt, dword update=ESCH_UPD_ALL);
    void set_position(const float ix, const float iy, const float iz,
                      dword update=ESCH_UPD_ALL);

    void set_top(const EschVector *v, dword update=ESCH_UPD_ALL);
    void set_top(float ii, float ij, float ik, dword update=ESCH_UPD_ALL);

    void set_direction(const EschVector *v, dword update=ESCH_UPD_ALL);
    void set_direction(float ii, float ij, float ik, dword update=ESCH_UPD_ALL);

    void rotatex(const float degrees, dword update=ESCH_UPD_ALL);
    void rotatey(const float degrees, dword update=ESCH_UPD_ALL);
    void rotatez(const float degrees, dword update=ESCH_UPD_ALL);

    void rotate(const EschVector *v, const float degrees,
                dword update=ESCH_UPD_ALL);

    void pitch(const float degrees, dword update=ESCH_UPD_ALL);
    void roll(const float degrees, dword update=ESCH_UPD_ALL);
    void yaw(const float degrees, dword update=ESCH_UPD_ALL);

    void translate(const EschVector *v, dword update=ESCH_UPD_ALL);
    void translate(const float idx, const float idy, const float idz,
                   dword update=ESCH_UPD_ALL);

    void move(const EschVector *v, dword update=ESCH_UPD_ALL);
    void move(const float idx, const float idy, const float idz,
              dword update=ESCH_UPD_ALL);

    void scale(const float is, dword update=ESCH_UPD_ALL);

    void orthogonalize(dword update=ESCH_UPD_ALL);
    void orthogonalize_top(dword update=ESCH_UPD_ALL);
    void orthogonalize_right(dword update=ESCH_UPD_ALL);

    void concat(const EschFrameRef *m);
    void concat(const EschFrameRef *m, EschFrameRef *result) const;

    void reset();

    void compute_inverse();
};


//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Inlines
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschPoint
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
inline EschPoint EschPoint::operator += (const EschVector &v)
{
    x += v.i;
    y += v.j;
    z += v.k;
    return (*this);
}

inline EschPoint EschPoint::operator + (const EschVector &v) const
{
    return EschPoint (x + v.i,
                      y + v.j,
                      z + v.k);
}

inline EschPoint EschPoint::operator -= (const EschVector &v)
{
    x -= v.i;
    y -= v.j;
    z -= v.k;
    return (*this);
}

inline EschPoint EschPoint::operator - (const EschVector &v) const
{
    return EschPoint (x - v.i,
                      y - v.j,
                      z - v.k);
}

inline float EschPoint::distance(const EschPoint *p) const
{
#ifndef ESCH_NEVER_INLINE_MATH
    float _i = p->x - x;
    float _j = p->y - y;
    float _k = p->z - z;

    return esch_sqrt((_i*_i) + (_j*_j) + (_k*_k));
#else
    return ::esch_magnitude(&EschVector(p->x - x, p->y - y, p->z - z));
#endif
}

inline void EschPoint::transform(const EschMatrix *m)
{
#ifdef assertMyth
    assertMyth("EschPoint::transform needs valid input", m != 0);
#endif

#ifdef ESCH_INLINE_MATH
    float _x = x;
    float _y = y;
    float _z = z;

    x = m->mtx[ESCH_MTX_A]*_x
        + m->mtx[ESCH_MTX_D]*_y
        + m->mtx[ESCH_MTX_G]*_z
        + m->mtx[ESCH_MTX_J];

    y = m->mtx[ESCH_MTX_B]*_x
        + m->mtx[ESCH_MTX_E]*_y
        + m->mtx[ESCH_MTX_H]*_z
        + m->mtx[ESCH_MTX_K];

    z = m->mtx[ESCH_MTX_C]*_x
        + m->mtx[ESCH_MTX_F]*_y
        + m->mtx[ESCH_MTX_I]*_z
        + m->mtx[ESCH_MTX_L];
#else
    ::esch_transform(this,m,this);
#endif
}

inline void EschPoint::transform(const EschMatrix *m, EschPoint *result) const
{
#ifdef assertMyth
    assertMyth("EschPoint::transform needs valid input", m!=0 && result!=0);
#endif

#ifdef ESCH_INLINE_MATH
    result->x = m->mtx[ESCH_MTX_A]*x
                + m->mtx[ESCH_MTX_D]*y
                + m->mtx[ESCH_MTX_G]*z
                + m->mtx[ESCH_MTX_J];

    result->y = m->mtx[ESCH_MTX_B]*x
                + m->mtx[ESCH_MTX_E]*y
                + m->mtx[ESCH_MTX_H]*z
                + m->mtx[ESCH_MTX_K];

    result->z = m->mtx[ESCH_MTX_C]*x
                + m->mtx[ESCH_MTX_F]*y
                + m->mtx[ESCH_MTX_I]*z
                + m->mtx[ESCH_MTX_L];
#else
    ::esch_transform(this,m,result);
#endif
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschVector
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
inline void EschVector::transform(const EschMatrix *m)
{
#ifdef assertMyth
    assertMyth("EschVector::transform needs valid input", m != 0);
#endif

#ifdef ESCH_INLINE_MATH
    float _i = i;
    float _j = j;
    float _k = k;

    i = m->mtx[ESCH_MTX_A]*_i
        + m->mtx[ESCH_MTX_D]*_j
        + m->mtx[ESCH_MTX_G]*_k;

    j = m->mtx[ESCH_MTX_B]*_i
        + m->mtx[ESCH_MTX_E]*_j
        + m->mtx[ESCH_MTX_H]*_k;

    k = m->mtx[ESCH_MTX_C]*_i
        + m->mtx[ESCH_MTX_F]*_j
        + m->mtx[ESCH_MTX_I]*_k;
#else
    ::esch_transform_notran(this,m,this);
#endif
}

inline void EschVector::transform(const EschMatrix *m, EschVector *result) const
{
#ifdef assertMyth
    assertMyth("EschVector::transform needs valid input", m!=0 && result!=0);
#endif

#ifdef ESCH_INLINE_MATH
    result->i = m->mtx[ESCH_MTX_A]*i
                + m->mtx[ESCH_MTX_D]*j
                + m->mtx[ESCH_MTX_G]*k;

    result->j = m->mtx[ESCH_MTX_B]*i
                + m->mtx[ESCH_MTX_E]*j
                + m->mtx[ESCH_MTX_H]*k;

    result->k = m->mtx[ESCH_MTX_C]*i
                + m->mtx[ESCH_MTX_F]*j
                + m->mtx[ESCH_MTX_I]*k;
#else
    ::esch_transform_notran(this,m,result);
#endif
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschPlane
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
inline void EschPlane::transform(const EschMatrix *m, const EschMatrix *im)
{
#ifdef assertMyth
    assertMyth("EschPlane::transform needs valid input", m != 0 && im != 0);
#endif

    float _i = normal.i;
    float _j = normal.j;
    float _k = normal.k;

// Must compute point and plane form for transform...
    EschPoint pos(0,0,0);
    if (_i != 0)
        pos.x = -dist / _i;
    else if (_j != 0)
        pos.y = -dist / _j;
    else if (_k != 0)
        pos.z = -dist / _k;

// Transform point
    pos.transform(m);

// This is a multiply by the transpose of the matrix 'im'
    normal.i = im->mtx[ESCH_MTX_A]*_i
               + im->mtx[ESCH_MTX_B]*_j
               + im->mtx[ESCH_MTX_C]*_k;

    normal.j = im->mtx[ESCH_MTX_D]*_i
               + im->mtx[ESCH_MTX_E]*_j
               + im->mtx[ESCH_MTX_F]*_k;

    normal.k = im->mtx[ESCH_MTX_G]*_i
               + im->mtx[ESCH_MTX_H]*_j
               + im->mtx[ESCH_MTX_I]*_k;

// Compute dist from new normal and point
    dist = -(normal.i*pos.x + normal.j*pos.y + normal.k*pos.z);
}

inline void EschPlane::transform(const EschFrameRef *m)
{
#ifdef assertMyth
    assertMyth("EschPlane::transform needs valid input", m != 0);
#endif
    transform(&m->orient, &m->iorient);
}

inline void EschPlane::transform(const EschMatrix *m,
                                 const EschMatrix *im,
                                 EschPlane *result) const
{
#ifdef assertMyth
    assertMyth("EschPlane::transform needs valid input", m != 0 && im !=0 && result!=0);
#endif

// Must compute point and plane form for transform...
    EschPoint pos(0,0,0);
    if (normal.i != 0)
        pos.x = -dist / normal.i;
    else if (normal.j != 0)
        pos.y = -dist / normal.j;
    else if (normal.k != 0)
        pos.z = -dist / normal.k;

// Transform point
    pos.transform(m);

// This is a multiply by the transpose of the matrix 'im'
    result->normal.i = im->mtx[ESCH_MTX_A]*normal.i
                       + im->mtx[ESCH_MTX_B]*normal.j
                       + im->mtx[ESCH_MTX_C]*normal.k;

    result->normal.j = im->mtx[ESCH_MTX_D]*normal.i
                       + im->mtx[ESCH_MTX_E]*normal.j
                       + im->mtx[ESCH_MTX_F]*normal.k;

    result->normal.k = im->mtx[ESCH_MTX_G]*normal.i
                       + im->mtx[ESCH_MTX_H]*normal.j
                       + im->mtx[ESCH_MTX_I]*normal.k;

// Compute dist from new normal and point
    result->dist = -(result->normal.i*pos.x + result->normal.j*pos.y + result->normal.k*pos.z);
}

inline void EschPlane::transform(const EschFrameRef *m, EschPlane *result) const
{
#ifdef assertMyth
    assertMyth("EschPlane::transform needs valid input", m!=0 && result!=0);
#endif
    transform(&m->orient, &m->iorient, result);
}

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//葦� End of header - esmath.hpp 憶�


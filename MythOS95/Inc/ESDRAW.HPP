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
// esdraw.hpp
//
// Contains the EschDrawable class definition.  EschDrawables form the
// basic interface for drawing classes.  EschDrawables are formed into
// lists which are drawn via the EschCamera object.  Derived classes
// expand on the available operations and organization.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

#ifndef __ESDRAW_HPP
#define __ESDRAW_HPP    1

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

#include <portable.h>
#include <ivory.hpp>

#include "esmath.hpp"
#include "esexts.hpp"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Structures
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

class EschDrawable;
class EschCamera;

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschDrawList - Control structure for making lists of drawables without   �
//                changing internal links for collide/pick operations.      �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
struct EschDrawList
{
    EschDrawable    *item;
    EschDrawList    *next;
    float           dist;           // Used for picking
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschCollision - Communication structure for collision detection.         �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
struct EschCollision
{
    dword               flags;      // Control flags
    ulong               count;      // Number of drawables in results
    EschDrawList        *result;    // Output list
    EschDrawable        *ilist;     // Input list
    IvoryArena          *arena;     // Arena for DrawList structures
    ulong               maxcount;   // Maximum number of returns (otherwise 1)
    EschSphereExtents   sphere;     // Test extents (usually set by setup)
    EschDrawable        *orig;      // Original object (usually set by setup)

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschCollision() : flags(0) {}
    EschCollision(EschDrawable *i, ulong mcount=1) :
        flags(ESCH_CLSN_ILIST | ESCH_CLSN_MAXCOUNT),
        ilist(i),
        maxcount(mcount) {}
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschPicking - Communication structure for picking.                       �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
struct EschPicking
{
    dword           flags;          // Control flags
    ulong           count;          // Number of drawables in results
    EschDrawList    *result;        // Output list
    EschDrawable    *ilist;         // Input list
    IvoryArena      *arena;         // Arena for DrawList structures
    ulong           maxcount;       // Maximum number of returns (otherwise 1)
    long            sx, sy;         // Camera viewport coordinates
    EschCamera      *camera;        // Camera to use for picking
    EschPoint       start;          // World start point for picking
    EschVector      direction;      // World direction vector for picking
    float           maxdist;        // Maximum distance to check

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschPicking() : flags(0) {}
    EschPicking(EschCamera *cam,
                long x, long y,
                EschDrawable *i,
                ulong mcount=1) :
        flags(ESCH_PICK_ILIST | ESCH_PICK_MAXCOUNT
              | ESCH_PICK_CAMERA | ESCH_PICK_VPORT),
        ilist(i),
        maxcount(mcount),
        sx(x),
        sy(y),
        camera(cam) {}
    EschPicking(EschCamera *cam,
                long x, long y,
                EschDrawable *i,
                float maxd,
                ulong mcount) :
        flags(ESCH_PICK_ILIST | ESCH_PICK_MAXCOUNT
              | ESCH_PICK_CAMERA | ESCH_PICK_VPORT | ESCH_PICK_MAXDIST),
        ilist(i),
        maxcount(mcount),
        sx(x),
        sy(y),
        camera(cam),
        maxdist(maxd) {}
    EschPicking(EschPoint &s,
                EschVector &dir,
                EschDrawable *i,
                ulong mcount=1) :
        flags(ESCH_PICK_ILIST | ESCH_PICK_MAXCOUNT | ESCH_PICK_WORLD),
        ilist(i),
        maxcount(mcount),
        start(s),
        direction(dir) {}
    EschPicking(EschPoint &s,
                EschVector &dir,
                EschDrawable *i,
                float maxd,
                ulong mcount) :
        flags(ESCH_PICK_ILIST | ESCH_PICK_MAXCOUNT
              | ESCH_PICK_WORLD | ESCH_PICK_MAXDIST),
        ilist(i),
        maxcount(mcount),
        start(s),
        direction(dir),
        maxdist(maxd) {}
};

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Classes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschDrawable - Abstract base class for drawable objects.                 �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class EschDrawable {

protected:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Protected data members                                               �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    EschDrawable    *inext;             // Linked-list pointers.
    EschDrawable    *iprev;

    word    dtyp;                       // Run-time type.

public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Public data members                                                  �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    word    limits;             // Shading-limit mask
    dword   flags;              // Status flags
    char    *name;              // Pointer to obj name, if any
    void    *partn_data;        // Partitioning pointer
    void    *app_data;          // Application data pointer

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
protected:
    EschDrawable(word t);

public:
    EschDrawable(const EschDrawable &drw);

    virtual ~EschDrawable();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Accessor functions                                                   �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    word get_type() const { return dtyp; }

    EschDrawable *next() const { return inext; }
    EschDrawable *prev() const { return iprev; }

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    const EschDrawable &operator = (const EschDrawable &drw);

    virtual void sibling(EschDrawable *myprev);
    virtual void remove();

    virtual EschDrawable *find(const char *dname) const;

    virtual void draw()=0;

    virtual int get_extents(EschSphereExtents *sp) const;

    virtual float ray(const EschPoint *pt, const EschVector *v, int coarse=0) const;

    virtual int hit(const EschPoint *pt, const float r, int coarse=0) const;

    virtual esch_error_codes pick(EschPicking *data) const;
    virtual esch_error_codes collide(EschCollision *data) const;

    virtual void animate();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Utility routines.                                                    �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    void set_flags(const dword f) { flags = f; }
    void set_flags(const dword m, const int on)
    {
        if (on)
            flags |= m;
        else
            flags &= ~m;
    }

    void set_limits(const word l) { limits = l; }
    void set_limits(const word m, const int on)
    {
        if (on)
            limits |= m;
        else
            limits &= ~m;
    }

    void set_partn_data(void *p) { partn_data = p; }
    void set_app_data(void *p) { app_data = p; }
};

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//葦� End of header - esdraw.hpp 憶�


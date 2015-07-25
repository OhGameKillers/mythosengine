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
// espartn.hpp
//
// Contains the code for the partitioning drawables which optimize
// performance of the drawables within the partitioning.
//
// EschPartition is the abstract base class for the partitioning mechanism.
//
// EschGridPartition is a basic partioning scheme that breaks space into
// a fixed number of uniform regions in the XZ plane.
//
//���������������������������������������������������������������������������

#ifndef __ESPARTN_HPP
#define __ESPARTN_HPP    1

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//���������������������������������������������������������������������������
//             
//                                Includes
//                                
//���������������������������������������������������������������������������

#include "esdraw.hpp"

//���������������������������������������������������������������������������
//
//                                Typedefs
//
//���������������������������������������������������������������������������

typedef int (*EschTraverseCallback) (void *, EschDrawable *);

//���������������������������������������������������������������������������
//
//                               Structures
//
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschPartitionList - Control structure used for making lists of drawables �
//                     within a partition without changing internal links.  �
//���������������������������������������������������������������������������
struct EschPartitionList
{
    EschDrawable        *item;
    EschPartitionList   *prev;
    EschPartitionList   *next;
};


//�������������������������������������������������������������������������Ŀ
// EschTraverse - Control structure for traversing a partitioning.          �
//���������������������������������������������������������������������������
struct EschTraverse
{
    dword                   flags;      // Control flags
    EschTraverseCallback    func;       // Traverse function
    void                    *data;      // Data for traverse function
    EschPoint               pos;        // Start position
    EschVector              dir;        // Traverse direction
    Flx16                   dist;       // Distance from start point

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    EschTraverse() : flags(0) {}
    EschTraverse(EschPoint &p,
                 EschTraverseCallback f, void *df=0) :
        flags(0),
        func(f),
        data(df),
        pos(p) {}
    EschTraverse(EschPoint &p,
                 Flx16 d,
                 EschTraverseCallback f, void *df=0) :
        flags(ESCH_TRAV_DIST),
        func(f),
        data(df),
        pos(p),
        dist(d) {}
    EschTraverse(EschPoint &p,
                 EschVector &v,
                 EschTraverseCallback f, void *df=0) :
        flags(ESCH_TRAV_DIRECTION),
        func(f),
        data(df),
        pos(p),
        dir(v) {}
    EschTraverse(EschPoint &p,  
                 EschVector &v, Flx16 d,
                 EschTraverseCallback f, void *df=0) :
        flags(ESCH_TRAV_DIRECTION | ESCH_TRAV_DIST),
        func(f),
        data(df),
        pos(p),
        dir(v),
        dist(d) {}
};

//���������������������������������������������������������������������������
//
//                                Classes
//
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschPartition - Partitioning interface class.                            �
//���������������������������������������������������������������������������
class EschPartition : public EschDrawable
{
public:
    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    EschPartition() : EschDrawable(ESCH_DRWT_PARTITION) {}

    virtual ~EschPartition() {}
    
    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    virtual void release()=0;

    virtual esch_error_codes insert(EschDrawable *drw)=0;
    virtual void remove(EschDrawable *drw)=0;

    virtual esch_error_codes traverse(EschTraverse *data) const=0;

    virtual esch_error_codes update(EschDrawable *drw=0)=0;
};


//�������������������������������������������������������������������������Ŀ
// EschGridPartition - 2D uniform regionalized partition.                   �
//���������������������������������������������������������������������������
class EschGridPartition : public EschPartition
{
public:
    //���������������������������������������������������������������������Ŀ
    // Public data members                                                  �
    //�����������������������������������������������������������������������
    ushort              width;              // Width of grid
    ushort              depth;              // Depth of grid
    Flx16               size;               // World size of each region
    ulong               sizeshift;          // Shift value for size
    EschPoint           origin;             // Origin of grid
    ulong               nregions;           // Number of regions (computed from width*depth)
    EschPartitionList   **regions;          // Region lists

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    EschGridPartition();

    virtual ~EschGridPartition();
    
    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    virtual EschDrawable *find(const char *dname) const;
   
    virtual void draw();

    virtual esch_error_codes pick(EschPicking *data) const;
    virtual esch_error_codes collide(EschCollision *data) const;

    virtual void animate();

    virtual void release();

    virtual esch_error_codes init(ushort w, ushort d, Flx16 s,
                                  const EschPoint *o);

    virtual esch_error_codes insert(EschDrawable *drw);
    virtual void remove(EschDrawable *drw);

    virtual esch_error_codes traverse(EschTraverse *data) const;

    virtual esch_error_codes update(EschDrawable *drw=0);
};


#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//��� End of header - espartn.hpp ���

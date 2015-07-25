//���������������������������������������������������������������������������
//                                   ____
//                                  / __ \
//                                 ( (__) )
//                                 _\____/___
//                                /  |  |   /\
//                               /_________/  \_
//                              /          \    \
//                             /            \    \_
//                            /              \     \
//                           /                \     \_
//                          /                  \      \
//                         /                    \      \_
//                        /                      \       \
//                       /                        \       \_
//                      /                          \        \
//                     /                            \        \_
//                    /                              \         \
//                   / N  N EEE W   W TTTTT  OO  N  N \        /
//                  /  NN N E_  W   W   T   O  O NN N  \      /
//                 /   N NN E   W W W   T   O  O N NN   \    /
//                /    N  N EEE  W W    T    OO  N  N    \  /
//               /________________________________________\/
//
//                     Newtonian Physics Simulation Library
//
//            Copyright (c) 1995-1997 by Charybdis Enterprises, Inc.
//                           All Rights Reserved.
//
//                       Microsoft Windows '95 Version
//
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
// Created by Dan Higdon
//
// newton.hpp
//
// Primary header for the Newton library.
//
//���������������������������������������������������������������������������

#ifndef __NEWTON_HPP
#define __NEWTON_HPP   1

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//���������������������������������������������������������������������������
//             
//                                Includes
//                                
//���������������������������������������������������������������������������

#include <portable.h>
#include <felix.hpp>
#include <assert.h>

#include "newtmath.hpp"                 // class NewtVector

//���������������������������������������������������������������������������
//
//                                Classes
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//  Newton Object Class
//���������������������������������������������������������������������������
class NewtObject
{
    NewtVector  position;           // location vector
    NewtVector  last_position;      // location in the previous frame

    NewtVector  velocity;           // velocity vector
    NewtVector  temp_velocity;      // temporary velocity (temporary)

    NewtVector  acceleration;       // acceleration vector
    NewtVector  temp_acceleration;  // acceleration vector (temporary)

public:
    friend class NewtForce;         // Allow a force to act on us directly

    //���������������������������������������������������������������������Ŀ
    // Public data members                                                  �
    //�����������������������������������������������������������������������
    Flx16       mass;               // mass (acceleration resistance)
    Flx16       drag;               // drag coefficient (velocity resistance)
    
    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    NewtObject (Flx16 m, const NewtVector &_pos, const NewtVector &_vel);
    NewtObject (Flx16 m, Flx16 x, Flx16 y, Flx16 z, const NewtVector &_vel);
    NewtObject (Flx16 m, Flx16 x, Flx16 y, Flx16 z);
    NewtObject ();

    virtual ~NewtObject ();

    //���������������������������������������������������������������������Ŀ
    // Accessor functions (inlined below)                                   �
    //�����������������������������������������������������������������������
    void get_last_position (NewtVector *) const;
    void get_position (NewtVector *) const;
    void set_position (const NewtVector &pos);
    void set_position (Flx16 x, Flx16 y, Flx16 z);

    void get_velocity (NewtVector *) const;
    void set_velocity (const NewtVector &vel);
    void set_velocity (Flx16 x, Flx16 y, Flx16 z);

    void get_temp_velocity (NewtVector *) const;
    void set_temp_velocity (const NewtVector &vel);
    void set_temp_velocity (Flx16 x, Flx16 y, Flx16 z);

    void get_acceleration (NewtVector *) const;
    void set_acceleration (const NewtVector &acc);
    void set_acceleration (Flx16 x, Flx16 y, Flx16 z);

    void get_temp_acceleration (NewtVector *) const;
    void set_temp_acceleration (const NewtVector &acc);
    void set_temp_acceleration (Flx16 x, Flx16 y, Flx16 z);

    void set_mass (Flx16);
    void set_drag (Flx16);

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    virtual void step (Flx16 time_interval);
};


//���������������������������������������������������������������������������
//  Newton Force Class
//���������������������������������������������������������������������������
class NewtForce
{
protected:

public:
    //���������������������������������������������������������������������Ŀ
    // Public data members                                                  �
    //�����������������������������������������������������������������������
    NewtVector  vector;

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    NewtForce (const NewtVector &_vector);
    NewtForce (Flx16 i, Flx16 j, Flx16 k);
    NewtForce ();

    virtual ~NewtForce ();

    //���������������������������������������������������������������������Ŀ
    // Accessor functions (inlined below)                                   �
    //�����������������������������������������������������������������������
    void set_vector(const NewtVector &_vector);
    void set_vector(Flx16 i, Flx16 j, Flx16 k);

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    virtual void affect (NewtObject *) const;
    virtual void affect_permanent (NewtObject *) const;
};

//���������������������������������������������������������������������������
//
//                              Inline Functions
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//  NewtObject - get_last_position
//���������������������������������������������������������������������������
inline void NewtObject::get_last_position (NewtVector *v) const
{
    assert (v != 0);
    *v = last_position;
}


//���������������������������������������������������������������������������
//  NewtObject - get_position
//���������������������������������������������������������������������������
inline void NewtObject::get_position (NewtVector *v) const
{
    assert (v != 0);
    *v = position;
}


//���������������������������������������������������������������������������
//  NewtObject - set_position
//���������������������������������������������������������������������������
inline void NewtObject::set_position (const NewtVector &pos)
{
    position = pos;
}

inline void NewtObject::set_position (Flx16 x, Flx16 y, Flx16 z)
{
    position.i=x;
    position.j=y;
    position.k=z;
}


//���������������������������������������������������������������������������
//  NewtObject - get_velocity
//���������������������������������������������������������������������������
inline void NewtObject::get_velocity (NewtVector *v) const
{
    assert (v != 0);
    *v = velocity;
}


//���������������������������������������������������������������������������
//  NewtObject - set_velocity
//���������������������������������������������������������������������������
inline void NewtObject::set_velocity (const NewtVector &vel)
{
    velocity = vel;
}

inline void NewtObject::set_velocity (Flx16 x, Flx16 y, Flx16 z)
{
    velocity.i = x;
    velocity.j = y;
    velocity.k = z;
}


//���������������������������������������������������������������������������
//  NewtObject - get_temp_velocity
//���������������������������������������������������������������������������
inline void NewtObject::get_temp_velocity (NewtVector *v) const
{
    assert (v != 0);
    *v = temp_velocity;
}


//���������������������������������������������������������������������������
//  NewtObject - set_temp_velocity
//���������������������������������������������������������������������������
inline void NewtObject::set_temp_velocity (const NewtVector &vel)
{
    temp_velocity = vel;
}

inline void NewtObject::set_temp_velocity (Flx16 x, Flx16 y, Flx16 z)
{
    temp_velocity.i = x;
    temp_velocity.j = y;
    temp_velocity.k = z;
}


//���������������������������������������������������������������������������
//  NewtObject - get_acceleration
//���������������������������������������������������������������������������
inline void NewtObject::get_acceleration (NewtVector *v) const
{
    assert (v != 0);
    *v = acceleration;
}


//���������������������������������������������������������������������������
//  NewtObject - set_acceleration
//���������������������������������������������������������������������������
inline void NewtObject::set_acceleration (const NewtVector &acc)
{
    acceleration = acc;
}

inline void NewtObject::set_acceleration (Flx16 x, Flx16 y, Flx16 z)
{
    acceleration.i = x;
    acceleration.j = y;
    acceleration.k = z;
}


//���������������������������������������������������������������������������
//  NewtObject - get_temp_acceleration
//���������������������������������������������������������������������������
inline void NewtObject::get_temp_acceleration (NewtVector *v) const
{
    assert (v != 0);
    *v = temp_acceleration;
}


//���������������������������������������������������������������������������
//  NewtObject - set_temp_acceleration
//���������������������������������������������������������������������������
inline void NewtObject::set_temp_acceleration (const NewtVector &acc)
{
    temp_acceleration = acc;
}

inline void NewtObject::set_temp_acceleration (Flx16 x, Flx16 y, Flx16 z)
{
    temp_acceleration.i = x;
    temp_acceleration.j = y;
    temp_acceleration.k = z;
}


//���������������������������������������������������������������������������
//  NewtObject - set_mass
//���������������������������������������������������������������������������
inline void NewtObject::set_mass (Flx16 m)
{
    mass = m;
}


//���������������������������������������������������������������������������
//  NewtObject - set_drag
//���������������������������������������������������������������������������
inline void NewtObject::set_drag (Flx16 d)
{
    drag = d;
}


//���������������������������������������������������������������������������
//  NewtForce - set_vector
//���������������������������������������������������������������������������
inline void NewtForce::set_vector(const NewtVector &_vector)
{
    vector = _vector;
}

inline void NewtForce::set_vector(Flx16 i, Flx16 j, Flx16 k)
{
    vector.i = i;
    vector.j = j;
    vector.k = k;
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//��� End of header - newton.hpp ���

//���������������������������������������������������������������������������
//
//                              S I M   G I N E
//
//             __               ___   ______,-------
//           __==__,------------/|\--|      | .-.-.|    ___________
//         (|     |--------------|---|------| '-`-`|  _/___________\_
//         (|_____|      _       _   |   _  | 6000 | |               |
//          |__\\_|`-._/___\___/___\_|_/___\|      | |               |
//         __/ |===|--|_____|_|_____|_|___  |\_____|=|_______________|
//      |=|[_]==[_]    \ _ /   \ _ /   \ _ /          [_]   [_]   [_]
//���������������������������������������������������������������������������
//
//                     A Simluator Framework for MythOS(tm)
//
//                        Microsoft Windows '95 Version
//
//               Copyright (c) 1997 by Charybdis Enterprises, Inc.
//                           All Rights Reserved.
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
// MythOS is a trademark of Charybdis Enterprises, Inc.
//
//���������������������������������������������������������������������������
//
// simobj.cpp
//
// This module contains the simple object representation class for the
// simulator.
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//                                
//���������������������������������������������������������������������������

#include "simgine.hpp"

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//�����������������������  Constructors/Destructors  ������������������������
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// SimObject - Constructor
//���������������������������������������������������������������������������
SimObject::SimObject(SimulatorState *_parent) :
    SimBase(_parent)
{
}


//���������������������������������������������������������������������������
// SimObject - Destructor
//���������������������������������������������������������������������������
SimObject::~SimObject()
{
    remove();
}



//���������������������������������������������������������������������������
//�����������������������������  Operations  ��������������������������������
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// SimObject - insert
//���������������������������������������������������������������������������
BOOL SimObject::insert(ushort t)
{
    assertMyth("SimObject::insert needs parent",
               parent != 0 && parent->objects != 0);

    if (index != ushort(-1))
        remove();

    team = t;

//��� Find empty slot
    for (int i=0; i < parent->obj_max; i++)
    {
        if (!parent->objects[i])
            break;
    }
    //��� Expand array
    if (i >= parent->obj_max)
    {
        ushort nsize = parent->obj_max + SIM_INIT_OBJECTS;

        SimObject **tmp = new SimObject *[nsize];
        if (!tmp)
            return FALSE;

        memset(tmp, 0, sizeof(SimObject*) * nsize);

        memcpy(tmp, parent->objects, sizeof(SimObject*) * parent->obj_max);

        delete [] parent->objects;

        parent->objects = tmp;
        parent->obj_max = nsize;
    }

//��� Insert into slot
    parent->objects[i] = this;
    index = i;

    if (i >= parent->obj_hi)
        parent->obj_hi = i + 1;

    return TRUE;
}


//���������������������������������������������������������������������������
// SimObject - remove
//���������������������������������������������������������������������������
void SimObject::remove()
{
    if (!parent || !parent->objects)
        return;

    if (index == ushort(-1))
        return;

    if (index < parent->obj_max)
        parent->objects[index] = 0;

    index = ushort(-1);
}



//���������������������������������������������������������������������������
//���������������������������  Utility Routines  ����������������������������
//���������������������������������������������������������������������������

//��� End of module - simobj.cpp ���

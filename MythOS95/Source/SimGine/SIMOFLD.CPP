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
// simofld.cpp
//
// This module contains the base representation class for the simulator.
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
// SimOffield - Constructor
//���������������������������������������������������������������������������
SimOffield::SimOffield(SimulatorState *_parent) :
    SimBase(_parent)
{
}


//���������������������������������������������������������������������������
// SimOffield - Destructor
//���������������������������������������������������������������������������
SimOffield::~SimOffield()
{
}



//���������������������������������������������������������������������������
//�����������������������������  Operations  ��������������������������������
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// SimOffield - insert
//���������������������������������������������������������������������������
BOOL SimOffield::insert(ushort t)
{
    assertMyth("SimOffield::insert needs parent",
               parent != 0 && parent->teams[t].offields != 0);

    if (index != ushort(-1))
        remove();

    team = t;

//��� Find empty slot
    SimulatorState::sim_team_t *st = &parent->teams[t];

    for (int i=0; i < st->ofld_max; i++)
    {
        if (!st->offields[i])
            break;
    }
    //��� Expand array
    if (i >= st->ofld_max)
    {
        ushort nsize = st->ofld_max + SIM_INIT_OBJECTS;

        SimOffield **tmp = new SimOffield *[nsize];
        if (!tmp)
            return FALSE;

        memset(tmp, 0, sizeof(SimOffield*) * nsize);

        memcpy(tmp, st->offields, sizeof(SimOffield*) * st->ofld_max);

        delete [] st->offields;

        st->offields = tmp;
        st->ofld_max = nsize;
    }

//��� Insert into slot
    st->offields[i] = this;
    index = i;

    if (i >= st->ofld_hi)
        st->ofld_hi = i + 1;

    return TRUE;
}


//���������������������������������������������������������������������������
// SimOffield - remove
//���������������������������������������������������������������������������
void SimOffield::remove()
{
    if (index == ushort(-1))
        return;

    if (!parent || !parent->teams[team].offields)
        return;

    SimulatorState::sim_team_t *st = &parent->teams[team];

    if (index < st->ofld_max)
        st->offields[index] = 0;

    index = ushort(-1);
}



//���������������������������������������������������������������������������
//���������������������������  Utility Routines  ����������������������������
//���������������������������������������������������������������������������

//��� End of module - simofld.cpp ���

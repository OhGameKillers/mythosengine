//���������������������������������������������������������������������������
//
//                              S I M   G I N E
//
//             __               ___   ______,-------
//           __==__,------------/|\--|      | .-.-.|    ___________
//         (|     |--------------|---|------| '-`-`|  _/___________\_
//         ({_____|      _       _   |   _  | 6000 | |               |
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
//                               *** Tester ***
//
// ststate.cpp
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//                                
//���������������������������������������������������������������������������

#include "st.hpp"

#include "stevt.hpp"

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//�����������������������  Constructors/Destructors  ������������������������
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// Constructor - TesterState
//���������������������������������������������������������������������������
TesterState::TesterState() :
    evt (0)
{
};


//���������������������������������������������������������������������������
// Destructor - TesterState
//���������������������������������������������������������������������������
TesterState::~TesterState()
{
    deactivate();
};



//���������������������������������������������������������������������������
//�����������������������������  Operations  ��������������������������������
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// TesterState - activate
//���������������������������������������������������������������������������
void TesterState::activate()
{
//��� Load palette and set color
    if (!Screen->load_palette("Default.VGP", 0))
        panic("TesterState::activate failed to load palette");

    gberg_color(Screen->find(VngoColor24bit(255,255,0)), VNGO_TRANSPARENT);

//��� Create event system
    evt = new MaxEventUser (*Devs);

    if (!evt
        || evt->load ("stevt.iff",0) != 0)
        panic("TesterState::activate fail for event");

    evt->install();

}


//���������������������������������������������������������������������������
// TesterState - deactivate
//���������������������������������������������������������������������������
void TesterState::deactivate()
{
    if (evt)
    {
        delete evt;
        evt = 0;
    }
}


//���������������������������������������������������������������������������
// TesterState - process_events
//���������������������������������������������������������������������������
void TesterState::process_events()
{
    MaxEventList events = evt->process();

    if (events.check (QUIT))
        theSim.exit();

    if (events.check (NEXT))
        switch_to(theSim.sim);
}


//���������������������������������������������������������������������������
// TesterState - render
//���������������������������������������������������������������������������
void TesterState::render()
{
    Screen->clear();

    int waslocked=Screen->lock();

    SimText st(Screen);

    st.out(100,100,"SimGine Framework Tester");

    if (!waslocked)
        Screen->unlock();
}

//��� End of module - ststate.cpp ���

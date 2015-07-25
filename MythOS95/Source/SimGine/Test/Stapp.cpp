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
//                               *** Tester ***
//
// stapp.cpp
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//                                
//���������������������������������������������������������������������������

#include "st.hpp"

//���������������������������������������������������������������������������
//
//                                 Data
//
//���������������������������������������������������������������������������

TesterApp theSim;

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//�����������������������  Constructors/Destructors  ������������������������
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// Constructor - TesterApp
//���������������������������������������������������������������������������
TesterApp::TesterApp() :
    SimGine (),
    start (0),
    sim (0)
{
};


//���������������������������������������������������������������������������
// Destructor - TesterApp
//���������������������������������������������������������������������������
TesterApp::~TesterApp()
{
};



//���������������������������������������������������������������������������
//�����������������������������  Operations  ��������������������������������
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// TesterApp - init_instance
//���������������������������������������������������������������������������
BOOL TesterApp::init_instance()
{
//��� Load settings from .INI file
    {
        XFParseINI ini;
        char buff[256];

        ini.open("ST.INI", XF_OPEN_READ);

        if (!ini.section("StartUp"))
        {
            if (!ini.read("DisplayDevice",buff))
            {
                strlwr(buff);

                startup &= ~(STARTUP_DDRAW | STARTUP_CLEAR3D);

#ifdef  _OEMS
#ifdef  _CLEAR_3D
                if (strstr(buff,"clear3d"))
                    startup |= STARTUP_CLEAR3D;
                else
#endif
#endif

                if (strstr(buff,"directdraw"))
                    startup |= STARTUP_DDRAW;
            }

            if (!ini.read("FullScreen",buff))
            {
                strlwr(buff);
                if (strstr(buff,"no"))
                    startup &= ~STARTUP_FULLSCREEN;
            }

            if (!ini.read("ColorDepth",buff))
            {
                if (strstr(buff,"8"))
                    startup_bitdepth = 8;
                else if (strstr(buff,"15"))
                    startup_bitdepth = 15;
                else if (strstr(buff,"16"))
                    startup_bitdepth = 16;
            }
        }
    }

//��� Perform base init
    if (!SimGine::init_instance())
        return FALSE;

//��� Install fonts
    if (gberg_install_font("arl-7x12.iff", 0))
        return FALSE;

//��� Create states
    start = new TesterState;
    if (!start)
        return FALSE;

    sim = new TesterSim;
    if (!sim)
        return FALSE;

    Mode = start;

    return TRUE;
}


//���������������������������������������������������������������������������
// TesterApp - exit_instance
//���������������������������������������������������������������������������
int TesterApp::exit_instance()
{
    if (start)
    {
        delete start;
        start = 0;
    }

    return SimGine::exit_instance();
}

//��� End of module - stapp.cpp ���


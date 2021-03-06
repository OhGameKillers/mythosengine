//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
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
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
//                     A Simluator Framework for MythOS(tm)
//
//                     Microsoft Windows 95/98/NT Version
//
//  Copyright (c) 1997-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
//
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
// Created by Dan Higdon and Chuck Walbourn
//
// simgine.cpp
//
// This module defines the basic application SimGine class which handles
// the startup and termination of the application.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include "simgine.hpp"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Routines
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

LRESULT CALLBACK SimWndProc (HWND, UINT, WPARAM, LPARAM);

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

SimGine         *SimApp = 0;
SimScreen       *Screen = 0;
MythosSystem    *MythOS = 0;
MaxDevices      *Devs   = 0;
SimState        *Mode   = 0;
SimAudio        *Audio  = 0;

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭�  Constructors/Destructors  碓旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SimGine - Constructor
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
SimGine::SimGine() :
    startup (STARTUP_FULLSCREEN
             | STARTUP_AUDIO
             | STARTUP_DX5),
    startup_width (SIM_DEFAULT_WIDTH),
    startup_height (SIM_DEFAULT_HEIGHT),
    startup_bitdepth (SIM_DEFAULT_BITDEPTH),
    startup_nchannels(SIM_AUDIO_NCHANNELS),
    startup_nreserved(SIM_AUDIO_NRESERVED),
    startup_nchannels3d(SIM_AUDIO_NCHANNELS3D),
    startup_drate(BACH_DIGI_DRIVERRATE),
    startup_dformat(BACH_DIGI_STEREO_16),
    startup_memsize (SIM_MYTHOS_MEM_SIZE),
    startup_arenasize (SIM_MYTHOS_ESCHER_ARENA_SIZE),
    startup_sortsize (SIM_MYTHOS_ESCHER_SORT_SIZE)
{
    assertMyth("Must be only one SimGine derived class instance in an application",
               SimApp == 0);

    SimApp = this;

    // Initilize strings
    strcpy(appName,"SimGine");
    *startup_target = 0;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SimGine - Destructor
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
SimGine::~SimGine()
{
    if (SimApp == this)
        SimApp = 0;
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  Operations  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SimGine - init_instance
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
BOOL SimGine::init_instance()
{
//陳� Scan for instance already running, and if found, defer to it...
    HWND hwnd = FindWindow (appName, NULL);
    if (hwnd)
    {
        if (IsIconic (hwnd))
            ShowWindow (hwnd, SW_RESTORE);
        SetForegroundWindow (hwnd);
        return FALSE;
    }

//陳� Register our basic window class
    WNDCLASSEX  wc;

    // Fill in window class structure with parameters that describe
    // the main window.
    wc.cbSize        = sizeof (WNDCLASSEX);
    wc.style         = CS_OWNDC;
    wc.lpfnWndProc   = (WNDPROC)SimWndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon (hInstance, MAKEINTRESOURCE(IDI_SIM_APPICON));
    wc.hCursor       = LoadCursor (NULL, MAKEINTRESOURCE(IDC_SIM_ARROW));
    wc.hbrBackground = (HBRUSH)GetStockObject (BLACK_BRUSH);
    wc.lpszClassName = appName;
    wc.lpszMenuName  = 0;

    // This will load the small icon image from the icon resource
    wc.hIconSm = (HICON__ *)LoadImage (hInstance,
                                       MAKEINTRESOURCE(IDI_SIM_APPICON),
                                       IMAGE_ICON,
                                       GetSystemMetrics(SM_CXSMICON),
                                       GetSystemMetrics(SM_CYSMICON),
                                       LR_DEFAULTCOLOR);

    if (!RegisterClassEx (&wc))
        return FALSE;

//陳� Create our client window
    hWndClient = CreateWindowEx (0,
                                 appName, appName,
                                 WS_VISIBLE | WS_POPUP,
                                 0, 0,
                                 startup_width, startup_height,
                                 NULL, NULL, hInstance, NULL);
    if (!hWndClient)
        return FALSE;

    ShowWindow (hWndClient, cmdShow);
    UpdateWindow (hWndClient);
    SetFocus (hWndClient);

//陳� Create our required objects
    assertMyth("SimGine::init_instance cannot be called twice",
               Screen == 0 && MythOS == 0 && Devs == 0 && Mode == 0 && Audio == 0);

    MythOS = new MythosSystem (startup_memsize);
    if (!MythOS)
        return FALSE;

    if (startup & STARTUP_DX5)
    {
        Devs = new MaxDevicesDirectX (hWndClient);

        if (!Devs)
            return FALSE;

        if (!Devs->is_mouse_present() || !Devs->is_keyboard_present())
        {
            delete Devs;
            Devs = new MaxDevicesWin32 (hWndClient);
        }

    }
    else
    {
        Devs = new MaxDevicesWin32 (hWndClient);
    }

    if (!Devs)
        return FALSE;

//陳� Create a stack space for Bozo (so tasks can call Win32 APIs)
//陳� Notice that this MUST reside on the stack!
    char    bozo_stackspace[SIM_MYTHOS_TASK_STACK_SIZE];

    IvorySubAlloc *bozo_alloc = (IvorySubAlloc *)bozo_stackspace;
    ivory_sub_initialize (bozo_alloc, sizeof (bozo_stackspace));

//陳� Finish MythOS initialization
    if (MythOS->init (startup_arenasize, startup_sortsize, bozo_alloc))
        return FALSE;

//陳� Create screen
    if (startup & STARTUP_D3D)
    {
        Screen = new SimScreenD3D;
    }
    else if (startup & STARTUP_DDRAW)
    {
        Screen = new SimScreenDD;
    }
    else
    {
        Screen = new SimScreenDIB;
    }

    if (!Screen)
        return FALSE;

    dword sflags = 0;
    if (startup & STARTUP_FULLSCREEN)
        sflags |= SimScreen::FULLSCREEN;
    if (startup & STARTUP_TRUEFLIP)
        sflags |= SimScreen::TRUEFLIP;

    if (Screen->init(startup_width, startup_height,
                     startup_bitdepth, sflags))
        return FALSE;

//陳� Create Audio
    if (startup & STARTUP_AUDIO)
    {
        Audio = new SimAudio;
        if (!Audio)
            return FALSE;

        if (Audio->init(startup_drate,startup_dformat,
                        startup_nchannels,startup_nreserved,
                        startup_nchannels3d)
                                                != SimAudio::ERROR_NONE)
        {
            delete Audio;
            Audio = 0;
        }
    }

    return TRUE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SimGine - run
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int SimGine::run()
{
    assertMyth("SimGine::run needs valid starting Mode", Mode != 0);

    if (!Mode)
        return 1;

    Mode->activate();
    while (Mode->pump_windows())
    {
        bz_yield(&ReadyQ, &ReadyQ);
        assertMyth ("SimGine::run needs a valid Mode", Mode != 0);

        Devs->update();
        step();
        Mode->process_events();
        if (hWndClient)
        {
            Mode->render();
            Mode->display();
        }
    }
    Mode->deactivate();

    return exit_instance();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SimGine - exit_instance
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int SimGine::exit_instance()
{
    if (Audio)
    {
        delete Audio;
        Audio=0;
    }

    if (Screen)
    {
        delete Screen;
        Screen=0;
    }

    if (Devs)
    {
        delete Devs;
        Devs=0;
    }

    if (MythOS)
    {
        delete MythOS;
        MythOS=0;
    }

    return 0;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SimGine - step
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void SimGine::step()
{
    // No action in the default step - this is for derived classes to
    // wedge processing in (like Network stuff, for instance).
}


//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭�  Utility Routines  碓旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SimState - exit
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void SimGine::exit()
{
    DestroyWindow(hWndClient);
    hWndClient=0;
}

//葦� End of module - simgine.cpp 憶�

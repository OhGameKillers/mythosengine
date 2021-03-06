//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//           __ ,
//            ,-| ~           ,               ,,
//           ('||/__,        ||               ||                  _
//          (( |||  | \\ \\ =||=   _-_  \\/\\ ||/|,  _-_  ,._-_  / \\
//          (( |||==| || ||  ||   || \\ || || || || || \\  ||   || ||
//           ( / |  , || ||  ||   ||/   || || || |' ||/    ||   || ||
//            -____/  \\/\\  \\,  \\,/  \\ \\ \\/   \\,/   \\,  \\_-|
//                                                               /  \
//                                                              '----`
//                     Text Output and Font Management System
//                       Microsoft Windows 95/98/NT Version
//
//  Copyright (c) 1995-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
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
// Created by Chuck Walbourn
//
// main.cpp
//
//      This is the "generic" application framework from which all
// non-MFC applications are traditionally created.  This is just a
// bare-bones app that creates a window and has an About dialog.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#define WIN32_LEAN_AND_MEAN
#include <stdlib.h>
#include "global.hpp"
#include "resource.h"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Routines
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

// Imported from INIT.CPP
BOOL    InitApplication (HINSTANCE, int);

STATIC int load_font(char *f);
STATIC int load_strings(char *f);

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

HINSTANCE   hInst;
HWND        hWndClient;
const char  szAppName[] = "Gutenberg";
GameState   *game;

MaxDevices  *Devs=0;

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

extern "C" int mythos_atexit (register void (*__func) (void))
{
    return atexit (__func);
}

extern "C" void mythos_atexit_remove (register void (*__func) (void))
{
}

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// WinMain
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int APIENTRY WinMain (HINSTANCE hInstance,
                      HINSTANCE hPrevInstance,
                      LPSTR     lpCmdLine,
                      int       nCmdShow)
{
        // Perform initializations.
    // If we are already running, this routine will reactivate the older
    // application and return FALSE.
        if (!InitApplication (hInstance, nCmdShow))
                return FALSE;

    // Initialize game here.
    IvorySystem ivory (1024*1024);
    GBergSystem gberg;

    // Load fonts
    if (xf_exist("3X6.IFF"))
        load_font("3X6.IFF");
    if (xf_exist("5X8.IFF"))
        load_font("5X8.IFF");
    if (xf_exist("7X12.IFF"))
        load_font("7X12.IFF");
    if (xf_exist("8X13.IFF"))
        load_font("8X13.IFF");
    if (xf_exist("9X15.IFF"))
        load_font("9X15.IFF");
    if (xf_exist("12X24.IFF"))
        load_font("12X24.IFF");

    if (gberg_select_font("3x6")
        && gberg_select_font("7x12")
        && gberg_select_font("8x13")
        && gberg_select_font("9x15")
        && gberg_select_font("12x24"))
        return FALSE;

    // Load strings
    if (load_strings("TEST.IFF"))
        return FALSE;

    Devs = new MaxDevicesWin32(hWndClient);
    if (!Devs)
    {
        MessageBeep (0);
        MessageBox(hWndClient,
                   "Could not create Max devices",
                   "Fatal Error",
                   MB_OK);
        return FALSE;
    }

    game = new GameState (Devs);
    game->LoadEvents ("gframe.iff");
    if (!game->active)
    {
        MessageBeep (0);
        MessageBox(hWndClient,
                   "Could not load event file",
                   "Error",
                   MB_OK);
        return FALSE;
    }

        // Acquire and dispatch messages until a WM_QUIT message is received.
    while (game->PumpWindows())
    {
        // Do per-frame processing here
        Devs->update ();
        game->GetEvents();
        game->ProcessEvents();
        game->Render();
        game->Display();
    }

    // Clean up the game here
    // (destructors get most of it)
    delete game;

    delete Devs;
    Devs=0;

        return 0;

    // This shuts up the compiler
    lpCmdLine;
}

STATIC int load_font(char *f)
{
    int err;

    err=gberg_install_font(f,0);
    if (err)
    {
        char    buff[128];
        sprintf(buff,"Failed to load font %s, error %d",f,(int)err);
        MessageBox(hWndClient,
                   buff,"Error",MB_OK);
        return 1;
    }
    return 0;
}

STATIC int load_strings(char *st)
{
    int err;

    err=gberg_install_strings(st,0);
    if (err)
    {
        char    buff[128];
        sprintf(buff,"Failed to load stringtable %s, error %d",st,(int)err);
        MessageBox(hWndClient,
                   buff,"Error",MB_OK);
        return 1;
    }
    return 0;
}

//葦� eof - main.cpp 憶�

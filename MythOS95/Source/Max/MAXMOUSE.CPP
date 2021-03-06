//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//                  ooo        ooooo
//                  `88.       .888'
//                   888b     d'888   .oooo.   oooo    ooo
//                   8 Y88. .P  888  `P  )88b   `88b..8P'
//                   8  `888'   888   .oP"888     Y888'
//                   8    Y     888  d8(  888   .o8"'88b
//                  o8o        o888o `Y888""8o o88'   888o
//
//                          Across the event horizon...
//
//                       Microsoft Windows 95/98/NT Version
//
//  Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
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
// Created by Dan Higdon
//
// maxmouse.cpp
//
// Event Devices
//
//      This module defines the physical devices used by the event
//  system.  Each device has a unique interface, suited to the device.
//  Only three devices are currently supported.
//
//  Mouse -- The mouse is a multi-button positional device.  The mouse
//          can be queried for its button's states, as well as its current
//          position, and delta movement.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <assert.h>
#include <string.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <ivory.hpp>

#include "maxdevs.hpp"
#include "maxmouse.hpp"

#include <iostream.h>

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Structures
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�


//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Routines
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                              Static Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                        Mouse Member Functions
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  Constructor                                                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
MaxMouse::MaxMouse():
    initialized (false),
    max_x (GetSystemMetrics (SM_CXSCREEN)),
    max_y (GetSystemMetrics (SM_CYSCREEN))
{
}


MaxMouse::~MaxMouse()
{
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  Uninit                                                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void MaxMouse::uninit ()
{
    initialized = false;
}

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  clear                                                                   �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void MaxMouse::clear ()
{
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  update                                                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void MaxMouse::update()
{
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  is_present                                                              �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
bool MaxMouse::is_present () const
{
    return true;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  set_extents                                                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void MaxMouse::set_extents (short x, short y)
{
    max_x = x;
    max_y = y;
}


//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                        Mouse Member Functions
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  Constructor                                                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
MaxMouseWin32::MaxMouseWin32():
    MaxMouse ()
{
}


MaxMouseWin32::~MaxMouseWin32()
{
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  Init                                                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int MaxMouseWin32::init ()
{
    initialized = true;
    MouseSupported = 1;
    NumButtons = 2;

    get_pos (&last_x, &last_y);

    return MouseSupported;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  show_cursor                                                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void MaxMouseWin32::show_cursor (bool on)
{
    ShowCursor (on);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  get_pos                                                                 �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void MaxMouseWin32::get_pos (short *mx, short *my) const
{
    assert (mx && my);

    POINT pt;
    GetCursorPos (&pt);

    if (pt.x > max_x)
        pt.x = max_x;

    if (pt.y > max_y)
        pt.y = max_y;

    *mx = short (pt.x);
    *my = short (pt.y);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  set_pos                                                                 �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void MaxMouseWin32::set_pos (short _mx, short _my)
{
    if (_mx > max_x)
        _mx = max_x;

    if (_my > max_y)
        _my = max_y;

    SetCursorPos (_mx, _my);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  get_buttons                                                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
byte MaxMouseWin32::get_buttons () const
{
    byte res = 0;

    if (GetAsyncKeyState (VK_LBUTTON))
        res |= 1;

    if (GetAsyncKeyState (VK_RBUTTON))
        res |= 2;

    return res;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  get_movement                                                            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void MaxMouseWin32::get_movement (short *dx, short *dy)
{
    assert (dx && dy);

    // Get the current mouse position
    short   mx, my;
    get_pos (&mx, &my);

    // Calculate the delta from the last position
    *dx = mx - last_x;
    *dy = my - last_y;

    // Remember the current position for the next time.
    last_x = mx;
    last_y = my;
}


//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                        Mouse Member Functions
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  Constructor                                                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
MaxMouseDirectX::MaxMouseDirectX (IDirectInput *pdi, HWND _hwnd):
    MaxMouse (),
    pdid (0)
{
    HRESULT hr = pdi->CreateDevice (GUID_SysMouse, &pdid, NULL);

    // Obtain an IDirectInputDevice2 interface
    if (!SUCCEEDED(hr))
        pdid = 0;

    pdid->SetCooperativeLevel (_hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
}


MaxMouseDirectX::~MaxMouseDirectX()
{
    if (pdid)
    {
        pdid->Unacquire();
        pdid->Release();
        pdid = 0;
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  Init                                                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int MaxMouseDirectX::init ()
{
    if (pdid)
    {
        dicaps.dwSize = sizeof (DIDEVCAPS);
        pdid->GetCapabilities (&dicaps);
        pdid->SetDataFormat (&c_dfDIMouse);

#if 1
        // Set the Mouse up for buffered access
        DIPROPDWORD prop;
        prop.diph.dwSize = sizeof (DIPROPDWORD);
        prop.diph.dwHeaderSize = sizeof (DIPROPHEADER);
        prop.diph.dwObj = 0;
        prop.diph.dwHow = DIPH_DEVICE;
        prop.dwData = DIDATA_SIZE;
        pdid->SetProperty (DIPROP_BUFFERSIZE, &prop.diph);
#endif

        // Get the current mouse position
        POINT pt;
        GetCursorPos (&pt);
        xpos = pt.x;
        ypos = pt.y;

        // Now, aquire the device
        initialized = SUCCEEDED(pdid->Acquire());

        // Enforce the cursor ON condition for now
        cursor_on = true;
        ShowCursor (true);
    }

    MouseSupported = 1;
//    NumButtons = 2;
//    get_pos (&last_x, &last_y);

    old_buttons[0] = state.rgbButtons[0] = 0;
    old_buttons[1] = state.rgbButtons[1] = 0;
    old_buttons[2] = state.rgbButtons[2] = 0;
    old_buttons[3] = state.rgbButtons[3] = 0;

    return MouseSupported;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  Uninit                                                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void MaxMouseDirectX::uninit ()
{
    initialized = false;
    if (pdid)
    {
        pdid->Unacquire();
        old_buttons[0] = state.rgbButtons[0] = 0;
        old_buttons[1] = state.rgbButtons[1] = 0;
        old_buttons[2] = state.rgbButtons[2] = 0;
        old_buttons[3] = state.rgbButtons[3] = 0;
    }
}

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  clear                                                                   �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void MaxMouseDirectX::clear ()
{
    old_buttons[0] = state.rgbButtons[0];
    old_buttons[1] = state.rgbButtons[1];
    old_buttons[2] = state.rgbButtons[2];
    old_buttons[3] = state.rgbButtons[3];
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  update                                                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void MaxMouseDirectX::update()
{
    // pdid->Poll();

#if 0
    while (pdid->GetDeviceState (sizeof (state), &state) == DIERR_INPUTLOST)
    {
        HRESULT hr = pdid->Acquire();

        // We can't reacquire, so don't go any further
        if (!SUCCEEDED (hr))
            return;
    }
#endif

    // Process data
    DIDEVICEOBJECTDATA od[DIDATA_SIZE];
    DWORD size = DIDATA_SIZE;
    while (pdid->GetDeviceData (sizeof (DIDEVICEOBJECTDATA),
                                od,
                                &size,
                                0) == DIERR_INPUTLOST)
    {
        HRESULT hr = pdid->Acquire();
        if (!SUCCEEDED (hr))
            return;
    }

    for (dword i = 0; i < size; i++)
    {
        dword data = od[i].dwData;

        switch (od[i].dwOfs)
        {
            case DIMOFS_X:
                xpos += data;
                break;

            case DIMOFS_Y:
                ypos += data;
                break;

            case DIMOFS_BUTTON0:
                if (data & 0x80)
                    old_buttons[0] = state.rgbButtons[0] = byte (data);
                else
                    state.rgbButtons[0] = byte (data);
                break;

            case DIMOFS_BUTTON1:
                if (data & 0x80)
                    old_buttons[1] = state.rgbButtons[1] = byte (data);
                else
                    state.rgbButtons[1] = byte (data);
                break;

            case DIMOFS_BUTTON2:
                if (data & 0x80)
                    old_buttons[2] = state.rgbButtons[2] = byte (data);
                else
                    state.rgbButtons[2] = byte (data);
                break;

            case DIMOFS_BUTTON3:
                if (data & 0x80)
                    old_buttons[3] = state.rgbButtons[3] = byte (data);
                else
                    state.rgbButtons[3] = byte (data);
                break;
        }
    }

    // Accumulate position, and clip to the window, or toss it all out
    // and ask Windows where the cursor is, as appropriate.
    if (cursor_on)
    {
        POINT pt;
        GetCursorPos (&pt);

        if (pt.x > max_x)
            pt.x = max_x;

        if (pt.y > max_y)
            pt.y = max_y;

        xpos = pt.x;
        ypos = pt.y;
    }
    else
    {
        if (xpos < 0)
            xpos = 0;
        else if (xpos > max_x)
            xpos = max_x;

        if (ypos < 0)
            ypos = 0;
        else if (ypos > max_y)
            ypos = max_y;
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  show_cursor                                                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void MaxMouseDirectX::show_cursor (bool on)
{
    ShowCursor (cursor_on = on);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  get_pos                                                                 �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void MaxMouseDirectX::get_pos (short *mx, short *my) const
{
    assert (mx && my);

    if (cursor_on)
    {
        POINT pt;
        GetCursorPos (&pt);

        if (pt.x > max_x)
            pt.x = max_x;

        if (pt.y > max_y)
            pt.y = max_y;

        *mx = short (pt.x);
        *my = short (pt.y);
    }
    else
    {
        // This should have been clipped into something sane....
        *mx = short (xpos);
        *my = short (ypos);
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  set_pos                                                                 �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void MaxMouseDirectX::set_pos (short _mx, short _my)
{
    if (_mx > max_x)
        _mx = max_x;

    if (_my > max_y)
        _my = max_y;

    xpos = _mx;
    ypos = _my;

    if (cursor_on)
        SetCursorPos (xpos, ypos);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  get_buttons                                                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
byte MaxMouseDirectX::get_buttons () const
{
    dword d = 0;
    for (int i = 3; i >= 0; i--)
    {
        d <<= 1;
        if (old_buttons[i] & 0x80)
            d |= 1;
    }

    return byte (d & 0xff);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  get_movement                                                            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void MaxMouseDirectX::get_movement (short *dx, short *dy)
{
    assert (dx && dy);

    *dx = short (state.lX);
    *dy = short (state.lY);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  is_present                                                              �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
bool MaxMouseDirectX::is_present () const
{
    return pdid != 0;
}

//葦� End of module - maxmouse.cpp 憶�

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
// simsdd.cpp
//
// This module contains the screen management class for DirectDraw
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include "simgine.hpp"

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭�  Constructors/Destructors  碓旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SimScreenDD - Constructor
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
SimScreenDD::SimScreenDD() :
    SimScreen()
{
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SimScreenDD - Destructor
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
SimScreenDD::~SimScreenDD()
{
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  Operations  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SimScreenDD - init
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
SimScreen::error_codes SimScreenDD::init (ushort w, ushort h,
                                          ushort bd, dword flags)
{
    assertMyth("SimScreenDD::init needs SimApp", SimApp != 0);

//陳� Verify bit-depth
    switch (bd)
    {
        case 8:
        case 15:
        case 16:
            break;
        default:
            return ERROR_INVALIDPARMS;
    }

//陳� Determine screen manager init flags
    dword init_flags = 0;
    if (flags & FULLSCREEN)
    {
        init_flags |= VNGO_SET_RESOLUTION;

        if (w == 320 && h == 240)
            init_flags |= VNGO_TRUE_FLIP | VNGO_FORCE_SYSTEMMEMORY;
    }
    if (flags & TRUEFLIP)
    {
        init_flags |= VNGO_TRUE_FLIP;
    }

//陳� Bit-depth error retry loop
    for (;;)
    {
        release();

        //陳� Create screen manager
        vgs = new VngoDirectDraw (SimApp->hWndClient);
        if (!vgs)
            return ERROR_NOMEMORY;

        if (vgs->get_initstate())
        {
            release();
            return ERROR_SCNRMNGRINIT;
        }

        //陳� Create palette
        switch(bd)
        {
            case 8:
                pal = new VngoPal8;
                if (!pal)
                {
                    release();
                    return ERROR_NOMEMORY;
                }
                if (((VngoPal8*)pal)->init(0) != 0)
                {
                    release();
                    return ERROR_PALINIT;
                }
                break;
            case 15:
                pal = new VngoPal15;
                if (!pal)
                {
                    release();
                    return ERROR_NOMEMORY;
                }
                if (((VngoPal15*)pal)->init(0) != 0)
                {
                    release();
                    return ERROR_PALINIT;
                }
                break;
            case 16:
                pal = new VngoPal16;
                if (!pal)
                {
                    release();
                    return ERROR_NOMEMORY;
                }
                if (((VngoPal16*)pal)->init(0) != 0)
                {
                    release();
                    return ERROR_PALINIT;
                }
                break;
            default:
                release();
                return ERROR_INVALIDPARMS;
        }

        //陳� Setup mode
        int cdepth = (bd != 8) ? 16 : 8;

        VNGError err = vgs->set_mode (w, h, cdepth, pal, init_flags);
        if (err == VNGO_NEEDS_PAL16)
            bd = 16;
        else if (err == VNGO_NEEDS_PAL15)
            bd = 15;
        else if (err == VNGO_NEEDS_PAL8)
            bd = 8;
        else if (err)
        {
            release();
            return ERROR_MODEFAIL;
        }
        else
            break;
    }

//陳� Call base
    error_codes err = SimScreen::init(w,h,bd,flags);
    if (err)
        return err;

//陳� Setup viewport
    if (bd == 8)
    {
        gvport = new VngoVportDD8 (((VngoDirectDraw*)vgs)->SurfaceManager,
                                   NULL, pal, 0);
    }
    else
    {
        gvport = new VngoVportDD16 (((VngoDirectDraw*)vgs)->SurfaceManager,
                                    NULL, pal, 0);
    }

    if (!gvport)
    {
        release();
        return ERROR_NOMEMORY;
    }

    if (gvport->get_init_state())
    {
        release();
        return ERROR_VPORTINIT;
    }

    clear();

    return ERROR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SimScreenDD - create_subviewport
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
VngoVport *SimScreenDD::create_subviewport(VngoRect &srect, dword flags)
{
    assertMyth("SimScreenDD::create_subviewport needs screen manager and palette",
               vgs != 0 && pal != 0);

    if (bit_depth == 8)
    {
        return new VngoVportDD8(((VngoDirectDraw*)vgs)->SurfaceManager,
                                NULL,srect,
                                pal, flags);
    }
    else
    {
        return new VngoVportDD16(((VngoDirectDraw*)vgs)->SurfaceManager,
                                 NULL,srect,
                                 pal, flags);
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SimScreenDD - lock
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
long SimScreenDD::lock ()
{
    return 1;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SimScreenDD - unlock
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int SimScreenDD::unlock ()
{
    return 0;
}

//葦� End of module - simsdd.cpp 憶�


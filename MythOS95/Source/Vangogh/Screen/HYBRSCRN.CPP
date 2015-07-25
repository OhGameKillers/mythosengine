//���������������������������������������������������������������������������
//
//                                                           %__________%
//                                                          %/ . .  .   \%
//           Van Gogh 2D-Display Library                     |  . .  o. |
//                                                           |. _  .   .|
//          Microsoft Windows '95 Version                    | / \   .  |
//                                                           |_|_|_._._.|
// Copyright (c) 1994-1997 by Charybdis Enterprises, Inc.    |.-.-.-.-..|
//              All rights reserved.                        %\__________/%
//                                                           %          %
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
// DDraw.cpp
//
//  This file contains the member functions for the class that describes
//  the current game state.  This class also "runs" the game, but must
//  be driven by an outside program.
//
//���������������������������������������������������������������������������

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <windows.h>
#include <ddraw.h>
#include "debug.h"
#include "portable.h"
#include "vangogh.hpp"
#include "vngscrn.hpp"

VngoHybrid::VngoHybrid():
    dd(0),
    FrontBuffer(NULL),
    BackBuffer(NULL),
    Primary(NULL),
    Palette(NULL),
    gmap(NULL),
    pitch(0),
    hWndClient(NULL)
{
    strcpy(hwName,"Hybrid");
    pal = NULL;
}

VngoHybrid::VngoHybrid(HWND hwndclient):
    dd(0),
    FrontBuffer(NULL),
    BackBuffer(NULL),
    Primary(NULL),
    Palette(NULL),
    gmap(NULL),
    pitch(0),
    hWndClient(hwndclient)
{
    strcpy(hwName,"Hybrid");
    pal = NULL;
    init_state = init();
}

VngoHybrid::~VngoHybrid()
{
    term();
}


BOOL VngoHybrid::init()
{
    strcpy(hwName,"Hybrid");
    err = DirectDrawCreate(NULL, &dd, NULL);

    if (err != DD_OK)
        return FALSE;

    type_info = SCREENTYPE_HYBRID;
    return TRUE;
}


void VngoHybrid::reinit(Flx16 brightness)
{
    if (!pal)
        return;

    set_palette(pal,brightness);
}

BOOL VngoHybrid::check_mode(int _width, int _height, int bpp)
{
    assert (dd != 0);

    return (FALSE);
}



BOOL VngoHybrid::set_mode(int _width, int _height, int bpp, VngoPal *_pal,dword flags)
{
    width = _width;
    height = _height;
    lflags = flags;
    startx = 0;
    starty = 0;
    bit_depth = bpp;

    if (err != DD_OK)
        return FALSE;

    if (lflags & VNGO_SET_RESOLUTION)
    {
        err = dd->SetCooperativeLevel(hWndClient,
            DDSCL_EXCLUSIVE | DDSCL_FULLSCREEN | DDSCL_ALLOWMODEX);
        if (err == DD_OK)
            err = dd->SetDisplayMode(width, height, bpp);
    }
    else
    {
        err = dd->SetCooperativeLevel(hWndClient,DDSCL_NORMAL);
    }

    if (err != DD_OK)
        return FALSE;

    // Get rid of any previous surfaces.
    if (FrontBuffer)
    {
        FrontBuffer->Release();
        FrontBuffer = NULL;
    }
    if (Palette)
    {
        Palette->Release();
        Palette = NULL;
    }
    if (gmap)
    {
        delete gmap;
        gmap = NULL;
    }

    // Creat surfaces.
    ZeroMemory (&ddsd, sizeof(ddsd));
    ddsd.dwSize = sizeof(ddsd);
    if (lflags & VNGO_TRUE_FLIP)
    {
        ddsd.dwFlags = DDSD_CAPS | DDSD_BACKBUFFERCOUNT;
        ddsd.dwBackBufferCount = 1;
        ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE |
                              DDSCAPS_FLIP |
                              DDSCAPS_COMPLEX |
                              DDSCAPS_VIDEOMEMORY;
    }
    else
    {
        ddsd.dwFlags = DDSD_CAPS;
        ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE
                              | DDSCAPS_VIDEOMEMORY;
    }

    err = dd->CreateSurface(&ddsd, &Primary, NULL);

    if (err != DD_OK)
        return FALSE;


    // get a pointer to the back buffer.
    if (lflags & VNGO_TRUE_FLIP)
    {
        DDSCAPS caps;
        caps.dwCaps = DDSCAPS_BACKBUFFER;
        err = Primary->GetAttachedSurface(&caps, &BackBuffer);

        if (err != DD_OK)
            return FALSE;
    }
    else
    {
        ddsd.dwFlags = DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;

        if (lflags & VNGO_FORCE_SYSTEMMEMORY)
            ddsd.ddsCaps.dwCaps = DDSCAPS_SYSTEMMEMORY;
        else
        {
            ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_VIDEOMEMORY;
            if (lflags & VNGO_3DDEVICE)
                ddsd.ddsCaps.dwCaps |= DDSCAPS_3DDEVICE;
        }

        ddsd.dwHeight = height;
        ddsd.dwWidth = width;
        err = dd->CreateSurface (&ddsd, &BackBuffer, NULL);

        if (err != DD_OK)
            return FALSE;
    }

    //
    //
    // OK, now creat the FrontBuffer surface using a DIB that we
    // create here!
    //
    //

#if 0
    if (bpp == 8)
    {
        gmap = new byte[_width * _height];
        if (gmap == NULL)
            return FALSE;
    }
    else
    {
        gmap = new byte[_width * _height * 2];
        if (gmap == NULL)
            return FALSE;
    }
#endif

    ddsd.dwFlags = DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH | DDSD_PITCH;
    ddsd.ddsCaps.dwCaps = DDSCAPS_SYSTEMMEMORY;
    ddsd.dwWidth    = _width;
    ddsd.dwHeight   = _height;
    ddsd.lPitch     = _width;
    err = dd->CreateSurface (&ddsd, &FrontBuffer, NULL);

    if (err != DD_OK)
        return FALSE;

#if 1 // For now we will steal the pointer from the surface and assume it never moves. :(
    int fail_safe = 0;
    int locked = 0;
    gmap = NULL;
    while (!locked && (fail_safe < 1000))
    {
        if ((err = FrontBuffer->Lock (NULL, &ddsd,
                                      DDLOCK_SURFACEMEMORYPTR
                                      | DDLOCK_WAIT, NULL)) == DD_OK)
        {
            pitch = ddsd.lPitch;
            gmap = (byte *)ddsd.lpSurface;
            FrontBuffer->Unlock( NULL );

            locked = 1;
        }
        if (err == DDERR_SURFACELOST)
        {
            err = FrontBuffer->Restore();
            if (err != DD_OK)
                locked = 1; // an error occured while
                            // restoring the surface, so it cannot be locked.
        }
    }
    if (gmap == NULL)
        return FALSE;

#else
    // Ok now we have a surface, lets change it to use our memory.
    ddsd.dwFlags    = DDSD_HEIGHT | DDSD_WIDTH | DDSD_PITCH
                      | DDSD_LPSURFACE;
    ddsd.dwWidth    = _width;
    ddsd.dwHeight   = _height;
    ddsd.lPitch     = _width;
    ddsd.lpSurface  = (void*)gmap;

    LPDIRECTDRAWSURFACE3    temp;
    err = FrontBuffer->QueryInterface(IID_IDirectDrawSurface3,(LPVOID*)&temp);
    if (err != DD_OK)
    {
        return FALSE;
    }

    err = temp->SetSurfaceDesc(&ddsd,0);
#endif
    if(err!=DD_OK)
    {
        return FALSE;
    }

    if (err != DD_OK)
        return FALSE;

    // Create a palette if we are in a paletized display mode.

    if (bpp == 8)
    {
        pal=_pal;
        PALETTEENTRY        ape[256];
        HDC hdc = GetDC(NULL);
        if (GetDeviceCaps(hdc, RASTERCAPS) & RC_PALETTE)
        {
            // get the current windows colors.
            GetSystemPaletteEntries(hdc, 0, 256, ape);

            if (pal)
            {
                // make the palette we want.
                for (int i=0; i < 256; i++)
                {
                    ape[i].peRed   = ((VngoPal8 *)pal)->get_RGB(i).r;
                    ape[i].peGreen = ((VngoPal8 *)pal)->get_RGB(i).g;
                    ape[i].peBlue  = ((VngoPal8 *)pal)->get_RGB(i).b;
                }
            }
            err = dd->CreatePalette(DDPCAPS_8BIT | DDPCAPS_ALLOW256,
                                    ape, &Palette, NULL);

            if (err == DD_OK)
            {
                err = Palette->SetEntries(0,0,256,ape);
                if (err == DD_OK)
                {
                    Primary->SetPalette(Palette);
                    BackBuffer->SetPalette(Palette);
                    FrontBuffer->SetPalette(Palette);
                }
            }

        }
        ReleaseDC (NULL, hdc);
    }

    return TRUE;
}

void VngoHybrid::flip()
{

    if (Primary->IsLost() == DDERR_SURFACELOST)
        Primary->Restore();

    if (BackBuffer->IsLost() == DDERR_SURFACELOST)
        Primary->Restore();


#if 1
    RECT rcRect;
    rcRect.left = 0;
    rcRect.top = 0;
    rcRect.right = width;
    rcRect.bottom = height;
#endif
    RECT srcRect;
    srcRect.left = startx + damage_rect.left;
    srcRect.top = starty + damage_rect.top;
    srcRect.right = startx + damage_rect.right;
    srcRect.bottom = starty + damage_rect.bottom;

    while (1)
    {
//        HRESULT ddrval = BackBuffer->Blt(&rcRect,
        HRESULT ddrval = Primary->Blt(&rcRect,
                                      FrontBuffer,
                                      &rcRect,
                                      0, NULL);
        if (ddrval == DD_OK)
        {
            break;
        }
        if (ddrval != DDERR_WASSTILLDRAWING)
        {
            return;
        }
    }
#if 0
    if (lflags & VNGO_TRUE_FLIP)
    {
        if (lflags & VNGO_FORCE_SYSTEMMEMORY)
        {
            RECT rcRect;
            rcRect.left = 0;
            rcRect.top = 0;
            rcRect.right = width;
            rcRect.bottom = height;

            while (1)
            {
                HRESULT ddrval = BackBuffer->Blt(&rcRect,
                                                 FrontBuffer,
                                                 &rcRect,
                                                 0, NULL);
                if (ddrval == DD_OK)
                {
                    break;
                }
                if (ddrval != DDERR_WASSTILLDRAWING)
                {
                    return;
                }
            }
        }
        Primary->Flip(NULL,DDFLIP_WAIT);
    }
    else
    {
#if 1
        RECT rcRect;
        rcRect.left = 0;
        rcRect.top = 0;
        rcRect.right = width;
        rcRect.bottom = height;
#endif
        RECT srcRect;
        srcRect.left = startx + damage_rect.left;
        srcRect.top = starty + damage_rect.top;
        srcRect.right = startx + damage_rect.right;
        srcRect.bottom = starty + damage_rect.bottom;

        while (1)
        {
            HRESULT ddrval = Primary->Blt(&rcRect,
                                          BackBuffer,
//                                          &damage_rect,
                                          &rcRect,
                                          0, NULL);
            if (ddrval == DD_OK)
            {
                break;
            }
            if (ddrval != DDERR_WASSTILLDRAWING)
            {
                return;
            }
        }
    }
#endif
    VngoScreenManager::flip();
}

void VngoHybrid::set_palette(VngoPal *p,Flx16 brightness)
{
    if (!Palette)
        return;

    pal = p;

    PALETTEENTRY        ape[256];

    // make the palette we want.
    for (int i=0; i < 256; i++)
    {
        VngoColorHLS hls;
        VngoColor24bit rgb;

        hls = ((VngoPal8*)p)->hw_pal.p[i];
        hls.l += brightness;
        if(hls.l < 0)
            hls.l = 0;
        else if (hls.l > Flx16(1))
            hls.l = Flx16(1);

        rgb = hls;

        ape[i].peRed   = rgb.r;
        ape[i].peGreen = rgb.g;
        ape[i].peBlue  = rgb.b;
    }

    Palette->SetEntries(0,0,256,ape);

}



void VngoHybrid::term()
{
    if (FrontBuffer)
    {
        FrontBuffer->Release();
        FrontBuffer = NULL;
    }

    if (Primary)
    {
        Primary->Release();
        Primary = NULL;
    }


    if (Palette)
    {
        Palette->Release();
        Palette = NULL;
    }

    if (gmap)
    {
        delete gmap;
        gmap = NULL;
    }

    if (dd)
    {
        dd->SetCooperativeLevel(hWndClient,DDSCL_NORMAL);
        dd->Release();
        dd = NULL;
    }
}
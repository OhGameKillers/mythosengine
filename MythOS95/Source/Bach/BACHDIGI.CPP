//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//
//                        樛樛樛樛樛                       樛樛
//     敖朕                栩�     栩�                     渟栩
//     �  �       敖朕     栩�     栩�   樛樛      樛樛�    栩� 樛�
//     �  � 敖朕  �  �     栩桀樛樂栩�  �  渟�    栩�   炳  栩栩桎栩
//     �  � �  �  �  �     栩�     栩�  樂栩栩�  栩�        栩�   栩�
//    O� O� �  �  �  �     栩�     栩� 渟�  栩�  栩�    樂  栩�   栩�
//          �  � O� O�    樂栩樛樂栩�   栩栩毯桀  炳桀樂�  樂栩� 樂栩�
//         O� O�
//                            C++ Music, Sound, and Effects Library
//                               Microsoft Windows 95/98/NT Version
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
// Created by Dan Higdon & Chuck Walbourn
//
// bachdigi.cpp
//
// Digital sound source implementation
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <stdlib.h>
#include <string.h>

#include "bach.hpp"

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭�  Constructors/Destructors  碓旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachDigital - Constructor
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
BachDigital::BachDigital (ulong drate, bach_digi_fmt fmt):
    dsound (0),
    primary (0),
    driverRate (drate),
    driverFmt (fmt),
    flags (0)
{
    assertMyth ("BachDigital needs valid driver rate", drate != 0);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachDigital - Destructor
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
BachDigital::~BachDigital()
{
    close ();
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  Operations  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachDigital - init
//
// Initializes the digital driver.
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
bach_err_codes BachDigital::init (HWND hWnd, DWORD coop_level, int cont_play)
{
    if (dsound)
        return BACH_ERR_NONE;

    if (!hWnd)
        return BACH_ERR_INVALIDPARAMS;

    switch (coop_level)
    {
        case DSSCL_WRITEPRIMARY:
        case DSSCL_EXCLUSIVE:
        case DSSCL_PRIORITY:
        case DSSCL_NORMAL:
            break;
        default:
            return BACH_ERR_INVALIDPARAMS;
    }

//陳 Create Direct Sound Object
    if (DirectSoundCreate (NULL, &dsound, NULL) != DS_OK)
        return BACH_ERR_DSCONNECTFAIL;

    assertMyth("BachDigital::init has invalid DSound create result",
               dsound != 0);

//陳 Let Direct Sound know how much control we need
    if (dsound->SetCooperativeLevel (hWnd, coop_level) != DS_OK)
    {
        close();
        return BACH_ERR_DSSETCOOPFAIL;
    }

//陳 Create Primary Direct Sound Buffer
    DSBUFFERDESC    bd;
    memset (&bd, 0, sizeof (bd));

    bd.dwSize = sizeof (bd);
    bd.dwFlags = DSBCAPS_PRIMARYBUFFER;

    if (dsound->CreateSoundBuffer (&bd, &primary, NULL) != DS_OK)
    {
        close();
        return BACH_ERR_DSPRICREATFAIL;
    }

    assertMyth("BachDigital::init failed DSound buffer create",
                primary != 0);

//陳 Get caps of primary buffer
    DSBCAPS     caps;
    caps.dwSize = sizeof(caps);

    primary->GetCaps(&caps);

    assertMyth("BachDigital::init has invalid caps for primary buffer",
               (caps.dwFlags & DSBCAPS_PRIMARYBUFFER)
               && (caps.dwBufferBytes > 0));

//陳 Setup format
    WAVEFORMATEX    wfmt;
    memset(&wfmt,0,sizeof(wfmt));

    switch (driverFmt)
    {
        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Mono 8-bit
        case BACH_DIGI_MONO_8:
            wfmt.nChannels      = 1;
            wfmt.wBitsPerSample = 8;
            wfmt.nBlockAlign    = 1;
            break;
        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Mono 16-bit
        case BACH_DIGI_MONO_16:
            wfmt.nChannels      = 1;
            wfmt.wBitsPerSample = 16;
            wfmt.nBlockAlign    = 2;
            break;
        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Stereo 8-bit
        case BACH_DIGI_STEREO_8:
            wfmt.nChannels      = 2;
            wfmt.wBitsPerSample = 8;
            wfmt.nBlockAlign    = 2;
            break;
        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Stereo 16-bit
        case BACH_DIGI_STEREO_16:
            wfmt.nChannels      = 2;
            wfmt.wBitsPerSample = 16;
            wfmt.nBlockAlign    = 4;
            break;
        //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Unknown
        default:
            close();
            return BACH_ERR_NOTSUPPORTED;
    }

    wfmt.wFormatTag      = WAVE_FORMAT_PCM;
    wfmt.nSamplesPerSec  = driverRate;
    wfmt.cbSize          = 0;
    wfmt.nAvgBytesPerSec = driverRate * wfmt.nBlockAlign;

//陳 Set format for primaray buffer
    if (coop_level == DSSCL_WRITEPRIMARY)
    {
        if (primary->SetFormat (&wfmt) != DS_OK)
        {
            close();
            return BACH_ERR_DSFORMATFAILED;
        }
    }
    else
    {
        if (primary->SetFormat (&wfmt) != DS_OK
            && coop_level != DSSCL_NORMAL)
        {
            close();
            return BACH_ERR_DSFORMATFAILED;
        }
    }

//陳 Begin primary buffer play
    if (cont_play)
    {
        if (primary->Play (0, 0, DSBPLAY_LOOPING) != DS_OK)
        {
            close();
            return BACH_ERR_DSFAILED;
        }
    }

    flags |= BACH_DIGI_PRIMARY_INITIALIZED;

    return BACH_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachDigital - close
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void BachDigital::close()
{
//陳 Release Direct Sound Buffer and Object
    if (primary)
    {
        if (flags & BACH_DIGI_PRIMARY_INITIALIZED)
            primary->Stop();
        primary->Release();
        primary = 0;
        flags &= ~BACH_DIGI_PRIMARY_INITIALIZED;
    }

    if (dsound)
    {
        dsound->Release();
        dsound = 0;
    }

}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭葦  Utilities 碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachDigital - get_caps
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
bach_err_codes BachDigital::get_caps(DSCAPS &caps) const
{
    if (!dsound)
        return BACH_ERR_UNINITIALIZED;

    memset(&caps,0,sizeof(DSCAPS));
    caps.dwSize = sizeof(DSCAPS);

    if (dsound->GetCaps(&caps) != DS_OK)
        return BACH_ERR_DSFAILED;

    return BACH_ERR_NONE;
}

//葦� End of module - bachdigi.cpp 憶�

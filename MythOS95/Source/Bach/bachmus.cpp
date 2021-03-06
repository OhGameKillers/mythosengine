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
// bachmus.cpp
//
// Music sound source implementation
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

#include <direct.h>

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

int     BachCOMInit     =  0;

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭�  Constructors/Destructors  碓旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachMusic - Constructor
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
BachMusic::BachMusic () :
    dmusic(0),
    port(0),
    perf(0),
    loader(0)
{
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachMusic - Destructor
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
BachMusic::~BachMusic()
{
    close ();
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  Operations  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachMusic - init
//
// Initializes the music source by obtaining DirectMusic performance
// and loader objects.
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
bach_err_codes BachMusic::init (BachDigital *digi, HWND hwnd, DWORD effects)
{
    if (dmusic)
        return BACH_ERR_NONE;

    if (!BachCOMInit)
    {
        CoInitialize(NULL);
        BachCOMInit=1;
    }

//陳� Create a performance object
    HRESULT hr = CoCreateInstance(CLSID_DirectMusicPerformance,
                                  NULL,
                                  CLSCTX_INPROC,
                                  IID_IDirectMusicPerformance,
                                  (void **) &perf);

    if (FAILED(hr))
    {
        close();
        return BACH_ERR_DMFAILED;
    }

    assertMyth("BachMusic::init() failed to obtain performance object",
               perf != 0);

//陳� Initialize performance object (and get DirectMusic object)
    dmusic=NULL;
    hr = perf->Init(&dmusic, (digi) ? digi->dsound : NULL, hwnd);
    if (FAILED(hr))
    {
        close();
        return (hr == E_OUTOFMEMORY) ? BACH_ERR_OUTOFMEMORY : BACH_ERR_DMFAILED;
    }

    assertMyth("BachMusic::init() failed to obtain DirectMusic object",
               dmusic != 0);

//陳� Create and assign port
    DMUS_PORTCAPS   caps;
    memset(&caps,0,sizeof(caps));
    caps.dwSize = sizeof(caps);

    for(int index=0; ; index++)
    {
        hr = dmusic->EnumPort(index, &caps);
        if (FAILED(hr))
        {
            close();
            return BACH_ERR_DMFAILED;
        }

        if (hr == S_FALSE)
            break;

        if (caps.dwClass == DMUS_PC_OUTPUTCLASS)
        {
            break;
        }
    }

    DMUS_PORTPARAMS params;
    memset(&params,0,sizeof(params));
    params.dwSize = sizeof(params);
    params.dwEffectFlags = effects;
    params.dwChannelGroups = 1;
    params.dwValidParams = DMUS_PORTPARAMS_CHANNELGROUPS
                           | DMUS_PORTPARAMS_EFFECTS;

    hr = dmusic->CreatePort(caps.guidPort, &params, &port, NULL);
    if (FAILED(hr))
    {
        close();
        return BACH_ERR_DMFAILED;

    }
    assertMyth("BachMusic::init() failed to obtain port",
               port != 0);

    port->Activate(TRUE);

    hr = perf->AddPort(port);
    if (FAILED(hr))
    {
        close();
        return (hr == E_OUTOFMEMORY) ? BACH_ERR_OUTOFMEMORY : BACH_ERR_DMFAILED;
    }

    hr = perf->AssignPChannelBlock(0, port, 1);
    if (FAILED(hr))
    {
        close();
        return BACH_ERR_DMFAILED;
    }

//陳� Obtain loader
    hr = CoCreateInstance(CLSID_DirectMusicLoader,
                          NULL,
                          CLSCTX_INPROC,
                          IID_IDirectMusicLoader,
                          (void **) &loader);

    if (FAILED(hr))
    {
        close();
        return BACH_ERR_DMFAILED;
    }

    assertMyth("BachMusic::init() failed to obtain loader object",
               loader != 0);

//陳� Ensure loader is using app's current directory
    char szDir[_MAX_PATH];
    WCHAR wszDir[_MAX_PATH];

    if(_getcwd( szDir, _MAX_PATH ) == NULL )
    {
        close();
        return BACH_ERR_FILEERROR;
    }

    mbstowcs(wszDir, szDir, _MAX_PATH);

    hr = loader->SetSearchDirectory(GUID_DirectMusicAllTypes,
                                    wszDir, FALSE );

    if (FAILED(hr))
    {
        close();
        return (hr == E_OUTOFMEMORY) ? BACH_ERR_OUTOFMEMORY : BACH_ERR_DMFAILED;
    }

    return BACH_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachMusic - close
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void BachMusic::close()
{
//陳 Stop all music
    if (perf)
        perf->Stop(NULL, NULL, 0, 0);

//陳 Release DirectMusic objects
    if (loader)
    {
        loader->Release();
        loader = 0;
    }
    if (perf)
    {
        perf->Release();
        perf = 0;
    }
    if (port)
    {
        port->Release();
        port=0;
    }
    if (dmusic)
    {
        dmusic->Release();
        dmusic=0;
    }
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭葦  Utilities 碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachMusic - activate
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
bach_err_codes BachMusic::activate()
{
    if (!dmusic)
        return BACH_ERR_UNINITIALIZED;

    HRESULT hr = dmusic->Activate(TRUE);
    if (FAILED(hr))
        return BACH_ERR_DMFAILED;

    return BACH_ERR_NONE;
}

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// BachMusic - deactivate
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
bach_err_codes BachMusic::deactivate()
{
    if (!dmusic)
        return BACH_ERR_UNINITIALIZED;

    HRESULT hr = dmusic->Activate(FALSE);
    if (FAILED(hr))
        return BACH_ERR_DMFAILED;

    return BACH_ERR_NONE;
}

//葦� End of module - bachmus.cpp 憶�

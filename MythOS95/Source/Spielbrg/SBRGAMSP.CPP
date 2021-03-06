//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//                                                      _o######ooooooo-_
//     Spielberg -- Animation player library          o#####o_o#####~~~~~~
//                                                   ################o__o
//      Microsoft Windows 95/98/NT Version        _o###########~~~~~###~
//                                               o##############
//                                            _o###############~
//                                          _o#########~ooo~##~
//                                     _o############# ##o::___
//                                   _o#################oo:~~~~~
//                                 _o#####################~
//                               _####~_oooooooo:~~######~
//                             _##### o###########_:~##~
//                            o#####_##################
//                           _#######_~#################_
//                           ##########o:~###############o
//                         _##############o~##############_
//                       o#############~~     ~~~~~~~######_
//                   __o##########~::o_             o#######
//              _oo##########~~::o#####            o###########o___
//          o##########~~~~    ~~~##########       ~~~~#############o
//         #####~~~~~~                ~~~
//
//  Copyright (c) 1996-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
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
// Created by Tim Little & Chuck Walbourn
//
// sbrgamsp.cpp
//
// ActiveMovie(TM) streaming player Spielberg class implementation
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include "spielbrg.hpp"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#define OATRUE      -1
#define OAFALSE     0

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

extern int SpielbrgCOMInit;

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭�  Constructors/Destructors  碓旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SpielbergAMStreamPlayer - Constructor
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
SpielbergAMStreamPlayer::SpielbergAMStreamPlayer(LPDIRECTDRAW _ddraw,
                                                 LPDIRECTDRAWSURFACE _dsurf) :
    SpielbergPlayer(),
    ddraw(_ddraw),
    dsurf(_dsurf),
    am_stream(0),
    am_vidstream(0),
    am_ddsample(0),
    am_ddsurf(0)
{
    assertMyth("SpielbergAMStreamPlayer needs DirectDraw and surface",
               _ddraw != 0 && _dsurf != 0);

    ddraw->AddRef();
    dsurf->AddRef();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SpielbergAMStreamPlayer - Destructor
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
SpielbergAMStreamPlayer::~SpielbergAMStreamPlayer()
{
    close();

    if (ddraw)
    {
        ddraw->Release();
        ddraw=0;
    }
    if (dsurf)
    {
        dsurf->Release();
        dsurf=0;
    }
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  Operations  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SpielbergAMStreamPlayer - open
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
sberg_err_codes SpielbergAMStreamPlayer::open(const char *name, dword ctrlfl)
{
    if (!name)
        return SBERG_ERR_INVALIDPARMS;

    if (!xf_exist(name))
        return SBERG_ERR_FILENOTFOUND;

    if (am_stream)
        return SBERG_ERR_ALREADYOPEN;

//陳� Initialize COM
    if (!SpielbrgCOMInit)
    {
        CoInitialize(NULL);
        SpielbrgCOMInit=1;
    }

//陳� Connect to ActiveMovie
    HRESULT hr = CoCreateInstance(CLSID_AMMultiMediaStream,
                                  NULL,
                                  CLSCTX_INPROC_SERVER,
                                  IID_IAMMultiMediaStream,
                                  (void **) &am_stream);

    if (FAILED(hr))
    {
        am_stream=0;
        return SBERG_ERR_AMCONNECTFAILED;
    }

//陳� Initialize the stream
    hr=am_stream->Initialize(STREAMTYPE_READ, 0, NULL);
    if (FAILED(hr))
    {
        close();
        return SBERG_ERR_AMFAILED;
    }

//陳� Add video/audio renders
    assertMyth("SpielbergAMStreamPlayer::open() needs DirectDraw",
               ddraw != 0);

    hr=am_stream->AddMediaStream(ddraw, &MSPID_PrimaryVideo, 0, NULL);
    if (FAILED(hr))
    {
        close();
        return SBERG_ERR_VIDEOFAILED;
    }

    hr=am_stream->AddMediaStream(NULL, &MSPID_PrimaryAudio,
                                 AMMSF_ADDDEFAULTRENDERER, NULL);
    if (FAILED(hr))
    {
        close();
        return SBERG_ERR_AUDIOFAILED;
    }

//陳� Attach file to graph
    WCHAR   wPath[XF_MAX_PATH];

    MultiByteToWideChar(CP_ACP,0,name, -1, wPath, XF_MAX_PATH);

    hr = am_stream->OpenFile(wPath,NULL);
    if (FAILED(hr))
    {
        close();
        return SBERG_ERR_NOTSUPPORTED;
    }

//陳� Get handle for end of playback
    hr = am_stream->GetEndOfStreamEventHandle(&am_event);
    if (FAILED(hr))
    {
        close();
        return SBERG_ERR_AMFAILED;
    }

//陳� Setup video for stream playback
    hr=am_stream->GetMediaStream(MSPID_PrimaryVideo, &am_vidstream);
    if (FAILED(hr))
    {
        close();
        return SBERG_ERR_AMFAILED;
    }

    hr=am_vidstream->QueryInterface(IID_IDirectDrawMediaStream,
                                    (void **) &am_ddstream);
    if (FAILED(hr))
    {
        close();
        return SBERG_ERR_AMQUERYIFAILED;
    }

    hr=am_ddstream->CreateSample(NULL, NULL, 0, &am_ddsample);
    if (FAILED(hr))
    {
        close();
        return SBERG_ERR_AMFAILED;
    }

    hr=am_ddsample->GetSurface(&am_ddsurf, &am_srect);
    if (FAILED(hr))
    {
        close();
        return SBERG_ERR_AMFAILED;
    }

    am_swidth = ushort(am_srect.right - am_srect.left);
    am_sheight = ushort(am_srect.bottom - am_srect.top);

//陳� Determine destination rectangle
    am_drect = am_srect;

    assertMyth("SpielbergAMStreamPlayer::open() needs DirectDraw surface",
               dsurf != 0);

    DDSURFACEDESC   ddesc;
    ddesc.dwSize = sizeof(ddesc);
    hr=dsurf->GetSurfaceDesc(&ddesc);
    if (hr == DD_OK)
    {
        //陳� By default, center playback into our target surface,
        //陳� but if it is off the surface, start at 0,0 and show as
        //陳� much as you can...

        am_drect.left = (ddesc.dwWidth>>1) - (am_swidth>>1);
        if (am_drect.left < 0)
            am_drect.left = 0;

        if (ddesc.dwWidth >= am_swidth)
            am_drect.right = am_drect.left + am_swidth;
        else
            am_drect.right = am_drect.left + ddesc.dwWidth;

        am_drect.top = (ddesc.dwHeight>>1) - (am_sheight>>1);
        if (am_drect.top < 0)
            am_drect.top = 0;

        if (ddesc.dwHeight >= am_sheight)
            am_drect.bottom = am_drect.top + am_sheight;
        else
            am_drect.bottom = am_drect.top + ddesc.dwHeight;
    }

    flags &= ~(SBERG_PLAYER_PLAYING | SBERG_PLAYER_PAUSED);

    return SBERG_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SpielbergAMStreamPlayer - close
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
sberg_err_codes SpielbergAMStreamPlayer::close()
{
    stop();

    if (am_ddsurf)
    {
        am_ddsurf->Release();
        am_ddsurf=0;
    }
    if (am_ddsample)
    {
        am_ddsample->Release();
        am_ddsample=0;
    }
    if (am_vidstream)
    {
        am_vidstream->Release();
        am_vidstream=0;
    }
    if (am_stream)
    {
        am_stream->Release();
        am_stream=0;
    }
    am_event=0;

    flags &= ~(SBERG_PLAYER_PLAYING | SBERG_PLAYER_PAUSED);

    return SBERG_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SpielbergAMStreamPlayer - play
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
sberg_err_codes SpielbergAMStreamPlayer::play()
{
    if (!am_stream)
        return SBERG_ERR_UNINITIALIZED;

    if (get_flags() & SBERG_PLAYER_PLAYING)
        return SBERG_ERR_NONE;

    HRESULT hr = am_stream->SetState(STREAMSTATE_RUN);
    if (FAILED(hr))
        return SBERG_ERR_AMFAILED;

    flags |= SBERG_PLAYER_PLAYING;
    flags &= ~SBERG_PLAYER_PAUSED;

    return SBERG_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SpielbergAMStreamPlayer - stop
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
sberg_err_codes SpielbergAMStreamPlayer::stop()
{
    if (!am_stream)
        return SBERG_ERR_UNINITIALIZED;

    if (!(get_flags() & SBERG_PLAYER_PLAYING))
        return SBERG_ERR_NONE;

    HRESULT hr = am_stream->SetState(STREAMSTATE_STOP);
    if (FAILED(hr))
        return SBERG_ERR_AMFAILED;

    hr = am_stream->Seek(0);

    flags &= ~(SBERG_PLAYER_PLAYING | SBERG_PLAYER_PAUSED);

    if (FAILED(hr))
        return SBERG_ERR_AMFAILED;

    return SBERG_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SpielbergAMStreamPlayer - pause
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
sberg_err_codes SpielbergAMStreamPlayer::pause()
{
    if (!am_stream)
        return SBERG_ERR_UNINITIALIZED;

    if (!(get_flags() & SBERG_PLAYER_PLAYING))
        return SBERG_ERR_NOTPLAYING;

    if (flags & SBERG_PLAYER_PAUSED)
        return SBERG_ERR_NONE;

    HRESULT hr = am_stream->SetState(STREAMSTATE_STOP);
    if (FAILED(hr))
        return SBERG_ERR_AMFAILED;

    flags |= SBERG_PLAYER_PAUSED;

    return SBERG_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SpielbergAMStreamPlayer - resume
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
sberg_err_codes SpielbergAMStreamPlayer::resume()
{
    if (!am_stream)
        return SBERG_ERR_UNINITIALIZED;

    if (!(get_flags() & SBERG_PLAYER_PLAYING))
        return SBERG_ERR_NOTPLAYING;

    if (!(flags & SBERG_PLAYER_PAUSED))
        return SBERG_ERR_NONE;

    HRESULT hr = am_stream->SetState(STREAMSTATE_RUN);
    if (FAILED(hr))
        return SBERG_ERR_AMFAILED;

    flags &= ~SBERG_PLAYER_PAUSED;

    return SBERG_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SpielbergAMStreamPlayer - set_position
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
sberg_err_codes SpielbergAMStreamPlayer::set_position(ulong ms)
{
    if (!am_stream)
        return SBERG_ERR_UNINITIALIZED;

    HRESULT hr=am_stream->Seek(ms * 10000);
    if (FAILED(hr))
        return SBERG_ERR_AMFAILED;

    return SBERG_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SpielbergAMStreamPlayer - get_position
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
ulong SpielbergAMStreamPlayer::get_position() const
{
    if (!am_stream)
        return SBERG_ERR_UNINITIALIZED;

    STREAM_TIME time;

    HRESULT hr=am_stream->GetTime(&time);
    if (FAILED(hr))
        return 0;

    return ulong(time / 10000);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SpielbergAMStreamPlayer - get_info
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
sberg_err_codes SpielbergAMStreamPlayer::get_info(SpielbergInfo *info) const
{
    if (!info)
        return SBERG_ERR_INVALIDPARMS;

    if (!am_stream || !am_ddstream)
        return SBERG_ERR_UNINITIALIZED;

    memset(info,0,sizeof(SpielbergInfo));

    info->width = am_swidth;
    info->height = am_sheight;

    STREAM_TIME time;
    HRESULT hr = am_stream->GetDuration(&time);
    if (FAILED(hr))
        return SBERG_ERR_AMFAILED;

    info->duration = ulong (time / 10000);

    return SBERG_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SpielbergAMStreamPlayer - get_flags
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
dword SpielbergAMStreamPlayer::get_flags()
{
    if (!am_stream)
        return flags;

    if (flags & SBERG_PLAYER_PLAYING)
    {
        if (WaitForSingleObject(&am_event, 0) == WAIT_OBJECT_0)
        {
            am_stream->SetState(STREAMSTATE_STOP);
            am_stream->Seek(0);

            flags &= ~(SBERG_PLAYER_PLAYING | SBERG_PLAYER_PAUSED);
        }
    }

    return flags;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SpielbergAMStreamPlayer - display
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void SpielbergAMStreamPlayer::display()
{
    if (!(get_flags() & SBERG_PLAYER_PLAYING))
        return;

    if (!am_ddsample || !am_stream)
        return;

    if (am_ddsample->Update(0, NULL, NULL, 0) == MS_S_ENDOFSTREAM)
    {
        am_stream->SetState(STREAMSTATE_STOP);
        am_stream->Seek(0);

        flags &= ~(SBERG_PLAYER_PLAYING | SBERG_PLAYER_PAUSED);
    }
    else
    {
        assertMyth("SpielbergAMStreamPlayer::display() needs DirectDraw surface",
                   dsurf != 0);

        if (dsurf->IsLost() == DDERR_SURFACELOST)
            dsurf->Restore();

        dsurf->Blt(&am_drect, am_ddsurf, &am_srect, DDBLT_WAIT, NULL);
    }
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭�  Utility Routines  碓旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SpielbergAMStreamPlayer - set_source_rect
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
sberg_err_codes SpielbergAMStreamPlayer::set_source_rect(long x, long y,
                                                         long w, long h)
{
    if (!am_stream)
        return SBERG_ERR_UNINITIALIZED;

    am_srect.left = x;
    am_srect.right = am_srect.left + w;

    am_srect.top = y;
    am_srect.bottom = am_srect.top + h;

    return SBERG_ERR_NONE;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SpielbergAMStreamPlayer - set_dest_rect
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
sberg_err_codes SpielbergAMStreamPlayer::set_dest_rect(long x, long y,
                                                       long w, long h)
{
    if (!am_stream)
        return SBERG_ERR_UNINITIALIZED;

    am_drect.left = x;
    am_drect.right = am_drect.left + w;

    am_drect.top = y;
    am_drect.bottom = am_drect.top + h;

    return SBERG_ERR_NONE;
}

//葦� End of module - sbrgamsp.cpp 憶�


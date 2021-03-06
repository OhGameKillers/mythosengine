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
// sbrgam.hpp
//
// Microsoft ActiveMovie(TM) Spielberg class implementations
//
// SpielbergAMPlayer - ActiveMovie(TM) player class
//
// SpielbergAMStreamPlayer - ActiveMovie(TM) Streaming Interface player class
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

#ifndef __SBRGAM_HPP
#define __SBRGAM_HPP    1

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳� DirectX headers
#include <ddraw.h>

//陳� ActiveMovie headers
#include <vfwmsgs.h>
#include <objbase.h>
#include <strmif.h>
#include <control.h>
#include <evcode.h>
#include <uuids.h>
#include <amvideo.h>
#include <mmstream.h>
#include <amstream.h>
#include <ddstream.h>

//陳� Spielberg headers
#include "sbrgdefs.h"
#include "sbrgbase.hpp"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Classes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SpielbergAMPlayer - ActiveMovie(TM) player implementation
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class SpielbergAMPlayer : public SpielbergPlayer
{
public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Public data members                                                  �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    HWND            parent;
    IGraphBuilder   *am_graph;
    HANDLE          am_event;

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    SpielbergAMPlayer(HWND _parent);
    virtual ~SpielbergAMPlayer();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    virtual sberg_err_codes open(const char *name, dword ctrlfl=0);
    virtual sberg_err_codes close();
    virtual sberg_err_codes play();
    virtual sberg_err_codes stop();
    virtual sberg_err_codes pause();
    virtual sberg_err_codes resume();
    virtual sberg_err_codes set_position(ulong ms);
    virtual ulong get_position() const;
    virtual sberg_err_codes get_info(SpielbergInfo *info) const;
    virtual dword get_flags();
    virtual void display();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Utility functions.                                                   �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

    //陳� Control render window
    sberg_err_codes get_window_styles(long *style, long *styleex);
    sberg_err_codes set_window_styles(long style, long styleex);

    sberg_err_codes get_window_pos(long *x, long *y);
    sberg_err_codes set_window_pos(long x, long y);

    //陳� Setup playback rectangles
    sberg_err_codes set_source_rect(long x, long y, long w, long h);
    sberg_err_codes set_dest_rect(long x, long y, long w, long h);
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// SpielbergAMStreamPLayer - ActiveMovie(TM) stream player implementation
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class SpielbergAMStreamPlayer : public SpielbergPlayer
{
public:
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Public data members                                                  �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    LPDIRECTDRAW            ddraw;          // DirectDraw instance
    LPDIRECTDRAWSURFACE     dsurf;          // DirectDraw target surface
    IAMMultiMediaStream     *am_stream;     // Stream instance
    IMediaStream            *am_vidstream;
    IDirectDrawMediaStream  *am_ddstream;
    IDirectDrawStreamSample *am_ddsample;
    LPDIRECTDRAWSURFACE     am_ddsurf;      // AM update surface
    RECT                    am_srect;       // Source rectangle
    RECT                    am_drect;       // Destination rectangle
    ushort                  am_swidth;      // Source size
    ushort                  am_sheight;
    HANDLE                  am_event;       // EOS handle

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Constructor/Destructors                                              �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    SpielbergAMStreamPlayer(LPDIRECTDRAW _ddraw, LPDIRECTDRAWSURFACE dsurf);
    virtual ~SpielbergAMStreamPlayer();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Operations                                                           �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    virtual sberg_err_codes open(const char *name, dword ctrlfl=0);
    virtual sberg_err_codes close();
    virtual sberg_err_codes play();
    virtual sberg_err_codes stop();
    virtual sberg_err_codes pause();
    virtual sberg_err_codes resume();
    virtual sberg_err_codes set_position(ulong ms);
    virtual ulong get_position() const;
    virtual sberg_err_codes get_info(SpielbergInfo *info) const;
    virtual dword get_flags();
    virtual void display();

    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
    // Utility functions.                                                   �
    //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

    //陳� Setup playback rectangles
    sberg_err_codes set_source_rect(long x, long y, long w, long h);
    sberg_err_codes set_dest_rect(long x, long y, long w, long h);
};

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//葦� End of header - sbrgam.hpp 憶�


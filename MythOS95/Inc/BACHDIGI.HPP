//���������������������������������������������������������������������������
//
//                        ����������                       ����
//     ��Ŀ                ���     ���                     ����
//     �  �       ��Ŀ     ���     ���   ����      �����    ��� ���
//     �  � ��Ŀ  �  �     �����������  �  ���    ���   ��  ��������
//     �  � �  �  �  �     ���     ���  �������  ���        ���   ���
//    O� O� �  �  �  �     ���     ��� ���  ���  ���    ��  ���   ���
//          �  � O� O�    �����������   ��������  �������  ����� �����
//         O� O�
//                            C++ Music, Sound, and Effects Library
//                                Microsoft Windows '95 Version
//
//           Copyright (c) 1995-1997 by Charybdis Enterprises, Inc.
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
// Created by Dan Higdon & Chuck Walbourn
//
// bachdigi.hpp
//
// Contains the Digital object hierarchy.
//
//���������������������������������������������������������������������������

#ifndef __BACHDIGI_HPP
#define __BACHDIGI_HPP    1

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//���������������������������������������������������������������������������
//
//                                Includes
//
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// Sound System Library Includes                                            �
//���������������������������������������������������������������������������

//��� Standard headers
#include <windows.h>
#include <mmsystem.h>
#include <dsound.h>

//��� Charybdis headers
#include <debug.h>
#include <portable.h>
#include <ivory.hpp>
#include <xfile.hpp>

//�������������������������������������������������������������������������Ŀ
// Bach Library Includes                                                    �
//���������������������������������������������������������������������������
#include "bachdefs.hpp"

//���������������������������������������������������������������������������
//
//                                Classes
//
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// BachSample - Container object for digital sample                         �
//���������������������������������������������������������������������������
class BachSample
{
    IDirectSound        *dSound;            // The DirectSound instance we will play on
    IDirectSoundBuffer  *pdsb;              // The DirectSound buffer
    IvoryHandle         dsbHandle;          // "Off-Card" storage for restoring buffers

    //��� Internal buffer maintainance
    HRESULT restore ();                     // Restore a lost DSound buffer

public:
    dword               flags;              // Sample status flags
    ulong               length;             // Sample length
    bach_digi_fmt       fmt;                // Sample format
    ulong               rate;               // Sample rate
    void                *ptr;               // non-zero if locked

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructor                                               �
    //�����������������������������������������������������������������������
    BachSample (const class BachDigital &);
    virtual ~BachSample();

    //���������������������������������������������������������������������Ŀ
    // Copy Constructor/Assignment                                          �
    //�����������������������������������������������������������������������
    BachSample (BachSample const &b);
    BachSample &operator = (BachSample const &);

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������

    //��� Lock/unlock ptr for use.
    virtual bach_err_codes lock ();
    virtual void unlock ();

    //��� Free all sample memory
    virtual void release ();

    //��� Loads the sample from disk.
    virtual bach_err_codes load (const char *fname);
    virtual bach_err_codes load (XFParseIFF *iff);

    //��� Play controls
    virtual bach_err_codes play (BOOL loop = 0);
    virtual bach_err_codes stop (BOOL rewind = TRUE);
    virtual bach_err_codes set_volume   (long);
    virtual long           get_volume   ();
    virtual bach_err_codes set_pan      (long);
    virtual long           get_pan      ();
    virtual bach_err_codes set_playrate (ulong);
    virtual dword          get_flags    ();

    dword   get_playtime () const;
};


#if 0
//�������������������������������������������������������������������������Ŀ
// BachSample - Container object for digital sample                         �
//���������������������������������������������������������������������������
class BachStreamSample: public BachSample
{
    XFile   *xf;
    ulong   buf_len;

public:
    BachStreamSample (const class BachDigital &, int buf_len = 4096);

    //��� Free all sample memory
    virtual void release ();

    //��� Loads the sample from disk.
    virtual bach_err_codes load (XFParseIFF *iff);

    //��� Play controls
    virtual bach_err_codes play (BOOL loop = 0);
    virtual bach_err_codes stop ();
};
#endif


//�������������������������������������������������������������������������Ŀ
// BachDigitalInterface - Abstract base class for digital I/O               �
//���������������������������������������������������������������������������
class BachDigitalInterface
{
protected:
    bach_err_codes      errorn;

public:
    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructor                                               �
    //�����������������������������������������������������������������������
    BachDigitalInterface() { errorn=BACH_ERR_NONE; };
    virtual ~BachDigitalInterface() {};

    //���������������������������������������������������������������������Ŀ
    // Operations for digital i/o                                           �
    //�����������������������������������������������������������������������
    bach_err_codes  error() { return errorn; }

    //�� Hardware init
    virtual bach_err_codes init (HWND, DWORD)=0;
    virtual void close ()=0;

    //�� Sample playback
    virtual byte setup(BachSample *s, byte chan=(byte)-1)=0;
    virtual void release(byte chan)=0;

    virtual void play(byte chan, ulong loop=1)=0;
    virtual void stop(byte chan)=0;
    virtual void pause(byte chan)=0;
    virtual void resume(byte chan)=0;

    virtual dword status(byte chan=(byte)-1)=0;

    //�� Sample volume/panning control
    virtual byte set_volume(byte chan, byte vol)=0;
    virtual byte get_volume(byte chan)=0;

    virtual byte set_pan(byte chan, byte pan)=0;
    virtual byte get_pan(byte chan)=0;
};


//�������������������������������������������������������������������������Ŀ
// BachDigital - Digital output object.                                     �
//���������������������������������������������������������������������������
class BachDigital : public BachDigitalInterface
{
    //���������������������������������������������������������������������Ŀ
    // Copy Constructor/Assignment                                          �
    //�����������������������������������������������������������������������
    // Private so they can't be used.
    BachDigital (BachDigital const &);
    BachDigital &operator= (BachDigital const &);

protected:
    dword                   driverRate;
    IDirectSound            *dSound;
    IDirectSoundBuffer      *dsPrimary;
    BachSample              *smpPtr[BACH_DIGI_CHANNELS];

    friend class BachSample;

public:
    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructor                                               �
    //�����������������������������������������������������������������������
    BachDigital(dword drate=BACH_DIGI_DRIVERRATE);
    virtual ~BachDigital();

    //���������������������������������������������������������������������Ŀ
    // Operations for digital i/o                                           �
    //�����������������������������������������������������������������������
    //�� Hardware init
    virtual bach_err_codes init (HWND, DWORD = DSSCL_PRIORITY);
    virtual void close ();

    //�� Sample playback
    virtual byte setup(BachSample *s, byte chan=(byte)-1);
    virtual void release(byte chan);

    virtual void play(byte chan, ulong loop=1);
    virtual void stop(byte chan);
    virtual void pause(byte chan);
    virtual void resume(byte chan);

    virtual dword status(byte chan=(byte)-1);

    //�� Sample volume/panning control
    virtual byte set_volume(byte chan, byte vol);
    virtual byte get_volume(byte chan);

    virtual byte set_pan(byte chan, byte pan);
    virtual byte get_pan(byte chan);
};

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//��� End of header - bachdigi.hpp ���

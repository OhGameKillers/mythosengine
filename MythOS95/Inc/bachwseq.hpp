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
// bachwseq.hpp
//
// Contains the Wave Sequencer
//
//���������������������������������������������������������������������������

#ifndef __BACHWSEQ_HPP
#define __BACHWSEQ_HPP    1

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

//�������������������������������������������������������������������������Ŀ
// Bach Library Includes                                                    �
//���������������������������������������������������������������������������
#include "bachdefs.hpp"
#include "bachdigi.hpp"

//���������������������������������������������������������������������������
//
//                                Classes
//
//���������������������������������������������������������������������������


//�������������������������������������������������������������������������Ŀ
// BachWaveSequencer - plays a series of waves in order.                    �
//���������������������������������������������������������������������������
class BachWaveSequencer
{
    // For storing the samples to sequence
    struct Link
    {
        BachSample  *const sample;
        Link        *next;

        Link (BachSample *_sample, Link *_next = 0):
            sample (_sample), next (_next) { }
    };

    HANDLE              thread_handle;
    DWORD               thread_id;
    CRITICAL_SECTION    critical_section;

    Link                *sequence;
    UINT                hTimer;

    void                arm_timer ();
    static DWORD CALLBACK thread_proc (LPVOID);

    virtual Link        *_next ();

    // We cannot allow copying because of the critical section
    BachWaveSequencer (BachWaveSequencer const &);
    BachWaveSequencer &operator= (BachWaveSequencer const &);

public:
    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructor                                               �
    //�����������������������������������������������������������������������
    BachWaveSequencer ();
    virtual ~BachWaveSequencer ();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    virtual Link *next ();

    //��� Sample management
    virtual bach_err_codes add (BachSample *const);
    virtual void clear (BOOL stop_current = TRUE);

    //��� Information about the sequence
    virtual BachSample *const playing ();
    virtual ulong latency ();

    //��� Play controls
    virtual bach_err_codes play();
    virtual bach_err_codes stop();
};


#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//��� End of header - bachwseq.hpp ���

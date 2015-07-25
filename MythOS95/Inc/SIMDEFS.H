//���������������������������������������������������������������������������
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
//���������������������������������������������������������������������������
//
//                     A Simluator Framework for MythOS(tm)
//
//                        Microsoft Windows '95 Version
//
//               Copyright (c) 1997 by Charybdis Enterprises, Inc.
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
// MythOS is a trademark of Charybdis Enterprises, Inc.
//
//���������������������������������������������������������������������������
//
// simdefs.hpp
//
// SimGine framework defines
//
//���������������������������������������������������������������������������

#ifndef __SIMDEFS_H
#define __SIMDEFS_H     1

//���������������������������������������������������������������������������
//
//                                Equates
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
// Application Settings
//���������������������������������������������������������������������������

#define SIM_DEFAULT_WIDTH               640
#define SIM_DEFAULT_HEIGHT              480
#define SIM_DEFAULT_BITDEPTH            15

#define SIM_MYTHOS_MEM_SIZE             (8*1024*1024)
#define SIM_MYTHOS_TASK_STACK_SIZE      (128*1024)
#define SIM_MYTHOS_ESCHER_ARENA_SIZE    (384*1024)


//���������������������������������������������������������������������������
// Model Settings
//���������������������������������������������������������������������������

//��� Teams
#define SIM_MAX_TEAMS                   5

#define SIM_TEAM_GRAY                   0
#define SIM_TEAM_BLUE                   1
#define SIM_TEAM_RED                    2
#define SIM_TEAM_GOLD                   3
#define SIM_TEAM_GREEN                  4

//��� Dynamic array starting sizes
#define SIM_INIT_OBJECTS                256
#define SIM_INIT_TEMPS                  128
#define SIM_INIT_UNITS                  64
#define SIM_INIT_OFFIELDS               4


//���������������������������������������������������������������������������
// Resource entries
//���������������������������������������������������������������������������

#define IDS_SIM_APPNAME         1
#define IDS_SIM_NOMEMORY        10

#define IDC_SIM_ARROW           200

#define IDI_SIM_APPICON         300

#endif

//��� End of header - simdefs.h ���

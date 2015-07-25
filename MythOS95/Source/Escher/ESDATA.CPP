//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//�����������Copyright�(c)�1994-1997�by�Charybdis�Enterprises,�Inc.����������
//��������������������������All�Rights�Reserved.�����������������������������
//���������������������������������������������������������������������������
//��������������������� Microsoft Windows '95 Version �����������������������
//���������������������������������������������������������������������������
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
// Created by Tim Little & Chuck Walbourn
//
// esdata.cpp
//
// Escher global data definitions are localized to this file.
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//                                
//���������������������������������������������������������������������������

#include "escher.hpp"

//���������������������������������������������������������������������������
//
//                                 Data
//
//���������������������������������������������������������������������������

#ifdef __WATCOMC__
#pragma off(unreferenced);
#endif

//�������������������������������������������������������������������������Ŀ
// Identification string for the library.                                   �
//���������������������������������������������������������������������������
static char id[] =
"Escher -  A component of the MythOS collection\n"
"Copyright (C) 1994-1996 by Charybdis Enterprises, Inc. All Rights Reserved.\n"
"MythOS is a trademark of Charybdis Enterprises, Inc.\n";


//�������������������������������������������������������������������������Ŀ
// Main escher system library pointer.                                      �
//���������������������������������������������������������������������������
EschSystem  *EschSysInstance=0;


//�������������������������������������������������������������������������Ŀ
// Currently active active context used by all other objects.               �
//���������������������������������������������������������������������������
EschContext *EschCurrent=0;


//�������������������������������������������������������������������������Ŀ
// Empty name for objects with name char pointers.                          �
//���������������������������������������������������������������������������
char EschNoName[] = "NoName";


//�������������������������������������������������������������������������Ŀ
// Workspace for a single point.                                            �
//���������������������������������������������������������������������������
EschPoint EschTempPoint;
VngoPoint EschTempVPoint;

//��� End of module - esdata.cpp ���

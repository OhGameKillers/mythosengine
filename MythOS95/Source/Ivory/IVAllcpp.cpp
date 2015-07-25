//���������������������������������������������������������������������������
//
//                     Ivory -- A Memory Management Library
//
//                          Microsoft Windows '95 Version
//
//            Copyright (c) 1994-1997 by Charybdis Enterprises, Inc.
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
// Created by Dan Higdon
//
// ivallcpp.cpp
//
// Ivory Allocation - Primary allocation routines for C++.
//
//      These routines provide a simple operator replacement for the
//  C++ memory allocation routines.  These routines call the standard
//  memory allocation routines found in IVALLOC.C
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//
//���������������������������������������������������������������������������

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <malloc.h>

#include <iostream.h>
#include <assert.h>

#include "ivory.hpp"

//���������������������������������������������������������������������������
//
//                                 Data
//
//���������������������������������������������������������������������������

extern "C" void *main_memory;

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//  These are versions of the C++ new and delete operators, wired to
//  use the ivory routines when ivory has been initialized.
//
//���������������������������������������������������������������������������

#if 1
void *operator new (size_t size)
{
    assertMyth("Ivory operator new needs valid size", size > 0);
    if (main_memory)
        return ivory_alloc (size);
    else
        return malloc (size);
}

void operator delete (void *ptr)
{
    assertMyth("Ivory operator delete needs valid pointer", ptr != 0);
    if (main_memory)
        ivory_free (&ptr);
    else
        free (ptr);
}
#endif

//��� End of module - ivallcpp.cpp ���

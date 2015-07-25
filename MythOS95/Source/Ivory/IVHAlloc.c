//���������������������������������������������������������������������������
//
//                     Ivory -- A Memory Management Library
//
//                          Microsoft Windows '95 Version
//
//            Copyright (c) 1994, 1995 by Charybdis Enterprises, Inc.
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
// Ivory Handle Allocation - Relocatable block allocation.
//
//  This is the second handle allocation attempt.  In this one,
//  I use DPMI calls to effect the locking and memory swapping.
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//                                
//���������������������������������������������������������������������������

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <assert.h>

#include "ivory.h"


//���������������������������������������������������������������������������
//
//                                Equates
//
//���������������������������������������������������������������������������


//���������������������������������������������������������������������������
//
//                               Structures
//
//���������������������������������������������������������������������������

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef __WATCOMC__
#pragma pack();
#endif


//���������������������������������������������������������������������������
//
//                               Routines
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                 Data
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������


//���������������������������������������������������������������������������
// Handle allocation routines.
//    For now, the memory is actually allocated with the standard routines.
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//  ivory_halloc
//      Allocate a block out of handle memory.
//���������������������������������������������������������������������������
IvoryHandle ivory_halloc (size_t size)
{
    assert (size > 0);

    return (IvoryHandle)GlobalAlloc (GMEM_MOVEABLE, size);
}


//���������������������������������������������������������������������������
//  ivory_zhalloc
//      Allocate and zero a block from handle memory.
//���������������������������������������������������������������������������
IvoryHandle ivory_zhalloc (size_t size)
{
    assert (size > 0);

    return (IvoryHandle)GlobalAlloc (GHND, size);
}


//���������������������������������������������������������������������������
//  ivory_hfree
//      Return a block to handle memory.
//���������������������������������������������������������������������������
void ivory_hfree (IvoryHandle *ptr)
{
    assert (ptr);

    GlobalFree ((HANDLE)*ptr);

    // Zero out the handle
    *ptr = 0;
}


//���������������������������������������������������������������������������
//  ivory_hlock
//      Lock a block of memory, returning a handle to it.
//���������������������������������������������������������������������������
void *ivory_hlock (IvoryHandle h)
{
    assert (h != 0);

    return GlobalLock ((HANDLE)h);
}


//���������������������������������������������������������������������������
//  ivory_hunlock
//      Unock a block of memory.
//���������������������������������������������������������������������������
void ivory_hunlock (IvoryHandle h)
{
    assert (h != 0);

    GlobalUnlock ((HANDLE)h);
}


//��� End of module - ivalloc.cpp ���

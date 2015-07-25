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
// Ivory Allocation - Primary allocation routines.
//
//    This is an MFC-friendly version of the IvoryAllocation routines.
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//                                
//���������������������������������������������������������������������������

#include <malloc.h>
#include <assert.h>

#include "ivory.h"

//���������������������������������������������������������������������������
//
//                                Pragmas
//
//���������������������������������������������������������������������������

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

//���������������������������������������������������������������������������
//
//                           External Routines
//
//���������������������������������������������������������������������������


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

//��������������������������������������������������������������������������
//  ivory_initialize
//      Initialize the global memory arena.  Must be called first.
//��������������������������������������������������������������������������
void ivory_initialize (size_t mem_size, ivory_init_codes opt)
{
    // This function does nothing in this implementation;
    (void)mem_size;
    (void)opt;
}

//��������������������������������������������������������������������������
//  ivory_terminate
//      Free all ivory-allocated resources and shut down the library.
//��������������������������������������������������������������������������
void ivory_terminate ()
{
    // This function does nothing in this implementation;
}


//��������������������������������������������������������������������������
//  ivory_alloc
//      Allocate a block out of main memory.
//��������������������������������������������������������������������������
void *ivory_alloc (size_t size)
{
    return malloc (size);
}


//��������������������������������������������������������������������������
//  ivory_zalloc
//      Allocate and zero a block from standard memory.
//��������������������������������������������������������������������������
void *ivory_zalloc (size_t size)
{
    void *ptr = ivory_alloc (size);
    memset (ptr, 0, size);
    return ptr;
}


//��������������������������������������������������������������������������
//  ivory_free
//��������������������������������������������������������������������������
void ivory_free (void **ptr)
{
	assert (ptr && *ptr);

    free (*ptr);
    *ptr = 0;
}

//��� End of module - ivmfc.cpp ���

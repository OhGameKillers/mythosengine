//���������������������������������������������������������������������������
//                            
//           ^           **   **   **** ***** *    ****     ^      Take me to
//          (_)            * *     *      *   *    *       (_)    / your
//     ^                    *      **     *   *    **            ^  leader...
//    (_)       ^          * *     *      *   *    *            (_)
//             (_)       **   **   *    ***** **** ****
//
//            Copyright (c) 1994-1997 by Charybdis Enterprises, Inc.
//                              All Rights Reserved.
//                        Microsoft Windows '95 Version
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
// Created by Chuck Walbourn
// Ported to Windows by Dan Higdon
//
// xfiopath.c
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//                                
//���������������������������������������������������������������������������

#include "xfio.h"

//���������������������������������������������������������������������������
//
//                               Routines
//
//���������������������������������������������������������������������������

void _makepath(char *, const char *, const char *, const char *, const char *);
void _splitpath(const char *, char *, char *, char *, char *);

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// xf_makepath                                                              �
//                                                                          �
// Make a full path from the components of the name.                        �
//���������������������������������������������������������������������������
char *xf_makepath(char *path, const char *drive, const char *dir, const char *fname, const char *ext)
{
    _makepath(path,drive,dir,fname,ext);
    return path;
}


//�������������������������������������������������������������������������Ŀ
// xf_splitpath                                                             �
//                                                                          �
// Break up a full path into the components.                                �
//���������������������������������������������������������������������������
void xf_splitpath(const char *path, char *drive, char *dir, char *fname, char *ext)
{
    _splitpath(path,drive,dir,fname,ext);
}

//��� End of module - xfiopath.c ���


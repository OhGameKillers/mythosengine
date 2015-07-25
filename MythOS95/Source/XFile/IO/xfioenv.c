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
// xfioenv.c
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

char *getenv(const char *varname);
void _searchenv(const char *, const char *, char *);

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// char *xf_getenv(const char *varname);                                    �
//                                                                          �
// Returns a pointer to the environment string for the variable name.       �
//���������������������������������������������������������������������������
char *xf_getenv(const char *varname)
{
    return getenv(varname);
}


//�������������������������������������������������������������������������Ŀ
// xf_searchenv                                                             �
//                                                                          �
// Searchings the directories given in environment variable and the current �
// working directory for the file.                                          �
//���������������������������������������������������������������������������
char *xf_searchenv(const char *filename, const char *env_var, char *path)
{
    _searchenv(filename,env_var,path);
    return path;
}

//��� End of module - xfioenv.c ���


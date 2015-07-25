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
// esscene.hpp
//
// An EschScene class instance is used to manage a collection of lights,
// cameras, and mesh objects within a single object.  Scenes can
// be loaded from files and their data can be used to for
// standard Escher display.
//
//���������������������������������������������������������������������������

#ifndef __ESSCENE_HPP
#define __ESSCENE_HPP    1

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//���������������������������������������������������������������������������
//             
//                                Includes
//                                
//���������������������������������������������������������������������������

#include <portable.h>
#include <xfile.hpp>

#include "esgeom.hpp"

//���������������������������������������������������������������������������
//
//                                Classes
//
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// EschScene - 3D Scene collection object.                                  �
//���������������������������������������������������������������������������
class EschScene {

public:
    //���������������������������������������������������������������������Ŀ
    // Public data members                                                  �
    //�����������������������������������������������������������������������
    dword           flags;
    char            name[ESCH_MAX_NAME];
    ulong           ncameras;
    EschCamera      *cameras;
    ulong           nlights;
    EschLight       *lights;
    ulong           nmeshes;
    EschMeshDraw    *meshes;

    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    EschScene();
    EschScene(const char *fname, const char *sname=0,
              VngoPal *pal=0, dword flgs=ESCH_SCENELD_ALL);
    EschScene(const EschScene &s);

    virtual ~EschScene();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    const EschScene &operator = (const EschScene &s);

    virtual void release();

    //���������������������������������������������������������������������Ŀ
    // Utility functions.                                                   �
    //�����������������������������������������������������������������������
    void set_flags(const dword f) { flags = f; }

    //���������������������������������������������������������������������Ŀ
    // I/O Routines.                                                        �
    //�����������������������������������������������������������������������
    virtual esch_error_codes load(const char *fname, const char *sname=0,
                                  VngoPal *pal=0, dword flgs=ESCH_SCENELD_ALL);
    virtual esch_error_codes load(XFParseIFF *iff, const char *sname=0,
                                  VngoPal *pal=0, dword flgs=ESCH_SCENELD_ALL);
};

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//��� End of header - esscene.hpp ���

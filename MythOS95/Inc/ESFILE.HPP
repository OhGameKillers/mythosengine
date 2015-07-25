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
// esfile.hpp
//
//      Contains the file structures for the Escher 3D library.
//
//���������������������������������������������������������������������������

#ifndef __ESFILE_HPP
#define __ESFILE_HPP    1

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
#include <felix.hpp>

#include "esdefs.h"

//���������������������������������������������������������������������������
//
//                               Structures
//
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// Cameras                                                                  �
//���������������������������������������������������������������������������

//��� 'ECAM' - Camera data
struct EschFileCamera
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    Flx16   x;
    Flx16   y;
    Flx16   z;
    Flx16   diri;
    Flx16   dirj;
    Flx16   dirk;
    Flx16   topi;
    Flx16   topj;
    Flx16   topk;
    Flx16   fov;
    char    na[4];
};


//�������������������������������������������������������������������������Ŀ
// Lights                                                                   �
//���������������������������������������������������������������������������

//��� 'EAMB' - Ambient light source
struct EschFileLightAmbi
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    dword   color;
    char    na[8];
};

//��� 'EVEC' - Vector light source
struct EschFileLightVect
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    Flx16   i;
    Flx16   j;
    Flx16   k;
    dword   color;
    char    na[12];
};

//��� 'EFPT' - Fast point light source
//��� 'EPNT' - Point light source
struct EschFileLightPoint
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    Flx16   x;
    Flx16   y;
    Flx16   z;
    dword   color;
    char    na[12];
};

//��� 'EFAT' - Fast Attenuated point light source
//��� 'EATN' - Attenuated point light source
struct EschFileLightAtten
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    Flx16   x;
    Flx16   y;
    Flx16   z;
    dword   color;
    Flx16   inner;
    Flx16   outer;
    char    na[4];
};

//��� 'EFSP' - Spot light source
//��� 'ESPT' - Spot light source
struct EschFileLightSpot
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    Flx16   x;
    Flx16   y;
    Flx16   z;
    Flx16   i;
    Flx16   j;
    Flx16   k;
    dword   color;
    Flx16   inner;
    Flx16   outer;
    Flx16   hotspot;
    Flx16   falloff;
};


//�������������������������������������������������������������������������Ŀ
// FORM 'EMSH' - Mesh data IFF form.                                        �
//���������������������������������������������������������������������������

//��� 'HDR ' - Header
struct EschFileMeshHDR 
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    ulong   nverts;
    ulong   nfaces;
    ulong   nmtls;
    char    na[32];
};

//��� 'MTRX' - Matrix
// Contains a single EschMatrix structure.

//��� 'EXNT' - Extents
struct EschFileMeshEXNT
{
    Flx16   cenx;
    Flx16   ceny;
    Flx16   cenz;
    Flx16   extent_radius;
    Flx16   minx;
    Flx16   miny;
    Flx16   minz;
    Flx16   maxx;
    Flx16   maxy;
    Flx16   maxz;
    char    na[8];
};

//��� 'HIER' - Hierarchy
struct EschFileMeshHIER
{
    char    parent[ESCH_MAX_NAME];
};

//��� 'VERT' - Vertex
// Consists of an array of EschVertex structures

//��� 'FACE' - Face
// Consists of an array of EschFace structures

//��� 'MTL ' - Material description
struct EschFileMeshMTL
{
    char    name[ESCH_MAX_NAME];
};


//�������������������������������������������������������������������������Ŀ
// FORM 'EMTL', 'EMT1' - Material Data Form.                                �
//���������������������������������������������������������������������������

//��� 'HDR ' - Material Header
struct EschFileMtlMHDR
{
    char    name[ESCH_MAX_NAME];
    ushort  xsize;
    ushort  ysize;
    ushort  nframes;        // Always 1 for EMTL
    byte    type;
    byte    compress;
    dword   flags;
    char    na[4];
    char    pname[16];
};

#define ESCH_MTL_TYPE_8BIT          1
#define ESCH_MTL_TYPE_8BIT_TRANSP   2
#define ESCH_MTL_TYPE_24BIT         3
#define ESCH_MTL_TYPE_32BIT         4

#define ESCH_MTL_COMPRESS_NONE      0
#define ESCH_MTL_COMPRESS_RLE       1

//��� 'BODY' - Material Body
// Raw data for the bitmap (use type in header to decode)


//�������������������������������������������������������������������������Ŀ
// FORM 'ESEN' - Scene data IFF form.                                       �
//               This form will contain all FORMs within the scene and      �
//               heirachy information for connecting the objects.           �
//               The various loaders will search for named objects within   �
//               a ESEN form for their data.                                �
//���������������������������������������������������������������������������

//��� 'HDR ' - Header
struct EschFileSceneHDR
{
    char    name[ESCH_MAX_NAME];
    ulong   ncameras;
    ulong   nobjects;
    ulong   nmaterials;
    ulong   nvectorlights;
    ulong   npointlights;
    ushort  nfpointlights;
    ushort  nattenlights; 
    ushort  nfattenlights; 
    ushort  nspotlights; 
    ushort  nfspotlights; 
    char    na[18];
};


//�������������������������������������������������������������������������Ŀ
// FORM 'ETER' - Terrain Data Form.                                         �
//���������������������������������������������������������������������������

//��� 'HDR ' - Header
struct EschFileTerrHDR
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    ushort  width;                      // Width of the height field
    ushort  depth;                      // Depth of the height field
    ushort  surfratio;                  // Height:Surface points ratio
    byte    compression;                // Compression flag for data (0=none)
    byte    ntxts;                      // Number of textures
    Flx16   wscale;                     // World space per unit in width (obs)
    Flx16   dscale;                     // World space per unit in depth (obs)
    Flx16   hscale;                     // World space per unit in height
    Flx16   scale;                      // World space per unit in width & depth
    Flx16   origin_x;                   // Origin location
    Flx16   origin_y;
    Flx16   origin_z;
    char    na[56];
    char    palname[16];                // Van Gogh palette used to color
                                        // terrain data
};

//��� 'HGTS' - Height data
// 2D array of bytes width*height in size, one row at a time.

//��� 'SURF' - Surface data
// 2D array of dwords (width*height)/(surfratio*2) in size, one row at a time.

//��� 'NRML' - Normals data
// 2D array of EschVectors (width*height)/(surfratio*2) in size, one row at a time.

//��� 'COLR' - Texture color data 
// Byte array for texture colors.

//��� 'HCLR' - Height color bands
struct EschFileTerrHCLR
{
    ushort  blue;
    ushort  lblue;
    ushort  white;
    ushort  green;
    ushort  lgreen;
    ushort  yellow;
    ushort  lorange;
    ushort  orange;
    ushort  lbrown;
    ushort  brown;
    ushort  red;
    char    na[10];
};

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//��� End of header - esfile.hpp ���

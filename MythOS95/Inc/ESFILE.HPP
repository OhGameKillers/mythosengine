//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//���������������������������������������������������������������������������
//����������旭旭旭旭旭�旭旭旭旭���旭旭旭旭��旭姻���旭姻旭旭旭旭旭�旭旭旭旭姻�
//���������葦姻������葦姻���葦姻葦姻���葦姻葦姻���葦姻葦姻�������葦姻���葦姻�
//��������碓甥������碓甥�������碓甥�������碓甥���碓甥碓甥�������碓甥���碓甥��
//�������渦臼葦渦��渦臼葦渦臼�渦甥�������渦臼葦渦臼�渦臼葦渦���渦臼葦渦姻����
//������渦甥�������������渦甥渦甥�������渦甥���渦甥渦甥�������渦甥���渦甥����
//�����憶悔������憶悔���憶悔憶悔���憶悔憶悔���憶悔憶悔�������憶悔���憶悔�����
//����臆臆臆臆臆�臆臆臆臆���臆臆臆臆��臆悔���臆悔臆臆臆臆臆�臆悔���臆悔������
//���������������������������������������������������������������������������
//����������������� Microsoft Windows 95/98/NT Version ����������������������
//���������������������������������������������������������������������������
//���Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn���
//���������������������������������������������������������������������������
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
// This file and all associated files are subject to the terms of the
// GNU Lesser General Public License version 2 as published by the
// Free Software Foundation (http://www.gnu.org).   They remain the
// property of the authors: Dan Higdon, Tim Little, and Chuck Walbourn.
// See LICENSE.TXT in the distribution for a copy of this license.
//
// THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
// OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
// PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
// LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
// OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
//                        http://www.mythos-engine.org/
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//
// Created by Tim Little & Chuck Walbourn
//
// esfile.hpp
//
//      Contains the file structures for the Escher 3D library.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

#ifndef __ESFILE_HPP
#define __ESFILE_HPP    1

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <portable.h>
#include <felix.hpp>

#include "esdefs.h"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Structures
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// Cameras                                                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

//陳� 'ECA1' (floating-point)
struct EschFileCamera
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    float   x;
    float   y;
    float   z;
    float   diri;
    float   dirj;
    float   dirk;
    float   topi;
    float   topj;
    float   topk;
    float   fov;
    char    na[4];
};


//陳� 'ECAM' (16.16 fixed-point)
struct EschFileCameraV1
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    long    x;
    long    y;
    long    z;
    long    diri;
    long    dirj;
    long    dirk;
    long    topi;
    long    topj;
    long    topk;
    long    fov;
    char    na[4];
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// Lights                                                                   �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Ambient light source
//陳� 'EAMB'
struct EschFileLightAmbi
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    dword   color;
    char    na[8];
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Vector light source
//陳� 'EVE1' (floating-point)
struct EschFileLightVect
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    float   i;
    float   j;
    float   k;
    dword   color;
    char    na[12];
};

//陳� 'EVEC' (fixed-point)
struct EschFileLightVectV1
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    long    i;
    long    j;
    long    k;
    dword   color;
    char    na[12];
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Fast/normal point light source
//陳� 'EFP1' (floating-point)
//陳� 'EPN1' (floating-point)
struct EschFileLightPoint
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    float   x;
    float   y;
    float   z;
    dword   color;
    char    na[12];
};

//陳� 'EFPT' (fixed-point)
//陳� 'EPNT' (fixed-point)
struct EschFileLightPointV1
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    long    x;
    long    y;
    long    z;
    dword   color;
    char    na[12];
};

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Fast/normal attenuated point light source
//陳� 'EFA1' (floating-point)
//陳� 'EAT1' (floating-point)
struct EschFileLightAtten
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    float   x;
    float   y;
    float   z;
    dword   color;
    float   inner;
    float   outer;
    char    na[4];
};

//陳� 'EFAT' (fixed-point)
//陳� 'EATN' (fixed-point)
struct EschFileLightAttenV1
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    long    x;
    long    y;
    long    z;
    dword   color;
    long    inner;
    long    outer;
    char    na[4];
};

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Fast/normal spot light source
//陳� 'EFS1' (floating-point)
//陳� 'ESP1' (floating-point)
struct EschFileLightSpot
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    float   x;
    float   y;
    float   z;
    float   i;
    float   j;
    float   k;
    dword   color;
    float   inner;
    float   outer;
    float   hotspot;
    float   falloff;
};

//陳� 'EFSP' (fixed-point)
//陳� 'ESPT' (fixed-point)
struct EschFileLightSpotV1
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    long    x;
    long    y;
    long    z;
    long    i;
    long    j;
    long    k;
    dword   color;
    long    inner;
    long    outer;
    long    hotspot;
    long    falloff;
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// FORM 'EMSH' - Mesh data IFF form.                                        �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Header
//陳� 'HDR '
struct EschFileMeshHDR
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    ulong   nverts;
    ulong   nfaces;
    ulong   nmtls;
    char    na[32];
};

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Matrix
//陳� 'MTR1' (floating-point)
// Contains a single EschMatrix structure.

//陳� 'MTRX' (fixed-point)
struct EschMatrixV1
{
    long    mtx[3*4];
};

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Extents
//陳� 'EXN1' (floating-point)
struct EschFileMeshEXNT
{
    float   cenx;
    float   ceny;
    float   cenz;
    float   extent_radius;
    float   minx;
    float   miny;
    float   minz;
    float   maxx;
    float   maxy;
    float   maxz;
    char    na[8];
};

//陳� 'EXNT' (fixed-point)
struct EschFileMeshEXNTV1
{
    long    cenx;
    long    ceny;
    long    cenz;
    long    extent_radius;
    long    minx;
    long    miny;
    long    minz;
    long    maxx;
    long    maxy;
    long    maxz;
    char    na[8];
};

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Hierarchy
//陳� 'HIER'
struct EschFileMeshHIER
{
    char    parent[ESCH_MAX_NAME];
};

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Vertex
//陳� 'VER1' (floating-point)
// Consists of an array of EschVertex structures

//陳� 'VERT' (fixed-point)
struct EschVertexV1
{
    long        x;
    long        y;
    long        z;
    dword       na;
    struct
    {
        long    i;
        long    j;
        long    k;
        dword   na;
    }       normal;
};

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Face
//陳� 'FAC2' (floating-point w/ alpha)
// Consists of an array of EschFace structures

//陳� 'FAC1' (floating-point)
#define ESCH_FACEV2_SILLUM_MASK 0xf00000
#define ESCH_FACEV2_ALPHA_MASK 0xf000000
struct EschFaceV2
{
    dword           flags;
    word            a;
    word            b;
    word            c;
    word            txt;
    float           u[3];
    float           v[3];
    dword           color;
    struct
    {
        float       i;
        float       j;
        float       k;
        dword       na;
    }       normal;
};

//陳� 'FACE' (fixed-point)
#define ESCH_FACEV1_SILLUM_MASK 0xf00000
#define ESCH_FACEV1_ALPHA_MASK 0xf000000
struct EschFaceV1
{
    dword           flags;
    word            a;
    word            b;
    word            c;
    word            txt;
    long            u[3];
    long            v[3];
    dword           color;
    struct
    {
        long        i;
        long        j;
        long        k;
        dword       na;
    }       normal;
};

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Material description
//陳� 'MTL '
struct EschFileMeshMTL
{
    char    name[ESCH_MAX_NAME];
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// FORM 'EMTL', 'EMT1' - Material Data Form.                                �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Material Header
//陳� 'HDR '
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
#define ESCH_MTL_TYPE_15BIT         5
#define ESCH_MTL_TYPE_15BIT_TRANSP  6

#define ESCH_MTL_COMPRESS_NONE      0
#define ESCH_MTL_COMPRESS_RLE       1

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Material Body
//陳� 'BODY'
// Raw data for the bitmap (use type in header to decode)


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// FORM 'KEYF' - Keyframing data IFF form.                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Header
//陳� 'HDR '
struct EschFileKeyframeHeader
{
    char    m_type[M_TYPE_LEN];
    ulong   flags;
    long   key_depth;
    char    chain[M_TYPE_LEN];
};

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Keyframes
//陳� 'KEY1' (floating-point)
struct EschFileKeyframe
{
    ulong   k_type;
    int     frame_num;
    float   rotation[3];
};

//陳� 'KEY ' (fixed-point)
struct EschFileKeyframeV1
{
    ulong   k_type;
    int     frame_num;
    long    rotation[3];
};

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// FORM 'ETOK' - Escher Keyframe Token data IFF form.                       �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Header
//陳� 'HDR '
struct EschFileTokenHeader
{
    ulong   ver;
    ulong   count;
};

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Tokens
//陳� 'KTOK'
struct EschFileToken
{
    char    name[ESCH_MAX_NAME];
    ulong   type;
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// FORM 'ESEN' - Scene data IFF form.                                       �
//               This form will contain all FORMs within the scene and      �
//               heirachy information for connecting the objects.           �
//               The various loaders will search for named objects within   �
//               a ESEN form for their data.                                �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Header
//陳� 'HDR '
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


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// FORM 'ETER' - Terrain Data Form.                                         �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Header
//陳� 'HDR1' (floating-point)
struct EschFileTerrHDR
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    ushort  width;                      // Width of the height field
    ushort  depth;                      // Depth of the height field
    ushort  surfratio;                  // Height:Surface points ratio
    byte    compression;                // Compression flag for data (0=none)
    byte    ntxts;                      // Number of textures
    float   wscale;                     // World space per unit in width (obs)
    float   dscale;                     // World space per unit in depth (obs)
    float   hscale;                     // World space per unit in height
    float   scale;                      // World space per unit in width & depth
    float   origin_x;                   // Origin location
    float   origin_y;
    float   origin_z;
    char    na[56];
    char    palname[16];                // Van Gogh palette used to color
                                        // terrain data
};

//陳� 'HDR ' (fixed-point)
struct EschFileTerrHDRV1
{
    char    name[ESCH_MAX_NAME];
    dword   flags;
    ushort  width;                      // Width of the height field
    ushort  depth;                      // Depth of the height field
    ushort  surfratio;                  // Height:Surface points ratio
    byte    compression;                // Compression flag for data (0=none)
    byte    ntxts;                      // Number of textures
    long    wscale;                     // World space per unit in width (obs)
    long    dscale;                     // World space per unit in depth (obs)
    long    hscale;                     // World space per unit in height
    long    scale;                      // World space per unit in width & depth
    long    origin_x;                   // Origin location
    long    origin_y;
    long    origin_z;
    char    na[56];
    char    palname[16];                // Van Gogh palette used to color
                                        // terrain data
};

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Height data
//陳� 'HGTS'
// 2D array of bytes width*height in size, one row at a time.

//陳� 256 entry array of height index to elevation mappings
//陳� 'HTB1' (floating-point)
//陳� 'HTBL' (fixed-point)

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Surface data
//陳� 'SURF'
// 2D array of dwords (width*height)/(surfratio*2) in size, one row at a time.

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Material description
//陳� 'MTL '
struct EschFileTerrMTL
{
    char    name[ESCH_MAX_NAME];
};

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Normals data
//陳� 'NRM2' (floating-point)
// 2D array of EschVectors (width*height)/(surfratio*2) in size, one row at a time.

//陳� 'NRM1' (compressed fixed-point)
// 2D array of ushorts 4*(width*height)/(surfratio*2) in size, one row at a time
// where each 4 ushort set lower 16-bits of a 16.16 number for i,j,k and
// the 1 and sign bits encoded into the 4th ushort.

//陳� 'NRML' (fixed-point)
// 2D array of EschVectorV1s (width*height)/(surfratio*2) in size, one row at a time.
struct EschVectorV1
{
    long        i;
    long        j;
    long        k;
    dword       na;
};

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Texture color data
//陳� 'COLR'
// Byte array for texture colors.

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳 Height color bands
//陳� 'HCLR'
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

//葦� End of header - esfile.hpp 憶�


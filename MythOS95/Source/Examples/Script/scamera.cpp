//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//
//                                /\    /\
//                               /  \  /  \
//                              /    \/    \
//                             /  /\    /\  \
//                            /  /  \  /  Y T H O S
//                           /  /    \/    \  \
//                          /  /            \  \
//                         /__/              \__\
//
//                  Microsoft Windows 95/98/NT Version
//
//  Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
//
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
//                               3D SCRIPT EXAMPLE
//
// Created by Chuck Walbourn
//
// scamera.cpp
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>

#include <mythos.hpp>

#include "scrtok.h"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Routines
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

extern long integer(void);
extern long expr(void);

extern double real(void);
extern double rexpr(void);

extern void match(int tok);
extern "C" void error(const char *str);
extern "C" void warning(const char *str);

//陳 Local
STATIC void camera_body(EschCameraEx *cam);

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//陳 External from scanner.
extern "C" int              YY_esc_allowed;
extern "C" char             *yytext;
extern "C" int              yyleng;

//陳 Global data
extern VngoVport            *Vport;
extern VngoPal              *Palette;
extern EschCamera           *CurCamera;
extern EschCameraEx         *Cameras;

extern int                  CurrentToken;

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// create_camera
//
//         create_camera :- camera '=' <name> [ file=<file> ] '{' <body> '}'
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void create_camera()
{
    EschCameraEx    *cam=0;
    char            name[ESCH_MAX_NAME];
    char            fname[256];

    *fname = 0;

    match(YY_CAMERA);
    match(YY_EQUAL);

//陳� Get name
    if (CurrentToken != YY_STRING)
        error("create camera needs name");

    //陳� Check to see if name already defined
    if (Cameras)
    {
        cam = (EschCameraEx*)Cameras->find(yytext);
        if (cam)
            warning("Duplicate camera name, camera already exists");
    }

    strncpy(name,yytext,sizeof(name));
    match(YY_STRING);

//陳� Handle attributes
    while (CurrentToken != YY_LBRACE)
    {
        switch (CurrentToken)
        {
            case YY_FILE:
                match(YY_FILE);

                YY_esc_allowed=0;
                match(YY_EQUAL);
                YY_esc_allowed=1;

                if (CurrentToken != YY_STRING
                    || !xf_exist(yytext))
                    error("file needs valid filename");
                strncpy(fname,yytext,sizeof(fname));

                match(YY_STRING);
                break;

            default:
                error("Expected optional file attribute or '{'");
        }
    }

    match(YY_LBRACE);

//陳� Handle load or create
    if (!cam)
    {
        cam = new EschCameraEx;
        if (!cam)
            error("Out of memory");
        strncpy(cam->name,name,ESCH_MAX_NAME);

        if (*fname)
        {
            if (cam->load(fname,name) != ESCH_ERR_NONE)
            {
                char buff[512];
                sprintf(buff,"Failed to load camera '%s'\nfrom '%s'",
                             name,fname);
                error(buff);
            }
        }

        cam->attach(Vport);
        cam->set_flags(cam->flags
                       | ESCH_CAM_SHADE_SMOOTH
                       | ESCH_CAM_SHADE_FLAT
                       | ESCH_CAM_SHADE_SOLID
                       | ESCH_CAM_SHADE_WIRE
                       | ESCH_CAM_BACKCULL
                       | ESCH_CAM_MODELSPACE
                       | ESCH_CAM_PERSPECTIVE
                       | ESCH_CAM_TEXTURED
                       | ESCH_CAM_ALPHA
                       );

        if (!CurCamera)
            CurCamera = cam;

        if (!Cameras)
            Cameras = cam;
        else
            cam->sibling(Cameras);
    }

//陳� Process body
    while (CurrentToken != YY_RBRACE)
        camera_body(cam);

    match(YY_RBRACE);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// modify_camera
//
//         modify_camera :- camera '=' <name> '{' <body> '}'
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void modify_camera()
{
    match(YY_CAMERA);
    match(YY_EQUAL);

//陳� Get name
    if (CurrentToken != YY_STRING)
        error("modify camera needs name");

    //陳� Check to see if name already defined
    if (!Cameras)
        error("No cameras defined");

    EschCameraEx *cam = (EschCameraEx*)Cameras->find(yytext);
    if (!cam)
        error("Modify camera needs defined camera name");

    match(YY_STRING);
    match(YY_LBRACE);

//陳� Process body
    while (CurrentToken != YY_RBRACE)
        camera_body(cam);

    match(YY_RBRACE);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// camera_body
//
//         camera_body :- shade={wire | flat | solid | smooth | specular};
//                        | bfculling={on | off | yes | no};
//                        | textured={on | off | yes | no};
//                        | perspective={on | off | yes | no};
//                        | alpha={on | off | yes | no};
//                        | show_all_lines={on | off | yes | no};
//                        | position=<float>,<float>,<float>;
//                        | top=<float>,<float>,<float>;
//                        | direction=<float>,<float>,<float>;
//                        | lookat=<float>,<float>,<float>;
//                        | factor=<float>;
//                        | fov=<float>;
//                        | hither=<float>;
//                        | yon=<float>;
//                        | aspect_ratio=<float>;
//                        | bcolor=<integer>,<integer>,<integer>;
//                        | bitmap=<file>;
//                        | haze={<float>,<float> | on | off | yes | no};
//                        | rotatex=<float>;
//                        | rotatey=<float>;
//                        | rotatez=<float>;
//                        | yaw=<float>;
//                        | pitch=<float>;
//                        | roll=<float>;
//                        | translate=<float>,<float>,<float>;
//                        | move=<float>,<float>,<float>;
//                        | <empty>
//
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
STATIC void camera_body(EschCameraEx *cam)
{
    assert(cam != 0);

    switch (CurrentToken)
    {
        case YY_RBRACE:
            break;

        //陳陳� shade={wire | flat | solid | smooth | specular};
        case YY_SHADE:
            {
                match(YY_SHADE);
                match(YY_EQUAL);

                dword flags = cam->flags;

                switch (CurrentToken)
                {
                    case YY_WIRE:
                        match(YY_WIRE);
                        flags &= ~(ESCH_CAM_SHADE_SOLID
                                   | ESCH_CAM_SHADE_FLAT
                                   | ESCH_CAM_SHADE_SMOOTH
                                   | ESCH_CAM_SHADE_SPECULAR);
                        flags |= ESCH_CAM_SHADE_WIRE;
                        break;
                    case YY_SOLID:
                        match(YY_SOLID);
                        flags &= ~(ESCH_CAM_SHADE_FLAT
                                   | ESCH_CAM_SHADE_SMOOTH
                                   | ESCH_CAM_SHADE_SPECULAR);
                        flags |= ESCH_CAM_SHADE_WIRE
                                 | ESCH_CAM_SHADE_SOLID;
                        break;
                    case YY_FLAT:
                        match(YY_FLAT);
                        flags &= ~(ESCH_CAM_SHADE_SMOOTH
                                   | ESCH_CAM_SHADE_SPECULAR);
                        flags |= ESCH_CAM_SHADE_WIRE
                                 | ESCH_CAM_SHADE_SOLID
                                 | ESCH_CAM_SHADE_FLAT;
                        break;
                    case YY_SMOOTH:
                        match(YY_SMOOTH);
                        flags &= ~ESCH_CAM_SHADE_SPECULAR;
                        flags |= ESCH_CAM_SHADE_WIRE
                                 | ESCH_CAM_SHADE_SOLID
                                 | ESCH_CAM_SHADE_FLAT
                                 | ESCH_CAM_SHADE_SMOOTH;
                        break;
                    case YY_SPECULAR:
                        match(YY_SPECULAR);
                        flags |= ESCH_CAM_SHADE_WIRE
                                 | ESCH_CAM_SHADE_SOLID
                                 | ESCH_CAM_SHADE_FLAT
                                 | ESCH_CAM_SHADE_SMOOTH
                                 | ESCH_CAM_SHADE_SPECULAR;
                        break;
                    default:
                        error("shade can be set to wire, flat, solid, smooth, or specular");
                        break;
                }

                match(YY_SEMICOLON);

                cam->set_flags(flags);
            }
            break;

        //陳陳� bfculling={on | off | yes | no};
        case YY_BFCULLING:
            {
                match(YY_BFCULLING);
                match(YY_EQUAL);

                dword flags = cam->flags;

                switch (CurrentToken)
                {
                    case YY_YES:
                    case YY_ON:
                        match(CurrentToken);
                        flags |= ESCH_CAM_BACKCULL;
                        break;

                    case YY_NO:
                    case YY_OFF:
                        match(CurrentToken);
                        flags &= ~ESCH_CAM_BACKCULL;
                        break;

                    default:
                        error("bfculling can be yes/on or no/off");
                        break;
                }

                match(YY_SEMICOLON);

                cam->set_flags(flags);
            }
            break;

        //陳陳� textured={on | off | yes | no};
        case YY_TEXTURED:
            {
                match(YY_TEXTURED);
                match(YY_EQUAL);

                dword flags = cam->flags;

                switch (CurrentToken)
                {
                    case YY_YES:
                    case YY_ON:
                        match(CurrentToken);
                        flags |= ESCH_CAM_TEXTURED;
                        break;

                    case YY_NO:
                    case YY_OFF:
                        match(CurrentToken);
                        flags &= ~ESCH_CAM_TEXTURED;
                        break;

                    default:
                        error("textured can be yes/on or no/off");
                        break;
                }

                match(YY_SEMICOLON);

                cam->set_flags(flags);
            }
            break;

        //陳陳� perspective={on | off | yes | no};
        case YY_PERSPECTIVE:
            {
                match(YY_PERSPECTIVE);
                match(YY_EQUAL);

                dword flags = cam->flags;

                switch (CurrentToken)
                {
                    case YY_YES:
                    case YY_ON:
                        match(CurrentToken);
                        flags |= ESCH_CAM_PERSPECTIVE;
                        break;

                    case YY_NO:
                    case YY_OFF:
                        match(CurrentToken);
                        flags &= ~ESCH_CAM_PERSPECTIVE;
                        break;

                    default:
                        error("perspective can be yes/on or no/off");
                        break;
                }

                match(YY_SEMICOLON);

                cam->set_flags(flags);
            }
            break;

        //陳陳� alpha={on | off | yes | no};
        case YY_ALPHA:
            {
                match(YY_ALPHA);
                match(YY_EQUAL);

                dword flags = cam->flags;

                switch (CurrentToken)
                {
                    case YY_YES:
                    case YY_ON:
                        match(CurrentToken);
                        flags |= ESCH_CAM_ALPHA;
                        break;

                    case YY_NO:
                    case YY_OFF:
                        match(CurrentToken);
                        flags &= ~ESCH_CAM_ALPHA;
                        break;

                    default:
                        error("alpha can be yes/on or no/off");
                        break;
                }

                match(YY_SEMICOLON);

                cam->set_flags(flags);
            }
            break;

        //陳陳� show_all_lines={on | off | yes | no};
        case YY_SHOW_ALL_LINES:
            {
                match(YY_SHOW_ALL_LINES);
                match(YY_EQUAL);

                dword flags = cam->flags;

                switch (CurrentToken)
                {
                    case YY_YES:
                    case YY_ON:
                        match(CurrentToken);
                        flags |= ESCH_CAM_SHOW_ALL_LINES;
                        break;

                    case YY_NO:
                    case YY_OFF:
                        match(CurrentToken);
                        flags &= ~ESCH_CAM_SHOW_ALL_LINES;
                        break;

                    default:
                        error("show_all_lines can be yes/on or no/off");
                        break;
                }

                match(YY_SEMICOLON);

                cam->set_flags(flags);
            }
            break;

        //陳陳� position=<float>,<float>,<float>;
        case YY_POSITION:
            {
                match(YY_POSITION);
                match(YY_EQUAL);

                float x = (float)rexpr();
                match(YY_COMMA);

                float y = (float)rexpr();
                match(YY_COMMA);

                float z = (float)rexpr();
                match(YY_SEMICOLON);

                cam->set_position(x, y, z);
            }
            break;

        //陳陳� top=<float>,<float>,<float>;
        case YY_TOP:
            {
                match(YY_TOP);
                match(YY_EQUAL);

                float i = (float)rexpr();
                match(YY_COMMA);

                float j = (float)rexpr();
                match(YY_COMMA);

                float k = (float)rexpr();
                match(YY_SEMICOLON);

                cam->set_top(i, j, k);
            }
            break;

        //陳陳� direction=<float>,<float>,<float>;
        case YY_DIRECTION:
            {
                match(YY_DIRECTION);
                match(YY_EQUAL);

                float i = (float)rexpr();
                match(YY_COMMA);

                float j = (float)rexpr();
                match(YY_COMMA);

                float k = (float)rexpr();
                match(YY_SEMICOLON);

                cam->set_dir(i, j, k);
            }
            break;

        //陳陳� lookat=<float>,<float>,<float>;
        case YY_LOOKAT:
            {
                match(YY_LOOKAT);
                match(YY_EQUAL);

                float x = (float)rexpr();
                match(YY_COMMA);

                float y = (float)rexpr();
                match(YY_COMMA);

                float z = (float)rexpr();
                match(YY_SEMICOLON);

                cam->set_lookat(x, y, z);
            }
            break;

        //陳陳� factor=<float>;
        case YY_FACTOR:
            {
                match(YY_FACTOR);
                match(YY_EQUAL);

                float f = (float)rexpr();
                match(YY_SEMICOLON);

                cam->set_factor(f);
            }
            break;

        //陳陳� fov=<float>;
        case YY_FOV:
            {
                match(YY_FOV);
                match(YY_EQUAL);

                float f = (float)rexpr();

                if (f < 1 || f > 175)
                    error("FOV out of range");

                match(YY_SEMICOLON);

                cam->set_fov(f);
            }
            break;

        //陳陳� hither=<float>;
        case YY_HITHER:
            {
                match(YY_HITHER);
                match(YY_EQUAL);

                float f = (float)rexpr();

                if (f < 1)
                    error("Hither out of range");

                match(YY_SEMICOLON);

                cam->set_hither(f);
            }
            break;

        //陳陳� yon=<float>;
        case YY_YON:
            {
                match(YY_YON);
                match(YY_EQUAL);

                float f = (float)rexpr();

                match(YY_SEMICOLON);

                cam->set_yon(f);
            }
            break;

        //陳陳� aspect_ratio=<float>;
        case YY_ASPECT_RATIO:
            {
                match(YY_ASPECT_RATIO);
                match(YY_EQUAL);

                float f = (float)rexpr();

                match(YY_SEMICOLON);

                cam->set_aspect_ratio(f);
            }
            break;

        //陳陳� bcolor=<integer>,<integer>,<integer>;
        case YY_BCOLOR:
            {
                match(YY_BCOLOR);
                match(YY_EQUAL);

                int r = expr();
                if (r < 0 || r > 255)
                    error("Red component out of range");
                match(YY_COMMA);

                int g = expr();
                if (g < 0 || g > 255)
                    error("Green component out of range");
                match(YY_COMMA);

                int b = expr();
                if (b < 0 || b > 255)
                    error("Blue component out of range");
                match(YY_SEMICOLON);

                assert(Palette != 0);
                cam->set_bcolor(Palette->get_index(VngoColor24bit((byte)r,
                                                                  (byte)g,
                                                                  (byte)b)));
            }
            break;

        //陳陳� bitmap=<file>;
        case YY_BITMAP:
            {
                YY_esc_allowed=0;
                match(YY_BITMAP);
                match(YY_EQUAL);
                YY_esc_allowed=1;

                if (CurrentToken != YY_STRING
                    || !xf_exist(yytext))
                    error("bitmap attribute needs valid filename");

                strlwr(yytext);

                XFBitmap bm;
                if (strstr(yytext,".bmp"))
                {
                    XFParseBMP bmp(&bm);
                    if (bmp.nameread(yytext) != XF_ERR_NONE)
                        error("Failed to read bitmap as BMP file");
                }
                else if (strstr(yytext,".cel"))
                {
                    XFParseCEL cel(&bm);
                    if (cel.nameread(yytext) != XF_ERR_NONE)
                        error("Failed to read bitmap as CEL file");
                }
                else if (strstr(yytext,".lbm"))
                {
                    XFParseLBM lbm(&bm);
                    if (lbm.nameread(yytext) != XF_ERR_NONE)
                        error("Failed to read bitmap as LBM file");
                }
                else if (strstr(yytext,".tga"))
                {
                    XFParseTGA tga(&bm);
                    if (tga.nameread(yytext) != XF_ERR_NONE)
                        error("Failed to read bitmap as TGA file");
                }
                else if (strstr(yytext,".xeb"))
                {
                    XFParseXEB xeb(&bm);
                    if (xeb.nameread(yytext) != XF_ERR_NONE)
                        error("Failed to read bitmap as XFEB file");
                }
                else
                    error("Unknown file extender for bitmap");

                if (cam->create_bg_bitmap(&bm))
                    warning("Failed to create bitmap background");

                match(YY_STRING);
                match(YY_SEMICOLON);
            }
            break;

        //陳陳� haze={<float>,<float> | on | off | yes | no};
        case YY_HAZE:
            match(YY_HAZE);
            match(YY_EQUAL);

            switch (CurrentToken)
            {
                case YY_ON:
                case YY_YES:
                    match(CurrentToken);
                    cam->vport->haze_on();
                    break;

                case YY_OFF:
                case YY_NO:
                    match(CurrentToken);
                    cam->vport->haze_off();
                    break;

                default:
                    {
                        float h1 = (float)rexpr();
                        match(YY_COMMA);

                        float h2 = (float)rexpr();

                        cam->set_haze(h1,h2);
                    }
                    break;
            }
            match(YY_SEMICOLON);
            break;

        //陳陳� rotatex=<float>;
        case YY_ROTATEX:
            {
                match(YY_ROTATEX);
                match(YY_EQUAL);

                float d = (float)rexpr();
                match(YY_SEMICOLON);

                cam->rotatex(d);
            }
            break;

        //陳陳� rotatey=<float>;
        case YY_ROTATEY:
            {
                match(YY_ROTATEY);
                match(YY_EQUAL);

                float d = (float)rexpr();
                match(YY_SEMICOLON);

                cam->rotatey(d);
            }
            break;

        //陳陳� rotatez=<float>;
        case YY_ROTATEZ:
            {
                match(YY_ROTATEZ);
                match(YY_EQUAL);

                float d = (float)rexpr();
                match(YY_SEMICOLON);

                cam->rotatez(d);
            }
            break;

        //陳陳� yaw=<float>;
        case YY_YAW:
            {
                match(YY_YAW);
                match(YY_EQUAL);

                float d = (float)rexpr();
                match(YY_SEMICOLON);

                cam->yaw(d);
            }
            break;

        //陳陳� pitch=<float>;
        case YY_PITCH:
            {
                match(YY_PITCH);
                match(YY_EQUAL);

                float d = (float)rexpr();
                match(YY_SEMICOLON);

                cam->pitch(d);
            }
            break;

        //陳陳� roll=<float>;
        case YY_ROLL:
            {
                match(YY_ROLL);
                match(YY_EQUAL);

                float d = (float)rexpr();
                match(YY_SEMICOLON);

                cam->roll(d);
            }
            break;

        //陳陳� translate=<float>,<float>,<float>;
        case YY_TRANSLATE:
            {
                match(YY_TRANSLATE);
                match(YY_EQUAL);

                float i = (float)rexpr();
                match(YY_COMMA);

                float j = (float)rexpr();
                match(YY_COMMA);

                float k = (float)rexpr();
                match(YY_SEMICOLON);

                cam->translate(i, j, k);
            }
            break;

        //陳陳� move=<float>,<float>,<float>;
        case YY_MOVE:
            {
                match(YY_MOVE);
                match(YY_EQUAL);

                float i = (float)rexpr();
                match(YY_COMMA);

                float j = (float)rexpr();
                match(YY_COMMA);

                float k = (float)rexpr();
                match(YY_SEMICOLON);

                cam->move(i, j, k);
            }
            break;

        default:
            error("Expected a camera attribute");
    }
}

//葦� eof - scamera.cpp 憶�

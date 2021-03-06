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
//                       *** IPAS Mesh Data Exporter ***
//
// uimtl.c
//
// Contains the user-interface for the material export.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <debug.h>

#include "xfdefs.h"

#include "pxp.h"
#include "dialog.h"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Structures
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Routines
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

void about();

//陳� Feel functions
static void feel_ok(Dialog *d, int mouse);
static void feel_cancel(Dialog *d, int mouse);
static void feel_about(Dialog *d, int mouse);
static void feel_palette(Dialog *d, int mouse);

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

static int loop_done;

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// Make sure that 'empty' strings in .3DE file are filled with dummy values,�
// otherwise the compiler makes them all point to the same string, assuming �
// it is static.  This is wrong and results in editables pointing to the    �
// string.                                                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
#include "eschmtl.3de"

static FeelSub EschMtl_feel[] =
{
    OK,         feel_ok,
    ABOUT,      feel_about,
    PALETTE,    feel_palette,
    -1, FNULL
};

int mtl_sizemode=1;                         // 1=just to power of 2,
                                            // 2=force to mtl_sizex/y
                                            // 3=query on each

int mtl_format=1;                           // 1=8-bit
                                            // 2=True-color (24/32-bit)

int mtl_compress=0;                         // 0=none
                                            // 1=rle

int mtl_animatedtxt=0;                      // 0=first-frame only
                                            // 1=multiframe

int mtl_perspmode=1;                        // 1=never
                                            // 2=^ in name
                                            // 3=always

static RadSub EschMtl_rad[] =
{
    POWER2, feel_radio, &mtl_sizemode, 1,
    SET, feel_radio, &mtl_sizemode, 2,
    QUERY, feel_radio, &mtl_sizemode, 3,

    F8BIT, feel_radio, &mtl_format, 1,
    FTC, feel_radio, &mtl_format, 2,

    PNEVER, feel_radio, &mtl_perspmode, 1,
    PCARET, feel_radio, &mtl_perspmode, 2,
    PALWAYS, feel_radio, &mtl_perspmode, 3,

    AFIRST, feel_radio, &mtl_animatedtxt, 0,
    AMFRAME, feel_radio, &mtl_animatedtxt, 1,

    -1, FNULL, NULL, -1
};

// Material export information

int mtl_sizex=64;
int mtl_sizey=64;

char mtl_palpath[128]   = "C:\\";
char mtl_palname[13]   = "ESPORT.VGP";

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// do_mtl                                                                   �
//                                                                          �
// Do material's dialog.                                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void do_mtl()
{
    int         sizex, sizey;
    Editable    *e;
    static int  inited = 0;
    char        buff[32];

    if (! inited)
    {
        init_dialog(EschMtl, EschMtl_edit, NULL);
        inited = 1;
    }

    loop_done=0;

    EschMtl[PALETTE].text=mtl_palname;
    EschMtl[PALETTE].radio=0;
    EschMtl[COMPRESS].radio = (mtl_compress) ? 1 : 0;

    ready_dialog(EschMtl, EschMtl_edit, NULL, EschMtl_feel, EschMtl_rad,
                NULL, NULL);

    sprintf(buff,"%d",mtl_sizex);
        init_editable(&EschMtl[SIZEX], buff);

    sprintf(buff,"%d",mtl_sizey);
        init_editable(&EschMtl[SIZEY], buff);

startover: ;

    while (!loop_done)
    {
        center_dialog(EschMtl);
        save_under_dialog(EschMtl);
        draw_dialog(EschMtl);
        do_dialog(EschMtl, -1);
    }

    e=(Editable*)EschMtl[SIZEX].text;
    sizex=atoi(e->string);

    switch(sizex) {
        case 16:
        case 32:
        case 64:
        case 128:
        case 256:
            break;
        default:
            gfx_continu_line("X Size must be 16, 32, 64, 128, or 256");
            loop_done=0;
            goto startover;
    }

    e=(Editable*)EschMtl[SIZEY].text;
    sizey=atoi(e->string);

    switch(sizey) {
        case 16:
        case 32:
        case 64:
        case 128:
        case 256:
            break;
        default:
            gfx_continu_line("Y Size must be 16, 32, 64, 128, or 256");
            loop_done=0;
            goto startover;
    }

    mtl_sizex=sizex;
    mtl_sizey=sizey;

    mtl_compress = (EschMtl[COMPRESS].radio) ? 1 : 0;
}

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//                            旭� static 旭�                                �
// Feel functions                                                           �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
static void feel_ok(Dialog *d, int mouse)
{
    if(mouse)
        if(!(press_button(d)))
            return;

    dialog_done=1;
    restore_under_dialog();

    loop_done=1;
}

static void feel_about(Dialog *d, int mouse)
{
    if(mouse)
        if(!(press_button(d)))
            return;

    dialog_done=1;
    restore_under_dialog();
    about();
}

static void feel_palette(Dialog *d, int mouse)
{
    char    buff[128];
    char    extenders[11][4] = { "VGP", "PAL",  "",  "",  "",  "",
                                "",  "",  "",  "",  "", };

    char    drive[XF_MAX_DRIVE];
    char    dir[XF_MAX_DIR];
    char    fname[XF_MAX_FNAME];
    char    ext[XF_MAX_EXT];

    if(mouse)
        if(!(press_button(d)))
            return;

    dialog_done=1;
    restore_under_dialog();

    for(;;) {
        if (mtl_palpath[strlen(mtl_palpath)-1]=='\\')
            mtl_palpath[strlen(mtl_palpath)-1]=0;

        gfx_file_selector("VanGogh Palette File",
                          mtl_palpath,
                          mtl_palname,
                          extenders,
                          buff);

        if (!*buff)
            return;

        if (access(buff,0) != 0) {
            gfx_continu_line("Palette file doesn't exist");
        }
        else
            break;
    }

    _splitpath(buff,drive,dir,fname,ext);

    strcpy(mtl_palpath,drive);
    strcat(mtl_palpath,dir);

    strcpy(mtl_palname,fname);
    strcat(mtl_palname,ext);
}

//葦� End of module - uimtl.c 憶�

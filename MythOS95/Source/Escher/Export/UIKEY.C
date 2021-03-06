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
// Created by Tim Little & Chuck Walbourn & Paul Masters
//
//                       *** IPAS Mesh Data Exporter ***
//
// uikey.c
//
// Contains the user-interface for the keyframe export.
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
static void feel_target(Dialog *d, int mouse);
static void feel_flags(Dialog *d, int mouse);

//陳� Functions in other modules
void do_key_flags();

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

long key_apnd;
char key_mtyp[80];

extern int keys_flag;

static int loop_done;
static int do_export;

char key_output_path[128] = "C:\\";
char key_output_name[13] = "SABKEYS.IFF";

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// Make sure that 'empty' strings in .3DE file are filled with dummy values,�
// otherwise the compiler makes them all point to the same string, assuming �
// it is static.  This is wrong and results in editables pointing to the    �
// string.                                                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
#include "eschkey.3de"

static FeelSub EschKey_feel[] =
{
    OK,         feel_ok,
    KEY_TARG,   feel_target,
    KEY_FLAG,   feel_flags,
    CANCEL,     feel_cancel,
    -1, FNULL
};

static RadSub EschKey_rad[] =
{
    -1, FNULL, NULL, -1
};

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// do_light                                                                 �
//                                                                          �
// Do lights's dialog.                                                      �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void do_key()
{
    static int  inited = 0;
    Editable    *e;

    char        file[16];
    char        path[128];
    char        buff[128];

    if (!inited)
    {
        // initialize dialog with Editable
        init_dialog(EschKey, EschKey_edit, NULL);
        inited = 1;
    }

    do_export=loop_done=0;

    gfx_get_paths(GFX_3DS_PATH,0,path,file);
    if (strstr(file,".3DS"))
    {
        *strstr(file,".3DS")=0;
        strcat(file,"K.IFF");
        strcpy(key_output_name,file);
        strcpy(key_output_path,path);
    }
    EschKey[KEY_TARG].text = key_output_name;

    // ready dialog with Editable, feelers, and Radio buttons active
    ready_dialog(EschKey, EschKey_edit, NULL, EschKey_feel, EschKey_rad,
                NULL, NULL);

    sprintf (buff, "WALKING_FOR");
    init_editable(&EschKey[KEY_MTYP], buff);

    while (!loop_done)
    {
        center_dialog(EschKey);
        save_under_dialog(EschKey);
        draw_dialog(EschKey);
        do_dialog(EschKey, -1);
    }

    if (do_export)
    {
        // Set flag data
        e=(Editable *)EschKey[KEY_MTYP].text;
        strcpy(key_mtyp, e->string);

        keys_flag = 1;
    }
    else
    {
        keys_flag = 0;
    }
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
    do_export=1;
    loop_done=1;
}

static void feel_cancel(Dialog *d, int mouse)
{
    int status;

    if(mouse)
        if(!(press_button(d)))
            return;

    dialog_done=1;
    restore_under_dialog();
    do_export=0;
    loop_done=1;
}


static void feel_target(Dialog *d, int mouse)
{
    int     status;
    char    buff[128];
    char    extenders[11][4] = { "IFF", "",  "",  "",  "",  "",
                                "",  "",  "",  "",  "", };
    Editable *e;

    char    drive[XF_MAX_DRIVE];
    char    dir[XF_MAX_DIR];
    char    fname[XF_MAX_FNAME];
    char    ext[XF_MAX_EXT];

    if(mouse)
        if(!(press_button(d)))
            return;

    dialog_done=1;
    restore_under_dialog();

    for(;;)
    {
        if (key_output_path[strlen(key_output_path)-1]=='\\')
            key_output_path[strlen(key_output_path)-1]=0;

        gfx_file_selector("Escher Output File",
                         key_output_path,
                         key_output_name,
                         extenders,
                         buff);

        if (!*buff)
            return;

        if (access(buff,0)==0)
        {
            gfx_alert (2, "[File exists][Append|Overwrite|Cancel]", status);
            if (status == 0)
            {
                key_apnd = 1;
                _splitpath(buff,drive,dir,fname,ext);

                strcpy(key_output_path,drive);
                strcat(key_output_path,dir);

                strcpy(key_output_name,fname);
                strcat(key_output_name,ext);
            }
            else if (status == 1)
            {
                key_apnd = 0;
                _splitpath(buff,drive,dir,fname,ext);

                strcpy(key_output_path,drive);
                strcat(key_output_path,dir);

                strcpy(key_output_name,fname);
                strcat(key_output_name,ext);
            }
            break;
        }
        else
        {
            _splitpath(buff,drive,dir,fname,ext);

            strcpy(key_output_path,drive);
            strcat(key_output_path,dir);

            strcpy(key_output_name,fname);
            strcat(key_output_name,ext);
            break;
        }
    }
}


static void feel_flags(Dialog *d, int mouse)
{
    dialog_done=1;
    restore_under_dialog();
    do_key_flags();
}


//葦� End of module - uikey.c 憶�


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

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

long key_loop;
long key_ping;
long key_flags;
char key_ctyp[80];

static int loop_done;
static int do_export;

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// Make sure that 'empty' strings in .3DE file are filled with dummy values,�
// otherwise the compiler makes them all point to the same string, assuming �
// it is static.  This is wrong and results in editables pointing to the    �
// string.                                                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
#include "eschkeyf.3de"

static FeelSub EschKeyFlags_feel[] =
{
    OK,         feel_ok,
    CANCEL,     feel_cancel,
    -1, FNULL
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
void do_key_flags()
{
    static int  inited = 0;
    Editable    *e;

    char        file[16];
    char        path[128];
    char        buff[128];

    if (!inited)
    {
        // initialize dialog with Editable
        init_dialog(KeyFlags, EschKeyFlags_edit, NULL);
        inited = 1;
    }

    do_export=loop_done=0;

    // ready dialog with Editable and feelers active
    ready_dialog(KeyFlags, EschKeyFlags_edit, NULL, EschKeyFlags_feel, NULL,
                NULL, NULL);


    sprintf (buff, "WALKING_FOR");
    init_editable(&KeyFlags[KFLGCTYP], buff);

    while (!loop_done)
    {
        center_dialog(KeyFlags);
        save_under_dialog(KeyFlags);
        draw_dialog(KeyFlags);
        do_dialog(KeyFlags, -1);
    }

    if (do_export)
    {
        // Set flag data
        if (KeyFlags[KFLGLOOP].radio)
        {
            key_flags = 1;
        }
        if (KeyFlags[KFLGPING].radio)
        {
            key_flags |= 2;
        }
        if (KeyFlags[KFLGCHAN].radio)
        {
            key_flags |= 4;
            e=(Editable *)KeyFlags[KFLGCTYP].text;
            strcpy(key_ctyp, e->string);
        }
        if (KeyFlags[KFLGSWP1].radio)
        {
            key_flags |= 8;
        }
        if (KeyFlags[KFLGSWP2].radio)
        {
            key_flags |= 16;
        }
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

    loop_done=1;
    do_export=0;
}

//葦� End of module - uikey.c 憶�



//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//                oooooooooo.
//                `888'   `Y8b
//                 888     888  .ooooo.    oooooooo  .ooooo.
//                 888oooo888' d88' `88b  d'""7d8P  d88' `88b
//                 888    `88b 888   888    .d8P'   888   888
//                 888    .88P 888   888  .d8P'  .P 888   888
//                o888bood8P'  `Y8bod8P' d8888888P  `Y8bod8P'
//                           _
//                          /_\     |    _  _ | _ ._
//                         /   \  \_||_|(_|(_||(/_|
//                                       _| _|
//                     Microsoft Windows 95/98/NT Version
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
// Created by Dan Higdon
//
// Bozo QUEUES
//
//  This module also defines the concept of the running queue.
//  This queue defines the "space" in which a task exists.
//  A task may only exist in one (or no) queue at a time.
//  Routines are given to place a task into a queue, and to
//  remove a task from the head of the queue.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

#ifndef __BZ_QUEUE_H
#define __BZ_QUEUE_H 1

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

#ifdef __cplusplus
extern "C" {
#endif

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include "bztask.h"

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


typedef struct _bz_task_queue bz_task_queue;
struct _bz_task_queue
{
    bz_task     *head;
    bz_task     *tail;

    // Additional information?
};

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                              Global Data
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

// A very special queue....
extern bz_task_queue    ReadyQ;

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Prototypes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

void bzqueue_init   (bz_task_queue *);
void bzqueue_enter  (bz_task_queue *, bz_task *);
void bzqueue_push   (bz_task_queue *, bz_task *);
int  bzqueue_empty  (const bz_task_queue *);
void bzqueue_remove (bz_task_queue *, bz_task *);
bz_task *bzqueue_leave  (bz_task_queue *);

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                            "Inline" Macros
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#define bzqueue_empty(q) (!(q)->head)

#ifdef __cplusplus
};
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//葦� End of header - bzqueue.h 憶�

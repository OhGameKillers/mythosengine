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
// Bozo TASK
//
//      This module contains the high-level tasking routines and data
//  structures.  It provides routines for creating and terminating tasks.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "ivory.h"
#include "bzqueue.h"
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

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Routines
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

// The current task
bz_task *Task;

static IvorySubAlloc    *taskspace;

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  API for creating (but not scheduling) a new task.                       �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
bz_task *bz_create (void (*entry) (void *), int stack_size, void *params)
{
    bz_task *t;

    if (taskspace)
        t = (bz_task *)ivory_sub_alloc (taskspace, sizeof (bz_task) + stack_size);
    else
        t = (bz_task *)ivory_alloc (sizeof (bz_task) + stack_size);

    if (t != NULL)
    {
        // The stack lives right beyond the context.
        char *stack = (char *)(t + 1);

        // Initialize the task state parameters
        t->creation_parameters = params;
        t->tls = NULL;

        // Initialize the task pointers.
        t->next  = NULL;
        t->queue = NULL;

        // Initialize the context
        bz_corout (&t->context, entry, stack, stack_size, bz_return, params);
    }

    return t;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  API for creating and scheduling a new coroutine                         �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
bz_task *bz_spawn (void (*entry) (void *), int stack_size, void *params)
{
    bz_task *t = bz_create (entry, stack_size, params);

    // Add the created task to the ready queue.
    if (t != NULL)
        bzqueue_enter (&ReadyQ, t);

    return t;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  Terminate the current coroutine and unschedule it.                      �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void bz_return (void)
{
    // If we're the last, get out.  Otherwise, switch to the next one.
    if (bzqueue_empty (&ReadyQ))
        exit (0);
    else
    {
        bz_task *t = Task;

        // Free the context (stack is optionally on the end of this block)
        // Kinda a hack here, since we're technically executing on a stack
        // that has already been freed!
        Task = bzqueue_leave (&ReadyQ);
        bz_term (t);
        bz_swap (NULL, &Task->context);
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  Terminate the specified task.  It is assumed not to be the current one. �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void bz_term (bz_task *t)
{
    // This function is not legal for the current task -- use bz_return().
    assert (Task != t);

    // Make sure that this task isn't in any queues.
    // (It shouldn't be, but you never really know, do you?)
    if (t->queue)
        bzqueue_remove (t->queue, t);

    // Free the context (stack is optionally on the end of this block)
    if (taskspace)
        ivory_sub_free (taskspace, &t);
    else
        ivory_free (&t);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  Establishes MAIN as the first and only task.                            �
//  Returns the task handle of MAIN as the result.                          �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
bz_task *bz_init_task (IvorySubAlloc *_taskspace)
{
    bz_task *t = (bz_task *)ivory_alloc (sizeof (bz_task));

    // Remember the allocator
    taskspace = _taskspace;

    if (t != NULL)
    {
        // Initialize the task state parameters
        t->creation_parameters = 0;
        t->tls   = NULL;
        t->queue = NULL;
        t->next  = NULL;

        Task = t;
    }

    return t;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  Set the allocator used by Bozo to allocate the stack space for          �
//  each individual task and stack.                                         �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void bz_set_allocator (IvorySubAlloc *_taskspace)
{
    taskspace = _taskspace;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  Get the creation parameters of the current task (the caller).           �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void *bz_get_params (void)
{
    return Task->creation_parameters;
}

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  Get the task's instance data pointer.  Unique for each task.            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void *bz_get_tls (void)
{
    return Task->tls;
}

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  Set the task's instance data pointer.  Unique for each task.            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void bz_set_tls (void *tls)
{
    Task->tls = tls;
}


//葦� End of file - bztask.c 憶�

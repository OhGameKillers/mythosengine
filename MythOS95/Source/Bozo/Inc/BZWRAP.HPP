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
// Bozo C++ Wrapper
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

#ifndef __BZ_WRAP_HPP
#define __BZ_WRAP_HPP 1

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include "bozo.h"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Classes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  The system object.  Initializes the library and such.                   �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class BozoSystem
{
    bz_task *main_task;

public:
    BozoSystem  (IvorySubAlloc * = 0);
    ~BozoSystem ();

    // Here is a simple operator to access the main task pointer.
    operator bz_task* () const;

    void set_allocator (IvorySubAlloc *);
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  The basic task type.  All user tasks should be derived from this.       �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class BozoTask
{
    bz_task     *task;
    bz_task     *parent;

    int         stack_size;
    void        *stackp;

static void     iRun (BozoTask *);

public:
    BozoTask    (int = 0x1000);
    virtual     ~BozoTask();

    // To run the task, we need to initialize it onto a queue.
    bz_task *init (bz_task_queue * = &ReadyQ);

    // This is the member that is executed for the task.
    // Add any user functionality here.
    virtual void run ();

    // Some utility members (hide dangerous globals)
    void    bz_term ()    { if (task) { bz_task *t = task; task = 0; ::bz_term (t); } }
    void    yield (bz_task_queue *destq = &ReadyQ, bz_task_queue *srcq = &ReadyQ)
            { bz_yield (destq, srcq); }

protected:
    void    bz_return ()  { if (task) { task = 0; ::bz_return(); } }
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  The Semaphore wrapper.  Very simple, no added functionality here.       �
//  On destruction, any tasks in the queue are lost.                        �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class BozoSemaphore: public bz_semaphore
{
public:
    BozoSemaphore (int count = 1)   { bzsem_init (this, count); }
    ~BozoSemaphore ()               {   }

    void wait ()                    { bzsem_wait (this); }
    void signal ()                  { bzsem_signal (this); }
};


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
//  A simple Gate type.  This allows a series of tasks to wait for a gate.  �
//  If the gate is open, waiting tasks may pass through it unimpeded.       �
//  If the gate is closed, waiting tasks are queued to wait for it to open. �
//  On destruction, the gate allows all waiting tasks to pass.              �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
class BozoGate: public bz_task_queue
{
    enum { opened, closed } status;

public:
    BozoGate ()     { bzqueue_init (this); close(); }
    ~BozoGate ()    { open(); }

    void wait ()    { if (status == closed) bz_yield (this, &ReadyQ); }
    void close ()   { status = closed; }
    void open ()
    {
        status = opened;
        while (!bzqueue_empty (this))
            bzqueue_enter (&ReadyQ, bzqueue_leave (this));
    }
};

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//葦� End of header - bzwrap.hpp 憶�

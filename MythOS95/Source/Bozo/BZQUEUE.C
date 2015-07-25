//���������������������������������������������������������������������������
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
//                       Microsoft Windows '95 Version
//
//            Copyright (c) 1994-1997 by Charybdis Enterprises, Inc.
//                           All Rights Reserved.
//
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
// Bozo QUEUES
//
//  This module also defines the concept of the task queue.
//  This queue defines the "space" in which a task exists.
//  A task may only exist in one (or no) queue at a time.
//  Routines are given to place a task into a queue, and to
//  remove a task from the head of the queue.
//
//  Note that the currently running task should not be present in
//  any queue, and may yield to any queue it chooses.
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Includes
//                                
//���������������������������������������������������������������������������

#include <stdlib.h>
#include <assert.h>

#include "bzqueue.h"

//���������������������������������������������������������������������������
//
//                                Equates
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                               Structures
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                               Routines
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                 Data
//
//���������������������������������������������������������������������������

// The Task queue used by this library to schedule the next event.
bz_task_queue   ReadyQ = { NULL, NULL };

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
//  Initialize the queue (makes it empty).                                  �
//���������������������������������������������������������������������������
void bzqueue_init (bz_task_queue *q)
{
    assert (q != NULL);

    q->head = q->tail = NULL;
}

//�������������������������������������������������������������������������Ŀ
//  Returns true if the queue is empty, false otherwise.                    �
//���������������������������������������������������������������������������
#ifdef NO_INLINE
int bzqueue_empty (const bz_task_queue *q)
{
    assert (q != NULL);

    return q->head == NULL;
}
#endif

//�������������������������������������������������������������������������Ŀ
//  Add p to list.                                                          �
//���������������������������������������������������������������������������
void bzqueue_enter (bz_task_queue *q, bz_task *t)
{
    assert (q != NULL);
    assert (t != NULL);

    // Remember what queue we're entering.
    t->queue = q;

    if (q->head == NULL)
        q->head = t;
    else
        q->tail->next = t;

    q->tail = t;
    t->next = NULL;
}


//�������������������������������������������������������������������������Ŀ
//  Remove the head from q                                                  �
//���������������������������������������������������������������������������
bz_task *bzqueue_leave (bz_task_queue *q)
{
    bz_task *const res = q->head;

    assert (q != NULL);
    assert (!bzqueue_empty (q));
    assert (res->queue == q);

    // Advance the head pointer to the next element
    q->head = res->next;

    // If there is no next element, empty the queue.
    if (q->head == NULL)
        q->tail = NULL;

    // Make sure that we zero these pointers, since we're no longer
    // in a queue!
    res->queue = NULL;
    res->next = NULL;

    return res;
}

//�������������������������������������������������������������������������Ŀ
//  Add to the head of q                                                    �
//���������������������������������������������������������������������������
void bzqueue_push (bz_task_queue *q, bz_task *t)
{
    assert (q != NULL);
    assert (t != NULL);

    // Remember what queue we're entering.
    t->queue = q;

    // If this is the only item in the queue, initialize the end pointer.
    if (q->tail == NULL)
        q->tail = t;

    // Now, link in the task as the first element.
    t->next = q->head;
    q->head = t;
}


//�������������������������������������������������������������������������Ŀ
//  Remove p from list.                                                     �
//���������������������������������������������������������������������������
void bzqueue_remove (bz_task_queue *q, bz_task *t)
{
    assert (q != NULL);
    assert (t != NULL);

    if (t->queue == q)
    {
        if (q->head == t)
        {
            if (q->head == q->tail)
                q->head = q->tail = NULL;
            else
                q->head = t->next;
        }
        else
        {
            bz_task *ct;
            for (ct = q->head; ct != NULL; ct = ct->next)
            {
                if (ct->next == t)
                {
                    if (t->next == NULL)
                        q->tail = ct->next = ct;
                    else
                        ct->next = t->next;
                    break;
                }
            }
        }

        t->queue = NULL;
        t->next = NULL;
    }
#ifdef DEBUG
    // else this isn't in the queue you think it is!
    else
        assert (t->queue == q);
#endif
}

//��� End of file - bzqueue.c ���
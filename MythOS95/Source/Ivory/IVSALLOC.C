//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//
//                   Ivory -- A Memory Management Library
//
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
// ivsalloc.c
//
// Ivory Sub Allocation - Allocation in a fixed, specified region
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <assert.h>

#include "ivory.h"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

// This is the size of a single page of memory.  It MUST be a power of 2!
#define PAGE_SIZE  (4096*4)
#define PAGE_MASK  (~(PAGE_SIZE-1))

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Routines
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳
// A routine to construct a dword from two words
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳
#define MAKEDWORD(a,b) ((((dword)a) << 16) | (b))

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳
// ivory_sub_initialize
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳
void ivory_sub_initialize (IvorySubAlloc *memory, size_t mem_size)
{
    assertMyth("ivory_sub_initialize needs valid input",
               memory != 0 && (mem_size > sizeof (IvorySubAlloc) + 1024));

//陳� Once we have the block, set up the allocation header
//陳� Fill in the "public" fields
    memory->memory_size = mem_size - sizeof (*memory);

//陳� Initialize the counters
#ifdef DEBUG
    memory->allocation_count = 0;
    memory->free_count = 0;
    memory->memory_alloced = 0;
#endif

//陳� Now, the internal fields (memory is allocated from the top)
    memory->next_free = (byte *)memory + mem_size - sizeof (AllocationHeader);
    memory->freelist = 0;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳
// ivory_sub_terminate
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳
void ivory_sub_terminate (IvorySubAlloc *memmory)
{
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳
// ivory_alloc
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳
void *ivory_sub_alloc (IvorySubAlloc *memory, size_t size)
{
    AllocationHeader **pph, *ph;
        size_t  alloc_size;

    assertMyth("ivory_sub_alloc needs valid inputs", memory != 0 && size > 0);

//陳� Now, make sure there is room for the AllocationHeader, and
//陳� then round the size to the nearest (greater) 16 byte alignment
    alloc_size  = size + sizeof (AllocationHeader) + 0x0f;
    alloc_size &= ~0x0f;

//陳� First, scan the free list to see if we can find a suitable block
//陳� Will this be fast enough, with the double pointer scheme?
    pph = &memory->freelist;
    ph  = *pph;

    while (ph && ph->size < alloc_size)
    {
        pph = &ph->next;
        ph  = ph->next;
    }

//陳� If we have found a suitable block....
    if (ph)
    {
        //陳� If this block is large enough to split, do so
        if (ph->size - alloc_size > sizeof (AllocationHeader) + 16)
        {
            //陳� Remove our block from the end, so as to preserve the chain.
            ph->size -= alloc_size;
            ph = (AllocationHeader *)((char *)ph + ph->size);
        }
        //陳� Otherwise, claim it as our own by overwriting
        //陳� whatever pointed to it.
        else
            *pph = ph->next;
    }
    else
    {
        //陳� Allocate a new block from the unused memory

        //陳� If there isn't enough memory....
        if (memory->next_free - alloc_size <= &memory->wildspace_start)
        {
            return 0;
        }
        else
        {
            //陳� Otherwise, take as much as we need (but no more!)
            //陳� Allocate the memory from wildspace
            memory->next_free -= alloc_size;
            ph = (AllocationHeader *)memory->next_free;
        }
    }

//陳� Now, 'ph' points to a usable chunk of memory.
    assert (ph != 0);
    ph->size = alloc_size;
    ph->next = 0;

#ifdef DEBUG
    //陳� Now, return the area past the buffer (our user's memory)
    memory->allocation_count++;
    memory->memory_alloced += alloc_size;

    //陳� Make sure the block actually contains as many bytes as we want!
    //陳� (Testing by protfault! :-)
    memset (ph + 1, 0, size);
#endif

    return ph + 1;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳
// ivory_sub_zalloc
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳
void *ivory_sub_zalloc (IvorySubAlloc *memory, size_t size)
{
    void *ptr;

    assertMyth("ivory_sub_zalloc needs valid inputs", memory != 0 && size > 0);

    ptr = ivory_sub_alloc (memory, size);
    if (!ptr)
        return 0;

    memset (ptr, 0, size);
    return ptr;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳
// ivory_sub_free
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳
void ivory_sub_free (IvorySubAlloc *memory, void **ptr)
{
    AllocationHeader    *freeblk, *prevprev, *prevblk, *nextblk;

    assertMyth("ivory_sub_free needs valid inputs", memory != 0 && ptr != 0 && *ptr != 0);

//陳� Make sure this is our pointer!
    assertMyth ("ivory_sub_free given pointer out of range",
                *ptr > (void *)memory);
    assertMyth ("ivory_sub_free given pointer out of range",
                *ptr < (void *)(((char *)memory) + memory->memory_size));

//陳� Get a pointer to the header info in front of this block
    freeblk = (AllocationHeader *)*ptr;
    freeblk--;

//陳� Record the free for statistical purposes
#ifdef DEBUG
    memory->memory_alloced -= freeblk->size;
    memory->free_count++;
#endif

//陳� Scan until we are past all free blocks lower in memory than
//陳� ourselves.  This is the most expensive part of this deallocator.
//陳� Note: the '== 0' case is ok, since 0 is not greater than anything!
    prevprev  = prevblk = 0;
    nextblk   = memory->freelist;
    while (nextblk > freeblk)
    {
        prevprev = prevblk;
        prevblk  = nextblk;
        nextblk  = nextblk->next;
    }

    assertMyth("ivory_sub_free told to free memory already in free list",
               nextblk != freeblk);

//陳� Now, we have either a point in the list to add our link, or
//陳� the end of the list.
//陳� 'ph2' points to the link we want to point to our
//陳� free region, and prevblk points to the block containing
//陳� that pointer.
    assert ((prevblk == 0 && nextblk == memory->freelist) ||
            (prevblk != 0 && prevblk->next == nextblk));
    assert (prevprev == 0 || prevprev->next == prevblk);

//陳� If the next block is adjacent, merge.  Otherwise chain it.
    if (nextblk)
    {
        if (freeblk == end_of (nextblk))
        {
            nextblk->size += freeblk->size;
            freeblk = nextblk;
        }
        else
            freeblk->next = nextblk;
    }
#ifdef DEBUG
    else
    {
        assert (freeblk->next == 0);
    }
#endif

//陳� At this point, we know that....
    assert (freeblk == nextblk ||       // We have merged, or
            freeblk->next == nextblk);  // we are linked in.

//陳� If there's a previous block, and it's adjacent, eat our block
    if (prevblk)
    {
        if (prevblk == end_of (freeblk))
        {
            freeblk->size += prevblk->size;

            //陳� Patch our pointer, which is the freelist head if there is no previous block
            if (prevprev)
                prevprev->next = freeblk;
            else
                memory->freelist = freeblk;

            //陳� Back up our previous block pointer for the next step
            prevblk = prevprev;
        }
        //陳� Otherwise, put our block into place
        else
            prevblk->next = freeblk;
    }
    //陳� Otherwise, set this as the first block
    else
        memory->freelist = freeblk;


//陳� If our block is now the last thing in memory, return it to wildspace
    if (freeblk == (AllocationHeader *)memory->next_free)
    {
        memory->next_free += freeblk->size;

        //陳� Make sure that we no longer point at this memory.
        if (prevblk)
            prevblk->next = 0;
        else
            memory->freelist = 0;
    }

//陳� Lastly, zero out the pointer so we don't get into trouble later
    *ptr = 0;
}

//葦� End of module - ivsalloc.c 憶�

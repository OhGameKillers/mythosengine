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
// estcache.cpp
//
// Contains the code for the texture cache management routines that are
// static members of EschTexture.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include "escher.hpp"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#define INIT_TCACHE_SIZE 64

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭�  Operations  碓旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschTexture - cache_new                                                  �
//                                                                          �
// Creates a new instance of texture in the cache or 0 if not found.        �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
EschTexture *EschTexture::cache_new(const char *n)
{
    if (!EschSysInstance || !EschSysInstance->tcache || !n)
        return 0;

//陳� Find texture name in cache
    for(ulong i=0; i < EschSysInstance->tcache_hi; i++)
    {
        if (EschSysInstance->tcache[i].handle
            && !strncmp(EschSysInstance->tcache[i].name,n,ESCH_MAX_NAME))
        {
            EschTexture *t;

            //陳� Create new instance based on type
            switch(EschSysInstance->tcache[i].typ)
            {
                case ESCH_TXTT_STATIC:
                    t = new EschStaticTexture;
                    if (!t)
                        return 0;

                    ((EschStaticTexture*)t)->handle
                                        = EschSysInstance->tcache[i].handle;
                    break;

                case ESCH_TXTT_MFRAME:
                    t = new EschMultiFrameTexture;
                    if (!t)
                        return 0;

                    ((EschMultiFrameTexture*)t)->max
                                        = EschSysInstance->tcache[i].max;
                    ((EschMultiFrameTexture*)t)->set_size
                                            (EschSysInstance->tcache[i].width,
                                             EschSysInstance->tcache[i].height);
                    ((EschMultiFrameTexture*)t)->handle
                                        = EschSysInstance->tcache[i].handle;
                    break;
                default:
                    return 0;
            }

            t->name = EschSysInstance->tcache[i].name;
            t->set_flags(t->flags
                         | ESCH_TXT_SHARED
                         | EschSysInstance->tcache[i].flags);

            //陳� Increment count
            EschSysInstance->tcache[i].count++;

            //陳� Return instance
            return t;
        }
    }

    return 0;
}



//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschTexture - cache_release                                              �
//                                                                          �
// This handles the count decrement for a texture instance created by the   �
// cache_new function and returns 1.  Returns 0 if not a shared texture.    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int EschTexture::cache_release(IvoryHandle h)
{
    if (!EschSysInstance || !EschSysInstance->tcache || !h)
        return 0;

//陳� Find texture handle in cache
    EschTextureCache *tc = EschSysInstance->tcache;
    for(ulong i=0; i < EschSysInstance->tcache_hi; i++, tc++)
    {
        if (tc->handle == h)
        {
            assertMyth("EschTexture::cache_release count should be non-zero",
                       tc->count > 0);

            //陳� Decrement count
            tc->count--;

            if (!tc->count)
            {
                //陳� Last reference, so free
                VngoTexture *p = (VngoTexture*)ivory_hlock(tc->handle);
                if (p)
                {
                    for(ushort i=0; i < tc->max; i++, p++)
                    {
                        p->VngoTexture::~VngoTexture();
                    }
                    ivory_hunlock(tc->handle);
                }
                ivory_hfree(&tc->handle);

                if (tc->name)
                {
                    delete [] tc->name;
                    tc->name = 0;
                }
            }
            return 1;
        }
    }

    return 0;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// EschTexture - cache_register                                             �
//                                                                          �
// Adds a new texture to the shared texture cache.                          �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
esch_error_codes EschTexture::cache_register(const char *n, IvoryHandle hnd,
                                             word t, dword f,
                                             ushort w, ushort h, ushort m,
                                             char **name, int inuse)
{
    assertMyth("EschTexture::cache_register needs System",
               EschSysInstance != 0);

//陳� Initialize texture cache if needed
    if (!EschSysInstance->tcache)
    {
        EschSysInstance->tcache = new EschTextureCache[INIT_TCACHE_SIZE];
        if (!EschSysInstance->tcache)
            return ESCH_ERR_NOMEMORY;

        EschSysInstance->tcache_hi = 0;
        EschSysInstance->tcache_max = INIT_TCACHE_SIZE;
    }

//陳� Find open slot
    for(ulong i=0; i < EschSysInstance->tcache_hi; i++)
    {
        if (!EschSysInstance->tcache[i].handle)
            break;
    }

    if (i >= EschSysInstance->tcache_hi)
    {
        if (EschSysInstance->tcache_hi >= EschSysInstance->tcache_max)
        {
            //陳� Must expand
            EschTextureCache *t
                    = new EschTextureCache[EschSysInstance->tcache_max << 1];
            if (!t)
                return ESCH_ERR_NOMEMORY;

            memcpy(t, EschSysInstance->tcache, EschSysInstance->tcache_max
                                               * sizeof(EschTextureCache));
            delete [] EschSysInstance->tcache;
            EschSysInstance->tcache=t;
            EschSysInstance->tcache_max <<= 1;
        }

        EschSysInstance->tcache_hi++;
    }

//陳� Fill slot
    assert(i < EschSysInstance->tcache_hi && i < EschSysInstance->tcache_max);

    EschTextureCache *tc = &EschSysInstance->tcache[i];

    tc->handle = hnd;
    tc->count = (inuse) ? 1 : 0;
    tc->flags = f & ~(ESCH_TXT_LOCKED
                      | ESCH_TXT_OWNSDATA
                      | ESCH_TXT_SHARED);
    tc->typ = t;
    tc->max = m;
    tc->width = w;
    tc->height = h;
    tc->name = new char[ESCH_MAX_NAME];
    if (!tc->name)
        return ESCH_ERR_NOMEMORY;

    strncpy(tc->name,n,ESCH_MAX_NAME);

    if (*name)
        *name = tc->name;

    return ESCH_ERR_NONE;
}

//葦� End of module - estcache.cpp 憶�


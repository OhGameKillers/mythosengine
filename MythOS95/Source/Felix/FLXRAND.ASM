;様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
;
;
;            _,'|             _.-''``-...___..--';)
;           /_ \'.      __..-' ,      ,--...--'''
;          <\    .`--'''       `     /'
;           `-';'               ;   ; ;  Felix the Fixed-point Library
;     __...--''     ___...--_..'  .;.'
;    (,__....----'''       (,..--''
;
;                    Microsoft Windows 95/98/NT Version
;
;  Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
;
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
;
; This file and all associated files are subject to the terms of the
; GNU Lesser General Public License version 2 as published by the
; Free Software Foundation (http://www.gnu.org).   They remain the
; property of the authors: Dan Higdon, Tim Little, and Chuck Walbourn.
; See LICENSE.TXT in the distribution for a copy of this license.
;
; THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
; OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
; PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
; LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
; OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
;
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
;
;                        http://www.mythos-engine.org/
;
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
;
; Created by Tim Little
;
; flxrand.asm
;
;     This file has all of the Felix 16.16 operator functions.
;
;様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

.486p

        OPTION SCOPED                   ; Enable local labels.

;旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
;
;                                Includes
;                                
;旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

include felix.inc
include macros.inc

;旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
;
;                                Equates
;
;旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�


;旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
;
;                               Structures
;
;旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�


;臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
;
;                                 Data
;
;臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

       ASSUME  ds:_DATA
_DATA  SEGMENT PARA PUBLIC USE32 'DATA'
; Seeds for the random number generator.
seed1          dd   1
seed2          dd   2
seed3          dd   3

_DATA  ENDS

;旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
;
;                                Macros
;
;旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�


;臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
;
;                                 Code
;
;臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�


_TEXT  SEGMENT PARA PUBLIC USE32 'CODE'


;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
; flx_srand(long s1,long s2);                                              �
;       This function sets the seeds for the random number generator.      �
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

START_PROC     flx_srand,  C   s1:DWORD, s2:DWORD
       lea     eax,offset seed1    ; get the offset of the static seed data.
       mov     edx,s1
       mov     [eax],edx
       mov     edx,s2
       mov     [eax+4],edx
       ret
END_PROC       flx_srand


;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
; flx_rand();                                                              �
;      This function generates a random number based on the current seeds. �
;      the result is in the range of positive integers.                    �
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
START_PROC     asm_flx_rand,   C   

       mov     eax,seed1
       xor     edx,edx
       mov     ecx,53668
       idiv    ecx
       mov     ecx,eax         ; store temp value.

       mov     edx,53668
       imul    edx
       sub     seed1,eax
       mov     eax,seed1
       mov     edx,40014
       imul    edx
       xchg    eax,ecx
       mov     edx,12211
       imul    edx
       sub     ecx,eax
       cmp     ecx,0
       jge     @f              ; if it is negative, make it positive.
       add     ecx,2147483399  ; add positive integer resolution.
@@:
       mov     seed1,ecx

; operate on second seed
       mov     eax,seed2
       xor     edx,edx
       mov     ecx,52774
       idiv    ecx
       mov     ecx,eax         ; store temp value.

       mov     edx,52774
       imul    edx
       sub     seed2,eax
       mov     eax,seed2
       mov     edx,40692
       imul    edx
       xchg    eax,ecx
       mov     edx,3791
       imul    edx
       sub     ecx,eax
       cmp     ecx,0
       jge     @f              ; if it is negative, make it positive.
       add     ecx,2147483399  ; add positive integer resolution.
@@:
       mov     seed2,ecx

       mov     eax,seed1
       sub     eax,ecx         ; the result is now in eax to be returned.
       ret
END_PROC       asm_flx_rand

_text   ends
        end

;葦� End of module - flxrand.asm 憶�

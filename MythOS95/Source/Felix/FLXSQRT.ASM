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
; flxsqrt.asm
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
; flx_sqrt(flx16 flx);                                                     �
;       This function takes a felix 16 and returns a felix 16 that is the  �
;       square root of the input value.                                    �
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
START_PROC      asm_flx_sqrt,      C flx:DWORD

        mov     eax,flx
        cmp     eax,0
        jle     done

        mov     ecx,(32-FLX_SQRT_BITRES)
        cmp     eax,(1 SHL FLX_SQRT_BITRES)
        jl      shift_done
        xor     ecx,ecx
;        cmp     eax,(1 SHL 22)
;        jge     find_shift_value
;        shl     eax,(22-FLX_SQRT_BITRES)
;        mov     ecx,(22-FLX_SQRT_BITRES)

find_shift_value:
        test    eax,(3 SHL 30)
        jnz     @f
        lea     ecx,[ecx+2]
        shl     eax,2
        jmp     SHORT find_shift_value
@@:
        shr     eax,(32-FLX_SQRT_BITRES)
; This line caused the orthonormalize to break....?!?!?!
;        adc     eax,0

shift_done:
        shr     ecx,1
        mov     edx,OFFSET Flx16_sqrt_table
        mov     eax,[edx+eax*4]
        shr     eax,cl

done:
        ret        
END_PROC        asm_flx_sqrt

_text   ends
        end

;葦� End of module - flxsqrt.asm 憶�

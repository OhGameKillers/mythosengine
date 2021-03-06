;様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
;
;                                                           %__________%
;                                                          %/ . .  .   \%
;           Van Gogh 2D-Display Library                     |  . .  o. |
;                                                           |. _  .   .|
;        Microsoft Windows 95/98/NT Version                 | / \   .  |
;                                                           |_|_|_._._.|
;                                                           |.-.-.-.-..|
;                                                          %\__________/%
;                                                           %          %
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
; vngZRECT.ASM
;
;      This module draws filled rectangles in all of their permutations.
;
;様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�


.486p

        OPTION SCOPED                   ; Enable local labels.


;旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
;
;                                Includes
;
;旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

include macros.inc
include vngdefs.inc
include vngstrct.inc

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
_DATA   SEGMENT PARA PUBLIC USE32 'DATA'
_DATA   ENDS

;臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
;
;                                 Code
;
;臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

_TEXT  SEGMENT PARA PUBLIC USE32 'CODE'

;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
; zbuff_reset_rect16(VngoVbuffer *vbuf, VngoRect *rect, dword depth);      �
;                                                                          �
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
START_PROC     zbuff_reset_rect16, C CurScreen:DWORD, rectptr:DWORD, depth:DWORD
        LOCAL   LX1             ; Top left x of the rect to fill.
        LOCAL   LDX             ; width of the rect to fill.
        LOCAL   LY1             ; Top left y of the rect to fill.
        LOCAL   LDY             ; height of the rect to fill.

        push    edi
        push    esi
        push    ebx

        mov     esi,CurScreen
        mov     edi,(VNGO_VBUFFER PTR [esi]).vb_scrn_ptr

        mov     ebx,(VNGO_VBUFFER PTR [esi]).vb_zpitch
        mov     ecx,rectptr

        mov     edx,(VNGO_RECT PTR [ecx]).rect_x
        mov     eax,(VNGO_RECT PTR [ecx]).rect_dx

        mov     LX1,edx
        mov     LDX,eax

        mov     edx,(VNGO_RECT PTR [ecx]).rect_dy
        mov     eax,(VNGO_RECT PTR [ecx]).rect_y

        mov     LDY,edx
        mov     ecx,(VNGO_VBUFFER PTR [esi]).vb_ztable

        mov     LY1,eax
        lea     eax,[ecx+eax*4]

        mov     eax,[eax]


        add     eax,LX1
        mov     edi,(VNGO_VBUFFER PTR [esi]).vb_zbuff_ptr
        add     edi,eax
        mov     ecx,LDX
        shl     ecx,1

        mov     eax,depth       ; it is already expanded to 32bits.

; Here it is assumed that edx still has the contents of LDY.
;        mov     edx,LDY         ; LDY doesn't get modified, since it is pixels.
        mov     esi,ecx
        sub     ebx,ecx

;; The outside loop....
Outside_loop:
        mov     ecx,esi
        test    edi,2
        jns     @f
        mov     word ptr [edi],ax
        sub     ecx,2
        lea     edi,[edi+2]
@@:
;        push    ecx
        shr     ecx,2
    rep stosd
;        pop     ecx
;        and     ecx,2
        jnc     @f
        mov     word ptr [edi],ax
        lea     edi,[edi+2]
@@:
        add     edi,ebx         ; go to the next scan line.
        dec     edx
        jg      Outside_loop

        pop     ebx
        pop     esi
        pop     edi
        ret
END_PROC       zbuff_reset_rect16

_text   ends
        end
;葦� End of module - vngZRECT.asm 憶�

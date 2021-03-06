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
; vngclip.asm
;
;       Contains the clipping support code.
;
;       Assumes all values are represented as signed 16.16 fixed-point.
;
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
;
;        Code assembled with Microsoft (R) Macro Assembler Version 6.11
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
include felix.inc
include vngstrct.inc

;臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
;
;                                 Data
;
;臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

       ASSUME  ds:_DATA
_DATA  SEGMENT PARA PUBLIC USE32 'DATA'
_DATA  ENDS

;臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
;
;                                 Code
;
;臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

_TEXT  SEGMENT PARA PUBLIC USE32 'CODE'

;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
; vng_clip_x_line                                                          �
;                                                                          �
;       This function fills in the data for the output point after it is   �
;       clipped to the line in p.                                          �
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

        ALIGN   16
START_PROC vng_clip_x_line,    C  p:dword, s:dword, f:dword, out_point:dword
        LOCAL   t:DWORD         ; this is to be used as a 2.30 fixed point.

        push    ebx
        push    esi
        push    edi

        mov     ebx,p
        mov     esi,f
        mov     edi,s
        mov     ecx,out_point

        mov     eax,(VNGO_POINT PTR [esi]).pt_clr
        mov     (VNGO_POINT PTR [ecx]).pt_clr,eax



        mov     edx,ebx
        cmp     edx,(VNGO_POINT PTR [edi]).pt_x
        jge     @f
        xchg    esi,edi
@@:
        sub     edx,(VNGO_POINT PTR [edi]).pt_x
        xor     eax,eax
        mov     (VNGO_POINT PTR [ecx]).pt_x,ebx
        mov     ebx,(VNGO_POINT PTR [esi]).pt_x
        sub     ebx,(VNGO_POINT PTR [edi]).pt_x
        shrd    eax,edx,2
        sar     edx,2
        idiv    ebx
        mov     t,eax                   ; store 2.30 result.

;; Calculate the new Y.
        mov     ebx,(VNGO_POINT PTR [esi]).pt_y
        sub     ebx,(VNGO_POINT PTR [edi]).pt_y
        imul    ebx
        shrd    eax,edx,30
        add     eax,(VNGO_POINT PTR [edi]).pt_y
        mov     (VNGO_POINT PTR [ecx]).pt_y,eax


;; Calculate the new W.
        mov     eax,t
        mov     ebx,(VNGO_POINT PTR [esi]).pt_w
        sub     ebx,(VNGO_POINT PTR [edi]).pt_w
        imul    ebx
        shrd    eax,edx,30
        add     eax,(VNGO_POINT PTR [edi]).pt_w
        mov     (VNGO_POINT PTR [ecx]).pt_w,eax

;; Calculate the new shade.
        mov     eax,t                   ; get the multiplier again.
        mov     ebx,(VNGO_POINT PTR [esi]).pt_shade
        sub     ebx,(VNGO_POINT PTR [edi]).pt_shade
        imul    ebx
        shrd    eax,edx,30
        add     eax,(VNGO_POINT PTR [edi]).pt_shade
        mov     (VNGO_POINT PTR [ecx]).pt_shade,eax


;; Calculate the new U.
if 1    ;; This is the perspective clip, it gets applied whether doing
        ;; perspective texture maping or not!
        push    ecx
        mov     eax,(VNGO_POINT PTR [esi]).pt_w
        mov     ebx,(VNGO_POINT PTR [esi]).pt_u
        imul    ebx
        shld    edx,eax,2
        mov     ecx,edx

        mov     ebx,(VNGO_POINT PTR [edi]).pt_u
        mov     eax,(VNGO_POINT PTR [edi]).pt_w
        imul    ebx
        shld    edx,eax,2
        push    edx
        sub     ecx,edx
        mov     eax,t
        imul    ecx
        shld    edx,eax,2
        pop     eax
        add     edx,eax
        xor     eax,eax
        shrd    eax,edx,2
        sar     edx,2
        pop     ecx
        idiv    (VNGO_POINT PTR [ecx]).pt_w
        mov     (VNGO_POINT PTR [ecx]).pt_u,eax
else
        mov     eax,t
        mov     ebx,(VNGO_POINT PTR [esi]).pt_u
        sub     ebx,(VNGO_POINT PTR [edi]).pt_u
        imul    ebx
        shrd    eax,edx,30                 
        add     eax,(VNGO_POINT PTR [edi]).pt_u
        mov     (VNGO_POINT PTR [ecx]).pt_u,eax
endif
;; Calculate the new V.
if 1    ;; This is the perspective clip, it gets applied whether doing   
        ;; perspective texture maping or not!

        push    ecx
        mov     eax,(VNGO_POINT PTR [esi]).pt_w
        mov     ebx,(VNGO_POINT PTR [esi]).pt_v
        imul    ebx
        shld    edx,eax,2
        mov     ecx,edx

        mov     ebx,(VNGO_POINT PTR [edi]).pt_v
        mov     eax,(VNGO_POINT PTR [edi]).pt_w
        imul    ebx
        shld    edx,eax,2
        push    edx
        sub     ecx,edx
        mov     eax,t
        imul    ecx
        shld    edx,eax,2
        pop     eax
        add     edx,eax
        xor     eax,eax
        shrd    eax,edx,2
        sar     edx,2
        pop     ecx
        idiv    (VNGO_POINT PTR [ecx]).pt_w
        mov     (VNGO_POINT PTR [ecx]).pt_v,eax
else
        mov     eax,t
        mov     ebx,(VNGO_POINT PTR [esi]).pt_v
        sub     ebx,(VNGO_POINT PTR [edi]).pt_v
        imul    ebx
        shrd    eax,edx,30                 
        add     eax,(VNGO_POINT PTR [edi]).pt_v
        mov     (VNGO_POINT PTR [ecx]).pt_v,eax
endif
;; Calculate the new Z.
        mov     eax,t
        mov     ebx,(VNGO_POINT PTR [esi]).pt_wz
        sub     ebx,(VNGO_POINT PTR [edi]).pt_wz
        imul    ebx
        shrd    eax,edx,30
        add     eax,(VNGO_POINT PTR [edi]).pt_wz
        mov     (VNGO_POINT PTR [ecx]).pt_wz,eax

        pop     edi
        pop     esi
        pop     ebx

        ret

END_PROC   vng_clip_x_line


;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
; vng_clip_y_line                                                         �
;                                                                          �
;       This function fills in the data for the output point after it is   �
;       clipped to the line in p.                                          �
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

        ALIGN   16
START_PROC vng_clip_y_line,    C  p:dword, s:dword, f:dword, out_point:dword
        LOCAL   t:DWORD         ; this is to be used as a 2.30 fixed point.

        push    ebx
        push    esi
        push    edi

        mov     ebx,p
        mov     esi,f
        mov     edi,s
        mov     ecx,out_point

        mov     eax,(VNGO_POINT PTR [esi]).pt_clr
        mov     (VNGO_POINT PTR [ecx]).pt_clr,eax

        mov     edx,ebx
        cmp     edx,(VNGO_POINT PTR [edi]).pt_y
        jge     @f
        xchg    esi,edi
@@:

        sub     edx,(VNGO_POINT PTR [edi]).pt_y
        xor     eax,eax
        mov     (VNGO_POINT PTR [ecx]).pt_y,ebx
        mov     ebx,(VNGO_POINT PTR [esi]).pt_y
        sub     ebx,(VNGO_POINT PTR [edi]).pt_y
        shrd    eax,edx,2
        sar     edx,2
        idiv    ebx
        mov     t,eax                   ; store 2.30 result.

;; Calculate the new X.
        mov     ebx,(VNGO_POINT PTR [esi]).pt_x
        sub     ebx,(VNGO_POINT PTR [edi]).pt_x
        imul    ebx
        shrd    eax,edx,30
        add     eax,(VNGO_POINT PTR [edi]).pt_x
        mov     (VNGO_POINT PTR [ecx]).pt_x,eax


;; Calculate the new W.
        mov     eax,t
        mov     ebx,(VNGO_POINT PTR [esi]).pt_w
        sub     ebx,(VNGO_POINT PTR [edi]).pt_w
        imul    ebx
        shrd    eax,edx,30
        add     eax,(VNGO_POINT PTR [edi]).pt_w
        mov     (VNGO_POINT PTR [ecx]).pt_w,eax


;; Calculate the new shade.
        mov     eax,t                   ; get the multiplier again.
        mov     ebx,(VNGO_POINT PTR [esi]).pt_shade
        sub     ebx,(VNGO_POINT PTR [edi]).pt_shade
        imul    ebx
        shrd    eax,edx,30
        add     eax,(VNGO_POINT PTR [edi]).pt_shade
        mov     (VNGO_POINT PTR [ecx]).pt_shade,eax

;; Calculate the new U.
if 1    ;; This is the perspective clip, it gets applied whether doing
        ;; perspective texture maping or not!

        push    ecx
        mov     eax,(VNGO_POINT PTR [esi]).pt_w
        mov     ebx,(VNGO_POINT PTR [esi]).pt_u
        imul    ebx
        shld    edx,eax,2
        mov     ecx,edx

        mov     ebx,(VNGO_POINT PTR [edi]).pt_u
        mov     eax,(VNGO_POINT PTR [edi]).pt_w
        imul    ebx
        shld    edx,eax,2
        push    edx
        sub     ecx,edx
        mov     eax,t
        imul    ecx
        shld    edx,eax,2
        pop     eax
        add     edx,eax
        xor     eax,eax
        shrd    eax,edx,2
        sar     edx,2
        pop     ecx
        idiv    (VNGO_POINT PTR [ecx]).pt_w
        mov     (VNGO_POINT PTR [ecx]).pt_u,eax
else
        mov     eax,t
        mov     ebx,(VNGO_POINT PTR [esi]).pt_u
        sub     ebx,(VNGO_POINT PTR [edi]).pt_u
        imul    ebx
        shrd    eax,edx,30
        add     eax,(VNGO_POINT PTR [edi]).pt_u
        mov     (VNGO_POINT PTR [ecx]).pt_u,eax
endif
;; Calculate the new V.
if 1    ;; This is the perspective clip, it gets applied whether doing
        ;; perspective texture maping or not!

        push    ecx
        mov     eax,(VNGO_POINT PTR [esi]).pt_w
        mov     ebx,(VNGO_POINT PTR [esi]).pt_v
        imul    ebx
        shld    edx,eax,2
        mov     ecx,edx

        mov     ebx,(VNGO_POINT PTR [edi]).pt_v
        mov     eax,(VNGO_POINT PTR [edi]).pt_w
        imul    ebx
        shld    edx,eax,2
        push    edx
        sub     ecx,edx
        mov     eax,t
        imul    ecx
        shld    edx,eax,2
        pop     eax
        add     edx,eax
        xor     eax,eax
        shrd    eax,edx,2
        sar     edx,2
        pop     ecx
        idiv    (VNGO_POINT PTR [ecx]).pt_w
        mov     (VNGO_POINT PTR [ecx]).pt_v,eax
else
        mov     eax,t
        mov     ebx,(VNGO_POINT PTR [esi]).pt_v
        sub     ebx,(VNGO_POINT PTR [edi]).pt_v
        imul    ebx
        shrd    eax,edx,30
        add     eax,(VNGO_POINT PTR [edi]).pt_v
        mov     (VNGO_POINT PTR [ecx]).pt_v,eax
endif

;; Calculate the new Z.
        mov     eax,t
        mov     ebx,(VNGO_POINT PTR [esi]).pt_wz
        sub     ebx,(VNGO_POINT PTR [edi]).pt_wz
        imul    ebx
        shrd    eax,edx,30
        add     eax,(VNGO_POINT PTR [edi]).pt_wz
        mov     (VNGO_POINT PTR [ecx]).pt_wz,eax


        pop     edi
        pop     esi
        pop     ebx

        ret
END_PROC   vng_clip_y_line

_text   ends
        end

;葦� End of module - vngclip.asm 憶�

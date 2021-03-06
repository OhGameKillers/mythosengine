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
; vngPIX8.ASM 
;
;      This module draws a pixel on the screen in the specified color.
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

;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳
;  vngo_pixel8(vngo_vbuffer *CurScreen, vngo_point *point_ptr);            
;      Draws to the vbuffer passed to it and the point is drawn in the     
;      color specified in the vngo_pixel structure.                        
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳
START_PROC     vngo_pixel8, C CurScreen:DWORD,point_ptr:DWORD
        push    edi
        push    esi
        push    ebx

        mov     esi,CurScreen
        mov     ecx,(VNGO_VBUFFER PTR [esi]).vb_ytable
        mov     edi,point_ptr
        mov     eax,(VNGO_POINT PTR [edi]).pt_y
        lea     ecx,[ecx+eax*4]
        mov     ebx,[ecx]
        add     ebx,(VNGO_POINT PTR [edi]).pt_x
        mov     eax,(VNGO_POINT PTR [edi]).pt_clr
        and     eax,0ffh
        mov     ecx,(VNGO_POINT PTR [edi]).pt_shade
        shr     ecx,3
        mov     edx,(VNGO_VBUFFER PTR [esi]).vb_pal
        mov     edx,[edx+4]
        mov     edx,[edx]
        shl     eax,5          ; color * 32(which is the number of colors
                               ;            in the shade color.

        lea     eax,[eax+ecx]  ; now add the shade level.
        mov     al,byte ptr [edx+eax]
        mov     edi,(VNGO_VBUFFER PTR [esi]).vb_scrn_ptr
        add     edi,ebx
        mov     [edi],al

        pop     ebx
        pop     esi
        pop     edi
        ret
END_PROC       vngo_pixel8     

;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳
;  vngo_zpixel8(vngo_vbuffer *CurScreen, vngo_point *point_ptr);           
;      Draws to the vbuffer passed to it and the point is drawn in the     
;      color specified in the vngo_pixel structure.  It checks the Z-Buffer
;      prior to drawing the pixel.                                         
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳
START_PROC     vngo_zpixel8, C CurScreen:DWORD,point_ptr:DWORD
        push    edi
        push    esi
        push    ebx

        mov     esi,CurScreen
        mov     ecx,(VNGO_VBUFFER PTR [esi]).vb_ytable
        mov     ebx,(VNGO_VBUFFER PTR [esi]).vb_ztable
        mov     edi,point_ptr
        mov     eax,(VNGO_POINT PTR [edi]).pt_y
        lea     ecx,[ecx+eax*4]
        lea     eax,[ebx+eax*4]
        mov     eax,[eax]
        add     eax,(VNGO_POINT PTR [edi]).pt_x
        add     eax,(VNGO_POINT PTR [edi]).pt_x
        mov     ebx,[ecx]
        add     ebx,(VNGO_POINT PTR [edi]).pt_x
; See if I want to draw it.
        add     eax,(VNGO_VBUFFER PTR [esi]).vb_zbuff_ptr
        mov     edx,(VNGO_POINT PTR [edi]).pt_z
        shr     edx,16
        cmp     dx,[eax]
        ja      @f
; update the with the new Z value.
        mov     [eax],dx
        mov     eax,(VNGO_POINT PTR [edi]).pt_clr
        and     eax,0ffh
        mov     ecx,(VNGO_POINT PTR [edi]).pt_shade
        shr     ecx,3
        mov     edx,(VNGO_VBUFFER PTR [esi]).vb_pal
        mov     edx,[edx+4]
        mov     edx,[edx]
        shl     eax,5          ; color * 32(which is the number of colors
                               ;            in the shade color.
        lea     eax,[eax+ecx]  ; now add the shade level.
        mov     al,byte ptr [edx+eax]
        mov     edi,(VNGO_VBUFFER PTR [esi]).vb_scrn_ptr
        add     edi,ebx
        mov     [edi],al
@@:
        pop     ebx
        pop     esi
        pop     edi
        ret
END_PROC       vngo_zpixel8     

_text   ends
        end
;葦� End of module - vngpix8.asm 憶�

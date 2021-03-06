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
; flx16ops.asm
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
; flx_muldiv (flx16 flx1,flx16 flx2,flx16 flx3);                           �
;      This function takes three felix 16's and multiplies the first two   �
;      together and then divides the result by the third and it does so    �
;      without a loss of precision in the intermediate value.              �
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
START_PROC      asm_flx_muldiv,     C   flx1:DWORD,flx2:DWORD,flx3:DWORD
       mov      edx,flx2
       mov      eax,flx1
       mov      ecx,flx3
       imul     edx

       cmp      ecx,0
       jge      @f
       neg      ecx
@@:
       push     edx
       cmp      edx,0
       jge      @f
       neg      edx
@@:
       shr      ecx,1
       cmp      edx,ecx
       jge      error_trap
       mov      ecx,flx3
       pop      edx
       idiv     ecx
       ret

error_trap:
       pop      edx
       mov      ecx,flx3
       xor      edx,ecx
       cmp      edx,0
       jl       @f
       mov      eax,07fffffffh
       ret
@@:
       mov      eax,080000000h
       ret

END_PROC        asm_flx_muldiv

;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
; flx_16mul16(flx16 flx1,flx16 flx2);                                      �
;       This function takes two felix 16's and multiplies them together    �
;       with no loss in precision.  It returns a flx16 with the result.    �
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
START_PROC      asm_flx_16mul16,    C       flx1:DWORD, flx2:DWORD
        mov     eax,flx1
        imul    flx2
        shrd    eax,edx,16
        adc     eax,0           ; round the least significant bit.
        ret
END_PROC        asm_flx_16mul16

;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
; flx_16mul30(flx16 flx1,flx16 flx2);                                      �
;       This function takes a felix 16 and multiplies it with a felix 30   �
;       It returns a flx16 with the result.                                �
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
START_PROC      asm_flx_16mul30,    C       flx1:DWORD, flx2:DWORD
        mov     eax,flx1
        imul    flx2
        shrd    eax,edx,16
        adc     eax,0           ; round the least significant bit.
        ret
END_PROC        asm_flx_16mul30

;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
; flx_16div16(flx16 flx1,flx16 flx2);                                      �
;       This function takes two felix 16's and divides the 1st by the 2nd  �
;       with no loss in precision.  It returns a flx16 with the result.    �
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
START_PROC      asm_flx_16div16,    C       flx1:DWORD, flx2:DWORD
        mov     edx,flx1
        xor     eax,eax
        shrd    eax,edx,16
        sar     edx,16
if SAFE_DIVIDE
        mov     ecx,flx2
        cmp     ecx,0
        jge     @f
        neg     ecx
@@:
        push    edx
        cmp      edx,0
        jge      @f
        neg      edx
@@:
        shr      ecx,1
        cmp      edx,ecx
        jge      error_trap
        pop     edx
endif
        idiv    flx2
        ret

if SAFE_DIVIDE
error_trap:
       pop      edx
       xor      edx,flx2
       cmp      edx,0
       jl       @f
       mov      eax,07fffffffh
       ret
@@:
       mov      eax,080000000h
       ret

endif
END_PROC        asm_flx_16div16



;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
; asm_flx_recip230(flx16 flx1);                                            �
;       This function takes a felix 16 and does the reciprical of it and   �
;       returns it as a signed 2.30 in a dword.                            �
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
START_PROC      asm_flx_recip230,   C   flx1:DWORD
        push    ecx
        mov     ecx,flx1
        mov     eax,010000h
        cmp     ecx,eax
        jge     in_range
        neg     eax
        cmp     ecx,eax
        jle     in_range
        cmp     ecx,0
        jl      @f
        neg     eax
@@:
        shl     eax,14
        pop     ecx
        ret
in_range:
        mov     edx,02000h
        xor     eax,eax
        idiv    ecx
        ; the reciprical is now in eax.
        pop     ecx
        ret
END_PROC        asm_flx_recip230

;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
; flx_sin(flx16 degrees);                                                  �
;       This function takes a felix 16 as degrees and returns the sine of  �
;       the passed in degrees in a felix 16.                               �
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

START_PROC      asm_flx_sin,        C       degrees:DWORD
        mov     eax,degrees
        cmp     eax,0           ; is it negative?
        jl      do_negative
@@:
        cmp     eax,(360 SHL FLX16_SHIFTS)
        jl      SHORT get_val
        sub     eax,(360 SHL FLX16_SHIFTS)
        jmp     SHORT @b
get_val:
        shr     eax,(FLX16_SHIFTS-FLX_DEGREES_SHIFT)
        mov     edx,eax         ; save the degrees. in 31.1
        cmp     eax,(180 SHL FLX_DEGREES_SHIFT)
        jl      @f
        sub     eax,(180 SHL FLX_DEGREES_SHIFT)
@@:
        cmp     eax,(90 SHL FLX_DEGREES_SHIFT)
        jl      all_adjust_done ; is it in the 1st quadrant?
        push    ebx
        mov     ebx,(180 SHL FLX_DEGREES_SHIFT)
        sub     ebx,eax
        mov     eax,ebx
        pop     ebx
all_adjust_done:
        mov     ecx,offset Flx16_sin_data
        mov     eax,[ecx+eax*4]
        cmp     edx,(180 SHL FLX_DEGREES_SHIFT)
                                ; is it in quadrant 3 or 4?       
        jle     SHORT done
        neg     eax
done:
        ret
do_negative:
        add     eax,(360 SHL FLX16_SHIFTS)
        cmp     eax,0
        jge     SHORT get_val
        jmp     SHORT do_negative
END_PROC        asm_flx_sin



;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
; flx_cos(flx16 degrees);                                                  �
;       This function takes a felix 16 as degrees and returns the cosine   �
;       of the passed in degrees in a felix 16.                            �
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
START_PROC      asm_flx_cos,        C       degrees:DWORD
        mov     eax,degrees
        add     eax,(90 SHL FLX16_SHIFTS)
                                ; add 90 degrees and go to the sin function.
        push    eax
        call    asm_flx_sin
        add     esp,4
        ret
END_PROC        asm_flx_cos



;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
; flx_abs(flx16 flx);                                                      �
;       This function takes a felix 16 and returns the absolute value of   �
;       it.                                                                �
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
START_PROC      asm_flx_abs,        C       flx:DWORD
        mov     eax,flx
        cmp     eax,0
        jg      @f              ; if it is less than zero, negate it!
        neg     eax
@@:
        ret
END_PROC        asm_flx_abs
_text   ends        
        end
;葦� End of module - flx16ops.asm 憶�

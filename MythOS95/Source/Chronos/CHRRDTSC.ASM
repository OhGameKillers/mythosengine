;様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
;
;        旭旭旭旭旭旭旭旭旭旭旭
;         旭                旭
;          旭              旭
;           旭        敖陳陳  �   � 敖陳� 敖陳� �   � 敖陳�  敖陳�
;            旭       �  旭   �   � �   � �   � �   � �   �  �
;             旭臼 � 桶碓�    �   � �   � �   � �\  � �   �  �
;              旭� 憶嘘旭     団陳� 団陳� �   � �\\ � �   �  青陳�
;               旭臼� 外      �   � �\    �   � � \\� �   �      �
;               旭    外      �   � � \   �   � �  \� �   �      �
;              旭 � � 青陳陳  �   � �  \  青陳� �   � 青陳�  青陳�
;             旭   � �  旭
;            旭 碓碓旭�  旭
;           旭 臼旭憶碓葦旭�            Timer Library
;          旭臼渦渦臆臼憶憶旭
;         旭臆臆臆臆臆臆臆臆旭
;        旭旭旭旭旭旭旭旭旭旭旭
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
; Created by Dan Higdon
;
; chrrdtsc.asm
;
;     This file contains the chronos_rdtsc routine
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

EXTRN   __fltused:NEAR

_TEXT  SEGMENT PARA PUBLIC USE32 'CODE'
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
; chronos_rdtsc();                                                         �
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
START_PROC      chronos_rdtsc, C
        sub     esp,0000008H
        db      0fH, 31H
        mov     dword ptr [esp+0],eax
        mov     dword ptr [esp+4],edx
        fild    qword ptr [esp+0]
        add     esp,000000008H
        ret
END_PROC        chronos_rdtsc

_text   ends
        end

;葦� End of module - chrrdtsc.asm 憶�

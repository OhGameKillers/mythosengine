;様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
;���������������������������������������������������������������������������
;����������旭旭旭旭旭�旭旭旭旭���旭旭旭旭��旭姻���旭姻旭旭旭旭旭�旭旭旭旭姻�
;���������葦姻������葦姻���葦姻葦姻���葦姻葦姻���葦姻葦姻�������葦姻���葦姻�
;��������碓甥������碓甥�������碓甥�������碓甥���碓甥碓甥�������碓甥���碓甥��
;�������渦臼葦渦��渦臼葦渦臼�渦甥�������渦臼葦渦臼�渦臼葦渦���渦臼葦渦姻����
;������渦甥�������������渦甥渦甥�������渦甥���渦甥渦甥�������渦甥���渦甥����
;�����憶悔������憶悔���憶悔憶悔���憶悔憶悔���憶悔憶悔�������憶悔���憶悔�����
;����臆臆臆臆臆�臆臆臆臆���臆臆臆臆��臆悔���臆悔臆臆臆臆臆�臆悔���臆悔������
;���������������������������������������������������������������������������
;����������������� Microsoft Windows 95/98/NT Version ����������������������
;���������������������������������������������������������������������������
;���Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn���
;���������������������������������������������������������������������������
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
; Created by Tim Little & Chuck Walbourn
;
; esmath.inc
;
;     Contains assembly structures for the various 'math' classes.
;
;様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

;旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
;
;                               Structures
;
;旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
; EschPoint - 3D point (needs to match first four members of VngoPoint).   �
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
ESCH_POINT     STRUCT
ep_x           dd ?    ; X position of the point.
ep_y           dd ?    ; Y position of the point.
ep_z           dd ?    ; Z position of the point.
ep_color       dd ?    ; color of the point.
ESCH_POINT     ENDS

;Note:  ESCH_POINT & ESCH_VECTOR are assumed to be 'identical' in terms of
;       their first three data points for the various math operations.

;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
; EschVector - 3D i,j,k vector.                                              �
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
ESCH_VECTOR    STRUCT
ev_i           dd ?    ; I component of the vector.
ev_j           dd ?    ; J component of the vector.
ev_k           dd ?    ; K component of the vector.
               dd ?    ; filler to make it 16 bytes.
ESCH_VECTOR    ENDS

;Note:  ESCH_POINT & ESCH_VECTOR are assumed to be 'identical' in terms of
;       their first three data points for the various math operations.

;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
; EschVertex - A 3D point and a normal at the point.                         �
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
ESCH_VERTEX    STRUCT
evr_x          dd ?    ; X position of the vertex.
evr_y          dd ?    ; Y position of the vertex.
evr_z          dd ?    ; Z position of the vertex.
evr_color      dd ?    ; color of the  vertex..
evr_i          dd ?    ; I component of the normal @ vertex.
evr_j          dd ?    ; J component of the normal @ vertex.
evr_k          dd ?    ; K component of the normal @ vertex.
               dd ?    ; filler to make it 32 bytes.
ESCH_VERTEX    ENDS

;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
; EschMatrix - A matrix is a 3x4 homogenous matrix (column-major).           �
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�

; [A B C 0]
; [D E F 0]
; [G H I 0]
; [J K L 1]

ESCH_MATRIX    STRUCT
mtx_a         dd ?
mtx_b         dd ?
mtx_c         dd ?
mtx_d         dd ?
mtx_e         dd ?
mtx_f         dd ?
mtx_g         dd ?
mtx_h         dd ?
mtx_i         dd ?
mtx_j         dd ?
mtx_k         dd ?
mtx_l         dd ?
ESCH_MATRIX    ENDS

;Note:  ESCH_MATRIX & ESCH_FOFREF are assumed to be idential in terms
;       of the first 12 data points for the various matrix operations.

;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
; EschFrameRef - Frame of reference                                          �
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
; [A B C 0]
; [D E F 0]
; [G H I 0]
; [J K L 1]
;
; [di dj dk];

ESCH_FOFREF    STRUCT
for_a         dd ?
for_b         dd ?
for_c         dd ?
for_d         dd ?
for_e         dd ?
for_f         dd ?
for_g         dd ?
for_h         dd ?
for_i         dd ?
for_j         dd ?
for_k         dd ?
for_l         dd ?
for_di        dd ?
for_dj        dd ?
for_dk        dd ?
              dd ?    ; filler
ESCH_FOFREF    ENDS

;葦� End of module - esmath.inc 憶�

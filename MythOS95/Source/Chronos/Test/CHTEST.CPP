//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//
//        旭旭旭旭旭旭旭旭旭旭旭
//         旭                旭
//          旭              旭
//           旭        敖陳陳  �   � 敖陳� 敖陳� �   � 敖陳�  敖陳�
//            旭       �  旭   �   � �   � �   � �   � �   �  �
//             旭臼 � 桶碓�    �   � �   � �   � �\  � �   �  �
//              旭� 憶嘘旭     団陳� 団陳� �   � �\\ � �   �  青陳�
//               旭臼� 外      �   � �\    �   � � \\� �   �      �
//               旭    外      �   � � \   �   � �  \� �   �      �
//              旭 � � 青陳陳  �   � �  \  青陳� �   � 青陳�  青陳�
//             旭   � �  旭
//            旭 碓碓旭�  旭
//           旭 臼旭憶碓葦旭�            Timer Library
//          旭臼渦渦臆臼憶憶旭
//         旭臆臆臆臆臆臆臆臆旭
//        旭旭旭旭旭旭旭旭旭旭旭
//
//                    Microsoft Windows 95/98/NT Version
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
// Chronos Test App
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <stdlib.h>
#include <stdio.h>
#include <iostream.h>
#include <conio.h>

#include <chronos.hpp>

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Structures
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Routines
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

int counter = 0;

void cproc (void *addr)
{
    counter++;
//    *(word *)addr = (word)(0x0700 | ('0' + (i & 7)));
}

void main (int argc, char **argv)
{
    ChronosSystem Chronos;

    for(int i=0; i < 30; i++)
        cout << "\n";

//陳陳 Print welcome banner 陳陳
    cout << "Chronos Tester - (C) 1994, 1995 by Charybdis Enterprises, Inc.\n\n";

    Chronos.init();

    Chronometer c;

    // Allow the user to specify a speed multiplier
    if (argc == 2)
    {
        int i = atoi (argv[1]);

        cout << "Interval set to " << i << " * 18.207 secs" << endl;

        Chronos.interval ((ushort)i);
    }
    else
        cout << "Optionally, specify a speed multiplyer (0-65535) on the command line" << endl;

    cout << "Time now = " << c.check() << " ms"  << endl;

    chronos_add_callback (cproc, 1, (void *)0xb8000);
    chronos_add_callback (cproc, 10, (void *)0xb8002);

    cout << "<press any key to stop>" << endl;

    while (!kbhit())
        cout << counter << ' ';

    cout << "Time now = " << c.check() << " ms, ("
         << counter << ") iterations" << endl;
    getch();
    Chronos.term();
}


extern "C" int mythos_atexit( register void ( *__func )( void ) )
{
    return atexit (__func);
}


extern "C" void mythos_atexit_remove( register void ( *__func )( void ) )
{
    (void)__func;
    // NOP
}

// Make sure it uses the correct calling convention!
#ifdef __WATCOMC__
#pragma aux (_ASMSTKCALL_) mythos_atexit;
#pragma aux (_ASMSTKCALL_) mythos_atexit_remove;
#endif

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// _charybdis_assert
//
// Handler for failed asserts.  If msg is set to non-NULL, then an assertMyth
// was used with a comment.
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
extern "C" void _charybdis_assert(char *msg, char *exp, char *f, unsigned ln)
{
    cout.flush();
    printf("\n\n臼� Assertion Failed 臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼\n"
           "Expr:\t%s\n"
           "File:\t%s\t\tLine %d\n",exp,f,ln);
    if (msg)
    {
        printf("Comment:\n%s\n",msg);
    }

    exit(1);
}

//葦� End of module - chtest.cpp 憶�


//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//
//           ^           **   **   **** ***** *    ****     ^      Take me to
//          (_)            * *     *      *   *    *       (_)    / your
//     ^                    *      **     *   *    **            ^  leader...
//    (_)       ^          * *     *      *   *    *            (_)
//             (_)       **   **   *    ***** **** ****
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
//                          *** Tester Application ***
//
// Created by Chuck Walbourn
//
// xtram.cpp
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <iostream.h>

#include "xfile.hpp"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Routines
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

void print_error(char *s);
void print_error(class XFile *xf, char *s);

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// ram                                                                      �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void ram ()
{
//陳陳 Perform file tests 陳陳
   cout << "\n\n\n旭旭旭臼臼臼臆臆臆 RAM object tests 臆臆臆臼臼臼旭旭旭\n";

   cout << "\n旭� Using XFileRAM object 旭�\n";
   XFileRAM     xf;

   if (xf.create("TESTFILE.DAT",0))
   {
       print_error(&xf,"Failed to create file");
   }
   else {
       ulong    i;
       ulong    result;
       char     data[128];

       cout << "File created.\n";

       result=xf.write("Test string\n",sizeof("Test string\n"));

       if (result != sizeof("Test string\n"))
           print_error(&xf,"Failed to write string");
       else
           cout << "Written.\n";

       cout << "Current file position: " << xf.tell() << "\n";

       xf.flush();
       xf.seek_set(0);

       result=xf.read(data,128);

       if (!result)
           print_error(&xf,"Failed to read");
       else {
           for(i=0; i < result; i++)
               cout << data[i];
       }

       xf.close();
   }

   cout << "旭� Copying BOUNCE.BMP into an XFileRAM and outputing RAM.DAT\n";

   if (xf.create("TESTFILE.DAT",0))
   {
       print_error(&xf,"Failed to create file");
   }
   else {
        XFileDisk    xfd;

        if (xfd.open("BOUNCE.BMP",XF_OPEN_READ))
        {
            print_error(&xfd,"Failed to open BOUNCE.BMP");
        }
        else
        {
            if (xf.copyfrom(&xfd))
            {
                print_error(&xf,"Copy to RAM failed");
            }
            else
            {
                xfd.close();
                if (xfd.create("RAM.DAT",0))
                {
                    print_error(&xfd,"Failed to create RAM.DAT");
                }
                else
                {
                    xf.seek_set(0);
                    xf.copyto(&xfd);
                }
            }
        }
        xfd.close();
   }
}

//葦� End of module - xtram.cpp 憶�


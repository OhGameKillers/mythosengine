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
// xtiff.cpp
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <stdio.h>
#include <iostream.h>

#include "xfile.hpp"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Routines
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

void print_error(XFParseIFF *xf, char *s);

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// iff                                                                      �
//                                                                          �
//     Entry point for the XFileIFF tests.                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void iff()
{
//陳陳 Perform .IFF tests 陳陳
   cout << "\n\n\n旭旭旭臼臼臼臆臆臆 XFileIFF object tests 臆臆臆臼臼臼旭旭旭\n";

   cout <<"\n葦� Testing .IFF read operations 憶�\n";

   XFParseIFF  iff;

   cout << "\n旭� Simple one-level object 旭�\n";

   if (iff.open("TEST.IFF",XF_OPEN_READ))
       print_error(&iff,"Cannot open TEST.IFF");
   else {
       char buff[5] = { 0, 0, 0, 0, 0 };

       while (iff.next() == XF_ERR_NONE) {
           cout << "Chunk " << iff.strid(iff.chunkid,buff) << "  size=" << iff.chunkSize << "\n";
       }
       print_error(&iff,"Done with next loop");

       if (iff.close())
           print_error(&iff,"Cannot close TEST.IFF");
   }

   cout << "\n旭� Two-level object 旭�\n";

   if (iff.open("TEST.LBM",XF_OPEN_READ))
       print_error(&iff,"Cannot open TEST.LBM");
   else {
       char buff[5] = { 0, 0, 0, 0, 0 };

       while (iff.next() == XF_ERR_NONE) {

           if (iff.makeid('F','O','R','M') == iff.chunkid) {
                cout << "Form " << iff.strid(iff.formid,buff);
                if (iff.enterform() != XF_ERR_NONE)
                   print_error(&iff,"Problem entering FORM");
           }
           else {
                cout << "Chunk " << iff.strid(iff.chunkid,buff);
           }
           cout << "  size=" << iff.chunkSize << "\n";
       }
       print_error(&iff,"Done with next loop");

       if (iff.close())
           print_error(&iff,"Cannot close TEST.LBM");
   }

   cout <<"\n葦� Testing .IFF write operations 憶�\n";

   ulong       size;
   XFParseIFF  iff2;

   cout << "\n旭� Simple one-level object 旭�\n";

   remove("TEST2.IFF");

   if (iff.open("TEST.IFF",XF_OPEN_READ))
       print_error(&iff,"Cannot open TEST.IFF");
   else if (iff2.create("TEST2.IFF",0))
       print_error(&iff,"Cannot create TEST2.IFF");
   else {
       char buff[5] = { 0, 0, 0, 0, 0 };
       char *work;

       work = new char[65536];

       while (iff.next() == XF_ERR_NONE) {
           cout << "Chunk " << iff.strid(iff.chunkid,buff) << "  size=" << iff.chunkSize << "\n";
           size=iff.chunkSize;
           iff.read(work);
           iff2.write(iff.chunkid,work,size);
       }

       delete [] work;

       if (iff.close())
           print_error(&iff,"Cannot close TEST.IFF");
       if (iff2.close())
           print_error(&iff2,"Cannot close TEST2.IFF");
   }

   cout << "\n旭� Two-level object 旭�\n";

   remove("TEST2.LBM");

   if (iff.open("TEST.LBM",XF_OPEN_READ))
       print_error(&iff,"Cannot open TEST.LBM");
   else if (iff2.create("TEST2.LBM",0))
       print_error(&iff,"Cannot create TEST2.LBM");
   else {
       char buff[5] = { 0, 0, 0, 0, 0 };
       char *work;

       work = new char[65536];

       while (iff.next() == XF_ERR_NONE) {

           if (iff.makeid('F','O','R','M') == iff.chunkid) {
                cout << "Form " << iff.strid(iff.formid,buff);
                if (iff.enterform() != XF_ERR_NONE)
                   print_error(&iff,"Problem entering FORM");
                if (iff2.newform(iff.formid))
                   print_error(&iff,"Cannot create FORM");
           }
           else {
                cout << "Chunk " << iff.strid(iff.chunkid,buff);
                size=iff.chunkSize;
                iff.read(work);
                iff2.write(iff.chunkid,work,size);
           }
           cout << "  size=" << iff.chunkSize << "\n";
       }

       delete [] work;

       if (iff.close())
           print_error(&iff,"Cannot close TEST.LBM");
       if (iff2.close())
           print_error(&iff2,"Cannot close TEST2.LBM");
   }

}

//葦� End of module - xtiff.cpp 憶�


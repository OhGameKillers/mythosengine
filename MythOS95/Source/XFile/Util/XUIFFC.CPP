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
//                              *** Utilities ***
//
// Created by Chuck Walbourn
//
// xuiffc.cpp
//
// This is the main module for the IFF compiler.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include <conio.h>
#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>

#include <ivory.hpp>

#include "debug.h"
#include "xfile.hpp"

#include "xuiffc.h"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#define INIT_WORK_SIZE     32768

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Routines
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

STATIC void cleanup(void);
STATIC void print_help(int full);

void print_error(XFParseIFF *xp, char *s=0);

extern void compile(void);

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

IvorySystem     Ivory;

extern "C" FILE *yyin;

STATIC char Util_name[]
        = "葦 IFF Compiler - (C) 1994-9 by D. Higdon, T. Little, C. Walbourn 碓\n"
          "                  Subject to the terms of the GNU LGPL  " __DATE__ "\n";

XFParseIFF      *IFF=NULL;

byte            *Work=0;
ulong           WorkSize=0;

dword           Flags=0;

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// main                                                                     �
//                                                                          �
// Entry point for the IFFC utility.                                        �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void main(int argc, char *argv[])
{
    int         i;
    char        *ifn, *ofn;

    char        path[XF_MAX_PATH];

    char        drive[XF_MAX_DRIVE];
    char        dir[XF_MAX_DIR];
    char        fname[XF_MAX_FNAME];
    char        ext[XF_MAX_EXT];

//陳� Handle no filename for source file...
    if (argc < 2)
    {
        print_help(0);
        return;
    }

//陳� Process arguments
    for(i=1, ifn=0, ofn=0; i < argc; i++)
    {
        if (*argv[i] == '-' || *argv[i] == '/')
        {
            switch (argv[i][1])
            {
                case '?':
                    print_help(1);
                    return;
                case 'q':
                case 'Q':
                    Flags |= FLAGS_QUIET;
                    break;
                case 'e':
                case 'E':
                    Flags |= FLAGS_EMPTYOK;
                    break;
                case 'r':
                case 'R':
                    Flags |= FLAGS_RIFF;
                    break;
                case 'z':
                case 'Z':
                    Flags |= FLAGS_NOPAD;
                    break;
                case 'x':
                case 'X':
                    Flags |= FLAGS_XEB;
                    break;
                default:
                    cout << "Unknown option " << argv[i] << " ignored\n";
                    break;
            }
        }
        else if (!ifn)
        {
            ifn=argv[i];
            strlwr(ifn);
        }
        else if (!ofn)
        {
            ofn=argv[i];
            strlwr(ofn);
        }
    }

    if (!ifn)
    {
        print_help(0);
        return;
    }

//陳� Check to see if source .cif file exists
    if (!xf_exist(ifn))
    {
        cout << Util_name;
        cout << "臼� " << ifn << " does not exist\n";
        return;
    }

//陳� Open source file
    if ((yyin=fopen(ifn,"r"))==NULL)
    {
        cout << Util_name;
        cout << "臼� Could not open " << ifn << "\n";
        return;
    }

//陳� Setup output filename (uses input name if none given)
    if (ofn)
    {
        strcpy(path,ofn);
    }
    else
    {
        strcpy(path,ifn);
    }
    ofn=path;

    if (!(Flags & FLAGS_RIFF))
    {
        // Forces .IFF extention onto whatever output file is being used
        xf_splitpath(path,drive,dir,fname,ext);
        strcpy(ext,".iff");
        xf_makepath(path,drive,dir,fname,ext);
    }
    else if (!strcmp(ifn,ofn))
    {
        // Forces .RIF extention if same as input name
        xf_splitpath(path,drive,dir,fname,ext);
        strcpy(ext,".rif");
        xf_makepath(path,drive,dir,fname,ext);
    }

//陳� Output title and source/output file stats.
    if (!(Flags & FLAGS_QUIET))
    {
        cout << Util_name;
        cout << "   Source: " << ifn << "    Output: " << ofn << endl;
        cout << "   Format: "
             << ((Flags & FLAGS_RIFF) ? "Microsoft RIFF" : "EA IFF")
             << ((Flags & FLAGS_NOPAD) ? ", no padding" : "") << endl;
    }

//陳� Kill target file...
    xf_remove(ofn);

//陳� Construct IFF writer
    IFF = new XFParseIFF ( ((Flags & FLAGS_RIFF) ? XF_IFF_RIFF : 0)
                           | ((Flags & FLAGS_NOPAD) ? XF_IFF_NOPAD : 0) );
    if (!IFF)
    {
        cout << "臼� Couldn't allocate memory for IFF writer" << endl;
        return;
    }

//陳� Open output file
    if (IFF->create(ofn,0))
    {
        print_error(IFF,"Failed to open output file");
    }

//陳� Parse input
    else
    {

        atexit(cleanup);

        Work = new byte[INIT_WORK_SIZE];
        WorkSize=INIT_WORK_SIZE;

        if (!Work)
        {
            cout << "臼� Couldn't allocate " << WorkSize << " bytes\n";
            exit(1);
        }

        compile();
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// Cleanup function.                                                        �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
STATIC void cleanup(void)
{
    if (Work)
    {
        delete [] Work;
        Work=0;
    }

    if (IFF)
        IFF->close();
    fclose(yyin);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// print_help                                                               �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
STATIC void print_help(int full)
{
    cout << Util_name;
    cout << "   Usage: iffc [ -q | -e | -r | -z | -x] <filename.cif> [<filename.iff>]\n";
    if (full)
    {
        cout << "          -q = Operate quietly.\n";
        cout << "          -e = Do not warn if empty chunk encountered\n";
        cout << "          -r = Use Microsoft RIFF instead of EA IFF\n";
        cout << "          -z = Don't assume even byte padding (MID files)\n";
        cout << "          -x = Insert bitmaps using XFEB form instead of ILBM.\n";
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// print_error                                                              �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void print_error(XFParseIFF *xp, char *s)
{
    cout << "臼� ";

    if (s)
    {
        cout << s << ", ";
    }

    switch (xp->error())
    {
        case XF_ERR_NOTIFF:
            cout << "not an IFF/RIFF file error";
            break;
        case XF_ERR_CHUCKNOTFOUND:
            cout << "chunk not found error";
            break;
        case XF_ERR_FORMNOTFOUND:
            cout << "form not found error";
            break;
        case XF_ERR_UNEXPECTEDEOF:
            cout << "unexpected end-of-file error";
            break;
        case XF_ERR_INVALIDFORFORM:
            cout << "invalid operation for FORM/RIFF error";
            break;
        case XF_ERR_INVALIDFORCHUNK:
            cout << "invalid operation for chunk error";
            break;
        case XF_ERR_INVALIDID:
            cout << "invalid identifier error";
            break;
        case XF_ERR_TRUNCATEDCHUNK:
            cout << "truncated chunk error";
            break;
        case XF_ERR_WRITENOTALLOWED:
            cout << "write not allowed error";
            break;
        case XF_ERR_MAXDEPTHREACHED:
            cout << "maximum supported depth reached error";
            break;
        default:
            cout << "error " << int (xp->error());
            break;
    }

    cout << "\n";
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// expand_work                                                              �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void expand_work(ulong target)
{
    byte    *tmp;
    ulong   tsize;

    tsize=WorkSize;
    while (target > tsize)
    {
        tsize *= 2;
    }

    if (tsize > WorkSize)
    {

        tmp=new byte[tsize];
        if (!tmp)
        {
            cout << "臼� Cannot expand work buffer to " << tsize << " bytes";
            exit(1);
        }

        memcpy(tmp,Work,WorkSize);
        delete [] Work;
        Work = tmp;
        WorkSize = tsize;
    }
}

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

//葦� End of module - xuiffc.cpp 憶�


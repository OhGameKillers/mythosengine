//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
//���������������������������������������������������������������������������
//����������旭旭旭旭旭�旭旭旭旭���旭旭旭旭��旭姻���旭姻旭旭旭旭旭�旭旭旭旭姻�
//���������葦姻������葦姻���葦姻葦姻���葦姻葦姻���葦姻葦姻�������葦姻���葦姻�
//��������碓甥������碓甥�������碓甥�������碓甥���碓甥碓甥�������碓甥���碓甥��
//�������渦臼葦渦��渦臼葦渦臼�渦甥�������渦臼葦渦臼�渦臼葦渦���渦臼葦渦姻����
//������渦甥�������������渦甥渦甥�������渦甥���渦甥渦甥�������渦甥���渦甥����
//�����憶悔������憶悔���憶悔憶悔���憶悔憶悔���憶悔憶悔�������憶悔���憶悔�����
//����臆臆臆臆臆�臆臆臆臆���臆臆臆臆��臆悔���臆悔臆臆臆臆臆�臆悔���臆悔������
//���������������������������������������������������������������������������
//����������������� Microsoft Windows 95/98/NT Version ����������������������
//���������������������������������������������������������������������������
//���Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn���
//���������������������������������������������������������������������������
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
// eshtlib.cpp
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

#include "debug.h"
#include "xfile.hpp"
#include "escher.hpp"
#include "esfile.hpp"

#include "eshtlib.h"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                               Routines
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

int extract(XFParseIFF &iff);
int dump(XFParseIFF &iff, XFile &xf);

int find_txtname(const char *n);
int add_txtname(const char *n);

STATIC void cleanup();

STATIC void print_help(int full);
void print_error(XFParseIFF *xp, char *s=0);

extern void compile();

STATIC int load_pal(VngoPal *pal,char *infile);

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

IvorySystem     Ivory;

extern "C" FILE *yyin;

STATIC char Util_name[]
        = "�Escher Texture Librarian - (C) 1997-9 by D. Higdon, T. Little, C. Walbourn�\n"
          "                            subject to GNU LGPL  " __DATE__ "\n";

XFParseIFF      *TxtIFF=0;
XFParseIFF      *RmdrIFF=0;

ulong           TxtCount=0;
ulong           TxtMax=0;
char            *TxtNames=0;

VngoPal         *Palette=0;

dword   Flags=0;

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// main                                                                     �
//                                                                          �
// Entry point for the ESHTLIB utility.                                     �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int main(int argc, char *argv[])
{
    int         i, err;
    int         fcount=0;
    char        **fn=0;
    char        *ofn=0, *rfn=0;
    char        path[XF_MAX_PATH];

//陳� Handle no filename for directory...
    if (argc < 2)
    {
        print_help(0);
        return 1;
    }

//陳� Process arguments
    fn = new char*[argc];
    assert(fn != 0);

    for(i=1; i < argc; i++)
    {
        if (*argv[i] == '-' || *argv[i] == '/')
        {
            switch (argv[i][1])
            {
                //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Quiet mode
                case 'Q':
                case 'q':
                    Flags |= FLAGS_QUIET;
                    break;

                //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Dump mode
                case 'D':
                case 'd':
                    Flags |= FLAGS_DUMP;
                    break;

                //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Uncompress
                case 'U':
                case 'u':
                    Flags |= FLAGS_UNCOMPRESS;
                    break;

                //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Transparent
                case 'X':
                case 'x':
                    Flags |= FLAGS_XPARENT;
                    break;

                //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Force overwite
                case 'F':
                case 'f':
                    Flags |= FLAGS_FORCEOVERWRITE;
                    break;

                //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Output file
                case 'O':
                case 'o':
                    if (ofn)
                    {
                        cout << "旭 Too many output filenames!\n";
                        return 1;
                    }
                    i++;
                    if (i >= argc || *argv[i]=='-' || *argv[i]=='/')
                    {
                        cout << "旭 Expected an output filename\n";
                        return 1;
                    }
                    ofn=argv[i];
                    strlwr(ofn);
                    break;

                //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Output residual file
                case 'R':
                case 'r':
                    if (Flags & FLAGS_DUMP)
                    {
                        cout << "旭 Residual name not used for dump mode!\n";
                        return 1;
                    }
                    else if (rfn)
                    {
                        cout << "旭 Too many residual filenames!\n";
                        return 1;
                    }
                    else
                    {
                        i++;
                        if (i >= argc || *argv[i]=='-' || *argv[i]=='/')
                        {
                            cout << "旭 Expected a residual filename\n";
                            return 1;
                        }
                        rfn=argv[i];
                        strlwr(rfn);
                    }
                    break;

                //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Palette file
                case 'T':
                case 't':
                    if (Palette)
                    {
                        cout << "旭 Palette name already specified\n";
                        return 1;
                    }

                    i++;
                    if (i >= argc || *argv[i]=='-' || *argv[i]=='/')
                    {
                        cout << "旭 Expected a palette filename\n";
                        return 1;
                    }

                    Palette = new VngoPal8;
                    if (!Palette)
                    {
                        cout << "旭 Out of memory for palette\n";
                        return 1;
                    }

                    err=load_pal(Palette,argv[i]);
                    if (err)
                    {
                        cout << "臼� Error " << err << " loading palette '" << argv[i] << "'\n";
                        return 1;
                    }

                    break;

                //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Help
                case '?':
                    print_help(1);
                    return 0;

                //陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳� Unknown option
                default:
                    cout << "Unknown option " << argv[i] << " ignored\n";
                    break;
            }
        }
        else
        {
            fn[fcount++] = strlwr(argv[i]);
        }
    }

    if (!fcount)
    {
        print_help(0);
        return 1;
    }

//陳� Check to see if supplied file(s) exists
    for(i=0; i < fcount; i++)
    {
        if (!xf_exist(fn[i]))
        {
            cout << "臼� '" << fn[i] << "' does not exist\n";
            return 1;
        }
    }

//陳� Process output filename
    if (ofn)
    {
        strcpy(path,ofn);
    }
    else
    {
        strcpy(path,fn[0]);
    }
    ofn=path;

    {
        char drive[XF_MAX_DRIVE];
        char dir[XF_MAX_DIR];
        char fname[XF_MAX_FNAME];
        char ext[XF_MAX_EXT];

        xf_splitpath(path,drive,dir,fname,ext);

        if (Flags & FLAGS_DUMP)
            strcpy(ext,".ctf");
        else
            strcpy(ext,".iff");

        xf_makepath(path,drive,dir,fname,ext);
    }

    for(i=0; i < fcount; i++)
    {
        if (!strcmp(fn[i],ofn))
        {
            cout << "臼� Output name must be different than input name\n";
            return 1;
        }
    }

    if (!(Flags & FLAGS_FORCEOVERWRITE)
        && xf_exist(ofn))
    {
        cout << "臼� Will overwrite " << ofn << ", ok? (Y/n)";
        cout.flush();
        for(;;)
        {
            i=getch();
            cout << (char)i << "\n";

            if (i == 'Y' || i == 'y' || i == 13)
                break;
            else if (i=='n' || i == 'N')
                return 1;

            break;
        }
    }

    xf_remove(ofn);

//陳� Check residual
    if (rfn)
    {
        for(i=0; i < fcount; i++)
        {
            if (!strcmp(fn[i],rfn))
            {
                cout << "臼� Residual name must be different than input name\n";
                return 1;
            }
        }

        if (!(Flags & FLAGS_FORCEOVERWRITE)
            && xf_exist(rfn))
        {
            cout << "臼� Will overwrite " << rfn << ", ok? (Y/n)";
            cout.flush();
            for(;;)
            {
                i=getch();
                cout << (char)i << "\n";

                if (i == 'Y' || i == 'y' || i == 13)
                    break;
                else if (i=='n' || i == 'N')
                    return 1;

                break;
            }
        }

        xf_remove(rfn);
    }

//陳� Banner
    if (!(Flags & FLAGS_QUIET))
    {
        cout << Util_name;
        if (rfn)
            cout << "   Output File: " << ofn << "   Residual File: " << rfn << "\n";
        else
            cout << "   Output File: " << ofn << "\n";
    }

//陳� Process
    if (Flags & FLAGS_DUMP)
    {
        if (!Palette)
        {
            cout << "臼� Need palette file (-t option) to dump" << endl;
            return 1;
        }

        XFileDiskBuf xf;

        //陳� Create output CTF
        char str[] = "; ESHTLIB dumped texture data\r\n\r\n";

        if (xf.create(ofn,0)
            || xf.write(str,strlen(str)) != strlen(str))
        {
            cout << "臼� Failed to create output file " << ofn << endl;
            return 1;
        }

        //陳� Step each input filename
        for(i=0; i < fcount; i++)
        {
            XFParseIFF iff;

            if (iff.open(fn[i],XF_OPEN_READ | XF_OPEN_DENYWRITE))
            {
                cout << "臼� Failed to open input file '" << fn[i] << "'\n";
                continue;
            }

            if (!(Flags & FLAGS_QUIET))
            {
                cout << "Dumping '" << fn[i] << "'...\n";
            }

            if (dump(iff,xf))
            {
                cout << "臼� Failed dump of '" << fn[i] << "'\n";
                return 1;
            }

            iff.close();
        }

        xf.close();
    }
    else
    {
        atexit(cleanup);

        //陳� Create texture output file
        TxtIFF = new XFParseIFF;
        assert(TxtIFF != 0);

        if (TxtIFF->create(ofn,0))
        {
            cout << "臼� Failed to create output file " << ofn << endl;
            return 1;
        }

        //陳� Create optional remainder file
        if (rfn)
        {
            RmdrIFF = new XFParseIFF;
            assert(RmdrIFF != 0);

            if (RmdrIFF->create(rfn,0))
            {
                cout << "臼� Failed to create residual output file " << rfn << endl;
                return 1;
            }
        }

        //陳� Step each input filename
        for(i=0; i < fcount; i++)
        {
            if (strstr(fn[i],".ctf"))
            {
                if ((yyin=fopen(fn[i],"r"))==NULL)
                {
                    cout << "臼� Failed to open input file '" << fn[i] << "'\n";
                    continue;
                }

                if (!(Flags & FLAGS_QUIET))
                {
                    cout << "Compiling '" << fn[i] << "'...\n";
                }

                compile();

                fclose(yyin);
            }
            else
            {
                XFParseIFF iff;

                if (iff.open(fn[i],XF_OPEN_READ | XF_OPEN_DENYWRITE))
                {
                    cout << "臼� Failed to open input file '" << fn[i] << "'\n";
                    continue;
                }

                if (!(Flags & FLAGS_QUIET))
                {
                    cout << "Extracting '" << fn[i] << "'...\n";
                }

                if (extract(iff))
                {
                    cout << "臼� Failed extract of '" << fn[i] << "'\n";
                    goto error_exit;
                }

                iff.close();
            }
        }
    }

//陳� Cleanup
    cleanup();
    delete [] fn;

    return 0;

error_exit : ;

    cleanup();

    delete [] fn;

    return 1;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// extract                                                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int extract(XFParseIFF &iff)
{
    assert(TxtIFF != 0);

    for(;;)
    {
        if (iff.next() != XF_ERR_NONE)
        {
            if (!iff.depth)
                return 0;

            iff.leaveform();

            if (RmdrIFF
                && RmdrIFF->leaveform())
            {
                cout << "臼� Failed to close form in residual file\n";
                return  1;
            }

            continue;
        }

        if (iff.chunkid == iff.makeid('F','O','R','M'))
        {
            if (iff.formid == iff.makeid('E','M','T','L')
                || iff.formid == iff.makeid('E','M','T','1'))
            {
                dword id = iff.formid;

                iff.enterform();

                // Find header
                if (iff.seekchunk(iff.makeid('M','H','D','R'))
                    || iff.chunkSize != sizeof(EschFileMtlMHDR))
                {
                    cout << "臼� Failed to find material header in input file\n";
                    return  1;
                }

                // Read header
                EschFileMtlMHDR header;
                if (iff.read(&header))
                {
                    cout << "臼� Failed to read material header in input file\n";
                    return  1;
                }

                // Need to see if we already have this texture...
                if (!find_txtname(header.name))
                {
                    // If not, add to list and copy
                    if (add_txtname(header.name))
                    {
                        cout << "臼� Out of memory for texture names\n";
                        return  1;
                    }

                    if (!(Flags & FLAGS_QUIET))
                    {
                        char name[17];
                        memset(name,0,sizeof(name));
                        strncpy(name,header.name,ESCH_MAX_NAME);
                        cout << "   Adding texture '" << name << "'...\n";
                    }

                    // Write texture
                    if (TxtIFF->newform(id)
                        || TxtIFF->write(iff.makeid('M','H','D','R'),
                                        &header,sizeof(header)))
                    {
                        cout << "臼� Failed to create new data in texture file\n";
                        return  1;
                    }

                    while (iff.next() == XF_ERR_NONE)
                    {
                        dword id = iff.chunkid;
                        ulong size = iff.chunkSize;

                        byte *ptr=0;

                        if (size > 0)
                        {
                            ptr = new byte[size];
                            if (!ptr)
                            {
                                cout << "臼� Out of memory copying chunk into texture file\n";
                                return  1;
                            }

                            if (iff.read(ptr))
                            {
                                cout << "臼� Failed to read material chunk from input file\n";
                                return  1;
                            }
                        }

                        if (TxtIFF->write(id,ptr,size))
                        {
                            cout << "臼� Failed to write chunk in material file\n";
                            return  1;
                        }

                        if (ptr)
                            delete [] ptr;
                    }

                    if (TxtIFF->leaveform())
                    {
                        cout << "臼� Failed to close form in texture file\n";
                        return  1;
                    }
                }
                else if (!(Flags & FLAGS_QUIET))
                {
                    char name[17];
                    memset(name,0,sizeof(name));
                    strncpy(name,header.name,ESCH_MAX_NAME);
                    cout << "   Skipping duplicate texture '" << name << "'...\n";
                }

                iff.leaveform();
            }
            else
            {
                if (RmdrIFF
                    && RmdrIFF->newform(iff.formid))
                {
                    cout << "臼� Failed to create new form in residual file\n";
                    return  1;
                }
                iff.enterform();
            }
        }
        else if (RmdrIFF)
        {
            dword id = iff.chunkid;
            ulong size = iff.chunkSize;

            byte *ptr=0;

            if (size > 0)
            {
                ptr = new byte[size];
                if (!ptr)
                {
                    cout << "臼� Out of memory copying chunk into residual file\n";
                    return  1;
                }

                if (iff.read(ptr))
                {
                    cout << "臼� Failed to read chunk from input file\n";
                    return  1;
                }
            }

            if (RmdrIFF->write(id,ptr,size))
            {
                cout << "臼� Failed to write chunk in residual file\n";
                return  1;
            }

            if (ptr)
                delete [] ptr;
        }
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// dump                                                                     �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int dump(XFParseIFF &iff, XFile &xf)
{
    assert(Palette != 0);

    for(;;)
    {
        if (iff.next() != XF_ERR_NONE)
        {
            if (!iff.depth)
                return 0;

            iff.leaveform();
            continue;
        }

        if (iff.chunkid == iff.makeid('F','O','R','M'))
        {
            if (iff.formid == iff.makeid('E','M','T','L')
                || iff.formid == iff.makeid('E','M','T','1'))
            {
                EschBuildTexture tbld;

                if (tbld.load(&iff,0,Palette))
                {
                    cout << "臼� Failed to read texture from IFF file\n";
                    return  1;
                }

                char tname[17];
                memset(tname,0,sizeof(tname));
                strncpy(tname,tbld.name,ESCH_MAX_NAME);

                if (!(Flags & FLAGS_QUIET))
                {
                    cout << "   Dumping texture '" << tname << "'...\n";
                    cout.flush();
                }

                char buff[256];
                sprintf(buff,"texture \"%s\" flags=0x%x %s bpp=%d\r\n",
                             tname, tbld.tflags,
                             (tbld.tflags & ESCH_TXT_TRANSP) ? "transparent" : "",
                             tbld.bms[0]->bpp);

                if (xf.write(buff,strlen(buff)) != strlen(buff)
                    || xf.write("{\r\n",sizeof("{\r\n")-1) != sizeof("{\r\n")-1)
                {
                    cout << "臼� Failed to write to CTF output file\n";
                    return  1;
                }

                for(ulong f=0;;)
                {
                    char fname[256];

                    if (tbld.nframes > 1)
                        sprintf(fname,"%s%d",tname,f+1);
                    else
                        strcpy(fname,tname);

                    if (tbld.bms[f]->bpp == 1 || tbld.bms[f]->bpp == 3)
                        strcat(fname,".BMP");
                    else
                        strcat(fname,".TGA");

                    if (!(Flags & FLAGS_FORCEOVERWRITE)
                        && xf_exist(fname))
                    {
                        cout << "臼� Will overwrite " << fname << ", ok? (Y/n)";
                        cout.flush();
                        for(;;)
                        {
                            int i=getch();
                            cout << (char)i << "\n";

                            if (i == 'Y' || i == 'y' || i == 13)
                                break;
                            else if (i=='n' || i == 'N')
                                return 1;

                            break;
                        }
                    }

                    xf_remove(fname);

                    assert(tbld.bms[f] != 0);

                    if (tbld.bms[f]->bpp == 1 || tbld.bms[f]->bpp == 3)
                    {
                        XFParseBMP bmp(tbld.bms[f]);
                        if (bmp.namewrite(fname))
                        {
                            cout << "臼� Failed to write bitmap file\n";
                            return  1;
                        }
                    }
                    else
                    {
                        strcat(fname,".TGA");
                        XFParseTGA tga(tbld.bms[f]);
                        if (tga.namewrite(fname))
                        {
                            cout << "臼� Failed to write bitmap file\n";
                            return  1;
                        }
                    }

                    sprintf(buff,"  \"%s\"",fname);
                    if (xf.write(buff,strlen(buff)) != strlen(buff))
                    {
                        cout << "臼� Failed to write to CTF output file\n";
                        return  1;
                    }

                    f++;
                    if (f < tbld.nframes)
                    {
                        if (xf.write(",\r\n",sizeof(",\r\n")-1) != sizeof(",\r\n")-1)
                        {
                            cout << "臼� Failed to write to CTF output file\n";
                            return  1;
                        }
                    }
                    else
                        break;
                }

                if (xf.write("\r\n}\r\n\r\n",sizeof("}\r\n\r\n")-1) != sizeof("}\r\n\r\n")-1)
                {
                    cout << "臼� Failed to write to CTF output file\n";
                    return  1;
                }

                tbld.release(1);
            }
        }
        else if (iff.chunkid == iff.makeid('D','E','S','C')
                 || iff.chunkid == iff.makeid('(','C',')',' ')
                 || iff.chunkid == iff.makeid('A','U','T','H'))
        {
            ulong size = iff.chunkSize;
            if (!size)
            {
                cout << "臼� Zero-size extra chunk found\n";
            }

            char keyword[32];
            if (iff.chunkid == iff.makeid('D','E','S','C'))
            {
                strcpy(keyword,"description");
            }
            else if (iff.chunkid == iff.makeid('(','C',')',' '))
            {
                strcpy(keyword,"copyright");
            }
            else if (iff.chunkid == iff.makeid('A','U','T','H'))
            {
                strcpy(keyword,"author");
            }

            if (xf.write(keyword,strlen(keyword)) != strlen(keyword)
                || xf.write(" \"",sizeof(" \"")-1) != sizeof(" \"")-1)
            {
                cout << "臼� Failed to write to CTF output file\n";
                return 1;
            }

            if (size > 0)
            {
                char *work = new char[size];
                if (!work)
                {
                    cout << "臼� Out of memory during dump\n";
                    return 1;
                }

                if (iff.read(work))
                {
                    cout << "臼� Failed reading extra chunk\n";
                    return 1;
                }

                if (xf.write(work,size) != size)
                {
                    cout << "臼� Failed to write to CTF output file\n";
                    return 1;
                }

                delete [] work;
            }

            if (xf.write("\"\r\n",sizeof("\"\r\n")-1) != sizeof("\"\r\n")-1)
            {
                    cout << "臼� Failed to write to CTF output file\n";
                    return 1;
            }
        }
    }

    return 0;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// find_txtname                                                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int find_txtname(const char *n)
{
    if (!TxtNames)
        return 0;

    for(ulong i=0; i < TxtCount; i++)
    {
        if (!strncmp(&TxtNames[i*ESCH_MAX_NAME],n,ESCH_MAX_NAME))
            return 1;
    }

    return 0;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// add_txtname                                                              �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
int add_txtname(const char *n)
{
    if (!TxtNames)
    {
        TxtCount = 0;
        TxtMax = 4096 / ESCH_MAX_NAME;
        TxtNames = new char[TxtMax*ESCH_MAX_NAME];
        if (!TxtNames)
            return 1;
    }

    if (TxtCount >= TxtMax)
    {
        char *tmp = new char[TxtMax*2*ESCH_MAX_NAME];
        memcpy(tmp,TxtNames,TxtMax*ESCH_MAX_NAME);
        delete TxtNames;
        TxtNames = tmp;
        TxtMax *= 2;
    }

    strncpy(&TxtNames[TxtCount*ESCH_MAX_NAME],n,ESCH_MAX_NAME);
    TxtCount++;

    return 0;
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// Cleanup function.                                                        �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
STATIC void cleanup()
{
    if (TxtIFF)
    {
        delete TxtIFF;
        TxtIFF=0;
    }
    if (RmdrIFF)
    {
        delete RmdrIFF;
        RmdrIFF=0;
    }
    if (TxtNames)
    {
        delete TxtNames;
        TxtNames=0;
    }

    if (yyin)
        fclose(yyin);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// print_help                                                               �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
STATIC void print_help(int full)
{
    cout << Util_name;
    cout << "   Usage: eshtlib [-q] [-d] [-u] [-x] [-f]\n";
    cout << "          <filename.iff/.ctf> [ ... <filename.iff/.ctf> ]\n";
    cout << "          [-t <filename.pal/.vgp>]\n";
    cout << "          [-o <filename.iff/.ctf>] [-r <filename.iff>]\n";
    if (full)
    {
        cout << "\n          -q = Operate quietly\n";
        cout << "          -d = Dump IFF's textures to a CTF and bitmaps\n";
        cout << "          -u = Changes default to uncompressed for texture compiles\n";
        cout << "          -x = Changes default to transparent for texture compiles\n";
        cout << "          -f = Force overwrite (don't prompt for possible overwrite)\n";
        cout << "          -t = Specifies palette file (needed for dump)\n";
        cout << "          -o = Provide output filename for textures or dump target\n";
        cout << "          -r = Provide residual filename for texture processing\n";
    }
    cout << endl;
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
            cout << "not an IFF file error";
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
            cout << "invalid operation for FORM error";
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
            cout << "error " << (int)xp->error();
            break;
    }

    cout << "\n";
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// load_pal                                                                 �
//                                                                          �
//     Palette loader...                                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
STATIC int load_pal(VngoPal *pal,char *infile)
{
    int err;

    err = pal->init(0,infile);

    return(err);
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

//葦� End of module - eshtlib.cpp 憶�


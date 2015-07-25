//���������������������������������������������������������������������������
//                            
//           ^           **   **   **** ***** *    ****     ^      Take me to
//          (_)            * *     *      *   *    *       (_)    / your
//     ^                    *      **     *   *    **            ^  leader...
//    (_)       ^          * *     *      *   *    *            (_)
//             (_)       **   **   *    ***** **** ****
//
//            Copyright (c) 1994-1997 by Charybdis Enterprises, Inc.
//                             All Rights Reserved.
//                        Microsoft Windows '95 Version
//
//���������������������������������������������������������������������������
//
//           *** Charybdis Enterprises, Inc. Company Confidential ***
//
//  This file and all associated files are the company proprietary property
//        of Charybdis Enterprises, Inc.  Unauthorized use prohibited.
//
// CHARYBDIS ENTERPRISES, INC. MAKES NO WARRANTIES, EXPRESS OR IMPLIED, AS
// TO THE CORRECTNESS OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE
// IT.  CHARYBDIS ENTERPRISES, INC. PROVIDES THE CODE ON AN "AS-IS" BASIS
// AND EXPLICITLY DISCLAIMS ANY LIABILITY, INCLUDING CONSEQUENTIAL AND
// INCIDENTAL DAMAGES FOR ERRORS, OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//���������������������������������������������������������������������������
//
// Created by Chuck Walbourn
//
// xfini.hpp
//
// This contains an object for parsingg .INI-style files.  These
// are text-based data files with headings and subsections of the
// format:
//
//    [heading-name]
//    item=value
//
//���������������������������������������������������������������������������

#ifndef __XFINI_HPP
#define __XFINI_HPP    1

#ifdef __WATCOMC__
#pragma pack(1);
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

//���������������������������������������������������������������������������
//             
//                                Includes
//                                
//���������������������������������������������������������������������������

#include "xfbase.hpp"

//���������������������������������������������������������������������������
//
//                                Equates
//
//���������������������������������������������������������������������������

#define XF_MAX_ININAME  256     // Maximum size of item or section name.
#define XF_MAX_INIVALUE 1024    // Maximum size of a value

//���������������������������������������������������������������������������
//
//                                Classes
//
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// XFParseINI - INI reader/writer class.                                    �
//���������������������������������������������������������������������������
class XFParseINI
{
    XFileDisk xfile;

protected:
    XFile           *xf;

    xf_error_codes  errorn;

    ulong           buffsize;
    char            *buff;
    char            sectname[XF_MAX_ININAME];

    //��� Loads the internal buffer from the open file handle.
    xf_error_codes load(void);
   
    //��� Returns the start position in buffer for active section
    char *start(void);

    //��� Scans the buffer for the variable starting with 'start'.
    //��� 0 is returned if not found.
    char *find(char *ptr, const char *item);

public:
    //���������������������������������������������������������������������Ŀ
    // Constructor/Destructors                                              �
    //�����������������������������������������������������������������������
    XFParseINI();
    XFParseINI(XFile *f);

    ~XFParseINI();

    //���������������������������������������������������������������������Ŀ
    // Operations                                                           �
    //�����������������������������������������������������������������������
    xf_error_codes error() const { return errorn; };

    void attach(XFile *f) { xf = (f) ? f : &xfile; }

           //��������������������������������������������������������������Ŀ
           // Quick access functions for the XFile object embedded.         �
           //����������������������������������������������������������������
    xf_error_codes open(const char *name, dword flags)
    {
        xf_error_codes err=xf->open(name,flags|XF_OPEN_READ);
        if (!err)
        {
            return begin();
        }
        errorn=err;
        return err;
    }
    xf_error_codes create(const char *name, dword flags)
    {
        xf_error_codes err=xf->create(name,flags|XF_OPEN_READ);
        if (!err)
        {
            return begin();
        }
        errorn=err;
        return err;
    }
    xf_error_codes close(void)
    {
        end();
        xf_error_codes err=xf->close();
        if (err) errorn=err;
        return err;
    }

           //��������������������������������������������������������������Ŀ
           // These must be called if the XFile object is not opened/closed �
           // via the member functions for this object.                     �
           //����������������������������������������������������������������
    xf_error_codes begin(void);
    xf_error_codes end(void);

           //��������������������������������������������������������������Ŀ
           // Sets processing to the given named section.  If writing, and  �
           // the section doesn't exist, a new section is created.          �
           //����������������������������������������������������������������
    xf_error_codes section(const char *name);

           //��������������������������������������������������������������Ŀ
           // Reads an item=value pair from the file, using the current     �
           // section, if any set.                                          �
           //����������������������������������������������������������������
    xf_error_codes read(const char *item, char *value);
    xf_error_codes read(const char **item, char **value);
    int read(const char *item);

           //��������������������������������������������������������������Ŀ
           // Writes an item=value pair to the file, using the current      �
           // section, if any set.                                          �
           //����������������������������������������������������������������
    xf_error_codes write(const char *item, const char *value);
    xf_error_codes write(const char **item, const char **value);
    xf_error_codes write(const char *item, int value);
};

#ifdef __WATCOMC__
#pragma pack();
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif

//��� End of header - xfini.hpp ���

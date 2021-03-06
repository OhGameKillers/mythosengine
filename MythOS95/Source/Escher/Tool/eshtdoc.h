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
//                             *** Escher Tool ***
//
// Chuck Walbourn
//
// eshtdoc.h
//
// Escher Tool Document Class
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Classes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

class ToolDoc : public CDocument
{
protected: // create from serialization only
        ToolDoc();
        DECLARE_DYNCREATE(ToolDoc)

// Attributes
public:

    // Scene information
    char        name[ESCH_MAX_NAME];
    char        desc[256];
    char        auth[256];
    char        copy[256];

    ulong           ncameras;
    EschCameraEx    *cameras;

    ulong           nlights;
    EschLight       *lights;

    ulong           nmeshes;
    EschMeshDraw    *meshes;

    // Support data
    char            pfname[256];
    VngoPal         *palette;

    HPALETTE        hpal;

    enum
    {
        COMPRESS    =0x1,
        TRUECOLOR   =0x2,
        USE15BIT    =0x4,
        FLOATING    =0x8,
    };

    dword           flags;

// Operations
public:
    BOOL LoadPalette(const char *fname);
    void GetCounts(ulong *ncams,
                   ulong *nvlgts,
                   ushort *nfplgts, ushort *nfalgts, ushort *nfslgts,
                   ulong *nplgts, ushort *nalgts, ushort *nslgts,
                   ulong *nobjs);

// Overrides
        // ClassWizard generated virtual function overrides
        //{{AFX_VIRTUAL(ToolDoc)
        public:
        virtual BOOL OnNewDocument();
        virtual void DeleteContents();
        //}}AFX_VIRTUAL

// Implementation
public:
        virtual ~ToolDoc();
        virtual void Serialize(CArchive& ar);   // overridden for document i/o
#ifdef _DEBUG
        virtual void AssertValid() const;
        virtual void Dump(CDumpContext& dc) const;
#endif

protected:
    int count_mesh(EschMeshDraw *msh);
    esch_error_codes serialize_store_mesh(XFParseIFF *iff, EschMeshDraw *msh);

// Generated message map functions
protected:
        //{{AFX_MSG(ToolDoc)
        //}}AFX_MSG
        DECLARE_MESSAGE_MAP()
};

//葦� eof - eshtdoc.h 憶�

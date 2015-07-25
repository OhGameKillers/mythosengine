//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//�����������Copyright�(c)�1994-1996�by�Charybdis�Enterprises,�Inc.����������
//��������������������������All�Rights�Reserved.�����������������������������
//���������������������������������������������������������������������������
//��������������������� Microsoft Windows '95 Version �����������������������
//���������������������������������������������������������������������������
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
//                             *** Escher Tool ***
//
// Chuck Walbourn
//
// eshtmfrm.cpp
//
// Main window frame class.
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//             
//                                Includes
//                                
//���������������������������������������������������������������������������

#include "stdafx.h"
#include "eshtool.h"

#include "eshtmfrm.h"
#include "eshtdoc.h"
#include "eshtview.h"

//���������������������������������������������������������������������������
//
//                                 Data
//
//���������������������������������������������������������������������������

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

//�������������������������������������������������������������������������Ŀ
// ToolFrame                                                                �
//���������������������������������������������������������������������������

IMPLEMENT_DYNCREATE(ToolFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(ToolFrame, CFrameWnd)
	//{{AFX_MSG_MAP(ToolFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_FILE_PALETTE, OnFilePalette)
	ON_COMMAND(ID_APP_HELP, OnAppHelp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//�������������������������������������������������������������������������Ŀ
// Arrays of IDs used to initialize control bars                            �
//���������������������������������������������������������������������������
	
// toolbar buttons - IDs are command buttons
static UINT BASED_CODE buttons[] =
{
	// same order as in the bitmap 'toolbar.bmp'
	ID_FILE_NEW,
	ID_FILE_OPEN,
	ID_FILE_SAVE,
		ID_SEPARATOR,
    ID_FILE_PALETTE,
		ID_SEPARATOR,
	ID_EDIT_CUT,
	ID_EDIT_COPY,
	ID_EDIT_PASTE,
		ID_SEPARATOR,
    ID_VIEW_ROTXY,
    ID_VIEW_MOVEXY,
    ID_VIEW_ROTMOVEZ,
		ID_SEPARATOR,
    ID_MESH_ROTIJ,
    ID_MESH_MOVEIJ,
    ID_MESH_ROTMOVEK,
		ID_SEPARATOR,
    ID_LGT_ADJUSTXY,
    ID_LGT_ABRIGHT,
		ID_SEPARATOR,
	ID_APP_ABOUT,
};

static UINT BASED_CODE indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

//���������������������������������������������������������������������������
//
//                                 Code
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//������������������������� Constructor/Destructor ��������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// ToolFrame - Constructor                                                  �
//���������������������������������������������������������������������������
ToolFrame::ToolFrame()
{
}

//�������������������������������������������������������������������������Ŀ
// ToolFrame - Destructor                                                   �
//���������������������������������������������������������������������������
ToolFrame::~ToolFrame()
{
}



//���������������������������������������������������������������������������
//������������������������������� Diagnostics �������������������������������
//���������������������������������������������������������������������������

#ifdef _DEBUG
//�������������������������������������������������������������������������Ŀ
// ToolFrame - AssertValid                                                  �
//���������������������������������������������������������������������������
void ToolFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}


//�������������������������������������������������������������������������Ŀ
// ToolFrame - Dump                                                         �
//���������������������������������������������������������������������������
void ToolFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG



//���������������������������������������������������������������������������
//������������������������������� Operations ��������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// ToolFrame - OnIdle                                                       �
//���������������������������������������������������������������������������
void ToolFrame::OnIdle()
{   
    if (GetActiveView())
        ((ToolView*)GetActiveView())->OnIdle();
}



//���������������������������������������������������������������������������
//���������������������������� Message Handlers �����������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// ToolFrame - OnCreate                                                     �
//���������������������������������������������������������������������������
int ToolFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.Create(this) ||
		!m_wndToolBar.LoadBitmap(IDR_MAINFRAME) ||
		!m_wndToolBar.SetButtons(buttons,
		  sizeof(buttons)/sizeof(UINT)))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY);

	return 0;
}


//�������������������������������������������������������������������������Ŀ
// ToolFrame - OnFilePalette                                                �
//���������������������������������������������������������������������������
void ToolFrame::OnFilePalette() 
{
    ToolDoc *pDoc = (ToolDoc*)GetActiveDocument();
    ASSERT_VALID(pDoc);

    CFileDialog dlg(TRUE,
                    "PAL", pDoc->pfname,
                    OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY,
                    "Van Gogh palette file (*.vgp;*.pal)|*.VGP;*.PAL|All files (*.*)|*.*||",
                    this);

    dlg.m_ofn.lpstrTitle = "Van Gogh Palette File";

    if (dlg.DoModal() == IDOK)
    {
        if (!pDoc->LoadPalette(dlg.GetPathName()))
        {
            MessageBox("Reverting to previous palette file due to failed load","Van Gogh Palette File",
                       MB_OK | MB_ICONINFORMATION);
            pDoc->LoadPalette(pDoc->pfname);
        }
    }
}


//�������������������������������������������������������������������������Ŀ
// ToolFrame - OnAppHelp                                                    �
//���������������������������������������������������������������������������
void ToolFrame::OnAppHelp() 
{
    int     i;
    char    *c;
    char    fname[256];
  
    GetModuleFileName(NULL, fname, 256);

    for (i=strlen(fname), c = &fname[i-1]; i > 0; i--, c--)
    {
        if (*c == '\\')
        {
            strcpy(c+1,"MythOS.HLP");

            if (xf_exist(fname))
                break;
        }
    }
    if (!i)
        strcpy(fname,"MythOS.HLP");

    ::WinHelp(GetSafeHwnd(),
              fname,
              HELP_CONTEXT, 1000);
}

//��� eof - eshtmfrm.cpp ���

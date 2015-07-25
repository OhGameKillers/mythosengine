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
//������������������� Microsoft Windows 95/NT Version �����������������������
//���������������������������������������������������������������������������
//�����������Copyright�(c)�1994-1998�by�Charybdis�Enterprises,�Inc.����������
//��������������������������All�Rights�Reserved.�����������������������������
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
//                        *** Escher Terrain Editor ***
//
// Chuck Walbourn
//
// eshtmfrm.h
//
// Main window frame class.
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Classes
//
//���������������������������������������������������������������������������

class TerrMainFrame : public CFrameWnd
{
protected: // create from serialization only
	TerrMainFrame();
	DECLARE_DYNCREATE(TerrMainFrame)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(TerrMainFrame)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~TerrMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// Generated message map functions
protected:
	//{{AFX_MSG(TerrMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTerrProperties();
	afx_msg void OnTerrImport();
	afx_msg void OnSurfPalette();
	afx_msg void OnSurfImport();
	afx_msg void OnFileExport();
	afx_msg void OnSurfDefineTexture();
	afx_msg void OnSurfEditTexture();
	afx_msg void OnSurfDeleteTexture();
	afx_msg void OnAppHelp();
	afx_msg void OnSurfSaveTextures();
	afx_msg void OnUpdateSurfSaveTextures(CCmdUI* pCmdUI);
	afx_msg void OnUpdateSurfDeleteTexture(CCmdUI* pCmdUI);
	afx_msg void OnUpdateSurfEditTexture(CCmdUI* pCmdUI);
	afx_msg void OnSurfLoadTextures();
	afx_msg void OnSurfDefineColor();
	afx_msg void OnSurfDeleteColor();
	afx_msg void OnUpdateSurfDeleteColor(CCmdUI* pCmdUI);
	afx_msg void OnSurfEditColor();
	afx_msg void OnUpdateSurfEditColor(CCmdUI* pCmdUI);
	afx_msg void OnSurfLoadColors();
	afx_msg void OnSurfSaveColors();
	afx_msg void OnUpdateSurfSaveColors(CCmdUI* pCmdUI);
	afx_msg void OnTerrSetBaseElevation();
	afx_msg void OnSurfRemoveUnusedTxts();
	afx_msg void OnUpdateSurfRemoveUnusedTxts(CCmdUI* pCmdUI);
	afx_msg void OnFileFloating();
	afx_msg void OnUpdateFileFloating(CCmdUI* pCmdUI);
	afx_msg void OnFileCompress();
	afx_msg void OnUpdateFileCompress(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//��� eof - eshtmfrm.h ���


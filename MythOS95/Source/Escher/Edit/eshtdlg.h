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
//����������Copyright�(c)�1994,�1995�by�Charybdis�Enterprises,�Inc.����������
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
//                        *** Escher Terrain Editor ***
//
// Chuck Walbourn
//
// eshtdlg.h
//
// Terrain Editor Dialog Classes
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Equates
//
//���������������������������������������������������������������������������

#define EXPSTAT_HDR     0x1
#define EXPSTAT_HGTS    0x2
#define EXPSTAT_NRML    0x4
#define EXPSTAT_SURF    0x8
#define EXPSTAT_TXTS    0x10

//���������������������������������������������������������������������������
//
//                                Classes
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//������������������������ Terrain Properies Dialog �������������������������
//���������������������������������������������������������������������������


class TerrEditDoc;

//�������������������������������������������������������������������������Ŀ
// TerrPropDlgA                                                             �
//���������������������������������������������������������������������������

class TerrPropDlgA : public CPropertyPage
{
	DECLARE_DYNCREATE(TerrPropDlgA)

// Construction
public:
	TerrPropDlgA();   // standard constructor
    ~TerrPropDlgA();   // standard constructor

    int     m_edit;
    UINT    m_surfratio;

// Dialog Data
	//{{AFX_DATA(TerrPropDlgA)
	enum { IDD = IDD_TERRPROPA };
	CComboBox	m_surfratioCtl;
	CEdit	m_depthCtl;
	CEdit	m_widthCtl;
	UINT	m_width;
	UINT	m_depth;
	float	m_dscale;
	float	m_hscale;
	float	m_wscale;
	CString	m_name;
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(TerrPropDlgA)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(TerrPropDlgA)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


//�������������������������������������������������������������������������Ŀ
// TerrPropDlgB                                                             �
//���������������������������������������������������������������������������

class TerrPropDlgB : public CPropertyPage
{
	DECLARE_DYNCREATE(TerrPropDlgB)

// Construction
public:
	TerrPropDlgB();
	~TerrPropDlgB();

// Dialog Data
	//{{AFX_DATA(TerrPropDlgB)
	enum { IDD = IDD_TERRPROPB };
	CString	m_copy;
	CString	m_auth;
	CString	m_desc;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(TerrPropDlgB)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(TerrPropDlgB)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};



//���������������������������������������������������������������������������
//���������������������������� Camera Properties ����������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// CameraPropDlg                                                            �
//���������������������������������������������������������������������������

class CameraPropDlg : public CDialog
{
// Construction
public:
	CameraPropDlg(CWnd* pParent = NULL);   // standard constructor

    dword m_bcolor;

// Dialog Data
	//{{AFX_DATA(CameraPropDlg)
	enum { IDD = IDD_CAMPROP };
	float	m_fov;
	float	m_hither;
	float	m_xpos;
	float	m_yon;
	float	m_ypos;
	float	m_zpos;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CameraPropDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CameraPropDlg)
	afx_msg void OnBackgroundColor();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};



//���������������������������������������������������������������������������
//���������������������������� Surface Properties ���������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// SurfacePropDlg                                                           �
//���������������������������������������������������������������������������

class SurfacePropDlg : public CDialog
{
// Construction
public:
	SurfacePropDlg(TerrEditDoc *pd, CWnd* pParent = NULL);   // standard constructor

    int   m_edit;
    dword m_color;
    int   m_txt;

// Dialog Data
	//{{AFX_DATA(SurfacePropDlg)
	enum { IDD = IDD_SURFPROP };
	CButton	m_colorbutn;
	CComboBox	m_txtlist;
	BOOL	m_cbit1;
	BOOL	m_cbit2;
	BOOL	m_cbit3;
	BOOL	m_cbit4;
	UINT	m_dloc;
	UINT	m_xloc;
	int		m_fire;
	int		m_smoke;
	int		m_water;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SurfacePropDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
    TerrEditDoc *pDoc;

	// Generated message map functions
	//{{AFX_MSG(SurfacePropDlg)
	afx_msg void OnColor();
	afx_msg void OnTextureSelectChange();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};



//���������������������������������������������������������������������������
//���������������������������� Texture Properties ���������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// TexturePropDlg                                                           �
//���������������������������������������������������������������������������

class TexturePropDlg : public CDialog
{
// Construction
public:
	TexturePropDlg(TerrEditDoc *pd, int i=-1, CWnd* pParent = NULL);   // standard constructor

    dword m_color;

// Dialog Data
	//{{AFX_DATA(TexturePropDlg)
	enum { IDD = IDD_TEXTUREPROP };
	CString	m_name;
	CString	m_fname;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(TexturePropDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
    int iNDex;
    TerrEditDoc *pDoc;

	// Generated message map functions
	//{{AFX_MSG(TexturePropDlg)
	afx_msg void OnBrowse();
	afx_msg void OnColor();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};



//���������������������������������������������������������������������������
//��������������������������� Progress Dialogs ������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// TerrCNmPrgDlg                                                            �
//���������������������������������������������������������������������������

class TerrCNmPrgDlg : public CDialog
{
// Construction
public:
	TerrCNmPrgDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(TerrCNmPrgDlg)
	enum { IDD = IDD_COMPNRML };
	CProgressCtrl	m_pBar;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(TerrCNmPrgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(TerrCNmPrgDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


//�������������������������������������������������������������������������Ŀ
// TerrCScPrgDlg                                                            �
//���������������������������������������������������������������������������

class TerrCScPrgDlg : public CDialog
{
// Construction
public:
	TerrCScPrgDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(TerrCScPrgDlg)
	enum { IDD = IDD_COMPSCLRS };
	CProgressCtrl	m_pBar;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(TerrCScPrgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(TerrCScPrgDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


//�������������������������������������������������������������������������Ŀ
// TerrSurfPrgDlg                                                           �
//���������������������������������������������������������������������������

class TerrSurfPrgDlg : public CDialog
{
// Construction
public:
	TerrSurfPrgDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(TerrSurfPrgDlg)
	enum { IDD = IDD_SCANSURF };
	CProgressCtrl	m_pBar;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(TerrSurfPrgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(TerrSurfPrgDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};



//���������������������������������������������������������������������������
//��������������������������� Status Dialogs ��������������������������������
//���������������������������������������������������������������������������

//�������������������������������������������������������������������������Ŀ
// TerrExpStatDlg                                                           �
//���������������������������������������������������������������������������

class TerrExpStatDlg : public CDialog
{
// Construction
public:
	TerrExpStatDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(TerrExpStatDlg)
	enum { IDD = IDD_EXPORTSTAT };
	CStatic	m_txts;
	CStatic	m_surf;
	CStatic	m_nrml;
	CStatic	m_hgts;
	CStatic	m_hdr;
	//}}AFX_DATA

    dword   sflags;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(TerrExpStatDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(TerrExpStatDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};



//���������������������������������������������������������������������������
//���������������������������������������������������������������������������
//���������������������������������������������������������������������������

//��� eof - eshtdlg.h ���

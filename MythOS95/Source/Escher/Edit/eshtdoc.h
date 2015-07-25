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
// eshtdoc.h
//
// Terrain Editor Document class
//
// The document class owns the terrain height field, surface array, and
// the texture information.  The data may be manipulated or exported into
// an Escher IFF file.
//
//���������������������������������������������������������������������������

//���������������������������������������������������������������������������
//
//                                Classes
//
//���������������������������������������������������������������������������

class TerrEditDoc : public CDocument
{
protected: // create from serialization only
	TerrEditDoc();
	DECLARE_DYNCREATE(TerrEditDoc)

// Attributes
public:
    ushort          width;                  // Width of height field
    ushort          depth;                  // Depth of height field
    ushort          surfratio;              // Surface ratio (height : surface)
    ushort          surfshift;              // Shift value for surf ratio

    Flx16           wscale, dscale, hscale; // Scale factors
    
    byte            *hfield;                // Height field array
    esch_surf_type  *surfinfo;              // Surface array
    dword           *surfcolr;              // Surface RGB color array
    IvoryHandle     hsurfnorml;             // Lighting normal array

    char            name[ESCH_MAX_NAME];    // Name, etc.
    char            desc[256];
    char            auth[256];
    char            copy[256];

    int             txtNumb;                // Texture information
    CString         txtName[256];
    CString         txtFName[256];
    EschTexture     txtEsch[256];
    dword           txtColr[256];
    byte            txtColrIndx[256];

    char            pfname[256];            // Van Gogh palette
    VngoPal8        palette;
    HPALETTE        hpal;

// Operations
public:
    BOOL LoadPalette(const char *fname, int doupdate=1);
    void ImportTerrain(const char *fname, int losswarn=0);
    void ImportSurface(const char *fname, int losswarn=0);

    BOOL AddTexture(const char *name, const char *fname, dword color);
    BOOL SetTexture(int ind, const char *name, const char *fname, dword color);
    void DeleteTexture(int ind);

    void ExportToIFF(const char *fname);

    void ComputeNormals();

    void UITerrainProperities(CWnd *parent, UINT ipage=0, int edit=0);
    void UISurfProperties(CWnd *parent, UINT xpos, UINT dpos);
    void UISurfColor(CWnd *parent, UINT xpos, UINT dpos);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(TerrEditDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void DeleteContents();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~TerrEditDoc();
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
    void map_surfcolor_to_palette();
    BOOL load_and_recolor_texture(int ind, const char *fname);

// Generated message map functions
protected:
	//{{AFX_MSG(TerrEditDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//��� eof - eshtdoc.h ���


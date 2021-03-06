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
// eshtview.h
//
// Editor Tool view class.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include "eshtvp.h"
#include "eshttree.h"

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Equates
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#define MAX_VPORTS  1

#define VIEWID_ITREE        1
#define VIEWID_VP0          2
#define VIEWID_VP1          3
#define VIEWID_VP2          4
#define VIEWID_VP3          5

typedef enum _vport_mode {
    VPMODE_NONE                 =0,
    VPMODE_STANDARD             =1,
} vport_mode;

#define HINT_UPDATETREELIST     0x1
#define HINT_UPDATERENDER       0x2
#define HINT_UPDATECAMATTACH    0x4

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Classes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

class ToolView
: public CView
{
protected: // create from serialization only
        ToolView();
        DECLARE_DYNCREATE(ToolView)

// Attributes
public:
        ToolDoc* GetDocument();

// Operations
public:
    vport_mode  vpmode;
    void OnIdle();
    void EditProperties();

// Overrides
        // ClassWizard generated virtual function overrides
        //{{AFX_VIRTUAL(ToolView)
        public:
        virtual void OnDraw(CDC* pDC);  // overridden to draw this view
        virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
        virtual void OnInitialUpdate();
        protected:
        virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
        virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
        //}}AFX_VIRTUAL

// Implementation
public:
        virtual ~ToolView();
#ifdef _DEBUG
        virtual void AssertValid() const;
        virtual void Dump(CDumpContext& dc) const;
#endif

protected:
    ToolTree    iTree;
    ToolVPort   wVp[MAX_VPORTS];

    BOOL ui_scene_properties(int doupdate=1);
    BOOL ui_camera_properties(EschCameraEx *cam, int doupdate=1);
    BOOL ui_light_properties(EschLight **lgt, int doupdate=1, int edittype=0);
    BOOL ui_mesh_properties(EschMeshDraw *msh, int doupdate=1);

// Generated message map functions
protected:
        //{{AFX_MSG(ToolView)
        afx_msg void OnSize(UINT nType, int cx, int cy);
        afx_msg void OnViewRndWireframe();
        afx_msg void OnUpdateViewRndWireframe(CCmdUI* pCmdUI);
        afx_msg void OnViewRndSolid();
        afx_msg void OnUpdateViewRndSolid(CCmdUI* pCmdUI);
        afx_msg void OnViewRndFlat();
        afx_msg void OnUpdateViewRndFlat(CCmdUI* pCmdUI);
        afx_msg void OnViewRndSmooth();
        afx_msg void OnUpdateViewRndSmooth(CCmdUI* pCmdUI);
        afx_msg void OnViewRndSpecular();
        afx_msg void OnUpdateViewRndSpecular(CCmdUI* pCmdUI);
        afx_msg void OnViewRndBackface();
        afx_msg void OnUpdateViewRndBackface(CCmdUI* pCmdUI);
        afx_msg void OnViewRndTextures();
        afx_msg void OnUpdateViewRndTextures(CCmdUI* pCmdUI);
        afx_msg void OnViewRndPerspective();
        afx_msg void OnUpdateViewRndPerspective(CCmdUI* pCmdUI);
        afx_msg void OnEditProperties();
        afx_msg void OnUpdateEditProperties(CCmdUI* pCmdUI);
        afx_msg void OnViewRndShowAllLines();
        afx_msg void OnUpdateViewRndShowAllLines(CCmdUI* pCmdUI);
        afx_msg void OnEditDelete();
        afx_msg void OnUpdateEditDelete(CCmdUI* pCmdUI);
        afx_msg void OnViewRefresh();
        afx_msg void OnViewRotateXY();
        afx_msg void OnUpdateViewRotateXY(CCmdUI* pCmdUI);
        afx_msg void OnViewMoveXY();
        afx_msg void OnUpdateViewMoveXY(CCmdUI* pCmdUI);
        afx_msg void OnViewRotateMoveZ();
        afx_msg void OnUpdateViewRotateMoveZ(CCmdUI* pCmdUI);
        afx_msg void OnMeshMoveIJ();
        afx_msg void OnUpdateMeshMoveIJ(CCmdUI* pCmdUI);
        afx_msg void OnUpdateMeshRotateIJ(CCmdUI* pCmdUI);
        afx_msg void OnMeshRotateIJ();
        afx_msg void OnMeshRotateMoveK();
        afx_msg void OnUpdateMeshRotateMoveK(CCmdUI* pCmdUI);
        afx_msg void OnLightAdjustXY();
        afx_msg void OnUpdateLightAdjustXY(CCmdUI* pCmdUI);
        afx_msg void OnUpdateLightIntensity(CCmdUI* pCmdUI);
        afx_msg void OnLightIntensity();
        afx_msg void OnViewAttachCamera();
        afx_msg void OnUpdateViewAttachCamera(CCmdUI* pCmdUI);
        afx_msg void OnEditNewCamera();
        afx_msg void OnEditNewLight();
        afx_msg void OnViewAutoRotateX();
        afx_msg void OnUpdateViewAutoRotateX(CCmdUI* pCmdUI);
        afx_msg void OnViewAutoRotateY();
        afx_msg void OnUpdateViewAutoRotateY(CCmdUI* pCmdUI);
        afx_msg void OnViewAutoRotateZ();
        afx_msg void OnUpdateViewAutoRotateZ(CCmdUI* pCmdUI);
        afx_msg void OnViewAutoRotateFast();
        afx_msg void OnUpdateViewAutoRotateFast(CCmdUI* pCmdUI);
        afx_msg void OnViewAutoRotateSlow();
        afx_msg void OnUpdateViewAutoRotateSlow(CCmdUI* pCmdUI);
        afx_msg void OnViewAutoRotateOff();
        afx_msg void OnViewRndModelSpace();
        afx_msg void OnUpdateViewRndModelSpace(CCmdUI* pCmdUI);
        afx_msg void OnViewShowBoxExtents();
        afx_msg void OnViewShowSphereExtents();
        afx_msg void OnUpdateViewShowSphereExtents(CCmdUI* pCmdUI);
        afx_msg void OnUpdateViewShowBoxExtents(CCmdUI* pCmdUI);
        afx_msg void OnUpdateViewRndSort(CCmdUI* pCmdUI);
        afx_msg void OnViewRndSort();
        afx_msg void OnViewRndAlpha();
        afx_msg void OnUpdateViewRndAlpha(CCmdUI* pCmdUI);
        afx_msg void OnViewRndOrtho();
        afx_msg void OnUpdateViewRndOrtho(CCmdUI* pCmdUI);
        //}}AFX_MSG
        DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in eshtview.cpp
inline ToolDoc* ToolView::GetDocument()
   { return (ToolDoc*)m_pDocument; }
#endif

//葦� eof - eshtview.h 憶�

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
//                        *** Escher Terrain Editor ***
//
// Created by Chuck Walbourn
//
// eshtview.cpp
//
// Terrain View class
//
// The view class handles the display of the data contained in an
// TerrEditDoc class.
//
//様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//
//                                Includes
//
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

#include "stdafx.h"
#include "eshtedit.h"

#include "eshtdoc.h"
#include "eshtview.h"
#include "eshtmfrm.h"
#include "eshtdlgx.h"

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Data
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView                                                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
IMPLEMENT_DYNCREATE(TerrEditView, CView)

BEGIN_MESSAGE_MAP(TerrEditView, CView)
        //{{AFX_MSG_MAP(TerrEditView)
        ON_WM_SIZE()
        ON_COMMAND(ID_VIEW_RENDER, OnViewRender)
        ON_COMMAND(ID_VIEW_RND_DOTS, OnViewRndDots)
        ON_COMMAND(ID_VIEW_RND_WIREFRAME, OnViewRndWireframe)
        ON_COMMAND(ID_VIEW_RND_SOLID, OnViewRndSolid)
        ON_COMMAND(ID_VIEW_RND_FLAT, OnViewRndFlat)
        ON_COMMAND(ID_VIEW_RND_SMOOTH, OnViewRndSmooth)
        ON_COMMAND(ID_VIEW_RND_SPECULAR, OnViewRndSpecular)
        ON_COMMAND(ID_VIEW_RND_BACKFACE, OnViewRndBackface)
        ON_COMMAND(ID_VIEW_RND_TEXTURES, OnViewRndTextures)
        ON_COMMAND(ID_VIEW_REFRESH, OnViewRefresh)
        ON_COMMAND(ID_VIEW_RND_PERSPECTIVE, OnViewRndPerspective)
        ON_COMMAND(ID_VIEW_ROTXY, OnViewRotateXY)
        ON_COMMAND(ID_VIEW_MOVEXY, OnViewMoveXY)
        ON_COMMAND(ID_VIEW_ROTMOVEZ, OnViewRotateMoveZ)
        ON_COMMAND(ID_LGT_ADJUSTXY, OnLightAdjustXY)
        ON_COMMAND(ID_LGT_ABRIGHT, OnLightAdjustIntensity)
        ON_COMMAND(ID_VIEW_ZOOM_NORM, OnViewZoomNormal)
        ON_COMMAND(ID_VIEW_ZOOM_LARGE, OnViewZoomLarge)
        ON_COMMAND(ID_VIEW_ZOOM_MED, OnViewZoomMedium)
        ON_COMMAND(ID_VIEW_ZOOM_XLARGE, OnViewZoomExLarge)
        ON_COMMAND(ID_VIEW_PROP, OnViewProperties)
        ON_COMMAND(ID_VIEW_ZOOM_MEGA, OnViewZoomMega)
        ON_UPDATE_COMMAND_UI(ID_VIEW_RENDER, OnUpdateViewRender)
        ON_UPDATE_COMMAND_UI(ID_VIEW_ROTXY, OnUpdateViewRotateXY)
        ON_UPDATE_COMMAND_UI(ID_VIEW_MOVEXY, OnUpdateViewMoveXY)
        ON_UPDATE_COMMAND_UI(ID_VIEW_ROTMOVEZ, OnUpdateViewRotateMoveZ)
        ON_UPDATE_COMMAND_UI(ID_VIEW_PROP, OnUpdateViewProperties)
        ON_UPDATE_COMMAND_UI(ID_VIEW_ZOOM_NORM, OnUpdateViewZoomNormal)
        ON_UPDATE_COMMAND_UI(ID_VIEW_ZOOM_MED, OnUpdateViewZoomMedium)
        ON_UPDATE_COMMAND_UI(ID_VIEW_ZOOM_LARGE, OnUpdateViewZoomLarge)
        ON_UPDATE_COMMAND_UI(ID_VIEW_ZOOM_XLARGE, OnUpdateViewZoomExLarge)
        ON_UPDATE_COMMAND_UI(ID_VIEW_ZOOM_MEGA, OnUpdateViewZoomMega)
        ON_UPDATE_COMMAND_UI(ID_VIEW_RND_DOTS, OnUpdateViewRndDots)
        ON_UPDATE_COMMAND_UI(ID_VIEW_RND_WIREFRAME, OnUpdateViewRndWireframe)
        ON_UPDATE_COMMAND_UI(ID_VIEW_RND_SOLID, OnUpdateViewRndSolid)
        ON_UPDATE_COMMAND_UI(ID_VIEW_RND_FLAT, OnUpdateViewRndFlat)
        ON_UPDATE_COMMAND_UI(ID_VIEW_RND_SMOOTH, OnUpdateViewRndSmooth)
        ON_UPDATE_COMMAND_UI(ID_VIEW_RND_SPECULAR, OnUpdateViewRndSpecular)
        ON_UPDATE_COMMAND_UI(ID_VIEW_RND_BACKFACE, OnUpdateViewRndBackface)
        ON_UPDATE_COMMAND_UI(ID_VIEW_RND_TEXTURES, OnUpdateViewRndTextures)
        ON_UPDATE_COMMAND_UI(ID_VIEW_RND_PERSPECTIVE, OnUpdateViewRndPerspective)
        ON_UPDATE_COMMAND_UI(ID_LGT_ABRIGHT, OnUpdateLightAdjustIntensity)
        ON_UPDATE_COMMAND_UI(ID_LGT_ADJUSTXY, OnUpdateLightAdjustXY)
        ON_COMMAND(ID_EDIT_UNDO, OnEditUndo)
        ON_UPDATE_COMMAND_UI(ID_EDIT_UNDO, OnUpdateEditUndo)
        ON_COMMAND(ID_VIEW_HOVER, OnViewHover)
        ON_UPDATE_COMMAND_UI(ID_VIEW_HOVER, OnUpdateViewHover)
        ON_COMMAND(ID_LGT_PROP, OnLightProperties)
        ON_UPDATE_COMMAND_UI(ID_LGT_PROP, OnUpdateLightProperties)
        ON_UPDATE_COMMAND_UI(ID_VIEW_SHOW_COLORS, OnUpdateViewShowColors)
        ON_COMMAND(ID_VIEW_SHOW_COLORS, OnViewShowColors)
        ON_UPDATE_COMMAND_UI(ID_VIEW_SHOW_SHADED, OnUpdateViewShowShaded)
        ON_COMMAND(ID_VIEW_SHOW_SHADED, OnViewShowShaded)
        ON_UPDATE_COMMAND_UI(ID_VIEW_SHOW_TXTONLY, OnUpdateViewShowTexturesOnly)
        ON_COMMAND(ID_VIEW_SHOW_TXTONLY, OnViewShowTexturesOnly)
        ON_UPDATE_COMMAND_UI(ID_VIEW_SHOW_HGT, OnUpdateViewShowHeight)
        ON_COMMAND(ID_VIEW_SHOW_HGT, OnViewShowHeight)
        ON_COMMAND(ID_EDIT_FLIPH, OnEditFlipHorizontal)
        ON_COMMAND(ID_EDIT_FLIPV, OnEditFlipVertical)
        ON_COMMAND(ID_EDIT_ROT90, OnEditRotate90)
        ON_COMMAND(ID_EDIT_ROTN90, OnEditRotateNegative90)
        ON_COMMAND(ID_EDIT_ASSIGN_HEIGHT, OnEditAssignByHeight)
        ON_UPDATE_COMMAND_UI(ID_EDIT_ASSIGN_HEIGHT, OnUpdateEditAssignByHeight)
        ON_COMMAND(ID_EDIT_ASSIGN_ROLL, OnEditAssignByRandomRoll)
        ON_UPDATE_COMMAND_UI(ID_EDIT_ASSIGN_ROLL, OnUpdateEditAssignByRandomRoll)
        ON_COMMAND(ID_VIEW_SHOW_APP, OnViewShowAppBits)
        ON_UPDATE_COMMAND_UI(ID_VIEW_SHOW_APP, OnUpdateViewShowAppBits)
        ON_COMMAND(ID_EDIT_ASSIGN_ANGLE, OnEditAssignByAngle)
        ON_UPDATE_COMMAND_UI(ID_EDIT_ASSIGN_ANGLE, OnUpdateEditAssignByAngle)
        //}}AFX_MSG_MAP
END_MESSAGE_MAP()

//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�
//
//                                 Code
//
//臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼臼�

//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭� Constructor/Destructor 旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - Constructor                                               �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
TerrEditView::TerrEditView() :
    gridright(0),
    rendertop(0),
    displayrender(1)
{
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - Destructor                                                �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
TerrEditView::~TerrEditView()
{
    if (txtList.m_hWnd)
        txtList.DestroyWindow();
    if (colorList.m_hWnd)
        colorList.DestroyWindow();
    if (grid.m_hWnd)
        grid.DestroyWindow();
    if (rend.m_hWnd)
        rend.DestroyWindow();
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭� Diagnostics 旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - AssertValid                                               �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
#ifdef _DEBUG
void TerrEditView::AssertValid() const
{
        CView::AssertValid();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - Dump                                                      �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::Dump(CDumpContext& dc) const
{
        CView::Dump(dc);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - GetDocument                                               �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
TerrEditDoc* TerrEditView::GetDocument() // non-debug version is inline
{
        ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(TerrEditDoc)));
        return (TerrEditDoc*)m_pDocument;
}
#endif //_DEBUG



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭� Operations 旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - Create                                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
BOOL TerrEditView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName,
                          DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
//陳� Create base window
    if (!CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext))
        return FALSE;

    CRect rectT;
    rectT.SetRectEmpty();

//陳� Create listbox for textures
    if (!txtList.Create( WS_CHILD
                         | WS_CAPTION
                         | WS_BORDER
                         | WS_CLIPSIBLINGS
                         | WS_VSCROLL
                         | LBS_NOINTEGRALHEIGHT
                         | LBS_DISABLENOSCROLL
                         | LBS_USETABSTOPS, rectT,
                         this,
                         1))
    {
        DestroyWindow();
        return FALSE;
    }
    txtList.SetWindowText("Texture Definitions");
    txtList.ShowWindow(SW_SHOW);



//陳� Create listbox for textures
    if (!colorList.Create( WS_CHILD
                         | WS_CAPTION
                         | WS_BORDER
                         | WS_CLIPSIBLINGS
                         | WS_VSCROLL
                         | LBS_NOINTEGRALHEIGHT
                         | LBS_DISABLENOSCROLL
                         | LBS_USETABSTOPS, rectT,
                         this,
                         1))
    {
        DestroyWindow();
        return FALSE;
    }
    colorList.SetWindowText("Color Definitions");
    colorList.ShowWindow(SW_SHOW);




//陳� Create child window for terrain grid
    if (!grid.Create(NULL,
                     "Surface Information Grid",
                     WS_CHILD
                     | WS_BORDER
                     | WS_CAPTION
                     | WS_CLIPSIBLINGS
                     | WS_VISIBLE
                     | WS_HSCROLL
                     | WS_VSCROLL,
                     rectT,
                     this,
                     2))
    {
        txtList.DestroyWindow();
        colorList.DestroyWindow();
        DestroyWindow();
        return FALSE;
    }

//陳� Create child window for render view
    if (!rend.Create(NULL,
                     "Render View",
                     WS_CHILD
                     | WS_BORDER
                     | WS_CAPTION
                     | WS_CLIPSIBLINGS
                     | WS_VISIBLE
                     | WS_HSCROLL
                     | WS_VSCROLL,
                     rectT,
                     this,
                     2))
    {
        txtList.DestroyWindow();
        colorList.DestroyWindow();
        grid.DestroyWindow();
        DestroyWindow();
        return FALSE;
    }

    return TRUE;
}



//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭 Message Handlers 旭旭旭旭旭旭旭旭旭旭旭旭旭旭�
//旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭旭�

//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - OnDraw                                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnDraw(CDC* pDC)
{
    // This window is just a parent for the data windows
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - OnInitialUpdate                                           �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnInitialUpdate()
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

//陳� Setup grid window
    grid.pal = &pDoc->palette;
    grid.SetZoomLevel(0);
    grid.SetMode(SURFDSP_COLORS);

//陳� Setup render window
    rend.pal = &pDoc->palette;
    rend.terr.flags = ESCH_TRN_DOTS;
    rend.SetMode(RNDCTRL_ROTATEXY);

        CView::OnInitialUpdate();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - OnUpdate                                                  �
//                                                                          �
// Hit values: 0 - update all data                                          �
//             otherwise bitmask of sections to update                      �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

//陳� Update terrain info
    if (!lHint || (lHint & HINT_UPDATETERR))
    {
        rend.terr.width = pDoc->width;
        rend.terr.depth = pDoc->depth;
        rend.terr.surfratio = pDoc->surfratio;
        rend.terr.surfshift = pDoc->surfshift;
        rend.terr.set_scale(pDoc->scale);
        rend.terr.hfield = pDoc->hfield;
        rend.terr.htable = pDoc->htable;
        rend.terr.surfinfo = pDoc->surfinfo;
        rend.terr.hsurfnorml = pDoc->hsurfnorml;
        rend.terr.set_origin(pDoc->orgx, pDoc->orgy, pDoc->orgz);
        rend.terr.set_lod(3, pDoc->lod_medium, pDoc->lod_low);
        rend.terr.set_texture_lod(3);
        rend.terr.set_perspective_lod(0);
        rend.terr.set_smooth_lod(3);
        rend.terr.set_start_lod(0);

        rend.terr.flags &= ~ESCH_TRN_LOD;
        if (pDoc->lod_active)
            rend.terr.flags |= ESCH_TRN_LOD;

        grid.SetSurfaceSize(pDoc->width >> pDoc->surfshift, pDoc->depth >> pDoc->surfshift);
    }

//陳� Update texture list
    if (!lHint || (lHint & HINT_UPDATETXTS))
    {
        txtList.UpdateContents();
        colorList.UpdateContents();

        rend.terr.tmax = pDoc->txtNumb;
        rend.terr.txtcolor = pDoc->txtColrIndx;
        rend.terr.txt = pDoc->txtEsch;
    }

//陳� If lights changed, reset camera mode
    if (!lHint || (lHint & HINT_UPDATELIGHTS))
    {
        rend.SetMode(rend.GetMode());
    }

//陳� Update terrain surface colors
    if (!lHint || (lHint & (HINT_UPDATECOLR|HINT_UPDATELIGHTS)))
    {
        grid.UpdateSurfaceColors();

        if (grid.m_hWnd)
            grid.Invalidate();
    }

    if (!lHint || (lHint & (HINT_UPDATECLRLIST)))
    {
        txtList.SetCurSel(-1);
    }

    if (!lHint || (lHint & (HINT_UPDATETXTLIST)))
    {
        colorList.SetCurSel(-1);
    }


//陳� Handle update of render view
    if (rend.m_hWnd && displayrender)
    {
        rend.UpdateRender();
        rend.Invalidate();
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - OnSize                                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnSize(UINT nType, int cx, int cy)
{
    cx &= ~0x3;

    rendertop = cy / 2;
    gridright = cx - ((rendertop * 4) / 3);
    gridright &= ~0x3;
    gridright += GetSystemMetrics(SM_CXBORDER)*2;
    textureright = gridright + ((cx - gridright)/2);

    if (txtList.m_hWnd)
        txtList.MoveWindow(gridright, 0, (cx - gridright)/2, (displayrender) ? rendertop : cy);

    if (colorList.m_hWnd)
        colorList.MoveWindow(textureright, 0, (cx - gridright)/2, (displayrender) ? rendertop : cy);

    if (grid.m_hWnd)
        grid.MoveWindow(0, 0, gridright, cy);

    if (rend.m_hWnd)
        rend.MoveWindow(gridright, rendertop, cx - gridright, cy - rendertop);

        CView::OnSize(nType, cx, cy);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - On(Update)EditUndo                                        �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnEditUndo()
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    pDoc->PopUndo();
}

void TerrEditView::OnUpdateEditUndo(CCmdUI* pCmdUI)
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    pCmdUI->Enable(pDoc->undo_valid ? 1 : 0);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - OnEditFlipHorizontal                                      �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnEditFlipHorizontal()
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    pDoc->Flip(TRUE);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - OnEditFlipVertical                                        �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnEditFlipVertical()
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    pDoc->Flip(FALSE);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - OnEditRotate90                                            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnEditRotate90()
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    pDoc->Rotate(TRUE);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - OnEditRotateNegative90                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnEditRotateNegative90()
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    pDoc->Rotate(FALSE);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - On(Update)EditAssignByHeight                              �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnEditAssignByHeight()
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    HeightToolDlg   dlg;
    dlg.setup(pDoc);

    if (dlg.DoModal()==IDCANCEL)
        return;

    ASSERT(dlg.count > 0);
    grid.AssignByHeight(dlg.count,
                        dlg.tc, dlg.istxt, dlg.heights,
                        dlg.m_height_stop,
                        dlg.area, dlg.m_preserve);
}

void TerrEditView::OnUpdateEditAssignByHeight(CCmdUI* pCmdUI)
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    pCmdUI->Enable( (pDoc->txtNumb+pDoc->colorNumb > 0) ? 1 : 0 );
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - On(Update)EditAssignByRandomRoll                          �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnEditAssignByRandomRoll()
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    RandomToolDlg   dlg;
    dlg.setup(pDoc);

    if (dlg.DoModal()==IDCANCEL)
        return;

    ASSERT(dlg.count > 0);
    grid.AssignByRandomRoll(dlg.count,
                            dlg.tc, dlg.istxt, dlg.chances,
                            dlg.m_elvcutoff,
                            dlg.m_elvlow, dlg.m_elvhigh,
                            dlg.area, dlg.m_preserve);
}

void TerrEditView::OnUpdateEditAssignByRandomRoll(CCmdUI* pCmdUI)
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    pCmdUI->Enable( (pDoc->txtNumb+pDoc->colorNumb > 0) ? 1 : 0 );
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - On(Update)EditAssignByAngle                               �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnEditAssignByAngle()
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    AngleToolDlg   dlg;
    dlg.setup(pDoc);

    if (dlg.DoModal()==IDCANCEL)
        return;

    ASSERT(dlg.count > 0);
    grid.AssignByAngle(dlg.count,
                       dlg.tc, dlg.istxt, dlg.angles,
                       dlg.m_angle_stop,
                       dlg.m_elvcutoff,
                       dlg.m_elvlow, dlg.m_elvhigh,
                       dlg.area, dlg.m_preserve);
}

void TerrEditView::OnUpdateEditAssignByAngle(CCmdUI* pCmdUI)
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    pCmdUI->Enable( (pDoc->txtNumb+pDoc->colorNumb > 0) ? 1 : 0 );
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - OnViewRefresh                                             �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnViewRefresh()
{
    txtList.RedrawWindow();
    colorList.RedrawWindow();

    grid.UpdateSurfaceColors();
    grid.RedrawWindow();

    if (displayrender)
    {
        rend.UpdateRender();
        rend.RedrawWindow();
    }
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - On(Update)ViewRender                                      �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnUpdateViewRender(CCmdUI* pCmdUI)
{
    pCmdUI->SetCheck(displayrender);
}

void TerrEditView::OnViewRender()
{
    displayrender = !displayrender;

    if (displayrender)
        rend.UpdateRender();
    rend.ShowWindow((displayrender) ? SW_SHOW : SW_HIDE);

    CRect rect;
    GetClientRect(&rect);
    int cx = rect.right - rect.left + 1;
    int cy = rect.bottom - rect.top + 1;

//    txtList.MoveWindow(gridright, 0, rect.right - gridright, (displayrender) ? rendertop : rect.bottom);
    txtList.MoveWindow(gridright, 0, (cx - gridright)/2, (displayrender) ? rendertop : cy);

    colorList.MoveWindow(textureright, 0, (cx - gridright)/2, (displayrender) ? rendertop : cy);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - On(Update)ViewHover                                       �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnUpdateViewHover(CCmdUI* pCmdUI)
{
    pCmdUI->SetCheck((rend.GetMode() == RNDCTRL_HOVER) ? 1 : 0);
    pCmdUI->Enable(displayrender);
}

void TerrEditView::OnViewHover()
{
    rend.SetMode(RNDCTRL_HOVER);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - On(Update)ViewRotateXY                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnUpdateViewRotateXY(CCmdUI* pCmdUI)
{
    pCmdUI->SetCheck((rend.GetMode() == RNDCTRL_ROTATEXY) ? 1 : 0);
    pCmdUI->Enable(displayrender);
}

void TerrEditView::OnViewRotateXY()
{
    rend.SetMode(RNDCTRL_ROTATEXY);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - On(Update)ViewMoveXY                                      �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnUpdateViewMoveXY(CCmdUI* pCmdUI)
{
    pCmdUI->SetCheck((rend.GetMode() == RNDCTRL_MOVEXY) ? 1 : 0);
    pCmdUI->Enable(displayrender);
}

void TerrEditView::OnViewMoveXY()
{
    rend.SetMode(RNDCTRL_MOVEXY);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - On(Update)ViewRotateMoveZ                                 �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnUpdateViewRotateMoveZ(CCmdUI* pCmdUI)
{
    pCmdUI->SetCheck((rend.GetMode() == RNDCTRL_ROTMOVEZ) ? 1 : 0);
    pCmdUI->Enable(displayrender);
}

void TerrEditView::OnViewRotateMoveZ()
{
    rend.SetMode(RNDCTRL_ROTMOVEZ);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - On(Update)ViewProperties                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnUpdateViewProperties(CCmdUI* pCmdUI)
{
    pCmdUI->Enable(displayrender);
}

void TerrEditView::OnViewProperties()
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    pDoc->UICameraProperties(this);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - On(Update)ViewZoomNormal                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnUpdateViewZoomNormal(CCmdUI* pCmdUI)
{
    pCmdUI->SetCheck((grid.GetZoomLevel() == 0) ? 1 : 0);
}

void TerrEditView::OnViewZoomNormal()
{
    grid.SetZoomLevel(0);
    grid.RedrawWindow();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - On(Update)ViewZoomMedium                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnUpdateViewZoomMedium(CCmdUI* pCmdUI)
{
    pCmdUI->SetCheck((grid.GetZoomLevel() == 1) ? 1 : 0);
}

void TerrEditView::OnViewZoomMedium()
{
    grid.SetZoomLevel(1);
    grid.RedrawWindow();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - On(Update)ViewZoomLarge                                   �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnUpdateViewZoomLarge(CCmdUI* pCmdUI)
{
    pCmdUI->SetCheck((grid.GetZoomLevel() == 2) ? 1 : 0);
}

void TerrEditView::OnViewZoomLarge()
{
    grid.SetZoomLevel(2);
    grid.RedrawWindow();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - On(Update)ViewZoomExLarge                                 �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnUpdateViewZoomExLarge(CCmdUI* pCmdUI)
{
    pCmdUI->SetCheck((grid.GetZoomLevel() == 3) ? 1 : 0);
}

void TerrEditView::OnViewZoomExLarge()
{
    grid.SetZoomLevel(3);
    grid.RedrawWindow();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - On(Update)ViewZoomMega                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnUpdateViewZoomMega(CCmdUI* pCmdUI)
{
    pCmdUI->SetCheck((grid.GetZoomLevel() == 4) ? 1 : 0);
}

void TerrEditView::OnViewZoomMega()
{
    grid.SetZoomLevel(4);
    grid.RedrawWindow();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - On(Update)ViewShowColors                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnUpdateViewShowColors(CCmdUI* pCmdUI)
{
    pCmdUI->SetCheck((grid.GetMode() == SURFDSP_COLORS) ? 1 : 0);
}

void TerrEditView::OnViewShowColors()
{
    grid.SetMode(SURFDSP_COLORS);
    grid.RedrawWindow();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - On(Update)ViewShowShaded                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnUpdateViewShowShaded(CCmdUI* pCmdUI)
{
    pCmdUI->SetCheck((grid.GetMode() == SURFDSP_SHADED) ? 1 : 0);
}

void TerrEditView::OnViewShowShaded()
{
    grid.SetMode(SURFDSP_SHADED);
    grid.RedrawWindow();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - On(Update)ViewShowHeight                                  �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnUpdateViewShowHeight(CCmdUI* pCmdUI)
{
    pCmdUI->SetCheck((grid.GetMode() == SURFDSP_HGT) ? 1 : 0);
}

void TerrEditView::OnViewShowHeight()
{
    grid.SetMode(SURFDSP_HGT);
    grid.RedrawWindow();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - On(Update)ViewShowTexturesOnly                            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnUpdateViewShowTexturesOnly(CCmdUI* pCmdUI)
{
    pCmdUI->SetCheck((grid.GetMode() == SURFDSP_TXTONLY) ? 1 : 0);
}

void TerrEditView::OnViewShowTexturesOnly()
{
    grid.SetMode(SURFDSP_TXTONLY);
    grid.RedrawWindow();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - On(Update)ViewShowAppBits                                 �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnUpdateViewShowAppBits(CCmdUI* pCmdUI)
{
    pCmdUI->SetCheck((grid.GetMode() == SURFDSP_APPBITS) ? 1 : 0);
}

void TerrEditView::OnViewShowAppBits()
{
    grid.SetMode(SURFDSP_APPBITS);
    grid.RedrawWindow();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - On(Update)ViewRndDots                                     �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnUpdateViewRndDots(CCmdUI* pCmdUI)
{
        pCmdUI->SetCheck((rend.terr.flags & ESCH_TRN_DOTS) ? 1 : 0);
    pCmdUI->Enable(displayrender);
}

void TerrEditView::OnViewRndDots()
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    rend.terr.flags |= ESCH_TRN_DOTS;

    pDoc->cam.flags &= ~(ESCH_CAM_SHADE_SPECULAR
                         | ESCH_CAM_SHADE_SMOOTH);
    pDoc->cam.flags |= ESCH_CAM_SHADE_WIRE
                       | ESCH_CAM_SHADE_SOLID
                       | ESCH_CAM_SHADE_FLAT;

    pDoc->SetModifiedFlag();
    pDoc->SetLightsModifiedFlag();
    pDoc->UpdateAllViews(NULL, HINT_UPDATELIGHTS, NULL);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - On(Update)ViewRndWireframe                                �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnUpdateViewRndWireframe(CCmdUI* pCmdUI)
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

        pCmdUI->SetCheck( (!(rend.terr.flags & ESCH_TRN_DOTS)
                           && (pDoc->cam.flags & (ESCH_CAM_SHADE_WIRE
                                              | ESCH_CAM_SHADE_SOLID
                                              | ESCH_CAM_SHADE_FLAT
                                              | ESCH_CAM_SHADE_SMOOTH
                                              | ESCH_CAM_SHADE_SPECULAR))==ESCH_CAM_SHADE_WIRE) ? 1 : 0);
    pCmdUI->Enable(displayrender);
}

void TerrEditView::OnViewRndWireframe()
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    rend.terr.flags &= ~ESCH_TRN_DOTS;
    pDoc->cam.flags &= ~(ESCH_CAM_SHADE_SPECULAR
                         | ESCH_CAM_SHADE_SMOOTH
                         | ESCH_CAM_SHADE_FLAT
                         | ESCH_CAM_SHADE_SOLID);
    pDoc->cam.flags |= ESCH_CAM_SHADE_WIRE;

    pDoc->SetModifiedFlag();
    pDoc->SetLightsModifiedFlag();
    pDoc->UpdateAllViews(NULL, HINT_UPDATELIGHTS, NULL);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - On(Update)ViewRndSolid                                    �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnUpdateViewRndSolid(CCmdUI* pCmdUI)
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

        pCmdUI->SetCheck( (!(rend.terr.flags & ESCH_TRN_DOTS)
                           && (pDoc->cam.flags & (ESCH_CAM_SHADE_SOLID
                                              | ESCH_CAM_SHADE_FLAT
                                              | ESCH_CAM_SHADE_SMOOTH
                                              | ESCH_CAM_SHADE_SPECULAR))==ESCH_CAM_SHADE_SOLID) ? 1 : 0);
    pCmdUI->Enable(displayrender);
}

void TerrEditView::OnViewRndSolid()
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    rend.terr.flags &= ~ESCH_TRN_DOTS;
    pDoc->cam.flags &= ~(ESCH_CAM_SHADE_SPECULAR
                         | ESCH_CAM_SHADE_SMOOTH
                         | ESCH_CAM_SHADE_FLAT);
    pDoc->cam.flags |= ESCH_CAM_SHADE_WIRE
                       | ESCH_CAM_SHADE_SOLID;

    pDoc->SetModifiedFlag();
    pDoc->SetLightsModifiedFlag();
    pDoc->UpdateAllViews(NULL, HINT_UPDATELIGHTS, NULL);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - On(Update)ViewRndFlat                                     �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnUpdateViewRndFlat(CCmdUI* pCmdUI)
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

        pCmdUI->SetCheck( (!(rend.terr.flags & ESCH_TRN_DOTS)
                           && (pDoc->cam.flags & (ESCH_CAM_SHADE_FLAT
                                              | ESCH_CAM_SHADE_SMOOTH
                                              | ESCH_CAM_SHADE_SPECULAR))==ESCH_CAM_SHADE_FLAT) ? 1 : 0);
    pCmdUI->Enable(displayrender);
}

void TerrEditView::OnViewRndFlat()
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    rend.terr.flags &= ~ESCH_TRN_DOTS;
    pDoc->cam.flags &= ~(ESCH_CAM_SHADE_SPECULAR
                         | ESCH_CAM_SHADE_SMOOTH);
    pDoc->cam.flags |= ESCH_CAM_SHADE_WIRE
                       | ESCH_CAM_SHADE_SOLID
                       | ESCH_CAM_SHADE_FLAT;

    pDoc->SetModifiedFlag();
    pDoc->SetLightsModifiedFlag();
    pDoc->UpdateAllViews(NULL, HINT_UPDATELIGHTS, NULL);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - On(Update)ViewRndSmooth                                   �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnUpdateViewRndSmooth(CCmdUI* pCmdUI)
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

        pCmdUI->SetCheck( (!(rend.terr.flags & ESCH_TRN_DOTS)
                           && (pDoc->cam.flags & (ESCH_CAM_SHADE_SMOOTH
                                              | ESCH_CAM_SHADE_SPECULAR))==ESCH_CAM_SHADE_SMOOTH) ? 1 : 0);
    pCmdUI->Enable(displayrender);
}

void TerrEditView::OnViewRndSmooth()
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    rend.terr.flags &= ~ESCH_TRN_DOTS;
    pDoc->cam.flags &= ~ESCH_CAM_SHADE_SPECULAR;
    pDoc->cam.flags |= ESCH_CAM_SHADE_WIRE
                       | ESCH_CAM_SHADE_SOLID
                       | ESCH_CAM_SHADE_FLAT
                       | ESCH_CAM_SHADE_SMOOTH;

    pDoc->SetModifiedFlag();
    pDoc->SetLightsModifiedFlag();
    pDoc->UpdateAllViews(NULL, HINT_UPDATELIGHTS, NULL);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - On(Update)ViewRndSpecular                                 �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnUpdateViewRndSpecular(CCmdUI* pCmdUI)
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

        pCmdUI->SetCheck( (!(rend.terr.flags & ESCH_TRN_DOTS)
                           && (pDoc->cam.flags & ESCH_CAM_SHADE_SPECULAR)) ? 1 : 0);
    pCmdUI->Enable(displayrender);
}

void TerrEditView::OnViewRndSpecular()
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    rend.terr.flags &= ~ESCH_TRN_DOTS;
    pDoc->cam.flags |= ESCH_CAM_SHADE_WIRE
                       | ESCH_CAM_SHADE_SOLID
                       | ESCH_CAM_SHADE_FLAT
                       | ESCH_CAM_SHADE_SMOOTH
                       | ESCH_CAM_SHADE_SPECULAR;

    pDoc->SetModifiedFlag();
    pDoc->SetLightsModifiedFlag();
    pDoc->UpdateAllViews(NULL, HINT_UPDATELIGHTS, NULL);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - On(Update)ViewRndBackface                                 �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnUpdateViewRndBackface(CCmdUI* pCmdUI)
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

        pCmdUI->SetCheck( (pDoc->cam.flags & ESCH_CAM_BACKCULL) ? 1 : 0);
    pCmdUI->Enable(displayrender);
}

void TerrEditView::OnViewRndBackface()
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    pDoc->cam.flags ^= ESCH_CAM_BACKCULL;

    rend.UpdateRender();
    rend.RedrawWindow();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - On(Update)ViewRndTextures                                 �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnUpdateViewRndTextures(CCmdUI* pCmdUI)
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

        pCmdUI->SetCheck( (pDoc->cam.flags & ESCH_CAM_TEXTURED) ? 1 : 0);
    pCmdUI->Enable(displayrender);
}

void TerrEditView::OnViewRndTextures()
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    pDoc->cam.flags ^= ESCH_CAM_TEXTURED;

    rend.UpdateRender();
    rend.RedrawWindow();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - On(Update)ViewRndPerspective                              �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnUpdateViewRndPerspective(CCmdUI* pCmdUI)
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

        pCmdUI->SetCheck( (pDoc->cam.flags & ESCH_CAM_PERSPECTIVE) ? 1 : 0);
    pCmdUI->Enable( (displayrender && (pDoc->cam.flags & ESCH_CAM_TEXTURED)) ? TRUE : FALSE);
}

void TerrEditView::OnViewRndPerspective()
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    pDoc->cam.flags ^= ESCH_CAM_PERSPECTIVE;

    rend.UpdateRender();
    rend.RedrawWindow();
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - On(Update)LightAdjustXY                                   �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnUpdateLightAdjustXY(CCmdUI* pCmdUI)
{
        pCmdUI->SetCheck( (rend.GetMode() == RNDCTRL_LIGHTXY) ? 1 : 0);
    pCmdUI->Enable(displayrender);
}

void TerrEditView::OnLightAdjustXY()
{
    rend.SetMode(RNDCTRL_LIGHTXY);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - On(Update)LightAdjustIntensity                            �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnUpdateLightAdjustIntensity(CCmdUI* pCmdUI)
{
        pCmdUI->SetCheck( (rend.GetMode() == RNDCTRL_LIGHTBRIGHT) ? 1 : 0);
    pCmdUI->Enable(displayrender);
}

void TerrEditView::OnLightAdjustIntensity()
{
    rend.SetMode(RNDCTRL_LIGHTBRIGHT);
}


//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
// TerrEditView - On(Update)LightProperties                                 �
//陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�
void TerrEditView::OnUpdateLightProperties(CCmdUI* pCmdUI)
{
    pCmdUI->Enable(displayrender);
}

void TerrEditView::OnLightProperties()
{
    TerrEditDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    pDoc->UILightProperties(this);
}

//葦� eof - eshtview.cpp 憶�

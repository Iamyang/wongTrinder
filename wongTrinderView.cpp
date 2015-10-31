
// wongTrinderView.cpp : CwongTrinderView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "wongTrinder.h"
#endif

#include "wongTrinderDoc.h"
#include "wongTrinderView.h"

#include"dlgSave.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CwongTrinderView

IMPLEMENT_DYNCREATE(CwongTrinderView, CScrollView)

BEGIN_MESSAGE_MAP(CwongTrinderView, CScrollView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CwongTrinderView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_32771, &CwongTrinderView::OnWongTrinder)
END_MESSAGE_MAP()

// CwongTrinderView ����/����

CwongTrinderView::CwongTrinderView()
{
	// TODO: �ڴ˴���ӹ������

}

CwongTrinderView::~CwongTrinderView()
{
}

BOOL CwongTrinderView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CScrollView::PreCreateWindow(cs);
}

// CwongTrinderView ����

void CwongTrinderView::OnDraw(CDC* pDC)
{
	CwongTrinderDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CSize sizeTotal;
	sizeTotal.cx = int(pDoc->m_imageProcess.m_dZoom*pDoc->m_imageProcess.imageWidth * 6 + 0.5);
	sizeTotal.cy = int(pDoc->m_imageProcess.m_dZoom*pDoc->m_imageProcess.imageHeight * 6 + 0.5);
	SetScrollSizes(MM_TEXT, sizeTotal);

	pDoc->m_imageProcess.ImageDisplay(pDC, pDoc->m_imageProcess.m_dZoom);
}

void CwongTrinderView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: �������ͼ�ĺϼƴ�С
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CwongTrinderView ��ӡ


void CwongTrinderView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CwongTrinderView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CwongTrinderView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CwongTrinderView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CwongTrinderView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CwongTrinderView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CwongTrinderView ���

#ifdef _DEBUG
void CwongTrinderView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CwongTrinderView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CwongTrinderDoc* CwongTrinderView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CwongTrinderDoc)));
	return (CwongTrinderDoc*)m_pDocument;
}
#endif //_DEBUG


// CwongTrinderView ��Ϣ�������


void CwongTrinderView::OnWongTrinder()
{
	// TODO: �ڴ���������������
	CwongTrinderDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->m_imageProcess.WongTrinder();
	dlgSave dlg;
	dlg.m_x=pDoc->m_imageProcess.x;
	dlg.m_y=pDoc->m_imageProcess.y;
	if(dlg.DoModal())
	{	
		
	}
}

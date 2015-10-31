
// wongTrinderView.cpp : CwongTrinderView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CwongTrinderView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_32771, &CwongTrinderView::OnWongTrinder)
END_MESSAGE_MAP()

// CwongTrinderView 构造/析构

CwongTrinderView::CwongTrinderView()
{
	// TODO: 在此处添加构造代码

}

CwongTrinderView::~CwongTrinderView()
{
}

BOOL CwongTrinderView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CScrollView::PreCreateWindow(cs);
}

// CwongTrinderView 绘制

void CwongTrinderView::OnDraw(CDC* pDC)
{
	CwongTrinderDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
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
	// TODO: 计算此视图的合计大小
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CwongTrinderView 打印


void CwongTrinderView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CwongTrinderView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CwongTrinderView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CwongTrinderView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
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


// CwongTrinderView 诊断

#ifdef _DEBUG
void CwongTrinderView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CwongTrinderView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CwongTrinderDoc* CwongTrinderView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CwongTrinderDoc)));
	return (CwongTrinderDoc*)m_pDocument;
}
#endif //_DEBUG


// CwongTrinderView 消息处理程序


void CwongTrinderView::OnWongTrinder()
{
	// TODO: 在此添加命令处理程序代码
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

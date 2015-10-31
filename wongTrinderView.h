
// wongTrinderView.h : CwongTrinderView ��Ľӿ�
//

#pragma once


class CwongTrinderView : public CScrollView
{
protected: // �������л�����
	CwongTrinderView();
	DECLARE_DYNCREATE(CwongTrinderView)

// ����
public:
	CwongTrinderDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ������һ�ε���
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CwongTrinderView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnWongTrinder();
};

#ifndef _DEBUG  // wongTrinderView.cpp �еĵ��԰汾
inline CwongTrinderDoc* CwongTrinderView::GetDocument() const
   { return reinterpret_cast<CwongTrinderDoc*>(m_pDocument); }
#endif


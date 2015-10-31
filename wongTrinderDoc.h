
// wongTrinderDoc.h : CwongTrinderDoc ��Ľӿ�
//
#include"YangLiuImageProcess.h"

#pragma once


class CwongTrinderDoc : public CDocument
{
protected: // �������л�����
	CwongTrinderDoc();
	DECLARE_DYNCREATE(CwongTrinderDoc)

// ����
public:
	CYangLiuImageProcess m_imageProcess;
// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CwongTrinderDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
};

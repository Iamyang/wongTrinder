#pragma once


// dlgSave 对话框

class dlgSave : public CDialogEx
{
	DECLARE_DYNAMIC(dlgSave)

public:
	dlgSave(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~dlgSave();

// 对话框数据
	enum { IDD = IDD_DLGSAVE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_x;
	int m_y;
	afx_msg void OnBnClickedSave();
};

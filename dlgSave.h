#pragma once


// dlgSave �Ի���

class dlgSave : public CDialogEx
{
	DECLARE_DYNAMIC(dlgSave)

public:
	dlgSave(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~dlgSave();

// �Ի�������
	enum { IDD = IDD_DLGSAVE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_x;
	int m_y;
	afx_msg void OnBnClickedSave();
};

// dlgSave.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "wongTrinder.h"
#include "dlgSave.h"
#include "afxdialogex.h"
#include<io.h>

// dlgSave �Ի���

IMPLEMENT_DYNAMIC(dlgSave, CDialogEx)

dlgSave::dlgSave(CWnd* pParent /*=NULL*/)
	: CDialogEx(dlgSave::IDD, pParent)
{

	m_x = 0;
	m_y = 0;
}

dlgSave::~dlgSave()
{
}

void dlgSave::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_x);
	DDX_Text(pDX, IDC_EDIT2, m_y);
}


BEGIN_MESSAGE_MAP(dlgSave, CDialogEx)
	ON_BN_CLICKED(IDOK, &dlgSave::OnBnClickedSave)
END_MESSAGE_MAP()


// dlgSave ��Ϣ�������


void dlgSave::OnBnClickedSave()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();

	CFile file;
	CString x;
	CString y;
	x.Format("%d",m_x);
	y.Format("%d",m_y);
	CString strX="X="+x;
	CString strY="Y="+y;

	CString strExt = ".txt";                                // ��չ��
    CString strFilePath;
    CString strFilter;
    strFilter.Format("Text Files (*txt)|*txt|All Files (*.*)|*.*||");
    CFileDialog dlg(FALSE, NULL, "", NULL, strFilter);
	 if (dlg.DoModal() == IDOK)
    {
        strFilePath = dlg.GetPathName();
        if (strFilePath.Find(strExt) == -1)
        {
            strFilePath += strExt;
        }
        if (_access(strFilePath, 0) == 0 )
        {
            CString strQuery;
            strQuery.Format("%s �Ѿ����ڣ�Ҫ�滻����", strFilePath);
            if ( IDNO == ::MessageBox(m_hWnd, strQuery, "�ļ�����ѯ��", MB_ICONQUESTION | MB_YESNO) )
            {
                return;
            }
        }
        FILE *fp = fopen(strFilePath, "wt+");
        if ( fp != NULL )
        {
            fputs(strX, fp);
            fputs("\r\n", fp);
			fputs(strY,fp);
            fputs("\r\n", fp);
            fclose(fp);
        }
    }
}

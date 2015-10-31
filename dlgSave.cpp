// dlgSave.cpp : 实现文件
//

#include "stdafx.h"
#include "wongTrinder.h"
#include "dlgSave.h"
#include "afxdialogex.h"
#include<io.h>

// dlgSave 对话框

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


// dlgSave 消息处理程序


void dlgSave::OnBnClickedSave()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();

	CFile file;
	CString x;
	CString y;
	x.Format("%d",m_x);
	y.Format("%d",m_y);
	CString strX="X="+x;
	CString strY="Y="+y;

	CString strExt = ".txt";                                // 扩展名
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
            strQuery.Format("%s 已经存在，要替换它吗？", strFilePath);
            if ( IDNO == ::MessageBox(m_hWnd, strQuery, "文件覆盖询问", MB_ICONQUESTION | MB_YESNO) )
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

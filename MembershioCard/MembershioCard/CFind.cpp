// CFind.cpp: 实现文件
//

#include "stdafx.h"
#include "MembershioCard.h"
#include "CFind.h"
#include "afxdialogex.h"
#include "head.h"

//extern Cardinfo *cardhead;


// CFind 对话框

IMPLEMENT_DYNAMIC(CFind, CDialogEx)

CFind::CFind(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_find, pParent)
{

}

CFind::~CFind()
{
}

void CFind::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFind, CDialogEx)
	ON_BN_CLICKED(IDOK, &CFind::OnBnClickedOk)
END_MESSAGE_MAP()


// CFind 消息处理程序


void CFind::OnBnClickedOk()		//查询按钮
{
	// TODO: 在此添加控件通知处理程序代码

	//查找信息
	CListBox *plist = (CListBox *)GetDlgItem(IDC_LIST_info);
	CEdit *editnum = (CEdit *)GetDlgItem(IDC_EDIT_num);
	TCHAR num[30];
	editnum->GetWindowTextW(num,30);

	if (wcslen(num) == 0)
	{
		MessageBox(_T("会员卡号不能为空"));
		plist->ResetContent();	//清空
		return;
	}
	Cardinfo *tem = FindId(num);
	if (tem == NULL)
	{
		MessageBox(_T("该会员卡号不存在"));
		plist->ResetContent();	//清空
		return;
	}

	//输出信息
	
	plist->ResetContent();	//清空
	CString info = _T("会员姓名：\t \t");
	info += tem->cname;
	plist->InsertString(0, info);
	info = _T("会员卡号：");
	info += tem->CardId;
	plist->InsertString(1,info);
	info.Format(_T("会员积分：%d"), tem->integral);
	plist->InsertString(2, info);
	info = _T("享受折扣: ");
	switch (tem->discount)
	{
	case 0:
		info += _T("无折扣");
		break;
	case 1:
		info += _T("9.5折");
		break;
	case 2:
		info += _T("9折");
		break;
	case 3:
		info += _T("8.5折");
		break;
	case 4:
		info += _T("8折");
		break;
	case 5:
		info += _T("7折");
		break;
	}
	plist->InsertString(3, info);
	info.Format(_T("累计折扣金额：%d"), tem->disamount);
	plist->InsertString(4, info);

}

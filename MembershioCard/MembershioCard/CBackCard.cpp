// CBackCard.cpp: 实现文件
//

#include "stdafx.h"
#include "MembershioCard.h"
#include "CBackCard.h"
#include "afxdialogex.h"
#include "head.h"

extern Cardinfo *cardhead;

// CBackCard 对话框

IMPLEMENT_DYNAMIC(CBackCard, CDialogEx)

CBackCard::CBackCard(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_backcard, pParent)
{

}

CBackCard::~CBackCard()
{
}

void CBackCard::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CBackCard, CDialogEx)
	ON_BN_CLICKED(IDOK, &CBackCard::OnBnClickedOk)
END_MESSAGE_MAP()


// CBackCard 消息处理程序


void CBackCard::OnBnClickedOk()	//退卡
{
	// TODO: 在此添加控件通知处理程序代码
	CEdit *editnum = (CEdit *)GetDlgItem(IDC_EDIT_num);
	TCHAR num[30];
	editnum->GetWindowTextW(num, 30);

	if (wcslen(num) == 0)
	{
		MessageBox(_T("会员卡号不可为空"));
		return;
	}

	Cardinfo *tem = FindId(num);
	if (tem == NULL)
	{
		MessageBox(_T("该卡号不存在"));
		return;
	}

	if (tem == cardhead)	//如果要删除结点为头结点
	{
		cardhead = tem->next;
		free(tem);
		MessageBox(_T("删除成功"));
		return;
	}

	//不是头结点
	Cardinfo *pre = cardhead, *p = cardhead->next;
	while (p != NULL)
	{
		if (p == tem)
			break;
		pre = p;
		p = p->next;
	}

	pre->next = p->next;
	free(p);
	MessageBox(_T("删除成功"));
}

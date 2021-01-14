// COpenCard.cpp: 实现文件
//

#include "stdafx.h"
#include "MembershioCard.h"
#include "COpenCard.h"
#include "afxdialogex.h"
#include "head.h"

extern Cardinfo *cardhead;


// COpenCard 对话框

IMPLEMENT_DYNAMIC(COpenCard, CDialogEx)

COpenCard::COpenCard(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_opencard, pParent)
{

}

COpenCard::~COpenCard()
{
}

void COpenCard::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(COpenCard, CDialogEx)
	ON_BN_CLICKED(IDOK, &COpenCard::OnBnClickedOk)
END_MESSAGE_MAP()


// COpenCard 消息处理程序


void COpenCard::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CEdit *editnum = (CEdit *)GetDlgItem(IDC_EDIT_Cnum);
	CEdit *editname = (CEdit *)GetDlgItem(IDC_EDIT_Cname);
	TCHAR num[30], name[20];
	editnum->GetWindowTextW(num, 30);
	editname->GetWindowTextW(name, 20);

	if (wcslen(num) == 0)	//判断是否为空
	{
		MessageBox(_T("会员卡号不能为空"));
		return;
	}
	if (wcslen(name) == 0)
	{
		MessageBox(_T("会员姓名不能为空"));
		return;
	}

	//判断卡号是否合法
	if (wcslen(num) < 5 || wcslen(num) > 12 )
	{
		MessageBox(_T("会员卡号不符合规定"));
		return;
	}
	else
	{
		for (int i = 0; i < wcslen(num); i++)
		{
			if (iswdigit(num[i]) == 0)
			{
				MessageBox(_T("会员卡号不符合规定"));
				return;
			}
		}
	}

	//判断卡号是否重复
	Cardinfo *tem = FindId(num);
	if (tem != NULL)
	{
		MessageBox(_T("会员卡号已存在"));
			return;
	}

	//开卡成功，保存记录
	Cardinfo *newcard = (Cardinfo *)malloc(sizeof(Cardinfo));
	wcscpy(newcard->CardId, num);
	newcard->integral = 0;
	newcard->discount = 0;
	newcard->disamount = 0;
	wcscat(name, _T("\n"));
	wcscpy(newcard->cname, name);
	newcard->next = cardhead;
	cardhead = newcard;
	MessageBox(_T("开卡成功"));
}

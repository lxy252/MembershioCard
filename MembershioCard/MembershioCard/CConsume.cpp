// CConsume.cpp: 实现文件
//

#include "stdafx.h"
#include "MembershioCard.h"
#include "CConsume.h"
#include "afxdialogex.h"
#include "head.h"

extern Cardinfo * cardhead;

// CConsume 对话框

IMPLEMENT_DYNAMIC(CConsume, CDialogEx)

CConsume::CConsume(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_consume, pParent)
{

}

CConsume::~CConsume()
{
	endcard();
}

void CConsume::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CConsume, CDialogEx)
	ON_BN_CLICKED(IDOK, &CConsume::OnBnClickedOk)
//	ON_BN_CLICKED(IDC_BUTTON1, &CConsume::OnBnClickedButton1)
ON_BN_CLICKED(IDC_CANCLE, &CConsume::OnBnClickedCancle)
ON_BN_CLICKED(ID_Settle, &CConsume::OnBnClickedSettle)
END_MESSAGE_MAP()


// CConsume 消息处理程序

void CConsume::OnBnClickedOk()	//查找到会员卡、计算实付金额
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
	CEdit *editnum = (CEdit *)GetDlgItem(IDC_EDIT_num);
	CEdit *editfmoney = (CEdit *)GetDlgItem(IDC_EDIT_fmoney);	//应付金额
	CEdit *edittmoney = (CEdit *)GetDlgItem(IDC_EDIT_tmoney);	//实付金额
	CEdit *editdiscount = (CEdit *)GetDlgItem(IDC_EDIT_discount);
	CEdit *editintegral = (CEdit *)GetDlgItem(IDC_EDIT_integral);
	TCHAR sc1[30], sc2[20],sc3[20],sc4[10],sc5[10];
	editnum->GetWindowTextW(sc1, 30);
	editfmoney->GetWindowTextW(sc2, 20);
	if (wcslen(sc1) == 0)
	{
		MessageBox(_T("会员卡号不能为空"));
		return;
	}
	if (wcslen(sc2) == 0)
	{
		MessageBox(_T("应付金额不能为空"));
		return;
	}

	Cardinfo *nowcard = FindId(sc1);
	if (nowcard == NULL)
	{
		MessageBox(_T("会员卡号不存在"));
		return;
	}

	int mon = _wtoi(sc2);		//计算实付金额
	switch (nowcard->discount)
	{
	case 0:
		wcscpy(sc4, L"无折扣");
		break;
	case 1:	
		mon = 0.95 * mon;
		wcscpy(sc4, L"9.5折");
		break;
	case 2:
		mon = 0.9 * mon;
		wcscpy(sc4, L"9折");
		break;
	case 3:
		mon = 0.85 * mon;
		wcscpy(sc4, L"8.5折");
		break;
	case 4:
		mon = 0.8 * mon;
		wcscpy(sc4, L"8折");
		break;
	case 5:
		mon = 0.7 * mon;
		wcscpy(sc4, L"7折");
	}

	_itow(mon, sc3, 10);
	edittmoney->SetWindowTextW(sc3);	//实付金额

	editdiscount->SetWindowTextW(sc4);	//折扣

	_itow(nowcard->integral, sc5, 10);
	editintegral->SetWindowTextW(sc5);	//积分
}





void CConsume::OnBnClickedCancle()	//退出
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CConsume::OnBnClickedSettle()
{
	// TODO: 在此添加控件通知处理程序代码
	CEdit *editnum = (CEdit *)GetDlgItem(IDC_EDIT_num);
	CEdit *editfmoney = (CEdit *)GetDlgItem(IDC_EDIT_fmoney);	//应付金额
	CEdit *edittmoney = (CEdit *)GetDlgItem(IDC_EDIT_tmoney);	//实付金额
	CEdit *editdiscount = (CEdit *)GetDlgItem(IDC_EDIT_discount);
	CEdit *editintegral = (CEdit *)GetDlgItem(IDC_EDIT_integral);
	//TCHAR sc1[30], sc2[20], sc3[10], sc4[10], sc5[10];
	TCHAR num[30],fmoney[20],tmoney[20];
	editnum->GetWindowTextW(num, 30);
	edittmoney->GetWindowTextW(tmoney, 20);
	editfmoney->GetWindowTextW(fmoney, 20);
	if (wcslen(tmoney) == 0)
	{
		MessageBox(_T("实付金额不能为空\r\n请先按确认键"));
		return;
	}

	Cardinfo *nowcard = FindId(num);
	nowcard->integral += _wtoi(tmoney);
	nowcard->disamount += (_wtoi(fmoney) - _wtoi(tmoney));

	int tem = nowcard->integral;	//计算会员等级
	if (tem < 1000)
		nowcard->discount = 0;
	else if (tem < 5000)
		nowcard->discount = 1;
	else if (tem < 10000)
		nowcard->discount = 2;
	else if (tem < 50000)
		nowcard->discount = 3;
	else if (tem < 150000)
		nowcard->discount = 4;
	else
		nowcard->discount = 5;

	editnum->SetWindowTextW(_T(""));
	editfmoney->SetWindowTextW(_T(""));
	edittmoney->SetWindowTextW(_T(""));
	editdiscount->SetWindowTextW(_T(""));
	editintegral->SetWindowTextW(_T(""));
	MessageBox(_T("结算成功"));
}

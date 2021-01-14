
// MembershioCardDlg.h: 头文件
//

#pragma once
#include"CConsume.h"
#include "COpenCard.h"
#include "CFind.h"
#include "CBackCard.h"

// CMembershioCardDlg 对话框
class CMembershioCardDlg : public CDialogEx
{
// 构造
public:
	CMembershioCardDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MEMBERSHIOCARD_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CConsume dlg_Consume;	//消费的窗口
	COpenCard dlg_OpenCard;	//开卡窗口
	CFind dlg_Find;			//查询窗口
	CBackCard dlg_BackCard;	//退卡窗口

	afx_msg void OnBnClickedSaccount();
	afx_msg void OnBnClickedopencard();
	afx_msg void OnBnClickedFound();
	afx_msg void OnBnClickedBackcard();
	afx_msg void OnBnClickedhelp();
};

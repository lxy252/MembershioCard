﻿#pragma once


// CBackCard 对话框

class CBackCard : public CDialogEx
{
	DECLARE_DYNAMIC(CBackCard)

public:
	CBackCard(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CBackCard();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_backcard };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};

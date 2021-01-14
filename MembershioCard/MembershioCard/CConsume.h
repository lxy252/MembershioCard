#pragma once


// CConsume 对话框

class CConsume : public CDialogEx
{
	DECLARE_DYNAMIC(CConsume)

public:
	CConsume(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CConsume();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_consume };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
//	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedCancle();
	afx_msg void OnBnClickedSettle();
};

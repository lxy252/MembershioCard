#pragma once


// COpenCard 对话框

class COpenCard : public CDialogEx
{
	DECLARE_DYNAMIC(COpenCard)

public:
	COpenCard(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~COpenCard();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_opencard };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};

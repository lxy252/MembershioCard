
// MembershioCardDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MembershioCard.h"
#include "MembershioCardDlg.h"
#include "afxdialogex.h"
#include "head.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMembershioCardDlg 对话框



CMembershioCardDlg::CMembershioCardDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MEMBERSHIOCARD_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMembershioCardDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMembershioCardDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_Saccount, &CMembershioCardDlg::OnBnClickedSaccount)
	ON_BN_CLICKED(ID_opencard, &CMembershioCardDlg::OnBnClickedopencard)
	ON_BN_CLICKED(IDC_Found, &CMembershioCardDlg::OnBnClickedFound)
	ON_BN_CLICKED(IDC_BackCard, &CMembershioCardDlg::OnBnClickedBackcard)
	ON_BN_CLICKED(IDC_help, &CMembershioCardDlg::OnBnClickedhelp)
END_MESSAGE_MAP()


// CMembershioCardDlg 消息处理程序

BOOL CMembershioCardDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	initcard();	//初始化会员卡信息

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMembershioCardDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMembershioCardDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMembershioCardDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMembershioCardDlg::OnBnClickedSaccount()	//创建消费管理的窗口
{
	// TODO: 在此添加控件通知处理程序代码
	if (dlg_Consume.m_hWnd == 0)
	{
		dlg_Consume.Create(IDD_DIALOG_consume, this);
	}
	dlg_Consume.ShowWindow(SW_SHOW);
}


void CMembershioCardDlg::OnBnClickedopencard()	//创建开卡的窗口
{
	// TODO: 在此添加控件通知处理程序代码
	if (dlg_OpenCard.m_hWnd == 0)
	{
		dlg_OpenCard.Create(IDD_DIALOG_opencard);
	}
	dlg_OpenCard.ShowWindow(SW_SHOW);
}


void CMembershioCardDlg::OnBnClickedFound()		//创建查询的窗口
{
	// TODO: 在此添加控件通知处理程序代码
	if (dlg_Find.m_hWnd == 0)
	{
		dlg_Find.Create(IDD_DIALOG_find);
	}
	dlg_Find.ShowWindow(SW_SHOW);
}


void CMembershioCardDlg::OnBnClickedBackcard()	//创建退卡的窗口
{
	// TODO: 在此添加控件通知处理程序代码
	if (dlg_BackCard.m_hWnd == 0)
	{
		dlg_BackCard.Create(IDD_DIALOG_backcard);
	}
	dlg_BackCard.ShowWindow(SW_SHOW);
}

//消费1元——1积分
//1000-5000积分：	9.5折	等级1
//5000-10000积分：	9折		等级2
//10000-50000积分：	8.5折	等级3
//50000-150000积分：8折		等级4
//150000积分以上：	7折		等级5

void CMembershioCardDlg::OnBnClickedhelp()
{
	// TODO: 在此添加控件通知处理程序代码
	CString s=_T("消费1元——1积分\r\n");
	s += _T("1000-5000积分：	9.5折	等级1\r\n");
	s += _T("5000-10000积分：	9折	等级2\r\n");
	s += _T("10000-50000积分：	8.5折	等级3\r\n");
	s += _T("50000-150000积分：	8折	等级4\r\n");
	s += _T("150000积分以上：	7折	等级5\r\n");
	MessageBox(s);
}


// Rry_SchCostConSysDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Rry_SchCostConSys.h"
#include "Rry_SchCostConSysDlg.h"
#include "afxdialogex.h"
#include "LoginDlg.h"
#include "ExployeeInfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//引用外部变量-员工号
extern CString m_exployee_id_glb;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CRry_SchCostConSysDlg 对话框




CRry_SchCostConSysDlg::CRry_SchCostConSysDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRry_SchCostConSysDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRry_SchCostConSysDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CRry_SchCostConSysDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_WM_CTLCOLOR()
ON_WM_CTLCOLOR()
ON_BN_CLICKED(IDC_BUTTON_YGXX, &CRry_SchCostConSysDlg::OnClickedButtonYgxx)
END_MESSAGE_MAP()


// CRry_SchCostConSysDlg 消息处理程序

BOOL CRry_SchCostConSysDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	CLoginDlg mLogin;
	if(mLogin.DoModal() != IDOK)
	{
		CDialog::OnCancel();
	}

	//设置按钮背景图片
    HBITMAP m_bitmap_ygxx;
	HBITMAP m_bitmap_ysbz;
	HBITMAP m_bitmap_fykz;
	HBITMAP m_bitmap_zxfx;
    m_bitmap_ygxx = (HBITMAP)::LoadImage(NULL,L"res/员工信息.bmp", IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	m_bitmap_ysbz = (HBITMAP)::LoadImage(NULL,L"res/预算编制.bmp", IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	m_bitmap_fykz = (HBITMAP)::LoadImage(NULL,L"res/费用控制.bmp", IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	m_bitmap_zxfx = (HBITMAP)::LoadImage(NULL,L"res/执行分析.bmp", IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
    ((CButton *)GetDlgItem(IDC_BUTTON_YGXX))->SetBitmap(m_bitmap_ygxx);
	((CButton *)GetDlgItem(IDC_BUTTON_YSBZ))->SetBitmap(m_bitmap_ysbz);
	((CButton *)GetDlgItem(IDC_BUTTON_FYKZ))->SetBitmap(m_bitmap_fykz);
	((CButton *)GetDlgItem(IDC_BUTTON_ZXFX))->SetBitmap(m_bitmap_zxfx);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CRry_SchCostConSysDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CRry_SchCostConSysDlg::OnPaint()
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
HCURSOR CRry_SchCostConSysDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


HBRUSH CRry_SchCostConSysDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  ÔÚ´Ë¸ü¸Ä DC µÄÈÎºÎÌØÐÔ

	// TODO:  Èç¹ûÄ¬ÈÏµÄ²»ÊÇËùÐè»­±Ê£¬Ôò·µ»ØÁíÒ»¸ö»­±Ê

	return hbr;
}




void CRry_SchCostConSysDlg::OnClickedButtonYgxx()
{
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
	if(m_exployee_id_glb == "00000")
	{
	
	}
	else
	{
	    CExployeeInfoDlg m_ygxx;
	    m_ygxx.DoModal();
	}
}

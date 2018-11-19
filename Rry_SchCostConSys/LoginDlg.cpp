// LoginDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Rry_SchCostConSys.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "MySQLConn.h"

//声明全局变量-员工号
CString m_exployee_id_glb;

// CLoginDlg 对话框

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLoginDlg::IDD, pParent)
{

	m_passwd = _T("");
	m_user = _T("");
	m_Time = 0;
	m_result = 0;
}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_PASSWD, m_passwd);
	DDV_MaxChars(pDX, m_passwd, 100);
	DDX_Text(pDX, IDC_EDIT_USER, m_user);
	DDV_MaxChars(pDX, m_user, 100);
	DDX_Control(pDX, IDC_STATIC_USER, m_static_user);
	DDX_Control(pDX, IDC_STATIC_PASSWD, m_static_passwd);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON_LOGIN, &CLoginDlg::OnClickedButtonLogin)
	ON_BN_CLICKED(IDC_BUTTON_RESET, &CLoginDlg::OnClickedButtonReset)
END_MESSAGE_MAP()


// CLoginDlg 消息处理程序


BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ÔÚ´ËÌí¼Ó¶îÍâµÄ³õÊ¼»¯
	//设置静态文本框"用户名"和"密码"的字体
	//用户名
	m_Font_user.CreatePointFont(120, TEXT("黑体"), NULL);
	m_Brush_user.CreateSolidBrush(RGB(255,255,255));
	m_static_user.SetFont(&m_Font_user,true);
	m_static_user.SetWindowText(TEXT("员工号:"));
	
	//密码
	m_Font_passwd.CreatePointFont(120, TEXT("黑体"), NULL);
	m_Brush_passwd.CreateSolidBrush(RGB(255,255,255));
	m_static_passwd.SetFont(&m_Font_passwd,true);
	m_static_passwd.SetWindowText(TEXT("密  码:"));

	return TRUE;  // return TRUE unless you set the focus to a control
	// Òì³£: OCX ÊôÐÔÒ³Ó¦·µ»Ø FALSE
}


HBRUSH CLoginDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  ÔÚ´Ë¸ü¸Ä DC µÄÈÎºÎÌØÐÔ
	if(m_static_user.m_hWnd == pWnd->m_hWnd)
    {    
		pDC->SetBkColor(RGB(255,255,255)); ///字体的背景
        pDC->SetBkMode(TRANSPARENT); ///编辑框透明
        pDC->SetTextColor(RGB(0, 0, 0));//文字颜色
        return m_Brush_user;
	}
    else if(m_static_passwd.m_hWnd == pWnd->m_hWnd)
    {    
		pDC->SetBkColor(RGB(255,255,255)); ///字体的背景
        pDC->SetBkMode(TRANSPARENT); ///编辑框透明
        pDC->SetTextColor(RGB(0, 0, 0));//文字颜色
        return m_Brush_passwd;
	}

	// TODO:  Èç¹ûÄ¬ÈÏµÄ²»ÊÇËùÐè»­±Ê£¬Ôò·µ»ØÁíÒ»¸ö»­±Ê
	return hbr;
}


void CLoginDlg::OnClickedButtonLogin()
{
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
	UpdateData(TRUE);
	if(m_user.IsEmpty() || m_passwd.IsEmpty())
	{
		MessageBox(_T("员工号或密码不能为空"));
		return;
	}
	m_Time++;
	CString m_string;	
	m_string.Format(_T("select * from tb_user where exployee_id = '%s'and passwd = '%s'"), m_user,m_passwd);
	const size_t strsize = ( m_string.GetLength() + 1 ) * 2; // 宽字符的长度;
    char * sql = new char[strsize]; //分配空间; 
    size_t sz = 0;
    wcstombs_s( &sz, sql, strsize, m_string, _TRUNCATE );

	MySQLConn m_Myconn;
	m_Myconn.OnInitMySQLConn();
	/* 获取结果行 */
	m_result = m_Myconn.GetRecordRow(sql);
	if(m_result == 1)
	{
		m_exployee_id_glb = m_user;
		CDialog::OnOK();
	}
	else
	{
		if(m_Time == 3)
		{
			MessageBox(_T("密码3次不正确"));
			CDialog::OnCancel();
		}
		else
		{
			MessageBox(_T("员工号或密码不正确"));
			m_user = "";
			m_passwd = "";
			UpdateData(FALSE);
		}
	}

	//断开数据库连接
    m_Myconn.ExitMySQLConn();
}

void CLoginDlg::OnClickedButtonReset()
{
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
	m_user = "";
	m_passwd = "";
	UpdateData(FALSE);
}

BOOL CLoginDlg::PreTranslateMessage(MSG* pMsg) 
{
    if(pMsg->message == WM_KEYDOWN) 
    {
        if(pMsg->wParam == VK_RETURN)//当按下键为回车键时
        {
            OnClickedButtonLogin();  //调用按钮函数

            return TRUE;
        }
    }
    return CDialog::PreTranslateMessage(pMsg);
}
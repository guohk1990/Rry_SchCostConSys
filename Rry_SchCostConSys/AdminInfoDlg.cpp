// AdminInfoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Rry_SchCostConSys.h"
#include "AdminInfoDlg.h"
#include "afxdialogex.h"
#include "MySQLConn.h"
#include "AddExployeeInfoDlg.h"


// CAdminInfoDlg 对话框

IMPLEMENT_DYNAMIC(CAdminInfoDlg, CDialogEx)

CAdminInfoDlg::CAdminInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAdminInfoDlg::IDD, pParent)
{

}

CAdminInfoDlg::~CAdminInfoDlg()
{
}

void CAdminInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_GLY_YGXX, m_Grid);
}


BEGIN_MESSAGE_MAP(CAdminInfoDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_GLY_ADD, &CAdminInfoDlg::OnBnClickedButtonGlyAdd)
	ON_BN_CLICKED(IDC_BUTTON_GLY_UPDATE, &CAdminInfoDlg::OnBnClickedButtonGlyUpdate)
	ON_BN_CLICKED(IDC_BUTTON_GLY_DELETE, &CAdminInfoDlg::OnBnClickedButtonGlyDelete)
	ON_BN_CLICKED(IDC_BUTTON_GLY_EXIT, &CAdminInfoDlg::OnBnClickedButtonGlyExit)
END_MESSAGE_MAP()


// CAdminInfoDlg 消息处理程序


BOOL CAdminInfoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ÔÚ´ËÌí¼Ó¶îÍâµÄ³õÊ¼»¯
	//设置列表视图的扩展风格
	m_Grid.SetExtendedStyle(LVS_EX_FLATSB
		|LVS_EX_FULLROWSELECT
		|LVS_EX_HEADERDRAGDROP
		|LVS_EX_ONECLICKACTIVATE
		|LVS_EX_GRIDLINES);
	//设置表头
	m_Grid.InsertColumn(0,_T("员工编号"),LVCFMT_CENTER,70,0); 
	m_Grid.InsertColumn(1,_T("员工姓名"),LVCFMT_CENTER,70,1); 
	m_Grid.InsertColumn(2,_T("性别"),LVCFMT_CENTER,40,2); 
	m_Grid.InsertColumn(3,_T("民族"),LVCFMT_CENTER,50,3); 
	m_Grid.InsertColumn(4,_T("政治面貌"),LVCFMT_CENTER,70,4); 
	m_Grid.InsertColumn(5,_T("籍贯"),LVCFMT_CENTER,100,5); 
	m_Grid.InsertColumn(6,_T("职称"),LVCFMT_CENTER,50,6); 
	m_Grid.InsertColumn(7,_T("教龄/年"),LVCFMT_CENTER,60,0); 
	m_Grid.InsertColumn(8,_T("身份证号"),LVCFMT_CENTER,150,1); 
	m_Grid.InsertColumn(9,_T("出生年月"),LVCFMT_CENTER,100,2); 
	m_Grid.InsertColumn(10,_T("入职时间"),LVCFMT_CENTER,100,3); 
	m_Grid.InsertColumn(11,_T("联系电话"),LVCFMT_CENTER,100,4); 
	m_Grid.InsertColumn(12,_T("家庭住址"),LVCFMT_CENTER,200,5); 
	m_Grid.InsertColumn(13,_T("任教学段"),LVCFMT_CENTER,70,6); 
	m_Grid.InsertColumn(14,_T("任教年级"),LVCFMT_CENTER,70,3); 
	m_Grid.InsertColumn(15,_T("任教学科"),LVCFMT_CENTER,90,4); 
	m_Grid.InsertColumn(16,_T("毕业院校"),LVCFMT_CENTER,150,5); 
	m_Grid.InsertColumn(17,_T("所学专业"),LVCFMT_CENTER,150,6); 
	m_Grid.InsertColumn(18,_T("毕业时间"),LVCFMT_CENTER,100,5); 
	m_Grid.InsertColumn(19,_T("备注"),LVCFMT_CENTER,300,6);
	
	//添加员工信息
	AddToGrid();

	return TRUE;  // return TRUE unless you set the focus to a control
	// Òì³£: OCX ÊôÐÔÒ³Ó¦·µ»Ø FALSE
}


void CAdminInfoDlg::AddToGrid(void)
{
	CString m_string;	
	m_string.Format(_T("select * from tb_exployee"));
	const size_t strsize = ( m_string.GetLength() + 1 ) * 2; // 宽字符的长度;
    char * sql = new char[strsize]; //分配空间; 
    size_t sz = 0;
    wcstombs_s( &sz, sql, strsize, m_string, _TRUNCATE );

	MySQLConn m_Myconn;
	m_Myconn.OnInitMySQLConn();
	unsigned int files = m_Myconn.GetRecordFields(sql);
	int t = 0;
    while(m_Myconn.row = mysql_fetch_row(m_Myconn.res))
    {
		m_Grid.InsertItem(t,_bstr_t(""));
        for(unsigned int i = 0; i < files; i++)
	    {
            m_Grid.SetItemText(t,i,(_bstr_t)m_Myconn.row[i]);
	    }
		t++;
    }

	//断开数据库连接
    m_Myconn.ExitMySQLConn();
}


void CAdminInfoDlg::OnBnClickedButtonGlyAdd()
{
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
	CAddExployeeInfoDlg m_addexployeeinfo;

	if(m_addexployeeinfo.DoModal() == IDOK)
	{
	    //先删除listctl控件的静态变量
	    m_Grid.DeleteAllItems();
	    
	    //重新查询数据库，更新新员工信息
	    AddToGrid();
	}
}


void CAdminInfoDlg::OnBnClickedButtonGlyUpdate()
{
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
}


void CAdminInfoDlg::OnBnClickedButtonGlyDelete()
{
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
}


void CAdminInfoDlg::OnBnClickedButtonGlyExit()
{
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
	CDialog::OnCancel();
}

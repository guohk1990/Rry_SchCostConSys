// AddExployeeInfoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Rry_SchCostConSys.h"
#include "AddExployeeInfoDlg.h"
#include "afxdialogex.h"
#include "MySQLConn.h"


// CAddExployeeInfoDlg 对话框

IMPLEMENT_DYNAMIC(CAddExployeeInfoDlg, CDialogEx)

CAddExployeeInfoDlg::CAddExployeeInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddExployeeInfoDlg::IDD, pParent)
{

	m_e_address = _T("");
	//  m_e_age = _T("");
	m_e_birthday = _T("");
	m_e_disc = _T("");
	m_e_grade = _T("");
	m_e_gradtime = _T("");
	m_e_hiredate = _T("");
	m_e_major = _T("");
	m_e_name = _T("");
	m_e_nation = _T("");
	m_e_place = _T("");
	m_e_remark = _T("");
	m_e_school = _T("");
	m_e_section = _T("");
	m_e_sex = _T("");
	m_e_status = _T("");
	m_e_telphone = _T("");
	m_e_title = _T("");
	m_e_ygbh = _T("");
	m_e_idnumber = _T("");
	m_e_age = 0;
}

CAddExployeeInfoDlg::~CAddExployeeInfoDlg()
{
}

void CAddExployeeInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_A_OK, m_add_ok);
	DDX_Control(pDX, IDC_BUTTON_A_CANCEL, m_add_cancel);
	DDX_Control(pDX, IDC_EDIT_A_ADDRESS, m_add_address);
	DDX_Control(pDX, IDC_EDIT_A_AGE, m_add_age);
	DDX_Control(pDX, IDC_EDIT_A_BIRTHDAY, m_add_birthday);
	DDX_Control(pDX, IDC_EDIT_A_DISC, m_add_disc);
	DDX_Control(pDX, IDC_EDIT_A_GRADE, m_add_grade);
	DDX_Control(pDX, IDC_EDIT_A_GRADTIME, m_add_gradtime);
	DDX_Control(pDX, IDC_EDIT_A_HIREDATE, m_add_hiredate);
	DDX_Control(pDX, IDC_EDIT_A_MAJOR, m_add_major);
	DDX_Control(pDX, IDC_EDIT_A_NAME, m_add_name);
	DDX_Control(pDX, IDC_EDIT_A_NATION, m_add_nation);
	DDX_Control(pDX, IDC_EDIT_A_PLACE, m_add_place);
	DDX_Control(pDX, IDC_EDIT_A_REMARK, m_add_remark);
	DDX_Control(pDX, IDC_EDIT_A_SCHOOL, m_add_school);
	DDX_Control(pDX, IDC_EDIT_A_SECTION, m_add_section);
	DDX_Control(pDX, IDC_EDIT_A_SEX, m_add_sex);
	DDX_Control(pDX, IDC_EDIT_A_STATUS, m_add_status);
	DDX_Control(pDX, IDC_EDIT_A_TELPHONE, m_add_telphone);
	DDX_Control(pDX, IDC_EDIT_A_TITLE, m_add_title);
	DDX_Control(pDX, IDC_EDIT_A_YGBH, m_add_ygbh);
	DDX_Control(pDX, IDC_EDIT_IDNUMBER, m_add_idnumber);
	DDX_Text(pDX, IDC_EDIT_A_ADDRESS, m_e_address);
	DDV_MaxChars(pDX, m_e_address, 255);
	//  DDX_Text(pDX, IDC_EDIT_A_AGE, m_e_age);
	//  DDV_MaxChars(pDX, m_e_age, 10);
	DDX_Text(pDX, IDC_EDIT_A_BIRTHDAY, m_e_birthday);
	DDV_MaxChars(pDX, m_e_birthday, 20);
	DDX_Text(pDX, IDC_EDIT_A_DISC, m_e_disc);
	DDV_MaxChars(pDX, m_e_disc, 20);
	DDX_Text(pDX, IDC_EDIT_A_GRADE, m_e_grade);
	DDV_MaxChars(pDX, m_e_grade, 20);
	DDX_Text(pDX, IDC_EDIT_A_GRADTIME, m_e_gradtime);
	DDV_MaxChars(pDX, m_e_gradtime, 20);
	DDX_Text(pDX, IDC_EDIT_A_HIREDATE, m_e_hiredate);
	DDV_MaxChars(pDX, m_e_hiredate, 20);
	DDX_Text(pDX, IDC_EDIT_A_MAJOR, m_e_major);
	DDV_MaxChars(pDX, m_e_major, 60);
	DDX_Text(pDX, IDC_EDIT_A_NAME, m_e_name);
	DDV_MaxChars(pDX, m_e_name, 100);
	DDX_Text(pDX, IDC_EDIT_A_NATION, m_e_nation);
	DDV_MaxChars(pDX, m_e_nation, 10);
	DDX_Text(pDX, IDC_EDIT_A_PLACE, m_e_place);
	DDV_MaxChars(pDX, m_e_place, 20);
	DDX_Text(pDX, IDC_EDIT_A_REMARK, m_e_remark);
	DDV_MaxChars(pDX, m_e_remark, 255);
	DDX_Text(pDX, IDC_EDIT_A_SCHOOL, m_e_school);
	DDV_MaxChars(pDX, m_e_school, 30);
	DDX_Text(pDX, IDC_EDIT_A_SECTION, m_e_section);
	DDV_MaxChars(pDX, m_e_section, 20);
	DDX_Text(pDX, IDC_EDIT_A_SEX, m_e_sex);
	DDV_MaxChars(pDX, m_e_sex, 5);
	DDX_Text(pDX, IDC_EDIT_A_STATUS, m_e_status);
	DDV_MaxChars(pDX, m_e_status, 10);
	DDX_Text(pDX, IDC_EDIT_A_TELPHONE, m_e_telphone);
	DDV_MaxChars(pDX, m_e_telphone, 20);
	DDX_Text(pDX, IDC_EDIT_A_TITLE, m_e_title);
	DDV_MaxChars(pDX, m_e_title, 10);
	DDX_Text(pDX, IDC_EDIT_A_YGBH, m_e_ygbh);
	DDV_MaxChars(pDX, m_e_ygbh, 10);
	DDX_Text(pDX, IDC_EDIT_IDNUMBER, m_e_idnumber);
	DDV_MaxChars(pDX, m_e_idnumber, 20);
	DDX_Text(pDX, IDC_EDIT_A_AGE, m_e_age);
	DDV_MinMaxInt(pDX, m_e_age, 0, 9999);
}


BEGIN_MESSAGE_MAP(CAddExployeeInfoDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_A_OK, &CAddExployeeInfoDlg::OnBnClickedButtonAOk)
	ON_BN_CLICKED(IDC_BUTTON_A_CANCEL, &CAddExployeeInfoDlg::OnBnClickedButtonACancel)
END_MESSAGE_MAP()


// CAddExployeeInfoDlg 消息处理程序


BOOL CAddExployeeInfoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ÔÚ´ËÌí¼Ó¶îÍâµÄ³õÊ¼»¯
	m_Font.CreatePointFont(200, TEXT("宋体"), NULL);
	m_add_ok.SetFont(&m_Font,true);
	m_add_cancel.SetFont(&m_Font,true);
	m_add_ygbh.SetFont(&m_Font,true);
	m_add_name.SetFont(&m_Font,true);
	m_add_sex.SetFont(&m_Font,true);
	m_add_nation.SetFont(&m_Font,true);
	m_add_status.SetFont(&m_Font,true);
	m_add_place.SetFont(&m_Font,true);
	m_add_title.SetFont(&m_Font,true);
	m_add_age.SetFont(&m_Font,true);
	m_add_idnumber.SetFont(&m_Font,true);
	m_add_birthday.SetFont(&m_Font,true);
	m_add_hiredate.SetFont(&m_Font,true);
	m_add_telphone.SetFont(&m_Font,true);
	m_add_address.SetFont(&m_Font,true);
	m_add_section.SetFont(&m_Font,true);
	m_add_grade.SetFont(&m_Font,true);
	m_add_disc.SetFont(&m_Font,true);
	m_add_school.SetFont(&m_Font,true);
	m_add_major.SetFont(&m_Font,true);
	m_add_gradtime.SetFont(&m_Font,true);
	m_add_remark.SetFont(&m_Font,true);

	return TRUE;  // return TRUE unless you set the focus to a control
	// Òì³£: OCX ÊôÐÔÒ³Ó¦·µ»Ø FALSE
}


void CAddExployeeInfoDlg::OnBnClickedButtonAOk()
{
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
	UpdateData(TRUE);
	if(m_e_ygbh.IsEmpty() || m_e_name.IsEmpty() || m_e_sex.IsEmpty() || m_e_nation.IsEmpty() ||\
	   m_e_status.IsEmpty() || m_e_place.IsEmpty() || m_e_title.IsEmpty() ||\
	   m_e_idnumber.IsEmpty() || m_e_birthday.IsEmpty() || m_e_hiredate.IsEmpty() || m_e_telphone.IsEmpty() ||\
	   m_e_address.IsEmpty() || m_e_section.IsEmpty() || m_e_grade.IsEmpty() || m_e_disc.IsEmpty() ||\
	   m_e_school.IsEmpty() || m_e_major.IsEmpty() || m_e_gradtime.IsEmpty() || m_e_remark.IsEmpty())
	{
		MessageBox(_T("所有项都不能为空"));
		return;
	}

	CString m_string;	
	m_string.Format(_T("insert into tb_exployee values('%s','%s','%s','%s','%s','%s','%s',%d,'%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s')"),\
		m_e_ygbh,m_e_name,m_e_sex,m_e_nation,m_e_status,m_e_place,m_e_title,m_e_age,m_e_idnumber,m_e_birthday,\
		m_e_hiredate,m_e_telphone,m_e_address,m_e_section,m_e_grade,m_e_disc,m_e_school,m_e_major,m_e_gradtime,m_e_remark);
	int nLength = m_string.GetLength( );
    int nBytes  = WideCharToMultiByte( CP_ACP, 0, m_string, nLength, NULL, 0, NULL, NULL );
    char * sql = new char[ nBytes + 1];
    memset( sql, 0, nLength + 1 );
    WideCharToMultiByte( CP_OEMCP, 0, m_string, nLength, sql, nBytes, NULL, NULL ); 
    sql[ nBytes ] = 0;

	MySQLConn m_Myconn;	
	m_Myconn.OnInitMySQLConn();
	if(m_Myconn.ExecuteSQL(sql))
	{
	    MessageBox(_T("员工信息添加成功"));
		CDialog::OnOK();
	}
	else
	{
	    MessageBox(_T("员工信息添加失败"));
		CDialog::OnCancel();
	}

	//断开数据库连接
    m_Myconn.ExitMySQLConn();
}


void CAddExployeeInfoDlg::OnBnClickedButtonACancel()
{
	// TODO: ÔÚ´ËÌí¼Ó¿Ø¼þÍ¨Öª´¦Àí³ÌÐò´úÂë
	CDialog::OnCancel();
}

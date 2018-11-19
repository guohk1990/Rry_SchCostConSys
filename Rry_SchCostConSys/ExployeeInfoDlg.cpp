// ExployeeInfoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Rry_SchCostConSys.h"
#include "ExployeeInfoDlg.h"
#include "afxdialogex.h"
#include "MySQLConn.h"

//引用外部变量-员工号
extern CString m_exployee_id_glb;

// CExployeeInfoDlg 对话框

IMPLEMENT_DYNAMIC(CExployeeInfoDlg, CDialogEx)

CExployeeInfoDlg::CExployeeInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CExployeeInfoDlg::IDD, pParent)
{

}

CExployeeInfoDlg::~CExployeeInfoDlg()
{
}

void CExployeeInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_E_YGBH, m_e_ygbh);
	DDX_Control(pDX, IDC_STATIC_E_ADDRESS, m_e_address);
	DDX_Control(pDX, IDC_STATIC_E_BIRTHDAY, m_e_birthday);
	DDX_Control(pDX, IDC_STATIC_E_DISC, m_e_disc);
	DDX_Control(pDX, IDC_STATIC_E_GRADE, m_e_grade);
	DDX_Control(pDX, IDC_STATIC_E_GRADTIME, m_e_gradtime);
	DDX_Control(pDX, IDC_STATIC_E_HIREDATE, m_e_hiredate);
	DDX_Control(pDX, IDC_STATIC_E_IDNUMBER, m_e_idnumber);
	DDX_Control(pDX, IDC_STATIC_E_MAJOR, m_e_major);
	DDX_Control(pDX, IDC_STATIC_E_NAME, m_e_name);
	DDX_Control(pDX, IDC_STATIC_E_NATION, m_e_nation);
	DDX_Control(pDX, IDC_STATIC_E_PLACE, m_e_place);
	DDX_Control(pDX, IDC_STATIC_E_POLSTATUS, m_e_polstatus);
	DDX_Control(pDX, IDC_STATIC_E_REMARK, m_e_remark);
	DDX_Control(pDX, IDC_STATIC_E_SCHOOL, m_e_school);
	DDX_Control(pDX, IDC_STATIC_E_SECTION, m_e_section);
	DDX_Control(pDX, IDC_STATIC_E_SEX, m_e_sex);
	DDX_Control(pDX, IDC_STATIC_E_TEACHAGE, m_e_teachage);
	DDX_Control(pDX, IDC_STATIC_E_TELPHONE, m_e_telphone);
	DDX_Control(pDX, IDC_STATIC_E_TITLE, m_e_title);
}


BEGIN_MESSAGE_MAP(CExployeeInfoDlg, CDialogEx)
END_MESSAGE_MAP()


// CExployeeInfoDlg 消息处理程序


BOOL CExployeeInfoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CString m_exployee_info_temp[20][1];

	// TODO:  ÔÚ´ËÌí¼Ó¶îÍâµÄ³õÊ¼»¯
	m_Font.CreatePointFont(200, TEXT("黑体"), NULL);
	m_e_ygbh.SetFont(&m_Font,true);
	m_e_name.SetFont(&m_Font,true);
	m_e_sex.SetFont(&m_Font,true);
	m_e_nation.SetFont(&m_Font,true);
	m_e_polstatus.SetFont(&m_Font,true);
	m_e_place.SetFont(&m_Font,true);
	m_e_title.SetFont(&m_Font,true);
	m_e_teachage.SetFont(&m_Font,true);
	m_e_idnumber.SetFont(&m_Font,true);
	m_e_birthday.SetFont(&m_Font,true);
	m_e_hiredate.SetFont(&m_Font,true);
	m_e_telphone.SetFont(&m_Font,true);
	m_e_address.SetFont(&m_Font,true);
	m_e_section.SetFont(&m_Font,true);
	m_e_grade.SetFont(&m_Font,true);
	m_e_disc.SetFont(&m_Font,true);
	m_e_school.SetFont(&m_Font,true);
	m_e_major.SetFont(&m_Font,true);
	m_e_gradtime.SetFont(&m_Font,true);
	m_e_remark.SetFont(&m_Font,true);

	CString m_string;	
	m_string.Format(_T("select * from tb_exployee where exployee_id = '%s'"), m_exployee_id_glb);
	const size_t strsize = ( m_string.GetLength() + 1 ) * 2; // 宽字符的长度;
    char * sql = new char[strsize]; //分配空间; 
    size_t sz = 0;
    wcstombs_s( &sz, sql, strsize, m_string, _TRUNCATE );

	MySQLConn m_Myconn;
	m_Myconn.OnInitMySQLConn();
	int files = m_Myconn.GetRecordFields(sql);
	m_Myconn.row = mysql_fetch_row(m_Myconn.res);
	for(int i = 0; i < files; i++)
	{
	    m_exployee_info_temp[i][0] = m_Myconn.row[i];
	}

	m_e_ygbh.SetWindowText(m_exployee_info_temp[0][0]);
	m_e_name.SetWindowText(m_exployee_info_temp[1][0]);
	m_e_sex.SetWindowText(m_exployee_info_temp[2][0]);
	m_e_nation.SetWindowText(m_exployee_info_temp[3][0]);
	m_e_polstatus.SetWindowText(m_exployee_info_temp[4][0]);
	m_e_place.SetWindowText(m_exployee_info_temp[5][0]);
	m_e_title.SetWindowText(m_exployee_info_temp[6][0]);
	m_e_teachage.SetWindowText(m_exployee_info_temp[7][0]);
	m_e_idnumber.SetWindowText(m_exployee_info_temp[8][0]);
	m_e_birthday.SetWindowText(m_exployee_info_temp[9][0]);
	m_e_hiredate.SetWindowText(m_exployee_info_temp[10][0]);
	m_e_telphone.SetWindowText(m_exployee_info_temp[11][0]);
	m_e_address.SetWindowText(m_exployee_info_temp[12][0]);
	m_e_section.SetWindowText(m_exployee_info_temp[13][0]);
	m_e_grade.SetWindowText(m_exployee_info_temp[14][0]);
	m_e_disc.SetWindowText(m_exployee_info_temp[15][0]);
	m_e_school.SetWindowText(m_exployee_info_temp[16][0]);
	m_e_major.SetWindowText(m_exployee_info_temp[17][0]);
	m_e_gradtime.SetWindowText(m_exployee_info_temp[18][0]);
	m_e_remark.SetWindowText(m_exployee_info_temp[19][0]);

	//断开数据库连接
    m_Myconn.ExitMySQLConn();

	return TRUE;  // return TRUE unless you set the focus to a control
	// Òì³£: OCX ÊôÐÔÒ³Ó¦·µ»Ø FALSE
}

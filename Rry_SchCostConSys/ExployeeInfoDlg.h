#pragma once


// CExployeeInfoDlg 对话框

class CExployeeInfoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CExployeeInfoDlg)

public:
	CExployeeInfoDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CExployeeInfoDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_YGXX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CFont m_Font;
	CStatic m_e_ygbh;
	virtual BOOL OnInitDialog();
	CStatic m_e_address;
	CStatic m_e_birthday;
	CStatic m_e_disc;
	CStatic m_e_grade;
	CStatic m_e_gradtime;
	CStatic m_e_hiredate;
	CStatic m_e_idnumber;
	CStatic m_e_major;
	CStatic m_e_name;
	CStatic m_e_nation;
	CStatic m_e_place;
	CStatic m_e_polstatus;
	CStatic m_e_remark;
	CStatic m_e_school;
	CStatic m_e_section;
	CStatic m_e_sex;
	CStatic m_e_teachage;
	CStatic m_e_telphone;
	CStatic m_e_title;
};

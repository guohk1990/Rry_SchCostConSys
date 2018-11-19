#pragma once
#include "afxwin.h"


// CAddExployeeInfoDlg 对话框

class CAddExployeeInfoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddExployeeInfoDlg)

public:
	CAddExployeeInfoDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddExployeeInfoDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_ADD_YGXX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CFont m_Font;
	CButton m_add_ok;
	CButton m_add_cancel;
	CEdit m_add_address;
	CEdit m_add_age;
	CEdit m_add_birthday;
	CEdit m_add_disc;
	CEdit m_add_grade;
	CEdit m_add_gradtime;
	CEdit m_add_hiredate;
	CEdit m_add_major;
	CEdit m_add_name;
	CEdit m_add_nation;
	CEdit m_add_place;
	CEdit m_add_remark;
	CEdit m_add_school;
	CEdit m_add_section;
	CEdit m_add_sex;
	CEdit m_add_status;
	CEdit m_add_telphone;
	CEdit m_add_title;
	CEdit m_add_ygbh;
	CEdit m_add_idnumber;
	CString m_e_address;
//	CString m_e_age;
	CString m_e_birthday;
	CString m_e_disc;
	CString m_e_grade;
	CString m_e_gradtime;
	CString m_e_hiredate;
	CString m_e_major;
	CString m_e_name;
	CString m_e_nation;
	CString m_e_place;
	CString m_e_remark;
	CString m_e_school;
	CString m_e_section;
	CString m_e_sex;
	CString m_e_status;
	CString m_e_telphone;
	CString m_e_title;
	CString m_e_ygbh;
	afx_msg void OnBnClickedButtonAOk();
	CString m_e_idnumber;
	afx_msg void OnBnClickedButtonACancel();
	int m_e_age;
};

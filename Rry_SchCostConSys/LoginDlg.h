#pragma once


// CLoginDlg 对话框

class CLoginDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLoginDlg)

public:
	CLoginDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLoginDlg();

// 对话框数据
	enum { IDD = IDD_RRY_SCHCOSTCONSYS_DIALOG_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
//	char    sql[500];
	int     m_result;
	int     m_Time;
	CBrush  m_Brush_user;
	CBrush  m_Brush_passwd;
	CFont   m_Font_user;
	CFont   m_Font_passwd;
	CString m_passwd;
	CString m_user;
	CStatic m_static_user;
	CStatic m_static_passwd;
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnClickedButtonLogin();
	afx_msg void OnClickedButtonReset();
};

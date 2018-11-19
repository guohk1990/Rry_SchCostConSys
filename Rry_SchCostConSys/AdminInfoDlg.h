#pragma once
#include "afxcmn.h"


// CAdminInfoDlg 对话框

class CAdminInfoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAdminInfoDlg)

public:
	CAdminInfoDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAdminInfoDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_GLYXX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_Grid;
	virtual BOOL OnInitDialog();
	void AddToGrid(void);
	afx_msg void OnBnClickedButtonGlyAdd();
	afx_msg void OnBnClickedButtonGlyUpdate();
	afx_msg void OnBnClickedButtonGlyDelete();
	afx_msg void OnBnClickedButtonGlyExit();
};

#pragma once
#include "afxcmn.h"


// CAdminInfoDlg �Ի���

class CAdminInfoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAdminInfoDlg)

public:
	CAdminInfoDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAdminInfoDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_GLYXX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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

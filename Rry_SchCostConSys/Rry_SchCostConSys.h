
// Rry_SchCostConSys.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CRry_SchCostConSysApp:
// �йش����ʵ�֣������ Rry_SchCostConSys.cpp
//

class CRry_SchCostConSysApp : public CWinApp
{
public:
	CRry_SchCostConSysApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CRry_SchCostConSysApp theApp;
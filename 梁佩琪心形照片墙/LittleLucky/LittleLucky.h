
// LittleLucky.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CLittleLuckyApp:
// �йش����ʵ�֣������ LittleLucky.cpp
//

class CLittleLuckyApp : public CWinApp
{
public:
	CLittleLuckyApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CLittleLuckyApp theApp;
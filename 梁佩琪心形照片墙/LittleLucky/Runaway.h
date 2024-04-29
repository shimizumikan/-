#pragma once
#include "BackGround.h"
#include "newbutton2.h"


// CRunaway 对话框

class CRunaway : public CDialogEx
{
	DECLARE_DYNAMIC(CRunaway)

public:
	CRunaway(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRunaway();

// 对话框数据
	enum { IDD = IDD_DIALOG_RUNAWAY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
public:
	CBackGround bk3;
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CNewButton2 m_btn1;
	afx_msg void OnBnClickedButtonYes();
	afx_msg void OnClose();
};

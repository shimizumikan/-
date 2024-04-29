#pragma once
#include "afxwin.h"


// CMindTwo 对话框

class CMindTwo : public CDialogEx
{
	DECLARE_DYNAMIC(CMindTwo)

public:
	CMindTwo(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMindTwo();

// 对话框数据
	enum { IDD = IDD_DIALOG_MINDTWO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnStnClickedStaticMindtwo();
	afx_msg void OnPaint();
	CStatic m_mindTwoPiture;
};

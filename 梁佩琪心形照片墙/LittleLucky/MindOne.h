#pragma once
#include "afxwin.h"


// CMindOne 对话框

class CMindOne : public CDialogEx
{
	DECLARE_DYNAMIC(CMindOne)

public:
	CMindOne(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMindOne();

// 对话框数据
	enum { IDD = IDD_DIALOG_MIND1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnBnClickedOk();
	afx_msg void OnStnClickedStaticMindone();
	CStatic m_mindonePiture;
};

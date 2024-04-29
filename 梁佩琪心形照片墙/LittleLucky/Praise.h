#pragma once
#include "BackGround.h"
#include "afxwin.h"


// CPraise 对话框

class CPraise : public CDialogEx
{
	DECLARE_DYNAMIC(CPraise)

public:
	CPraise(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPraise();

// 对话框数据
	enum { IDD = IDD_DIALOG_PRAISE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
public:
	CBackGround bk2;
	afx_msg void OnBnClickedButtonAdvan();
	int nCount;
	afx_msg void OnBnClickedOk();
	CStatic m_meiPicture;
	int m_nNumber;
};

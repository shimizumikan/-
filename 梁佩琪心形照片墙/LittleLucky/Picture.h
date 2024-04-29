#pragma once
#include "BackGround.h"
#include "afxwin.h"


// CPicture 对话框

class CPicture : public CDialogEx
{
	DECLARE_DYNAMIC(CPicture)

public:
	CPicture(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPicture();

// 对话框数据
	enum { IDD = IDD_DIALOG_PICTURE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CBackGround bk3;
	afx_msg void OnPaint();
	afx_msg void OnBnClickedOk();
	CStatic m_cao2Picture;
	afx_msg void OnStnClickedStaticPicture();
};

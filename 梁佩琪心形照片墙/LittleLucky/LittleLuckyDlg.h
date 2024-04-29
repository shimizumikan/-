
// LittleLuckyDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "BackGround.h"

// CLittleLuckyDlg 对话框
class CLittleLuckyDlg : public CDialogEx
{
// 构造
public:
	CLittleLuckyDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_LITTLELUCKY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CBackGround bk1;
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CStatic m_zhangPicture;
	CStatic m_zhuPicture;
	CStatic m_yuePicture;
	CStatic m_caoPicture;
	afx_msg void OnStnClickedStaticZhang();
	afx_msg void OnStnClickedStaticZhu();
	afx_msg void OnStnClickedStaticYue();
	afx_msg void OnStnClickedStaticCao();
	afx_msg void OnBnClickedOk();
};

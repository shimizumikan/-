#pragma once


// CMyLove 对话框

class CMyLove : public CDialogEx
{
	DECLARE_DYNAMIC(CMyLove)

public:
	CMyLove(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMyLove();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};

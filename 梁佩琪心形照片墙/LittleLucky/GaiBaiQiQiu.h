#pragma once


// CGaiBaiQiQiu 对话框

class CGaiBaiQiQiu : public CDialogEx
{
	DECLARE_DYNAMIC(CGaiBaiQiQiu)

public:
	CGaiBaiQiQiu(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CGaiBaiQiQiu();

// 对话框数据
	enum { IDD = IDD_DIALOG_GAOBAIQIQIU };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};

#pragma once


// CGaiBaiQiQiu �Ի���

class CGaiBaiQiQiu : public CDialogEx
{
	DECLARE_DYNAMIC(CGaiBaiQiQiu)

public:
	CGaiBaiQiQiu(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CGaiBaiQiQiu();

// �Ի�������
	enum { IDD = IDD_DIALOG_GAOBAIQIQIU };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};

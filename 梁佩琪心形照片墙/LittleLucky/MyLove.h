#pragma once


// CMyLove �Ի���

class CMyLove : public CDialogEx
{
	DECLARE_DYNAMIC(CMyLove)

public:
	CMyLove(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMyLove();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};

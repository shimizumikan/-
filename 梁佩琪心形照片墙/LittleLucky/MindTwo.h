#pragma once
#include "afxwin.h"


// CMindTwo �Ի���

class CMindTwo : public CDialogEx
{
	DECLARE_DYNAMIC(CMindTwo)

public:
	CMindTwo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMindTwo();

// �Ի�������
	enum { IDD = IDD_DIALOG_MINDTWO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnStnClickedStaticMindtwo();
	afx_msg void OnPaint();
	CStatic m_mindTwoPiture;
};

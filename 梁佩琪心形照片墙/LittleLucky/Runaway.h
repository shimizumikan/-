#pragma once
#include "BackGround.h"
#include "newbutton2.h"


// CRunaway �Ի���

class CRunaway : public CDialogEx
{
	DECLARE_DYNAMIC(CRunaway)

public:
	CRunaway(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRunaway();

// �Ի�������
	enum { IDD = IDD_DIALOG_RUNAWAY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
public:
	CBackGround bk3;
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CNewButton2 m_btn1;
	afx_msg void OnBnClickedButtonYes();
	afx_msg void OnClose();
};

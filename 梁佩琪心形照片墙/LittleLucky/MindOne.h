#pragma once
#include "afxwin.h"


// CMindOne �Ի���

class CMindOne : public CDialogEx
{
	DECLARE_DYNAMIC(CMindOne)

public:
	CMindOne(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMindOne();

// �Ի�������
	enum { IDD = IDD_DIALOG_MIND1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnBnClickedOk();
	afx_msg void OnStnClickedStaticMindone();
	CStatic m_mindonePiture;
};

#pragma once
#include "BackGround.h"


// CMarryMe �Ի���

class CMarryMe : public CDialogEx
{
	DECLARE_DYNAMIC(CMarryMe)

public:
	CMarryMe(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMarryMe();

// �Ի�������
	enum { IDD = IDD_DIALOG_MARRYME };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnBnClickedOk();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

public:
	CBackGround bk4;
	afx_msg void OnBnClickedButtonAgreen();
	afx_msg void OnBnClickedButtonDisagreen();
public:
	int nCount;
	afx_msg void OnClose();
};

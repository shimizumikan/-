#pragma once
#include "BackGround.h"
#include "afxwin.h"


// CPicture �Ի���

class CPicture : public CDialogEx
{
	DECLARE_DYNAMIC(CPicture)

public:
	CPicture(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPicture();

// �Ի�������
	enum { IDD = IDD_DIALOG_PICTURE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CBackGround bk3;
	afx_msg void OnPaint();
	afx_msg void OnBnClickedOk();
	CStatic m_cao2Picture;
	afx_msg void OnStnClickedStaticPicture();
};

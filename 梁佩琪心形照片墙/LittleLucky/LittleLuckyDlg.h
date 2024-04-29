
// LittleLuckyDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "BackGround.h"

// CLittleLuckyDlg �Ի���
class CLittleLuckyDlg : public CDialogEx
{
// ����
public:
	CLittleLuckyDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_LITTLELUCKY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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

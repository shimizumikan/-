// Runaway.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LittleLucky.h"
#include "Runaway.h"
#include "afxdialogex.h"
#include "MindOne.h"


// CRunaway �Ի���

IMPLEMENT_DYNAMIC(CRunaway, CDialogEx)

CRunaway::CRunaway(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRunaway::IDD, pParent)
{
		bk3.Init();
}

CRunaway::~CRunaway()
{
}

void CRunaway::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_NO, m_btn1);
}


BEGIN_MESSAGE_MAP(CRunaway, CDialogEx)
	ON_BN_CLICKED(IDOK, &CRunaway::OnBnClickedOk)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON_YES, &CRunaway::OnBnClickedButtonYes)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CRunaway ��Ϣ�������


void CRunaway::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void CRunaway::OnPaint()
{
	CPaintDC dc(this); // device context for painting

		// TODO: �ڴ˴������Ϣ����������
		// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	CRect rect;  
	GetClientRect(rect);  
	dc.FillSolidRect(rect,RGB(255,255,255));   //����Ϊ�ױ���
}


HBRUSH CRunaway::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	//�޸�static�ؼ��ı���ɫ
	if (pWnd->GetDlgCtrlID() == IDC_STATIC_CHASE)
	{
		bk3.SetCtrlBK(pDC);
		HBRUSH brush = bk3.m_brush;
		return brush;
	}
	return hbr;
}


void CRunaway::OnBnClickedButtonYes()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	MessageBox(_T("���� �󱿵��� ����˵�������ﻰ�˰ɣ�"));

	CMindOne *mindOne = new CMindOne(); 
	this->ShowWindow(SW_HIDE);
	mindOne->DoModal();
	OnBnClickedOk();
}


void CRunaway::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	MessageBox(_T("û�����ѡ��"));
	//CDialogEx::OnClose();
}

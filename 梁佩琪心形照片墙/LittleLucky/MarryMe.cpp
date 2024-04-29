// MarryMe.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LittleLucky.h"
#include "MarryMe.h"
#include "afxdialogex.h"
#include "GaiBaiQiQiu.h"
#include "Romantic.h"


// CMarryMe �Ի���

IMPLEMENT_DYNAMIC(CMarryMe, CDialogEx)

CMarryMe::CMarryMe(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMarryMe::IDD, pParent)
{
	bk4.Init();
	nCount = 1;
}

CMarryMe::~CMarryMe()
{
}

void CMarryMe::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMarryMe, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDOK, &CMarryMe::OnBnClickedOk)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON_AGREEN, &CMarryMe::OnBnClickedButtonAgreen)
	ON_BN_CLICKED(IDC_BUTTON_DISAGREEN, &CMarryMe::OnBnClickedButtonDisagreen)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CMarryMe ��Ϣ�������


void CMarryMe::OnPaint()
{
	CPaintDC dc(this); // device context for painting
		// TODO: �ڴ˴������Ϣ����������
		// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	//�޸ĶԻ��򱳾���ɫΪ��ɫ
	CRect rect;  
	GetClientRect(rect);  
	dc.FillSolidRect(rect,RGB(255,255,255));   //����Ϊ�ױ���
}


void CMarryMe::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


HBRUSH CMarryMe::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������

	//�޸�static�ؼ��ı���ɫ
	if (pWnd->GetDlgCtrlID() == IDC_STATIC_MARRYME)
	{
		bk4.SetCtrlBK(pDC);
		HBRUSH brush = bk4.m_brush;
		return brush;
	}
	//�޸�static�ؼ��ı���ɫ
	if (pWnd->GetDlgCtrlID() == IDC_STATI_YUANYI)
	{
		bk4.SetCtrlBK(pDC);
		HBRUSH brush = bk4.m_brush;
		return brush;
	}
	
	return hbr;
}


void CMarryMe::OnBnClickedButtonAgreen()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	MessageBox(_T("��Ӧ�˲�����Ŷ��������~"));
	MessageBox(_T("���㳪�׸�ɣ�����5���ӣ�����Ҫ����һ�� ����~"));
	this->ShowWindow(SW_HIDE);
	CRomantic romantic;
	romantic.ShowLove();
	MessageBox(_T("   Bye Bye!"));
	OnBnClickedOk();
}


void CMarryMe::OnBnClickedButtonDisagreen()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	switch(nCount){
	case 1:	
		MessageBox(_T("        ��������"));
		nCount++;
		break; 
	case 2:	
		MessageBox(_T("        ���㵹ϴ��ˮ"));
		nCount++;
		break; 
	case 3:
		MessageBox(_T("        ����д������"));
		nCount++;
		break; 
	case 4:
		MessageBox(_T("        ���ʹ����"));
		nCount = 1;
		break; 

		// ������������������ case ���
	default : // ��ѡ��
		break; 
	}
}


void CMarryMe::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
		MessageBox(_T("   ��ͬ�ⲻ׼�أ�"));
	//CDialogEx::OnClose();
}

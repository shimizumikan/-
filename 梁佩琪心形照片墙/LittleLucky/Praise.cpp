// Praise.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LittleLucky.h"
#include "Praise.h"
#include "afxdialogex.h"
#include "Runaway.h"


// CPraise �Ի���

IMPLEMENT_DYNAMIC(CPraise, CDialogEx)

CPraise::CPraise(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPraise::IDD, pParent)
{
	// m_hIcon  =  AfxGetApp() -> LoadIcon( IDI_ICON_FLOWER);
	//��ʼ����ˢ������
	bk2.Init();
	nCount = 1;
	m_nNumber = 1;
}

CPraise::~CPraise()
{
}

void CPraise::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_MEI, m_meiPicture);
}


BEGIN_MESSAGE_MAP(CPraise, CDialogEx)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON_ADVAN, &CPraise::OnBnClickedButtonAdvan)
	ON_BN_CLICKED(IDOK, &CPraise::OnBnClickedOk)
END_MESSAGE_MAP()


// CPraise ��Ϣ�������


void CPraise::OnPaint()
{
	CPaintDC dc(this); // device context for painting
		// TODO: �ڴ˴������Ϣ����������
		// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	//�޸ĶԻ��򱳾���ɫΪ��ɫ
	CRect rect;  
	GetClientRect(rect);  
	dc.FillSolidRect(rect,RGB(255,255,255));   //����Ϊ�ױ���

	//��ʼ��λͼ
	CBitmap bitmap1;  // CBitmap�������ڼ���λͼ   
	HBITMAP hBmp1;    // ����CBitmap���ص�λͼ�ľ��   
	switch(nCount){
	case 1:
		bitmap1.LoadBitmap(IDB_BITMAP_YUE2);   
		break; 
	case 2:
		bitmap1.LoadBitmap(IDB_BITMAP_CAO3);   
		break; 
	case 3:
		bitmap1.LoadBitmap(IDB_BITMAP_CAO4);   
		break; 
	case 4:
		bitmap1.LoadBitmap(IDB_BITMAP_CAO5);     
		break; 
	case 5:
		bitmap1.LoadBitmap(IDB_BITMAP_CAO6);   
		break; 
	case 6:
		bitmap1.LoadBitmap(IDB_BITMAP_CAO7);   
		break; 
	default :
		break; 
	}
	hBmp1 = (HBITMAP)bitmap1.GetSafeHandle();  // ��ȡbitmap����λͼ�ľ��   
	m_meiPicture.SetBitmap(hBmp1);    // ����ͼƬ�ؼ�m_jzmPicture��λͼͼƬΪIDB_BITMAP1 
}




HBRUSH CPraise::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	if (pWnd->GetDlgCtrlID() == IDC_STATIC_ADVANTAGE)
	{
		bk2.SetCtrlBK(pDC);
		HBRUSH brush = bk2.m_brush;
		return brush;
	}

	if (pWnd->GetDlgCtrlID() == IDC_BUTTON_ADVAN)
	{
		bk2.SetCtrlBK(pDC);
		HBRUSH brush = bk2.m_brush;
		return brush;
	}
	return hbr;
	// || pWnd->GetDlgCtrlID() == IDC_BUTTON_ADVAN
}


void CPraise::OnBnClickedButtonAdvan()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	switch(nCount){
	case 1:
		nCount++;
		OnPaint();
		MessageBox(_T("        ���~����"));
		break; 
	case 2:
	    nCount++;
		OnPaint();
		MessageBox(_T("        �A���A��"));
		break; 
	case 3:
		nCount++;
		OnPaint();
		MessageBox(_T("        ��������"));
		break; 
	case 4:
		nCount++;
		OnPaint();
		MessageBox(_T("        �^������"));
		break; 
	case 5:
		nCount++;
		OnPaint();
		MessageBox(_T("        �������"));
		break; 

		// ������������������ case ���
	default : // ��ѡ��

		CRunaway *dlgRunaway = new CRunaway(); 

		this->ShowWindow(SW_HIDE);

		dlgRunaway->DoModal();
		OnBnClickedOk();
	}
}


void CPraise::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}

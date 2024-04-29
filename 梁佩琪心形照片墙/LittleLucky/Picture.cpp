// Picture.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LittleLucky.h"
#include "Picture.h"
#include "afxdialogex.h"
#include "Praise.h"


// CPicture �Ի���

IMPLEMENT_DYNAMIC(CPicture, CDialogEx)

CPicture::CPicture(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPicture::IDD, pParent)
{
	bk3.Init();
}

CPicture::~CPicture()
{
}

void CPicture::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_PICTURE, m_cao2Picture);
}


BEGIN_MESSAGE_MAP(CPicture, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDOK, &CPicture::OnBnClickedOk)
	ON_STN_CLICKED(IDC_STATIC_PICTURE, &CPicture::OnStnClickedStaticPicture)
END_MESSAGE_MAP()


// CPicture ��Ϣ�������


void CPicture::OnPaint()
{
	CPaintDC dc(this); // device context for painting

		// TODO: �ڴ˴������Ϣ����������
		// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	//�޸ĶԻ��򱳾���ɫΪ��ɫ
	CRect rect;  
	GetClientRect(rect);  
	dc.FillSolidRect(rect,RGB(255,255,255));   //����Ϊ�ױ���

	//��ʼ��λͼ
	CBitmap bitmap5;  // CBitmap�������ڼ���λͼ   
	HBITMAP hBmp5;    // ����CBitmap���ص�λͼ�ľ��   
	bitmap5.LoadBitmap(IDB_BITMAP_CAO2);  // ��λͼIDB_BITMAP1���ص�bitmap   
	hBmp5 = (HBITMAP)bitmap5.GetSafeHandle();  // ��ȡbitmap����λͼ�ľ��   
	m_cao2Picture.SetBitmap(hBmp5);    // ����ͼƬ�ؼ�m_jzmPicture��λͼͼƬΪIDB_BITMAP1 
}


void CPicture::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void CPicture::OnStnClickedStaticPicture()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CPraise *dlgPra = new CPraise(); 

	this->ShowWindow(SW_HIDE);

	dlgPra->DoModal();
	OnBnClickedOk();
}

// MindTwo.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LittleLucky.h"
#include "MindTwo.h"
#include "afxdialogex.h"
#include "MarryMe.h"


// CMindTwo �Ի���

IMPLEMENT_DYNAMIC(CMindTwo, CDialogEx)

CMindTwo::CMindTwo(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMindTwo::IDD, pParent)
{

}

CMindTwo::~CMindTwo()
{
}

void CMindTwo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_MINDTWO, m_mindTwoPiture);
}


BEGIN_MESSAGE_MAP(CMindTwo, CDialogEx)
	ON_BN_CLICKED(IDOK, &CMindTwo::OnBnClickedOk)
	ON_STN_CLICKED(IDC_STATIC_MINDTWO, &CMindTwo::OnStnClickedStaticMindtwo)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CMindTwo ��Ϣ�������


void CMindTwo::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void CMindTwo::OnStnClickedStaticMindtwo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CMarryMe *marryMe = new CMarryMe(); 
	this->ShowWindow(SW_HIDE);
	marryMe->DoModal();
	OnBnClickedOk();
}


void CMindTwo::OnPaint()
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
	bitmap1.LoadBitmap(IDB_BITMAP_CAO9);  // ��λͼIDB_BITMAP1���ص�bitmap   
	hBmp1 = (HBITMAP)bitmap1.GetSafeHandle();  // ��ȡbitmap����λͼ�ľ��   
	m_mindTwoPiture.SetBitmap(hBmp1);    // ����ͼƬ�ؼ�m_jzmPicture��λͼͼƬΪIDB_BITMAP1 
}

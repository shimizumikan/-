// MindOne.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LittleLucky.h"
#include "MindOne.h"
#include "afxdialogex.h"
#include "MindTwo.h"


// CMindOne �Ի���

IMPLEMENT_DYNAMIC(CMindOne, CDialogEx)

CMindOne::CMindOne(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMindOne::IDD, pParent)
{

}

CMindOne::~CMindOne()
{
}

void CMindOne::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_MINDONE, m_mindonePiture);
}


BEGIN_MESSAGE_MAP(CMindOne, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDOK, &CMindOne::OnBnClickedOk)
	ON_STN_CLICKED(IDC_STATIC_MINDONE, &CMindOne::OnStnClickedStaticMindone)
END_MESSAGE_MAP()


// CMindOne ��Ϣ�������


void CMindOne::OnPaint()
{
	CPaintDC dc(this); // device context for painting
		// TODO: �ڴ˴������Ϣ����������
		// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	//�޸ĶԻ��򱳾���ɫΪ��ɫ
	//�޸ĶԻ��򱳾���ɫΪ��ɫ
	CRect rect;  
	GetClientRect(rect);  
	dc.FillSolidRect(rect,RGB(255,255,255));   //����Ϊ�ױ���

	//��ʼ��λͼ
	CBitmap bitmap1;  // CBitmap�������ڼ���λͼ   
	HBITMAP hBmp1;    // ����CBitmap���ص�λͼ�ľ��   
	bitmap1.LoadBitmap(IDB_BITMAP_MINDONE);  // ��λͼIDB_BITMAP1���ص�bitmap   
	hBmp1 = (HBITMAP)bitmap1.GetSafeHandle();  // ��ȡbitmap����λͼ�ľ��   
	m_mindonePiture.SetBitmap(hBmp1);    // ����ͼƬ�ؼ�m_jzmPicture��λͼͼƬΪIDB_BITMAP1 
}


void CMindOne::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CDialogEx::OnOK();
}


void CMindOne::OnStnClickedStaticMindone()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CMindTwo *mindTwo = new CMindTwo(); 
	this->ShowWindow(SW_HIDE);
	mindTwo->DoModal();
	OnBnClickedOk();
}

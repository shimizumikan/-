 //MyLove.cpp : ʵ���ļ�


#include "stdafx.h"
#include "LittleLucky.h"
#include "MyLove.h"
#include "afxdialogex.h"


 //CMyLove �Ի���

IMPLEMENT_DYNAMIC(CMyLove, CDialogEx)

CMyLove::CMyLove(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMyLove::IDD, pParent)
{

}

CMyLove::~CMyLove()
{
}

void CMyLove::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyLove, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


 //CMyLove ��Ϣ�������


void CMyLove::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	//	 TODO: �ڴ˴������Ϣ����������
	//	 ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	//�޸ĶԻ��򱳾���ɫΪ��ɫ
	CRect rect;  
	GetClientRect(rect);  
	dc.FillSolidRect(rect,RGB(255,255,255));   //����Ϊ�ױ���
}

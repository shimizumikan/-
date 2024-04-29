 //MyLove.cpp : 实现文件


#include "stdafx.h"
#include "LittleLucky.h"
#include "MyLove.h"
#include "afxdialogex.h"


 //CMyLove 对话框

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


 //CMyLove 消息处理程序


void CMyLove::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	//	 TODO: 在此处添加消息处理程序代码
	//	 不为绘图消息调用 CDialogEx::OnPaint()
	//修改对话框背景颜色为白色
	CRect rect;  
	GetClientRect(rect);  
	dc.FillSolidRect(rect,RGB(255,255,255));   //设置为白背景
}

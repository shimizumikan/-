// MindOne.cpp : 实现文件
//

#include "stdafx.h"
#include "LittleLucky.h"
#include "MindOne.h"
#include "afxdialogex.h"
#include "MindTwo.h"


// CMindOne 对话框

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


// CMindOne 消息处理程序


void CMindOne::OnPaint()
{
	CPaintDC dc(this); // device context for painting
		// TODO: 在此处添加消息处理程序代码
		// 不为绘图消息调用 CDialogEx::OnPaint()
	//修改对话框背景颜色为白色
	//修改对话框背景颜色为白色
	CRect rect;  
	GetClientRect(rect);  
	dc.FillSolidRect(rect,RGB(255,255,255));   //设置为白背景

	//初始化位图
	CBitmap bitmap1;  // CBitmap对象，用于加载位图   
	HBITMAP hBmp1;    // 保存CBitmap加载的位图的句柄   
	bitmap1.LoadBitmap(IDB_BITMAP_MINDONE);  // 将位图IDB_BITMAP1加载到bitmap   
	hBmp1 = (HBITMAP)bitmap1.GetSafeHandle();  // 获取bitmap加载位图的句柄   
	m_mindonePiture.SetBitmap(hBmp1);    // 设置图片控件m_jzmPicture的位图图片为IDB_BITMAP1 
}


void CMindOne::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	CDialogEx::OnOK();
}


void CMindOne::OnStnClickedStaticMindone()
{
	// TODO: 在此添加控件通知处理程序代码
	CMindTwo *mindTwo = new CMindTwo(); 
	this->ShowWindow(SW_HIDE);
	mindTwo->DoModal();
	OnBnClickedOk();
}

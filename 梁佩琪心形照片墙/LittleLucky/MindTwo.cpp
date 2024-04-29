// MindTwo.cpp : 实现文件
//

#include "stdafx.h"
#include "LittleLucky.h"
#include "MindTwo.h"
#include "afxdialogex.h"
#include "MarryMe.h"


// CMindTwo 对话框

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


// CMindTwo 消息处理程序


void CMindTwo::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CMindTwo::OnStnClickedStaticMindtwo()
{
	// TODO: 在此添加控件通知处理程序代码
	CMarryMe *marryMe = new CMarryMe(); 
	this->ShowWindow(SW_HIDE);
	marryMe->DoModal();
	OnBnClickedOk();
}


void CMindTwo::OnPaint()
{
	CPaintDC dc(this); // device context for painting
		// TODO: 在此处添加消息处理程序代码
		// 不为绘图消息调用 CDialogEx::OnPaint()
	//修改对话框背景颜色为白色
	CRect rect;  
	GetClientRect(rect);  
	dc.FillSolidRect(rect,RGB(255,255,255));   //设置为白背景

	//初始化位图
	CBitmap bitmap1;  // CBitmap对象，用于加载位图   
	HBITMAP hBmp1;    // 保存CBitmap加载的位图的句柄   
	bitmap1.LoadBitmap(IDB_BITMAP_CAO9);  // 将位图IDB_BITMAP1加载到bitmap   
	hBmp1 = (HBITMAP)bitmap1.GetSafeHandle();  // 获取bitmap加载位图的句柄   
	m_mindTwoPiture.SetBitmap(hBmp1);    // 设置图片控件m_jzmPicture的位图图片为IDB_BITMAP1 
}

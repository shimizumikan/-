// Picture.cpp : 实现文件
//

#include "stdafx.h"
#include "LittleLucky.h"
#include "Picture.h"
#include "afxdialogex.h"
#include "Praise.h"


// CPicture 对话框

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


// CPicture 消息处理程序


void CPicture::OnPaint()
{
	CPaintDC dc(this); // device context for painting

		// TODO: 在此处添加消息处理程序代码
		// 不为绘图消息调用 CDialogEx::OnPaint()
	//修改对话框背景颜色为白色
	CRect rect;  
	GetClientRect(rect);  
	dc.FillSolidRect(rect,RGB(255,255,255));   //设置为白背景

	//初始化位图
	CBitmap bitmap5;  // CBitmap对象，用于加载位图   
	HBITMAP hBmp5;    // 保存CBitmap加载的位图的句柄   
	bitmap5.LoadBitmap(IDB_BITMAP_CAO2);  // 将位图IDB_BITMAP1加载到bitmap   
	hBmp5 = (HBITMAP)bitmap5.GetSafeHandle();  // 获取bitmap加载位图的句柄   
	m_cao2Picture.SetBitmap(hBmp5);    // 设置图片控件m_jzmPicture的位图图片为IDB_BITMAP1 
}


void CPicture::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CPicture::OnStnClickedStaticPicture()
{
	// TODO: 在此添加控件通知处理程序代码
	CPraise *dlgPra = new CPraise(); 

	this->ShowWindow(SW_HIDE);

	dlgPra->DoModal();
	OnBnClickedOk();
}

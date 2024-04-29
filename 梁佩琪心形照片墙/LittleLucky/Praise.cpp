// Praise.cpp : 实现文件
//

#include "stdafx.h"
#include "LittleLucky.h"
#include "Praise.h"
#include "afxdialogex.h"
#include "Runaway.h"


// CPraise 对话框

IMPLEMENT_DYNAMIC(CPraise, CDialogEx)

CPraise::CPraise(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPraise::IDD, pParent)
{
	// m_hIcon  =  AfxGetApp() -> LoadIcon( IDI_ICON_FLOWER);
	//初始化画刷和字体
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


// CPraise 消息处理程序


void CPraise::OnPaint()
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
	hBmp1 = (HBITMAP)bitmap1.GetSafeHandle();  // 获取bitmap加载位图的句柄   
	m_meiPicture.SetBitmap(hBmp1);    // 设置图片控件m_jzmPicture的位图图片为IDB_BITMAP1 
}




HBRUSH CPraise::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
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
	// TODO: 在此添加控件通知处理程序代码
	switch(nCount){
	case 1:
		nCount++;
		OnPaint();
		MessageBox(_T("        沉魚落雁"));
		break; 
	case 2:
	    nCount++;
		OnPaint();
		MessageBox(_T("        傾國傾城"));
		break; 
	case 3:
		nCount++;
		OnPaint();
		MessageBox(_T("        美若天仙"));
		break; 
	case 4:
		nCount++;
		OnPaint();
		MessageBox(_T("        絕代佳人"));
		break; 
	case 5:
		nCount++;
		OnPaint();
		MessageBox(_T("        秀外惠中"));
		break; 

		// 您可以有任意数量的 case 语句
	default : // 可选的

		CRunaway *dlgRunaway = new CRunaway(); 

		this->ShowWindow(SW_HIDE);

		dlgRunaway->DoModal();
		OnBnClickedOk();
	}
}


void CPraise::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}

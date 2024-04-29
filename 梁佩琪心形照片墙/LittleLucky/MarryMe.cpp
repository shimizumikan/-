// MarryMe.cpp : 实现文件
//

#include "stdafx.h"
#include "LittleLucky.h"
#include "MarryMe.h"
#include "afxdialogex.h"
#include "GaiBaiQiQiu.h"
#include "Romantic.h"


// CMarryMe 对话框

IMPLEMENT_DYNAMIC(CMarryMe, CDialogEx)

CMarryMe::CMarryMe(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMarryMe::IDD, pParent)
{
	bk4.Init();
	nCount = 1;
}

CMarryMe::~CMarryMe()
{
}

void CMarryMe::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMarryMe, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDOK, &CMarryMe::OnBnClickedOk)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON_AGREEN, &CMarryMe::OnBnClickedButtonAgreen)
	ON_BN_CLICKED(IDC_BUTTON_DISAGREEN, &CMarryMe::OnBnClickedButtonDisagreen)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CMarryMe 消息处理程序


void CMarryMe::OnPaint()
{
	CPaintDC dc(this); // device context for painting
		// TODO: 在此处添加消息处理程序代码
		// 不为绘图消息调用 CDialogEx::OnPaint()
	//修改对话框背景颜色为白色
	CRect rect;  
	GetClientRect(rect);  
	dc.FillSolidRect(rect,RGB(255,255,255));   //设置为白背景
}


void CMarryMe::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


HBRUSH CMarryMe::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔

	//修改static控件的背景色
	if (pWnd->GetDlgCtrlID() == IDC_STATIC_MARRYME)
	{
		bk4.SetCtrlBK(pDC);
		HBRUSH brush = bk4.m_brush;
		return brush;
	}
	//修改static控件的背景色
	if (pWnd->GetDlgCtrlID() == IDC_STATI_YUANYI)
	{
		bk4.SetCtrlBK(pDC);
		HBRUSH brush = bk4.m_brush;
		return brush;
	}
	
	return hbr;
}


void CMarryMe::OnBnClickedButtonAgreen()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(_T("答应了不许反悔哦！拉勾勾~"));
	MessageBox(_T("给你唱首歌吧！给我5秒钟，我需要酝酿一下 呜呜~"));
	this->ShowWindow(SW_HIDE);
	CRomantic romantic;
	romantic.ShowLove();
	MessageBox(_T("   Bye Bye!"));
	OnBnClickedOk();
}


void CMarryMe::OnBnClickedButtonDisagreen()
{
	// TODO: 在此添加控件通知处理程序代码
	switch(nCount){
	case 1:	
		MessageBox(_T("        给你做饭"));
		nCount++;
		break; 
	case 2:	
		MessageBox(_T("        给你倒洗脚水"));
		nCount++;
		break; 
	case 3:
		MessageBox(_T("        房子写你名字"));
		nCount++;
		break; 
	case 4:
		MessageBox(_T("        工资归你管"));
		nCount = 1;
		break; 

		// 您可以有任意数量的 case 语句
	default : // 可选的
		break; 
	}
}


void CMarryMe::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
		MessageBox(_T("   不同意不准关！"));
	//CDialogEx::OnClose();
}

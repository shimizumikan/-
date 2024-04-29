// Runaway.cpp : 实现文件
//

#include "stdafx.h"
#include "LittleLucky.h"
#include "Runaway.h"
#include "afxdialogex.h"
#include "MindOne.h"


// CRunaway 对话框

IMPLEMENT_DYNAMIC(CRunaway, CDialogEx)

CRunaway::CRunaway(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRunaway::IDD, pParent)
{
		bk3.Init();
}

CRunaway::~CRunaway()
{
}

void CRunaway::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_NO, m_btn1);
}


BEGIN_MESSAGE_MAP(CRunaway, CDialogEx)
	ON_BN_CLICKED(IDOK, &CRunaway::OnBnClickedOk)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON_YES, &CRunaway::OnBnClickedButtonYes)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CRunaway 消息处理程序


void CRunaway::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CRunaway::OnPaint()
{
	CPaintDC dc(this); // device context for painting

		// TODO: 在此处添加消息处理程序代码
		// 不为绘图消息调用 CDialogEx::OnPaint()
	CRect rect;  
	GetClientRect(rect);  
	dc.FillSolidRect(rect,RGB(255,255,255));   //设置为白背景
}


HBRUSH CRunaway::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	//修改static控件的背景色
	if (pWnd->GetDlgCtrlID() == IDC_STATIC_CHASE)
	{
		bk3.SetCtrlBK(pDC);
		HBRUSH brush = bk3.m_brush;
		return brush;
	}
	return hbr;
}


void CRunaway::OnBnClickedButtonYes()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(_T("哈哈 大笨蛋！ 终于说出你心里话了吧！"));

	CMindOne *mindOne = new CMindOne(); 
	this->ShowWindow(SW_HIDE);
	mindOne->DoModal();
	OnBnClickedOk();
}


void CRunaway::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	MessageBox(_T("没有这个选项"));
	//CDialogEx::OnClose();
}

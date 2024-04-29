// GaiBaiQiQiu.cpp : 实现文件
//

#include "stdafx.h"
#include "LittleLucky.h"
#include "GaiBaiQiQiu.h"
#include "afxdialogex.h"


// CGaiBaiQiQiu 对话框

IMPLEMENT_DYNAMIC(CGaiBaiQiQiu, CDialogEx)

CGaiBaiQiQiu::CGaiBaiQiQiu(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGaiBaiQiQiu::IDD, pParent)
{

}

CGaiBaiQiQiu::~CGaiBaiQiQiu()
{
}

void CGaiBaiQiQiu::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGaiBaiQiQiu, CDialogEx)
	ON_BN_CLICKED(IDOK, &CGaiBaiQiQiu::OnBnClickedOk)
END_MESSAGE_MAP()


// CGaiBaiQiQiu 消息处理程序


void CGaiBaiQiQiu::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}

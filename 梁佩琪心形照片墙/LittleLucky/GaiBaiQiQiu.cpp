// GaiBaiQiQiu.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LittleLucky.h"
#include "GaiBaiQiQiu.h"
#include "afxdialogex.h"


// CGaiBaiQiQiu �Ի���

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


// CGaiBaiQiQiu ��Ϣ�������


void CGaiBaiQiQiu::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}

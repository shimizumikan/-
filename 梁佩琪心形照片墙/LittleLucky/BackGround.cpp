#include "stdafx.h"
#include "BackGround.h"


CBackGround::CBackGround(void)
{
}


CBackGround::~CBackGround(void)
{
}

void CBackGround::SetCtrlBK(CDC* pDC)
{
	pDC->SetTextColor(RGB(255,0,0));//����������ɫ
	pDC->SetBkMode(TRANSPARENT);    //���ؼ���������Ϊ͸��
	pDC->SelectObject(&m_font);
}

void CBackGround::Init()
{
	//��ʼ����ˢ������
	m_brush.CreateSolidBrush(RGB(255,255,255));
	m_font.CreatePointFont(150,_T("����"));
}


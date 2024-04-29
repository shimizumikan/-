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
	pDC->SetTextColor(RGB(255,0,0));//设置字体颜色
	pDC->SetBkMode(TRANSPARENT);    //将控件背景设置为透明
	pDC->SelectObject(&m_font);
}

void CBackGround::Init()
{
	//初始化画刷和字体
	m_brush.CreateSolidBrush(RGB(255,255,255));
	m_font.CreatePointFont(150,_T("宋体"));
}


#pragma once
#ifndef CBACKGROUND_H_H
#define CBACKGROUND_H_H
class CBackGround
{
public:
	CBackGround(void);
	virtual ~CBackGround(void);
public:
	void SetCtrlBK(CDC* pDC);
	void Init();
public:
	CBrush m_brush;
	CFont m_font;
};

#endif

#pragma once
#include "afxwin.h"
class CNewButton2 :
	public CButton
{
public:
	CNewButton2(void);
	virtual ~CNewButton2(void);
	DECLARE_MESSAGE_MAP()
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};


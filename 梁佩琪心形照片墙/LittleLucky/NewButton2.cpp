#include "stdafx.h"
#include "NewButton2.h"


CNewButton2::CNewButton2(void)
{
}


CNewButton2::~CNewButton2(void)
{
}
BEGIN_MESSAGE_MAP(CNewButton2, CButton)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


void CNewButton2::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	//逃跑按钮的实现
	CRect rectBtn; 
	CRect rectDialog; 

	//获取按钮和对话框的尺寸坐标        
	GetWindowRect(&rectBtn); 
	GetParent()->GetWindowRect(&rectDialog); 
	//将相对于屏幕的尺寸大小转换为相对于对话框窗口的        
	ScreenToClient(rectBtn); 
	ScreenToClient(rectDialog); 

	//获取一个相对于对话框大小的一个随机坐标        
	int x = rand() % rectDialog.right; 
	//保证整个按钮完整的显示在对话框内部        
	if(x > rectDialog.right - rectBtn.right)     
		x -= rectBtn.right; 

	int y = rand() % rectDialog.bottom; 
	if(y > rectDialog.right - rectBtn.bottom)       
		y -= rectBtn.bottom; 

	//不改变尺寸，不改变Z次序        
	SetWindowPos(NULL, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER); 

	CButton::OnMouseMove(nFlags, point);
}

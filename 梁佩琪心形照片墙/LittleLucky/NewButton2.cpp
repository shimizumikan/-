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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	//���ܰ�ť��ʵ��
	CRect rectBtn; 
	CRect rectDialog; 

	//��ȡ��ť�ͶԻ���ĳߴ�����        
	GetWindowRect(&rectBtn); 
	GetParent()->GetWindowRect(&rectDialog); 
	//���������Ļ�ĳߴ��Сת��Ϊ����ڶԻ��򴰿ڵ�        
	ScreenToClient(rectBtn); 
	ScreenToClient(rectDialog); 

	//��ȡһ������ڶԻ����С��һ���������        
	int x = rand() % rectDialog.right; 
	//��֤������ť��������ʾ�ڶԻ����ڲ�        
	if(x > rectDialog.right - rectBtn.right)     
		x -= rectBtn.right; 

	int y = rand() % rectDialog.bottom; 
	if(y > rectDialog.right - rectBtn.bottom)       
		y -= rectBtn.bottom; 

	//���ı�ߴ磬���ı�Z����        
	SetWindowPos(NULL, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER); 

	CButton::OnMouseMove(nFlags, point);
}

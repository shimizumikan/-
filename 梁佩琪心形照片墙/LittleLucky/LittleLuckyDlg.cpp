
// LittleLuckyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LittleLucky.h"
#include "LittleLuckyDlg.h"
#include "afxdialogex.h"
#include "Picture.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CLittleLuckyDlg 对话框



CLittleLuckyDlg::CLittleLuckyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLittleLuckyDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON_FLOWER);

	//初始化画刷和字体
	bk1.Init();

	
}

void CLittleLuckyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_ZHANG, m_zhangPicture);
	DDX_Control(pDX, IDC_STATIC_ZHU, m_zhuPicture);
	DDX_Control(pDX, IDC_STATIC_YUE, m_yuePicture);
	DDX_Control(pDX, IDC_STATIC_CAO, m_caoPicture);
}

BEGIN_MESSAGE_MAP(CLittleLuckyDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	ON_STN_CLICKED(IDC_STATIC_ZHANG, &CLittleLuckyDlg::OnStnClickedStaticZhang)
	ON_STN_CLICKED(IDC_STATIC_ZHU, &CLittleLuckyDlg::OnStnClickedStaticZhu)
	ON_STN_CLICKED(IDC_STATIC_YUE, &CLittleLuckyDlg::OnStnClickedStaticYue)
	ON_STN_CLICKED(IDC_STATIC_CAO, &CLittleLuckyDlg::OnStnClickedStaticCao)
	ON_BN_CLICKED(IDOK, &CLittleLuckyDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CLittleLuckyDlg 消息处理程序

BOOL CLittleLuckyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CLittleLuckyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CLittleLuckyDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//修改对话框背景颜色为白色
		CWnd* pWnd = FindWindow(NULL, _T("LittleLucky"));
		CRect rect;  
		CPaintDC dc(pWnd);  
		GetClientRect(rect);  
		dc.FillSolidRect(rect,RGB(255,255,255));   //设置为白背景

		//初始化位图
		CBitmap bitmap1;  // CBitmap对象，用于加载位图   
		HBITMAP hBmp1;    // 保存CBitmap加载的位图的句柄   
		bitmap1.LoadBitmap(IDB_BITMAP_ZHANG);  // 将位图IDB_BITMAP1加载到bitmap   
		hBmp1 = (HBITMAP)bitmap1.GetSafeHandle();  // 获取bitmap加载位图的句柄   
		m_zhangPicture.SetBitmap(hBmp1);    // 设置图片控件m_jzmPicture的位图图片为IDB_BITMAP1 

		CBitmap bitmap2;  // CBitmap对象，用于加载位图   
		HBITMAP hBmp2;    // 保存CBitmap加载的位图的句柄   
		bitmap2.LoadBitmap(IDB_BITMAP_ZHU);  // 将位图IDB_BITMAP1加载到bitmap   
		hBmp2 = (HBITMAP)bitmap2.GetSafeHandle();  // 获取bitmap加载位图的句柄   
		m_zhuPicture.SetBitmap(hBmp2);    // 设置图片控件m_jzmPicture的位图图片为IDB_BITMAP1 

		CBitmap bitmap3;  // CBitmap对象，用于加载位图   
		HBITMAP hBmp3;    // 保存CBitmap加载的位图的句柄   
		bitmap3.LoadBitmap(IDB_BITMAP_GAO);  // 将位图IDB_BITMAP1加载到bitmap   
		hBmp3 = (HBITMAP)bitmap3.GetSafeHandle();  // 获取bitmap加载位图的句柄   
		m_yuePicture.SetBitmap(hBmp3);    // 设置图片控件m_jzmPicture的位图图片为IDB_BITMAP1 

		CBitmap bitmap4;  // CBitmap对象，用于加载位图   
		HBITMAP hBmp4;    // 保存CBitmap加载的位图的句柄   
		bitmap4.LoadBitmap(IDB_BITMAP_YUE);  // 将位图IDB_BITMAP1加载到bitmap   
		hBmp4 = (HBITMAP)bitmap4.GetSafeHandle();  // 获取bitmap加载位图的句柄   
		m_caoPicture.SetBitmap(hBmp4);    // 设置图片控件m_jzmPicture的位图图片为IDB_BITMAP1 
		
		CDialogEx::OnPaint();
	}


}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CLittleLuckyDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



HBRUSH CLittleLuckyDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	
	//修改static控件的背景色
	if (pWnd->GetDlgCtrlID() == IDC_STATIC_BEAUTY)
	{
		bk1.SetCtrlBK(pDC);
		HBRUSH brush = bk1.m_brush;
		return brush;
	}
	return hbr;
}


void CLittleLuckyDlg::OnStnClickedStaticZhang()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(_T("Bad choice！"));
}


void CLittleLuckyDlg::OnStnClickedStaticZhu()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(_T("这才不是最漂亮的女孩！"));
}


void CLittleLuckyDlg::OnStnClickedStaticYue()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(_T("错啦!高圆圆第二美你第一美！"));
}


void CLittleLuckyDlg::OnStnClickedStaticCao()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(_T("哈哈 你选对啦！这不是岳云鹏，这是大美女，点确定，看我72变 变 变"));

	CPicture *dlgPic = new CPicture(); 

	this->ShowWindow(SW_HIDE);

	dlgPic->DoModal();
	OnBnClickedOk();
}


void CLittleLuckyDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CAboutDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}

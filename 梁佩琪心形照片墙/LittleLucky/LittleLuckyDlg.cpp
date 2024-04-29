
// LittleLuckyDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LittleLucky.h"
#include "LittleLuckyDlg.h"
#include "afxdialogex.h"
#include "Picture.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CLittleLuckyDlg �Ի���



CLittleLuckyDlg::CLittleLuckyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLittleLuckyDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON_FLOWER);

	//��ʼ����ˢ������
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


// CLittleLuckyDlg ��Ϣ�������

BOOL CLittleLuckyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CLittleLuckyDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//�޸ĶԻ��򱳾���ɫΪ��ɫ
		CWnd* pWnd = FindWindow(NULL, _T("LittleLucky"));
		CRect rect;  
		CPaintDC dc(pWnd);  
		GetClientRect(rect);  
		dc.FillSolidRect(rect,RGB(255,255,255));   //����Ϊ�ױ���

		//��ʼ��λͼ
		CBitmap bitmap1;  // CBitmap�������ڼ���λͼ   
		HBITMAP hBmp1;    // ����CBitmap���ص�λͼ�ľ��   
		bitmap1.LoadBitmap(IDB_BITMAP_ZHANG);  // ��λͼIDB_BITMAP1���ص�bitmap   
		hBmp1 = (HBITMAP)bitmap1.GetSafeHandle();  // ��ȡbitmap����λͼ�ľ��   
		m_zhangPicture.SetBitmap(hBmp1);    // ����ͼƬ�ؼ�m_jzmPicture��λͼͼƬΪIDB_BITMAP1 

		CBitmap bitmap2;  // CBitmap�������ڼ���λͼ   
		HBITMAP hBmp2;    // ����CBitmap���ص�λͼ�ľ��   
		bitmap2.LoadBitmap(IDB_BITMAP_ZHU);  // ��λͼIDB_BITMAP1���ص�bitmap   
		hBmp2 = (HBITMAP)bitmap2.GetSafeHandle();  // ��ȡbitmap����λͼ�ľ��   
		m_zhuPicture.SetBitmap(hBmp2);    // ����ͼƬ�ؼ�m_jzmPicture��λͼͼƬΪIDB_BITMAP1 

		CBitmap bitmap3;  // CBitmap�������ڼ���λͼ   
		HBITMAP hBmp3;    // ����CBitmap���ص�λͼ�ľ��   
		bitmap3.LoadBitmap(IDB_BITMAP_GAO);  // ��λͼIDB_BITMAP1���ص�bitmap   
		hBmp3 = (HBITMAP)bitmap3.GetSafeHandle();  // ��ȡbitmap����λͼ�ľ��   
		m_yuePicture.SetBitmap(hBmp3);    // ����ͼƬ�ؼ�m_jzmPicture��λͼͼƬΪIDB_BITMAP1 

		CBitmap bitmap4;  // CBitmap�������ڼ���λͼ   
		HBITMAP hBmp4;    // ����CBitmap���ص�λͼ�ľ��   
		bitmap4.LoadBitmap(IDB_BITMAP_YUE);  // ��λͼIDB_BITMAP1���ص�bitmap   
		hBmp4 = (HBITMAP)bitmap4.GetSafeHandle();  // ��ȡbitmap����λͼ�ľ��   
		m_caoPicture.SetBitmap(hBmp4);    // ����ͼƬ�ؼ�m_jzmPicture��λͼͼƬΪIDB_BITMAP1 
		
		CDialogEx::OnPaint();
	}


}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CLittleLuckyDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



HBRUSH CLittleLuckyDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	
	//�޸�static�ؼ��ı���ɫ
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	MessageBox(_T("Bad choice��"));
}


void CLittleLuckyDlg::OnStnClickedStaticZhu()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	MessageBox(_T("��Ų�����Ư����Ů����"));
}


void CLittleLuckyDlg::OnStnClickedStaticYue()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	MessageBox(_T("����!��ԲԲ�ڶ������һ����"));
}


void CLittleLuckyDlg::OnStnClickedStaticCao()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	MessageBox(_T("���� ��ѡ�������ⲻ�������������Ǵ���Ů����ȷ��������72�� �� ��"));

	CPicture *dlgPic = new CPicture(); 

	this->ShowWindow(SW_HIDE);

	dlgPic->DoModal();
	OnBnClickedOk();
}


void CLittleLuckyDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void CAboutDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}

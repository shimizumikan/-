#include "stdafx.h"
#include "Romantic.h"
#include<windows.h>
#include<iostream>
#include<cstdio> 

using namespace std;

CRomantic::CRomantic(void)
{
}


CRomantic::~CRomantic(void)
{
}
//=====================================================�Ի�����ú���============
void CRomantic::ShowLove()
{
	GaoBaiQiQiu();//��һ������

	FireFlower();//�ڶ�������

}

//============================��һ������=================
void CRomantic::GaoBaiQiQiu()
{
	struct Point 
	{
		int x;
		int y;
	};

	Point arr[46] = {
		{537,268},//23
		{548,222},//24
		{558,193},//25
		{583,162},//26
		{610,133},//27
		{642,117},//28
		{679,105},//29
		{719,107},//30
		{759,120},//31
		{791,146},//32
		{808,173},//33
		{822,211},//34
		{825,247},//35
		{822,293},//36
		{817,338},//37
		{802,385},//38
		{782,440},//39
		{758,484},//40
		{730,529},//41
		{699,573},//42
		{672,610},//43
		{635,645},//44
		{602,675},//45
		{564,696},//46
		{523,676},//47
		{492,654},//48
		{462,626},//49
		{434,606},//50
		{399,570},//51
		{372,540},//52
		{342,500},//53
		{322,470},//54
		{302,430},//55
		{282,390},//56
		{268,342},//57
		{259,293},//58
		{262,250},//59
		{275,203},//60
		{302,170},//61
		{342,140},//62
		{382,130},//63
		{422,135},//64
		{454,146},//65
		{482,170},//66
		{502,195},//67
		{517,230} //68
	};

	//������Ƭ
	IMAGE img[46]; //�洢30����Ƭ
	IMAGE img2[46]; //�洢30����Ƭ
	char buf[128] = { 0 };//ͼƬ��·��
	for (int i = 0;i < 46; i++)
	{
		sprintf_s(buf,"Image\\%d.jpg",i+1);
		loadimage(&img[i],buf,40,40);
		loadimage(&img2[i],buf,150,150);
	}

	//initgraph(800,800);
	initgraph(1200,800);
	//cleardevice();
	//setbkcolor(TRANSPARENT);

	srand((unsigned)time(NULL));
	mciSendString(_T("open ./music/�ܽ���-�������.wav"),0,0,0);
	mciSendString(_T("play ./music/�ܽ���-�������.wav"),0,0,0);

	for (int i = 0;i < 46;i++)
	{
		putimage(arr[i].x,arr[i].y,&img[i % 46]);
		Sleep(nSecond);
	}

	//��ʾ���м����Ƭ
	putimage(375+142,385,&img2[2]);
	Sleep(nSecond);

	int add = 0;
	while (add<140)  //140�ոպá����ֲ��ŵ�1:09ʱ��add = 138;   ||23�� == add=46  3:30���ֽ���  ���ŵ�2��50����
	{
		cleardevice();
		for (int i = 0;i < 46;i++)
		{
			//settextcolor(RGB(rand()%256,rand()%256,rand()%256));
			putimage(arr[i].x,arr[i].y,&img[(i+add)%46]);
			//outtextxy(arr[i].x,arr[i].y,buff[(i+add)%46]);
			putimage(375+142,385,&img2[(i+add+1)%46]);
		}
		add++;
		Sleep(nSecond);
	}


	cleardevice();
	settextcolor(YELLOW);
	settextstyle(50,0,_T("Times New Roman"));
	outtextxy(250+142,385,"Merry Christmas!");
	Sleep(5000);

	cleardevice();
	settextcolor(YELLOW);
	settextstyle(50,0,_T("����"));
	outtextxy(345+142,385,"�ʵ�");
	Sleep(3000);
	//closegraph(); //

	//=======================�̻�===============
	//FireFlower();
}





//===========================================�ڶ������ڣ�����С����=================

void CRomantic::FireFlower()
{
	
	Welcome();

	DWORD t1 = timeGetTime(); //��ȡϵͳ��ʱ��
	DWORD *pMem = GetImageBuffer();

	for (int i = 0; i < NUM; i++)
	{
		Init(i);
	}

	Load();
	BeginBatchDraw();

	int flowerTimeCount = 0;
	while (!_kbhit())
	{
		Sleep(10);

		for (int clr = 0; clr < 1000; clr++)
		{
			for (int j = 0; j < 2; j++) //2000
			{
				int px1 = rand() % 1200;
				int py1 = rand() % 800;

				if (py1 < 799)
				{
					pMem[py1 * 1200 + px1] = pMem[py1 * 1200 + px1 + 1] = BLACK;
				}
			}
		}

		Chose(t1);
		Shoot();
		Show(pMem);
		FlushBatchDraw();

		flowerTimeCount++;
		if(flowerTimeCount == 2000) //������9000�ոպã�1000=15��  //���ֲ���2��15��
		{
			break;
		}

	}
	closegraph();

}

//��ӭ����
void CRomantic::Welcome()
{
	srand((unsigned int)time(NULL));

	//2.����
	settextcolor(YELLOW);

	for (int i = 0; i < 50; i++)  //i����Ĵ�С
	{
		//XY Բ��  R�뾶
		int x = 600 + int(180 *sin(PI * 2 * i / 60));
		int y = 200 + int(180 *cos(PI * 2 * i / 60));

		cleardevice();
		settextstyle(i, 0, _T("����"));   //���  ��С  ������ʽ
		outtextxy(x-80, y,_T("��˵�����˼��������"));
		outtextxy(x-10, y+100, _T("Ц������������"));

		//int second = 6*nSecond;
		Sleep(25);
	}
	Sleep(2000);
	_getch();  //������ȴ�  �����������...
	cleardevice();  //ˢ��
	settextstyle(25, 0, _T("����"));
	outtextxy(400,200,_T("��������߲�����"));
	outtextxy(400, 250, _T("�Ҿ�������, ���� ��ϲ"));
	outtextxy(400, 300, _T("������߲�����"));
	outtextxy(400, 350, _T("���������, ���� ��ȥ"));
	outtextxy(400, 400, _T("�㰮�����߲�����"));
	outtextxy(400, 450, _T("����������, ���� ����"));
	//outtextxy(600, 500, _T("____007"));
	Sleep(2000);
}

void CRomantic::Init(int i)//��ʼ��
{
	int r[13] = { 120, 120, 155, 123, 130, 147, 138, 138, 130, 135, 140, 132, 155 };
	int x[13] = { 120, 120, 110, 117, 110, 93, 102, 102, 110, 105, 100, 108, 110 };
	int y[13] = { 120, 120, 85, 118, 120, 103, 105, 110, 110, 120, 120, 105, 85 };

	fire[i].x = 0;
	fire[i].y = 0; 
	fire[i].width = 240;
	fire[i].height = 240;
	fire[i].max_r = r[i];
	fire[i].cen_x = x[i];
	fire[i].cen_y = y[i];
	fire[i].show = false;
	fire[i].dt = 5;
	fire[i].t1 = timeGetTime();
	fire[i].r = 0;

	//�̻���
	jet[i].x = 0;
	jet[i].y = 0;
	jet[i].t1 = timeGetTime();  //
	jet[i].dt = rand() % 10;  //0-9ms
	jet[i].n = 0;
	jet[i].height = 0;
	jet[i].hx = 0;
	jet[i].hy = 0;
	jet[i].shoot = false;

}

void CRomantic::Load() //����ͼƬ
{
	IMAGE fm, gm;
	loadimage(&fm,_T("./fire/flower.jpg"),3120,240);

	for (int i = 0; i < 13; i++)
	{
		SetWorkingImage(&fm);
		getimage(&gm, i * 240, 0, 240, 240);
		SetWorkingImage(&gm);

		for (int a = 0; a < 240; a++)
		{
			for (int b = 0; b < 240; b++)
			{
				fire[i].xy[a][b] = getpixel(a, b);
			}
		}
	}

	IMAGE sm;  //sm���������̻�����ͼƬ
	loadimage(&sm, _T("./fire/shoot.jpg"), 200, 50);//&sm ·��
	//putimage(0,0,&sm);

	//�������� ������������--->sm
	SetWorkingImage(&sm);
	for (int i = 0; i < NUM; i++)  //5����ɫ 13�� 
	{
		int n = rand() % 5;  //0-4
		getimage(&jet[i].img[0], n * 20, 0, 20, 50);  //n*20  0 20 40 60 80
		getimage(&jet[i].img[1], (n + 5) * 20, 0, 20, 50); //100 120 140 160 180
	}
	SetWorkingImage(NULL);
}

void CRomantic::Chose(DWORD& t1)  //ѡ����Է�����̻���
{
	DWORD t2 = timeGetTime();
	if (t2 - t1 > 100)  //100  100
	{
		int n = rand() % 20;  //0-19  0-13
		if (n < 13 && jet[n].shoot == false)  //---------------------
		{
			//x y  hy  hx  height ����
			jet[n].x = rand() % 1200;
			jet[n].y = 600+rand()%100;		//600-699
			jet[n].height = jet[n].y - jet[n].hy;
			jet[n].hx = jet[n].x;
			jet[n].hy = rand()%400; //0-399
			jet[n].shoot = true;

			putimage(jet[n].x, jet[n].y, &jet[n].img[jet[n].n]); //0-1 //

		}
		t1 = t2;
	}
}

void CRomantic::Shoot()  //����
{
	for (int i = 0; i < NUM; i++)
	{
		jet[i].t2 = timeGetTime();

		if (jet[i].t2 - jet[i].t1 > jet[i].dt&&jet[i].shoot == true)
		{
			putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n], SRCINVERT);

			if (jet[i].y > jet[i].hy)
			{
				//���� ��������ʲô? 
				jet[i].n++;  //��������
				jet[i].y -= 5; //����
			}
			putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n], SRCINVERT);

			if (jet[i].y <= jet[i].hy)
			{
				putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n],SRCINVERT);
				fire[i].x = jet[i].hx+10;
				fire[i].y = jet[i].hy;
				fire[i].show = true;
				fire[i].draw = false;
			}

			jet[i].t1 = jet[i].t2;
		}
	}
}

// �����̻�
void CRomantic::Show(DWORD* pMem)
{
	// �̻����׶�����ʱ������������������Ч��
	int drt[16] = { 5, 5, 5, 5, 5, 6, 25, 25, 25, 25, 55, 55, 55, 55, 55 };

	for (int i = 0; i < NUM; i++)
	{
		fire[i].t2 = timeGetTime();

		// ���ӱ�ը�뾶�������̻�������ʱ����������Ч��
		if (fire[i].t2 - fire[i].t1 > fire[i].dt && fire[i].show == true)
		{
			if (fire[i].r < fire[i].max_r)
			{
				fire[i].r++;
				fire[i].dt = drt[fire[i].r / 10];
				fire[i].draw = true;
			}

			if (fire[i].r >= fire[i].max_r - 1)
			{
				fire[i].draw = false;
				Init(i);
			}
			fire[i].t1 = fire[i].t2;
		}

		// ����ú��ڻ��ɱ�ը�����ݵ�ǰ��ը�뾶���̻�����ɫֵ�ӽ���ɫ�Ĳ������
		if (fire[i].draw)
		{
			for (double a = 0; a <= 6.28; a += 0.01)
			{
				int x1 = (int)(fire[i].cen_x + fire[i].r * cos(a));				// �����ͼƬ���Ͻǵ�����
				int y1 = (int)(fire[i].cen_y - fire[i].r * sin(a));

				if (x1 > 0 && x1 < fire[i].width && y1 > 0 && y1 < fire[i].height)	// ֻ���ͼƬ�ڵ����ص�
				{
					int b = fire[i].xy[x1][y1] & 0xff;
					int g = (fire[i].xy[x1][y1] >> 8) & 0xff;
					int r = (fire[i].xy[x1][y1] >> 16);

					// �̻����ص��ڴ����ϵ�����
					int xx = (int)(fire[i].x + fire[i].r * cos(a));
					int yy = (int)(fire[i].y - fire[i].r * sin(a));

					// �ϰ������ص㲻�������ֹԽ��
					if (r > 0x20 && g > 0x20 && b > 0x20 && xx > 0 && xx < 1200 && yy > 0 && yy < 800)
						pMem[yy * 1200 + xx] = BGR(fire[i].xy[x1][y1]);	// �Դ���������̻�
				}
			}
			fire[i].draw = false;
		}
	}
}
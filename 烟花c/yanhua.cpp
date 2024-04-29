#include <stdio.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <graphics.h>
#include <mmstream.h>
#pragma comment(lib,"winmm.lib")//��ý���豸�ӿڿ��ļ�
#define PI 3.1415
#define NUM 13  //�̻�������
#define WIDTH 960
#define HEIGHT 640

struct Fire
{
	int x, y;
	int cen_x, cen_y;//���ĵ�����
	int r;//��ǰ���Ű뾶
	int max_r;//������Ű뾶
	int width, height;//��ȸ߶�
	DWORD pixe[240][240];//ͼƬ�������飨��ά���飩
	bool isShow;//�̻��Ƿ�׼������
	bool isDraw;//�Ƿ�����̻�

}fire[NUM];

struct Jet    //�̻���
{
	int x, y;
	int hx, hy;//��ߵ�����
	bool isLaunch;
	IMAGE img[2];
	byte n : 1;//λ��
}jet[NUM];



void welcome()
{
	mciSendString("open dgc.mp3", NULL, NULL, NULL);
	mciSendString("play dgc.mp3", NULL, NULL, NULL);
	for (int i = 0; i < 50; i++)
	{
		//����
		cleardevice();
		int x = 500 + 180 * sin(2 * PI / 60 * i);
		int y = 200 + 180 * cos(2 * PI / 60 * i);
		//����������ʽ
		settextstyle(i, 0, "����");
		settextcolor(RGB(0, 202, 0));
		setbkcolor(TRANSPARENT);//͸������
		outtextxy(x, y, "DDD");
		Sleep(200);
	}
	_getch();//�����������
	cleardevice();
	settextstyle(25, 0, "����");
	outtextxy(350, 100, "DDDCCC");
	outtextxy(350, 150, "DDDDCCC");
	outtextxy(350, 200, "DDDDCCCC");
	outtextxy(350, 250, "DDDCCC");
	outtextxy(350, 300, "DDDCCCC");
	outtextxy(350, 350, "DDDDDCCC");
	outtextxy(450, 400, "DDDCCCCC");
}

void InitData(int i);

void loadImg()
{
	//��ʼ���̻�����Ч��
	IMAGE bloomImg, tImg;
	loadimage(&bloomImg, "flower.jpg", 3120, 240);
	for (int i = 0; i < NUM; i++)
	{
		InitData(i);
		SetWorkingImage(&bloomImg);
		getimage(&tImg, i * 240, 0, 240, 240);
		SetWorkingImage(&tImg);
		for (int a = 0; a < 240; a++)
		{
			for (int b = 0; b < 240; b++)
			{
				fire[i].pixe[a][b] = getpixel(a, b);
			}
		}//������Щ�����Ѿ����뵽pixe[240][240]�����ά����������
	
	}
	//��ʼ���̻���
	IMAGE jetImg;
	loadimage(&jetImg, "shoot.jpg", 200, 50);
	SetWorkingImage(&jetImg);
	
	for (int i = 0; i < NUM; i++)
	{
		
		int n = rand() % 5;
		getimage(&jet[i].img[0], n*20, 0, 20, 50);
		getimage(&jet[i].img[1], n*20 + 100, 0, 20, 50);
		jet[i].isLaunch = false;
	}
	
	SetWorkingImage();

}

void InitData(int i)
{
	fire[i].cen_x = 120;//�����̻��������Ű�������������������ĵ�
	fire[i].cen_y = 120;
	fire[i].max_r = 120;//Բ�����뾶���Ծ��λ�һ��Բ���뾶Ҳ��120
	fire[i].r = 0;//Բ�İ뾶�����������ŵ�ʱ������һ����,����û�������Ϊ0��
	fire[i].width = 240;//�ߺͿ�
	fire[i].height = 240;
	fire[i].isDraw = false;
	fire[i].isShow = false;
}

//�����̻���
void createJet()
{
	int i = rand() % NUM;
	if (jet[i].isLaunch == false)
	{
		jet[i].x = rand() % (WIDTH-20);
		jet[i].y = rand() % 100 + HEIGHT;
		jet[i].hx = jet[i].x;
		jet[i].hy = rand() % (HEIGHT / 3 * 2);
		jet[i].isLaunch = true;
	}
}

void launch()
{
	for (int i = 0; i < NUM; i++)
	{
		if (jet[i].isLaunch)
		{
			putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n],SRCINVERT);
			if (jet[i].y > jet[i].hy)//�ж��Ƿ���ߵ�
			{
				jet[i].y -= 5;//��ͼЧ��
				jet[i].n++;
			}
			putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n],SRCINVERT);
			if (jet[i].y <= jet[i].hy)
			{
				jet[i].isLaunch = false;
				//��ʼ���̻�
				fire[i].x = jet[i].x;
				fire[i].y = jet[i].y;
				fire[i].isShow = true;
			}
			
		}
	}
}

void bloom(DWORD *pMem)//���ź���
{
	for (int i = 0; i < NUM; i++)
	{
		//׼������
		if (fire[i].isShow)
		{
			if (fire[i].r < fire[i].max_r)
			{
				fire[i].r++;//���Ű뾶��������
				fire[i].isDraw = true;//��ʼ�����̻�
			}
			if (fire[i].r >= fire[i].max_r)
			{
				
				InitData(i);
			}

		}
		if (fire[i].isDraw)
		{
			//��ǰ�뾶Բ�����ÿһ����
			for (double a = 0; a <= 2 * PI; a += 0.01)
			{
				int img_x = fire[i].cen_x + fire[i].r * cos(a);//���Բ��ÿһ��������� 
				int img_y = fire[i].cen_y + fire[i].r * sin(a);
				if (img_x > 0 && img_x < fire[i].width && img_y>0 && img_y < fire[i].height)
				{
					//������ڵ����ŵ㣬��Ӧ����Ļ����
					int win_x = fire[i].x + fire[i].r * cos(a);
					int win_y = fire[i].y + fire[i].r * sin(a);
					if (win_x > 0 && win_x < WIDTH && win_y>0 && win_y < WIDTH)
					{
						pMem[win_y * WIDTH + win_x] = BGR(fire[i].pixe[img_x][img_y]);
					}
				}
			}
		}
	}

}

int main()
{
	//��������
	initgraph(960, 640);
	//���������
	srand((unsigned)time(NULL)+clock());
	welcome();
	loadImg();
	DWORD* pMem = GetImageBuffer();

	while (1) 
	{
		for (int i = 0; i < WIDTH; i++)
		{
			for (int k = 0; k < 4; k++)
			{
				int x = rand() % WIDTH;
				int y = rand() % HEIGHT;
				if (y < HEIGHT)
				{
					pMem[y * WIDTH + x] = BLACK;
				}
			}
		}
		createJet();
		launch();

		bloom(pMem);
		Sleep(10);
	}
	closegraph();//��ֹ����
	return 0;
}
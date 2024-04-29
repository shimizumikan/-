#include <stdio.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <graphics.h>
#include <mmstream.h>
#pragma comment(lib,"winmm.lib")//多媒体设备接口库文件
#define PI 3.1415
#define NUM 13  //烟花弹数量
#define WIDTH 960
#define HEIGHT 640

struct Fire
{
	int x, y;
	int cen_x, cen_y;//中心点坐标
	int r;//当前绽放半径
	int max_r;//最大绽放半径
	int width, height;//宽度高度
	DWORD pixe[240][240];//图片像素数组（二维数组）
	bool isShow;//烟花是否准备好了
	bool isDraw;//是否绘制烟花

}fire[NUM];

struct Jet    //烟花弹
{
	int x, y;
	int hx, hy;//最高点坐标
	bool isLaunch;
	IMAGE img[2];
	byte n : 1;//位段
}jet[NUM];



void welcome()
{
	mciSendString("open dgc.mp3", NULL, NULL, NULL);
	mciSendString("play dgc.mp3", NULL, NULL, NULL);
	for (int i = 0; i < 50; i++)
	{
		//清屏
		cleardevice();
		int x = 500 + 180 * sin(2 * PI / 60 * i);
		int y = 200 + 180 * cos(2 * PI / 60 * i);
		//设置字体样式
		settextstyle(i, 0, "楷体");
		settextcolor(RGB(0, 202, 0));
		setbkcolor(TRANSPARENT);//透明背景
		outtextxy(x, y, "DDD");
		Sleep(200);
	}
	_getch();//按任意键继续
	cleardevice();
	settextstyle(25, 0, "楷体");
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
	//初始化烟花绽放效果
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
		}//现在这些数据已经进入到pixe[240][240]这个二维数组里面了
	
	}
	//初始化烟花弹
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
	fire[i].cen_x = 120;//根据烟花弹的绽放爱做这个操作，这是中心点
	fire[i].cen_y = 120;
	fire[i].max_r = 120;//圆的最大半径，以矩形画一个圆，半径也是120
	fire[i].r = 0;//圆的半径，就是先绽放的时候先是一个点,就是没有嘛，所以为0；
	fire[i].width = 240;//高和宽
	fire[i].height = 240;
	fire[i].isDraw = false;
	fire[i].isShow = false;
}

//产生烟花弹
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
			if (jet[i].y > jet[i].hy)//判断是否到最高点
			{
				jet[i].y -= 5;//切图效果
				jet[i].n++;
			}
			putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n],SRCINVERT);
			if (jet[i].y <= jet[i].hy)
			{
				jet[i].isLaunch = false;
				//开始放烟花
				fire[i].x = jet[i].x;
				fire[i].y = jet[i].y;
				fire[i].isShow = true;
			}
			
		}
	}
}

void bloom(DWORD *pMem)//绽放函数
{
	for (int i = 0; i < NUM; i++)
	{
		//准备数据
		if (fire[i].isShow)
		{
			if (fire[i].r < fire[i].max_r)
			{
				fire[i].r++;//绽放半径慢慢增大
				fire[i].isDraw = true;//开始绘制烟花
			}
			if (fire[i].r >= fire[i].max_r)
			{
				
				InitData(i);
			}

		}
		if (fire[i].isDraw)
		{
			//求当前半径圆上面的每一个点
			for (double a = 0; a <= 2 * PI; a += 0.01)
			{
				int img_x = fire[i].cen_x + fire[i].r * cos(a);//求出圆上每一个点的坐标 
				int img_y = fire[i].cen_y + fire[i].r * sin(a);
				if (img_x > 0 && img_x < fire[i].width && img_y>0 && img_y < fire[i].height)
				{
					//针对现在的绽放点，对应的屏幕坐标
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
	//创建窗口
	initgraph(960, 640);
	//设置随机数
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
	closegraph();//防止闪退
	return 0;
}
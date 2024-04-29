#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#include <graphics.h>  //easyX

#include <mmsystem.h>


#pragma comment(lib,"winmm.lib")

#define NUM 46   //46组坐标

#define WINDOW_WDITH 800
#define WINDOW_HEIGHT 800   //窗口大小

#define PHOTO_NUM 6  //识取文件夹里的照片
#define PHOTO_SPACE 250   //设置图片大小

struct lone //结构体定义全局变量，简单来说就是弄个坐标x和y
{
	int x, y;
};


int main()
{
	//爱心的坐标数组
	struct lone arr[NUM] = 
	{
		{ 395,268 },
		{ 406,222 },
		{ 416,193 },
		{ 441,162 },
		{ 468,133 },
		{ 500,117 },
		{ 537,105 },
		{ 577,107 },
		{ 617,120 },
		{ 649,146 },
		{ 666,173 },
		{ 680,211 },
		{ 683,247 },
		{ 680,293 },
		{ 675,338 },
		{ 660,385 },
		{ 640,440 },
		{ 616,484 },
		{ 588,529 },
		{ 557,573 },
		{ 530,610 },
		{ 493,645 },
		{ 460,675 },
		{ 422,696 },
		{ 381,676 },
		{ 350,654 },
		{ 320,626 },
		{ 292,606 },
		{ 257,570 },
		{ 230,540 },
		{ 200,500 },
		{ 180,470 },
		{ 160,430 },
		{ 140,390 },
		{ 126,342 },
		{ 117,293 },
		{ 120,250 },
		{ 133,203 },
		{ 160,170 },
		{ 200,140 },
		{ 240,130 },
		{ 280,135 },
		{ 312,146 },
		{ 340,170 },
		{ 360,195 },
		{ 375,230 }
	};

	mciSendString("open lonely.mp3", NULL, NULL, NULL);
	mciSendString("play lonely.mp3", NULL, NULL, NULL);

	initgraph(WINDOW_WDITH, WINDOW_HEIGHT);

	char buff[NUM][50] = 
	{
		"一辈子",
		"和你一起",
		"这一生",
		"只爱你",
		"没有",
		"你的时候",
		"我想死",
		"用这一生",
		"来证明",
		"我爱你",
		"梁佩琪",
		"错过",
		"求爱",
		"的日期",
		"那天你",
		"消失在",
		"人海里",
		"你的背影",
		"沉默的",
		"让我恐惧",
		"你说的",
		"所有话语",
		"我全部都",
		"放心上",
		"偏偏",
		"那个时候",
		"我最想你",
		"我非常",
		"的爱你",
		"我自己",
		"控制不住",//3
		"已经给你",
		"发了微信",//3
		"你却一",
		"言不发了",
		"我真的",
		"好爱你",
		"我愿意",
		"改变自己",//3
		"明明觉得",
		"自己",
		"很冷静",
		"却还",
		"是无",
		"法控制",
		"我自己"
	};

	IMAGE img[PHOTO_NUM];  //显示文件夹里面的图片

	char temp[56];
	for (int i = 0; i < PHOTO_NUM; i++)//循环播放图片
	{
		memset(temp, 0, 56);//清0
		sprintf(temp, "memory\\%d.jpg", i + 1);//i为0的时候它是1，这样循环读取图片
		loadimage(&img[i], temp, PHOTO_SPACE, PHOTO_SPACE, true);
	}

//预编制代码


	for (int i = 0; i < NUM; i++)
	{
		settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));//设置爱心字体的颜色，%256是0到256这是颜色的范围
		outtextxy(arr[i].x, arr[i].y, buff[i]);//定位爱心的坐标和要显示的东西
		Sleep(200);//爱心秒数
	}

	



	int n = 0;

	while (1)//循环演示
	{
		//外围
		for (int i = 0; i < NUM; i++)
		{
			settextcolor(RGB(rand() % 256, rand() % 256, rand() % 256));//设置爱心字体的颜色，%256是0到256这是颜色的范围
			outtextxy(arr[i].x, arr[i].y, buff[i]);//定位爱心的坐标和要显示的东西
			
		}

		//贴图
		putimage(300, 300, &img[n]);

		//图片变化
		n++; if (n >= PHOTO_NUM) n = 0;//n数值如果大于文件夹里面的数值，则变为0；

		//演示时间
		Sleep(300);
	}
	while(1);
	return 0;
}
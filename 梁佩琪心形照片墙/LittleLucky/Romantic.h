#pragma once
#include "graphics.h"
#include "time.h"
#include "mmsystem.h"
#include <stdio.h>		//标准的输入输出头文件。
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include "windows.h"

#pragma comment(lib,"winmm.lib")
#define nSecond 500

#define PI 3.1415926548
#define NUM		13

class CRomantic
{
public:
	CRomantic(void);
	virtual ~CRomantic(void);
public:
	void ShowLove();
	void GaoBaiQiQiu();

	//==============第二个================窗口
	void FireFlower();
	//烟花弹
	struct JET
	{
		int x, y;   //烟花弹的坐标
		int hx, hy;  //最高点坐标 ---> 烟花(爆炸坐标)
		int height;  //高度  y-hy
		bool shoot;  //是否可以发射

		DWORD t1, t2, dt;  //时间间隔
		IMAGE img[2];      //小数组 存放图片
		byte n : 1;        //位段 
	}jet[NUM];

	//烟花
	struct FIRE
	{
		int r;      //r
		int max_r;  //
		int x, y;  //
		int cen_x, cen_y;  //
		int width, height;
		int xy[240][240];

		bool show;
		bool draw;
		DWORD t1, t2, dt;
	}fire[NUM];

	//声明函数
	void Welcome();
	void Init(int i);//初始化
	void Load(); //加载图片
	void Chose(DWORD& t1);  //选择可以发射的烟花弹
	void Shoot();   //发射
	void Show(DWORD* pMem);

};


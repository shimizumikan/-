#pragma once
#include "graphics.h"
#include "time.h"
#include "mmsystem.h"
#include <stdio.h>		//��׼���������ͷ�ļ���
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

	//==============�ڶ���================����
	void FireFlower();
	//�̻���
	struct JET
	{
		int x, y;   //�̻���������
		int hx, hy;  //��ߵ����� ---> �̻�(��ը����)
		int height;  //�߶�  y-hy
		bool shoot;  //�Ƿ���Է���

		DWORD t1, t2, dt;  //ʱ����
		IMAGE img[2];      //С���� ���ͼƬ
		byte n : 1;        //λ�� 
	}jet[NUM];

	//�̻�
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

	//��������
	void Welcome();
	void Init(int i);//��ʼ��
	void Load(); //����ͼƬ
	void Chose(DWORD& t1);  //ѡ����Է�����̻���
	void Shoot();   //����
	void Show(DWORD* pMem);

};


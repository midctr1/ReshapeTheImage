#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<opencv2\opencv.hpp>
#include<conio.h>
#include<graphics.h>
#include<easyx.h>

using namespace cv;
using namespace std;

Mat background ,Target , dst ;
int startX = 0 ,startY = 0 ,imgNum = 0 ;

/***********load my image and background*********************/
void loadmyResource()
{
  background = imread("MyPath1.jpg");
  Target = imread("MyPath2.jpg");
}

/***********set my display window***************************/
void setmywindowforImage()
{
  initgrahp(3840,2160);
  putimage(0,0,&background);
  putimage(stratX ,startY ,2160 ,3840 ,&Target ,2160*imgNum ,3840*2 ,SRCAND);
}

/***********put key dowm and contrl the image`s shape************/
void key_down_contrl()
{
  	int user = _getch();
	switch (user)
	{
  
  /****************up*************/
	case 'w':
	case 'W':
	case 72:
		BeginBatchDraw();
	putimage(0, 0, &background);
	putimage(startX, startY, 2160, 3840, &Target, 2160 * imgNum, 3840 * 3, SRCAND);
		startY -= 1;
		imgNum++;
		if (imgNum == 4)
		{
			imgNum = 0;
		}
		EndBatchDraw();
		break;

/****************down*************/
	case 's':
	case 'S':
	case 80:
		BeginBatchDraw();
	putimage(0, 0, &background);
	putimage(startX, startY, 2160, 3840, &Target, 2160 * imgNum, 3840 * 0, SRCAND);
		startY += 1;
		imgNum++;
		if (imgNum == 4)
		{
			imgNum = 0;
		}
		EndBatchDraw();
		break;

/******************left***************/
	case 'a':
	case 'A':
	case 75:
		BeginBatchDraw();
		putimage(0, 0, &background);
		putimage(startX, startY, 2160, 3840, &Target, 2160 * imgNum, 3840 * 1, SRCAND);
		startY -= 1;
		imgNum++;
		if (imgNum == 4)
		{
			imgNum = 0;
		}
		EndBatchDraw();
		break;

/****************right***************/
	case 'd':
	case 'D':
	case 77:
		BeginBatchDraw();
		putimage(0, 0, &background);
		putimage(startX, startY, 2160, 3840, &Target, 2160 * imgNum, 3840 * 2, SRCAND);
		startY += 1;
		imgNum++;
		if (imgNum == 4)
		{
			imgNum = 0;
		}
		EndBatchDraw();
		break;
    }
}

int main(void)
{
	loadmyResource();
	setmywindowforImage();
	while (1)
	{
		key_down_contrl();
	}
	return 0;
}

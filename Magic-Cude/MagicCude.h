#pragma once
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"

//每个块的旋转变量
int rox[3][3][3] = {};
int roy[3][3][3] = {};
int roz[3][3][3] = {};

//绕X轴旋转的块
typedef struct Rote_X
{
	int **rotex;
}*RoteX;

//绕Y轴旋转的块
typedef struct Rote_Y
{
	int **rotey;
}*RoteY;

//绕Z轴旋转的块
typedef struct Rote_Z
{
	int **rotez;
}*RoteZ;

//绘画块的函数
void Draw_Cube(GLfloat x1, GLfloat x2, GLfloat y1, GLfloat y2, GLfloat z1, GLfloat z2)
{	//桌子由立方体组成，已知六个参数即可构造八个顶点
	int i, j;
	GLfloat vertex[8][3] = {
		//八个顶点，从v1-v8
		x1,y1,z2,
		x2,y1,z2,
		x1,y2,z2,
		x2,y2,z2,
		x1,y1,z1,
		x2,y1,z1,
		x1,y2,z1,
		x2,y2,z1
	};
	GLint surface[6][4] = {
		//v1对应0,以此类推
		0,1,3,2,
		4,5,7,6,
		2,3,7,6,
		0,1,5,4,
		0,2,6,4,
		1,3,7,5
	};

	glBegin(GL_QUADS);//指定绘制方式
					  //将每个立方体分成六个面绘制
	for (i = 0; i < 6; i++)
	{
		//默认是白色的
		glColor3f(1.0, 1.0, 1.0);
		switch (i)
		{
		case 0:
			glColor3f(1.0, 1.0, 0.0);	//黄色
			break;
		case 1:
			glColor3f(1.0, 1.0, 1.0);	//白色
			break;
		case 2:
			glColor3f(0.0, 1.0, 0.0);	//绿色
			break;
		case 3:
			glColor3f(0.0, 0.0, 1.0);	//蓝色
			break;
		case 4:
			glColor3f(1.0, 0.0, 0.0);	//红色
			break;
		case 5:
			glColor3ub(233, 150, 122);	//橙色
			break;
		default:
			break;
		}
		for (j = 0; j < 4; j++)
			glVertex3fv(vertex[surface[i][j]]);
	}
		
	glEnd();
}

//给每个块设置旋转变量
void Cube_rate(int rox[][3][3],int roy[][3][3],int roz[][3][3],int n1, int n2, int n3)
{
	glRotatef((GLfloat)rox[n1][n2][n3], 1.0, 0.0, 0.0);
	glRotatef((GLfloat)roy[n1][n2][n3], 0.0, 1.0, 0.0);
	glRotatef((GLfloat)roz[n1][n2][n3], 0.0, 0.0, 1.0);
}

//画第一层块
void Cube_01()
{
	//缓存
	glPushMatrix();

	//原点上的（中间的）Cube (1,1,1)
	Cube_rate(rox, roy, roz, 1, 1, 1);
	Draw_Cube(-50.0, 50.0, -50.0, 50.0, -50.0, 50.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//x轴上两端的Cube (0,1,1)
	Cube_rate(rox, roy, roz, 0, 1, 1);
	Draw_Cube(50.0, 150.0, -50.0, 50.0, -50.0, 50.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//x轴上两端的Cube (2,1,1)
	Cube_rate(rox, roy, roz, 2, 1, 1);
	Draw_Cube(-150.0, -50.0, -50.0, 50.0, -50.0, 50.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//y轴上两端的Cube (1,0,1)
	Cube_rate(rox, roy, roz, 1, 0, 1);
	Draw_Cube(-50.0, 50.0, 50.0, 150.0, -50.0, 50.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//y轴上两端的Cube (1,2,1)
	Cube_rate(rox, roy, roz, 1, 2, 1);
	Draw_Cube(-50.0, 50.0, -150.0, -50.0, -50.0, 50.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//x，y轴上的四个Cube (0,0,1)
	Cube_rate(rox, roy, roz, 0, 0, 1);
	Draw_Cube(50.0, 150.0, 50.0, 150.0, -50.0, 50.0);



	glPopMatrix();


	//缓存
	glPushMatrix();

	//x，y轴上的四个Cube (0,2,1)
	Cube_rate(rox, roy, roz, 0, 2, 1);
	Draw_Cube(50.0, 150.0, -150.0, -50.0, -50.0, 50.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//x，y轴上的四个Cube (2,0,1)
	Cube_rate(rox, roy, roz, 2, 0, 1);
	Draw_Cube(-150.0, -50.0, 50.0, 150.0, -50.0, 50.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//x，y轴上的四个Cube (2,2,1)
	Cube_rate(rox, roy, roz, 2, 2, 1);
	Draw_Cube(-150.0, -50.0, -150.0, -50.0, -50.0, 50.0);

	glPopMatrix();
}

//画中间一层的块
void Cube_00()
{
	//缓存
	glPushMatrix();

	//原点上的（中间的）Cube (1,1,0)
	Cube_rate(rox, roy, roz, 1, 1, 0);
	Draw_Cube(-50.0, 50.0, -50.0, 50.0, 50.0, 150.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//x轴上两端的Cube (0,1,0)
	Cube_rate(rox, roy, roz, 0, 1, 0);
	Draw_Cube(50.0, 150.0, -50.0, 50.0, 50.0, 150.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//x轴上两端的Cube (2,1,0)
	Cube_rate(rox, roy, roz, 2, 1, 0);
	Draw_Cube(-150.0, -50.0, -50.0, 50.0, 50.0, 150.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//y轴上两端的Cube (1,0,0)
	Cube_rate(rox, roy, roz, 1, 0, 0);
	Draw_Cube(-50.0, 50.0, 50.0, 150.0, 50.0, 150.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//y轴上两端的Cube (1,2,0)
	Cube_rate(rox, roy, roz, 1, 2, 0);
	Draw_Cube(-50.0, 50.0, -150.0, -50.0, 50.0, 150.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//x，y轴上的四个Cube (0,0,0)
	Cube_rate(rox, roy, roz, 0, 0, 0);
	Draw_Cube(50.0, 150.0, 50.0, 150.0, 50.0, 150.0);



	glPopMatrix();


	//缓存
	glPushMatrix();

	//x，y轴上的四个Cube (0,2,0)
	Cube_rate(rox, roy, roz, 0, 2, 0);
	Draw_Cube(50.0, 150.0, -150.0, -50.0, 50.0, 150.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//x，y轴上的四个Cube (2,0,0)
	Cube_rate(rox, roy, roz, 2, 0, 0);
	Draw_Cube(-150.0, -50.0, 50.0, 150.0, 50.0, 150.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//x，y轴上的四个Cube (2,2,0)
	Cube_rate(rox, roy, roz, 2, 2, 0);
	Draw_Cube(-150.0, -50.0, -150.0, -50.0, 50.0, 150.0);

	glPopMatrix();
}

//画最后一层的块
void Cube_02()
{
	//缓存
	glPushMatrix();

	//原点上的（中间的）Cube (1,1,2)
	Cube_rate(rox, roy, roz, 1, 1, 2);
	Draw_Cube(-50.0, 50.0, -50.0, 50.0, -150.0, -50.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//x轴上两端的Cube (0,1,2)
	Cube_rate(rox, roy, roz, 0, 1, 2);
	Draw_Cube(50.0, 150.0, -50.0, 50.0, -150.0, -50.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//x轴上两端的Cube (2,1,2)
	Cube_rate(rox, roy, roz, 2, 1, 2);
	Draw_Cube(-150.0, -50.0, -50.0, 50.0, -150.0, -50.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//y轴上两端的Cube (1,0,2)
	Cube_rate(rox, roy, roz, 1, 0, 2);
	Draw_Cube(-50.0, 50.0, 50.0, 150.0, -150.0, -50.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//y轴上两端的Cube (1,2,2)
	Cube_rate(rox, roy, roz, 1, 2, 2);
	Draw_Cube(-50.0, 50.0, -150.0, -50.0, -150.0, -50.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//x，y轴上的四个Cube (0,0,2)
	Cube_rate(rox, roy, roz, 0, 0, 2);
	Draw_Cube(50.0, 150.0, 50.0, 150.0, -150.0, -50.0);



	glPopMatrix();


	//缓存
	glPushMatrix();

	//x，y轴上的四个Cube (0,2,2)
	Cube_rate(rox, roy, roz, 0, 2, 2);
	Draw_Cube(50.0, 150.0, -150.0, -50.0, -150.0, -50.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//x，y轴上的四个Cube (2,0,2)
	Cube_rate(rox, roy, roz, 2, 0, 2);
	Draw_Cube(-150.0, -50.0, 50.0, 150.0, -150.0, -50.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//x，y轴上的四个Cube (2,2,2)
	Cube_rate(rox, roy, roz, 2, 2, 2);
	Draw_Cube(-150.0, -50.0, -150.0, -50.0, -150.0, -50.0);

	glPopMatrix();
}
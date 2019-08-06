#pragma once
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include <iostream>

using namespace std;

//每个块的旋转变量
typedef struct cube
{
	int rox, roy, roz;
	int x, y, z;
	int up, down, right, left;
}cube;

cube c[3][3][3];

int rox[3][3][3] = {};
int roy[3][3][3] = {};
int roz[3][3][3] = {};

typedef struct RCube
{
	int *ro;
	int x, y, z;
}RCube;

//绕X轴旋转的块
typedef struct Rote_X
{
	RCube *rotex[3][3];
}RoteX;



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
void Cube_rate(int n1, int n2, int n3)
{
	glRotatef((GLfloat)c[n1][n2][n3].rox, 1.0, 0.0, 0.0);
	glRotatef((GLfloat)c[n1][n2][n3].roy, 0.0, 1.0, 0.0);
	glRotatef((GLfloat)c[n1][n2][n3].roz, 0.0, 0.0, 1.0);
	c[n1][n2][n3].x = n1;
	c[n1][n2][n3].y = n2;
	c[n1][n2][n3].z = n3;
}

//画第一层块
void Cube_01()
{
	//缓存
	glPushMatrix();

	//原点上的（中间的）Cube (1,1,1)
	Cube_rate( 1, 1, 1);
	Draw_Cube(-50.0, 50.0, -50.0, 50.0, -50.0, 50.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//x轴上两端的Cube (0,1,1)
	Cube_rate( 0, 1, 1);
	Draw_Cube(50.0, 150.0, -50.0, 50.0, -50.0, 50.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//x轴上两端的Cube (2,1,1)
	Cube_rate( 2, 1, 1);
	Draw_Cube(-150.0, -50.0, -50.0, 50.0, -50.0, 50.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//y轴上两端的Cube (1,0,1)
	Cube_rate( 1, 0, 1);
	Draw_Cube(-50.0, 50.0, 50.0, 150.0, -50.0, 50.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//y轴上两端的Cube (1,2,1)
	Cube_rate( 1, 2, 1);
	Draw_Cube(-50.0, 50.0, -150.0, -50.0, -50.0, 50.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//x，y轴上的四个Cube (0,0,1)
	Cube_rate( 0, 0, 1);
	Draw_Cube(50.0, 150.0, 50.0, 150.0, -50.0, 50.0);



	glPopMatrix();


	//缓存
	glPushMatrix();

	//x，y轴上的四个Cube (0,2,1)
	Cube_rate( 0, 2, 1);
	Draw_Cube(50.0, 150.0, -150.0, -50.0, -50.0, 50.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//x，y轴上的四个Cube (2,0,1)
	Cube_rate( 2, 0, 1);
	Draw_Cube(-150.0, -50.0, 50.0, 150.0, -50.0, 50.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//x，y轴上的四个Cube (2,2,1)
	Cube_rate( 2, 2, 1);
	Draw_Cube(-150.0, -50.0, -150.0, -50.0, -50.0, 50.0);

	glPopMatrix();
}

//画中间一层的块
void Cube_00()
{
	//缓存
	glPushMatrix();

	//原点上的（中间的）Cube (1,1,0)
	Cube_rate( 1, 1, 0);
	Draw_Cube(-50.0, 50.0, -50.0, 50.0, 50.0, 150.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//x轴上两端的Cube (0,1,0)
	Cube_rate( 0, 1, 0);
	Draw_Cube(50.0, 150.0, -50.0, 50.0, 50.0, 150.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//x轴上两端的Cube (2,1,0)
	Cube_rate( 2, 1, 0);
	Draw_Cube(-150.0, -50.0, -50.0, 50.0, 50.0, 150.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//y轴上两端的Cube (1,0,0)
	Cube_rate( 1, 0, 0);
	Draw_Cube(-50.0, 50.0, 50.0, 150.0, 50.0, 150.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//y轴上两端的Cube (1,2,0)
	Cube_rate( 1, 2, 0);
	Draw_Cube(-50.0, 50.0, -150.0, -50.0, 50.0, 150.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//x，y轴上的四个Cube (0,0,0)
	Cube_rate( 0, 0, 0);
	Draw_Cube(50.0, 150.0, 50.0, 150.0, 50.0, 150.0);



	glPopMatrix();


	//缓存
	glPushMatrix();

	//x，y轴上的四个Cube (0,2,0)
	Cube_rate( 0, 2, 0);
	Draw_Cube(50.0, 150.0, -150.0, -50.0, 50.0, 150.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//x，y轴上的四个Cube (2,0,0)
	Cube_rate( 2, 0, 0);
	Draw_Cube(-150.0, -50.0, 50.0, 150.0, 50.0, 150.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//x，y轴上的四个Cube (2,2,0)
	Cube_rate( 2, 2, 0);
	Draw_Cube(-150.0, -50.0, -150.0, -50.0, 50.0, 150.0);

	glPopMatrix();
}

//画最后一层的块
void Cube_02()
{
	//缓存
	glPushMatrix();

	//原点上的（中间的）Cube (1,1,2)
	Cube_rate( 1, 1, 2);
	Draw_Cube(-50.0, 50.0, -50.0, 50.0, -150.0, -50.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//x轴上两端的Cube (0,1,2)
	Cube_rate( 0, 1, 2);
	Draw_Cube(50.0, 150.0, -50.0, 50.0, -150.0, -50.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//x轴上两端的Cube (2,1,2)
	Cube_rate( 2, 1, 2);
	Draw_Cube(-150.0, -50.0, -50.0, 50.0, -150.0, -50.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//y轴上两端的Cube (1,0,2)
	Cube_rate( 1, 0, 2);
	Draw_Cube(-50.0, 50.0, 50.0, 150.0, -150.0, -50.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//y轴上两端的Cube (1,2,2)
	Cube_rate( 1, 2, 2);
	Draw_Cube(-50.0, 50.0, -150.0, -50.0, -150.0, -50.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//x，y轴上的四个Cube (0,0,2)
	Cube_rate( 0, 0, 2);
	Draw_Cube(50.0, 150.0, 50.0, 150.0, -150.0, -50.0);



	glPopMatrix();


	//缓存
	glPushMatrix();

	//x，y轴上的四个Cube (0,2,2)
	Cube_rate( 0, 2, 2);
	Draw_Cube(50.0, 150.0, -150.0, -50.0, -150.0, -50.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//x，y轴上的四个Cube (2,0,2)
	Cube_rate( 2, 0, 2);
	Draw_Cube(-150.0, -50.0, 50.0, 150.0, -150.0, -50.0);

	glPopMatrix();


	//缓存
	glPushMatrix();

	//x，y轴上的四个Cube (2,2,2)
	Cube_rate( 2, 2, 2);
	Draw_Cube(-150.0, -50.0, -150.0, -50.0, -150.0, -50.0);

	glPopMatrix();
}

//初始化旋转块指针
/*
void Init_Rote()
{
for (int i = 0; i < 3; i++)
{
for (int j = 0; j < 3; j++)
{
x1.rotex[i][j] = (RCube*)malloc(sizeof(RCube));
x1.rotex[i][j]->ro = &rox[0][j][i];
x1.rotex[i][j]->x = 0;
x1.rotex[i][j]->y = j;
x1.rotex[i][j]->z = i;

x2.rotex[i][j] = (RCube*)malloc(sizeof(RCube));
x2.rotex[i][j]->ro = &rox[1][j][i];
x2.rotex[i][j]->x = 1;
x2.rotex[i][j]->y = j;
x2.rotex[i][j]->z = i;

x3.rotex[i][j] = (RCube*)malloc(sizeof(RCube));
x3.rotex[i][j]->ro = &rox[2][j][i];
x3.rotex[i][j]->x = 2;
x3.rotex[i][j]->y = j;
x3.rotex[i][j]->z = i;

y01.rotey[i][j] = (RCube*)malloc(sizeof(RCube));
y01.rotey[i][j]->ro = &roy[j][0][i];
y01.rotey[i][j]->x = j;
y01.rotey[i][j]->y = 0;
y01.rotey[i][j]->z = i;

y02.rotey[i][j] = (RCube*)malloc(sizeof(RCube));
y02.rotey[i][j]->ro = &roy[j][1][i];
y02.rotey[i][j]->x = j;
y02.rotey[i][j]->y = 1;
y02.rotey[i][j]->z = i;

y03.rotey[i][j] = (RCube*)malloc(sizeof(RCube));
y03.rotey[i][j]->ro = &roy[j][2][i];
y03.rotey[i][j]->x = j;
y03.rotey[i][j]->y = 2;
y03.rotey[i][j]->z = i;

z1.rotez[i][j] = (RCube*)malloc(sizeof(RCube));
z1.rotez[i][j]->ro = &roz[j][i][0];
z1.rotez[i][j]->x = j;
z1.rotez[i][j]->y = i;
z1.rotez[i][j]->z = 0;

z2.rotez[i][j] = (RCube*)malloc(sizeof(RCube));
z2.rotez[i][j]->ro = &roz[j][i][1];
z2.rotez[i][j]->x = j;
z2.rotez[i][j]->y = i;
z2.rotez[i][j]->z = 1;

z3.rotez[i][j] = (RCube*)malloc(sizeof(RCube));
z3.rotez[i][j]->ro = &roz[j][i][2];
z3.rotez[i][j]->x = j;
z3.rotez[i][j]->y = i;
z3.rotez[i][j]->z = 2;
//cout << x1->rotex[i][j] << endl;
}
}
}
*/



void XRote10()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (c[i][j][k].x == 0)
					c[i][j][k].rox = (c[i][j][k].rox + 90) % 360;
			}
		}
	}

}


void XRote11()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//*x1.rotex[i][j]->ro = (*x1.rotex[i][j]->ro - 90) % 360;
		}
	}
}


void XRote20()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//*x2.rotex[i][j]->ro = (*x2.rotex[i][j]->ro + 90) % 360;
		}
	}
}


void YRote10()
{
	cube *t[8];
	int n = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (c[i][j][k].y == 0)
				{
					c[i][j][k].roy = (c[i][j][k].roy + 90) % 360;
					if (c[i][j][k].x == c[i][j][k].z && c[i][j][k].x == 1)
					{
						continue;
					}
					else
					{
						t[n] = &c[i][j][k];
						n++;
					}
					
				}
				
			}
			
		}
	}

	cube *t01, *t02;
	t01 = t[0];
	t02 = t[1];
	
	t[0]->x = t[2]->x;
	t[0]->y = t[2]->y;
	t[0]->z = t[2]->z;

	t[1]->x = t[4]->x;
	t[1]->y = t[4]->y;
	t[1]->z = t[4]->z;

	t[2]->x = t[7]->x;
	t[2]->y = t[7]->y;
	t[2]->z = t[7]->z;

	t[3]->x = t02->x;
	t[3]->y = t02->y;
	t[3]->z = t02->z;

	t[4]->x = t[6]->x;
	t[4]->y = t[6]->y;
	t[4]->z = t[6]->z;

	cube *t03 = t[5];
	t[5]->x = t01->x;
	t[5]->y = t01->y;
	t[5]->z = t01->z;

	t[6]->x = t[3]->x;
	t[6]->y = t[3]->y;
	t[6]->z = t[3]->z;


	t[7]->x = t03->x;
	t[7]->y = t03->y;
	t[7]->z = t03->z;
}
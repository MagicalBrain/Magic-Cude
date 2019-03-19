#pragma once
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"

//ÿ�������ת����
int rox[3][3][3] = {};
int roy[3][3][3] = {};
int roz[3][3][3] = {};

//��X����ת�Ŀ�
typedef struct Rote_X
{
	int **rotex;
}*RoteX;

//��Y����ת�Ŀ�
typedef struct Rote_Y
{
	int **rotey;
}*RoteY;

//��Z����ת�Ŀ�
typedef struct Rote_Z
{
	int **rotez;
}*RoteZ;

//�滭��ĺ���
void Draw_Cube(GLfloat x1, GLfloat x2, GLfloat y1, GLfloat y2, GLfloat z1, GLfloat z2)
{	//��������������ɣ���֪�����������ɹ���˸�����
	int i, j;
	GLfloat vertex[8][3] = {
		//�˸����㣬��v1-v8
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
		//v1��Ӧ0,�Դ�����
		0,1,3,2,
		4,5,7,6,
		2,3,7,6,
		0,1,5,4,
		0,2,6,4,
		1,3,7,5
	};

	glBegin(GL_QUADS);//ָ�����Ʒ�ʽ
					  //��ÿ��������ֳ����������
	for (i = 0; i < 6; i++)
	{
		//Ĭ���ǰ�ɫ��
		glColor3f(1.0, 1.0, 1.0);
		switch (i)
		{
		case 0:
			glColor3f(1.0, 1.0, 0.0);	//��ɫ
			break;
		case 1:
			glColor3f(1.0, 1.0, 1.0);	//��ɫ
			break;
		case 2:
			glColor3f(0.0, 1.0, 0.0);	//��ɫ
			break;
		case 3:
			glColor3f(0.0, 0.0, 1.0);	//��ɫ
			break;
		case 4:
			glColor3f(1.0, 0.0, 0.0);	//��ɫ
			break;
		case 5:
			glColor3ub(233, 150, 122);	//��ɫ
			break;
		default:
			break;
		}
		for (j = 0; j < 4; j++)
			glVertex3fv(vertex[surface[i][j]]);
	}
		
	glEnd();
}

//��ÿ����������ת����
void Cube_rate(int rox[][3][3],int roy[][3][3],int roz[][3][3],int n1, int n2, int n3)
{
	glRotatef((GLfloat)rox[n1][n2][n3], 1.0, 0.0, 0.0);
	glRotatef((GLfloat)roy[n1][n2][n3], 0.0, 1.0, 0.0);
	glRotatef((GLfloat)roz[n1][n2][n3], 0.0, 0.0, 1.0);
}

//����һ���
void Cube_01()
{
	//����
	glPushMatrix();

	//ԭ���ϵģ��м�ģ�Cube (1,1,1)
	Cube_rate(rox, roy, roz, 1, 1, 1);
	Draw_Cube(-50.0, 50.0, -50.0, 50.0, -50.0, 50.0);

	glPopMatrix();


	//����
	glPushMatrix();

	//x�������˵�Cube (0,1,1)
	Cube_rate(rox, roy, roz, 0, 1, 1);
	Draw_Cube(50.0, 150.0, -50.0, 50.0, -50.0, 50.0);

	glPopMatrix();


	//����
	glPushMatrix();

	//x�������˵�Cube (2,1,1)
	Cube_rate(rox, roy, roz, 2, 1, 1);
	Draw_Cube(-150.0, -50.0, -50.0, 50.0, -50.0, 50.0);

	glPopMatrix();


	//����
	glPushMatrix();

	//y�������˵�Cube (1,0,1)
	Cube_rate(rox, roy, roz, 1, 0, 1);
	Draw_Cube(-50.0, 50.0, 50.0, 150.0, -50.0, 50.0);

	glPopMatrix();


	//����
	glPushMatrix();

	//y�������˵�Cube (1,2,1)
	Cube_rate(rox, roy, roz, 1, 2, 1);
	Draw_Cube(-50.0, 50.0, -150.0, -50.0, -50.0, 50.0);

	glPopMatrix();


	//����
	glPushMatrix();

	//x��y���ϵ��ĸ�Cube (0,0,1)
	Cube_rate(rox, roy, roz, 0, 0, 1);
	Draw_Cube(50.0, 150.0, 50.0, 150.0, -50.0, 50.0);



	glPopMatrix();


	//����
	glPushMatrix();

	//x��y���ϵ��ĸ�Cube (0,2,1)
	Cube_rate(rox, roy, roz, 0, 2, 1);
	Draw_Cube(50.0, 150.0, -150.0, -50.0, -50.0, 50.0);

	glPopMatrix();


	//����
	glPushMatrix();

	//x��y���ϵ��ĸ�Cube (2,0,1)
	Cube_rate(rox, roy, roz, 2, 0, 1);
	Draw_Cube(-150.0, -50.0, 50.0, 150.0, -50.0, 50.0);

	glPopMatrix();


	//����
	glPushMatrix();

	//x��y���ϵ��ĸ�Cube (2,2,1)
	Cube_rate(rox, roy, roz, 2, 2, 1);
	Draw_Cube(-150.0, -50.0, -150.0, -50.0, -50.0, 50.0);

	glPopMatrix();
}

//���м�һ��Ŀ�
void Cube_00()
{
	//����
	glPushMatrix();

	//ԭ���ϵģ��м�ģ�Cube (1,1,0)
	Cube_rate(rox, roy, roz, 1, 1, 0);
	Draw_Cube(-50.0, 50.0, -50.0, 50.0, 50.0, 150.0);

	glPopMatrix();


	//����
	glPushMatrix();

	//x�������˵�Cube (0,1,0)
	Cube_rate(rox, roy, roz, 0, 1, 0);
	Draw_Cube(50.0, 150.0, -50.0, 50.0, 50.0, 150.0);

	glPopMatrix();


	//����
	glPushMatrix();

	//x�������˵�Cube (2,1,0)
	Cube_rate(rox, roy, roz, 2, 1, 0);
	Draw_Cube(-150.0, -50.0, -50.0, 50.0, 50.0, 150.0);

	glPopMatrix();


	//����
	glPushMatrix();

	//y�������˵�Cube (1,0,0)
	Cube_rate(rox, roy, roz, 1, 0, 0);
	Draw_Cube(-50.0, 50.0, 50.0, 150.0, 50.0, 150.0);

	glPopMatrix();


	//����
	glPushMatrix();

	//y�������˵�Cube (1,2,0)
	Cube_rate(rox, roy, roz, 1, 2, 0);
	Draw_Cube(-50.0, 50.0, -150.0, -50.0, 50.0, 150.0);

	glPopMatrix();


	//����
	glPushMatrix();

	//x��y���ϵ��ĸ�Cube (0,0,0)
	Cube_rate(rox, roy, roz, 0, 0, 0);
	Draw_Cube(50.0, 150.0, 50.0, 150.0, 50.0, 150.0);



	glPopMatrix();


	//����
	glPushMatrix();

	//x��y���ϵ��ĸ�Cube (0,2,0)
	Cube_rate(rox, roy, roz, 0, 2, 0);
	Draw_Cube(50.0, 150.0, -150.0, -50.0, 50.0, 150.0);

	glPopMatrix();


	//����
	glPushMatrix();

	//x��y���ϵ��ĸ�Cube (2,0,0)
	Cube_rate(rox, roy, roz, 2, 0, 0);
	Draw_Cube(-150.0, -50.0, 50.0, 150.0, 50.0, 150.0);

	glPopMatrix();


	//����
	glPushMatrix();

	//x��y���ϵ��ĸ�Cube (2,2,0)
	Cube_rate(rox, roy, roz, 2, 2, 0);
	Draw_Cube(-150.0, -50.0, -150.0, -50.0, 50.0, 150.0);

	glPopMatrix();
}

//�����һ��Ŀ�
void Cube_02()
{
	//����
	glPushMatrix();

	//ԭ���ϵģ��м�ģ�Cube (1,1,2)
	Cube_rate(rox, roy, roz, 1, 1, 2);
	Draw_Cube(-50.0, 50.0, -50.0, 50.0, -150.0, -50.0);

	glPopMatrix();


	//����
	glPushMatrix();

	//x�������˵�Cube (0,1,2)
	Cube_rate(rox, roy, roz, 0, 1, 2);
	Draw_Cube(50.0, 150.0, -50.0, 50.0, -150.0, -50.0);

	glPopMatrix();


	//����
	glPushMatrix();

	//x�������˵�Cube (2,1,2)
	Cube_rate(rox, roy, roz, 2, 1, 2);
	Draw_Cube(-150.0, -50.0, -50.0, 50.0, -150.0, -50.0);

	glPopMatrix();


	//����
	glPushMatrix();

	//y�������˵�Cube (1,0,2)
	Cube_rate(rox, roy, roz, 1, 0, 2);
	Draw_Cube(-50.0, 50.0, 50.0, 150.0, -150.0, -50.0);

	glPopMatrix();


	//����
	glPushMatrix();

	//y�������˵�Cube (1,2,2)
	Cube_rate(rox, roy, roz, 1, 2, 2);
	Draw_Cube(-50.0, 50.0, -150.0, -50.0, -150.0, -50.0);

	glPopMatrix();


	//����
	glPushMatrix();

	//x��y���ϵ��ĸ�Cube (0,0,2)
	Cube_rate(rox, roy, roz, 0, 0, 2);
	Draw_Cube(50.0, 150.0, 50.0, 150.0, -150.0, -50.0);



	glPopMatrix();


	//����
	glPushMatrix();

	//x��y���ϵ��ĸ�Cube (0,2,2)
	Cube_rate(rox, roy, roz, 0, 2, 2);
	Draw_Cube(50.0, 150.0, -150.0, -50.0, -150.0, -50.0);

	glPopMatrix();


	//����
	glPushMatrix();

	//x��y���ϵ��ĸ�Cube (2,0,2)
	Cube_rate(rox, roy, roz, 2, 0, 2);
	Draw_Cube(-150.0, -50.0, 50.0, 150.0, -150.0, -50.0);

	glPopMatrix();


	//����
	glPushMatrix();

	//x��y���ϵ��ĸ�Cube (2,2,2)
	Cube_rate(rox, roy, roz, 2, 2, 2);
	Draw_Cube(-150.0, -50.0, -150.0, -50.0, -150.0, -50.0);

	glPopMatrix();
}
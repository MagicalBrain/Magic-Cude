#pragma once
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"

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
			glColor3f(1.0, 1.0, 0.0);
			break;
		case 1:
			glColor3f(1.0, 0.0, 0.0);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		default:
			break;
		}
		for (j = 0; j < 4; j++)
			glVertex3fv(vertex[surface[i][j]]);
	}
		
	glEnd();
}

void Cube_rate(int rox[][3][3],int roy[][3][3],int roz[][3][3],int n1, int n2, int n3)
{
	glRotatef((GLfloat)rox[n1][n2][n3], 1.0, 0.0, 0.0);
	glRotatef((GLfloat)roy[n1][n2][n3], 0.0, 1.0, 0.0);
	glRotatef((GLfloat)roz[n1][n2][n3], 0.0, 0.0, 1.0);
}
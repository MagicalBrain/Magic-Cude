#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include "MagicCude.h"

GLboolean bWire = false;
int rox[3][3][3] = {};
int roy[3][3][3] = {};
int roz[3][3][3] = {};

void Draw_Table()
{
	//�����Ӳ�ֳ�5�����������
	Draw_Cube(0.0, 1.0, 0.0, 0.8, 0.6, 0.8);//����
	Draw_Cube(0.1, 0.3, 0.1, 0.3, 0.0, 0.6);//������
	Draw_Cube(0.7, 0.9, 0.1, 0.3, 0.0, 0.6);
	Draw_Cube(0.1, 0.3, 0.5, 0.7, 0.0, 0.6);
	Draw_Cube(0.7, 0.9, 0.5, 0.7, 0.0, 0.6);
}

void OnDisplay(void)
{
	double RADIUS = 50.0f;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST); //ʹ����ȼ��

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

	

	//��Ҫ�������ݻ������
	glutSwapBuffers();
}




//��������Ӧ����
void OnReshape(int w, int h)
{
	double SIZE = 500.0f;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);

	float aspect = (float)h / (float)w;

	if (w <= h)
	{
		glOrtho(-SIZE, SIZE, -SIZE * aspect, SIZE * aspect, -SIZE, SIZE);
	}
	else
	{
		glOrtho(-SIZE / aspect, SIZE / aspect, -SIZE, SIZE, -SIZE, SIZE);
	}
	gluLookAt(10.0f, 20.0f, 25.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
}

void KeyBoard(unsigned char key, int x, int y)
//�����������������
{
	switch (key) {
	case 'a':
		roy[0][0][1] = (roy[0][0][1] + 90) % 360;
		roy[1][0][1] = (roy[1][0][1] + 90) % 360;
		roy[2][0][1] = (roy[2][0][1] + 90) % 360;
		glutPostRedisplay();
		break;
	case 'A':
		roy[0][0][1] = (roy[0][0][1] - 90) % 360;
		roy[1][0][1] = (roy[1][0][1] - 90) % 360;
		roy[2][0][1] = (roy[2][0][1] - 90) % 360;
		glutPostRedisplay();
		break;
	case 's':
		roy[0][1][1] = (roy[0][1][1] + 90) % 360;
		roy[1][1][1] = (roy[1][1][1] + 90) % 360;
		roy[2][1][1] = (roy[2][1][1] + 90) % 360;
		glutPostRedisplay();
		break;
	case 'S':
		roy[0][1][1] = (roy[0][1][1] - 90) % 360;
		roy[1][1][1] = (roy[1][1][1] - 90) % 360;
		roy[2][1][1] = (roy[2][1][1] - 90) % 360;
		glutPostRedisplay();
		break;
	case 'd':
		roy[0][2][1] = (roy[0][2][1] + 90) % 360;
		roy[1][2][1] = (roy[1][2][1] + 90) % 360;
		roy[2][2][1] = (roy[2][2][1] + 90) % 360;
		glutPostRedisplay();
		break;
	case 'D':
		roy[0][1][1] = (roy[0][1][1] - 90) % 360;
		roy[1][1][1] = (roy[1][1][1] - 90) % 360;
		roy[2][1][1] = (roy[2][1][1] - 90) % 360;
		glutPostRedisplay();
		break;
	case 'e':
		for (int i = 0; i < 3; i++)
			for (int j = 0;j < 3;j++)
				for (int k = 0; k < 3; k++)
				{
					rox[i][j][k] = 0;
					roy[i][j][k] = 0;
					roz[i][j][k] = 0;
				}
		glutPostRedisplay();
		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

//���ù��պ���
void SetupLights()
{
	GLfloat ambientLight[] = { 0.2f,  0.2f,  0.2f,  1.0f };//������
	GLfloat diffuseLight[] = { 0.9f,  0.9f,  0.9f,  1.0f };//������
	GLfloat specularLight[] = { 1.0f,  1.0f,  1.0f,  1.0f };//�����
	GLfloat lightPos[] = { 50.0f, 80.0f, 60.0f, 1.0f };//��Դλ��

	glEnable(GL_LIGHTING);								//���ù���
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);		//���û�����Դ
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);		//�����������Դ
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);	//���þ����Դ
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);		//���õƹ�λ��
	glEnable(GL_LIGHT0);								//�򿪵�һ���ƹ�

	glEnable(GL_COLOR_MATERIAL);						//���ò��ʵ���ɫ����
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);	//ָ��������ɫ����
	glMaterialfv(GL_FRONT, GL_SPECULAR, specularLight); //ָ�����϶Ծ����ķ�Ӧ
	glMateriali(GL_FRONT, GL_SHININESS, 100);           //ָ������ϵ��
}


int main(int argc, char *argv[])
{
	glutInit(&argc, argv);//��ʼ��GULT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);//������ʾģʽ
	glutInitWindowPosition(50, 100);//�������ϽǴ�����ʾλ��
	glutInitWindowSize(1920, 1080);//���ô�����ʾ�Ŀ����
	glutCreateWindow("An Example OpenGL Program��");//����һ������
	
	glutReshapeFunc(OnReshape);
	glutDisplayFunc(OnDisplay);//��ͼ����ʾ�ڴ���
	glutKeyboardFunc(KeyBoard);
	SetupLights();	//���ù��պ����������û�������
	glutMainLoop();//��ʾ���в�����ȴ�״̬
}
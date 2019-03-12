#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"

GLboolean bWire = false;



void OnDisplay(void)
{
	double RADIUS = 50.0f;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST); //ʹ����ȼ��

	glPushMatrix();
	
	glColor3f(1.0f, 0.0f, 0.0f);

	glEnable(GL_NORMALIZE);  //��һ��������

	glutSolidCone(RADIUS, 2 * RADIUS, 30, 30);

	glPopMatrix();
	glutSwapBuffers();
}


void OnReshape(int w, int h)
{
	double SIZE = 100.0f;
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
	glutInitWindowSize(600, 480);//���ô�����ʾ�Ŀ����
	glutCreateWindow("An Example OpenGL Program��");//����һ������
	
	glutReshapeFunc(OnReshape);
	glutDisplayFunc(OnDisplay);//��ͼ����ʾ�ڴ���
	SetupLights();	//���ù��պ����������û�������
	glutMainLoop();//��ʾ���в�����ȴ�״̬
}
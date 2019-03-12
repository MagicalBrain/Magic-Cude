#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"

GLboolean bWire = false;



void OnDisplay(void)
{
	double RADIUS = 50.0f;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST); //使能深度检测

	glPushMatrix();
	
	glColor3f(1.0f, 0.0f, 0.0f);

	glEnable(GL_NORMALIZE);  //归一化法向量

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

//设置光照函数
void SetupLights()
{
	GLfloat ambientLight[] = { 0.2f,  0.2f,  0.2f,  1.0f };//环境光
	GLfloat diffuseLight[] = { 0.9f,  0.9f,  0.9f,  1.0f };//漫反射
	GLfloat specularLight[] = { 1.0f,  1.0f,  1.0f,  1.0f };//镜面光
	GLfloat lightPos[] = { 50.0f, 80.0f, 60.0f, 1.0f };//光源位置

	glEnable(GL_LIGHTING);								//启用光照
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);		//设置环境光源
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);		//设置漫反射光源
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);	//设置镜面光源
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);		//设置灯光位置
	glEnable(GL_LIGHT0);								//打开第一个灯光

	glEnable(GL_COLOR_MATERIAL);						//启用材质的颜色跟踪
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);	//指定材料着色的面
	glMaterialfv(GL_FRONT, GL_SPECULAR, specularLight); //指定材料对镜面光的反应
	glMateriali(GL_FRONT, GL_SHININESS, 100);           //指定反射系数
}


int main(int argc, char *argv[])
{
	glutInit(&argc, argv);//初始化GULT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);//设置显示模式
	glutInitWindowPosition(50, 100);//设置左上角窗口显示位置
	glutInitWindowSize(600, 480);//设置窗口显示的宽与高
	glutCreateWindow("An Example OpenGL Program！");//创建一个窗口
	
	glutReshapeFunc(OnReshape);
	glutDisplayFunc(OnDisplay);//把图形显示在窗口
	SetupLights();	//调用光照函数，否则会没有立体感
	glutMainLoop();//显示所有并进入等待状态
}
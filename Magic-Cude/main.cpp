#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include "MagicCude.h"

GLboolean bWire = false;


void Draw_Table()
{
	//将桌子拆分成5个立方体绘制
	Draw_Cube(0.0, 1.0, 0.0, 0.8, 0.6, 0.8);//桌面
	Draw_Cube(0.1, 0.3, 0.1, 0.3, 0.0, 0.6);//四条腿
	Draw_Cube(0.7, 0.9, 0.1, 0.3, 0.0, 0.6);
	Draw_Cube(0.1, 0.3, 0.5, 0.7, 0.0, 0.6);
	Draw_Cube(0.7, 0.9, 0.5, 0.7, 0.0, 0.6);
}

void OnDisplay(void)
{
	//double RADIUS = 50.0f;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST); //使能深度检测

	Cube_00();
	Cube_01();
	Cube_02();

	

	//将要画的内容缓冲出来
	glutSwapBuffers();
}




//窗口自适应函数
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
//必须得有这三个参数
{
	switch (key) {
	case 'a':
		roy[0][0][1] = (roy[0][0][1] + 90) % 360;
		roy[1][0][1] = (roy[1][0][1] + 90) % 360;
		roy[2][0][1] = (roy[2][0][1] + 90) % 360;

		roy[0][0][0] = (roy[0][0][0] + 90) % 360;
		roy[1][0][0] = (roy[1][0][0] + 90) % 360;
		roy[2][0][0] = (roy[2][0][0] + 90) % 360;

		roy[0][0][2] = (roy[0][0][2] + 90) % 360;
		roy[1][0][2] = (roy[1][0][2] + 90) % 360;
		roy[2][0][2] = (roy[2][0][2] + 90) % 360;
		glutPostRedisplay();
		break;
	case 'q':
		roy[0][0][1] = (roy[0][0][1] - 90) % 360;
		roy[1][0][1] = (roy[1][0][1] - 90) % 360;
		roy[2][0][1] = (roy[2][0][1] - 90) % 360;

		roy[0][0][0] = (roy[0][0][0] - 90) % 360;
		roy[1][0][0] = (roy[1][0][0] - 90) % 360;
		roy[2][0][0] = (roy[2][0][0] - 90) % 360;

		roy[0][0][2] = (roy[0][0][2] - 90) % 360;
		roy[1][0][2] = (roy[1][0][2] - 90) % 360;
		roy[2][0][2] = (roy[2][0][2] - 90) % 360;
		glutPostRedisplay();
		break;
	case 's':
		roy[0][1][1] = (roy[0][1][1] + 90) % 360;
		roy[1][1][1] = (roy[1][1][1] + 90) % 360;
		roy[2][1][1] = (roy[2][1][1] + 90) % 360;

		roy[0][1][0] = (roy[0][1][0] + 90) % 360;
		roy[1][1][0] = (roy[1][1][0] + 90) % 360;
		roy[2][1][0] = (roy[2][1][0] + 90) % 360;

		roy[0][1][2] = (roy[0][1][2] + 90) % 360;
		roy[1][1][2] = (roy[1][1][2] + 90) % 360;
		roy[2][1][2] = (roy[2][1][2] + 90) % 360;
		glutPostRedisplay();
		break;
	case 'w':
		roy[0][1][1] = (roy[0][1][1] - 90) % 360;
		roy[1][1][1] = (roy[1][1][1] - 90) % 360;
		roy[2][1][1] = (roy[2][1][1] - 90) % 360;

		roy[0][1][0] = (roy[0][1][0] - 90) % 360;
		roy[1][1][0] = (roy[1][1][0] - 90) % 360;
		roy[2][1][0] = (roy[2][1][0] - 90) % 360;

		roy[0][1][2] = (roy[0][1][2] - 90) % 360;
		roy[1][1][2] = (roy[1][1][2] - 90) % 360;
		roy[2][1][2] = (roy[2][1][2] - 90) % 360;
		glutPostRedisplay();
		break;
	case 'd':
		roy[0][2][1] = (roy[0][2][1] + 90) % 360;
		roy[1][2][1] = (roy[1][2][1] + 90) % 360;
		roy[2][2][1] = (roy[2][2][1] + 90) % 360;

		roy[0][2][0] = (roy[0][2][0] + 90) % 360;
		roy[1][2][0] = (roy[1][2][0] + 90) % 360;
		roy[2][2][0] = (roy[2][2][0] + 90) % 360;

		roy[0][2][2] = (roy[0][2][2] + 90) % 360;
		roy[1][2][2] = (roy[1][2][2] + 90) % 360;
		roy[2][2][2] = (roy[2][2][2] + 90) % 360;
		glutPostRedisplay();
		break;
	case 'e':
		roy[0][2][1] = (roy[0][2][1] - 90) % 360;
		roy[1][2][1] = (roy[1][2][1] - 90) % 360;
		roy[2][2][1] = (roy[2][2][1] - 90) % 360;

		roy[0][2][0] = (roy[0][2][0] - 90) % 360;
		roy[1][2][0] = (roy[1][2][0] - 90) % 360;
		roy[2][2][0] = (roy[2][2][0] - 90) % 360;

		roy[0][2][2] = (roy[0][2][2] - 90) % 360;
		roy[1][2][2] = (roy[1][2][2] - 90) % 360;
		roy[2][2][2] = (roy[2][2][2] - 90) % 360;
		glutPostRedisplay();
		break;
	case 'r':
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
	case '1':
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 3; k++)
				{
					rox[i][j][k] = (rox[i][j][k] + 45) % 360;;
					//roy[i][j][k] = 0;
					//roz[i][j][k] = 0;
				}
		glutPostRedisplay();
		break;
	case '2':
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 3; k++)
				{
					roy[i][j][k] = (roy[i][j][k] + 45) % 360;;
					//roy[i][j][k] = 0;
					//roz[i][j][k] = 0;
				}
		glutPostRedisplay();
		break;
	case '3':
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 3; k++)
				{
					roz[i][j][k] = (roz[i][j][k] + 90) % 360;;
					//roy[i][j][k] = 0;
					//roz[i][j][k] = 0;
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
	glutInitWindowSize(1920, 1080);//设置窗口显示的宽与高
	glutCreateWindow("An Example OpenGL Program！");//创建一个窗口
	
	glutReshapeFunc(OnReshape);
	glutDisplayFunc(OnDisplay);//把图形显示在窗口
	glutKeyboardFunc(KeyBoard);
	SetupLights();	//调用光照函数，否则会没有立体感
	glutMainLoop();//显示所有并进入等待状态
}
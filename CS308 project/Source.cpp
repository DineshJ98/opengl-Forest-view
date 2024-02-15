#include <iostream>
#include <math.h>
#include <GL/glut.h>
#include"terrain.h"
#include"normalTree.h"
#include"grass.h"
#include"water.h"

//move the camera
GLfloat camX = 0, camY = 0, camZ = 0;
GLfloat objRY = 0;
//GLfloat PI = 3.141592653589;
GLfloat animationfactor = 0.0;
GLfloat h[20][20];
GLfloat rowsh = 20, colsh = 20;

void axis() {

	//x axis 
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(-20.0, 0.0, 0.0);
	glVertex3f(20.0, 0.0, 0.0);
	glEnd();

	//y axis 
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(0.0, -20.0, 0.0);
	glVertex3f(0.0, 20.0, 0.0);
	glEnd();

	//z axis 
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, -20.0);
	glVertex3f(0.0, 0.0, 20.0);
	glEnd();
}

void grid() {
	GLfloat ext = 20.0f;
	GLfloat step = 1.0f;
	GLfloat yGrid = -0.4f;
	GLint line;

	for (line = -ext; line <= ext; line += step) {
		glBegin(GL_LINES);
		glVertex3f(line, yGrid, ext);
		glVertex3f(line, yGrid, -ext);

		glVertex3f(ext, yGrid, line);
		glVertex3f(-ext, yGrid, line);
		glEnd();
	}
}


void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	gluLookAt(0.0 + camX, 3.0 + camY, 10.0 + camZ, 0, 0, 0, 0, 1, 0);
	glRotatef(objRY, 0.0, 1.0, 0.0);

	axis();
	glColor3f(1.0, 1.0, 1.0);
	grid();

	fullterrain();
	fullwater(h);
	


	//tree(10.0, 0.0, 10.0, 0.0);
	//tree(14.0, 0.0, -10.0, 45.0);
	//tree(11.0, 0.0, -5.0, 0.0);
	//tree(12.0, 0.0, -9.0, 0.0);

	//glPushMatrix();
	////glScalef(5.0, 5.0, 5.0);
	////grassLeaf3();
	//glTranslatef(5, 0.0, -5);
	//grassFull();
	//glPopMatrix();

	//glPushMatrix();
	//glTranslatef(0.0, 0.0, 0.0);
	//leavsOnBranchFinal();
	//glPopMatrix();
	//tree();
	glPopMatrix();
	glutSwapBuffers();

	for (int i = 0; i < rowsh; ++i) {
		for (int j = 0; j < colsh; ++j) {
			h[i][j] = 0.3 + static_cast<float>(rand()) / RAND_MAX * (0.5 - 0.3);
		}
	}
}

void reshape(GLsizei w, GLsizei h) {
	glViewport(0, 0, w, h);
	GLfloat aspect_ratio = h == 0 ? w / 1 : (GLfloat)w / (GLfloat)h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(120, aspect_ratio, 1.0, 100.0);
}

void MyInit() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glEnable(GL_DEPTH_TEST);
}

void keyboard(unsigned char key, int x, int y) {

	if (key == 'Z')
		camZ += 0.5;

	if (key == 'z')
		camZ -= 0.5;

	if (key == 'r')
		objRY += 0.5;

	if (key == 'R')
		objRY -= 0.5;

	glutPostRedisplay();
}

void specialkeyboard(int key, int x, int y) {
	if (key == GLUT_KEY_UP)
		camY += 0.5;

	if (key == GLUT_KEY_DOWN)
		camY -= 0.5;

	if (key == GLUT_KEY_LEFT)
		camX -= 0.5;

	if (key == GLUT_KEY_RIGHT)
		camX += 0.5;

	glutPostRedisplay();
}

void animation(int value) {
	animationfactor += 0.1;
	glutPostRedisplay();
	glutTimerFunc(280, animation, 0);
}

int main(int arcc, char** arcv) {

	glutInit(&arcc, arcv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(720, 480);
	glutCreateWindow("virtual forest");
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialkeyboard);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(280, animation, 0);
	MyInit();
	glutMainLoop();
	return 0;
}
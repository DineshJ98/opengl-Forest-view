#include <iostream>
#include <math.h>
#include <GL/glut.h>

//move the camera
GLfloat camX = 0; GLfloat  camY = 0; GLfloat camZ = 0;
GLfloat objRY = 0;
GLfloat PI = 3.141592653589;

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

void terrain() {
	GLfloat heigth[11][11] = { {0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0}
	};
	GLfloat x = -5;
	GLfloat z = -5;

	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 10; i++) {
		for (int j = 0; j <= 10; j++) {
			glVertex3f(x, heigth[i][j], z);
			std::cout << x << std::endl;
			x++;
		}
		x = -5;
		z++;
	}
	glEnd();
}

void terrain2() {
	
	GLfloat height[2][2] = {
		{0,1.5},
		{1.5,2}
	};

	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_TRIANGLE_STRIP);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			glVertex3f(j, height[j][i], i);
		}
	}
	glEnd();
}

void terrain3() {
	GLfloat heigth[11][11] = { {0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,1,2,3,2,1,0,0,0},
								{0,0,0,2,3,4,3,2,0,0,0},
								{0,0,0,3,4,5,4,3,0,0,0},
								{0,0,0,2,3,4,3,2,0,0,0},
								{0,0,0,1,2,3,2,1,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0}
	};
	int rows = 11, cols = 11;
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_STRIP);
	for (int i = 0; i < rows-1; i++) {
		for (int j = 0; j < cols; j++) {
			glVertex3f(j, heigth[j][i], i);
			glVertex3f(j, heigth[j][i+1], i + 1);
		}
	}
	glEnd();
}

void leafs() {
	
	glColor3f(0.0, 1.0, 0.10);
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 0.0, -0.02);
	glVertex3f(0.035, 0.05, 0.01);
	glVertex3f(0.05, 0.1, -0.02);
	glVertex3f(0.035, 0.15, -0.02);
	glVertex3f(0.0, 0.2, 0.01);
	glVertex3f(-0.035, 0.15, -0.01);
	glVertex3f(-0.05, 0.1, 0.02);
	glVertex3f(-0.035, 0.05, -0.02);
	glEnd();
}

void leafsOnBranch() {
	GLfloat x = 0, y = 0, z = 0;
	GLfloat angle = 0.0;

	for (int i = 0; i < 10; i++) {
		glPushMatrix();
		x = 1 * cos(angle);
		z = 1 * sin(angle);
		glTranslatef(x, y, z);
		glRotatef(angle - 90, 0.0, 1.0, 0.0);
		glRotatef(90, 1.0, 0.0, 0.0);
		leafs();
		glPopMatrix();
		angle += PI * 2 / 10;
	}
}

void tree() {
	glPushMatrix();
	glRotatef(-90, 1.0, 0.0, 0.0);
	glColor3f(0.40, 0.25, 0.20);
	glutSolidCone(2, 5, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 2.0, 0.0);
	glRotatef(-90, 1.0, 0.0, 0.0);
	glColor3f(0.40, 1.0, 0.20);
	glutSolidCone(2, 5, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 3.0, 0.0);
	glRotatef(-90, 1.0, 0.0, 0.0);
	glColor3f(0.40, 1.0, 0.20);
	glutSolidCone(2, 5, 50, 50);
	glPopMatrix();
}


void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	gluLookAt(0.0 + camX, 3.0 + camY, 10.0 + camZ, 0, 0, 0, 0, 1, 0);
	glRotatef(objRY, 0.0, 1.0, 0.0);

	axis();
	glColor3f(1.0, 1.0, 1.0);
	grid();

	//glPushMatrix();
	//glTranslatef(-5.0, 0.0, -5.0);
	//terrain3();
	//glPopMatrix();

	glPushMatrix();
	glScalef(10, 10, 10);
	leafsOnBranch();
	glPopMatrix();

	//tree();
	glPopMatrix();
	glutSwapBuffers();
}

void reshape(GLsizei w,GLsizei h) {
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

int main(int arcc ,char** arcv) {
	
	glutInit(&arcc, arcv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(720, 480);
	glutCreateWindow("virtual forest");
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialkeyboard);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	MyInit();
	glutMainLoop();
	return 0;
}
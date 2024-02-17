#include <iostream>
#include<SOIL2.h>
#include <math.h>
#include <GL/glut.h>
#include"terrain.h"
#include"normalTree.h"
#include"grass.h"
#include"water.h"
#include"bambootree.h"
#include"rock.h"

//move the camera
GLfloat camX = 0, camY = 5.0, camZ = 5.0;
GLfloat objRY = 0;
GLfloat animationfactor = 0.0;
GLfloat h[20][20];
GLfloat rowsh = 20, colsh = 20;


GLfloat textureId;


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

void loadTexture() {
	textureId = SOIL_load_OGL_texture(
		"terrain.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y
	);

	if (!textureId) {
		printf("Texture load failed: %s\n", SOIL_last_result());
	}
}
void loadTextureRock() {
	textureId = SOIL_load_OGL_texture(
		"rock.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y
	);

	if (!textureId) {
		printf("Texture load failed: %s\n", SOIL_last_result());
	}
}



void setLighting() {
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	//set lighting intensity and color
	GLfloat qaAmbientLight[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat qaDiffuseLight[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat qaSpecularLight[] = { 1.0, 1.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);

	//set position of the light
	GLfloat qaLightPosition[] = { 0.0, 1.0, 4.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);
}


void display() {


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	setLighting();


	glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();



	glPushMatrix();
	gluLookAt(0.0 + camX, 3.0 + camY, 10.0 + camZ, 0, 0, 0, 0, 1, 0);
	glRotatef(objRY, 0.0, 1.0, 0.0);

	/*axis();
	glColor3f(1.0, 1.0, 1.0);
	grid();*/
	//loadTextureRock();
	//rock(textureId);
	bambooTree(10.0, 0.0, -10.0, 180.0);
	bambooTree(10.0, 0.0, -10.0, 30.0);
	bambooTree(12.0, 0.0, -12.0, 45.0);
	bambooTree(12.0, 0.0, -9.0, -45.0);

	bambooTree(-10.0, 0.0, 10.0, 180.0);
	bambooTree(-10.0, 0.0, 10.0, 30.0);
	bambooTree(-12.0, 0.0, 12.0, 45.0);
	bambooTree(-12.0, 0.0, 9.0, -45.0);
	
	bambooTree(-10.0, 0.0, -10.0, 180.0);
	bambooTree(-10.0, 0.0, -10.0, 30.0);
	bambooTree(-12.0, 0.0, -12.0, 90.0);
	bambooTree(-12.0, 0.0, -9.0, -45.0);

	glPushMatrix();
	glTranslatef(-9.0, 1.0, -9.0);
	grassFull();
	glPopMatrix();

	for (int i = 0; i < 4; i++) {
		glPushMatrix();
		glTranslatef(-5.0 + (-1) * i, 1.0 , -5.0 + (-1) * i);
		grassFull();
		glPopMatrix();
	}

	for (int i = 0; i < 4; i++) {
		glPushMatrix();
		glTranslatef(-5.0 + (-1) * i, 1.0, -3.0 + (-1) * i);
		grassFull();
		glPopMatrix();
	}
	for (int i = 0; i < 4; i++) {
		glPushMatrix();
		glTranslatef(-5.0 + (-1) * i, 1.0, -7.0 + (-1) * i);
		grassFull();
		glPopMatrix();
	}
	for (int i = 0; i < 4; i++) {
		glPushMatrix();
		glTranslatef(-5.0 + (-1) * i, 1.0, -2.0 + (-1) * i);
		grassFull();
		glPopMatrix();
	}

	for (int i = 0; i < 4; i++) {
		glPushMatrix();
		glTranslatef(5.0 + (-1) * i, 1.0, 9.0 + (-1) * i);
		grassFull();
		glPopMatrix();
	}
	
	for (int i = 0; i < 4; i++) {
		glPushMatrix();
		glTranslatef(7.0 + (-1) * i, 1.0, 9.0 + (-1) * i);
		grassFull();
		glPopMatrix();
	}
	
	for (int i = 0; i < 4; i++) {
		glPushMatrix();
		glTranslatef(9.0 + (-1) * i, 1.0, 9.0 + (-1) * i);
		grassFull();
		glPopMatrix();
	}


	loadTexture();
	fullterrain();
	fullwater(h);

	tree(-10.0, 0.0, -20.0, 0.0);
	tree(15.0, 1.0, 9.0, 60.0);

	loadTextureRock();
	glPushMatrix();
	glTranslatef(8.0, 1.0, 7.0);
	glScalef(0.7, 1.0, 0.4);
	rock(textureId);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(7.0, 2.0, 9.0);
	glScalef(0.5, 1.0, 0.1);
	rock(textureId);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-10.0, 2.0, 0.0);
	glScalef(1.1, 1.0, 1.7);
	rock(textureId);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-11.0, 2.0, 5.0);
	glScalef(0.7, 0.7, 1.0);
	rock(textureId);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(10.0, 2.0, -10.0);
	glScalef(1.1, 1.0, 1.7);
	rock(textureId);
	glPopMatrix();

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
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);

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
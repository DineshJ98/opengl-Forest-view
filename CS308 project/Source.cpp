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
#include"swan.h"
#include"sky.h"
#include"waterlily.h"

//move the camera
GLfloat camX = 0, camY = 5.0, camZ = 5.0;
GLfloat objRY = 0;
GLfloat angle = 0.0, xs = 0.0, zs = 0.0, swanrotationfactor = 90.0;
GLfloat h[20][20];
GLfloat rowsh = 20, colsh = 20;
GLfloat PIswan = 3.141592653589;

GLfloat textureIdsoil;
GLfloat textureIdrock;
GLfloat textureIdtree;
GLfloat textureIdsky;
GLfloat textureIdflowerbase;
GLfloat textureIdflowertop;
GLfloat textureIdskybackground;


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

void loadTextureskybackground() {
	textureIdskybackground = SOIL_load_OGL_texture(
		"skyimage.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y
	);

	if (!textureIdskybackground) {
		printf("Texture load failed: %s\n", SOIL_last_result());
	}
}

void loadTextureflowertop() {
	textureIdflowertop = SOIL_load_OGL_texture(
		"flowertop.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y
	);

	if (!textureIdflowertop) {
		printf("Texture load failed: %s\n", SOIL_last_result());
	}
}

void loadTextureflowerbase() {
	textureIdflowerbase = SOIL_load_OGL_texture(
		"baseofflower.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y
	);

	if (!textureIdflowerbase) {
		printf("Texture load failed: %s\n", SOIL_last_result());
	}
}

void loadTexturesky() {
	textureIdsky = SOIL_load_OGL_texture(
		"sky.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y
	);

	if (!textureIdsky) {
		printf("Texture load failed: %s\n", SOIL_last_result());
	}
}

void loadTexturetree() {
	textureIdtree = SOIL_load_OGL_texture(
		"wood.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y
	);

	if (!textureIdtree) {
		printf("Texture load failed: %s\n", SOIL_last_result());
	}
}

void loadTexture() {
	textureIdsoil = SOIL_load_OGL_texture(
		"terrain.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y
	);

	if (!textureIdsoil) {
		printf("Texture load failed: %s\n", SOIL_last_result());
	}
}
void loadTextureRock() {
	textureIdrock = SOIL_load_OGL_texture(
		"rock.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y
	);

	if (!textureIdrock) {
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
	GLfloat qaLightPosition0[] = { -1.0, 0.5, 0.5, 0.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition0);


	glLightfv(GL_LIGHT1, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT1, GL_SPECULAR, qaSpecularLight);

	//set position of the light
	GLfloat qaLightPosition1[] = { -1.0, 5.0, 15.0, 1.0 };
	glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
}


void display() {


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	setLighting();


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0 + camX, 3.0 + camY, 10.0 + camZ, 0, 0, 0, 0, 1, 0);



	glPushMatrix();
	glRotatef(objRY, 0.0, 1.0, 0.0);

	/*axis();
	glColor3f(1.0, 1.0, 1.0);
	grid();*/
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
	
	bambooTree(-15.0, 5.0, 0.0, -45.0);
	bambooTree(-14.0, 5.0, -1.0, 0.0);

	glPushMatrix();
	glTranslatef(-7.5, 2.1, 11.0);
	glScalef(1.0, 1.5, 1.0);
	grassFull();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-7.5, 2.4, 12.0);
	glScalef(1.5, 1.1, 1.0);
	grassFull();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-9.0, 1.0, -9.0);
	grassFull();
	glPopMatrix();

	for (int i = 0; i < 4; i++) {
		glPushMatrix();
		glTranslatef(-5.0 + (-1) * i, 1.0, -5.0 + (-1) * i);
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


	fullterrain(textureIdsoil);
	fullwater(h);

	tree(-10.0, 0.0, -16.0, 0.0, textureIdtree);
	tree(15.0, 1.0, 9.0, 60.0, textureIdtree);

	glPushMatrix();
	glTranslatef(8.0, 1.0, 7.0);
	glScalef(0.7, 1.0, 0.4);
	rock(textureIdrock);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(7.0, 2.0, 9.0);
	glScalef(0.5, 1.0, 0.6);
	rock(textureIdrock);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-10.0, 2.0, 0.0);
	glScalef(1.1, 1.0, 1.7);
	rock(textureIdrock);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-11.0, 2.0, 5.0);
	glScalef(0.7, 0.7, 1.0);
	rock(textureIdrock);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(10.0, 2.0, -10.0);
	glScalef(1.1, 1.0, 1.7);
	rock(textureIdrock);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-10.0, 2.0, 11.0);
	glScalef(1.1, 0.5, 0.7);
	rock(textureIdrock);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-13.7, 6.4, -1.0);
	glScalef(0.5, 0.5, 0.7);
	rock(textureIdrock);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(xs, 1.0, zs);
	glRotatef(swanrotationfactor, 0.0, 1.0, 0.0);
	swan();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5.0, 1.07, -5.0);
	waterlily();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.0, 1.07, -5.0);
	waterlily();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.5, 1.07, -7.0);
	waterlily();
	glPopMatrix();

	waterlilyflower(3.7, 3.07, -5.4, textureIdflowertop, textureIdflowerbase);
	
	glPushMatrix();
	glTranslatef(-5.4, 1.07, 5.0);
	waterlily();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.4, 1.07, 5.0);
	waterlily();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.9, 1.07, 7.0);
	waterlily();
	glPopMatrix();

	waterlilyflower(-4.0, 3.07, 5.4, textureIdflowertop, textureIdflowerbase);

	sky(textureIdsky,textureIdskybackground);

	glPopMatrix();
	glutSwapBuffers();

	swanrotationfactor -= 360 / 60;
	angle += 2 * PIswan / 60;
	xs = 2.0 * cos(angle);
	zs = 2.0 * sin(angle);

	if (angle > 2 * PIswan) {
		angle = 0.0;
	}

	if (swanrotationfactor < -270) {
		swanrotationfactor = 90.0;
	}

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
	loadTextureRock();
	loadTexture();
	loadTexturetree();
	loadTexturesky();
	loadTextureflowerbase();
	loadTextureflowertop();
	loadTextureskybackground();
}

void keyboard(unsigned char key, int x, int y) {

	if (key == 'Z')
		camZ += 1.0;

	if (key == 'z')
		camZ -= 1.0;

	if (key == 'r')
		objRY += 1.0;

	if (key == 'R')
		objRY -= 1.0;

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
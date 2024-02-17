#include<GL/glut.h>

GLfloat waterlilyleaf[] = { 0.451,0.4745,0.2313,1.0 };
GLfloat waterlilydiff[] = { 0.3,0.3,0.3,1.0 };

void waterlily() {
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);

	glMaterialfv(GL_FRONT, GL_AMBIENT, waterlilyleaf);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, waterlilydiff);
	glMaterialfv(GL_FRONT, GL_SPECULAR, waterlilyleaf);
	glMaterialf(GL_FRONT, GL_SHININESS, 128);

	glPushMatrix();
	gluSphere(gluNewQuadric(), 1.0, 50, 50);
	glPopMatrix();

	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT1);
	glDisable(GL_LIGHT0);
}
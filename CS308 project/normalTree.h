#include<GL/glut.h>
#include<math.h>#pragma once
GLfloat PI = 3.141592653589;

GLfloat treeleaf[] = { 0.0196 ,0.2784 ,0.1647 ,1.0 };
GLfloat treediff[] = { 0.3 ,0.3 ,0.3 ,1.0 };
GLfloat treetrunk[] = { 0.447,0.3725,0.2941,1.0 };

void leafs() {

	glMaterialfv(GL_FRONT, GL_AMBIENT, treeleaf);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, treediff);
	glMaterialfv(GL_FRONT, GL_SPECULAR, treeleaf);
	glMaterialf(GL_FRONT, GL_SHININESS, 10);

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

void leafsOnBranch(GLfloat r) {
	GLfloat x = 0, y = 0.0, z = 0;
	GLfloat angle = 0.0;
	GLfloat angleY = 0.0;

	for (int j = 0; j < 40; j++) {
		for (int i = 0; i < 10; i++) {

			glMaterialfv(GL_FRONT, GL_AMBIENT, treeleaf);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, treediff);
			glMaterialfv(GL_FRONT, GL_SPECULAR, treeleaf);
			glMaterialf(GL_FRONT, GL_SHININESS, 10);

			glPushMatrix();
			x = r * cos(angle);
			z = r * sin(angle);
			glTranslatef(x, y, z);
			glRotatef(angle + 90, 0.0, 1.0, 0.0);
			glRotatef(90, 1.0, 0.0, 0.0);
			leafs();
			glPopMatrix();
			angle += PI * 2 / 10;
		}
		//angle = 0.0;
		//for (int i = 0; i < 10; i++) {
		//	glPushMatrix();
		//	x = r * cos(angle);
		//	z = r * sin(angle);
		//	glTranslatef(x,-0.1 - y, z);
		//	glRotatef(angle - 90, 0.0, 1.0, 0.0);
		//	glRotatef(90, 1.0, 0.0, 0.0);
		//	leafs();
		//	glPopMatrix();
		//	angle += PI * 2 / 10;
		//}
		angle = 0.0;
		y = sin(angleY);
		r = cos(angleY);
		angleY += PI * 2 / 40;
	}

}


void cupForTheTrunk(GLfloat r) {
	glMaterialfv(GL_FRONT, GL_AMBIENT, treetrunk);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, treediff);
	glMaterialfv(GL_FRONT, GL_SPECULAR, treetrunk);
	glMaterialf(GL_FRONT, GL_SHININESS, 30);
	GLfloat angle = 0.0;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 180; i++) {
		GLfloat x = r * cos(angle);
		GLfloat z = r * sin(angle);
		glVertex3f(x, 0.0, z);
		angle += 2 * PI / 180;
	}
	glEnd();
}

void tree(GLfloat x, GLfloat y, GLfloat z, GLfloat rotate) {
	GLfloat h = 3.0, translatefactor = 0.0, r = 1.0;

	for (int i = 0; i < 3; i++) {

		glMaterialfv(GL_FRONT, GL_AMBIENT, treetrunk);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, treediff);
		glMaterialfv(GL_FRONT, GL_SPECULAR, treetrunk);
		glMaterialf(GL_FRONT, GL_SHININESS, 30);

		glColor3f(0.30, 0.20, 0.18);
		glPushMatrix();
		glTranslatef(0.0 + x, translatefactor + y, 0.0 + z);
		glRotatef(-90, 1.0, 0.0, 0.0);
		gluCylinder(gluNewQuadric(), 1.0 - i * 0.2, 1.0 - i * 0.2, h, 50, 50);
		glPopMatrix();
		translatefactor += h;
		h -= i * 0.1;

		glColor3f(0.30, 0.20, 0.18);
		glPushMatrix();
		glTranslatef(0.0 + x, translatefactor + y, 0.0 + z);
		cupForTheTrunk(1.0 - i * 0.2);
		glPopMatrix();

		glColor3f(0.30, 0.20, 0.18);
		glPushMatrix();
		glTranslatef(0.0 + x, translatefactor + y, 0.0 + z);
		glRotatef(90 * i + rotate, 0.0, 1.0, 0.0);
		glRotatef(-45, 1.0, 0.0, 0.0);
		gluCylinder(gluNewQuadric(), 0.5 - i * 0.1, 0.5 - i * 0.1, h - 0.2, 50, 50);
		glPopMatrix();


		glPushMatrix();
		glTranslatef(x, y, z);
		glRotatef(90 * i + rotate, 0.0, 1.0, 0.0);
		glTranslatef(0.4, translatefactor + h / 2, 0.2 + h / 2);
		glScalef(0.5, 0.5, 0.5);
		leafsOnBranch(1.0);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(x, y, z);
		glRotatef(90 * i + rotate, 0.0, 1.0, 0.0);
		glTranslatef(-0.4, translatefactor + h / 2, 0.2 + h / 2);
		glScalef(0.5, 0.5, 0.5);
		leafsOnBranch(1.0);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(x, y, z);
		glRotatef(90 * i + rotate, 0.0, 1.0, 0.0);
		glTranslatef(0.0, translatefactor + h / 2, 0.6 + h / 2);
		glScalef(0.5, 0.5, 0.5);
		leafsOnBranch(1.0);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(x, y, z);
		glRotatef(90 * i + rotate, 0.0, 1.0, 0.0);
		glTranslatef(0.0, translatefactor + h / 2, 0.2 + h / 2);
		glScalef(0.5, 0.5, 0.5);
		leafsOnBranch(1.0);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(x, y, z);
		glRotatef(90 * i + rotate, 0.0, 1.0, 0.0);
		glTranslatef(0.0, 0.4 + translatefactor + h / 2, 0.2 + h / 2);
		glScalef(0.5, 0.5, 0.5);
		leafsOnBranch(1.0);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(x, y, z);
		glRotatef(90 * i + rotate, 0.0, 1.0, 0.0);
		glTranslatef(0.0, 0.4 + translatefactor + h / 2, 0.2 + h / 2);
		glScalef(0.5, 0.5, 0.5);
		leafsOnBranch(1.0);
		glPopMatrix();

	}
}

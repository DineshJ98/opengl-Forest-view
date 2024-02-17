#include<GL/glut.h>
#include<math.h>

GLfloat white[] = { 1.0,1.0,1.0,1.0 };
GLfloat black[] = { 0.0,0.0,0.0,1.0 };
GLfloat eyediff[] = { 0.2,0.2,0.2,1.0 };
GLfloat beak[] = { 0.9843,0.6039,0.3725,1.0 };

void swan() {
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glShadeModel(GL_SMOOTH);

	glMaterialfv(GL_FRONT, GL_AMBIENT, white);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMaterialf(GL_FRONT, GL_SHININESS, 10);

	glPushMatrix();//boady
	glScalef(1.7, 0.7, 1.0);
	glutSolidSphere(1.0, 50, 50);
	glPopMatrix();

	glPushMatrix();//tail
	glTranslated(1.6, 0.0, 0.0);
	glRotatef(45, 0.0, 0.0, 1.0);
	glRotatef(90, 0.0, 1.0, 0.0);
	glutSolidCone(0.2, 1.0, 50, 50);
	glPopMatrix();

	glPushMatrix();//tail
	glTranslated(1.6, 0.0, 0.0);
	glRotatef(45, 0.0, 0.0, 1.0);
	glRotatef(120, 0.0, 1.0, 0.0);
	glutSolidCone(0.2, 1.0, 50, 50);
	glPopMatrix();

	glPushMatrix();//tail
	glTranslated(1.6, 0.0, 0.0);
	glRotatef(45, 0.0, 0.0, 1.0);
	glRotatef(60, 0.0, 1.0, 0.0);
	glutSolidCone(0.2, 1.0, 50, 50);
	glPopMatrix();

	glPushMatrix();//neck
	glTranslated(-1.5, 0.0, 0.0);
	glRotatef(120, 0.0, 0.0, 1.0);
	glRotatef(90, 0.0, 1.0, 0.0);
	glutSolidCone(0.3, 1.3, 50, 50);
	glPopMatrix();

	glPushMatrix();//head
	glTranslatef(-2.0, 1.0, 0.0);
	glScalef(0.4, 0.2, 0.3);
	glutSolidSphere(1.0, 50, 50);
	glPopMatrix();

	glMaterialfv(GL_FRONT, GL_AMBIENT, beak);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, eyediff);
	glMaterialfv(GL_FRONT, GL_SPECULAR, beak);
	glMaterialf(GL_FRONT, GL_SHININESS, 128);

	glPushMatrix();//beak
	glTranslated(-2.35, 1.0, 0.0);
	glRotatef(180, 0.0, 0.0, 1.0);
	glRotatef(90, 0.0, 1.0, 0.0);
	glutSolidCone(0.1, 0.3, 50, 50);
	glPopMatrix();

	glMaterialfv(GL_FRONT, GL_AMBIENT, black);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, eyediff);
	glMaterialfv(GL_FRONT, GL_SPECULAR, black);
	glMaterialf(GL_FRONT, GL_SHININESS, 128);

	glPushMatrix();//eye
	glTranslatef(-2.3, 1.10, 0.15);
	glScalef(0.05, 0.05, 0.05);
	glutSolidSphere(1.0, 50, 50);
	glPopMatrix();
	
	glPushMatrix();//eye
	glTranslatef(-2.3, 1.10, -0.15);
	glScalef(0.05, 0.05, 0.05);
	glutSolidSphere(1.0, 50, 50);
	glPopMatrix();

	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHT1);
}
#include<GL/glut.h>
#include<math.h>

void grassLeaf1() {
	glColor3f(0.05, 0.9, 0.2);
	glBegin(GL_POLYGON);
	glVertex3f(0.05, 0.0, 0.0);
	glVertex3f(0.1, 0.25, 0.1);
	glVertex3f(0.15, 0.5, 0.2);
	glVertex3f(0.15, 0.75, 0.3);
	glVertex3f(0.0, 1.0, 0.4);

	glVertex3f(-0.15, 0.75, 0.3);
	glVertex3f(-0.15, 0.5, 0.2);
	glVertex3f(-0.1, 0.25, 0.1);
	glVertex3f(-0.05, 0.0, 0.0);
	glEnd();
}

void grassLeaf2() {
	glColor3f(0.3, 0.9, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(0.05, 0.0, 0.0);
	glVertex3f(0.1, 0.25, 0.0);
	glVertex3f(0.125, 0.5, 0.07);
	glVertex3f(0.15, 0.75, 0.17);
	glVertex3f(0.15, 1.0, 0.27);
	glVertex3f(0.0, 1.25, 0.37);

	glVertex3f(-0.15, 1.0, 0.27);
	glVertex3f(-0.15, 0.75, 0.17);
	glVertex3f(-0.125, 0.5, 0.07);
	glVertex3f(-0.1, 0.25, 0.0);
	glVertex3f(-0.05, 0.0, 0.0);
	glEnd();
}

void grassLeaf3() {
	glBegin(GL_POLYGON);
	glVertex3f(0.05, 0.0, 0.0);
	glVertex3f(0.1, 0.25, 0.2);
	glVertex3f(0.125, 0.5, 0.3);
	glVertex3f(0.0, 0.25, 0.4);

	glEnd();
}

void grassFull() {

	glColor3f(0.5, 0.9, 0.7);
	glPushMatrix();
	glRotatef(-90, 1.0, 0.0, 0.0);
	glutSolidCone(0.1, 1.3, 50, 50);
	glPopMatrix();
	for (int i = 0; i < 5; i++) {
		glPushMatrix();
		glRotatef(72 * i, 0.0, 1.0, 0.0);
		grassLeaf1();
		glPopMatrix();

		glPushMatrix();
		glRotatef(72 * i, 0.0, 1.0, 0.0);
		grassLeaf2();
		glPopMatrix();
	}
}

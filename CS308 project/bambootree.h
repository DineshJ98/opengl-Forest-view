#include<GL/glut.h>
#include<math.h>

GLfloat PIs = 3.141592653589;
GLfloat bambooleafcolor[] = { 0.34,0.4267, 0.274,1.0 };
GLfloat materialDeffu[] = { 0.2,0.2,0.2,1.0 };
GLfloat bambooyellow[] = { 0.682,0.533,0.294,1.0 };

void bambooLeaf() {

	

	glMaterialfv(GL_FRONT, GL_AMBIENT, bambooleafcolor);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDeffu);
	glMaterialfv(GL_FRONT, GL_SPECULAR, bambooleafcolor);
	glMaterialf(GL_FRONT, GL_SHININESS, 1);


	//glColor3f(0.5, 0.8, 0.6);
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 0.2, 0.0);
	glVertex3f(0.4, 0.1, 0.0);
	glVertex3f(0.6, 0.3, 0.0);
	glVertex3f(0.4, 0.5, 0.0);
	glVertex3f(0.1, 0.4, 0.0);
	glVertex3f(0.15, 0.8, 0.0);
	glVertex3f(0.0, 1.0, 0.0);

	glVertex3f(-0.15, 0.8, 0.0);
	glVertex3f(-0.1, 0.4, 0.0);
	glVertex3f(-0.4, 0.5, 0.0);
	glVertex3f(-0.6, 0.3, 0.0);
	glVertex3f(-0.4, 0.1, 0.0);
	glEnd();
}

void bambooLeafSegment() {
	glPushMatrix();
	glRotatef(-90, 0.0, 1.0, 0.0);
	glRotatef(45, 1.0, 0.0, 0.0);
	bambooLeaf();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0.0, 1.0, 0.0);
	glRotatef(45, 1.0, 0.0, 0.0);
	bambooLeaf();
	glPopMatrix();
}

void bambooTree(GLfloat movex, GLfloat movey, GLfloat movez, GLfloat rotatefactor) {

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glShadeModel(GL_SMOOTH);

	GLfloat angle = PIs;
	GLfloat r = 6.0, x = 0.0, y = 0.0;


	for (int i = 0; i <= 6; i++) {

		glMaterialfv(GL_FRONT, GL_AMBIENT, bambooyellow);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDeffu);
		glMaterialfv(GL_FRONT, GL_SPECULAR, bambooleafcolor);
		glMaterialf(GL_FRONT, GL_SHININESS, 100);

		x = r * cos(angle);
		y = r * sin(angle);
		glColor3f(0.30, 0.20, 0.18);
		glPushMatrix();
		glTranslatef(movex, movey, movez);
		glRotatef(rotatefactor, 0.0, 1.0, 0.0);
		glTranslatef(x + r, y, 0.0);
		glRotatef(i * (-90 / 6) - 6, 0.0, 0.0, 1.0);
		glRotatef(-90, 1.0, 0.0, 0.0);
		gluCylinder(gluNewQuadric(), 0.2, 0.2, 1.6, 50, 50);
		glPopMatrix();

		if (i != 0) {
			glPushMatrix();
			glTranslatef(movex, movey, movez);
			glRotatef(rotatefactor, 0.0, 1.0, 0.0);
			glTranslatef(0.0 + x + r, y, 0.0);
			glRotatef(i * (-90 / 6) - 6, 0.0, 0.0, 1.0);
			bambooLeafSegment();
			glPopMatrix();
		}



		angle -= PIs / 2 / 6;

	}
	glColor3f(0.30, 0.90, 0.18);
	glPushMatrix();
	glTranslatef(movex, movey, movez);
	glRotatef(rotatefactor, 0.0, 1.0, 0.0);
	glTranslatef(1.6 + r, r - 0.17, 0.0);
	glRotatef(90, 0.0, 1.0, 0.0);
	glutSolidCone(0.2, 1.0, 50, 50);
	glPopMatrix();

	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHT1);

}

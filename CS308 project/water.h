#include<GL/glut.h>
#include<math.h>

GLfloat watercolor[] = { 0.1373,0.5373,0.8549,1.0 };
GLfloat waterDiff[] = { 0.2,0.2,0.2,1.0 };

void underTheWater() {
	glMaterialfv(GL_FRONT, GL_AMBIENT, watercolor);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, waterDiff);
	glMaterialfv(GL_FRONT, GL_SPECULAR, watercolor);
	glMaterialf(GL_FRONT, GL_SHININESS, 100);

	glPushMatrix();
	glTranslatef(0.0, 0.4, 0.0);
	glScalef(20.0, 1.0, 20.0);
	glutSolidCube(1.0);
	glPopMatrix();
}

void water(GLfloat height[20][20]) {
	int rows = 20, cols = 20;
	//glColor3f(1.0, 0.0, 0.0);
	for (int i = 0; i < rows - 1; i++) {
		glBegin(GL_TRIANGLE_STRIP);
		for (int j = 0; j < cols - 1; j++) {
			glColor3f(0.0, 0.0, 1.0 / height[j][i] * 5);
			glVertex3f(j, height[j][i], i);
			glColor3f(0.0, 0.0, 1.0 / height[j][i] * 5);
			glVertex3f(j, height[j][i + 1], i + 1);
			glColor3f(0.0, 0.0, 1.0 / height[j][i] * 5);
			glVertex3f(j + 1, height[j + 1][i], i);
		}
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
		for (int j = 0; j < cols - 1; j++) {
			glColor3f(0.0, 0.0, 1.0 / height[j][i] * 5);
			glVertex3f(j + 1, height[j + 1][i], i);
			glColor3f(0.0, 0.0, 1.0 / height[j][i] * 5);
			glVertex3f(j + 1, height[j + 1][i + 1], i + 1);
			glColor3f(0.0, 0.0, 1.0 / height[j][i] * 5);
			glVertex3f(j, height[j][i + 1], i + 1);
		}
		glEnd();
	}
}

void fullwater(GLfloat h[20][20]) {
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glShadeModel(GL_SMOOTH);

	underTheWater();

	glPushMatrix();
	glTranslatef(-10.0, 0.59, -10.0);
	water(h);
	glPopMatrix();

	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHT1);
}
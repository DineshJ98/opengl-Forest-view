#include<GL/glut.h>
#include<math.h>

void underTheWater() {
	glColor3f(0.0, 0.0, 1.0);
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
	underTheWater();

	glPushMatrix();
	glTranslatef(-10.0, 0.55, -10.0);
	water(h);
	glPopMatrix();
}
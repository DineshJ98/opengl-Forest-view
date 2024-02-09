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

void cornerhills1() {
	GLfloat height[10][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{ 1, 1.5, 1.8, 2.2, 2.5, 2.5, 2.5, 2.2, 1.5, 1 },
		{ 1, 1.5, 2, 2.3, 2.7, 3, 2.7, 2.3, 2, 1 },
		{ 1, 1.8, 2.2, 2.5, 2.8, 3, 2.8, 2.5, 2.2, 1.8 },
		{ 1, 2.2, 2.5, 2.8, 3, 3.2, 3, 2.8, 2.5, 2.2 },
		{ 1, 2.5, 2.8, 3, 3.2, 3.5, 3.2, 3, 2.8, 2.5 },
		{ 1, 2.7, 3, 3.2, 3.5, 3.8, 3.5, 3.2, 3, 2.7 },
		{ 1, 3, 3.2, 3.5, 3.8, 4, 3.8, 3.5, 3.2, 3 },
		{ 1, 3.2, 3.5, 3.8, 4, 4.2, 4, 3.8, 3.5, 3.2 },
		{ 1, 3.5, 3.8, 4, 4.2, 4.5, 4.2, 4, 3.8, 3.5 }
	};
	int rows = 10, cols = 10;
	//glColor3f(1.0, 0.0, 0.0);
	for (int i = 0; i < rows - 1; i++) {
		glBegin(GL_TRIANGLE_STRIP);
		for (int j = 0; j < cols - 1; j++) {
			glColor3f(1.0 / height[j][i], 1.0 / height[j][i], 1.0 / height[j][i]);
			glVertex3f(j, height[j][i], i);
			glColor3f(1.0 / height[j][i], 1.0 / height[j][i], 1.0 / height[j][i]);
			glVertex3f(j, height[j][i + 1], i + 1);
			glColor3f(1.0 / height[j][i], 1.0 / height[j][i], 1.0 / height[j][i]);
			glVertex3f(j + 1, height[j + 1][i], i);
		}
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
		for (int j = 0; j < cols - 1; j++) {
			glColor3f(1.0 / height[j][i], 1.0 / height[j][i], 1.0 / height[j][i]);
			glVertex3f(j + 1, height[j + 1][i], i);
			glColor3f(1.0 / height[j][i], 1.0 / height[j][i], 1.0 / height[j][i]);
			glVertex3f(j + 1, height[j + 1][i + 1], i + 1);
			glColor3f(1.0 / height[j][i], 1.0 / height[j][i], 1.0 / height[j][i]);
			glVertex3f(j, height[j][i + 1], i + 1);
		}
		glEnd();
	}
}

void cornerhills2() {
	GLfloat height[10][10] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1.5, 2, 2, 2, 2, 2, 1.5, 1, 1},
	{1, 2, 2.5, 3, 3, 3, 2.5, 2, 1, 1},
	{1, 2, 3, 3.5, 4, 3.5, 3, 2, 1, 1},
	{1, 2, 3, 4, 4, 4, 3, 2, 1, 1},
	{1, 2, 3, 3.5, 4, 3.5, 3, 2, 1, 1},
	{1, 2, 2.5, 3, 3, 3, 2.5, 2, 1, 1},
	{1, 1.5, 2, 2, 2, 2, 2, 1.5, 1, 1},
	{1, 1.5, 2, 2, 2, 2, 2, 1.5, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	int rows = 10, cols = 10;
	//glColor3f(1.0, 0.0, 0.0);
	for (int i = 0; i < rows - 1; i++) {
		glBegin(GL_TRIANGLE_STRIP);
		for (int j = 0; j < cols - 1; j++) {
			glColor3f(1.0 / height[j][i], 1.0 / height[j][i], 1.0 / height[j][i]);
			glVertex3f(j, height[j][i], i);
			glColor3f(1.0 / height[j][i], 1.0 / height[j][i], 1.0 / height[j][i]);
			glVertex3f(j, height[j][i + 1], i + 1);
			glColor3f(1.0 / height[j][i], 1.0 / height[j][i], 1.0 / height[j][i]);
			glVertex3f(j + 1, height[j + 1][i], i);
		}
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
		for (int j = 0; j < cols - 1; j++) {
			glColor3f(1.0 / height[j][i], 1.0 / height[j][i], 1.0 / height[j][i]);
			glVertex3f(j + 1, height[j + 1][i], i);
			glColor3f(1.0 / height[j][i], 1.0 / height[j][i], 1.0 / height[j][i]);
			glVertex3f(j + 1, height[j + 1][i + 1], i + 1);
			glColor3f(1.0 / height[j][i], 1.0 / height[j][i], 1.0 / height[j][i]);
			glVertex3f(j, height[j][i + 1], i + 1);
		}
		glEnd();
	}
}

void terrain() {

	GLfloat height[10][20] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1.5, 2, 2.5, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2.5, 2, 1.5, 1, 1},
	{1, 1.5, 2, 2.5, 3, 3.5, 4, 4, 4, 4, 4, 4, 4, 4, 3.5, 3, 2.5, 2, 1.5, 1},
	{1, 2, 2.5, 3, 3.5, 4, 4.5, 5, 5, 5, 5, 5, 5, 4.5, 4, 3.5, 3, 2.5, 2, 1},
	{1, 2, 3, 3.5, 4, 4.5, 5, 5.5, 6, 6, 6, 6, 5.5, 5, 4.5, 4, 3.5, 3, 2, 1},
	{1, 2, 3, 4, 4.5, 5, 5.5, 6, 6.5, 6.5, 6.5, 6, 5.5, 5, 4.5, 4, 3, 2, 1, 1},
	{1, 2, 3, 3.5, 4, 4.5, 5, 5.5, 6, 6, 6, 5.5, 5, 4.5, 4, 3.5, 3, 2, 1.5, 1},
	{1, 2, 3, 4, 4.5, 5, 5.5, 6, 6, 6, 6, 5.5, 5, 4.5, 4, 3.5, 3, 2, 1.5, 1},
	{1, 2, 3, 3.5, 4, 4.5, 5, 5.5, 6, 6, 6, 6, 5.5, 5, 4.5, 4, 3, 2, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

	int rows = 20, cols = 10;
	for (int i = 0; i < rows - 1; i++) {
		glBegin(GL_TRIANGLE_STRIP);
		for (int j = 0; j < cols - 1; j++) {
			glColor3f(1.0 / height[j][i], 1.0 / height[j][i], 1.0 / height[j][i]);
			glVertex3f(j, height[j][i], i);
			glColor3f(1.0 / height[j][i], 1.0 / height[j][i], 1.0 / height[j][i]);
			glVertex3f(j, height[j][i + 1], i + 1);
			glColor3f(1.0 / height[j][i], 1.0 / height[j][i], 1.0 / height[j][i]);
			glVertex3f(j + 1, height[j + 1][i], i);
		}
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
		for (int j = 0; j < cols - 1; j++) {
			glColor3f(1.0 / height[j][i], 1.0 / height[j][i], 1.0 / height[j][i]);
			glVertex3f(j + 1, height[j + 1][i], i);
			glColor3f(1.0 / height[j][i], 1.0 / height[j][i], 1.0 / height[j][i]);
			glVertex3f(j + 1, height[j + 1][i + 1], i + 1);
			glColor3f(1.0 / height[j][i], 1.0 / height[j][i], 1.0 / height[j][i]);
			glVertex3f(j, height[j][i + 1], i + 1);
		}
		glEnd();
	}
}
void pond() {
	GLfloat height[20][20] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{ 1, 0.988235, 0.976471, 0.964706, 0.952941, 0.941176, 0.929412, 0.917647, 0.905882, 0.894118, 0.882353, 0.870588, 0.858824, 0.847059, 0.835294, 0.823529, 0.811765, 0.8, 0.788235, 1 },
		{ 1, 0.776471, 0.764706, 0.752941, 0.741176, 0.729412, 0.717647, 0.705882, 0.694118, 0.682353, 0.670588, 0.658824, 0.647059, 0.635294, 0.623529, 0.611765, 0.6, 0.588235, 0.576471, 1 },
		{ 1, 0.564706, 0.552941, 0.541176, 0.529412, 0.517647, 0.505882, 0.494118, 0.482353, 0.470588, 0.458824, 0.447059, 0.435294, 0.423529, 0.411765, 0.4, 0.388235, 0.376471, 0.364706, 1 },
		{ 1, 0.352941, 0.341176, 0.329412, 0.317647, 0.305882, 0.294118, 0.282353, 0.270588, 0.258824, 0.247059, 0.235294, 0.223529, 0.211765, 0.2, 0.188235, 0.176471, 0.164706, 0.152941, 1 },
		{ 1, 0.352941, 0.341176, 0.329412, 0.317647, 0.305882, 0.294118, 0.282353, 0.270588, 0.258824, 0.247059, 0.235294, 0.223529, 0.211765, 0.2, 0.188235, 0.176471, 0.164706, 0.152941, 1 },
		{ 1, 0.141176, 0.129412, 0.117647, 0.105882, 0.0941176, 0.0823529, 0.0705882, 0.0588235, 0.0470588, 0.0352941, 0.0235294, 0.0117647, 0, 0.0117647, 0.0235294, 0.0352941, 0.0470588, 0.0588235, 1 },
		{ 1, 0.0705882, 0.0588235, 0.0470588, 0.0352941, 0.0235294, 0.0117647, 0, 0.0117647, 0.0235294, 0.0352941, 0.0470588, 0.0588235, 0.0705882, 0.0823529, 0.0941176, 0.105882, 0.117647, 0.129412, 1 },
		{ 1, 0.0705882, 0.0588235, 0.0470588, 0.0352941, 0.0235294, 0.0117647, 0, 0.0117647, 0.0235294, 0.0352941, 0.0470588, 0.0588235, 0.0705882, 0.0823529, 0.0941176, 0.105882, 0.117647, 0.129412, 1 },
		{ 1, 0.223529, 0.211765, 0.2, 0.188235, 0.176471, 0.164706, 0.152941, 0.141176, 0.129412, 0.117647, 0.105882, 0.0941176, 0.0823529, 0.0705882, 0.0588235, 0.0470588, 0.0352941, 0.0235294, 1 },
		{ 1, 0.223529, 0.211765, 0.2, 0.188235, 0.176471, 0.164706, 0.152941, 0.141176, 0.129412, 0.117647, 0.105882, 0.0941176, 0.0823529, 0.0705882, 0.0588235, 0.0470588, 0.0352941, 0.0235294, 1 },
		{ 1, 0.376471, 0.364706, 0.352941, 0.341176, 0.329412, 0.317647, 0.305882, 0.294118, 0.282353, 0.270588, 0.258824, 0.247059, 0.235294, 0.223529, 0.211765, 0.2, 0.188235, 0.176471, 1 },
		{ 1, 0.376471, 0.364706, 0.352941, 0.341176, 0.329412, 0.317647, 0.305882, 0.294118, 0.282353, 0.270588, 0.258824, 0.247059, 0.235294, 0.223529, 0.211765, 0.2, 0.188235, 0.176471, 1 },
		{ 1, 0.529412, 0.517647, 0.505882, 0.494118, 0.482353, 0.470588, 0.458824, 0.447059, 0.435294, 0.423529, 0.411765, 0.4, 0.388235, 0.376471, 0.364706, 0.352941, 0.341176, 0.329412, 1 },
		{ 1, 0.529412, 0.517647, 0.505882, 0.494118, 0.482353, 0.470588, 0.458824, 0.447059, 0.435294, 0.423529, 0.411765, 0.4, 0.388235, 0.376471, 0.364706, 0.352941, 0.341176, 0.329412, 1 },
		{ 1, 0.682353, 0.670588, 0.658824, 0.647059, 0.635294, 0.623529, 0.611765, 0.6, 0.588235, 0.576471, 0.564706, 0.552941, 0.541176, 0.529412, 0.517647, 0.505882, 0.494118, 0.482353, 1 },
		{ 1, 0.835294, 0.823529, 0.811765, 0.8, 0.788235, 0.776471, 0.764706, 0.752941, 0.741176, 0.729412, 0.717647, 0.705882, 0.694118, 0.682353, 0.670588, 0.658824, 0.647059, 0.635294, 1 },
		{ 1, 0.835294, 0.823529, 0.811765, 0.8, 0.788235, 0.776471, 0.764706, 0.752941, 0.741176, 0.729412, 0.717647, 0.705882, 0.694118, 0.682353, 0.670588, 0.658824, 0.647059, 0.635294, 1 },
		{ 1, 0.988235, 0.976471, 0.964706, 0.952941, 0.941176, 0.929412, 0.917647, 0.905882, 0.894118, 0.882353, 0.870588, 0.858824, 0.847059, 0.835294, 0.823529, 0.811765, 0.8, 0.788235, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
	};

	int rows = 20, cols = 20;
	//glColor3f(1.0, 0.0, 0.0);
	for (int i = 0; i < rows - 1; i++) {
		glBegin(GL_TRIANGLE_STRIP);
		for (int j = 0; j < cols - 1; j++) {
			glColor3f(1.0 / height[j][i], 1.0 / height[j][i], 1.0 / height[j][i]);
			glVertex3f(j, height[j][i], i);
			glColor3f(1.0 / height[j][i + 1], 1.0 / height[j][i + 1], 1.0 / height[j][i + 1]);
			glVertex3f(j, height[j][i + 1], i + 1);
			glColor3f(1.0 / height[j + 1][i], 1.0 / height[j + 1][i], 1.0 / height[j + 1][i]);
			glVertex3f(j + 1, height[j + 1][i], i);
		}
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
		for (int j = 0; j < cols - 1; j++) {
			glColor3f(1.0 / height[j][i], 1.0 / height[j][i], 1.0 / height[j][i]);
			glVertex3f(j + 1, height[j + 1][i], i);
			glColor3f(1.0 / height[j][i], 1.0 / height[j][i], 1.0 / height[j][i]);
			glVertex3f(j + 1, height[j + 1][i + 1], i + 1);
			glColor3f(1.0 / height[j][i], 1.0 / height[j][i], 1.0 / height[j][i]);
			glVertex3f(j, height[j][i + 1], i + 1);
		}
		glEnd();
	}
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
	GLfloat fractionalrotate = 0.0;

	for (int i = 0; i < 10; i++) {
		glPushMatrix();
		x = 1 * cos(angle);
		z = 1 * sin(angle);
		glTranslatef(x, y, z);
		glRotatef(90 + fractionalrotate, 0.0, 1.0, 0.0);
		glRotatef(90, 1.0, 0.0, 0.0);
		leafs();
		glPopMatrix();
		angle += PI * 2 / 10;
		fractionalrotate += 40;
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
void fullterrain() {
	glPushMatrix();
	glTranslatef(-15.0, 0.0, 13.0);
	glRotatef(180, 0.0, 1.0, 0.0);
	glTranslatef(-5.0, 0.0, -5.0);
	cornerhills2();//bottom left
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(9.0, 0.0, -19.0);
	cornerhills2();//top right 
	glPopMatrix();
	 
	 glPushMatrix();
	glTranslatef(9.0, 0.0, 9.0);
	cornerhills1();//bottom right 
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-15.0, 0.0, -15.0);
	glRotatef(180, 0.0, 1.0, 0.0);
	glTranslatef(-5.0, 0.0, -5.0);
	cornerhills1();//top left 
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-10.0, 0.0, -10.0);
	pond();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, 13.0);
	glRotatef(-90, 0.0, 1.0, 0.0);
	glTranslatef(-4.0, 0.0, -9.0);
	terrain();//bottom
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.0, 0.0, -14.0);
	glRotatef(90, 0.0, 1.0, 0.0);
	glTranslatef(-4.0, 0.0, -9.0);
	terrain();//top
	glPopMatrix();

	glPushMatrix();
	glTranslatef(9.0, 0.0, -10.0);
	terrain();//right
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-19.0, 0.0, -10.0);
	terrain();//left
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

	fullterrain();
	
	
	
	
	//glPushMatrix();
	//glScalef(10, 10, 10);
	//leafsOnBranch();
	////glPopMatrix();

	//tree();
	glPopMatrix();
	glutSwapBuffers();
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
	MyInit();
	glutMainLoop();
	return 0;
}
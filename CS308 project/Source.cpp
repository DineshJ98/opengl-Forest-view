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

void terrain() {
	/*GLfloat heigth[11][11] = { {0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,1,2,3,2,1,0,0,0},
								{0,0,0,2,3,4,3,2,0,0,0},
								{0,0,0,3,4,5,4,3,0,0,0},
								{0,0,0,2,3,4,3,2,0,0,0},
								{0,0,0,1,2,3,2,1,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0,0,0}
	};*/

	GLfloat height[21][21] = {
		{0.680, 1.084, 1.306, 1.828, 1.616, 0.535, 0.170, 1.551, 1.074, 1.328, 0.266, 1.485, 1.942, 0.158, 0.775, 1.246, 0.548, 0.600, 0.176, 0.071, 1.612},
		{0.211, 1.330, 1.990, 1.364, 1.257, 0.671, 1.963, 0.535, 0.197, 1.401, 1.755, 1.014, 0.808, 1.385, 1.086, 0.452, 0.206, 1.783, 1.472, 1.267, 1.977},
		{1.389, 1.676, 0.169, 0.209, 0.751, 1.271, 0.068, 0.023, 0.743, 0.422, 1.072, 1.290, 1.936, 0.430, 0.034, 1.090, 0.946, 0.400, 0.413, 1.439, 0.043 },
		{0.639, 0.977, 1.025, 0.389, 0.464, 1.075, 0.919, 1.598, 0.242, 0.936, 0.028, 1.018, 1.389, 1.845, 1.324, 0.303, 0.380, 0.103, 0.621, 0.058, 1.320},
		{0.749, 1.137, 1.812, 0.794, 1.321, 1.704, 1.908, 1.228, 0.190, 1.261, 0.847, 0.981, 1.924, 0.079, 0.363, 0.308, 0.585, 1.900, 1.047, 1.630, 0.411},
		{1.932, 0.132, 1.100, 1.652, 0.570, 1.833, 1.352, 1.625, 0.109, 1.263, 1.478, 0.991, 0.981, 1.163, 1.369, 0.368, 0.136, 0.290, 0.535, 1.266, 1.073},
		{1.883, 0.524, 0.487, 0.237, 1.579, 0.671, 0.943, 1.636, 1.809, 0.152, 0.399, 0.487, 0.062, 0.074, 0.292, 0.692, 1.162, 0.929, 0.214, 0.932, 1.045},
		{1.953, 1.078, 0.741, 1.676, 0.299, 1.686, 1.639, 1.413, 0.349, 1.409, 0.365, 0.408, 0.339, 1.927, 0.140, 0.961, 1.227, 0.451, 1.361, 0.074, 1.781},
		{1.604, 1.150, 1.578, 1.834, 1.477, 0.981, 1.080, 0.373, 1.839, 1.477, 0.057, 1.986, 0.600, 1.295, 0.216, 1.043, 0.422, 1.666, 1.243, 0.231, 0.981},
		{0.736, 1.764, 0.587, 0.788, 1.972, 1.001, 1.535, 0.998, 0.388, 1.198, 1.525, 1.313, 1.717, 0.947, 0.394, 1.300, 1.606, 0.107, 1.854, 0.074, 1.680},
		{1.198, 1.265, 0.520, 0.015, 0.442, 0.800, 0.162, 1.472, 1.689, 0.451, 1.328, 1.635, 0.074, 1.994, 0.007, 1.680, 0.385, 1.334, 0.503, 1.408, 1.983},
		{1.500, 0.524, 1.918, 0.006, 0.098, 0.378, 1.143, 1.279, 0.669, 1.901, 0.086, 0.419, 0.485, 0.888, 1.317, 0.848, 0.154, 0.647, 1.695, 0.058, 1.153},
		{0.377, 0.697, 0.271, 0.989, 1.272, 0.582, 0.633, 1.448, 1.832, 1.045, 0.266, 0.353, 0.119, 1.046, 0.462, 1.653, 0.189, 0.254, 1.091, 0.598, 0.167},
		{0.939, 1.999, 1.077, 0.588, 1.229, 0.468, 0.437, 0.704, 0.803, 0.710, 1.660, 1.672, 0.823, 0.897, 0.465, 1.760, 0.648, 1.704, 1.630, 0.707, 1.400},
		{2.580, 2.112, 2.464, 2.306, 2.921, 2.665, 2.242, 2.987, 2.089, 2.786, 2.721, 2.257, 2.594, 2.893, 2.412, 2.470, 2.808, 2.443, 2.856, 2.170, 2.947},
		{2.194, 2.333, 2.028, 2.655, 2.240, 2.646, 2.899, 2.166, 2.695, 2.227, 2.013, 2.741, 2.283, 2.338, 2.202, 2.952, 2.451, 2.109, 2.276, 2.026, 2.849},
		{2.948, 2.354, 2.244, 2.365, 2.684, 2.587, 2.464, 2.612, 2.146, 2.111, 2.246, 2.596, 2.648, 2.278, 2.027, 2.431, 2.755, 2.557, 2.544, 2.028, 2.125},
		{2.063, 2.744, 2.422, 2.337, 2.617, 2.294, 2.468, 2.614, 2.312, 2.076, 2.985, 2.478, 2.628, 2.977, 2.752, 2.076, 2.080, 2.194, 2.986, 2.189, 2.529},
		{2.430, 2.540, 2.703, 2.706, 2.954, 2.742, 2.297, 2.021, 2.857, 2.453, 2.997, 2.150, 2.328, 2.207, 2.052, 2.305, 2.590, 2.618, 2.232, 2.883, 2.523},
		{2.246, 2.385, 2.208, 2.429, 2.857, 2.660, 2.678, 2.982, 2.149, 2.512, 2.205, 2.056, 2.535, 2.576, 2.582, 2.844, 2.437, 2.736, 2.349, 2.825, 2.073},
		{2.009, 2.319, 2.463, 2.685, 2.742, 2.542, 2.358, 2.368, 2.390, 2.916, 2.661, 2.043, 2.430, 2.271, 2.265, 2.024, 2.310, 2.164, 2.670, 2.228, 2.890}
	};

	int rows = 21, cols = 21;
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

	for (int i = 0; i < 10; i++) {
		glPushMatrix();
		x = 1 * cos(angle);
		z = 1 * sin(angle);
		glTranslatef(x, y, z);
		glRotatef(angle - 90, 0.0, 1.0, 0.0);
		glRotatef(90, 1.0, 0.0, 0.0);
		leafs();
		glPopMatrix();
		angle += PI * 2 / 10;
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


void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	gluLookAt(0.0 + camX, 3.0 + camY, 10.0 + camZ, 0, 0, 0, 0, 1, 0);
	glRotatef(objRY, 0.0, 1.0, 0.0);

	axis();
	glColor3f(1.0, 1.0, 1.0);
	grid();

	glPushMatrix();
	glTranslatef(-10.0, 0.0, -10.0);
	terrain();
	glPopMatrix();

	//glPushMatrix();
	//glScalef(10, 10, 10);
	//leafsOnBranch();
	////glPopMatrix();

	//tree();
	glPopMatrix();
	glutSwapBuffers();
}

void reshape(GLsizei w,GLsizei h) {
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

int main(int arcc ,char** arcv) {
	
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
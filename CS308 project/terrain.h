#include<GL/glut.h>
#include<math.h>


GLfloat soilcolor[] = { 0.2745,0.1803,0.1019,1.0 };
GLfloat soilDeffu[] = { 0.2,0.2,0.2,1.0 };
GLfloat soilgrasscolor[] = { 0.4862 ,0.9882 ,0.0,1.0 };



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
			glTexCoord2f(0.0, 0.0);
			glVertex3f(j, height[j][i], i);
			glTexCoord2f(0.0, 1.0);
			glVertex3f(j, height[j][i + 1], i + 1);
			glTexCoord2f(1.0, 0.0);
			glVertex3f(j + 1, height[j + 1][i], i);
		}
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
		for (int j = 0; j < cols - 1; j++) {
			glTexCoord2f(1.0, 0.0);
			glVertex3f(j + 1, height[j + 1][i], i);
			glTexCoord2f(1.0, 1.0);
			glVertex3f(j + 1, height[j + 1][i + 1], i + 1);
			glTexCoord2f(0.0, 1.0);
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
			glTexCoord2f(0.0, 0.0);
			glVertex3f(j, height[j][i], i);
			glTexCoord2f(0.0, 1.0);
			glVertex3f(j, height[j][i + 1], i + 1);
			glTexCoord2f(1.0, 0.0);
			glVertex3f(j + 1, height[j + 1][i], i);
		}
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
		for (int j = 0; j < cols - 1; j++) {
			glTexCoord2f(1.0, 0.0);
			glVertex3f(j + 1, height[j + 1][i], i);
			glTexCoord2f(1.0, 1.0);
			glVertex3f(j + 1, height[j + 1][i + 1], i + 1);
			glTexCoord2f(0.0, 1.0);
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
			glTexCoord2f(0.0, 0.0);
			glVertex3f(j, height[j][i], i);
			glTexCoord2f(0.0, 1.0);
			glVertex3f(j, height[j][i + 1], i + 1);
			glTexCoord2f(1.0, 0.0);
			glVertex3f(j + 1, height[j + 1][i], i);
		}
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
		for (int j = 0; j < cols - 1; j++) {
			glTexCoord2f(1.0, 0.0);
			glVertex3f(j + 1, height[j + 1][i], i);
			glTexCoord2f(1.0, 1.0);
			glVertex3f(j + 1, height[j + 1][i + 1], i + 1);
			glTexCoord2f(0.0, 1.0);
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
			glVertex3f(j, height[j][i], i);
			glVertex3f(j, height[j][i + 1], i + 1);
			glVertex3f(j + 1, height[j + 1][i], i);
		}
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
		for (int j = 0; j < cols - 1; j++) {
			glVertex3f(j + 1, height[j + 1][i], i);
			glVertex3f(j + 1, height[j + 1][i + 1], i + 1);
			glVertex3f(j, height[j][i + 1], i + 1);
		}
		glEnd();
	}
}

void fullterrain(GLfloat textureId) {
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_TEXTURE_2D);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glBindTexture(GL_TEXTURE_2D, textureId);

	glMaterialfv(GL_FRONT, GL_AMBIENT, soilgrasscolor);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, soilDeffu);
	glMaterialfv(GL_FRONT, GL_SPECULAR, soilgrasscolor);
	glMaterialf(GL_FRONT, GL_SHININESS, 10);

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
	glDisable(GL_TEXTURE_2D);

	glMaterialfv(GL_FRONT, GL_AMBIENT, soilcolor);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, soilDeffu);
	glMaterialfv(GL_FRONT, GL_SPECULAR, soilcolor);
	glMaterialf(GL_FRONT, GL_SHININESS, 10);

	glPushMatrix();
	glTranslatef(-10.0, 0.0, -10.0);
	pond();
	glPopMatrix();

	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHT1);
}

#include<GL/glut.h>

GLfloat skycolor[] = { 0.5294,0.8078,0.9216,1.0 };

void sky(GLfloat textureId) {
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_TEXTURE_2D);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glBindTexture(GL_TEXTURE_2D, textureId);

	glMaterialfv(GL_FRONT, GL_AMBIENT, skycolor);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, skycolor);
	glMaterialfv(GL_FRONT, GL_SPECULAR, skycolor);
	glMaterialf(GL_FRONT, GL_SHININESS, 80);

	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-19.0, 0.0, -19.0);//back
	glTexCoord2f(1.0, 0.0);
	glVertex3f(18.0, 0.0, -19.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(18.0, 25.0, -19.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-19.0, 25.0, -19.0);
	
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-19.0, 0.0, -19.0);//left
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-19.0, 25.0, -19.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-19.0, 25.0, 18.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(-19.0, 0.0, 18.0);
	
	glTexCoord2f(1.0, 0.0);
	glVertex3f(18.0, 0.0, -19.0);//right
	glTexCoord2f(1.0, 1.0);
	glVertex3f(18.0, 25.0, -19.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(18.0, 25.0, 18.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(18.0, 0.0, 18.0);
	
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-19.0, 0.0, 18.0);//front
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-19.0, 25.0, 18.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(18.0, 25.0, 18.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(18.0, 0.0, 18.0);
	
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-19.0, 25.0, -19.0);//top
	glTexCoord2f(1.0, 0.0);
	glVertex3f(18.0, 25.0, -19.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(18.0, 25.0, 18.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-19.0, 25.0, 18.0);

	glEnd();

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT1);
	glDisable(GL_LIGHT0);
}
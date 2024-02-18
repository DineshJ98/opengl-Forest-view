
GLfloat PIvalue = 3.141592653589;
GLfloat waterlilyleaf[] = { 0.451,0.4745,0.2313,1.0 };
GLfloat waterlilydiff[] = { 0.3,0.3,0.3,1.0 };
GLfloat waterlilyflowercolor[] = { 0.9686,0.8745,0.8902,1.0 };
 
void leafcircle() {
	GLfloat angle = 0.0;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 180; i++) {
		GLfloat x = 1.0 * cos(angle);
		GLfloat z = 1.0 * sin(angle);
		glVertex3f(x, 0.0, z);
		angle += 2 * PIvalue / 180;
	}
	glEnd();
}

void waterlily() {
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);

	glMaterialfv(GL_FRONT, GL_AMBIENT, waterlilyleaf);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, waterlilydiff);
	glMaterialfv(GL_FRONT, GL_SPECULAR, waterlilyleaf);
	glMaterialf(GL_FRONT, GL_SHININESS, 100);

	//gluSphere(gluNewQuadric(), 1.0, 50, 50);
	leafcircle();

	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT1);
	glDisable(GL_LIGHT0);
}

void waterlilyflower(GLfloat x, GLfloat y, GLfloat z, GLfloat textureid1 ,GLfloat textureid2) {
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_TEXTURE_2D);

	GLUquadric* quad1 = gluNewQuadric();
	gluQuadricTexture(quad1, GL_TRUE);
	glBindTexture(GL_TEXTURE_2D, textureid1);

	glMaterialfv(GL_FRONT, GL_AMBIENT, waterlilyflowercolor);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, waterlilydiff);
	glMaterialfv(GL_FRONT, GL_SPECULAR, waterlilyflowercolor);
	glMaterialf(GL_FRONT, GL_SHININESS, 100);

	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(1.0, 0.8, 1.0);
	glRotatef(-90, 1.0, 0.0, 0.0);
	gluCylinder(quad1, 0.3, 0.0, 0.6, 50, 50);
	glPopMatrix();

	GLUquadric* quad2 = gluNewQuadric();
	gluQuadricTexture(quad2, GL_TRUE);
	glBindTexture(GL_TEXTURE_2D, textureid2);

	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(90, 1.0, 0.0, 0.0);
	gluCylinder(quad2, 0.3, 0.0, 0.3, 50, 50);
	glPopMatrix();

	glMaterialfv(GL_FRONT, GL_AMBIENT, waterlilyleaf);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, waterlilydiff);
	glMaterialfv(GL_FRONT, GL_SPECULAR, waterlilyleaf);
	glMaterialf(GL_FRONT, GL_SHININESS, 100);

	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(90, 1.0, 0.0, 0.0);
	gluCylinder(gluNewQuadric(), 0.05, 0.05, 3.0, 50, 50);
	glPopMatrix();

	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT1);
	glDisable(GL_LIGHT0);
}
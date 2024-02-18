
void rock(GLfloat textureId) {
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_TEXTURE_2D);

	GLfloat rockcolor[] = { 0.2745,0.1803,0.1019,1.0 };
	GLfloat rockDeffu[] = { 0.2,0.2,0.2,1.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, rockcolor);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, rockDeffu);
	glMaterialfv(GL_FRONT, GL_SPECULAR, rockcolor);
	glMaterialf(GL_FRONT, GL_SHININESS, 10);

	GLUquadric* quad = gluNewQuadric();
	gluQuadricTexture(quad, GL_TRUE);
	glBindTexture(GL_TEXTURE_2D, textureId);

	gluSphere(quad, 2.0, 50, 50);

	gluDeleteQuadric(quad);

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHT1);
}

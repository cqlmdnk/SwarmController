

#include "LiveScreen.h"



LiveScreen::LiveScreen(QWidget* parent) : QOpenGLWidget{ parent} {

}

void LiveScreen::initializeGL()
{
	float r = 1.0f, g = 1.0f, b = 1.0f, a = 0.0f;
	initializeOpenGLFunctions();
	glClearColor(r, g, b, a);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
}


void LiveScreen::resizeGL(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void LiveScreen::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.7f);
	glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
	double radius = 0.60;
	int i, x, y;
	double twicePi = 2.0 * 3.142;
	x = 0, y = 0;
	glVertex2f(x, y); // center of circle
	for (i = 0; i <= 20; i++) {
		glVertex2f(
			(x + (radius * cos(i * twicePi / 20))), (y + (radius * sin(i * twicePi / 20)))
		);
	}

	glEnd();
}




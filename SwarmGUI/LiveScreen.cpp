

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


	double radius = 0.02;

	double twicePi = 2.0 * 3.142;
	for (auto pos : PointsVector::nodePositions) {
		glColor3f(0.0f, 0.5f, 0.7f);
		glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
		float x = pos.x() / 50, y = pos.y() / 50;
		glVertex2f(x, y); // center of circle
		for (int i = 0; i <= 10; i++) {
			glVertex2f(
				(x + (radius * cos(i * twicePi / 10))), (y + (radius * sin(i * twicePi / 10)))
			);

		}
		glEnd();
	}

	
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);

	glVertex2f(1.0f, 0.0f);
	glVertex2f(-1.0f, 0.0f);
	glVertex2f(0.0f, -1.0f);
	glVertex2f(0.0f, 1.0f);
	glEnd();
	update();
	
	
	
	
}




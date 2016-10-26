// GuideArrow.h
// Header for guide arrow class
// 
// Chengyu Yang - 2016

#ifndef GUIDEARROW_H
#define GUIDEARROW_H

#include <stdlib.h>
#include <GL/glut.h>
#include "texturedPolygons.h"

class GuideArrow
{
public:

	GuideArrow();

	GuideArrow(GLdouble x, GLdouble y, GLdouble z);

	void setPosition(GLdouble x, GLdouble y, GLdouble z);


	GLdouble getX();

	GLdouble getY();

	GLdouble getZ();

	void display();

	static void drawArrow();

private:
	GLdouble AP_x;
	GLdouble AP_y;
	GLdouble AP_z;

};

#endif

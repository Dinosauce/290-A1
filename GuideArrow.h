// GuideArrow.h
// Header for guide arrow class
// 
// Chengyu Yang - 2016

#ifndef GUIDEARROW_H
#define GUIDEARROW_H

#include <stdlib.h>
#include <GL/glut.h>
#include "texturedPolygons.h"

/// GuideArrow: Displays hints arrow on screen
class GuideArrow
{
public:

	/// Default Constructor: Sets values to 0.
	GuideArrow();

	/// Constructor: Sets given GuideArrow coordinates and angle.
	GuideArrow(GLdouble x, GLdouble y, GLdouble z, GLdouble angle);

	/// Sets given position and angle
	void setPosition(GLdouble x, GLdouble y, GLdouble z, GLdouble angle);

	/// Displays guidearrow
	void display();

	/// Sets the verticies
	static void drawArrow();

private:
	GLdouble AP_x;
	GLdouble AP_y;
	GLdouble AP_z;
	GLdouble Angle_xz;

};

#endif

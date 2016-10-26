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
	/// Default constructor: Sets position to 0, 0, 0.
	GuideArrow();

	/// Constructor: Sets position to given values.
	GuideArrow(GLdouble x, GLdouble y, GLdouble z);

	/// Sets position to given values
	void setPosition(GLdouble x, GLdouble y, GLdouble z);

	/// Returns X position
	GLdouble getX();

	/// Returns Y position
	GLdouble getY();

	/// Returns Z position
	GLdouble getZ();

	/// Displayes the Guide Arrow
	void display();

	/// Draws the Guide Arrow
	static void drawArrow();

private:
	GLdouble AP_x;
	GLdouble AP_y;
	GLdouble AP_z;

};

#endif

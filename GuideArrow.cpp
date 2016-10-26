// GuideArrow.cpp
//
//
//
//
// Chengyu Yang - 2016

#include "GuideArrow.h"


GuideArrow::GuideArrow()
{
	setPosition(0, 0, 0);
}

GuideArrow::GuideArrow(GLdouble x, GLdouble y, GLdouble z)
{
	setPosition(x, y, z);
}

void GuideArrow::setPosition(GLdouble x, GLdouble y, GLdouble z)
{
	AP_x = x;
	AP_y = y;
	AP_z = z;
}

GLdouble GuideArrow::getX()
{
	return AP_x;
}

GLdouble GuideArrow::getY()
{
	return AP_y;
}

GLdouble GuideArrow::getZ()
{
	return AP_z;
}

void GuideArrow::drawArrow()
{
	glBegin(GL_TRIANGLES);
	glVertex3f(0, 0, 0);
	glVertex3f(40, 0, 0);
	glVertex3f(20, 0, 80);
	glEnd();
}

void GuideArrow::display()
{

	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glTranslated(AP_x, AP_y, AP_z);
	drawArrow();
	glPopMatrix();

}
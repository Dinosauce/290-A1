// TextDisplay.cpp
//
// Jayden Grant - 2016

#include "TextDisplay.h"

void TextDisplay::printToScreen(std::string text, int screenHeight, int screenWidth, int posV, int posH)
{
	glPushMatrix();
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
			glLoadIdentity();
			gluOrtho2D(0, screenWidth, 0, screenHeight);
			glScalef(1, -1, 1);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();

			glBindTexture(GL_TEXTURE_2D, 0); //Unbind texture to give text color
			glColor3d(0.2, 1.0, 0.5);

			glTranslatef(-posH, -posV, 0);
			
			glRasterPos2d(0, 0);
			for (char & c : text)
			{
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
			}

			glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}
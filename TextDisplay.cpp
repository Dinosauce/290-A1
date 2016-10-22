// TextDisplay.cpp
//
// Jayden Grant - 2016

#include "TextDisplay.h"

void TextDisplay::printToScreen(std::string text, int screenHeight, int screenWidth, int posV, int posH)
{
	//Change to 2D view model
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

			//Position Text
			glTranslatef(posH, -posV, 0);
			
			//Set Bottom Right Raster Position
			glRasterPos2d(0, 0);
			for (int i = 0; i < text.length(); i++)
			{
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
			}

			//Set view model back
			glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}
// Checkpoint.h
// Header for TextDisplay class
// Displays raster text to screen
// 
// Jayden Grant - 2016

#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <stdlib.h>
#include <GL/glut.h>
#include <string>

class TextDisplay
{
public:
	
	void printToScreen(std::string text, int screenHeight, int screenWidth, int posH, int posW);
};

#endif
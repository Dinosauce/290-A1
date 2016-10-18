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

/// TextDisplay: Used to display bitmap text to the window.
class TextDisplay
{
public:
	///Prints the given text to the display at the given screen position posV / posH (Vert / Horz)
	void printToScreen(std::string text, int screenHeight, int screenWidth, int posV, int posH);
};

#endif
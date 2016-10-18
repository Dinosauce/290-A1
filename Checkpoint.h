// Checkpoint.h
// Header for checkpoint class
// 
// Jayden Grant - 2016

#ifndef CHECKPOINT_H
#define CHECKPOINT_H

#include <stdlib.h>
#include <GL/glut.h>
#include "texturedPolygons.h"

class Checkpoint
{

public:

	/// Default constructor: Sets default coordinate values.
	Checkpoint();
	/// Constructor: Sets given coordinate values.
	Checkpoint(GLdouble x, GLdouble y, GLdouble z);

	/// Sets the x, y and z coordinates of the Checkpoint as GLdoubles.
	void setPosition(GLdouble x, GLdouble y, GLdouble z);

	/// Sets whether the checkpoint has been passed / collected.
	void setPassed(bool newPassed); 





	/// Returns whether the checkpoint has been passed / collected.
	bool isPassed();

	/// Returns X position of checkpoint as GLdouble.
	GLdouble getX();

	/// Returns Y position of checkpoint as GLdouble.
	GLdouble getY();

	/// Returns Z position of checkpoint as GLdouble.
	GLdouble getZ();

	/// Displays the checkpoint
	void display();

	/// Loads the textures needed for the Checkpoint
	static void createTextures();
	/// Creates display lists
	static void draw();
	


private:
	GLdouble m_xPos;
	GLdouble m_yPos;
	GLdouble m_zPos;

	static TexturedPolygons tp;

	bool passed = false;

};

#endif

// Potion.h
// Header for potion class
// 
// Jayden Grant - 2016

#ifndef POTION_H
#define POTION_H

#include <stdlib.h>
#include <GL/glut.h>
#include "texturedPolygons.h"

#define POTION_SPEED 0
#define POTION_SLOW 1
#define POTION_TOTEM 2

class Potion
{

public:

	/// Default constructor: Sets default coordinate values.
	Potion();
	/// Constructor: Sets given coordinate values, and potion type.
	Potion(int potionType, GLdouble x, GLdouble y, GLdouble z);

	/// Sets the x, y and z coordinates of the Potion as GLdoubles.
	void setPosition(GLdouble x, GLdouble y, GLdouble z);


	/// Returns X position of Potion as GLdouble.
	GLdouble getX();

	/// Returns Y position of Potion as GLdouble.
	GLdouble getY();

	/// Returns Z position of Potion as GLdouble.
	GLdouble getZ();

	/// Returns the potion type as int
	int getType();

	/// Displays the Potion
	void display();

	/// Loads the textures needed for the Potion
	static void createTextures();
	/// Creates display lists, using the given list nubmer and the next 2 numbers.
	static void draw(int dispListNo3);



private:
	GLdouble m_xPos;
	GLdouble m_yPos;
	GLdouble m_zPos;

	int type;

	static TexturedPolygons texpol;
	static int dispListNo;
	static int textureNo;

};

#endif
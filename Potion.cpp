// Potion.cpp
//
//
//
//
// Jayden Grant - 2016

#include "Potion.h"

TexturedPolygons Potion::texpol;
int Potion::dispListNo;

Potion::Potion()
{
	type = POTION_SPEED;
	setPosition(0, 0, 0);
}

Potion::Potion(int potionType, GLdouble x, GLdouble y, GLdouble z)
{
	if (potionType > -1 && potionType < 3)
		type = potionType;
	else
		type = POTION_SPEED;

	setPosition(x, y, z);
}

void Potion::setPosition(GLdouble x, GLdouble y, GLdouble z)
{
	m_xPos = x;
	m_yPos = y;
	m_zPos = z;
}

GLdouble Potion::getX()
{
	return m_xPos;
}

GLdouble Potion::getY()
{
	return m_yPos;
}

GLdouble Potion::getZ()
{
	return m_zPos;
}


// ------------------------------------- Load / Create Assests -------------------------------------
void Potion::createTextures()
{
	texpol.SetTextureCount(10);

	texpol.CreateTexture(9, texpol.LoadTexture("images/PotBot.raw", 64, 64), 64, 64);

	texpol.CreateTexture(0, texpol.LoadTexture("images/PotGreen.raw", 64, 94), 64, 94);
	texpol.CreateTexture(3, texpol.LoadTexture("images/PotGreenX.raw", 94, 64), 94, 64);
	texpol.CreateTexture(6, texpol.LoadTexture("images/PotGreenTop.raw", 64, 64), 64, 64);

	texpol.CreateTexture(1, texpol.LoadTexture("images/PotPurple.raw", 64, 94), 64, 94);
	texpol.CreateTexture(4, texpol.LoadTexture("images/PotPurpleX.raw", 94, 64), 94, 64);
	texpol.CreateTexture(7, texpol.LoadTexture("images/PotPurpleTop.raw", 64, 64), 64, 64);

	texpol.CreateTexture(2, texpol.LoadTexture("images/Owl.raw", 64, 94), 64, 94);
	texpol.CreateTexture(5, texpol.LoadTexture("images/OwlX.raw", 94, 64), 94, 64);
	texpol.CreateTexture(8, texpol.LoadTexture("images/OwlTop.raw", 64, 64), 64, 64);
}

void Potion::draw(int dispListNo3)
{
	dispListNo = dispListNo3;
	texpol.CreateDisplayList(0, dispListNo, 64, 94, -32.0, 0.0, -32.0, 1.0, 1.0); //XY Pot
	texpol.CreateDisplayList(2, dispListNo + 1, 94, 64, -32.0, 0.0, -32.0, 1.0, 1.0); //YZ Pot X

	texpol.CreateDisplayList(1, dispListNo + 2, 64, 64, -32.0, 0.0, -32.0, 1.0, 1.0); //XY Top/Bottom
}

void Potion::display()
{
	glBindTexture(GL_TEXTURE_2D, texpol.GetTexture(type));//Pot
	glPushMatrix();
		glTranslated(m_xPos, m_yPos + 100, m_zPos);
		glCallList(dispListNo);
	glPopMatrix();
	glPushMatrix();
		glTranslated(m_xPos, m_yPos + 100, m_zPos + 64);
		glCallList(dispListNo);
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, texpol.GetTexture(type + 3));//Pot X
	glPushMatrix();
		glTranslated(m_xPos, m_yPos + 100, m_zPos);
		glCallList(dispListNo + 1);
	glPopMatrix();
	glPushMatrix();
		glTranslated(m_xPos + 64, m_yPos + 100, m_zPos);
		glCallList(dispListNo + 1);
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, texpol.GetTexture(type + 6));//Pot Top
	glPushMatrix();
	glTranslated(m_xPos, m_yPos + 194, m_zPos);
	glCallList(dispListNo + 2);
	glPopMatrix();


	glBindTexture(GL_TEXTURE_2D, texpol.GetTexture(0));//Bottom
	glPushMatrix();
	glTranslated(m_xPos, m_yPos + 100, m_zPos);
	glCallList(dispListNo + 2);
	glPopMatrix();
}




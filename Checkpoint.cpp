// Checkpoint.cpp
//
//
//
//
// Jayden Grant - 2016

#include "Checkpoint.h"

TexturedPolygons Checkpoint::tp;
int Checkpoint::dispListNo;

Checkpoint::Checkpoint()
{
	passed = false;
	setPosition(0, 0, 0);
}

Checkpoint::Checkpoint(GLdouble x, GLdouble y, GLdouble z)
{
	passed = false;
	setPosition(x, y, z);
}

void Checkpoint::setPosition(GLdouble x, GLdouble y, GLdouble z)
{
	m_xPos = x;
	m_yPos = y;
	m_zPos = z;
}

void Checkpoint::setPassed(bool newPassed)
{ 
	passed = newPassed;
}

bool Checkpoint::isPassed()
{ 
	return passed; 
}

GLdouble Checkpoint::getX()
{
	return m_xPos;
}

GLdouble Checkpoint::getY()
{
	return m_yPos;
}

GLdouble Checkpoint::getZ()
{
	return m_zPos;
}


// ------------------------------------- Load / Create Assests -------------------------------------
void Checkpoint::createTextures()
{
	tp.SetTextureCount(7);

	tp.CreateTexture(1, tp.LoadTexture("images/FlagPole.raw", 16, 16), 16, 16);
	tp.CreateTexture(2, tp.LoadTexture("images/FlagPoleX.raw", 16, 16), 16, 16);

	tp.CreateTexture(3, tp.LoadTexture("images/Flag.raw", 384, 94), 384, 94);
	tp.CreateTexture(5, tp.LoadTexture("images/FlagX.raw", 94, 384), 94, 384);

	tp.CreateTexture(4, tp.LoadTexture("images/FlagPassed.raw", 384, 94), 384, 94);
	tp.CreateTexture(6, tp.LoadTexture("images/FlagPassedX.raw", 94, 384), 94, 384);
}

void Checkpoint::draw(int dispListNo4)
{
	dispListNo = dispListNo4;
	tp.CreateDisplayList(0, dispListNo, 16, 16, 0.0, 0.0, 0.0, 1.0, 50.0); //XY Pole
	tp.CreateDisplayList(2, dispListNo+1, 16, 16, 0.0, 0.0, 0.0, 50.0, 1.0); //YZ Pole X

	tp.CreateDisplayList(0, dispListNo+2, 384, 94, 0.0, 0.0, 0.0, 1.0, 1.0); //XY Flag
	tp.CreateDisplayList(2, dispListNo+3, 94, 384, 0.0, 0.0, 0.0, 1.0, 1.0); //YZ Flag X
}

void Checkpoint::display()
{
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(1));//Pole
	glPushMatrix();
		glTranslated(m_xPos, m_yPos, m_zPos);
		glCallList(dispListNo);
	glPopMatrix();
	glPushMatrix();
		glTranslated(m_xPos, m_yPos, m_zPos + 16);
		glCallList(dispListNo);
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(2));//Pole X
	glPushMatrix();
		glTranslated(m_xPos, m_yPos, m_zPos);
		glCallList(dispListNo + 1);
	glPopMatrix();
	glPushMatrix();
		glTranslated(m_xPos + 16, m_yPos, m_zPos);
		glCallList(dispListNo + 1);
	glPopMatrix();

	int flagTex = 3;
	if (passed)
		flagTex++;

	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(flagTex));//Flag 
	glPushMatrix();
		glTranslated(m_xPos - 184, m_yPos + 706, m_zPos + 8);
		glCallList(dispListNo + 2);
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(flagTex + 2));//Flag X
	glPushMatrix();
		glTranslated(m_xPos + 8, m_yPos + 706, m_zPos - 184);
		glCallList(dispListNo + 3);
	glPopMatrix();

}




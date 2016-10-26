// CheckpointList.cpp
//	Implementation for checkpoint list class
//
// Jayden Grant - 2016

#include "CheckpointList.h"

CheckpointList::CheckpointList()
{
	noPassed = 0;
	length = 0;
}

CheckpointList::CheckpointList(int newLength)
{
	noPassed = 0;
	SetLength(newLength);
}

void CheckpointList::SetLength(int newLength)
{
	if (length == 0)
	{
		checkpoints = new Checkpoint[newLength];
	}
	else
	{
		Checkpoint * temp = checkpoints;
		checkpoints = new Checkpoint[newLength];

		for (int i = 0; i < length; i++)
		{
			checkpoints[i] = temp[i];
		}
	}

	length = newLength;
}

void CheckpointList::Set(int index, GLdouble x, GLdouble y, GLdouble z)
{
	checkpoints[index].setPosition(x, y, z);
}

void CheckpointList::callDisplay()
{
	for (int i = 0; i < length; i++)
	{
		checkpoints[i].display();
	}
}

int CheckpointList::checkPassed(GLdouble x, GLdouble z)
{
	int passed = 0;
	int cx, cz;
	for (int i = 0; i < length; i++)
	{
		if (!checkpoints[i].isPassed())
		{
			cx = checkpoints[i].getX();
			cz = checkpoints[i].getZ();

			if (getDistance(cx, cz, x, z) < 1000.0)
			{
				checkpoints[i].setPassed(true);
				noPassed++;
				passed++;
			}
		}
	}

	return passed;
}

GLdouble CheckpointList::getDistance(GLdouble x1, GLdouble z1, GLdouble x2, GLdouble z2)
{
	return sqrt(pow((x2 - x1), 2) + pow((z2 - z1), 2));
}

Checkpoint & CheckpointList::Get(int index) const
{
	return checkpoints[index];
}
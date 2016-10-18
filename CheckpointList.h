// CheckpointList.h
//	Header for checkpoint list class
//
// Jayden Grant - 2016

#ifndef CHECKPOINTLIST_H
#define CHECKPOINTLIST_H

#include "Checkpoint.h"
#include <cmath>

class CheckpointList
{
public:
	CheckpointList();
	CheckpointList(int length);

	void SetLength(int length);

	void Set(int index, GLdouble x, GLdouble y, GLdouble z);

	void callDisplay();

	void checkPassed(GLdouble x, GLdouble z);

	int getNoPassed() { return noPassed; };

	const Checkpoint & Get(int index) const;


private:

	GLdouble getDistance(GLdouble x1, GLdouble z1, GLdouble x2, GLdouble z2);

	Checkpoint * checkpoints;
	int length = 0;

	int noPassed = 0;

};

#endif
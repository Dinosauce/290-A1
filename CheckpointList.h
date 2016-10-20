// CheckpointList.h
//	Header for checkpoint list class
//
// Jayden Grant - 2016

#ifndef CHECKPOINTLIST_H
#define CHECKPOINTLIST_H

#include "Checkpoint.h"
#include <cmath>

/// CheckpointList: Handles a list of checkpoints
class CheckpointList
{
public:
	///Default constructor: sets default values (0 length list)
	CheckpointList();
	///Constructor: Sets list lenght to given value
	CheckpointList(int length);

	/// Sets the lenght of the list to given value
	void SetLength(int length);

	/// Sets to coordinates of specified checkpoint.
	void Set(int index, GLdouble x, GLdouble y, GLdouble z);

	/// calls the display function of all checkpoints in the list.
	void callDisplay();

	/// Compares given position to checkpoints and sets checkpoints as passed if in range.
	void checkPassed(GLdouble x, GLdouble z);

	/// Returns the number of checkpoints which the player has already passed.
	int getNoPassed() { return noPassed; };

	/// Returns constant referance to specified checkpoint
	const Checkpoint & Get(int index) const;


private:

	/// Returns the distance between the two points
	GLdouble getDistance(GLdouble x1, GLdouble z1, GLdouble x2, GLdouble z2);

	/// Pointer to start of Checkpoint array
	Checkpoint * checkpoints;
	/// length of array
	int length;

	/// the number of checkpoints currently passed.
	int noPassed;

};

#endif
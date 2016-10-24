// PotionList.h
//	Header for potion list class
//
// Jayden Grant - 2016

#ifndef POTIONLIST_H
#define POTIONLIST_H

#include "Potion.h"
#include <vector>
#include <cmath>

/// PotionList: Handles a list of potions
class PotionList
{
public:
	///Default constructor: sets default values (0 length list)
	PotionList();

	/// Sets the type and coordinates of specified potion.
	void Add(int type, GLdouble x, GLdouble y, GLdouble z);

	/// calls the display function of all potions in the list.
	void callDisplay();

	/// Compares given position to potions and returns the potion type collected (-1) if no potion was collected.
	int checkCollected(GLdouble x, GLdouble z);

private:

	/// Returns the distance between the two points
	GLdouble getDistance(GLdouble x1, GLdouble z1, GLdouble x2, GLdouble z2);

	/// Vector of potions
	std::vector<Potion> potions;
};

#endif
// PotionList.cpp
//	Implementation for potion list class
//
// Jayden Grant - 2016

#include  "PotionList.h"

PotionList::PotionList() {}


void PotionList::Add(int type, GLdouble x, GLdouble y, GLdouble z)
{
	potions.push_back(Potion(type, x, y, z));
}


void PotionList::callDisplay()
{
	if (!potions.empty())
	{
		for (std::vector<Potion>::iterator it = potions.begin(); it != potions.end(); ++it)
		{
			it->display();
		}
	}
}


int PotionList::checkCollected(GLdouble x, GLdouble z)
{
	int typePassed = -1;
	int cx, cz;
	if (!potions.empty())
	{
		for (std::vector<Potion>::iterator i = potions.begin(); i != potions.end(); ++i)
		{
			cx = i->getX();
			cz = i->getZ();


			if (getDistance(cx, cz, x, z) < 500.0)
			{
				typePassed = i->getType();
				i = potions.erase(i);
				break;
			}
		}
	}

	return typePassed;
}


GLdouble PotionList::getDistance(GLdouble x1, GLdouble z1, GLdouble x2, GLdouble z2)
{
	return sqrt(pow((x2 - x1), 2) + pow((z2 - z1), 2));
}
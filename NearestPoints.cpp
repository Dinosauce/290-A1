// NearestPoints.cpp
// Implementation for nearest checkpoints class
// 
// Chengyu Yang - 2016

#include "NearestPoints.h"

NearestPoints::NearestPoints()
{
	NP_x = 0;
	NP_z = 0;
}

void NearestPoints::CalculateNP(GLdouble x, GLdouble z)
{
	for (int i = 0; i < CheckPoints.size(); i++)
	{
		CheckPointsDistance.push_back(getDistance(CheckPoints.at(i).X, CheckPoints.at(i).Z, x, z));
	}

	ShortestDistance = *min_element(begin(CheckPointsDistance), end(CheckPointsDistance));

	for (int i = 0; i < CheckPoints.size(); i++)
	{
		if (ShortestDistance == getDistance(CheckPoints.at(i).X, CheckPoints.at(i).Z, x, z))
		{
			NP_x = CheckPoints.at(i).X;
			NP_z = CheckPoints.at(i).Z;

			if ((getDistance(CheckPoints.at(i).X, CheckPoints.at(i).Z, x, z) < 1000) && (CheckPoints.size()>1))
			{
					CheckPoints.erase(CheckPoints.begin() + i);	
			}

		}
	}

	CheckPointsDistance.clear();
}

void NearestPoints::setCheckPoints_XZ(GLdouble x, GLdouble z)
{
	CP.X = x;
	CP.Z = z;

	CheckPoints.push_back(CP);
	
}

GLdouble NearestPoints::getDistance(GLdouble x1, GLdouble z1, GLdouble x2, GLdouble z2)
{
	return sqrt(pow((x2 - x1), 2) + pow((z2 - z1), 2));
}


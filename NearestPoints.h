// NearestPoints.h
// Header for nearest checkpoints
// 
// Chengyu Yang - 2016

#ifndef NEARESTPOINTS_H
#define NEARESTPOINTS_H

#include <stdlib.h>
#include <GL/glut.h>
#include <vector>
#include <algorithm>

using namespace std;

/// Holds the XZ Coordinates of a checkpoint
struct CheckPoint
{
	GLdouble X;
	GLdouble Z;
};

/// NearestPoints: Determines the nearest checkpoint to the player
class NearestPoints
{
	
public:

	/// Default Constructor: Sets nearest checkpoint to 0, 0.
	NearestPoints();

	/// Adds checkpoint
	void setCheckPoints_XZ(GLdouble x, GLdouble z);

	/// Determines the nearest checkpoint
	void CalculateNP(GLdouble x, GLdouble z);

	/// Returns the distance between two points
	GLdouble getDistance(GLdouble x1, GLdouble z1, GLdouble x2, GLdouble z2);

	/// Returns the X coordinate of nearest checkpoint.
	GLdouble GetNearestPoints_X(){ return NP_x; }

	/// Returns the Z coordinate of nearest checkpoint.
	GLdouble GetNearestPoints_Z(){ return NP_z; }


private:
	GLdouble NP_x;
	GLdouble NP_z;
	GLdouble ShortestDistance;
	vector<CheckPoint> CheckPoints;
	vector<GLdouble> CheckPointsDistance;
	struct CheckPoint CP;

};

#endif
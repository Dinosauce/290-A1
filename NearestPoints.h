// NearestPoints.h
// Header for nearest checkpoints class
// 
// Chengyu Yang - 2016

#ifndef NEARESTPOINTS_H
#define NEARESTPOINTS_H

#include <stdlib.h>
#include <GL/glut.h>
#include <vector>
#include <algorithm>

using namespace std;

struct CheckPoint
{
	GLdouble X;
	GLdouble Z;
};

class NearestPoints
{
	
public:

	NearestPoints();

	void setCheckPoints_XZ(GLdouble x, GLdouble z);

	void CalculateNP(GLdouble x, GLdouble z);

	GLdouble getDistance(GLdouble x1, GLdouble z1, GLdouble x2, GLdouble z2);

	GLdouble GetNearestPoints_X(){ return NP_x; }

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
//  collsion.h
//  Header file for the collision class
// 
//
//  Shay Leary, March 2005
//--------------------------------------------------------------------------------------
#ifndef COLLISION_H
#define COLLISION_H

//--------------------------------------------------------------------------------------

#include "AABB.h"
#include "AABBLinkedList.h"

//--------------------------------------------------------------------------------------
/// Collision: Collision detection and bounding boxes
class Collision
{
public:

	Collision() {}
	virtual ~Collision() {}

	//----------------------------------------------------------------------------------
	//  Set Methods
	//----------------------------------------------------------------------------------
	// sets initial co-ordinates of bounding boxes (these set the co-ords is AABB, the array,
	// the values for the list are copied from the array using CreateLinkedList).
	///Sets the max x value for bouding box at tempIndex.
	void SetAABBMaxX(const int & tempIndex, const double &tempX) {m_AABB.SetMaxX(tempIndex, tempX);}
	///Sets the min x value for bouding box at tempIndex.
	void SetAABBMinX(const int & tempIndex, const double &tempX) {m_AABB.SetMinX(tempIndex, tempX);}
	///Sets the max y value for bouding box at tempIndex.
	void SetAABBMaxY(const int & tempIndex, const double &tempY) {m_AABB.SetMaxY(tempIndex, tempY);}
	///Sets the min y value for bouding box at tempIndex.
	void SetAABBMinY(const int & tempIndex, const double &tempY) {m_AABB.SetMinY(tempIndex, tempY);}
	///Sets the max z value for bouding box at tempIndex.
	void SetAABBMaxZ(const int & tempIndex, const double &tempZ) {m_AABB.SetMaxZ(tempIndex, tempZ);}
	///Sets the min z value for bouding box at tempIndex.
	void SetAABBMinZ(const int & tempIndex, const double &tempZ) {m_AABB.SetMinZ(tempIndex, tempZ);}

	/// Sets the world size: x
	void SetWorldX(const double &tempX) {m_worldSizeX = tempX;}
	/// Sets the world size: z
	void SetWorldZ(const double &tempZ) {m_worldSizeZ = tempZ;}

	/// Sets number of bounding boxes
	void SetNoBoundingBoxes(const int & tempSize) {m_AABB.SetNoBoundingBoxes(tempSize);}

	//----------------------------------------------------------------------------------
	//  Returns Methods
	//----------------------------------------------------------------------------------
	// returns co-ordinates of bounding boxes
	///Gets the max x value from bouding box at tempIndex.
	double GetAABBMaxX (const int & tempIndex) {return m_AABB.GetMaxX (tempIndex);}
	///Gets the min x value from bouding box at tempIndex.
	double GetAABBMinX (const int & tempIndex) {return m_AABB.GetMinX (tempIndex);}
	///Gets the max y value from bouding box at tempIndex.
	double GetAABBMaxY (const int & tempIndex) {return m_AABB.GetMaxY (tempIndex);}
	///Gets the min y value from bouding box at tempIndex.
	double GetAABBMinY (const int & tempIndex) {return m_AABB.GetMinY (tempIndex);}
	///Gets the max z value from bouding box at tempIndex.
	double GetAABBMaxZ (const int & tempIndex) {return m_AABB.GetMaxZ (tempIndex);}
	///Gets the min z value from bouding box at tempIndex.
	double GetAABBMinZ (const int & tempIndex) {return m_AABB.GetMinZ (tempIndex);}

	/// Gets number of bounding boxes
	int GetNoBoundingBoxes() {return m_AABB.GetNoBoundingBoxes();}

	/// Detects for a collision at given position and returns true if collision occurs.
	bool Collide (double endX, double endY, double endZ);

	// reads the BB info from AABB (dynamic array) and creates a Linked List
	// containing BB data
	/// Creates a linked list from bounding box data
	void CreateLinkedList();

private:
	// initially stores BB info in AABB (dynamic array) before copying to Linked List
	AABB m_AABB;

	// lists to store bounding box info in each quadrant
	AABBLinkedList m_list[4];

	// Stores the list size of each linked list
	// Set to 4 has the world is split into 4 quadrants
	int m_listSize[4];

	// stores world co-ordinates
	double m_worldSizeX;
	double m_worldSizeZ;

	///Checks for collison at given position with bounding box at given index, returns true is collision occurs.
	bool CheckCollision(int index, double endX, double endY, double endZ);

	//----------------------------------------------------------------------------------

    // Privatised copy constructor and assignment operator
    Collision (const Collision &coll) {};
    Collision &operator = (const Collision &coll) {};
};

#endif
//--------------------------------------------------------------------------------------
//  AABH.h
//  Header file for the AABB class
//  Dynamic Array used to store the co-ordinates of the bounding boxes used for collsion 
//  detection.  The array is only used initially before being copied into AABB Linked Lists.
//  The array is then terminated.
//  
//  I created this class originally before using linked lists to store the BB info. But decided
//  to keep it has the stored data can be easily copied across into different linked lists
//  in any prefered order. (i.e. the data is copied into across into linked lists for different
//  quadrants)
//
//  Shay Leary, March 2005
//--------------------------------------------------------------------------------------

#ifndef AABB_H
#define AABB_H

//--------------------------------------------------------------------------------------

using namespace std;
#include <iostream>
#include <math.h>
#include <gl/glut.h>

//--------------------------------------------------------------------------------------
/// AABB: Data structure for dynamic array of bounding boxes
class AABB
{
private:
	/// Data structure to hold x, y and z co-ordinates.
	struct XYZ 
	{ 
		GLdouble x, y, z; 
	}; 
	
	/// Stores max and min XYZ bounding box co-ordinates.
	struct BoundingBox 
	{ 
		XYZ max; 
		XYZ min; 
	}; 

	/// Dynamic array to store 
	BoundingBox *m_BBox;
	/// Number of bounding boxes in array (length)
	int m_NoOfBoxes;

	/// Brief Deletes and clears array
	void ClearBB (BoundingBox* &tempArray);

	//----------------------------------------------------------------------------------

    // Privatised copy constructor and assignment operator
    AABB (const AABB &aabb) {};
    AABB &operator = (const AABB &aabb) {};

public:
	AABB () {}
    virtual ~AABB () {ClearBB(m_BBox);}
	
	//----------------------------------------------------------------------------------
	//  Set Methods
	//----------------------------------------------------------------------------------
	/**
	* @brief Set the max x value of a bounding box.
	* @param tempIndex index of bounding box to set.
	* @param tempX X co-ordinate of bounding box to set.
	*/
	void SetMaxX(const int & tempIndex, const GLdouble &tempX) {m_BBox[tempIndex].max.x = tempX;}
	/**
	* @brief Set the min x value of a bounding box.
	* @param tempIndex index of bounding box to set.
	* @param tempX X co-ordinate of bounding box to set.
	*/
	void SetMinX(const int & tempIndex, const GLdouble &tempX) {m_BBox[tempIndex].min.x = tempX;}
	/**
	* @brief Set the max y value of a bounding box.
	* @param tempIndex index of bounding box to set.
	* @param tempY Y co-ordinate of bounding box to set.
	*/
	void SetMaxY(const int & tempIndex, const GLdouble &tempY) {m_BBox[tempIndex].max.y = tempY;}
	/**
	* @brief Set the min y value of a bounding box.
	* @param tempIndex index of bounding box to set.
	* @param tempY Y co-ordinate of bounding box to set.
	*/
	void SetMinY(const int & tempIndex, const GLdouble &tempY) {m_BBox[tempIndex].min.y = tempY;}
	/**
	* @brief Set the max z value of a bounding box.
	* @param tempIndex index of bounding box to set.
	* @param tempZ Z co-ordinate of bounding box to set.
	*/
	void SetMaxZ(const int & tempIndex, const GLdouble &tempZ) {m_BBox[tempIndex].max.z = tempZ;}
	/**
	* @brief Set the min z value of a bounding box.
	* @param tempIndex index of bounding box to set.
	* @param tempZ Z co-ordinate of bounding box to set.
	*/
	void SetMinZ(const int & tempIndex, const GLdouble &tempZ) {m_BBox[tempIndex].min.z = tempZ;}
	void SetNoBoundingBoxes(const int & tempSize);

	//----------------------------------------------------------------------------------
	//  Get Methods
	//----------------------------------------------------------------------------------
	/**
	* @brief Returns max x value of bounding box.
	* @param tempIndex index of bounding box to return value from.
	* @return max x value of bounding box.
	*/
	GLdouble GetMaxX (const int & tempIndex) {return m_BBox[tempIndex].max.x;}
	/**
	* @brief Returns min x value of bounding box.
	* @param tempIndex index of bounding box to return value from.
	* @return min x value of bounding box.
	*/
	GLdouble GetMinX (const int & tempIndex) {return m_BBox[tempIndex].min.x;}
	/**
	* @brief Returns max y value of bounding box.
	* @param tempIndex index of bounding box to return value from.
	* @return max y value of bounding box.
	*/
	GLdouble GetMaxY (const int & tempIndex) {return m_BBox[tempIndex].max.y;}
	/**
	* @brief Returns min y value of bounding box.
	* @param tempIndex index of bounding box to return value from.
	* @return min y value of bounding box.
	*/
	GLdouble GetMinY (const int & tempIndex) {return m_BBox[tempIndex].min.y;}
	/**
	* @brief Returns max z value of bounding box.
	* @param tempIndex index of bounding box to return value from.
	* @return max z value of bounding box.
	*/
	GLdouble GetMaxZ (const int & tempIndex) {return m_BBox[tempIndex].max.z;}
	/**
	* @brief Returns min z value of bounding box.
	* @param tempIndex index of bounding box to return value from.
	* @return min z value of bounding box.
	*/
	GLdouble GetMinZ (const int & tempIndex) {return m_BBox[tempIndex].min.z;}
	/**
	* @brief Returns the number of bounding boxes (length)
	* @return number of bounding boxes stored.
	*/
	int GetNoBoundingBoxes () {return m_NoOfBoxes;}
};

#endif
//--------------------------------------------------------------------------------------
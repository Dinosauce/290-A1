//  AABBNODE.h
//  Header file for the AABBNODE class
//  Stores details for each bounding box used for collsion detection.  Each node is stored
//  in each link of the AABB Linked List

//  Shay Leary, March 2005
//--------------------------------------------------------------------------------------

#ifndef AABBNODE_H
#define AABBNODE_H

#include <vector>
#include <gl/glut.h>

//--------------------------------------------------------------------------------------
///AABB Node: Holds the data of a single bounding box.
class AABBNode
{
public:
	AABBNode () {Clear();}
    virtual ~AABBNode () {Clear();}

	//----------------------------------------------------------------------------------

	/// clears linked list and frees memory
	void  Clear   ();

	//----------------------------------------------------------------------------------
	//  Get Methods
	//----------------------------------------------------------------------------------
	///Gets max x of bounding box
	GLdouble GetMaxX () {return m_BBox.max.x;}
	///Gets min x of bounding box
	GLdouble GetMinX () {return m_BBox.min.x;}
	///Gets max y of bounding box
	GLdouble GetMaxY () {return m_BBox.max.y;}
	///Gets min y of bounding box
	GLdouble GetMinY () {return m_BBox.min.y;}
	///Gets max z of bounding box
	GLdouble GetMaxZ () {return m_BBox.max.z;}
	///Gets min z of bounding box
	GLdouble GetMinZ () {return m_BBox.min.z;}

    /// Return the address of the link to the next node in the list
    AABBNode *GetNext () const {return m_next;}

	//----------------------------------------------------------------------------------
	//  Set Methods
	//----------------------------------------------------------------------------------
	/** @brief Adds bounding box data to the node
	* @param maxX Coordinate of bounding box vertex
	* @param minX Coordinate of bounding box vertex
	* @param maxY Coordinate of bounding box vertex
	* @param minY Coordinate of bounding box vertex
	* @param maxZ Coordinate of bounding box vertex
	* @param mniZ Coordinate of bounding box vertex
	*/
	void SetData(const GLdouble maxX, const GLdouble minX,
				 const GLdouble maxY, const GLdouble minY,
				 const GLdouble maxZ, const GLdouble minZ);

    /// Set the address of the link to the next node in the list
    void SetNext (AABBNode *next) {m_next = next;}

private:
    /// The address of the next node in the list
    AABBNode *m_next;

	/// Stores x,y,z co-ordinates
	struct XYZ 
	{ 
		GLdouble x, y, z; 
	}; 
	/// stores max and min values of co-ordinates
	struct BoundingBox 
	{ 
		XYZ max; 
		XYZ min; 
	}; 
	/// stores bounding box info
	BoundingBox m_BBox;

	//----------------------------------------------------------------------------------

    // Privatised copy constructor and assignment operator
    AABBNode (const AABBNode &newNode) {};
    AABBNode &operator = (const AABBNode &newNode) {};
};

#endif
//--------------------------------------------------------------------------------------
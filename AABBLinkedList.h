//  AABBLinkedList.h
//  Header file for the AABBLinkedList class
//  Linked List used to store nodes (AABBNode) which contain the co-ordinates of the 
//  boundings boxes which are used for the collsion detection.
//
//	The program splits the world into four quadrants and creates a linked list to
//  store the bounding box details for each
//
//  Author:  Shay Leary
//  March 2005
//--------------------------------------------------------------------------------------

#ifndef AABBLINKED_LIST_H
#define AABBLINKED_LIST_H

//--------------------------------------------------------------------------------------

#include "AABBNode.h"
#include <gl/glut.h>

//--------------------------------------------------------------------------------------
///AABB Linked List: Stores AABB Nodes which contain Bounding Box info.
class AABBLinkedList
{
public:
	/// constructor creates pointer to first node
	AABBLinkedList() {m_first = new AABBNode;}

	virtual ~AABBLinkedList() {Clear();}

	//----------------------------------------------------------------------------------

	/// clears linked list and frees memory
	void Clear();

	/** @brief Adds a node to the start of the linked list
	* @param maxX Coordinate of bounding box vertex
	* @param minX Coordinate of bounding box vertex
	* @param maxY Coordinate of bounding box vertex
	* @param minY Coordinate of bounding box vertex
	* @param maxZ Coordinate of bounding box vertex
	* @param minZ Coordinate of bounding box vertex
	*/
	bool AddToStart (GLdouble maxX, GLdouble minX, GLdouble maxY,
				     GLdouble minY, GLdouble maxZ, GLdouble minZ);
	
	/** @brief Adds data to a node in linked list
	* @param ptrCount Position of node in linked list to set data
	* @param maxX Coordinate of bounding box vertex
	* @param minX Coordinate of bounding box vertex
	* @param maxY Coordinate of bounding box vertex
	* @param minY Coordinate of bounding box vertex
	* @param maxZ Coordinate of bounding box vertex
	* @param minZ Coordinate of bounding box vertex
	*/
	void SetData(const int &ptrCount,
				 const GLdouble maxX, const GLdouble minX,
				 const GLdouble maxY, const GLdouble minY,
				 const GLdouble maxZ, const GLdouble minZ);

	//----------------------------------------------------------------------------------
	//  Get Methods
	//----------------------------------------------------------------------------------
	/** @brief Gets max x position
	* @param ptrCount Node in list to get data from
	*/
	GLdouble GetMaxX (int ptrCount);
	/** @brief Gets min x position
	* @param ptrCount Node in list to get data from
	*/
	GLdouble GetMinX (int ptrCount);
	/** @brief Gets max y position
	* @param ptrCount Node in list to get data from
	*/
	GLdouble GetMaxY (int ptrCount);
	/** @brief Gets min y position
	* @param ptrCount Node in list to get data from
	*/
	GLdouble GetMinY (int ptrCount);
	/** @brief Gets max z position
	* @param ptrCount Node in list to get data from
	*/
	GLdouble GetMaxZ (int ptrCount);
	/** @brief Gets mni z position
	* @param ptrCount Node in list to get data from
	*/
	GLdouble GetMinZ (int ptrCount);
	
	/// Returns the list of the list.
	int GetListSize ();
	
	/// Return the address of the link to the next node in the list
    AABBNode *GetNext () const {return m_first->GetNext();}
	/// Return the address of the link to the first node in the list
	AABBNode *GetFirst() const {return m_first;}

//--------------------------------------------------------------------------------------

private:
	/// pointer to first node in list
	AABBNode *m_first;

	/// used to clear memory
	void Delete (AABBNode *before);

	// Privatised copy constructor and assignment operator
	AABBLinkedList (const AABBLinkedList &ll) {};
	AABBLinkedList &operator = (const AABBLinkedList &ll) {};
};

#endif

//--------------------------------------------------------------------------------------
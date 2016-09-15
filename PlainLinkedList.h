//  PlainLinkedList.h
//  Header file for the PlainLinkedList class
//  Linked List used to store nodes (PlainNode) which contain the co-ordinates of the 
//  of each plain used in the program.
//
//	The program will split the world into four quadrants and creates a linked list to
//  store the bounding box details for each
//
//  Author:  Shay Leary
//  April 2005
//--------------------------------------------------------------------------------------

#ifndef PLAINLINKED_LIST_H
#define PLAINLINKED_LIST_H
	
//--------------------------------------------------------------------------------------

#include "PlainNode.h"

//--------------------------------------------------------------------------------------

///PlainLinkedList: Linked list of Plain nodes
class PlainLinkedList
{
public:
	// constructor creates pointer to first node
	PlainLinkedList() {m_first = new PlainNode;}

	virtual ~PlainLinkedList() {Clear();}

	//----------------------------------------------------------------------------------

	///Clears linked list and frees memory.
	void Clear();

	/** @brief Adds a plain node to the start of the linked list.
	* @param tempXs Coordinate of plains start X
	* @param tempXe Coordinate of plains end X
	* @param tempYs Coordinate of plains start Y
	* @param tempYe Coordinate of plains end Y
	* @param tempZs Coordinate of plains start Z
	* @param tempZe Coordinate of plains end Z
	*/
	bool AddToStart (const int tempType,
				     const GLdouble tempXs, const GLdouble tempXe,
				     const GLdouble tempYs, const GLdouble tempYe,
				     const GLdouble tempZs, const GLdouble tempZe);
	
	/** @brief Adds a plain node to the given position in linked list.
	* @param ptrCount Position to add data to
	* @param tempType Set the type of plain
	* @param tempXs Coordinate of plains start X
	* @param tempXe Coordinate of plains end X
	* @param tempYs Coordinate of plains start Y
	* @param tempYe Coordinate of plains end Y
	* @param tempZs Coordinate of plains start Z
	* @param tempZe Coordinate of plains end Z
	*/
	void SetData(const int &ptrCount, const int tempType,
				 const GLdouble tempXs, const GLdouble tempXe,
				 const GLdouble tempYs, const GLdouble tempYe,
				 const GLdouble tempZs, const GLdouble tempZe);

	//----------------------------------------------------------------------------------
	//  Get Methods
	//----------------------------------------------------------------------------------
	///Get type of plain at index ptrCount.
	GLdouble GetType (int ptrCount);
	///Get starting X postion of plain at index ptrCount.
	GLdouble GetXstart (int ptrCount);
	///Get ending X postion of plain at index ptrCount.
	GLdouble GetXend (int ptrCount);
	///Get starting Y postion of plain at index ptrCount.
	GLdouble GetYstart (int ptrCount);
	///Get ending Y postion of plain at index ptrCount.
	GLdouble GetYend (int ptrCount);
	///Get starting Z postion of plain at index ptrCount.
	GLdouble GetZstart (int ptrCount);
	///Get ending Z postion of plain at index ptrCount.
	GLdouble GetZend (int ptrCount);

	/// Return size of list
	int GetListSize ();
	
	/// Return the address of the link to the next node in the list
    PlainNode *GetNext () const {return m_first->GetNext();}
	/// Return the address of the link to the first node in the list
	PlainNode *GetFirst() const {return m_first;}


//--------------------------------------------------------------------------------------

private:
	// pointer to first node in list
	PlainNode *m_first;

	// used to clear memory
	void Delete (PlainNode *before);

	// Privatised copy constructor and assignment operator
	PlainLinkedList (const PlainLinkedList &array) {};
	PlainLinkedList &operator = (const PlainLinkedList &array) {};
};

#endif

//--------------------------------------------------------------------------------------
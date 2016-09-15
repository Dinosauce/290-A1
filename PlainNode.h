//  PlainNode.h
//  Header file for the PlainNode class
//  Stores details for each plain.  Each node is stored in each link of the Plain Linked List

//  Shay Leary, April 2005
//--------------------------------------------------------------------------------------

#ifndef PLAINNODE_H
#define PLAINNODE_H

//--------------------------------------------------------------------------------------

using namespace std;
#include <iostream>
#include <math.h>
#include <gl/glut.h>

/// PlainNode: One Plain node
class PlainNode
{

public:
	PlainNode () {Clear();}
    virtual ~PlainNode () {Clear();}

	//----------------------------------------------------------------------------------

	void  Clear   ();

	//----------------------------------------------------------------------------------
	//  Get Methods
	//----------------------------------------------------------------------------------
	/// Return type of plain
	GLdouble GetType () {return m_type;}
	/// Return X starting position of plain
	GLdouble GetXstart () {return m_xPlainStart;}
	/// Return X ending position of plain
	GLdouble GetXend () {return m_xPlainEnd;}
	/// Return Y starting position of plain
	GLdouble GetYstart () {return m_yPlainStart;}
	/// Return Y ending position of plain
	GLdouble GetYend () {return m_yPlainEnd;}
	/// Return Z starting position of plain
	GLdouble GetZstart () {return m_zPlainStart;}
	/// Return Z ending position of plain
	GLdouble GetZend () {return m_zPlainEnd;}

    /// Return the address of the link to the next node in the list
    PlainNode *GetNext () const {return m_next;}

	//----------------------------------------------------------------------------------
	//  Set Methods
	//----------------------------------------------------------------------------------
	/** @brief Sets the plain.
	* @param tempType Set the type of plain
	* @param tempXs Coordinate of plains start X
	* @param tempXe Coordinate of plains end X
	* @param tempYs Coordinate of plains start Y
	* @param tempYe Coordinate of plains end Y
	* @param tempZs Coordinate of plains start Z
	* @param tempZe Coordinate of plains end Z
	*/
	void SetData(const int tempType,
				 const GLdouble tempXs, const GLdouble tempXe,
				 const GLdouble tempYs, const GLdouble tempYe,
				 const GLdouble tempZs, const GLdouble tempZe);

    /// Set the address of the link to the next node in the list
    void SetNext (PlainNode *next) {m_next = next;}

private:
    // The address of the next node in the list
    PlainNode *m_next;

	// Stores type of plain:
	// (0: flat plane)
	// (1: incline from z to y)
	// (2: incline from x to y)
	GLdouble m_type;
	

	// stores start and end co-ordinates of plane on x, y and z axis
	GLdouble m_xPlainStart, m_xPlainEnd;
	GLdouble m_yPlainStart, m_yPlainEnd;
	GLdouble m_zPlainStart, m_zPlainEnd;

	//----------------------------------------------------------------------------------

    // Privatised copy constructor and assignment operator
    PlainNode (const PlainNode &newNode) {};
    PlainNode &operator = (const PlainNode &newNode) {};
};

#endif

//--------------------------------------------------------------------------------------
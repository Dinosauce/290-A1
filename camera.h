//  camera.h
//  Header file for the camera class
//	Allows the camera to be navigated around the world. 
//	Also sets Plains, Bounding Boxes and view Maps
//
//  Shay Leary, March 2005
//--------------------------------------------------------------------------------------
#ifndef CAMERA_H
#define CAMERA_H

#define PI 3.1415962654

#include "collision.h"
#include "cameraMap.h"
#include "PlainLinkedList.h"
#include "EasySound.h"

//--------------------------------------------------------------------------------------

/// Camera: Allows for camera navigatiom
class Camera
{
public:

	Camera();
	virtual ~Camera() {es->Unload(stepSound);}

	//----------------------------------------------------------------------------------
	
	//----------------------------------------------------------------------------------
	//  Set Methods
	//----------------------------------------------------------------------------------
	/** @brief Sets max x of a bounding box
	* @param tempIndex index to add bounding box data to.
	* @param tempX value to set.
	*/
	void SetAABBMaxX(const int & tempIndex, const GLdouble &tempX) {m_colDetect.SetAABBMaxX(tempIndex, tempX);}
	/** @brief Sets min x of a bounding box
	* @param tempIndex index to add bounding box data to.
	* @param tempX value to set.
	*/
	void SetAABBMinX(const int & tempIndex, const GLdouble &tempX) {m_colDetect.SetAABBMinX(tempIndex, tempX);}
	/** @brief Sets max y of a bounding box
	* @param tempIndex index to add bounding box data to.
	* @param tempX value to set.
	*/
	void SetAABBMaxY(const int & tempIndex, const GLdouble &tempY) {m_colDetect.SetAABBMaxY(tempIndex, tempY);}
	/** @brief Sets min y of a bounding box
	* @param tempIndex index to add bounding box data to.
	* @param tempX value to set.
	*/
	void SetAABBMinY(const int & tempIndex, const GLdouble &tempY) {m_colDetect.SetAABBMinY(tempIndex, tempY);}
	/** @brief Sets max z of a bounding box
	* @param tempIndex index to add bounding box data to.
	* @param tempX value to set.
	*/
	void SetAABBMaxZ(const int & tempIndex, const GLdouble &tempZ) {m_colDetect.SetAABBMaxZ(tempIndex, tempZ);}
	/** @brief Sets min z of a bounding box
	* @param tempIndex index to add bounding box data to.
	* @param tempX value to set.
	*/
	void SetAABBMinZ(const int & tempIndex, const GLdouble &tempZ) {m_colDetect.SetAABBMinZ(tempIndex, tempZ);}

	// set step and rotation size
	///Sets the speed at which the camera rotates.
	void SetRotateSpeed (const GLdouble &tempSpeed) {m_rotateSpeed = tempSpeed;}
	//Sets the speed at which the camera moves.
	void SetMoveSpeed (const GLdouble &tempSpeed) {m_moveSpeed = tempSpeed;}

	// COLLSION DETECTION FUNCTIONS
	/// set collision detection (TRUE = on)
	void SetCollisionDetectionOn (const bool &tempCol) {m_CollisionDetectionOn = tempCol;}
	/// set number of bounding boxes
	void SetNoBoundingBoxes(const int & tempSize) {m_colDetect.SetNoBoundingBoxes(tempSize);}
	/// Set the co-ordinates of the world
	void SetWorldCoordinates (const GLdouble &tempX, const GLdouble &tempZ);
	///Sets the bounding boxes for collision detection.
	void InitiateBoundingBoxes() {m_colDetect.CreateLinkedList();}

	/** @brief set a plains for the camera to follor
	* @param tempType sets the type of plain to create
	*/
	void SetPlains (const int tempType,
				    const GLdouble tempXs, const GLdouble tempXe,
				    const GLdouble tempYs, const GLdouble tempYe,
				    const GLdouble tempZs, const GLdouble tempZe);

	//----------------------------------------------------------------------------------
	//  Get Methods
	//----------------------------------------------------------------------------------
	
	GLdouble GetLR () {return m_x;}
	GLdouble GetUD () {return m_y;}
	GLdouble GetFB () {return m_z;}	
	///Returns max x fo bounding box at tempIndex.
	GLdouble GetAABBMaxX (const int & tempIndex) {return m_colDetect.GetAABBMaxX (tempIndex);}
	///Returns min x fo bounding box at tempIndex.
	GLdouble GetAABBMinX (const int & tempIndex) {return m_colDetect.GetAABBMinX (tempIndex);}
	///Returns max y fo bounding box at tempIndex.
	GLdouble GetAABBMaxY (const int & tempIndex) {return m_colDetect.GetAABBMaxY (tempIndex);}
	///Returns min y fo bounding box at tempIndex.
	GLdouble GetAABBMinY (const int & tempIndex) {return m_colDetect.GetAABBMinY (tempIndex);}
	///Returns max z fo bounding box at tempIndex.
	GLdouble GetAABBMaxZ (const int & tempIndex) {return m_colDetect.GetAABBMaxZ (tempIndex);}
	///Returns min z fo bounding box at tempIndex.
	GLdouble GetAABBMinZ (const int & tempIndex) {return m_colDetect.GetAABBMinZ (tempIndex);}

	///Returns X camera position
	GLdouble GetXPos() { return m_x; }
	///Returns Y camera position
	GLdouble GetYPos() { return m_y; }
	///Returns Z camera position
	GLdouble GetZPos() { return m_z; }
	
	/// Sets the X, Y, Z postion of camera and its horixontal angle.
	void Position (GLdouble const & tempX,
				   GLdouble const & tempY,
				   GLdouble const & tempZ,
				   GLdouble const & tempAngle);

	// check whether ok to move
	void CheckCamera();

	/// Move the camera forward/backward
	void DirectionFB(int const & tempMove);
	/// Move the camera sidewards
	void DirectionLR(int const & tempMove);
	///Move the camera vertically
	void DirectionUD(int const & tempMove);
	///Rotate camera horizontally
	void DirectionRotateLR(GLdouble const & tempMove);
	///Rotate camera vertically
	void DirectionLookUD(int const & tempMove);

	/// display mini map
	void DisplayMap(const int & screenWidth, const int & screenHeight, 
		            const GLuint & tempImage);
	/// display welcome screen
	void DisplayWelcomeScreen (const int & screenWidth, const int & screenHeight,
							   const int & tempExit, const GLuint & tempImage);
	/// display no exit sign
	void DisplayNoExit (const int & screenWidth, const int & screenHeight, 
						const GLuint & tempImage);
	
private:

	//steep incline increments
	GLdouble m_incrementX;
	GLdouble m_incrementZ;
	int m_No_Plains;
	int m_plainNo;
	GLdouble m_plainHeight;

	// rotation variables
	GLdouble m_rotateAngleLR;
	GLdouble m_deltaAngleLR;
	GLdouble m_rotateAngleUD;	
	GLdouble m_deltaAngleUD;

	// movement variables
	GLdouble m_x, m_y, m_z, m_zLast, m_xLast;
	GLdouble m_lookX, m_lookY,m_lookZ;
	GLdouble m_lookXX, m_lookYY, m_lookZZ;
	GLdouble m_deltaMoveLR;
	GLdouble m_deltaMoveFB;
	GLdouble m_deltaMoveUD;
	GLdouble m_direction;

	// movement speed (step size)
	GLdouble m_rotateSpeed;
	GLdouble m_moveSpeed;
	
	// is it ok to move
	bool MoveFBOK();
	bool MoveLROK();
	bool MoveUDOK();
	bool RotateLROK();
	bool LookUDOK();

	// move around the world
	void MoveFB();
	void MoveLR();
	void MoveUD();
	void RotateLR();
	void LookUD();
	
	/// Set plains for caerma to move on (overloaded)
	void SetPlains(const int & moveX, const int & moveZ);

	/// reset camera
	void ResetXYZ();
	// display new view
	void callGLLookAt();

	bool m_CollisionDetectionOn;

	// objects
	Collision m_colDetect;
	CameraMap m_map;
	PlainLinkedList m_Plain;

	// These functions were set up to climb stairs, but are not used.
	// The Plain object is used instead
	void ClimbSteps(GLdouble stepStart, GLdouble stepFinish, GLdouble stepHeight, GLdouble stepWidth, int noSteps);
	void CheckSteps();

	CEasySound *es;
	CSound* stepSound;

	//----------------------------------------------------------------------------------

    // Privatised copy constructor and assignment operator
    Camera (const Camera &cam) {};
    Camera &operator = (const Camera &cam) {};
};

#endif
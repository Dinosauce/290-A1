//  cameraMap.h
//  Header file for the cameraMap class
//  Displays a map and welcome screen in 2D on the screen
//  
//  Shay Leary, April 2005
//--------------------------------------------------------------------------------------

#ifndef CAMERA_MAP_H
#define CAMERA_MAP_H

#include <gl/glut.h>

//--------------------------------------------------------------------------------------

/// CameraMap: Displays 2D images (e.g. HUD)
class CameraMap
{
public:
	CameraMap() {};
	virtual ~CameraMap() {};

	//----------------------------------------------------------------------------------

	/// Display mini map and player indicator at given world position.
	void DisplayMap(const int & screenWidth, const int & screenHeight,
				    const GLdouble & xPos, const GLdouble & zPos,
					const GLuint & tempImage);

	/// Displays the welcoming/ tutorial screen.
	void DisplayWelcomeScreen (const int & screenWidth, const int & screenHeight, 
		                       const int & tempExit, const GLuint & tempImage);

	/// Displays 'No exit' signs for unmapped areas.
	void DisplayNoExit (const int & screenWidth, const int & screenHeight, 
						const GLuint & tempImage);

private:
    // Privatised copy constructor and assignment operator
    CameraMap (const CameraMap &cam) {};
    CameraMap &operator = (const CameraMap &cam) {};
};

#endif

//--------------------------------------------------------------------------------------
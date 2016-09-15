//  texturedPolygon.h
//  Header file for the texturedPolygon class
// 
//
//  Shay Leary, March 2005
//--------------------------------------------------------------------------------------

#ifndef TEXTURE_POLYGON_H
#define TEXTURE_POLYGON_H

//--------------------------------------------------------------------------------------

#include <gl/glut.h>
#include <stdio.h>	// should really be using c++, but didn't get time to change
#include <stdlib.h>

//--------------------------------------------------------------------------------------

/// TexturedPolygons: Loads textures and display lists.
class TexturedPolygons
{
public:

	TexturedPolygons () {}
    virtual ~TexturedPolygons () {Clear();}

	//----------------------------------------------------------------------------------

	/// Returns texture at tempIndex
	GLuint GetTexture (const int & tempIndex) {return m_texture[tempIndex];}

	/** @brief Loads a raw image file into memory
	* @param filename relative filepath
	* @param imgWidth width of image 
	* @param imgHeight height of image 
	*/
	GLubyte* LoadTexture(char *filename, int imgWidth, int imgHeight);
	
	/// Set the number of textures to be used 
	void SetTextureCount(const int &textureNo);

	/** @brief Creates texture
	* @param textureNo The number of the texture to load
	* @param image image typeto create
	* @param imgWidth width of image 
	* @param imgHeight height of image 
	*/
	void CreateTexture(int textureNo, unsigned char* image, int imgWidth, int imgHeight);

	/** @brief Calls function to creates display list to contain image
	* @param XYZ plain of which to create display list
	* @param listNo assign display list no
	* @param xImgSize Images size (x)
	* @param zImgSize Images size (z)
	* @param xStart x starting position
	* @param yStart y starting position
	* @param zStart z starting position
	* @param xTimes no of times to repeat image on x axis
	* @param zTimes no of times to repeat image on z axis
	*/
	void CreateDisplayList(const int &XYZ, const int &listNo, 
		                   const GLdouble &xImgSize, const GLdouble &zImgSize, 
					       const GLdouble &xStart, const GLdouble &yStart, const GLdouble &zStart,
					       const GLdouble &xTimes, const GLdouble &zTimes);

	/** @brief Calls function to create display lists where image is larger than world scale on YZ axis
	* @param listNo assign display list no
	* @param xStart x starting position
	* @param yStart y starting position
	* @param ySize Images size (y)
	* @param zStart z starting position
	* @param zSize Images size (z)
	* @param yImgSize images scale y
	* @param zImgSize images scale z
	*/
	void CreateYtoZWindowList(const int &listNo, const GLdouble &xStart, 
							  const GLdouble &yStart, const GLdouble &ySize, 
							  const GLdouble &zStart, const GLdouble &zSize,
							  const GLdouble &yImgSize, const GLdouble &zImgSize);

	/** @brief Calls function to create display lists where image is larger than world scale on XY axis
	* @param listNo assign display list no
	* @param zStart z starting position
	* @param xStart x starting position
	* @param xSize Images size (x)
	* @param yStart y starting position
	* @param ySize Images size (y)
	* @param xImgSize images scale x
	* @param yImgSize images scale y
	*/
	void CreateXtoYWindowList(const int &listNo, const GLdouble &zStart, 
							  const GLdouble &xStart, const GLdouble &xSize, 
							  const GLdouble &yStart, const GLdouble &ySize,
							  const GLdouble &xImgSize, const GLdouble &yImgSize);
	
	// used to create display lists where image is on an angle
	/** @brief Calls function to create display lists where image is on an angle.
	* @param imageWidth width of image
	* @param imageHeight height of image
	* @param x1 x position 1
	* @param x2 x position 2
	* @param x3 x position 3
	* @param x4 x position 4
	* @param y1 y position 1
	* @param y2 y position 2
	* @param y3 y position 3
	* @param y4 y position 4
	* @param z1 z position 1
	* @param z2 z position 2
	* @param z3 z position 3
	* @param z4 z position 4
	* @param smallestX ordering of image corners
	* @param smallestZ ordering of image corners
	*/
	void CreateAngledPolygon(const int &listNo, 
							 const GLdouble &imageWidth, const GLdouble &imageHeight,
							 const GLdouble &x1, const GLdouble &x2, 
							 const GLdouble &x3, const GLdouble &x4,
						     const GLdouble &y1, const GLdouble &y2,
							 const GLdouble &y3, const GLdouble &y4,
							 const GLdouble &z1, const GLdouble &z2,
							 const GLdouble &z3, const GLdouble &z4,
							 const int &smallestX, const int &smallestZ);

private:
	// pointer to display list
	GLuint *m_texture;

	/// returns image file
	GLubyte* LoadRawImageFile(char* filename, int width, int height);

	void Clear ();

	/// creates display list to contain image on X Z axis
	void CreateXtoZTextureList(const GLdouble &xImgSize, const GLdouble &zImgSize, 
					           const GLdouble &xStart, const GLdouble &yStart, const GLdouble &zStart,
					           const GLdouble &xTimes, const GLdouble &zTimes);

	/// creates display list to contain image on X Y axis
	void CreateXtoYTextureList(const GLdouble &xImgSize, const GLdouble &yImgSize, 
							   const GLdouble &xStart, const GLdouble &yStart, const GLdouble &zStart,
							   const GLdouble &xTimes, const GLdouble &yTimes, const bool &flip);

	/// creates display list to contain image on Y Z axis
	void CreateYtoZTextureList(const GLdouble &yImgSize, const GLdouble &zImgSize, 
							   const GLdouble &xStart, const GLdouble &yStart, const GLdouble &zStart,
							   const GLdouble &yTimes, const GLdouble &zTimes, const bool &flip);
	
	/// called from	CreateAngledPolygon determine how images are displayed
	void CreateTextureScale(GLdouble & xzImage1, GLdouble & xzImage2, 
							GLdouble & xzImage3, GLdouble & xzImage4,
							const GLdouble &imageSize);

	//----------------------------------------------------------------------------------

    // Privatised copy constructor and assignment operator
    TexturedPolygons (const TexturedPolygons &tp) {};
    TexturedPolygons &operator = (const TexturedPolygons &tp) {};
};

#endif

//----------------------------------------------------------------------------------
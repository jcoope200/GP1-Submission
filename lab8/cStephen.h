/*
=================
cStephen.h
- Header file for class definition - SPECIFICATION
- Header file for the Sprite class
=================
*/
#ifndef _CStephen_H
#define _CStephen_H
#include "cSprite.h"

class cStephen : public cSprite
{
private:
	bool mActive;
	int mNoFrames;
	int mCurrentFrame;
	RECT mSourceRect;
	float mRate;

public:
	cStephen();
	cStephen(D3DXVECTOR3 sPosition, LPDIRECT3DDEVICE9 pd3dDevice, LPCSTR theFilename); // Constructor
	void update(float dt);					// update the balloons position based on the translation
	RECT getSourceRect();					// Return the current segment of the sprite sheet to draw.
	int getCurrentFrame();					// Return the current frame.
	void setActive(bool sActive);			// Set the sprite to active.
	bool isActive();						// Determine if the sprite is active.
};
#endif
/*
=================
cStephen.cpp
- Header file for class definition - IMPLEMENTATION
=================
*/
#include "cStephen.h"
/*
=================
- Data constructor initializes the cBalloon to the data passed to 
- the constructor from the paramater sPosition.
- Is always called, thus ensures all sprite objects are in a consistent state.
=================
*/
cStephen::cStephen(): cSprite() 			// Default constructor
{
	mActive = true;
	mNoFrames = 1;
	mCurrentFrame = 0;
	mRate = 1000.0f/25.0f;
	SetRect(&mSourceRect,0,0,cStephen::getSTWidth(),cStephen::getSTHeight());
}
cStephen::cStephen(D3DXVECTOR3 sPosition, LPDIRECT3DDEVICE9 pd3dDevice, LPCSTR theFilename): cSprite(sPosition,pd3dDevice,theFilename)  // Constructor
{
	mActive = true;
	mNoFrames = 1;
	mCurrentFrame = 0;
	mRate = 1000.0f/25.0f;
	SetRect(&mSourceRect,0,0,cStephen::getSTWidth(),cStephen::getSTHeight());
}
/*
=================
- update the position etc of the sprite.
=================
*/
void cStephen::update(float dt) 					// update the balloons position based on the translation
{
	cSprite::update();
	mCurrentFrame++;
	if(dt > mRate)
	{
		if(mCurrentFrame > mNoFrames)
		{
			mCurrentFrame = 0;
			SetRect(&mSourceRect,mCurrentFrame*64,0,(mCurrentFrame*64)+64,64);
			mActive = false;
		}
	}
	SetRect(&mSourceRect,mCurrentFrame*64,0,(mCurrentFrame*64)+64,64);
}
/*
=================
- Return the current segment of the sprite sheet to draw.
=================
*/
RECT cStephen::getSourceRect() 					// Return the current segment of the sprite sheet to draw.
{
	return mSourceRect;
}
/*
=================
- Return the current frame.
=================
*/
int cStephen::getCurrentFrame() 					// Return the current frame.
{
	return mCurrentFrame;
}
/*
=================
- Set the sprite to active.
=================
*/
void cStephen::setActive(bool sActive) 			// Set the sprite to active.
{
	mActive = sActive;
}
/*
=================
- Determine if the sprite is active.
=================
*/
bool cStephen::isActive() 						// Determine if the sprite is active.
{
	return mActive;
}

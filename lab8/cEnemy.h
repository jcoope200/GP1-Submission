/*
=================
cEnemy.h
- Header file for class definition - SPECIFICATION
- Header file for the Sprite class
=================
*/
#ifndef _CEnemy_H
#define _CEnemy_H
#include "cSprite.h"

class cEnemy : public cSprite
{
private:
	int mScore;
	eDirection mDirection;

public:
	cEnemy();
	cEnemy(D3DXVECTOR3 sPosition, LPDIRECT3DDEVICE9 pd3dDevice, LPCSTR theFilename); // Constructor
	void update();					// update the Enemys position based on the translation
	eDirection getDirection();      // Rturns the current direction of the sprite
	void setDirection(eDirection theDirection); // Sets the current direction for the sprite.
};
#endif
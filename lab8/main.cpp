/*
=================
main.cpp
Main entry point for the application
=================
*/

#include "GameConstants.h"
#include "GameResources.h"
#include "cD3DManager.h"
#include "cD3DXSpriteMgr.h"
#include "cD3DXTexture.h"
#include "cSprite.h"
#include "cExplosion.h"
#include "cStephen.h"
#include "cEnemy.h"
#include "cXAudio.h"
#include "cD3DXFont.h"
#include <strsafe.h>

using namespace std;
bool game = false;
bool gameWater = false;
bool gameLightning = false;
bool gameFire = false;
bool gameSpace = false;
bool gameCity = false;
bool gameForest = false;
bool gameIce = false;
bool startmenu = true;
bool endscreen = false;
bool music = false;
//bool musicWater = false;
//bool musicLightning = false;
//bool musicFire = false;
//bool musicSpace = false;
//bool musicCity = false;
//bool musicForest = false;
//bool musicIce = false;
//bool musicEnd = false;
RECT start;

HINSTANCE hInst; // global handle to hold the application instance
HWND wndHandle; // global variable to hold the window handle

// Get a reference to the DirectX Manager
static cD3DManager* d3dMgr = cD3DManager::getInstance();

// Get a reference to the DirectX Sprite renderer Manager 
static cD3DXSpriteMgr* d3dxSRMgr = cD3DXSpriteMgr::getInstance();

float rot = 0.0f;
D3DXVECTOR2 stephenTrans = D3DXVECTOR2(100,375);
D3DXVECTOR2 stephenScale = D3DXVECTOR2(1.0f,1.0f);
D3DXVECTOR2 EnemyTrans = D3DXVECTOR2(300,300);
RECT clientBounds;

int EnemyPos = clientBounds.right/2 - 200;
vector<cEnemy*> aEnemy;
vector<cEnemy*>::const_iterator iterRO;
vector<cEnemy*>::iterator george;
vector<cEnemy*>::iterator index;

TCHAR szTempOutput[30];

bool gHit = false;
int gEnemiesKilled = 0;
char gEnemiesKilledStr[50];
D3DXVECTOR3 expPos;
POINT ptStephen;
list<cExplosion*> gExplode;
list<cStephen*> gStephen;
POINT pstephenPos;


list<cStephen*>::iterator pete = gStephen.begin();

cXAudio gAttackSound;
cXAudio gameMusic;
//cXAudio waterMusic;
//cXAudio lightningMusic;
//cXAudio fireMusic;
//cXAudio spaceMusic;
//cXAudio cityMusic;
//cXAudio forestMusic;
//cXAudio iceMusic;
//cXAudio endMusic;

LPCSTR background = "Images\\menu background.png";
LPDIRECT3DSURFACE9 aSurface;



/*
==================================================================
* LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam,
* LPARAM lParam)
* The window procedure
==================================================================
*/
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	// Check any available messages from the queue
	switch (message)
	{
	case WM_KEYDOWN:
		{
			if(wParam == VK_LEFT)
			{
				if(pstephenPos.x>(clientBounds.left))
				{
					pstephenPos.x -=10.0f;
					stephenTrans.x -= 10.0f;
					return 0;
				}
			}
			if(wParam == VK_RIGHT)
			{
				if(pstephenPos.x<(clientBounds.right - 90))
				{
					pstephenPos.x += 10.0f;
					stephenTrans.x += 10.0f;
					return 0;
				}
			}
			if(wParam == '1')
			{
				startmenu = false;
				gameLightning = false;
				gameFire = false;
				gameSpace = false;
				gameCity = false;
				gameForest = false;
				gameIce = false;
				//menuMusic.~cXAudio();
				game = true;
				gameWater = true;
				//musicWater = false;
				//waterMusic.playSound(L"Sounds\\buoybase.wav",false);
				return 0;
				
			}
			if(wParam == '2')
			{
				startmenu = false;
				gameWater = false;
				gameFire = false;
				gameSpace = false;
				gameCity = false;
				gameForest = false;
				gameIce = false;
				game = true;
				//waterMusic.~cXAudio();
				gameLightning = true;
				//musicLightning = true;
				//lightningMusic.playSound(L"Sounds\\mutecity.wav",false);
				return 0;
			}
			if(wParam == '3')
			{
				startmenu = false;
				gameWater = false;
				gameLightning = false;
				gameSpace = false;
				gameCity = false;
				gameForest = false;
				gameIce = false;
				game = true;
				//lightningMusic.~cXAudio();
				gameFire = true;
				//musicFire = true;
				//fireMusic.playSound(L"Sounds\\metaridley.wav",false);
				return 0;
			}
			if(wParam == '4')
			{
				startmenu = false;
				gameWater = false;
				gameLightning = false;
				gameFire = false;
				gameCity = false;
				gameForest = false;
				gameIce = false;
				game = true;
				//fireMusic.~cXAudio();
				gameSpace = true;
				//musicSpace = true;
				//spaceMusic.playSound(L"Sounds\\revenge.wav",false);
				return 0;
				
			}
			if(wParam == '5')
			{
				startmenu = false;
				gameWater = false;
				gameLightning = false;
				gameFire = false;
				gameSpace = false;
				gameForest = false;
				gameIce = false;
				game = true;
				//spaceMusic.~cXAudio();
				gameCity = true;
				//musicCity = true;
				//cityMusic.playSound(L"Sounds\\spearpillar.wav",false);
				return 0;
				
			}
			if(wParam == '6')
			{
				startmenu = false;
				gameWater = false;
				gameLightning = false;
				gameFire = false;
				gameSpace = false;
				gameCity = false;
				gameIce = false;
				game = true;
				//cityMusic.~cXAudio();
				gameForest = true;
				//musicForest = true;
				//forestMusic.playSound(L"Sounds\\medley.wav",false);
				return 0;
				
			}
			if(wParam == '7')
			{
				startmenu = false;
				gameWater = false;
				gameLightning = false;
				gameFire = false;
				gameSpace = false;
				gameCity = false;
				gameForest = false;
				game = true;
				//forestMusic.~cXAudio();
				gameIce = true;
				//musicIce = true;
				//iceMusic.playSound(L"Sounds\\snowman.wav",false);
				return 0;
				
			}
			if(wParam=='8')
			{
				startmenu = false;
				gameWater = false;
				gameLightning = false;
				gameFire = false;
				gameSpace = false;
				gameCity = false;
				gameForest = false;
				gameIce == false;
				game = false;
				//iceMusic.~cXAudio();
				endscreen = true;
				//endMusic.playSound(L"Sounds\\gabbag.wav", false);
				//startmenu = true;
				return 0;
				
			}
			if(wParam == '9')
			{
				gameWater = false;
				gameLightning = false;
				gameFire = false;
				gameSpace = false;
				gameCity = false;
				gameForest = false;
				gameIce = false;
				game = false;
				endscreen == false;
				//endMusic.~cXAudio();
				startmenu = true;
				//cXAudio menuMusic;
				//menuMusic.playSound(L"Sounds\\gabbag.wav",false);
				return 0;
				
			}


			if(wParam == VK_SPACE)
			{
				if(game == true)
					{
						POINT mouseXY;
						mouseXY.x = LOWORD(lParam);
						mouseXY.y = HIWORD(lParam);
						george = aEnemy.begin();
							while (george != aEnemy.end() && !gHit)
							{
								if ( (*george)->insideRect((*george)->getBoundingRect(), pstephenPos))
								{
									OutputDebugString("Hit!\n");
									gHit = true;
							
									george = aEnemy.erase(george);
									gEnemiesKilled++;
									sprintf_s(gEnemiesKilledStr, 50, "Kills: %d", gEnemiesKilled);
								}
								else
								{
									++george;
								}
							}
						expPos = D3DXVECTOR3((float)pstephenPos.x,(float)pstephenPos.y-23, 0.0f);
						gAttackSound.playSound(L"Sounds\\dale.wav",false);

						StringCchPrintf(szTempOutput, STRSAFE_MAX_CCH, TEXT("Mouse: lLastX=%d lLastY=%d\r\n"), LOWORD(lParam), HIWORD(lParam));
						OutputDebugString(szTempOutput);
						gHit = false;
						return 0;
					}
			}
			return 0;
		}
	case WM_CLOSE:
		{
			// Exit the Game
			PostQuitMessage(0);
			return 0;
		}
	case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		}
	}
	// Always return the message to the default window
	// procedure for further processing
	return DefWindowProc(hWnd, message, wParam, lParam);
}

/*
==================================================================
* bool initWindow( HINSTANCE hInstance )
* initWindow registers the window class for the application, creates the window
==================================================================
*/
bool initWindow( HINSTANCE hInstance )
{
	WNDCLASSEX wcex;
	// Fill in the WNDCLASSEX structure. This describes how the window
	// will look to the system
	wcex.cbSize = sizeof(WNDCLASSEX); // the size of the structure
	wcex.style = CS_HREDRAW | CS_VREDRAW; // the class style
	wcex.lpfnWndProc = (WNDPROC)WndProc; // the window procedure callback
	wcex.cbClsExtra = 0; // extra bytes to allocate for this class
	wcex.cbWndExtra = 0; // extra bytes to allocate for this instance
	wcex.hInstance = hInstance; // handle to the application instance
	wcex.hIcon = LoadIcon(hInstance,MAKEINTRESOURCE(IDI_MyWindowIcon)); // icon to associate with the application
	wcex.hCursor = LoadCursor(NULL, (IDC_ARROW));// the default cursor
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW+1); // the background color
	wcex.lpszMenuName = NULL; // the resource name for the menu
	wcex.lpszClassName = "Balloons"; // the class name being created
	wcex.hIconSm = LoadIcon(hInstance,"stephen icon.ico"); // the handle to the small icon
	pstephenPos.x = 100;
	pstephenPos.y = 375;

	RegisterClassEx(&wcex);
	// Create the window
	wndHandle = CreateWindow("Balloons",			// the window class to use
							 "Stephen Stills' Fabulous Adventure",			// the title bar text
							WS_OVERLAPPEDWINDOW,	// the window style
							CW_USEDEFAULT, // the starting x coordinate
							CW_USEDEFAULT, // the starting y coordinate
							800, // the pixel width of the window
							600, // the pixel height of the window
							NULL, // the parent window; NULL for desktop
							NULL, // the menu for the application; NULL for none
							hInstance, // the handle to the application instance
							NULL); // no values passed to the window
	// Make sure that the window handle that is created is valid
	if (!wndHandle)
		return false;
	// Display the window on the screen
	ShowWindow(wndHandle, SW_SHOW);
	UpdateWindow(wndHandle);
	return true;
}

/*
==================================================================
// This is winmain, the main entry point for Windows applications
==================================================================
*/
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow )
{
	// Initialize the window
	if ( !initWindow( hInstance ) )
		return false;
	// called after creating the window
	if ( !d3dMgr->initD3DManager(wndHandle) )
		return false;
	if ( !d3dxSRMgr->initD3DXSpriteMgr(d3dMgr->getTheD3DDevice()))
		return false;

	// Grab the frequency of the high def timer
	__int64 freq = 0;				// measured in counts per second;
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
	float sPC = 1.0f / (float)freq;			// number of seconds per count

	__int64 currentTime = 0;				// current time measured in counts per second;
	__int64 previousTime = 0;				// previous time measured in counts per second;

	float numFrames   = 0.0f;				// Used to hold the number of frames
	float timeElapsed = 0.0f;				// cumulative elapsed time

	GetClientRect(wndHandle,&clientBounds);

	float fpsRate = 1.0f/25.0f;

	D3DXVECTOR3 EnemyPos;
	srand((unsigned int)time(NULL));
	int numEnemies = 5;//(rand()%5+1);

	for(int loop = 0; loop < numEnemies; loop++)
	{
		if(loop<3){
			EnemyPos = D3DXVECTOR3(160+loop*160,(float)clientBounds.top+150,0);
		}
		else{
			EnemyPos = D3DXVECTOR3(160+((loop-3)*160),(float)clientBounds.top+300,0);
		}
		aEnemy.push_back(new cEnemy(EnemyPos,d3dMgr->getTheD3DDevice(),"Images\\ridley.png"));
		srand((unsigned int)time(NULL));
		aEnemy[loop]->setTranslation(D3DXVECTOR2(5.0f,(rand()%+(-5))));
	}

	LPDIRECT3DSURFACE9 aSurface;				// the Direct3D surface
	LPDIRECT3DSURFACE9 theBackbuffer = NULL;  // This will hold the back buffer
	
	cD3DXFont * EnemyFont = new cD3DXFont(d3dMgr->getTheD3DDevice(),hInstance, "Metroid Prime: Hunters3");
	cD3DXFont * MenuFont = new cD3DXFont(d3dMgr->getTheD3DDevice(),hInstance, "Metroid Prime: Hunters3");

	RECT textPos;
	SetRect(&textPos, 30, 10, 400, 100);
	RECT menuTextPos;
	SetRect(&menuTextPos, 20, 10, 600, 1000);
	D3DXVECTOR3 stephenPos = D3DXVECTOR3(600, 600, 0);
	D3DXVECTOR3 aEnemyPos;
	
	cSprite stephen (stephenPos, d3dMgr->getTheD3DDevice(), "Images\\stephen.png");
	stephen.setTranslation(D3DXVECTOR2(5.0f, 0.0f));
	D3DXMATRIX stephenMatrix;
	
	MSG msg;
	ZeroMemory( &msg, sizeof( msg ) );

	// Create the background surface
	aSurface = d3dMgr->getD3DSurfaceFromFile(background);

	gameMusic.playSound(L"Sounds\\gabbag.wav",true);

	QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
	while( msg.message!=WM_QUIT )
	{
		// Check the message queue
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE) )
		{
			TranslateMessage( &msg );
			DispatchMessage( &msg );
		}
		else
		{
			
			// Game code goes here
			if(startmenu == true && music == false)
			{
				
				background = "Images\\menu background.png";
				aSurface = d3dMgr->getD3DSurfaceFromFile(background);
				d3dMgr->beginRender();
				theBackbuffer = d3dMgr->getTheBackBuffer();
				d3dMgr->updateTheSurface(aSurface, theBackbuffer);
				d3dMgr->releaseTheBackbuffer(theBackbuffer);
				MenuFont->printText("Stephen Stills' Fabulous Adventure\n\n\nPress any number from 1-7 to begin! \nSwap backgrounds! There are seven! \nPress SPACE to kill Ridleys!", menuTextPos);
				d3dMgr->endRender();
				//music = true;
				
			}
			if(endscreen == true)
			{
				game = false;
				background = "Images\\menu background.png";
				aSurface = d3dMgr->getD3DSurfaceFromFile(background);
				for(int loop = 0; loop < numEnemies; loop++)
				{
					if(loop<3){
						EnemyPos = D3DXVECTOR3(160+loop*160,(float)clientBounds.top+150,0);
					}
					else{
						EnemyPos = D3DXVECTOR3(160+((loop-3)*160),(float)clientBounds.top+300,0);
					}
					aEnemy.push_back(new cEnemy(EnemyPos,d3dMgr->getTheD3DDevice(),"Images\\ridley.png"));
					srand((unsigned int)time(NULL));
					aEnemy[loop]->setTranslation(D3DXVECTOR2(5.0f,(rand()%+(-5))));
				}
				d3dMgr->beginRender();
				theBackbuffer = d3dMgr->getTheBackBuffer();
				d3dMgr->updateTheSurface(aSurface, theBackbuffer);
				d3dMgr->releaseTheBackbuffer(theBackbuffer);
				EnemyFont->printText(gEnemiesKilledStr,textPos);
				MenuFont->printText("\nThank you for playing! \nGo back to the levels! \nThey're waiting for you...", menuTextPos);
				d3dMgr->endRender();
				endscreen = false;
				music = false;
			}
			if(game == true)
			{
				D3DXMatrixTransformation2D(&stephenMatrix, NULL,0.0f,&stephenScale,&(stephen.getSpriteCentre()),rot,&stephenTrans);
				QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
				float dt = (currentTime - previousTime)*sPC;
				EnemyPos = D3DXVECTOR3(EnemyTrans.x,EnemyTrans.y,0);
				sprintf_s(gEnemiesKilledStr, 50, "Kills: %d", gEnemiesKilled);

				// Accumulate how much time has passed.
				timeElapsed += dt;
				/*
				==============================================================
				| Update the postion of the enemies and check for collisions
				==============================================================
				*/
				if(timeElapsed > fpsRate)
				{
			
						if(gameWater == true)
						{
							aSurface = d3dMgr->getD3DSurfaceFromFile("Images\\water background.png");
						}
						if(gameLightning == true)
						{
							aSurface = d3dMgr->getD3DSurfaceFromFile("Images\\lightning background.png");
						}
						if(gameFire == true)
						{
							aSurface = d3dMgr->getD3DSurfaceFromFile("Images\\fire background.png");
						}
						if(gameSpace == true)
						{
							aSurface = d3dMgr->getD3DSurfaceFromFile("Images\\space background.png");
						}
						if(gameCity == true)
						{
							aSurface = d3dMgr->getD3DSurfaceFromFile("Images\\city background.png");
						}
						if(gameForest == true)
						{
							aSurface = d3dMgr->getD3DSurfaceFromFile("Images\\forest background.png");
						}
						if(gameIce == true)
						{
							aSurface = d3dMgr->getD3DSurfaceFromFile("Images\\ice background.png");
						}
						if(endscreen == true)
						{
							aSurface = d3dMgr->getD3DSurfaceFromFile("Images\\menu background.png");
						}
						for(george = aEnemy.begin(); george != aEnemy.end(); ++george)
						{
							(*george)->update();			// update enemy
							aEnemyPos = (*george)->getSpritePos();  // get the position of the current enemy
						/*
						==============================================================
						| Check for boundary collision and change enemy direction
						==============================================================
						*/
						if((*george)->getTranslation().x>0 && aEnemyPos.x>(clientBounds.right - 60))
						{
							(*george)->setTranslation(D3DXVECTOR2(-((*george)->getTranslation().x), (*george)->getTranslation().y));
						}
						if((*george)->getTranslation().x<0 && aEnemyPos.x<(clientBounds.left + 10))
						{
							(*george)->setTranslation(D3DXVECTOR2(-((*george)->getTranslation().x), (*george)->getTranslation().y));
						}

						if((*george)->getTranslation().y<0 && aEnemyPos.y<(clientBounds.top + 50))
						{
							(*george)->setTranslation(D3DXVECTOR2(-((*george)->getTranslation().x), -((*george)->getTranslation().y)));
						}
						if((*george)->getTranslation().y>0 && aEnemyPos.y>(clientBounds.bottom-200))
						{
							(*george)->setTranslation(D3DXVECTOR2(-((*george)->getTranslation().x), -((*george)->getTranslation().y)));
						}

							for(index = aEnemy.begin(); index != aEnemy.end(); ++index)
							{
								if ((*george)->collidedWith((*george)->getBoundingRect(),(*index)->getBoundingRect()))
								{
									// if a collision occurs change the direction of each enemy that has collided
									OutputDebugString("Collision!!");
									(*george)->setTranslation((*george)->getTranslation()*(-1));
									(*index)->setTranslation((*index)->getTranslation()*(-1));
								}
							}
						}

	
						d3dMgr->beginRender();
						theBackbuffer = d3dMgr->getTheBackBuffer();
						d3dMgr->updateTheSurface(aSurface, theBackbuffer);
						d3dMgr->releaseTheBackbuffer(theBackbuffer);

						d3dxSRMgr->beginDraw();
						for(george = aEnemy.begin(); george!= aEnemy.end(); ++george)
						{
							d3dxSRMgr->setTheTransform((*george)->getSpriteTransformMatrix());  
							d3dxSRMgr->drawSprite((*george)->getTexture(),NULL,NULL,NULL,0xFFFFFFFF);
						}
						d3dxSRMgr->endDraw();

						d3dxSRMgr->beginDraw();
						d3dxSRMgr->setTheTransform(stephenMatrix);
						d3dxSRMgr->drawSprite(stephen.getTexture(),NULL,NULL,NULL,0xFFFFFFFF);
						d3dxSRMgr->endDraw();
						//d3dMgr->endRender();
				
						d3dxSRMgr->beginDraw();
						list<cStephen*>::iterator pete = gStephen.begin();
						while(pete != gStephen.end())
						{
							(*pete)->setSpritePos(stephenPos);
							(*pete)->update(dt);
							d3dxSRMgr->setTheTransform((*pete)->getSpriteTransformMatrix());
							d3dxSRMgr->drawSprite((*pete)->getTexture(),&((*pete)->getSourceRect()),NULL,NULL,0xFFFFFFFF);
							++pete;
							pstephenPos.x = stephenTrans.x;
							pstephenPos.y = stephenTrans.y;
							stephenPos = D3DXVECTOR3(stephenTrans.x, stephenTrans.y,0);
						}

						list<cExplosion*>::iterator mike = gExplode.begin();
						while(mike != gExplode.end())
						{
							if((*mike)->isActive() == false)
							{
								mike = gExplode.erase(mike);
							}
							else
							{
								(*mike)->update(timeElapsed);
								d3dxSRMgr->setTheTransform((*mike)->getSpriteTransformMatrix());  
								d3dxSRMgr->drawSprite((*mike)->getTexture(),&((*mike)->getSourceRect()),NULL,NULL,0xFFFFFFFF);
								++mike;
							}
	
						}
			
					previousTime = currentTime;
					OutputDebugString("timeElapsed > fpsRate");
					timeElapsed = 0.0f;
					d3dxSRMgr->endDraw();
					EnemyFont->printText(gEnemiesKilledStr,textPos);
					if(gameWater == true)
					{
						MenuFont->printText("\nBackground 1: Water \nPress 8 when you're done!", menuTextPos);
					}
					if(gameLightning == true)
					{
						MenuFont->printText("\nBackground 2: Lightning \nPress 8 when you're done!", menuTextPos);
					}
					if(gameFire == true)
					{
						MenuFont->printText("\nBackground 3: Fire \nPress 8 when you're done!", menuTextPos);
					}
					if(gameSpace == true)
					{
						MenuFont->printText("\nBackground 4: Space \nPress 8 when you're done!", menuTextPos);
					}
					if(gameCity == true)
					{
						MenuFont->printText("\nBackground 5: City \nPress 8 when you're done!", menuTextPos);
					}
					if(gameForest == true)
					{
						MenuFont->printText("\nBackground 6: Forest \nPress 8 when you're done!", menuTextPos);
					}
					if(gameIce == true)
					{
						MenuFont->printText("\nBackground 7: Ice \nPress 8 when you're done!", menuTextPos);
					}
					
				
				}
				d3dMgr->endRender();
			}
		}
	}
	d3dxSRMgr->cleanUp();
	d3dMgr->clean();
	return (int) msg.wParam;
}

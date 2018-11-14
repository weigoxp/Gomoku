/* GomokuManager.cpp
* a Game manager which have several options for player to choose.
* Created in 3/4/2014
*/
#include <stdio.h>
#include "stdafx.h"
#include "GomokuManager.h"
#include "Mouse.h"
#include "BottonUI.h"
#include "Credit.h"
#include "OnlinePlay.h"
#include "newMouse.h"

BottonUI *b = new BottonUI();
Credit *c = new Credit();
Mouse *m;
OnlinePlay *o;
newMouse *n;

using namespace std;
GomokuManager::GomokuManager(){
    _initialSetup = false;
    _gameOver = false;

    _gameOverScreen = new FullScreenActor();



    //put background sounds one the Sounds file.
    //AngelSampleHandle backgroundSample = theSound.LoadSample("./Resources/Sounds/.....", true);
    //theSound.PlaySound(backgroundSample, 0.7f, true);
}

void GomokuManager::Reset(){
    //if(_gameOver){theWorld.Remove(_gameOverScreen);}
    _gameOver = false;

    theWorld.ResetWorld();
    //theWorld.SetBackgroundColor(Color(255,255,255));
    FullScreenActor *background = new FullScreenActor();
	background->SetSprite("./Resources/Images/background.jpg");
	theWorld.Add(background, -1);
    delete m;
    delete o;
	delete n;
    c->Start();
    b->Start();



}

void GomokuManager::Online(){
    b->Stop();
    c->Stop();
   o = new OnlinePlay();
   if(theInput.IsKeyDown(ANGEL_KEY_B)){o->SetFirst(0);}
   else if(theInput.IsKeyDown(ANGEL_KEY_W)){o->SetFirst(1);}

}
void GomokuManager::HvsEasy(){
    b->Stop();
	c->Stop();
	n = new newMouse();
	n->initialize();

}
void GomokuManager::HvsHard(){
    b->Stop();
    c->Stop();
	n = new newMouse();
	n->initialize();
}

void GomokuManager::HvsH(){
    b->Stop();
    c->Stop();
    m = new Mouse();



}

void GomokuManager::GameOver(){

    //_gameOverScreen->SetSprite("./Resources/Images/angel.png");
    //theWorld.Add(_gameOverScreen,5);
    _gameOver = true;

}

void GomokuManager::Update(float dt){
    if(!_initialSetup){
        Reset();
        _initialSetup = true;

    }
    if(_gameOver && theInput.IsKeyDown(ANGEL_KEY_R)){
        Reset();
    }


}


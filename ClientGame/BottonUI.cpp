/*BottonUI.cpp
* Created iin 3/6/2014
* Create Botton for player to choose game mode
*/

#include "stdafx.h"
#include "BottonUI.h"
#include "GomokuManager.h"
#include "Mouse.h"
#include <unistd.h>
AngelUIHandle BottonUI::_choiceBox = NULL;
AngelUIHandle BottonUI::_choiceBox2 = NULL;

BottonUI::BottonUI(){}
void ComputerAI(int choice){
    if(choice ==0){
        ((GomokuManager*)theWorld.GetGameManager())->HvsEasy();
    }
    else if(choice ==1){
        ((GomokuManager*)theWorld.GetGameManager())->HvsHard();
    }

}

void ChoiceMade(int choice){

    if(choice ==0){
        ((GomokuManager*)theWorld.GetGameManager())->HvsH();
    }
    else if(choice ==1){
        StringList labels;
        labels.push_back("EASY");
        labels.push_back("HARD");

        BottonUI::_choiceBox=theUI.ShowChoiceBox("DIFFICULTY",labels,ComputerAI);
    }
    else if(choice ==2){
        ((GomokuManager*)theWorld.GetGameManager())->Online();
    }

}

void BottonPress(){

    StringList labels;
    labels.push_back("MULTIPLAYER");
    labels.push_back("AGAINST COMPUTER");
    labels.push_back("ONLINE PLAYING");

    BottonUI::_choiceBox=theUI.ShowChoiceBox("GAME MODE",labels,ChoiceMade);


}
void BottonUI::Stop(){
    theUI.RemoveUIElement(_button);
	theUI.RemoveUIElement(BottonUI::_choiceBox);

	//sleep(1);
    //Mouse *m = new Mouse();
}
void BottonUI::Start(){

    _button = theUI.AddButton(" START  ",Vec2i(110,110),BottonPress,true);





}


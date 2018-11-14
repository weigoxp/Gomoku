#include "stdafx.h"
#include "GomokuManager.h"
#include "Credit.h"

Actor *a = new Actor();
Credit::Credit(){}

void Press(){
   //     Actor *a = new Actor();
	a->SetDrawShape(ADS_Square);
	a->SetSize(15);
	theWorld.Add(a,-1);

}
void Credit::Stop(){

    theUI.RemoveUIElement(_button);
    theWorld.Remove(a);
}

void Credit::Start(){

    _button = theUI.AddButton("CREDITS",Vec2i(110,190), Press,true);


}

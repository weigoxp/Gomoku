/*Mouse.cpp
* For human vs human.
*/
#include "Algor.h"
#include "GomokuManager.h"
#include "Mouse.h"

using namespace std;
Algor al;

Mouse::Mouse(){
    Actor *b = new Actor();
    Actor *a = new Actor();
	a->SetDrawShape(ADS_Square);
	a->SetSize(15);
	a->SetSprite("./Resources/Images/chessboard.jpg");
	theWorld.Add(a,-1);
	theWorld.Add(new GridActor(Color(0, 0, 0),Color(0, 0, 0),1.0f,Vector2(-7.0f,-7.0f),Vector2(7.01f,7.01f)), -1);

    b->SetDrawShape(ADS_Square);
    b->SetSprite("./Resources/Images/sta.png");
    b->SetPosition(0,-9);
    theWorld.Add(b,-1);



}

int correctXCoordinate(float sX){
     float x,resultX;
     int x1;
     x = (sX - 400)/40;
     x1 = x;
     resultX=x-x1;
    if(resultX>=0.5){x1+=1;}
    else if(resultX<=-0.5){x1-=1;}
    return x1;
}
int correctYCoordinate(float sY){
    float y,resultY;
     int y1;
     y = (sY - 400)/40*(-1);
     y1 = y;
     resultY=y-y1;
    if(resultY>=0.5){y1+=1;}
    else if(resultY<=-0.5){y1-=1;}
    return y1;


}

void Mouse::MouseMotionEvent(Vec2i s){
    int x,y;
    x=correctXCoordinate(s.X);
    y=correctYCoordinate(s.Y);
    if(y<=-8){gameStart=true;}
}


void Mouse::MouseUpEvent(Vec2i s,MouseButtonInput b){
			static int color = 2;//2 is black, 1 is white.
			int change_colorR,change_colorG,change_colorB;
            int x1,y1;

            x1=correctXCoordinate(s.X);
            y1=correctYCoordinate(s.Y);

			if(b == MOUSE_LEFT &&al.GetPos(x1,y1)&&gameStart)
			{
                al.SetPos(x1,y1,color);
				if(color == 1)
				{
					color = 2;
					change_colorR=0;
					change_colorG=0;
					change_colorB=0;
				}else if(color == 2){
					color = 1;
					change_colorR=255;
					change_colorG=255;
					change_colorB=255;
				}
                Actor *a = new Actor();
                a->SetColor(change_colorR,change_colorG,change_colorB);
                a->SetPosition(x1,y1);
                a->SetDrawShape(ADS_Circle);
                a->SetSize(0.7);
                theWorld.Add(a);

				if(al.isWin(x1,y1)){
				      al.reset();
				      gameStart= false;
				     // start =false;
				     ((GomokuManager*)theWorld.GetGameManager())->GameOver();

				    string str;
				    if(color ==1){str ="White Win! Press R to restart";}
				    else{str="Black Win! Press R to restart";}
                    TextActor *t = new TextActor("Console",str,TXT_Center);
			        theWorld.Add(t);

				}

			}
}




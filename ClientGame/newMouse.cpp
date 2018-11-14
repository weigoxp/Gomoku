
#include "newMouse.h"
#include "Algor.h"
#include "GomokuManager.h"
#include <cstdlib>
#include <ctime>

using namespace std;
Algor al2;

newMouse::newMouse(){
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



	bool comp
		(const std::pair<pair<int, int>,long> &left, const std::pair<pair<int, int>,long> &right) {
			return left.second > right.second;
		}


void newMouse::initialize(){


	Actor *b = new Actor();
	b->SetColor(0,0,0);
	b->SetPosition(0,0);
	b->SetDrawShape(ADS_Circle);
	b->SetSize(0.7);
	theWorld.Add(b);
	al2.SetPos(0, 0, 2);



}
int newcorrectXCoordinate(float sX){
	float x,resultX;
	int x1;
	x = (sX - 400)/40;
	x1 = x;
	resultX=x-x1;
    if(resultX>=0.5){x1+=1;}
    else if(resultX<=-0.5){x1-=1;}
    return x1;
}
int newcorrectYCoordinate(float sY){
    float y,resultY;
	int y1;
	y = (sY - 400)/40*(-1);
	y1 = y;
	resultY=y-y1;
    if(resultY>=0.5){y1+=1;}
    else if(resultY<=-0.5){y1-=1;}
    return y1;


}

void newMouse::MouseMotionEvent(Vec2i s){
    int x,y;
    x=newcorrectXCoordinate(s.X);
    y=newcorrectYCoordinate(s.Y);
    if(y<=-8){gameStart=true;}
}


void newMouse::MouseUpEvent(Vec2i s,MouseButtonInput b){
	static int color = 2;//1 is black, 2 is white.
	int x1,y1;

	srand (time(NULL));



	x1=newcorrectXCoordinate(s.X);
	y1=newcorrectYCoordinate(s.Y);

	if(b == MOUSE_LEFT &&al2.GetPos(x1,y1)&&gameStart)
	{
		long computerx,computery;



		al2.SetPos(x1,y1,1);

		Actor *a = new Actor();
		a->SetColor(255,255,255);
		a->SetPosition(x1,y1);
		a->SetDrawShape(ADS_Circle);
		a->SetSize(0.7);
		theWorld.Add(a);


		if(al2.isWin(x1,y1)){
			al2.reset();
			gameStart= false;
			// start =false;
			((GomokuManager*)theWorld.GetGameManager())->GameOver();

			string str;
			if(color ==2){str ="White Win! Press R to restart";}
			else{str="Black Win! Press R to restart";}
			TextActor *t = new TextActor("Console",str,TXT_Center);
			theWorld.Add(t);

		}

		std::vector<std::pair<std::pair<int, int> ,long> > vec;
		vec = al2.AiGo();






	sort(vec.begin(), vec.end(), comp);


		for (vector<pair<pair<int, int>,long> >::iterator it = vec.begin() ; it != vec.end(); ++it){
			computerx = (*it).first.first;
			computery = (*it).first.second;
			if (al2.GetPos(computerx-7,7-computery)){
				break;
			}

		}


		al2.SetPos(computerx-7,7-computery,2);

		Actor *d = new Actor();
		d->SetColor(0,0,0 );
		d->SetPosition(computerx-7,7-computery);
		d->SetDrawShape(ADS_Circle);
		d->SetSize(0.7);
		theWorld.Add(d);


		if(al2.isWin(computerx-7,7-computery)){
			al2.reset();
			gameStart= false;
			// start =false;
			((GomokuManager*)theWorld.GetGameManager())->GameOver();

			string str;
			if(color ==2){str ="Black Win! Press R to restart";}
			else{str="White Win! Press R to restart";}
			TextActor *t = new TextActor("Console",str,TXT_Center);
			theWorld.Add(t);

		}



	}
}





#include "Algor.h"
#include "GomokuManager.h"
#include "OnlinePlay.h"
#include "clientLocal.hpp"
using namespace std;
Algor as;

OnlinePlay::OnlinePlay(){
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

int correctX(float sX){
     float x,resultX;
     int x1;
     x = (sX - 400)/40;
     x1 = x;
     resultX=x-x1;
    if(resultX>=0.5){x1+=1;}
    else if(resultX<=-0.5){x1-=1;}
    return x1;
}
int correctY(float sY){
    float y,resultY;
     int y1;
     y = (sY - 400)/40*(-1);
     y1 = y;
     resultY=y-y1;
    if(resultY>=0.5){y1+=1;}
    else if(resultY<=-0.5){y1-=1;}
    return y1;


}
/*
void OnlinePlay::makeMatrix(int x,int y){

     for(int i=0;i<15;++i){
         for(int j=0;j<15;++j){
             *(board[i]+j)=0;
             if(i==x+7&&j==7-y){*(board[i]+j)=1;}
         }
     }
}

int getX(int** b){
    int x;
     for(int i=0;i<15;++i){
         for(int j=0;j<15;++j){
             if(*(b[i]+j)==1){x =i-7;}

         }
     }
     return x;
}
int getY(int** b){
    int y;
    for(int i=0;i<15;++i){
         for(int j=0;j<15;++j){
             if(*(b[i]+j)==1){y =7-j;}

         }
     }
     return y;

}
*/
void OnlinePlay::SetFirst(int x){
    if(x ==0){
        color =2;
        enemyC =0;
        myTurn=true;
        change_colorR=0;
        change_colorG=0;
        change_colorB=0;}
    else if (x ==1){
        color =1;
        enemyC =2;
        myTurn=false;
        change_colorR=255;
        change_colorG=255;
        change_colorB=255;}

}

void OnlinePlay::MouseMotionEvent(Vec2i s){
    int x,y;
    x=correctX(s.X);
    y=correctY(s.Y);
    if(y<=-8){gameStart=true;}
}


void OnlinePlay::MouseUpEvent(Vec2i s,MouseButtonInput b){

    int x1,y1;
    x1=correctX(s.X);
    y1=correctY(s.Y);
    if(b == MOUSE_LEFT &&as.GetPos(x1,y1)&&gameStart&&myTurn){
            as.SetPos(x1,y1,color);
          //  makeMatrix(x1,y1);
            clientLocal(myTurn,x1,y1);
            myTurn = false;
            Actor *a = new Actor();
            a->SetColor(change_colorR,change_colorG,change_colorB);
            a->SetPosition(x1,y1);
            a->SetDrawShape(ADS_Circle);
            a->SetSize(0.7);
            theWorld.Add(a);
            if(as.isWin(x1,y1)){
                    as.reset();
                    gameStart= false;
                    ((GomokuManager*)theWorld.GetGameManager())->GameOver();

				    string str;
				    if(color ==0){str ="White Win! Press R to restart";}
				    else{str="Black Win! Press R to restart";}
                    TextActor *t = new TextActor("Console",str,TXT_Center);
			        theWorld.Add(t);}
        }
        else{
        clientLocal(myTurn,x1,y1);
        myTurn =true;
        //x1 =getX(board);
        //y1 = getY(board);
        as.SetPos(x1,y1,enemyC);
        Actor *a = new Actor();
        a->SetColor(change_colorR,change_colorG,change_colorB);
        a->SetPosition(x1,y1);
        a->SetDrawShape(ADS_Circle);
        a->SetSize(0.7);
        }




}

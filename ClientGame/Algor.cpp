/*Algor.cpp
* human vs human algorithm or basic algorithm to determine win.
* Create in 2/28/2014
* Author:  weigo Xu.
*
*
*/
#include "Algor.h"
#include <vector>
#include <algorithm>

using namespace std;
Algor::Algor(){
	reset();
}

std::vector<std::pair<std::pair<int, int> ,long> > Algor::AiGo()
{

	char BoardData[2][15][15][8][2]={0};    // the matrix data
	int k,i,j,q,b=0,a=1,d=0;
	int a1[15][15]={0},a2[15][15]={0};

	// fill in the matrix.
	for(k=0;k<2;k++)
		for(i=0;i<15;i++)
			for(j=0;j<15;j++)
			{
				if(matrix[0][0]==0)
				{
					for(q=0;q<8;q++)
					{
						if(k==0) d=1;
						else d=2;
						if(q==0&&j>=0)
						{
							for(;j-a>=0;)
							{
								if(matrix[i][j-a]==d){b++;a++;continue;}
								else break;
							}
							BoardData[k][i][j][q][0]=b;b=0;
							if(matrix[i][j-a]==0&&j-a>=0){BoardData[k][i][j][q][1]=1;a=1;}
							else {BoardData[k][i][j][q][1]=0;a=1;}
						}
						if(q==1&&i>=0&&j>=0)
						{
							for(;i-a>=0&&j-a>=0;)
							{
								if(matrix[i-a][j-a]==d){b++;a++;continue;}
								else break;
							}
							BoardData[k][i][j][q][0]=b;b=0;
							if(matrix[i-a][j-a]==0&&j-a>=0&&i-a>=0){BoardData[k][i][j][q][1]=1;a=1;}
							else {BoardData[k][i][j][q][1]=0;a=1;}
						}
						if(q==2&&i>=0)
						{
							for(;i-a>=0;)
							{
								if(matrix[i-a][j]==d){b++;a++;continue;}
								else break;
							}
							BoardData[k][i][j][q][0]=b;b=0;
							if(matrix[i-a][j]==0&&i-a>=0){BoardData[k][i][j][q][1]=1;a=1;}
							else {BoardData[k][i][j][q][1]=0;a=1;}
						}
						if(q==3&&i>=0&&j<15)
						{
							for(;i-a>=0&&j+a<15;)
							{
								if(matrix[i-a][j+a]==d){b++;a++;continue;}
								else break;
							}
							BoardData[k][i][j][q][0]=b;b=0;
							if(matrix[i-a][j+a]==0&&i-a>=0&&j+a<15){BoardData[k][i][j][q][1]=1;a=1;}
							else {BoardData[k][i][j][q][1]=0;a=1;}
						}
						if(q==4&&j<15)
						{
							for(;j+a<15;)
							{
								if(matrix[i][j+a]==d){b++;a++;continue;}
								else break;
							}
							BoardData[k][i][j][q][0]=b;b=0;
							if(matrix[i][j+a]==0&&j+a<15){BoardData[k][i][j][q][1]=1;a=1;}
							else {BoardData[k][i][j][q][1]=0;a=1;}
						}
						if(q==5&&i<15&&j<15)
						{
							for(;i+a<15&&j+a<15;)
							{
								if(matrix[i+a][j+a]==d){b++;a++;continue;}
								else break;
							}
							BoardData[k][i][j][q][0]=b;b=0;
							if(matrix[i+a][j+a]==0&&i+a<15&&j+a<15){BoardData[k][i][j][q][1]=1;a=1;}
							else {BoardData[k][i][j][q][1]=0;a=1;}
						}
						if(q==6&&i<15)
						{
							for(;i+a<15;)
							{
								if(matrix[i+a][j]==d){b++;a++;continue;}
								else break;
							}
							BoardData[k][i][j][q][0]=b;b=0;
							if(matrix[i+a][j]==0&&i+a<15){BoardData[k][i][j][q][1]=1;a=1;}
							else {BoardData[k][i][j][q][1]=0;a=1;}
						}
						if(q==7&&j>=0&&i<15)
						{
							for(;i+a<15&&j-a>=0;)
							{
								if(matrix[i+a][j-a]==d){b++;a++;continue;}
								else break;
							}
							BoardData[k][i][j][q][0]=b;b=0;
							if(matrix[i+a][j-a]==0&&i+a<15&&j-a>=0){BoardData[k][i][j][q][1]=1;a=1;}
							else {BoardData[k][i][j][q][1]=0;a=1;}
						}
					}
				}

			}


	//evaluate every spot.
	for(k=0;k<2;k++)
		for(i=0;i<15;i++)
			for(j=0;j<15;j++)
			{
				if(k==0) // evaluate white.
				{
					for(q=0;q<4;q++)
					{
						if((BoardData[k][i][j][q][0]+BoardData[k][i][j][q+4][0])==4
						   &&BoardData[k][i][j][q][1]==1&&BoardData[k][i][j][q+4][1]==1)
							b+=7000;
						if((BoardData[k][i][j][q][0]+BoardData[k][i][j][q+4][0])==3
						   &&BoardData[k][i][j][q][1]==1&&BoardData[k][i][j][q+4][1]==1)
							b+=301;
						if((BoardData[k][i][j][q][0]+BoardData[k][i][j][q+4][0])==2
						   &&BoardData[k][i][j][q][1]==1&&BoardData[k][i][j][q+4][1]==1)
							b+=43;
						if((BoardData[k][i][j][q][0]+BoardData[k][i][j][q+4][0])==1
						   &&BoardData[k][i][j][q][1]==1&&BoardData[k][i][j][q+4][1]==1)
							b+=11;
						if((BoardData[k][i][j][q][0]+BoardData[k][i][j][q+4][0])==4
						   &&((BoardData[k][i][j][q+4][1]==0)
							  ||(BoardData[k][i][j][q][1]==0)))
							b+=7000;
						if((BoardData[k][i][j][q][0]+BoardData[k][i][j][q+4][0])==3
						   &&((BoardData[k][i][j][q][1]==1&&BoardData[k][i][j][q+4][1]==0)
							  ||(BoardData[k][i][j][q][1]==0&&BoardData[k][i][j][q+4][1]==1)))
							b+=63;
						if((BoardData[k][i][j][q][0]+BoardData[k][i][j][q+4][0])==2
						   &&((BoardData[k][i][j][q][1]==1&&BoardData[k][i][j][q+4][1]==0)
							  ||(BoardData[k][i][j][q][1]==0&&BoardData[k][i][j][q+4][1]==1)))
							b+=6;
						if((BoardData[k][i][j][q][0]+BoardData[k][i][j][q+4][0])==1
						   &&((BoardData[k][i][j][q][1]==1&&BoardData[k][i][j][q+4][1]==0)
							  ||(BoardData[k][i][j][q][1]==0&&BoardData[k][i][j][q+4][1]==1)))
							b+=1;

					}
					if(b==126||b==189||b==252) b=1500;
					if(b==106) b=1000;

					a1[i][j]=b;b=0;
				}
				if(k==1) //evaluate black
				{
					for(q=0;q<4;q++)
					{

						if((BoardData[k][i][j][q][0]+BoardData[k][i][j][q+4][0])==4
						   &&BoardData[k][i][j][q][1]==1&&BoardData[k][i][j][q+4][1]==1)
							b+=30000;
						if((BoardData[k][i][j][q][0]+BoardData[k][i][j][q+4][0])==3
						   &&BoardData[k][i][j][q][1]==1&&BoardData[k][i][j][q+4][1]==1)
							b+=1500;
						if((BoardData[k][i][j][q][0]+BoardData[k][i][j][q+4][0])==2
						   &&BoardData[k][i][j][q][1]==1&&BoardData[k][i][j][q+4][1]==1)
							b+=51;
						if((BoardData[k][i][j][q][0]+BoardData[k][i][j][q+4][0])==1
						   &&BoardData[k][i][j][q][1]==1&&BoardData[k][i][j][q+4][1]==1)
							b+=16;
						if((BoardData[k][i][j][q][0]+BoardData[k][i][j][q+4][0])==4
						   &&((BoardData[k][i][j][q+4][1]==0)
							  ||(BoardData[k][i][j][q][1]==0)))
							b+=30000;
						if((BoardData[k][i][j][q][0]+BoardData[k][i][j][q+4][0])==3
						   &&((BoardData[k][i][j][q][1]==1&&BoardData[k][i][j][q+4][1]==0)
							  ||(BoardData[k][i][j][q][1]==0&&BoardData[k][i][j][q+4][1]==1)))
							b+=71;
						if((BoardData[k][i][j][q][0]+BoardData[k][i][j][q+4][0])==2
						   &&((BoardData[k][i][j][q][1]==1&&BoardData[k][i][j][q+4][1]==0)
							  ||(BoardData[k][i][j][q][1]==0&&BoardData[k][i][j][q+4][1]==1)))
							b+=7;
						if((BoardData[k][i][j][q][0]+BoardData[k][i][j][q+4][0])==1
						   &&((BoardData[k][i][j][q][1]==1&&BoardData[k][i][j][q+4][1]==0)
							  ||(BoardData[k][i][j][q][1]==0&&BoardData[k][i][j][q+4][1]==1)))
							b+=2;
					}
					if(b==142||b==213||b==284) b=1500;
					if(b==122) b=1300;

					a2[i][j]=b;b=0;
				}
			}


	// pick the spot with highest score
	std::vector<std::pair<std::pair<int, int> ,long> > vec;

	for(int i=0;i<15;i++)
		for(int j=0;j<15;j++)
		{
			if(a1[i][j]<a2[i][j])
				a1[i][j]=a2[i][j];
			vec.push_back (make_pair( make_pair(i, j), a1[i][j]));

		}






	return vec;
}

//***********************************************//

void Algor::reset(){
    for(int i=0;i<15;++i){
        for(int j=0;j<15;++j){
            matrix[i][j]=0;
        }}

}
void Algor::SetPos(int x, int y, int col){
        int x1,y1;
        x1 = x+7;
        y1 = 7-y;

        if(col==2){matrix[x1][y1]=2;}  //black
        else if(col ==1){matrix[x1][y1]=1;} //white

}

bool Algor::GetPos(int x,int y){

        if(x>7||x<-7){return false;}
        else if(y>7||y<-7){return false;}
        else if(matrix[x+7][7-y]==2){return false;}  //black
        else if(matrix[x+7][7-y]==1){return false;}  //white
        return true;
    }

bool Algor::isWin(int x1,int y1){
         /* human vs human algorithm. Checking for which side get five continous
         * same color, the basic idea is locate current position x1,y1 and
         *transform into the matrix position x=x1+7, y=7-y1.Then set this position
         *as center point search for up down left right bevels,and find if it have
         *five same color position.
         */
         int x,y;
         x=x1+7;
         y=7-y1;
         color = matrix[x][y];
         // first calacute row number of this position,
         int counter=1;
         for(int i=1;i<5;++i){
             if(y+i>15){break;}
             else if(matrix[x][y+i]==color){
                 counter++;
                 if(counter==5){return true;}}
             else {break;}
            }

         for(int i=1;i<5;++i){
             if(y-i<0){break;}
             else if(matrix[x][y-i]==color){counter++;if(counter==5){return true;}}
             else{break;}
         }

         //if no row can have five same color, reset counter and find col.
         counter=1;
         for(int i=1;i<5;++i){
             if(x+i>15){break;}
             else if(matrix[x+i][y]==color){counter++;if(counter==5){return true;}}
             else {break;}
            }
         for(int i=1;i<5;++i){
             if(x-i<0){break;}
             else if(matrix[x-i][y]==color){counter++;if(counter==5){return true;}}
             else{break;}
         }
         // if no col have five same color, reset counter and find right bevel
         counter =1;
         for(int i=1;i<5;++i){
             if(y+i>15||x-i<0){break;}
             else if(matrix[x-i][y+i]==color){counter++;if(counter==5){return true;}}
             else {break;}
            }
         for(int i=1;i<5;++i){
             if(y-i<0||x+i>15){break;}
             else if(matrix[x+i][y-i]==color){counter++;if(counter==5){return true;}}
             else{break;}
         }
         //if no right bevel, reset counter and find left bevel.
         counter=1;
         for(int i=1;i<5;++i){
             if(y+i>15||x+i>15){break;}
             else if(matrix[x+i][y+i]==color){counter++;if(counter==5){return true;}}
             else {break;}
            }
         for(int i=1;i<5;++i){
             if(y-i<0||x-i<0){break;}
             else if(matrix[x-i][y-i]==color){counter++;if(counter==5){return true;}}
             else{break;}
         }

         // if all above no five same number return falie
         return false;


}






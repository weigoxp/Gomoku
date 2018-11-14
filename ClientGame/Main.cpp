#include "stdafx.h"
#include "GomokuManager.h"




int main(int argc, char* argv[])
{
	//cout<<"what topic did you want to pick in this game: "<<endl;
	//string topic;
	//cin>>topic;

	// get things going
	//  optional parameters:
	//		int windowWidth			default: 1024
	//		int windowHeight		default: 768
	//		std::string windowName	default: "Gomoku"
	//		bool antiAliasing		default: false
	//		bool fullScreen			default: false
	//		bool resizable			default: false
	theWorld.Initialize(800,800,"Gomoku",false,false);


    theWorld.SetGameManager(new GomokuManager());







	// do all your setup first, because this function won't return until you're exiting
	theWorld.StartGame();

	// any cleanup can go here
	theWorld.Destroy();

	return 0;
}

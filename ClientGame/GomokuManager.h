#pragma once

class GomokuManager : public GameManager {
public:
	GomokuManager();

	void Reset();
	void GameOver();
	void HvsH();   //MULTIPLAYER
	void HvsEasy(); //Easy mode
	void HvsHard();  //Hard mode
	void Online();
	virtual void Update(float dt);



private:
	FullScreenActor* _gameOverScreen;


	bool _initialSetup;
	bool _gameOver;


};

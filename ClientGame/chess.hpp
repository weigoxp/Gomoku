
#ifndef CHESS_HPP
#define CHESS_HPP
#include "stdafx.h"
#include "MatrixBoard.cpp"
#include <fstream>
#include <iostream>

class CChess : public MouseListener
{
public:
	void BackGo();           // go previous step.
	void NewGame(int);       // new game
	void ReDraw();           //the function to redraw.
	bool DownZi(int nx,int ny,int type); // external function for step.
	CChess();
	virtual ~CChess();

private:
	void AiGo(int &,int &);     // AI
	void DrawQz(int nx,int ny,int type=0);// Step
	void DrawQp();							// Board
	int Judge(int nx,int ny);           // judge win or lose
	int m_turn;								// turn
	int m_flag;								// win or lose flag,1-black 2-white

	char m_board[15][15];				// board

	struct pos{int x;int y;int flag;};
	pos posinfo[225];						// what you have stepped
	int posflag;							// flag for stepped
};

#endif

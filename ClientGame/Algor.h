#pragma once
#include "stdafx.h"
#include <vector>

class Algor{
    public:
    Algor();
    void SetPos(int x,int y,int col);
    bool GetPos(int x,int y);
    bool isWin(int x1,int y1);
    void reset();
	std::vector<std::pair<std::pair<int, int> ,long> > AiGo();
	
	
    private:
    int color;
    int matrix[15][15];




};

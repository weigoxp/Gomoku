
#pragma once
#include "stdafx.h"
#include <iostream>
#include <stdio.h>


class OnlinePlay: public MouseListener{
    public:
    OnlinePlay();
    void SetFirst(int x);
    void makeMatrix(int x, int y);
    void MouseMotionEvent(Vec2i s);
    void MouseUpEvent(Vec2i s, MouseButtonInput b);

    private:
    bool gameStart = false;
    bool myTurn;
    int color,enemyC,change_colorR,change_colorG,change_colorB;
    int** board;


};

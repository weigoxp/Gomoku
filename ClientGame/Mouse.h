#pragma once
#include "stdafx.h"
#include <iostream>
#include <stdio.h>


class Mouse: public MouseListener{
    public:
    Mouse();
    void Start();
    void MouseMotionEvent(Vec2i s);
    void MouseUpEvent(Vec2i s, MouseButtonInput b);

    private:
    bool gameStart = false;


};

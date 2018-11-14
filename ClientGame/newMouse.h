


#pragma once
#include "stdafx.h"
#include <iostream>
#include <stdio.h>


class newMouse: public MouseListener{
public:
    newMouse();
    void newStart();  ///// 改
    void MouseMotionEvent(Vec2i s);
    void MouseUpEvent(Vec2i s, MouseButtonInput b);
	void initialize();
	
private:
    bool gameStart = false;
	
};





#pragma once

#include "stdafx.h"
#include <vector>
#include <string>

using namespace std;
class UiScreen : public Renderable
{
	public:
	void Start();
	void Stop();
	void Update(float dt);
	void Render();

	void ReceiveMessage(Message *message){}
	protected:
	vector<Renderable*> _ojects;
};

#define theDemoGame 
